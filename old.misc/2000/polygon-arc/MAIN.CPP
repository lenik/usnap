
#include "polygon.h"
#include "simGui.h"
#include <stdio.h>
#include <stdlib.h>

#include <graphics.h>
#include <conio.h>
int initg() {
	int gdriver = DETECT, gmode, errorcode;

	/* initialize graphics mode */
        initgraph(&gdriver, &gmode, "");

	/* read result of initialization */
	errorcode = graphresult();

	if (errorcode != grOk)  /* an error occurred */
	{
	   printf("�޷���ʼ��ͼ���豸, ��ȷ��*.BGI�ļ�������Ŀ¼.\n");
	   exit(1);             /* return with error code */
	}
	cleardevice();
	return 0;
}

void main(int argc, char **argv) {
	CPolygon p;
	static int hasbeendone = 0;
	if (hasbeendone) exit(-1);

	if (argc < 2) {
		printf("�������Բ�Ľ���ʾ��\n��ʽ: \n\t%s <�����ļ�>\n\n(��ȷ������ʱVGA.BGI�ļ��ڵ�ǰĿ¼)", argv[0]);
		return;
	}
	FILE *f = fopen(argv[1], "r");
	if (f == NULL) {
		//perror("�޷��������ļ�");
		return;
	}

	int x, y;
	while (!feof(f)) {
		fscanf(f, "%d,%d", &x, &y);
		if (x < 0 && y < 0) break;
		p.add((Object&)*new CPoint(x, y));
	}

	int c_r;
	fscanf(f, "%d,%d,%d", &x, &y, &c_r);
	CPoint c_o(x, y);

	initg();

 //       for (int off = 0; off < 100; off+=1000) {
 //               c_o.offset(-1, 0);
		p.intersect(c_o, c_r);
		getch();
 //       }

	closegraph();

	hasbeendone = 1;
	exit(-1);
}