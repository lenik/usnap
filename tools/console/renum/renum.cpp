// renum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#include <pos/pos.h>
//using namespace pos;

bool g_include_date = 0;		// yymmddnn.<ext name>, nn is serial no.
int  g_width = 0;
int  g_base = 0;
bool g_hex_for_nn = false;
bool g_include_hidden = false;
bool g_include_readonly = false;
bool g_include_directory = false;
bool g_recursive_directory = false;

struct fileinfo {
	char name_short[14];	// 8+'.'+3	+2 safe?
	char *name_long;

	SYSTEMTIME date_create;
	SYSTEMTIME date_modify;
	SYSTEMTIME date_access;
	DWORD attr0;
	size_t length;
	size_t length_h;
	int serial;
	void (*_destroy)();
};

namespace std {
	template<>
	struct greater<fileinfo *> : public binary_function<fileinfo *, fileinfo *, bool> {
		bool st_cmp_gt(const SYSTEMTIME& t1, const SYSTEMTIME& t2) const {
			if (t1.wYear != t2.wYear) return t1.wYear > t2.wYear;
			if (t1.wMonth != t2.wMonth) return t1.wMonth > t2.wMonth;
			if (t1.wDay != t2.wDay) return t1.wDay > t2.wDay;
			if (t1.wHour != t2.wHour) return t1.wHour > t2.wHour;
			if (t1.wMinute != t2.wMinute) return t1.wMinute > t2.wMinute;
			if (t1.wSecond != t2.wSecond) return t1.wSecond > t2.wSecond;
			return t1.wMilliseconds > t2.wMilliseconds;
		}
		bool st_cmp_eq(const SYSTEMTIME& t1, const SYSTEMTIME& t2) const {
			return t1.wYear == t2.wYear
				&& t1.wMonth == t2.wMonth
				&& t1.wDay == t2.wDay
				&& t1.wHour == t2.wHour
				&& t1.wMinute == t2.wMinute
				&& t1.wSecond == t2.wSecond
				&& t1.wMilliseconds == t2.wMilliseconds
				;
		}
		bool st_cmp_lt(const SYSTEMTIME& t1, const SYSTEMTIME& t2) const {
			return !st_cmp_gt(t1, t2) && !st_cmp_eq(t1, t2);
		}

		bool operator()(const fileinfo *s1, const fileinfo *s2) const {
			SYSTEMTIME& t1 = (SYSTEMTIME&)s1->date_modify;
			SYSTEMTIME& t2 = (SYSTEMTIME&)s2->date_modify;
			return st_cmp_lt(t1, t2);
		}
	};
}

struct fileinfos {
	typedef list<fileinfo *> fileinfo_list;
	fileinfo_list files;
	fileinfo *add_file(WIN32_FIND_DATA& wfd) {
		fileinfo *_f = new fileinfo;
		__zero(*_f);
		strcpy(_f->name_short, wfd.cAlternateFileName);
		_f->name_long = strdup(wfd.cFileName);

		// is this most important.?
		FileTimeToLocalFileTime(&wfd.ftLastWriteTime, &wfd.ftLastWriteTime);
		FileTimeToSystemTime(&wfd.ftLastWriteTime, &_f->date_modify);

		FileTimeToLocalFileTime(&wfd.ftCreationTime, &wfd.ftCreationTime);
		FileTimeToSystemTime(&wfd.ftCreationTime, &_f->date_create);
		FileTimeToLocalFileTime(&wfd.ftLastAccessTime, &wfd.ftLastAccessTime);
		FileTimeToSystemTime(&wfd.ftLastAccessTime, &_f->date_access);

		_f->length = wfd.nFileSizeLow;
		_f->length_h = wfd.nFileSizeHigh;

		files.push_back(_f);
		return _f;
	}
	~fileinfos() {
		fileinfo_list::iterator it = files.begin();
		while (it != files.end()) {
			fileinfo *_f = *it;
			if (_f->name_long) delete _f->name_long;
			if (_f->_destroy) _f->_destroy();
			delete _f;
			it++;
		}
		files.clear();
	}
};


