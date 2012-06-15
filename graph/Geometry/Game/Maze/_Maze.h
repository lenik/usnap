
#pragma once

#include <sgp/dspace.h>
#include <list>
#include <vector>

class BoxMaze {
public:
	typedef sgp::linear_space<bool>	boolspace;
	typedef boolspace::vector	vector;
	typedef std::list<vector>	vectors;
	typedef boolspace::box_range	range;		// 子空间
	typedef std::list<range>	ranges;		// 子空间列表
	typedef vectors			connection;	// 连接点
	typedef std::list<connection>	connections;	// 连接点列表
public:
	boolspace map;
public:
	// 建立一个在each in connection处相连的迷宫
	void CreateMaze(range& mazerange, vectors& connection);
	// 建立一个连接each in connection的迷宫通道。注意引用，递归前必须先建立对象。
	void CreateWay(range& mazerange, vectors& connection);
public:
	BoxMaze();
public:
	ranges _r;
};
