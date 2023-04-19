
// Article Test King 	Ver 1.00  // By DanSei  46K MEM
//1996

#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<stdlib.h>
#include "_scomp.h"

#define FAR
#define MALLOC	malloc

int	nwide = 20, ndepth = 4;

void 	version(int k)
{
	printf("syntax:tk3 <dest> [<src=\"tksource.txt\">]\n\
格式:  tk3 <比较文件> [<模版文件,默认tksource.txt>]\n");
}

int main(int argc, char **argv) {
	FILE *feach, *ftmpl;

	printf("fuzzy compare 模糊流比较[ANSI] 谢继雷/桃壳软件 2001\n");
	if ((argc <= 1) || (argc >= 4)) {
		version(0);
		return 2;
	}

	if (argc >= 3) {
		if ((ftmpl = fopen(argv[2], "rb")) == NULL) {
			perror("Error in source file ");
			return 4;
		}
	} else {
		if ((ftmpl = fopen("TKSource.TXT", "rb"))== NULL) {
			perror("Error in open TKSource.TXT\n");
			return 5;
		}
	}
n:
	if ((feach = fopen(argv[1], "rb")) == NULL) {
		perror("Error in test file ");
		return 10;
	}

	char FAR *t;
	char FAR *e;
	size_t *rr = new size_t[4096];
	size_t nt, ne;
	size_t rrsize = 4096;
	char FAR *ref=t, FAR *obj=e;

	fseek(ftmpl, 0, SEEK_END);
	nt = (size_t)ftell(ftmpl);
	fseek(ftmpl, 0, SEEK_SET);
	fseek(feach, 0, SEEK_END);
	ne = (size_t)ftell(feach);
	fseek(feach, 0, SEEK_SET);

	t	= (char FAR *)MALLOC(nt);
	e	= (char FAR *)MALLOC(ne);
	if (t == NULL || e == NULL) {
		printf("memory out. \n");
		return -1;
	}

	fread(t, 1, nt, ftmpl);
	fread(e, 1, ne, feach);
	stream_comp(ref, obj, nt, ne, nwide, ndepth, rr, &rrsize);

	fclose(ftmpl);
	fclose(feach);

 //Print Result...
	printf("total: %d, %d\n", nt, ne);
	printf("right:%d wrong:%d extra:%d lost:%d\n正确:%d 错误:%d 多余:%d 缺少:%d\n",
		rr[0], rr[1], rr[2], rr[3],
		rr[0], rr[1], rr[2], rr[3]
		);
	return 0;
}
