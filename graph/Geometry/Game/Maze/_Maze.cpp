
#include "stdafx.h"
#include "_Maze.h"
#include <math.h>

BoxMaze::BoxMaze() {}

void BoxMaze::CreateMaze(BoxMaze::range& mazerange, BoxMaze::vectors& connection) {
	// 建立正确通道
	CreateWay(mazerange, connection);
	// 建立杂七杂八辅助管道
	// ...
}

void BoxMaze::CreateWay(BoxMaze::range& mazerange, BoxMaze::vectors& connection) {
	range current;
	vector& rl = mazerange.first;
	vector& rr = mazerange.second;
	vector& cl = current.first = rl;
	vector& cr = current.second = rr;

	// (noneed)需切割的空间维, 用于切割的拟递归
	// 对于一个N维空间, 开方切割数目为 2^N
	//std::vector<bool> should_be_cut;

	// 切割的拟递归栈, int在开方（折半）切割中为 1~2, 0
	std::vector<int> cutted;

	cutted.resize(map.dimensions, 1);

	// 切割的拟递归, 将空间割成 2^N 个子空间
	ranges	cuts;
	int i = 0;					// 正在切割的维索引
	while (i >= 0) {				// 判断是否回溯到最开始之前
		if (i == map.dimensions) {		// 判断叶结点成立条件
			// 栈顶指向最底维, 加入子空间
			cuts.push_back(current);
			i--;
		} else {
			switch (cutted[i]) {
			case 1: // 左半部, 有可能比右半部大一个单元
				if (rr[i] - rl[i] >= 2) {
					cl[i] = rl[i];
					cr[i] = rl[i] + (rr[i] - rl[i]) / 2;
					cutted[i++] = 2;
				} else {
					// width=0(A/B),1(A)(B) 不需折半
					cr[i] = rr[i];
					cutted[i++] = 0;
				}
				break;
			case 2: // 右半部
				cl[i] = cr[i] + 1;
				cr[i] = rr[i];
				cutted[i++] = 0;
				break;
			case 0:
				cutted[i--] = 1;
				break;
			}
		}
	}

#ifdef _DEBUG
	_r = cuts;
#endif
	// 根据子空间创建随机管道。
	// 目前只能取 C(2,connections.size()) 的组合，对组合中每一对求出管道。

}
