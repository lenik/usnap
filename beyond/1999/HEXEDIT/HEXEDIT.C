
#if defined (__unix__)
#	define INT	int
#	define UINT	unsigned int
#elif defined (_WIN32)
#	define INT	int
#	define UINT	unsigned int
#else
#	define INT	long
#	define UINT	unsigned long
#endif

#ifdef __unix__
#include <unistd.h>
#endif

#include "gds.h"
#include "hexedit.h"

#ifndef __unix__
#define strcasecmp	stricmp
#endif

int main(int argc, char **argv) {
	FILE *f = NULL;
	INT fsize;

	strcpy(filename, "");
	while (argc >= 2) {
		if (argv[1][0] == '-') {
			switch (argv[1][1]) {
			case 'm':
				memsize = atol(argv[1] + 2);
				break;
			case '?':
			case 'h':
				printf("hex [-?|h] [-m<initsize (kb)>] [filename]\n");
				break;
			default: ;
			}
		} else {
			strcpy(filename, argv[1]);
		}
		argc--;
		argv++;
	}

	if (strlen(filename) > 0) {
#ifndef R_OK
#	define R_OK	4	/* MS-DOS: 4: check for read permission */
#endif
		if (access(filename, R_OK) == 0) {
			if ((f = fopen(filename, "rb")) != NULL) {
				flen = getlen(f);
				if (flen > memsize * MEM_UNIT) {
					printf("memory streched for contain the whole file\n");
					memsize = flen / MEM_UNIT + 1;
				}
			} else {
				perror("can't open file");
				printf("continue? (Y/n) ");
				if (tolower(getchar()) == 'n') {
					goto end_clean;
				}
			}
		} else {
			printf("file not found, continue? (Y/n) ");
			if (tolower(getchar()) == 'n') {
				goto end_clean;
			}
		}
	}

	if ((buf = (PCHAR)calloc(memsize, MEM_UNIT)) == NULL) {
		printf("memory not enough: %ld\n", MEM_UNIT * memsize);
		return 1;
	}

	strcpy((char *)buf, HE_VERSION);

	if (f != NULL) {
		fsize = fread((void *)buf, 1, flen, f);
		if (fsize != flen) {
			printf("there may be errors during reading file, continue? (Y/n) ");
			if (tolower(getchar()) == 'n') {
				goto end_clean;
			}
		}
		fclose(f);
		f = NULL;
	}

	/* Begin */
	{
		INT c;
		char command = C_NOP;
		char *p1, *p2;
		INT startaddr, endaddr;
		INT fsize;
		char outfilename[1024];

		printf("memory allocated: %ld\n", memsize * MEM_UNIT);

		while (command != C_QUIT) {
			putchar('-');
			getin();
			if (strlen(ltrim(inputbuf)) == 0) inputbuf[0] = '\0';
			switch (inputbuf[0]) {
			case 'a':
				ip = next(inputbuf + 1, 0);
				if (strlen(ip) > 0) {
					char anatype[64], anaparam[256];
					strcpy(anaparam, pocstr(ip));
					strcpy(anatype, ip);
					analyse(anatype, anaparam);
				} else {
					printf("a <analyse module>\n");
				}
				command = C_ANALYSE;
				break;
			case 'd':
				if (strlen(ltrim(inputbuf + 1)) > 0) {
					startaddr = strtol(ltrim(inputbuf + 1), &p1, 16);
					if (p1 - inputbuf < strlen(inputbuf + 1)) {
						endaddr = strtol(ltrim(p1), &p2, 16);
						if (endaddr < startaddr) {
							endaddr = startaddr + PARA_LENGTH - 1;
						}
					} else {
						endaddr = startaddr + PARA_LENGTH - 1;
					}
					dumpdata(buf + startaddr, endaddr - startaddr + 1, startaddr);
					curaddr = endaddr + 1;
				} else {
					dumpdata(buf + curaddr, PARA_LENGTH, curaddr);
					curaddr += PARA_LENGTH;
					if (curaddr >= memsize * MEM_UNIT) curaddr = 0;
				}
				command = C_DUMP;
				break;
			case 'e':
				if (strlen(ltrim(inputbuf + 1)) > 0) {
					startaddr = strtol(ltrim(inputbuf + 1), &p1, 16);
					curaddr += editdata(buf + startaddr, startaddr);
				} else {
					curaddr += editdata(buf + curaddr, curaddr);
				}
				command = C_EDIT;
				break;
			case 's':
				command = C_SEARCH;
				break;
			case 'f':
				command = C_FILL;
				break;
			case 'w':
				if (strlen(inputbuf + 1) > 0) {
					strcpy(outfilename, ltrim(inputbuf + 1));
				} else {
					strcpy(outfilename, ltrim(filename));
				}
				if (strlen(outfilename) > 0) {
					if ((f = fopen(outfilename, "wb")) == NULL) {
						perror("can't open file for writing");
						printf("continue? (Y/n) ");
						if (tolower(getchar()) == 'n') {
							goto end_clean;
						}
					} else {
						fsize = fwrite((void *)(buf + writeoffset), 1, flen, f);
						if (fsize != flen) {
							printf("error happened during write file, continue? (Y/n) ");
							if (tolower(getchar()) == 'n') {
								goto end_clean;
							}
						}
					}
				} else {
					printf("you haven't specify filename, try again!\n");
				}
				command = C_WRITE;
				break;
			case 'v':
				printf(HE_VERSION);
				command = C_VERSION;
				break;
			case '?':
				if (inputbuf[1] == '?') {
					char lastcmd[512];
					switch (command) {
					case C_NOP:
						strcpy(lastcmd, "no operation");
						break;
					case C_ANALYSE:
						strcpy(lastcmd, "analyse");
						break;
					case C_DUMP:
						strcpy(lastcmd, "dump data");
						break;
					case C_EDIT:
						strcpy(lastcmd, "edit data");
						break;
					case C_WRITE:
						strcpy(lastcmd, "write to file");
						break;
					case C_SEARCH:
						strcpy(lastcmd, "search");
						break;
					case C_FILL:
						strcpy(lastcmd, "fill");
						break;
					case C_CONTROL:
						strcpy(lastcmd, "dump control");
						break;
					case C_REPLACE:
						strcpy(lastcmd, "built-in var replace");
						break;
					case C_TRANSLATE:
						strcpy(lastcmd, "constant translation");
						break;
					case C_CALC:
						strcpy(lastcmd, "calculation");
						break;
					case C_INIT:
						strcpy(lastcmd, "working space initialize");
						break;
					case C_HELP:
						strcpy(lastcmd, "help");
						break;
					case C_QUIT:
						strcpy(lastcmd, "quit");
						break;
					default:
						strcpy(lastcmd, "??unknown??");
					}

					printf("\
WORKING_SPACE: %lX (%ld) units (1 unit: %ld bytes)\n\
DUMP_CONTROL: %4lX\n\
FILENAME: %s	FILE_LENGTH: %ld\n\
LAST_OPERATION: %s\n\
",
						memsize, memsize, MEM_UNIT,
						dumpcontrol,
						filename, flen,
						lastcmd
					);
				} else {
					showhelp();
				}
				command = C_HELP;
				break;
			case 'c':
				switch (ltrim(inputbuf + 1)[0]) {
				case 'b':
					dumpcontrol = dumpcontrol & 0xFFF0 | DUMP_BYTE;
					break;
				case 'w':
					dumpcontrol = dumpcontrol & 0xFFF0 | DUMP_WORD;
					break;
				case 'd':
					dumpcontrol = dumpcontrol & 0xFFF0 | DUMP_DWORD;
					break;
				case 't':
					dumpcontrol = dumpcontrol & 0xFFF0 | DUMP_TWORD;
					break;
				case 'z':
					dumpcontrol = dumpcontrol & 0xFFF0 | DUMP_ASCIZ;
					break;
				case 's':
					dumpcontrol = dumpcontrol & 0xFFF0 | DUMP_STRING;
					break;
				case 'f':
					dumpcontrol = dumpcontrol & 0xFF0F | DUMP_HEX;
					break;
				case 'a':
					dumpcontrol = dumpcontrol & 0xFF0F | DUMP_DEC;
					break;
				case '8':
					dumpcontrol = dumpcontrol & 0xFF0F | DUMP_OCT;
					break;
				case '2':
					dumpcontrol = dumpcontrol & 0xFF0F | DUMP_BIN;
					break;
				case 'm':
					dumpcontrol ^= DUMP_MASKCHAR;
					break;
				case '#':
					dumpcontrol ^= DUMP_ADDRESS;
					break;
				default:
					printf("unknown control word!\n");
				}
				command = C_CONTROL;
				break;
			case 'r':
				switch (ltrim(inputbuf + 1)[0]) {
				case 'p':
					printf("current pointer: %lX\nnew offset: (0x- for hex) ", curaddr);
					getin();
					if (strlen(inputbuf) > 0) {
						curaddr = strtol(inputbuf, &p1, 0);
					}
					break;
				case 'o':
					printf("current write offset: %lX\nnew write offset: (0x- for hex) ", writeoffset);
					getin();
					if (strlen(inputbuf) > 0) {
						writeoffset = strtol(inputbuf, &p1, 0);
					}
					break;
				case 's':
					printf("current working size is %ld, you may change it here: ", memsize);
					getin();
					if (strlen(inputbuf) > 0) {
						INT l;
						if (strcasecmp(inputbuf, "flen") == 0) {
							l = flen;
						} else {
							l = strtol(inputbuf, &p1, 0);
						}
						if (l > memsize) {
							if (realloc((void *)buf, l * MEM_UNIT) == NULL) {
								printf("could not re-allocate the working buffer, request may be too large. \n");
							} else {
								printf("successful re-allocated, do you want to initialize the extra space to zero? (Y/n) ");
								if (tolower(getchar()) != 'n') {
									memset((void *)(buf + memsize), '\0', l * MEM_UNIT - memsize);
								}
								memsize = l;
							}
						} else if (l < memsize) {
							printf("operation may cause data lost, continue? (Y/n) ");
							if (tolower(getchar()) != 'n') {
								realloc((void *)buf, l);
								memsize = l;
							}
						} else {
							printf("size unchanged, do you force to re-allocate the space? (Y/n) ");
							if (tolower(getchar()) != 'n') {
								realloc((void *)buf, memsize);
							}
						}
					}
					break;
				case 'm':
					printf("current mask char is: %c, you can modify it here: ", maskchar);
					getin();
					if (strlen(ltrim(inputbuf)) > 0) {
						if (ltrim(inputbuf)[0] == '\\') {
							maskchar = ltrim(inputbuf)[1];
						} else {
							maskchar = (char)strtol(ltrim(inputbuf), &p1, 0);
						}
					}
					break;
				default:
					printf("unknown built-in var!\n");
				}
				command = C_REPLACE;
				break;
			case '.':
				if (strlen(ltrim(inputbuf + 1)) > 0) {
					UINT l = strtol(ltrim(inputbuf + 1), &p1, 0);
					printf("%XH = %ld = 0%o = %sb\n", l, l, l, tobinary(l, tmpdata, 0));
				}
				command = C_TRANSLATE;
				break;
			case '+': 	/* add */
			case '-': 	/* sub */
			case '_': 	/* rev-sub */
			case '*': 	/* mul */
			case '/': 	/* div */
			case '%': 	/* mod */
			case '>': 	/* shr */
			case '<': 	/* shl */
			case '&': 	/* and */
			case '|': 	/* or */
			case '^': 	/* xor */
				if (strlen(ltrim(inputbuf + 1)) > 0) {
					INT l1 = strtol(ltrim(inputbuf + 1), &p1, 0);
					INT l2 = 0;
					INT result;
					if (p1 - inputbuf < strlen(inputbuf + 1)) {
						l2 = strtol(ltrim(p1), &p2, 0);
					}
					switch (inputbuf[0]) {
					case '+': result = l1 + l2; break;
					case '-': result = l1 - l2; break;
					case '_': result = l2 - l1; break;
					case '*': result = l1 * l2; break;
					case '/': result = l1 / l2; break;
					case '%': result = l1 % l2; break;
					case '>': result = l1 >> l2; break;
					case '<': result = l1 << l2; break;
					case '&': result = l1 & l2; break;
					case '|': result = l1 | l2; break;
					case '^': result = l1 ^ l2; break;
					default: ;
					}
					printf("%ld %c %ld = \n\t%XH\n\t%ld\n\t0%o\n\t%sb\n", l1, inputbuf[0], l2, result, result, result, tobinary(result, tmpdata, 0));
					/* */
				}
				command = C_CALC;
				break;
			case 'i':
				memset((void *)buf, inputbuf[1], memsize * MEM_UNIT);
				command = C_INIT;
				break;
			case 'q':
				command = C_QUIT;
				break;
			case '\0':
				break;
			default:
				printf("invalid command\n");
				command = C_NOP;
			} /* switch */
		} /* while */
	} /* begin block */
	printf("bye-bye!\n");

end_clean:
	if (f != NULL) {
		fclose(f);
	}
	free((void *)buf);
	return 0;
}

