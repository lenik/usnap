
#pragma once

#include <sgp/dspace.h>
#include <list>
#include <vector>

class BoxMaze {
public:
	typedef sgp::linear_space<bool>	boolspace;
	typedef boolspace::vector	vector;
	typedef std::list<vector>	vectors;
	typedef boolspace::box_range	range;		// �ӿռ�
	typedef std::list<range>	ranges;		// �ӿռ��б�
	typedef vectors			connection;	// ���ӵ�
	typedef std::list<connection>	connections;	// ���ӵ��б�
public:
	boolspace map;
public:
	// ����һ����each in connection���������Թ�
	void CreateMaze(range& mazerange, vectors& connection);
	// ����һ������each in connection���Թ�ͨ����ע�����ã��ݹ�ǰ�����Ƚ�������
	void CreateWay(range& mazerange, vectors& connection);
public:
	BoxMaze();
public:
	ranges _r;
};
