
#include "stdafx.h"
#include "MineMap.h"

typedef int MCLASS;

MineMap::MineMap() {
	width = height = 9;
	randomMap();

	BOOL	init[3][3] = {
		{ 1, 1, 1 },
		{ 1, 0, 1 },
		{ 1, 1, 1 }
	};
	twidth = theight = 3;
	for (tY = 0; tY < theight; tY++) {
		for (tX = 0; tX < twidth; tX++) {
			lookt[tY][tX] = init[tY][tX];
		}
	}
	tX = tY = 1;	// (1,1)Ϊ���ĵ�
}

void MineMap::randomMap() {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			map[y][x].bMined = rand() % 2 == 0;
		}
	}
}

void MineMap::click(int x, int y) {
	if (!map[y][x].bMined) map[y][x].state = OPENED;

	// �н����
	BOOL hassolve = FALSE;
	//while (!hassolve) {
	//...

	// 1.������δ�⵫���Խ�ĸ���

	// �����������
	int i, j;
	BOOL needrandom[MAXH][MAXW];
	int needrandom_count = 0;
	int rerandom_mines_count = 0;
	for (j = 0; j < height; j++) {
		for (i = 0; i < width; i++) {
			if (needrandom[j][i] = map[j][i].state != OPENED) {
				needrandom_count++;
				if (map[j][i].bMined) {
					rerandom_mines_count++;
					map[j][i].bMined = FALSE;
				}
			}
		}
	}
	i = j = 0;
	while (rerandom_mines_count > 0) {
		if (needrandom[j][i]) {
			if ((rand() % needrandom_count) < rerandom_mines_count) {
				if (!map[j][i].bMined) {
					map[j][i].bMined = TRUE;
					rerandom_mines_count--;
				}
			}
		}
		i++;
		j += i / width;
		i %= width;
		j %= height;
	}
}

BOOL MineMap::hint_byprob(int& x, int& y) {
	double pmap[MAXH][MAXW];	// * ���ʱ�
	int timestamp[MAXH][MAXW];	// ʱ��
	int i, j, _i, _j;
	int T;
	double prob = 0.0;

	for (j = 0; j < height; j++) {
		for (i = 0; i < width; i++) {
			pmap[j][i] = 0.0;
			timestamp[j][i] = 0;
		}
	}

	T = 0;

	for (j = 0; j < height; j++) {
		for (i = 0; i < width; i++) {
			if (map[j][i].state == OPENED && map[j][i].areaCount > 0) {
				prob = 0.0;	// �õ�˷�δ�����ĸ�����*����
				int t = 0;	// �˷�������������
				int Tmax = 0;	// �����ʱ��
				int tmax = 0;	// ���ʱ�����ĸ�����
				for (_j = -1; _j <= 1; _j++) {
					for (_i = -1; _i <= 1; _i++) {
						if (j + _j < 0 || i + _i < 0 || j + _j >= height || i + _i >= width) {
							continue;
						}
						if (map[j + _j][i + _i].state != OPENED) {
							prob += pmap[j + _j][i + _i];
							t++;
							if (timestamp[j + _j][i + _i] > Tmax) {
								Tmax = timestamp[j + _j][i + _i];
								tmax = 0;
							}
							if (timestamp[j + _j][i + _i] == Tmax) {
								tmax++;
							}
						}
					}
				}
				// �����¸���
				prob = map[j][i].areaCount - prob;	// ʣ�����
				if (prob < 0) prob = 0;
				prob /= (t - tmax);			// ���¾ɵ�
				for (_j = -1; _j <= 1; _j++) {
					for (_i = -1; _i <= 1; _i++) {
						if (j + _j < 0 || i + _i < 0 || j + _j >= height || i + _i >= width) {
							continue;
						}
						if (map[j + _j][i + _i].state != OPENED) {
							if (timestamp[j + _j][i + _i] < Tmax) {
								pmap[j + _j][i + _i] = prob;
								timestamp[j + _j][i + _i] = T;
							}
						}
					}
				}
			}
		}
	}
	return TRUE;
}

