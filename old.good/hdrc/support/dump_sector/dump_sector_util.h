

#pragma once


#define SEPERATE_LINE				\
	"-----------------------------------------------------------\n"
#define DUMP_TITLE(title)			\
	cout << "\n" << title << "\n" << SEPERATE_LINE;
#define DUMP_IF_BIT(v, b)			\
	if ((v) & (b)) printf("\t" #b "\n");
#define DUMP_PROPERTY(obj, member)		\
	printf("%-30s= %12d (%Xh)\n", #member,	\
		obj->member, obj->member);
#define DUMP_PROPNAME(obj, member)              \
	printf("%-30s= ", #member);
#define DUMP_PROPERTY_BINARY(obj, member, l) {	\
	DUMP_PROPNAME(obj, member);		\
	printf("\n\t");				\
	DumpBytes((void *)obj->member, l);	\
	printf("\n"); }
#define DUMP_PROPERTY_STRING(obj, member, l) {	\
	DUMP_PROPNAME(obj, member);		\
	printf("\n\t");				\
	DumpString((void *)obj->member, l);	\
	printf("\n"); }

inline void DumpBytes(void * pv, int len) {
	BYTE *p = (BYTE *)pv;
	for (int i = 0; i < len; i++) {
		printf("%02x ", p[i]);
		if (i % 16 == 15) printf("\n\t");
	}
}

inline void DumpString(void *pv, int len, int bSZ = 1) {
	char *pbuf = (char *)pv;
	for (int i = 0; i < len; i++) {
		int c = pbuf[i];
		if (bSZ && c == 0) break;
		printf("%c", c);
	}
}

inline u64_t strtol64(char *sz, char **_endptr, int ordix) {
	u64_t n = 0;
	int c;
	bool zPrefix = false;
	int i = 0;
	int x;

	while (isspace(*sz)) sz++;
	while (c = sz[i]) {
		switch (c | 0x20) {
		case '0':
			if (!i) {
				zPrefix = true;
			} else {
				n = n * ordix + 0;
			}
			break;
		case 'x':
			if (zPrefix && i == 1) {
				if (ordix == 0) ordix = 16;
			} else {
				ASSERT(FALSE);		// invalid number
				n = 0;
				break;
			}
			break;
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
			x = (c | 0x20) - 'a' + 10;
		case '8':
		case '9':
			if (ordix == 8) {
				ASSERT(FALSE);		// invalid number
				n = 0;
				break;
			}
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
			if (!i) {
				if (ordix == 0) ordix = 10;	// [1-9] at the beginning
			}
			if (c <= '9') x = c - '0';
			n = n * ordix + x;
			break;
		default:
			//ASSERT(FALSE);		// invalid number
			//n = 0;
			break;
		}
		i++;
	}
	if (_endptr) *_endptr = sz + i;
	return n;
}

inline void output_u64(u64_t n, int ordix) {
	char *nc = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (n == 0) {
		printf("0");
		return;
	}

	char buf[200];
	int i = 198;
	buf[199] = '\0';
	for (;;) {
		buf[i] = nc[n % ordix];
		n = (n - n % ordix) / ordix;
		if (n == 0) break;
		i--;
		ASSERT(i > 0);
	}
	printf(buf + i);
}
