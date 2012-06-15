
// something could be improved:
// not only copy from, but also copy to,
// as: scopy out1 out2 out3 , in1 in2 in3 in4

#include <stdio.h>
#include <errno.h>

#define NUM_FILES_MAX			10
#define UNITSIZE			1000

main(int argc, char **argv) {

	int i, nFiles = 0;
	FILE *fi[NUM_FILES_MAX], *fo;
	char buf[UNITSIZE];
	int nRead, nWrite;
	long p = 0;
	int end = 0;

	printf("Security COPY v1.00\nauthor by dansei, 2000.9.19\n\n");

	if (argc > 1 && argv[1][0] == '?') {
		printf("preference set: \n");
		printf("ignore kilobytes: ");
		scanf("%ld", &p);
		p *= 1000;
		argc--;
		argv++;
	}

	if (argc < 3) {
		printf("Syntax\n\
	scopy [?] <output> <in 1> [<in 2> [<in 3> ...... ]]\n\
		the program will copy from input files to output, \n\
		if one of input file has error in it, program will \n\
		use data in another input file, and so on. \n");

		return 1;
	}

	if ((fo = fopen(argv[1], "wb+")) == NULL) {
		perror("open output: ");
		return 2;
	}
	fseek(fo, p, SEEK_SET);

	for (i = 2; i < argc; i++) {
		if ((fi[i - 2] = fopen(argv[i], "rb")) == NULL) {
			printf("error in open %s: ", argv[i]);
			perror("");

			for (i--; i >= 2; i--) fclose(fi[i - 2]);

			return i + 1;
		}
	}
	nFiles = argc - 2;

	printf("copying... if error occured, press FAIL\n");

	while (!end) {
		printf("\n%5ldk>", p / 1000);
		for (i = 0; i < nFiles; i++) {
			printf("\t_");
			errno = 0;
			if (fseek(fi[i], p, SEEK_SET)) {
				printf("Xsk");
				if (i != nFiles - 1) continue;
				printf("!");
			}
			nRead = fread(buf, 1, UNITSIZE, fi[i]);
			if (errno != 0) {
				printf("Xrd");
				if (i != nFiles - 1) continue;
				printf("!");
			}
			printf("R");

			errno = 0;
			if (nRead >= 0) {
				nWrite = fwrite(buf, 1, nRead, fo);
			} else {
				nWrite = fwrite(buf, 1, UNITSIZE, fo);
			}

			if (errno != 0)
				printf("Xwr");
			else
				printf("W");

			break;
		} // for fi[]
		if (!feof(fi[0]))
			printf(">");
		else {
			end = 1;
			printf("<END!");
			printf("\ncontinue reading? ");
			if ((getchar() | 0x20) == 'y') end = 0;
		}
		p += nRead;
	}

	for (i = 0; i < nFiles; i++) fclose(fi[i]);

	fclose(fo);

	return 0;
}