int process(char *_pattern) {
	cerr << "processing: " << _pattern << endl;

	char _drive[_MAX_DRIVE];
	char _dir[_MAX_DIR];
	char _fname[_MAX_FNAME];
	char _ext[_MAX_EXT];
	::_splitpath(_pattern, _drive, _dir, 0, 0);

	WIN32_FIND_DATA fd;
	__zero(fd);
	HANDLE hFind = ::FindFirstFile(_pattern, &fd);

	if (hFind == INVALID_HANDLE_VALUE) return -1;

	fileinfos fs;
	do {
		if (fd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) {
			if (!g_include_hidden) continue;
		}
		if (fd.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
			if (!g_include_readonly) continue;
		}
		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			if (!g_include_directory) continue;
			if (strcmp(fd.cFileName, ".") == 0
				|| strcmp(fd.cFileName, "..") == 0) continue;
		}

		fileinfo *_f;
		_f = fs.add_file(fd);
		_f->serial = 0;
	} while (::FindNextFile(hFind, &fd));
	CloseHandle(hFind);

	fs.files.sort(greater<fileinfo *>());

	fileinfos::fileinfo_list::iterator it = fs.files.begin();
	fileinfo *_f0 = NULL;
	int y0 = -1;
	int m0 = -1;
	int d0 = -1;
    char _num_fmt[10];
	int serial = -1;

	if (g_width > 0)
		sprintf(_num_fmt, "%%%d%c", g_width, g_hex_for_nn ? 'x' : 'd');
	else
		sprintf(_num_fmt, "%%%c", g_hex_for_nn ? 'x' : 'd');

	do {
		fileinfo *_f = *it;
		serial++;

		int y1 = _f->date_modify.wYear;
		int m1 = _f->date_modify.wMonth;
		int d1 = _f->date_modify.wDay;
		if (y0 != y1 || m0 != m1 || d0 != d1) {
			y0 = y1;
			m0 = m1;
			d0 = d1;
			if (g_include_date) serial = 0;
		}

		int h = _f->date_modify.wHour;
		int m = _f->date_modify.wMinute;
		int s = _f->date_modify.wSecond;

		/*
		_DBG
		cout	<< _f << " "
			<< y1 << '-' << m1 <<  '-' << d1 <<  ' '
			<< h <<  ':' << m <<  ':' << s
			<<  '(' << serial <<  ") " << _f->name_long << endl;
		*/
		::_splitpath(_f->name_long, 0, 0, _fname, _ext);

		char _path_from[_MAX_PATH];
		char _path_to[_MAX_PATH];
		::_makepath(_path_from, _drive, _dir, _fname, _ext);

		char _num[256];
		sprintf(_num, _num_fmt, g_base + serial);

        if (g_include_date) {
            char *_filter = _num;
            while (*_filter == ' ') *_filter++ = '_';
		    sprintf(_fname, "%02d%02d%02d%s", y1 % 100, m1, d1, _num);
        } else {
			char *_filter = _num;
			while (*_filter == ' ') *_filter++ = '0';
            sprintf(_fname, "%s", _num);
        }

		::_makepath(_path_to, _drive, _dir, _fname, _ext);

		cout << _path_from << " -> " << _path_to << endl;
		if (!MoveFile(_path_from, _path_to)) {
			cerr	<< "Can't rename file: " << _path_from << " to " << _path_to
				<< "(" << GetLastError() << ")" << endl;
		}

		++it;
		_f0 = _f;
	} while (it != fs.files.end());
	fs.files.clear();

	if (g_recursive_directory) {
		__zero(fd);
		HANDLE hFind = ::FindFirstFile(_pattern, &fd);

		do {
			if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
				if (strcmp(fd.cFileName, ".") == 0
					|| strcmp(fd.cFileName, "..") == 0) continue;
				char _path_sub[_MAX_PATH];
				::_splitpath(fd.cFileName, 0, 0, _fname, _ext);
				::_makepath(_path_sub, _drive, _dir, _fname, _ext);

				::_splitpath(_pattern, 0, 0, _fname, _ext);
				strcat(_path_sub, "\\");
				strcat(_path_sub, _fname);
				if (strlen(_ext) > 0) {
					strcat(_path_sub, ".");
					strcat(_path_sub, _ext);
				}
				process(_path_sub);
			}
		} while (::FindNextFile(hFind, &fd));
		CloseHandle(hFind);
	}

	return 0;
}

int main(int argc, char* argv[])
{
	cout	<< "re-numbering file names / written by zauj.g.d. 2003.6.22" << endl;

	if (argc < 2) {
		cout	<< "syntax: " << endl
			<< "	renum [options] <files pattern> ..." << endl
			<< "options: " << endl
            << "    -D      include date yymmdd in file name" << endl
            << "    -w n    width of serial no, so pad 0's if actual length less than width" << endl
            << "    -b n    serial no starts from this number" << endl
			<< "    -H      use hex for serial no" << endl
			<< "    -h      include hidden file" << endl
			<< "    -r      include read-only file" << endl
			<< "    -d      include directory name" << endl
			<< "    -R      recursive directory" << endl
			;
		return -1;
	}

	do {
		argc--;
		argv++;
		if (**argv == '-') {
			char *opts = *argv;
			while (*++opts) {
				switch (*opts) {
                case 'D':
                    g_include_date = true;
                    break;
                case 'w':
                    if (argc > 1) {
                        argc--;
                        argv++;
                        int width = strtol(*argv, NULL, 0);
                        if (width <= 0 || width >= 16) {
                            cerr << "invalid option: width must in range [1,15]" << endl;
                            return -1;
                        }
                        g_width = width;
                    }
                    break;
                case 'b':
                    if (argc > 1) {
                        argc--;
                        argv++;
                        int base = strtol(*argv, NULL, 0);
                        if (base < 0) {
                            cerr << "invalid option: base must >= 0" << endl ;
                            return -1;
                        }
                        g_base = base;
                    }
                    break;
				case 'H':
					// using hex for unique-number
					g_hex_for_nn = true;
					break;
				case 'a':
					g_include_hidden = true;
					g_include_readonly = true;
					g_include_directory = true;
					break;
				case 'h':
					g_include_hidden = true;
					break;
				case 'r':
					g_include_readonly = true;
					break;
				case 'd':
					g_include_directory = true;
					break;
				case 'R':
					g_recursive_directory = true;
					break;
				default:
					cerr << "invalid option: -" << *opts << endl;
					break;
				}
			}
		} else {
			process(*argv);
		}
	} while (argc > 1);

	return 0;
}
