typedef union {
	char		c;
	int			i;
	long		l;
	char *		s;
	float		f;
	double		r;
	void *		p;
	v128_t		v;
} YYSTYPE;
#define	NUMBER	258
#define	STRING	259
#define	ID	260
#define	ANYCHAR	261
#define	NEWLINE	262
