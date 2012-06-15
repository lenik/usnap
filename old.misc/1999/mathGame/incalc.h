typedef union {
	double	val;
	symrec	*tptr;
} YYSTYPE;
#define	NUM	257
#define	VAR	258
#define	FNCT	259
#define	NEG	260


extern YYSTYPE yylval;
