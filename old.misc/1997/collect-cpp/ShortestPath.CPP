
#include <stdio.h>
#include <stdlib.h>

#define NODES		11

typedef struct s_tree *tp;

struct s_tree {
	int count;
	tp parent;
	tp *leaf;
} *root;

int m[NODES][NODES] = {
	{ 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
	{ 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
	{ 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0 },
	{ 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0 },
	{ 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1 },
	{ 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
	{ 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
	{ 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1 }
};

#define GETC(n)		((n) + 'A')
#define GETN(c)		((int)((c) - 'A'))

int passed[NODES];

int tree(int start, int end,

void tree(int start, tp tree) {
	passed[start] = 1;
	ta[start].count = 0;
	for (int i = 0; i < NODES; i++) {
		if (m[start][i] == 1) {
			ta[start].count++;
			realloc(ta.leaf, sizeof(int) * ta[start].count);
			ta[start].leaf[ta[start].count - 1] = i;
		}
	}
}

int shortest(int end
void main() {
	int start, end;

	memset(&ta, sizeof(s_tree) * NODES, 0);

	printf("from: ");
	scanf("%c", &start); start = GETN(start);
	printf("to: ");
	scanf("%c", &end); end = GETN(end);

	tree(start);

	for (int i = 0; i < NODES; i++) {
		for (int j = 0; j < ta[i].count; j++) {
			if (ti[i].leaf[i] == end)
