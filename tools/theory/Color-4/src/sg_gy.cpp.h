typedef union {
	char		c;
	int		i;
	long		l;
	char *		s;
	float		f;
	double		r;
	void *		p;
	_PVT_128	v;

	graph_t *		graph;
	iolinks_node_t *	node;
	nodes_t *		nodes;
} YYSTYPE;
#define	NUMBER	258
#define	STRING	259
#define	ID	260
#define	D_LINK	261
#define	G_LINK	262
