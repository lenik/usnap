
#include <stdio.h>
#include <windows.h>
#include <assert.h>

int bForce = false;
int bDelta = false;
int nScale = 1;

int batch_set_file_size(const char *pFilesName, long size);
int set_file_size(const char *pFileName, long size);

int main(int argc, char **argv) {
	while (argc > 1) {
		argc--;
		argv++;
		if (argv[0][0] == '-') {
			switch (argv[0][1]) {
			case 'f':
				bForce = true;
				break;
			case 'd':
				bDelta = true;
				break;
			case 'a':
				bDelta = false;
				break;
			case 'h':
				printf("setsize: change file size. \nauthored by zauj.g.dansei, 2003.7.9\nsyntax: setsize [-fdah] <filename> <size> [<filename> <size> [...]]\n\t-f: force change file size(override read-only settings)\n\t-d: delta size\n\t-a: absolute size\n\t-h: this help message. \n");
				break;
			default:
				printf("unrecognized option: -%c\n", argv[0][1]);
				break;
			}
			continue;
		}
		if (argc < 2) {
			printf("size for file \"%s\" not specified!\n", argv[0]);
			break;
		}
		long nSize = strtol(argv[1], NULL, 0);
		batch_set_file_size(argv[0], nSize);
		argc--;
		argv++;
	}
	return 0;
}

int batch_set_file_size(const char *pFilesName, long size) {
	WIN32_FIND_DATA wfd;
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	_splitpath(pFilesName, drive, dir, fname, ext);
	HANDLE hFind = FindFirstFile(pFilesName, &wfd);
	if (hFind == INVALID_HANDLE_VALUE) {
		return 0;
	}

	int nFiles = 0;
	do {
		char filename[_MAX_PATH];
		_splitpath(wfd.cFileName, 0, 0, fname, ext);
		_makepath(filename, drive, dir, fname, ext);
		printf("%s: changed to size ", filename);
		if (set_file_size(filename, size)) {
			nFiles++;
			printf("successed. \n");
		} else {
			printf("failed. \n");
		}
	} while (FindNextFile(hFind, &wfd));
	FindClose(hFind);
	return nFiles;
}

int set_file_size(const char *pFileName, long size) {
	DWORD dwAttr = GetFileAttributes(pFileName);
	int success = 0;
	DWORD ret;
	if (bForce) SetFileAttributes(pFileName, 0);

	HANDLE hFile = CreateFile(pFileName, GENERIC_READ | GENERIC_WRITE,
		0/*exclusive*/, NULL/*sec*/, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE) {
		DWORD nPtr;
		if (bDelta) {
			nPtr = SetFilePointer(hFile, 0, NULL, FILE_END);
			size += nPtr;
		}
		printf("%d", size);
		nPtr = SetFilePointer(hFile, size, NULL, FILE_BEGIN);
		if (nPtr != /*INVALID_SET_FILE_POINTER*/ -1) {
			if (SetEndOfFile(hFile)) {
				success = 1;
			}
		}
		CloseHandle(hFile);
	}

	if (bForce) SetFileAttributes(pFileName, dwAttr);
	return success;
}
