
#include "stdafx.h"
#include "_Maze.h"
#include <math.h>

BoxMaze::BoxMaze() {}

void BoxMaze::CreateMaze(BoxMaze::range& mazerange, BoxMaze::vectors& connection) {
	// ������ȷͨ��
	CreateWay(mazerange, connection);
	// ���������Ӱ˸����ܵ�
	// ...
}

void BoxMaze::CreateWay(BoxMaze::range& mazerange, BoxMaze::vectors& connection) {
	range current;
	vector& rl = mazerange.first;
	vector& rr = mazerange.second;
	vector& cl = current.first = rl;
	vector& cr = current.second = rr;

	// (noneed)���и�Ŀռ�ά, �����и����ݹ�
	// ����һ��Nά�ռ�, �����и���ĿΪ 2^N
	//std::vector<bool> should_be_cut;

	// �и����ݹ�ջ, int�ڿ������۰룩�и���Ϊ 1~2, 0
	std::vector<int> cutted;

	cutted.resize(map.dimensions, 1);

	// �и����ݹ�, ���ռ��� 2^N ���ӿռ�
	ranges	cuts;
	int i = 0;					// �����и��ά����
	while (i >= 0) {				// �ж��Ƿ���ݵ��ʼ֮ǰ
		if (i == map.dimensions) {		// �ж�Ҷ����������
			// ջ��ָ�����ά, �����ӿռ�
			cuts.push_back(current);
			i--;
		} else {
			switch (cutted[i]) {
			case 1: // ��벿, �п��ܱ��Ұ벿��һ����Ԫ
				if (rr[i] - rl[i] >= 2) {
					cl[i] = rl[i];
					cr[i] = rl[i] + (rr[i] - rl[i]) / 2;
					cutted[i++] = 2;
				} else {
					// width=0(A/B),1(A)(B) �����۰�
					cr[i] = rr[i];
					cutted[i++] = 0;
				}
				break;
			case 2: // �Ұ벿
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
	// �����ӿռ䴴������ܵ���
	// Ŀǰֻ��ȡ C(2,connections.size()) ����ϣ��������ÿһ������ܵ���

}
