
#pragma once


#include <pos/pos.h>

struct i_info {
	pos::asz_t	name;

	int		color;
};

extern int g_count;
extern i_info *g_i;

//extern pos::matrix_t g_mat;
//extern pos::matrix::mat2d_t *g_mat_data;

extern pos::graph_t g_graph;
