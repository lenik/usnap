
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#include <memory.h>
#include <alloc.h>
#include <string.h>
//#include <char.h>
#include <dos.h>
#include "fatview.h"
#include "diskio.h"
#include "fatutil.h"

DriveInformation	g_DI;
DriveParameters 	g_DP;
DiskAddressPacket	g_DAP;
PFAR			g_Buffer; 	// buffer for one sector.

void main() {
	WORD _F = 0;

	g_Buffer = farmalloc(50000ul);
	if (!g_Buffer) {
		cerr << "memory out!\n64k+ memory is at least.\n";
		return;
	}

	__zero(g_DI);
	__zero(g_DP);
	__zero(g_DAP);
	g_DP.cbSize = sizeof(g_DP);

	_asm {
		xor ax, ax
		mov ah, 25h
		mov dl, 82h
		mov bx, offset g_DI
		int 13h
	}

	if (_CF) {
		cout << "Can't get drive information!" << (int)_AH << endl;
		return;
	}
	DumpDriveInformation(&g_DI);
	getch();

	_asm {
		xor ax, ax
		mov ah, 48h
		mov dl, 82h
		mov si, offset g_DP;
		int 13h
	}

	if (_CF) {
		cout << "Can't get drive parameters: " << (int)_AH << endl;
		return;
	}
	DumpDriveParameters(&g_DP);
	getch();
	if (g_DP.pEDDConfig) {
		DumpEnhancedDiskDriveSpec((EDD_Spec *)g_DP.pEDDConfig);
		getch();
	}

	_fstrcpy((char far *)g_Buffer, "1234");
	g_DAP.cbSize		= sizeof(g_DAP);
	g_DAP.nBlocks 		= 2;
	g_DAP.pTransferBuffer 	= g_Buffer;
	g_DAP.nStartBlock.low	= 1; 	// cy*

	_asm {
		mov ah, 42h		// Extend Read
		mov dl, 82h		// Disk-3
		mov di, offset g_DAP	// DS:SI -> disk address packet
		int 13h
	}
	if (_CF) {
		cout << "Can't read the sector: " << (int)_AH << "\n";
		return;
	}

	DumpString(g_Buffer, g_DP.nSectorSize * g_DAP.nBlocks, 0);

	return;
}
