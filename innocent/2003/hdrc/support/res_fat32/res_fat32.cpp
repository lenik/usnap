
#include "stdafx.h"
#include <winioctl.h>
#include <pos/pos.h>
using namespace pos;
#include "dump_sector.h"
__std;

#include "dump_sector_util.h"

/*
	Rescue FAT-32

	Function:
		-s	Search for directories
	Options:
		-r	Rescue directory

*/


struct RescueDirectoryOptions {
	u64_t	MaxFileSize;
	Date	BeginDate;
	char	FilePattern[_MAX_PATH];
};

int main(int argc, char* argv[])
{
	printf("Hello World!\n");
	return 0;
}