void dumpdata(PCHAR data, INT length, INT display_start) {
	char strpos[128], tmpdata[128];
	INT pos = 0, lastpos = 0;
	INT loopi = 0, loope = 15, loopscale = 1;

	switch (dumpcontrol & 0xF) {
	case DUMP_BYTE:
	case DUMP_WORD:
	case DUMP_DWORD:
	case DUMP_TWORD:
		break;
	case DUMP_ASCIZ:
	case DUMP_STRING:
		loope = 1;
		break;
	}

	switch (dumpcontrol & 0xF0) {
	case DUMP_HEX: loopscale = 1; break;
	case DUMP_DEC: loopscale = 2; break;
	case DUMP_OCT: loopscale = 2; break;
	case DUMP_BIN: loopscale = 4; break;
	}

	while (pos < length) {
		if (loopi == 0) {
			sprintf(strpos, "%08lX: ", display_start + pos);
			if (dumpcontrol & DUMP_ADDRESS) printf("%s", strpos);
		}

		switch (dumpcontrol & 0xF) {
		case DUMP_BYTE:
			switch (dumpcontrol & 0xF0) {
			case DUMP_HEX:
				printf("%02X", data[pos]); break;
			case DUMP_DEC:
				printf("%3d", data[pos]); break;
			case DUMP_OCT:
				printf("%03o", data[pos]); break;
			case DUMP_BIN:
				printf("%s", tobinary(data[pos], tmpdata, 8));
				break;
			}
			pos++;
			loopi += loopscale;
			break;
		case DUMP_WORD:
			{
				UINT w = (data[pos + 1] << 8) + data[pos];
				switch (dumpcontrol & 0xF0) {
				case DUMP_HEX:
					printf("%04lX", w); break;
				case DUMP_DEC:
					printf("%6ld", w); break;
				case DUMP_OCT:
					printf("%06lo", w); break;
				case DUMP_BIN:
					printf("%s", tobinary(w, tmpdata, 16));
					break;
				}
			}
			pos += 2;
			loopi += loopscale << 1;
			break;
		case DUMP_DWORD:
			{
				UINT dw = (data[pos + 3] << 24) + (data[pos + 2] << 16) + (data[pos + 1] << 8) + data[pos];
				switch (dumpcontrol & 0xF0) {
				case DUMP_HEX:
					printf("%08lX", dw); break;
				case DUMP_DEC:
					printf("%10ld", dw); break;
				case DUMP_OCT:
					printf("%11lo", dw); break;
				case DUMP_BIN:
					printf("%s", tobinary(dw, tmpdata, 32));
					break;
				}
			}
			pos += 4;
			loopi += loopscale << 2;
			break;
		case DUMP_ASCIZ:
			{
				char c;
				while ((c = data[pos++]) != '\0') {
					if (dumpcontrol & DUMP_MASKCHAR) {
						c &= 0x7F;
						c = c < 0x20 ? maskchar : c;
					}
					putchar(c);
				}
			}
			loopi++;
			break;
		case DUMP_STRING:
			{
				INT stringlen = data[pos++];
				while (stringlen--) {
					char c = data[pos++];
					if (dumpcontrol & DUMP_MASKCHAR) {
						c &= 0x7F;
						c = c < 0x20 ? maskchar : c;
					}
					putchar(c);
				}
			}
			loopi++;
			break;
		default: ;
		} /* switch dumpcontrol & 0xF */

		putchar(loopi == (loope / 2) + 1 ? '-' : ' ');

		if (loopi > loope || pos == length) {
			switch (dumpcontrol & 0xF) {
			case DUMP_BYTE:
			case DUMP_WORD:
			case DUMP_DWORD:
			case DUMP_TWORD:
				putchar(' ');
				for (; lastpos < pos; lastpos++) {
					CHAR c = data[lastpos];
					if (dumpcontrol & DUMP_MASKCHAR) {
						c &= 0x7F;
						putchar(c < 0x20 ? maskchar : c);
					} else {
						putchar(c);
					}
				}
				break;
			case DUMP_ASCIZ:
			case DUMP_STRING:
				break;
			default: ;
			}
			putchar('\n');
			loopi = 0;
		}
	} /* while length > 0 */
	if (loopi != 0) putchar('\n');
}

