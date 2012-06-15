
#pragma once


#define PRIVUTIL_DEVICE_NAME		L"\\Device\\PrivUtil"
#define PRIVUTIL_DOS_DEVICE_NAME	L"\\DosDevices\\PrivUtil"


typedef struct _PRIVUTIL_DEVICE_EXTENSION {
	PDEVICE_OBJECT	FunctionDeviceObject;
	PDEVICE_OBJECT	NextStackDevice;
	UNICODE_STRING	ucsSymLinkName;
} PRIVUTIL_DEVICE_EXTENSION, *PPRIVUTIL_DEVICE_EXTENSION;


NTSTATUS DriverEntry(
	IN PDRIVER_OBJECT DriverObject,
	IN PUNICODE_STRING RegistryPath
	);
NTSTATUS PrivUtilOpen(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp
	);
NTSTATUS PrivUtilClose(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp
	);
NTSTATUS PrivUtilControl(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp
	);
NTSTATUS PrivUtilCleanup(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp
	);
VOID PrivUtilUnload(
	IN PDRIVER_OBJECT DriverObject
	);