// �ɿ������ҳ���ǰ���Ե�֪�Ľ�, ���û�ж����򷵻�FALSE
BOOL MineMap::hint_byblock(int& x, int& y) {
	class MapList {
	public:
		typedef MCLASS *MAP;
		typedef std::list<MAP> MAPLIST;
		typedef MAPLIST::size_type size_type;
	public:
		MCLASS& grid(MAP map, int x, int y) {
			return map[y * This->width + x];
		}
		// �ο���û��Ҫ��
		MAP operator[](int index) {
			MAPLIST::iterator it;
			if (index >= m_list.size()) return NULL;
			for (it = m_list.begin(); it != m_list.end() && index > 0; ++it, --index);
			if (index > 0) {
				__assume(0);
				return NULL;
			}
			return *it;
		}
		size_type size() { return m_list.size(); }
	public:
		typedef his::hashes<MCLASS, int> Xclass;	// ����� -> ��Ŀ
		int *classNum(MCLASS classid) {
			Xclass::hashlist::iterator it;
			for (it = m_classes.m_list.begin(); it != m_classes.m_list.end(); ++it) {
				if (it->key == classid) {
					return &(it->value);
				}
			}
			return NULL;	// �����δ����
		}
		// ��ӷ��࣬�����Ƿ�������½ڵ�
		BOOL addClass(MCLASS classid, int num) {
			Xclass::hashlist::iterator it;
			for (it = m_classes.m_list.begin(); it != m_classes.m_list.end(); ++it) {
				if (it->key == classid) {
					it->value = num;
					return FALSE;
				}
			}
			Xclass::hash_type newclass(classid, num);
			m_classes.m_list.push_back(newclass);
			return TRUE;
		}
	public:
		MAPLIST m_list;
		Xclass m_classes;
		MineMap *This;
	public:
		MapList(const MineMap *pOuter) : m_list(MAPLIST()), m_classes(Xclass()) {}
	public:
		// ������ָ�������п��õ�MAP, ���޽��½�һ�������ء�
		// �������ù������ɵ�������ɡ�
		MAP availmap(BOOL *regiondesc, int width, int height, int cX, int cY, int mapX, int mapY) {
			MAPLIST::iterator it;
			BOOL available;
			MAP map;

			for (it = m_list.begin(); it != m_list.end(); ++it) {
				map = *it;
				int px, py;
				available = TRUE;
				for (py = 0; py < height && available; py++) {
					if (mapY + (py - cY) < 0) continue;
					if (mapY + (py - cY) >= This->height) continue;
					for (px = 0; px < width && available; px++) {
						if (mapX + (px - cX) < 0) continue;
						if (mapX + (px - cX) >= This->width) continue;
						if (regiondesc[py * This->width + px]) {
							if (map[(mapY + py - cY) * This->width + (mapX + px - cX)] > 0) {
								available = FALSE;
							}
						}
					}
				}
				if (available) break;
			}
			if (!available) {
				map = new MCLASS[This->height * This->width];
				for (int i = 0; i < This->height * This->width; i++) {
					map[i] = 0;
				}
				m_list.push_back(map);
			}
			return map;
		}
		BOOL	sm_in_bm(MAP sm, MAP bm, int x, int y, MCLASS smt, MCLASS bmt) {
			BOOL equal = TRUE;
			for (int j = 0; j < This->theight && equal; j++) {
				for (int i = 0; i < This->twidth; i++) {
					if (y + j - This->tY < 0 || y + j - This->tY >= This->height) continue;
					if (x + i - This->tX < 0 || x + i - This->tX >= This->width) continue;
					BOOL ss = sm[j * This->twidth + i] == smt;
					BOOL sb = bm[(y + j - This->tY) * This->width + (x + i - This->tX)] == bmt;
					if (ss != sb) {
						equal = FALSE;
						break;
					}
				}
			}
			return equal;
		}
		BOOL	bm_in_sm(MAP sm, MAP bm, int x, int y, MCLASS smt, MCLASS bmt) {
			BOOL equal = TRUE;
			for (int j = 0; j < This->height && equal; j++) {
				for (int i = 0; i < This->width; i++) {
					if (j < y - This->tY
						|| j > y + This->theight - 1 - This->tY
						|| i < x - This->tX
						|| i > x + This->twidth - 1 - This->tX) {
						if (bm[j * This->width + i] == bmt) {
							equal = FALSE;
							break;
						}
					} else {
						BOOL ss = sm[(j - y + This->tY) * This->twidth + (i - x + This->tX)] == smt;
						BOOL sb = bm[j * This->width + i] == bmt;
						if (ss != sb) {
							equal = FALSE;
							break;
						}
					}
				}
			}
			return equal;
		}
	};
	MapList	maplist(this);

	int i, j, _i, _j;
	MCLASS T = 0;
	int Tnum = 0;

	for (j = 0; j < height; j++) {
		for (i = 0; i < width; i++) {
			if (map[j][i].state == OPENED && map[j][i].areaCount > 0) {
				// �Ƚ���׼����������maplist��
				//   1 ����׼��
				MCLASS cls[MAXTH][MAXTW];
				++T;
				Tnum = map[j][i].areaCount;
				for (_j = 0; _j < theight; _j++) {
					for (_i = 0; _i < twidth; _i++) {
						cls[_j][_i] = 0;
						if (j + _j - tY < 0 || j + _j - tY >= height) continue;
						if (i + _i - tX < 0 || i + _i - tX >= width) continue;
						if (!lookt[_j][_i] || map[j + _j - tY][i + _i - tX].state == OPENED) {
							continue;
						}
						cls[_j][_i] = T;
					}
				}

				//   2 ���ձ�׼�����������ظ��������ظ�����ӱ�׼��
				BOOL repeated = FALSE;
				MCLASS pT;		// �ظ���T����
				MapList::size_type maps = maplist.size();

				for (int mi = 0; mi < maps && !repeated; mi++) {
					MapList::MAP pmap = maplist[mi];
					repeated = FALSE;
					for (_j = 0; _j < theight && !repeated; _j++) {
						for (_i = 0; _i < twidth && !repeated; _i++) {
							if (j + _j - tY < 0 || j + _j - tY >= height) continue;
							if (i + _i - tX < 0 || i + _i - tX >= width) continue;
							if (cls[_j][_i]) {
								pT = pmap[(j + _j - tY) * width + (i + _i - tX)];
								if (pT > 0) {
									// ��pmap�з���һ���ظ������ø���pmap�ж�ӦT����
									// �������������׼���ȽϿ��Ƿ�ȫ���ص���
									// ��ȫ���ص�ֻ��˵����׼���Ǹ�T����ĸ������в���˵��ȫ���ظ���
									// ����Ҫ���ż��T�����Ǳ�׼���ĸ�����
									//if (maplist.big_in_small(

									int _x, _y;
									int repeated2 = TRUE;
									for (_y = 0; _y < height && repeated2; _y++) {
										for (_x = 0; _x < width && repeated2; _x++) {
											MCLASS pT2;
											pT2 = pmap[_y * width + _x];
											// 1 �õ�������Ҫ����������
											//   �õ���������������������׼�����䣬
											//   ����Ȼ˵�������������׼�����غϡ�
											// 2 �õ��������������ڱ�׼�������ڣ�
											//   �����׼�������ж�Ӧ��Ƚϡ�����ͬ��ͬ�ϡ�
											// ��Ӧ������: y = j + _j - tY, x = i + _i - tX
											if (pT2 == pT) {
												// ��׼������λ��map�����꣺j+(0..theight-1)-tY i+(0..twidth-1)-tX
												if (_y < j - tY
													|| _y > j + theight - 1 - tY
													|| _x < i - tX
													|| _x > i + twidth - 1 - tX) {
													repeated2 = FALSE;
													break;
												}
												if (!cls[_y - j + tY][_x - i + tX]) {
													repeated2 = FALSE;
													break;
												}
											} else {
												if (!(_y < j - tY
													|| _y > j + theight - 1 - tY
													|| _x < i - tX
													|| _x > i + twidth - 1 - tX)) {
													if (cls[_y - j + tY][_x - i + tX]) {
														repeated2 = FALSE;
														break;
													}
												}
											}
										}
									}
									if (repeated2) {
										repeated2 = TRUE;
										for (_y = 0; _y < theight && repeated2; _y++) {
											for (_x = 0; _x < twidth && repeated2; _x++) {
												if (j + _y - tY < 0 || j + _y - tY >= height) continue;
												if (i + _x - tX < 0 || i + _x - tX >= width) continue;
												if ((cls[_y][_x] > 0) != (pmap[(j + _y - tY) * width + (i + _x - tX)] == pT)) {
													repeated2 = FALSE;
													break;
												}
											}
										}
									}
									if (repeated2) {
										// ��ȫ�ظ�
										repeated = TRUE;
									}

								} // if (pT > 0)
							} // if cls[_j][_i]
						} // for _i
					} // for _j
				} // for mi

				if (repeated) {
					// ���ظ������ظ���T������Ŀ�������иĽ���
					// ѡȡС����Ŀ��Ϊ���������Ŀ������
					int *classnum = maplist.classNum(pT);
					if (classnum == NULL) {
						__assume(0);
					}
					if (*classnum > Tnum) {
						*classnum = Tnum;
					}
				} else {
					// ���ظ�����ӱ�׼����
					BOOL *region = new BOOL[theight * twidth];
					for (_j = 0; _j < theight; _j++) {
						for (_i = 0; _i < twidth; _i++) {
							region[_j * twidth + _i] = cls[_j][_i] > 0;
						}
					}
					MapList::MAP pavailmap;
					pavailmap = maplist.availmap(region, twidth, theight, tX, tY, i, j);
					if (pavailmap == NULL) {
						__assume(0);
					}
					delete[] region;
					for (_j = 0; _j < theight; _j++) {
						for (_i = 0; _i < twidth; _i++) {
							pavailmap[(j + _j - tY) * width + (i + _i - tX)] = T;
						}
					}
				}

				// sum lookt+P[j][i] ==> areaCount
				// P�㸽��lookt�ң�OPENED�ĸ��������ѱ���ŵģ�
				//	���У�������Ƿ���ȫ���ǵģ�����������Ŀ��P����ȥ��
				//	����P��׼����ȥ��������ʣ��������Ϊʣ����Ŀ��
				//	������maplist�б�

			} // if map[j][i] OPENED
		}
	}

	return TRUE;
}