void dumpbytes(PCHAR data, INT length, INT showchar) {
	INT l;
	for (l = 0; l < length; l++) {
		switch (dumpcontrol & 0xF0) {
		case DUMP_HEX:
			printf("%02X ", data[l]); break;
		case DUMP_DEC:
			printf("%3d ", data[l]); break;
		case DUMP_OCT:
			printf("%3o ", data[l]); break;
		case DUMP_BIN:
			printf("%8s ", tobinary(data[l], tmpdata, 0)); break;
		default: ;
		}
	}
	if (showchar) {
		printf(" (\"");
		for (l = 0; l < length; l++) {
			char c = data[l];
			if (dumpcontrol & DUMP_MASKCHAR) {
				c &= 0x7F;
				if (c < 0x20) c = maskchar;
			}
			putchar(c);
		}
		printf("\") ");
	}
}

INT editdata(PCHAR data, INT start_offset) {
	INT p = 0;
	char strpos[512];
	char inputbuf[512];
	INT markquit = 0;

	for (;markquit == 0;) {
		sprintf(strpos, "%08lX: ", start_offset + p);
		printf(strpos);

		switch(dumpcontrol & 0xF) {
		case DUMP_BYTE:
			printf("%02X ", data[p]);
			getin();
			if (strlen(ltrim(inputbuf)) != 0) {
				data[p] = (CHAR)strtol(inputbuf, NULL, 16);
			} else markquit = 1;
			p++;
			break;
		case DUMP_WORD:
			printf("%04X ", (data[p + 1] << 8) + data[p]);
			getin();
			if (strlen(ltrim(inputbuf)) != 0) {
				UINT w = strtol(inputbuf, NULL, 16);
				data[p + 1] = w >> 8;
				data[p] = w & 0xFF;
			} else markquit = 1;
			p += 2;
			break;
		case DUMP_DWORD:
			printf("%08lX ", (data[p + 3] << 24) + (data[p + 2] << 16) + (data[p + 1] << 8) + data[p]);
			getin();
			if (strlen(ltrim(inputbuf)) != 0) {
				UINT dw = strtol(inputbuf, NULL, 16);
				data[p + 3] = dw >> 24;
				data[p + 2] = dw & 0xFF0000 >> 16;
				data[p + 1] = dw & 0xFF00 >> 8;
				data[p] = dw & 0xFF;
			} else markquit = 1;
			p += 4;
			break;
		} /* switch dumpcontrol & 0xF */
	}
	return p;
}

