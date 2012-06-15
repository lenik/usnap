
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
	   printf("无法初始化图形设备, 请确保*.BGI文件在启动目录.\n");
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
		printf("多边形与圆的交点示例\n格式: \n\t%s <数据文件>\n\n(请确保运行时VGA.BGI文件在当前目录)", argv[0]);
		return;
	}
	FILE *f = fopen(argv[1], "r");
	if (f == NULL) {
		//perror("无法打开数据文件");
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