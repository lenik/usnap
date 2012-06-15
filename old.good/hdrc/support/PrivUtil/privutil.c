
#include <ntddk.h>

#include "privutil.h"
#include "privutilsdk.h"



void _declspec(naked) _crit_proc() {
	_asm {
		; init seh
		; mov fs:[0] ...

		xor eax, eax
		in al, 0x43		; PIT#1 status
	}
}


NTSTATUS
DriverEntry(
	IN PDRIVER_OBJECT DriverObject,
	IN PUNICODE_STRING RegistryPath
	)
{
	UNICODE_STRING	ucsDeviceName;
	UNICODE_STRING	ucsDosDeviceName;
	NTSTATUS	status;
	PDEVICE_OBJECT	pdev = NULL;

	RtlInitUnicodeString(&ucsDeviceName, PRIVUTIL_DEVICE_NAME);

	status = IoCreateDevice(
		DriverObject,
		0, 		// extra
		&ucsDeviceName, 	// naming the FDO bypasses security mgr.
		FILE_DEVICE_UNKNOWN,
		0, 		// features
		FALSE, 		// exclusive
		&pdev
		);
	if (!NT_SUCCESS(status)) {
		DbgPrint("PrivUtil DriverEntry: IoCreateDevice failed\n");
		return status;
	}

	RtlInitUnicodeString(&ucsDosDeviceName, PRIVUTIL_DOS_DEVICE_NAME);
	status = IoCreateSymbolicLink(&ucsDosDeviceName, &ucsDeviceName);
	if (!NT_SUCCESS(status)) {
		DbgPrint("PrivUtil DriverEntry: IoCreateSymbolicLink failed\n");
		return status;
	}
	RtlFreeUnicodeString(&ucsDosDeviceName);

	DriverObject->MajorFunction[IRP_MJ_CREATE]	= PrivUtilOpen;
	DriverObject->MajorFunction[IRP_MJ_CLOSE]	= PrivUtilClose;
	DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL]
							= PrivUtilControl;
	DriverObject->MajorFunction[IRP_MJ_CLEANUP]	= PrivUtilCleanup;
	DriverObject->DriverUnload			= PrivUtilUnload;
	DriverObject->DriverStartIo;

	return STATUS_SUCCESS;
}


NTSTATUS
PrivUtilOpen(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp
	)
{
	Irp->IoStatus.Status = STATUS_SUCCESS;
	Irp->IoStatus.Information = FILE_OPENED;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}

NTSTATUS
PrivUtilClose(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp
	)
{
	Irp->IoStatus.Status = STATUS_SUCCESS;
	Irp->IoStatus.Information = 0; //FILE_CLOSED;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}


NTSTATUS
PrivUtilControl(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp
	)
{
	NTSTATUS Status;
	PIO_STACK_LOCATION IrpSp;

	IrpSp = IoGetCurrentIrpStackLocation(Irp);

	switch (IrpSp->Parameters.DeviceIoControl.IoControlCode) {
	case PRIVUTIL_GET_VERSION:
		if (IrpSp->Parameters.DeviceIoControl.OutputBufferLength
			< 32) {
			Status = STATUS_UNSUCCESSFUL;
			break;
		} else {
			STRING szVersion;
			RtlInitAnsiString(&szVersion, "Priviledge Utility 1.00");
			RtlCopyString((PSTRING)&Irp->AssociatedIrp.SystemBuffer,
				&szVersion);
			RtlFreeAnsiString(&szVersion);
			Status = STATUS_SUCCESS;
		}
		break;
	case PRIVUTIL_CRIT_PROC:
		_crit_proc();
		Status = STATUS_SUCCESS;
		break;
	default:
		DbgPrint("PrivUtil: Bad IOCTL!\n");
		Status = STATUS_NOT_IMPLEMENTED;
		break;
	}

	Irp->IoStatus.Status = Status;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return Status;
}


NTSTATUS
PrivUtilCleanup(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp
	)
{
	Irp->IoStatus.Status = STATUS_SUCCESS;
	Irp->IoStatus.Information = 0;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}

VOID
PrivUtilUnload(
	IN PDRIVER_OBJECT DriverObject
	)
{
	UNICODE_STRING	ucsDosDeviceName;
	NTSTATUS	status;
	PDEVICE_OBJECT	pdev = NULL;

	RtlInitUnicodeString(&ucsDosDeviceName, PRIVUTIL_DOS_DEVICE_NAME);

	status = IoDeleteSymbolicLink(&ucsDosDeviceName);

	RtlFreeUnicodeString(&ucsDosDeviceName);

	IoDeleteDevice(DriverObject->DeviceObject);
}


/*
void _imp__IoCreateSymbolicLink() {}
void _imp__IoCreateDevice() {}
void __stdcall _imp__RtlCopyString(int a, int b) {}
void _imp__IoDeleteDevice() {}
void _imp__IoDeleteSymbolicLink() {}


int _stdcall WinMain(void *_s1, void *_s2, char *_r1, int _r2) {
    int x = sizeof(IRP);
    int y = sizeof(DRIVER_OBJECT);
    int z = sizeof(DEVICE_OBJECT);

    return 0;
}
*/