/*********************************************************************************************
 *  ANALYSE MODULE
 *  CURRENTLY SUPPORT:
 *    EXECUTABLE FILES ->
 *      ELF	ELF32, ELF64
 *      *COFF
 *      *A.OUT
 *      *MS-DOS	MZ
 *      *MS-WIN	PE, NE
 *    FILE SYSTEMS ->
 *      EXT2
 *      *VFAT	FAT-16, FAT-32
 *	*ISO9660
 *********************************************************************************************/

PCHAR strndx(PCHAR strtbl, INT index) {
	PCHAR curstr = strtbl;
	for (;index > 0; index--) {
		curstr += strlen((char *)curstr) + 1;
	}
	return curstr;
}

void analyse(char *anatype, char *param) {
	PCHAR mem = buf + curaddr;
	INT msize = memsize - curaddr;

	if (strcmp(anatype, "elf") == 0) {
		/* -a elf 32|64 */
		INT elfclass = mem[EI_CLASS];
		if (memcmp((void *)(mem + EI_MAG0), ELFMAG, SELFMAG)) {
			printf("it doesn't seem to a valid ELF type executable file, continue? (Y/n) ");
			if (tolower(getchar()) == 'n') {
				return;
			}
		}
		if (strcmp(param, "32") == 0) elfclass = ELFCLASS32;
		else if (strcmp(param, "64") == 0) elfclass = ELFCLASS64;
		switch (elfclass) {
		case ELFCLASSNONE:
			printf("invalid class (EI_CLASS = ELFCLASSNONE), analyse stopped, use <elf 32|64> to force ELF class. \n");
			return;
		case ELFCLASS32:
			/* ELF - Begin */
			do {
				char *pp;
				Elf32_Ehdr *ehdr = (Elf32_Ehdr *)mem;

				if (elfclass == ELFCLASS32) printf("ELF32> ");
				else if (elfclass == ELFCLASS64) printf("ELF64> ");
				getin();
				ip = next(inputbuf, 0);
				if (strlen(ip) == 0) continue;
				inP[1] = inP[2] = inP[3] = inP[4] = 0;
				getparams(ip + 1, inP);

				switch (ip[0]) {
				case 'h': /* print header */
					printf("\nElf32_Ehdr ehdr : \n\n");
					printf("uchar\te_ident[16] \t= ");
					dumpbytes(ehdr->e_ident, EI_NIDENT, 0);
					printf("\n\te_ident[EI_CLASS (4)] \t= ");
					switch (ehdr->e_ident[EI_CLASS]) {
					case ELFCLASSNONE: printf("ELFNONE (0) : invalid class"); break;
					case ELFCLASS32: printf("ELFCLASS32 (1) ; 32-bit objects"); break;
					case ELFCLASS64: printf("ELFCLASS64 (2) : 64-bit objects"); break;
					default: printf("ELFCLASS???? (0x%02X) : unknown class", ehdr->e_ident[EI_CLASS]);
					}
					printf("\n\te_ident[EI_DATA (5)] \t= ");
					switch (ehdr->e_ident[EI_DATA]) {
					case ELFDATANONE: printf("ELFDATANONE (0) : invalid data encoding"); break;
					case ELFDATA2LSB: printf("ELFDATA2LSB (1) ; 2's complement, lit-endian"); break;
					case ELFDATA2MSB: printf("ELFDATA2MSB (2) : 2's complement, big-endian"); break;
					default: printf("ELFDATA???? (0x%02X) : unknown data encoding", ehdr->e_ident[EI_DATA]);
					}
					printf("\n\te_ident[EI_VERSION (6)]\t= ");
					switch (ehdr->e_ident[EI_VERSION]) {
					case EV_NONE: printf("EV_NONE (0) : invalid ELF version"); break;
					case EV_CURRENT: printf("EV_CURRENT (1): current version"); break;
					default: printf("EV_???? (0x%02X) : unknown ELF version");
					}
					printf("\n\te_ident[EI_OSABI (7)] \t\t= ");
					switch (ehdr->e_ident[EI_OSABI]) {
					case ELFOSABI_SYSV: printf("ELFOSABI_SYSV (0) : UnixSysV ABI"); break;
					case ELFOSABI_HPUX: printf("ELFOSABI_HPUX (1) : HP-UX"); break;
					case ELFOSABI_STANDALONE: printf("ELFOSABI_STANDALONE (255) : Standalone (embedded) application"); break;
					default: printf("ELFOSABI_???? (0x%02X) : unknown OS ABI");
					}
					printf("\n\te_ident[EI_ABIVERSION (8)] \t= 0x%02X\n", ehdr->e_ident[EI_ABIVERSION]);
					printf("ui16\te_type \t= ");
					switch (ehdr->e_type) {
					case ET_NONE: printf("ET_NONE (0) : no file type"); break;
					case ET_REL: printf("ET_REL (1) : relocatable file"); break;
					case ET_EXEC: printf("ET_EXEC (2) : executable file"); break;
					case ET_DYN: printf("ET_DYN (3) : shared object file"); break;
					case ET_CORE: printf("ET_CORE (4) : core file"); break;
					default: printf("ET_???? (0x%X) : unknown type", ehdr->e_type); break;
					}
					printf("\nui16\te_machine \t= ");
					switch (ehdr->e_machine) {
					case EM_NONE: printf("ET_NONE (0) : no machine"); break;
					case EM_M32: printf("ET_M32 (1) : AT&T WE 32100"); break;
					case EM_SPARC: printf("ET_SPARC (2) : SUN SPARC"); break;
					case EM_386: printf("EM_386 (3) : Intel 80386"); break;
					case EM_68K: printf("EM_68K (4) : Motorola m68k family"); break;
					case EM_88K: printf("EM_88K (5) : Motorola m88k family"); break;
					case EM_486: printf("EM_486 (6) : Intel 80486"); break;
					case EM_860: printf("EM_860 (7) : Intel 80860"); break;
					case EM_MIPS: printf("EM_MIPS (8) : MIPS R3000 big-endian"); break;
					case EM_S370: printf("EM_S370 (9) : Amdahl"); break;
					case EM_MIPS_RS4_BE: printf("EM_MIPS_RS4_BE (10) : MIPS R4000 big-endian"); break;
					case EM_RS6000: printf("EM_RS6000 (11) : RS6000"); break;
					case EM_PARISC: printf("EM_PARISC (15) : HPPA"); break;
					case EM_nCUBE: printf("EM_nCUBE (16) : nCUBE"); break;
					case EM_VPP500: printf("EM_VPP500 (17) : Fujitsu VPP500"); break;
					case EM_SPARC32PLUS: printf("EM_SPARC32PLUS (18) : Sun's \"v8plus\""); break;
					case EM_960: printf("EM_960 (19) : Intel 80960"); break;
					case EM_PPC: printf("EM_PPC (20) : PowerPC"); break;
					case EM_V800: printf("EM_V800 (36) :  NEC V800 series"); break;
					case EM_FR20: printf("EM_FR20 (37) :  Fujitsu FR20"); break;
					case EM_RH32: printf("EM_RH32 (38) :  TRW RH32"); break;
					case EM_MMA: printf("EM_MMA (39) :  Fujitsu MMA"); break;
					case EM_ARM: printf("EM_ARM (40) :  ARM"); break;
					case EM_FAKE_ALPHA: printf("EM_FAKE_ALPHA (41) :  Digital Alpha"); break;
					case EM_SH: printf("EM_SH (42) :  Hitachi SH"); break;
					case EM_SPARCV9: printf("EM_SPARCV9 (43) :  SPARC v9 64-bit"); break;
					case EM_TRICORE: printf("EM_TRICORE (44) :  Siemeus Tricore"); break;
					case EM_ARC: printf("EM_ARC (45) :  Argonaut RISC Core"); break;
					case EM_H8_300: printf("EM_H8_300 (46) :  Hitachi H8/300"); break;
					case EM_H8_300H: printf("EM_H8_300H (47) :  Hitachi H8/300H"); break;
					case EM_H8S: printf("EM_H8S (48) :  Hitachi H8S"); break;
					case EM_H8_500: printf("EM_H8_500 (49) :  Hitachi H8/500"); break;
					case EM_IA_64: printf("EM_IA_64 (50) :  Intel Merced"); break;
					case EM_MIPS_X: printf("EM_MIPS_X (51) :  Stanford MIPS-X"); break;
					case EM_COLDFIRE: printf("EM_COLDFIRE (52) :  Motorola Coldfire"); break;
					case EM_68HC12: printf("EM_68HC12 (53) :  Motorola M68HC12"); break;
					default: printf("EM_???? (0x%X) : unknown machine", ehdr->e_machine);
					}
					printf("\nui32\te_version \t= ");
					if (ehdr->e_version == EV_NONE) printf("EV_NONE (0) : invalid version");
					else if (ehdr->e_version == EV_CURRENT) printf("EV_CURRENT (1) : current version");
					printf("\nui32\te_entry \t= 0x%08X\n", ehdr->e_entry);
					printf("ui32\te_phoff \t= 0x%08X\n", ehdr->e_phoff);
					printf("ui32\te_shoff \t= 0x%08X\n", ehdr->e_shoff);
					printf("ui32\te_flags \t= 0x%08X\n", ehdr->e_flags);
					printf("ui16\te_ehsize \t= 0x%04X\n", ehdr->e_ehsize);
					printf("ui16\te_phentsize \t= 0x%04X\n", ehdr->e_phentsize);
					printf("ui16\te_phnum \t= 0x%04X\n", ehdr->e_phnum);
					printf("ui16\te_shentsize \t= 0x%04X\n", ehdr->e_shentsize);
					printf("ui16\te_shnum \t= 0x%04X\n", ehdr->e_shnum);
					printf("ui16\te_shstrndx \t= 0x%04X\n", ehdr->e_shstrndx);
					break;
				case 'p':
					/* print specify phdr */
					{
						INT nindex = inP[1], t;
						INT phdroff = ehdr->e_phoff + nindex * ehdr->e_phentsize;
						Elf32_Phdr *phdr = (Elf32_Phdr *)(mem + phdroff);
						if (nindex >= ehdr->e_phnum) {
							printf("index out of ehdr->e_phnum, continue? (y/N) ");
							if (tolower(getchar()) != 'y') {
								break;
							}
						}
						printf("\nElf32_Phdr #%04XH (%ld) < Offset: %08XH, %ld >\n\n", nindex, nindex, phdroff, phdroff);
						printf("ui32\tp_type \t\t= ");
						switch (phdr->p_type) {
						case PT_NULL: printf("PT_NULL (0) :  Program header table entry unused "); break;
						case PT_LOAD: printf("PT_LOAD (1) :  Loadable program segment "); break;
						case PT_DYNAMIC: printf("PT_DYNAMIC (2) :  Dynamic linking information "); break;
						case PT_INTERP: printf("PT_INTERP (3) :  Program interpreter "); break;
						case PT_NOTE: printf("PT_NOTE (4) :  Auxiliary information "); break;
						case PT_SHLIB: printf("PT_SHLIB (5) :  Reserved "); break;
						case PT_PHDR: printf("PT_PHDR (6) :  Entry for header table itself "); break;
						default: printf("PT_???? (0x%08X) : unknown segment type", phdr->p_type);
						}
						printf("\nui32\tp_offset \t= 0x%08X\n", phdr->p_offset);
						printf("ui32\tp_vaddr \t= 0x%08X\n", phdr->p_vaddr);
						printf("ui32\tp_paddr \t= 0x%08X\n", phdr->p_paddr);
						printf("ui32\tp_filesz \t= 0x%08X\n", phdr->p_filesz);
						printf("ui32\tp_memsz \t= 0x%08X\n", phdr->p_memsz);
						printf("ui32\tp_flags \t= 0x%08X ", phdr->p_flags);
						t = 0;
						if (phdr->p_flags & PF_X) { if (t) printf("| "); printf("PF_X "); t = 1; }
						if (phdr->p_flags & PF_W) { if (t) printf("| "); printf("PF_W "); t = 1; }
						if (phdr->p_flags & PF_R) { if (t) printf("| "); printf("PF_R "); t = 1; }
						printf("\nui32\tp_align \t= 0x%08X\n", phdr->p_align);
					}
					break;
				case 's': /* print specify shdr */
					{
						INT nindex = inP[1], t;
						INT shdroff = ehdr->e_shoff + nindex * ehdr->e_shentsize;
						INT shstroff = ((Elf32_Shdr *)(mem + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize))->sh_offset;
						Elf32_Shdr *shdr = (Elf32_Shdr *)(mem + shdroff);
						if (nindex >= ehdr->e_shnum) {
							printf("index out of ehdr->e_shnum, continue? (y/N) ");
							if (tolower(getchar()) != 'y') {
								break;
							}
						}
						printf("\nElf32_Shdr #%04XH (%ld) < Offset: %08XH, %ld >\n\n", nindex, nindex, shdroff, shdroff);
						printf("ui32\tsh_name \t\t= 0x%08X ", shdr->sh_name);
						switch (shdr->sh_name) {
						case SHN_UNDEF: printf("SHN_UNDEF : undefined section"); break;
						case SHN_ABS: printf("SHN_ABS : associated symbol is absolute"); break;
						case SHN_COMMON: printf("SHN_COMMON : associated symbol is common"); break;
						default: ;
						}
						printf(" (%s)", mem + shstroff + shdr->sh_name);
						printf("\nui32\tsh_type \t\t= ");
						switch (shdr->sh_type) {
						case SHT_NULL: printf("SHT_NULL (0) :  Section header table entry unused "); break;
						case SHT_PROGBITS: printf("SHT_PROGBITS (1) :  Program data "); break;
						case SHT_SYMTAB: printf("SHT_SYMTAB (2) :  Symbol table "); break;
						case SHT_STRTAB: printf("SHT_STRTAB (3) :  String table "); break;
						case SHT_RELA: printf("SHT_RELA (4) :  Relocation entries with addends "); break;
						case SHT_HASH: printf("SHT_HASH (5) :  Symbol hash table "); break;
						case SHT_DYNAMIC: printf("SHT_DYNAMIC (6) :  Dynamic linking information "); break;
						case SHT_NOTE: printf("SHT_NOTE (7) :  Notes "); break;
						case SHT_NOBITS: printf("SHT_NOBITS (8) :  Program space with no data (bss) "); break;
						case SHT_REL: printf("SHT_REL (9) :  Relocation entries, no addends "); break;
						case SHT_SHLIB: printf("SHT_SHLIB (10) :  Reserved "); break;
						case SHT_DYNSYM: printf("SHT_DYNSYM (11) :  Dynamic linker symbol table "); break;
						case SHT_SUNW_COMDAT: printf("SHT_SUNW_COMDAT (0x6FFFFFFB)"); break;
						case SHT_SUNW_syminfo: printf("SHT_SUNW_syminfo (0x6FFFFFFC)"); break;
						case SHT_GNU_verdef: printf("SHT_GNU_verdef (0x6ffffffd) :  Version definition section.  "); break;
						case SHT_GNU_verneed: printf("SHT_GNU_verneed (0x6ffffffe) :  Version needs section.  "); break;
						case SHT_GNU_versym: printf("SHT_GNU_versym (0x6fffffff) :  Version symbol table.  "); break;
						default:
							printf("SHT_???? (0x%08X) : unknown segment header type", shdr->sh_type);
						}
						printf("\nui32\tsh_flags \t\t= 0x%08X ", shdr->sh_flags);
						t = 0;
						if (shdr->sh_flags & SHF_EXECINSTR) { if (t) printf("| "); printf("SHF_EXECINSTR "); t = 1; }
						if (shdr->sh_flags & SHF_ALLOC) { if (t) printf("| "); printf("SHF_ALLOC "); t = 1; }
						if (shdr->sh_flags & SHF_WRITE) { if (t) printf("| "); printf("SHF_WRITE "); t = 1; }
						printf("\nui32\tsh_addr \t\t= 0x%08X\n", shdr->sh_addr);
						printf("ui32\tsh_offset \t\t= 0x%08X\n", shdr->sh_offset);
						printf("ui32\tsh_size \t\t= 0x%08X\n", shdr->sh_size);
						printf("ui32\tsh_link \t\t= 0x%08X\n", shdr->sh_link);
						printf("ui32\tsh_info \t\t= 0x%08X\n", shdr->sh_info);
						printf("ui32\tsh_addralign \t\t= 0x%08X\n", shdr->sh_addralign);
						printf("ui32\tsh_entsize \t\t= 0x%08X\n", shdr->sh_entsize);
					}
					break;
				case '?':
					printf("\
ELF analyse commands: \n\
h: 	print ehdr (ELF Header)\n\
p <n>:	print the n. phdr (Program Header)\n\
s <n>: 	print the n. shdr (Section Header)\n\
?: 	this help\n");
					break;
				case 'q':
					break;
				default:
					printf("invalid elf analyse command!\n");
				}
			} while (ip[0] != 'q');
			/* ELF - End */
			break;
		case ELFCLASS64:
			break;
		default:
			printf("unrecognised class: EI_CLASS = %ld, analyse stopped, use <elf 32|64> to force ELF class. \n");
			return;
		}
		printf("elf analyse ended, analyse successful returned. \n");
	} else if (strcmp(anatype, "coff") == 0) {
	} else if (strcmp(anatype, "ext2") == 0) {
		/* -a ext2 */
		printf("couldn't initialize ext2 filesystem working space!\n");

/*
		INT elfclass = mem[EI_CLASS];
		switch (elfclass) {
		case ELFCLASSNONE:
			printf("invalid class (EI_CLASS = ELFCLASSNONE), analyse stopped, use <elf 32|64> to force ELF class. \n");
			return;
		case ELFCLASS32:
			do {
				INT para1 = 0, para2 = 0;
				char *pp;
				if (elfclass == ELFCLASS32) printf("ELF32> ");
				getin();
*/
	} else if (strcmp(anatype, "dev") == 0) {
		/* device analyse */
		FILE *devf = NULL;
		INT devopen = 0;
		static char devfname[1024];

		do {
			printf("DEVICE> ");
			ip = next(getin(), 0);
			if (strlen(ip) == 0) continue;
			switch (*ip) {
			case 'l': 	/* list devices */
				{
					char *pathname = ".";
					ip = next(ip + 1, 0);
					if (strlen(ip) != 0) pathname = ip;
					listdir(pathname);
				}
				break;
			case 'o': 	/* open device */
				{
					char *mode = "rb";
					char *newdevfname = NULL;
					ip = next(ip + 1, 0);
					ip = next(pocstr(newdevfname = ip), 0);
					if (strlen(newdevfname) == 0) {
						printf("no filename specified. \n");
						break;
					}
					if (strlen(ip) != 0) mode = ip;
					if (devf != NULL) {
						printf("you haven't closed the previous device yet, close it? (Y/n) ");
						if (tolower(getchar()) == 'n') break;
						else {
							if (fclose(devf) != 0) {
								printf("couldn't close the file, continue force? (y/N) ");
								if (tolower(getchar()) != 'y') break;
							}
						}
					}
					if ((devf = fopen(newdevfname, mode)) == NULL) {
						perror("error during device open");
					} else {
						devopen = 1;
						strcpy(devfname, newdevfname);
					}
				}
				break;
			case 'O': 	/* open 64-bit device */
				{
#ifndef __USE_FILE_OFFSET64
					printf("system doesn't support 64-bit file operation\n");
#else
					printf("this function hasn't supported yet. \n");
#endif
				}
				break;
			case 'm':
				if (!devopen) {
					printf("you should open a device first. \n");
				} else {
					char *mode = "rb";
				}
				break;
			case 'c':
				if (devopen) {
					if (fclose(devf) != 0) {
						perror("couldn't close the file");
					} else {
						devf = NULL;
					}
				} else {
					printf("you should open a device first. \n");
				}
				break;
			case 's':
				if (devopen) {
					INT off = 0;
					INT whence = SEEK_SET;
					char *from;
					ip = next(ip + 1, 0);
					off = strtol(ip, NULL, 0);
					from = next(ip, 1);
					if (from != NULL && strlen(from) > 0) {
						if (from[0] == '>') whence = SEEK_SET;
						else if (from[0] == '+') whence = SEEK_CUR;
						else if (from[0] == '<') whence = SEEK_END;
						else if (strcasecmp(from, "seek_set")) whence = SEEK_SET;
						else if (strcasecmp(from, "seek_cur")) whence = SEEK_CUR;
						else if (strcasecmp(from, "seek_end")) whence = SEEK_END;
					}
					printf("seeking device %s to %ld (%XH) from %s\n", devfname, off, off, whence == SEEK_SET ? "BEGIN" : whence == SEEK_CUR ? "CURRENT POS" : "END");
					if (fseek(devf, off, whence) == -1) {
						perror("error during seek");
					}
				} else {
					printf("before seek, you should open a device. \n");
				}
				break;
			case 'r':
				if (!devopen) {
					printf("open a device before reading. \n");
					break;
				} else {
					INT memoffset = 0;
					INT readsize = 0, factread;
					INT canceled = 0;

					if (inP[0] > 0) memoffset = inP[1];
					if (inP[0] > 1) {
						readsize = inP[2];
					} else {
						readsize = getlen(devf);
					}
					if (memoffset >= memsize * MEM_UNIT) {
						printf("offset out of bound, set it to the minimize requirement? (y/N) ");
						if (tolower(getchar()) == 'y') {
							memoffset = memsize * MEM_UNIT - readsize;
						} else {
							canceled = 1;
						}
					}
					if (readsize > memsize * MEM_UNIT - memoffset) {
						printf("file too large to confit in the working-space, stretch the working-space, reading part of file, or cancel? (s/P/c) ");
						switch (tolower(getchar())) {
						case 's':
							/* callext('r', 's', readsize); */
							printf("bug version, sorry!\n");
							break;
						case 'c':
							canceled = 1;
							break;
						default:
							readsize = memsize * MEM_UNIT - memoffset;
						}
					}
					if (canceled) break;
					printf("reading %ld bytes from file %s + %ld bytes to memory + %ld bytes...\n", readsize, devfname, ftell(devf), memoffset);
					factread = fread((void *)(buf + memoffset), 1, readsize, devf);
					if (factread != readsize) {
						perror("not all has been loaded, some errors may be happened");
					}
				} /* if devopen */
				break;
			case 'w':
				if (!devopen) {
					printf("open a device before writing. \n");
					break;
				} else {
					INT memoffset = 0;
					INT writesize = 0, factwrite;
					INT canceled = 0;

					if (inP[0] > 0) memoffset = inP[1];
					if (inP[0] > 1) writesize = inP[2];
					else writesize = getlen(devf);
					if (memoffset >= memsize * MEM_UNIT) {
						printf("offset out of bound, set it to the last part of memory which contain the flen size datas? (y/N) ");
						if (tolower(getchar()) == 'y') {
							memoffset = memsize * MEM_UNIT - writesize;
						} else
							canceled = 1;
					}
					if (writesize > memsize * MEM_UNIT - memoffset) {
						printf("there're no so many bytes to write, cut the extra bytes? (Y/n) ");
						if (tolower(getchar()) != 'n') {
							writesize = memsize * MEM_UNIT - memoffset;
						}
					}
					if (canceled) break;
					factwrite = fwrite((void *)(buf + memoffset), 1, writesize, devf);
					if (factwrite != writesize) {
						perror("not all has been writed, some errors may be happened");
					}
				} /* if devopen */
				break;
			case 'i': 	/* device info */
				if (!devopen) {
					printf("before get info, you should open a device. \n");
					break;
				}
				printf("\
DEVICE ANALYSE :: INFO\n\
DEVICE_POS: 	%8XH, %ld\n",
					ftell(devf), ftell(devf)
				);
				{
#if defined(__unix__)
					struct stat a_stat;
					INT r;
					if ((r = stat(devfname, &a_stat)) != 0) {
						perror("error happened when getting statistics of file");
						break;
					}
					printf("-\nDEVICE ANALYSE :: INFO / UNIX VERSION\n");
					printf("DEVICE_ID: 	%8XH, %ld\n", a_stat.st_dev, a_stat.st_dev);
					printf("DEVICE_INODE: 	%8XH, %ld\n", a_stat.st_ino, a_stat.st_ino);
					printf("DEVICE_MODE: 	%8XH, %ld\n", a_stat.st_mode, a_stat.st_mode);
					printf("DEVICE_NUMLINK:	%8XH, %ld\n", a_stat.st_nlink, a_stat.st_nlink);
					printf("DEVICE_UID: 	%8XH, %ld\n", a_stat.st_uid, a_stat.st_uid);
					printf("DEVICE_GID: 	%8XH, %ld\n", a_stat.st_gid, a_stat.st_gid);
					printf("DEVICE_RDEV: 	%8XH, %ld\n", a_stat.st_rdev, a_stat.st_rdev);
					printf("DEVICE_SIZE: 	%8XH, %ld\n", a_stat.st_size, a_stat.st_size);
					printf("DEVICE_ACCESSTIME:	%s\n", ctime(&a_stat.st_atime));
					printf("DEVICE_MODIFYTIME:	%s\n", ctime(&a_stat.st_mtime));
					printf("DEVICE_CHANGETIME: 	%s\n", ctime(&a_stat.st_ctime));
#elif defined(_WIN32)
					printf("\
DEVICE ANALYSE :: INFO / WINDOWS 95 VERSION\n");
#elif defined(__MSDOS__)
					struct ftime a_ftime;
					INT a_fhandle;
					INT devsize;
					if ((a_fhandle = open(devfname, O_BINARY | O_RDONLY)) == 0) {
						printf("error during file open. (IO function failed!)\n");
						break;
					}
					devsize = filelength(a_fhandle);
					getftime(a_fhandle, &a_ftime);
					printf("\
-\n\
DEVICE ANALYSE :: INFO / MS-DOS VERSION\n\
DEVICE_SIZE: 	%8XH, %ld\n\
DEVICE_T_YEAR: 	%ld\n\
DEVICE_T_MONTH:	%ld\n\
DEVICE_T_DAT: 	%ld\n\
DEVICE_T_HOUR: 	%ld\n\
DEVICE_T_MIN:	%ld\n\
DEVICE_T_SEC:	%ld\n",
						devsize, devsize,
						a_ftime.ft_year,
						a_ftime.ft_month,
						a_ftime.ft_day,
						a_ftime.ft_hour,
						a_ftime.ft_min,
						a_ftime.ft_tsec
					);
					close(a_fhandle);
#endif
				}
				break;
			case '?':
				if (ip[1] == '?') {
					printf("\
DEVICE ANALYSE :: STATUS\n\
DEVICE_OPENED = [%s]\n\
DEVICE_NAME = [%s], DEVICE_HANDLE = [%ld, %XH]\n\
ERROR = [%ld, %08XH]\n",
						(char *)strBool[devopen],
						devfname, devf, devf,
						errno, errno);
				} else {
					printf("\
DEVICE ANALYSE\n\
o <devname> [<mode>=rb]\n\
		open device (64-bit: O)\n\
m [<mode>=rb]	change mode\n\
c		close device\n\
s [<fileoffset>=0] [<whence>=SEEK_SET]\n\
		seek device, whence: SEEK_SET|> SEEK_CUR|+ SEEK_END|<\n\
r [<memoffset>=0] [<size>=flen]\n\
		read file to work space\n\
w [<memoffset>=0] [<size>=flen]\n\
		write work space to file\n\
? show this help	?? show status\n");
				}
				break;
			case 'q':
				if (devf != NULL) fclose(devf);
				break;
			default:
				printf("command unrecognised!\n");
			} /* switch */
		} while (*ip != 'q'); /* do */
		printf("normal returned. \n");
	} else {
		printf("no such type in extra analyse system, or it doesn't support that now. \n");
	}
}
