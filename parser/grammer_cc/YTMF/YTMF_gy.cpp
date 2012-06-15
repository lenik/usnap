
/*
 * decoded parser by Zauj. G. D.
 * January 1st a.D.2000
 */

#define YYBISON 1  /* Identify Bison output.  */

#define yyparse YTMFparse
#define yylex YTMFlex
#define yyerror YTMFerror
#define yylval YTMFlval
#define yychar YTMFchar
#define yydebug YTMFdebug
#define yynerrs YTMFnerrs
#define	NUMBER	258
#define	STRING	259
#define	ID	260
#define	ANYCHAR	261
#define	NEWLINE	262

#line 5 ".\\ytmf_g.y"

	#include "stdafx.h"
	#include "YTMF_util.h"

#line 11 ".\\ytmf_g.y"
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
#line 23 ".\\ytmf_g.y"

	/*
	 * Add your declaration here
	 */
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		12
#define	YYFLAG		-32768
#define	YYNTBASE	9

#define YYTRANSLATE(x) ((unsigned)(x) <= 262 ? yytranslate[x] : 13)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     8,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     6,     8,    12,    14,    16,    19
};

static const short yyrhs[] = {    10,
     0,     9,     7,    10,     0,    11,     0,    10,     8,    11,
     0,    12,     0,     6,     0,    12,     6,     0,     5,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    43,    45,    48,    57,    69,    73,    75,    86
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","NUMBER",
"STRING","ID","ANYCHAR","NEWLINE","','","text","words","word","word1", NULL
};
#endif

static const short yyr1[] = {     0,
     9,     9,    10,    10,    11,    12,    12,    -1
};

static const short yyr2[] = {     0,
     1,     3,     1,     3,     1,     1,     2,     1
};

static const short yydefact[] = {     0,
     6,     0,     1,     3,     5,     0,     0,     7,     2,     4,
     0,     0
};

static const short yydefgoto[] = {     2,
     3,     4,     5
};

static const short yypact[] = {    -5,
-32768,     0,    -6,-32768,    -3,    -5,    -5,-32768,    -6,-32768,
     4,-32768
};

static const short yypgoto[] = {-32768,
    -1,     1,-32768
};


#define	YYLAST		8


static const short yytable[] = {    11,
     1,     7,     8,    12,     9,     0,     6,    10
};

static const short yycheck[] = {     0,
     6,     8,     6,     0,     6,    -1,     7,     7
};
#define YYPURE 1


#line 3 "z:/s/b/a/g/ref/misc/bison.simple"

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else
#if defined(WIN32)
#include <malloc.h>
#else
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else
void *alloca ();
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value)							\
	do									\
		if (yychar == YYEMPTY && yylen == 1)				\
			{ yychar = (token), yylval = (value);			\
				yychar1 = YYTRANSLATE (yychar);			\
				YYPOPSTACK;					\
				goto yybackup;					\
			}							\
		else								\
			{ yyerror ("syntax error: cannot back up"); YYERROR; }	\
	while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif
#endif


#ifndef YYPURE
	int	yychar;
	YYSTYPE	yylval;
	#ifdef YYLSP_NEEDED
		YYLTYPE yylloc;
	#endif
	int yynerrs;
#endif

#if YYDEBUG != 0
	int yydebug;
#endif

#ifndef	YYINITDEPTH
	#define YYINITDEPTH 200
#endif

#if YYMAXDEPTH == 0
	#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
	#define YYMAXDEPTH 10000
#endif

#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1
	#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else
	#ifndef __cplusplus
		static void
		__yy_memcpy (to, from, count)
				 char *to;
				 char *from;
				 int count;
		{
			register char *f = from;
			register char *t = to;
			register int i = count;

			while (i-- > 0)
				*t++ = *f++;
		}
	#else
		static void
		__yy_memcpy (char *to, char *from, int count)
		{
			register char *f = from;
			register char *t = to;
			register int i = count;

			while (i-- > 0)
				*t++ = *f++;
		}
	#endif
#endif

#line 143 "z:/s/b/a/g/ref/misc/bison.simple"


#ifdef YYPARSE_PARAM
	#ifdef __cplusplus
		#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
		#define YYPARSE_PARAM_DECL
	#else
		#define YYPARSE_PARAM_ARG YYPARSE_PARAM
		#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
	#endif
	#else
	#define YYPARSE_PARAM_ARG
	#define YYPARSE_PARAM_DECL
#endif

#ifndef YYPARSE_HEAD
#define YYPARSE_HEAD
#endif
int
yyparse(YYPARSE_PARAM_ARG)
		 YYPARSE_PARAM_DECL
{
	register int yystate;
	register int yyn;
	register short *yyssp;
	register YYSTYPE *yyvsp;
	int yyerrstatus;
	int yychar1 = 0;

	short	yyssa[YYINITDEPTH];
	YYSTYPE yyvsa[YYINITDEPTH];

	short *yyss = yyssa;
	YYSTYPE *yyvs = yyvsa;

#ifdef YYLSP_NEEDED
	YYLTYPE yylsa[YYINITDEPTH];
	YYLTYPE *yyls = yylsa;
	YYLTYPE *yylsp;
	#define YYPOPSTACK	 (yyvsp--, yyssp--, yylsp--)
#else
	#define YYPOPSTACK	 (yyvsp--, yyssp--)
#endif

	int yystacksize = YYINITDEPTH;

#ifdef YYPURE
	int yychar;
	YYSTYPE yylval;
	int yynerrs;
#ifdef YYLSP_NEEDED
	YYLTYPE yylloc;
#endif
#endif

	YYSTYPE yyval;

	int yylen;
#if YYDEBUG != 0
	if (yydebug)
		fprintf(stderr, "Starting parse\n");
#endif
	yystate = 0;
	yyerrstatus = 0;
	yynerrs = 0;
	yychar = YYEMPTY;
	yyssp = yyss - 1;
	yyvsp = yyvs;
#ifdef YYLSP_NEEDED
	yylsp = yyls;
#endif


	YYPARSE_HEAD


yynewstate:
	*++yyssp = yystate;
	if (yyssp >= yyss + yystacksize - 1)
		{
			YYSTYPE *yyvs1 = yyvs;
			short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
			YYLTYPE *yyls1 = yyls;
#endif

			int size = yyssp - yyss + 1;
#ifdef yyoverflow
#ifdef YYLSP_NEEDED
			yyoverflow("parser stack overflow",
			 &yyss1, size * sizeof (*yyssp),
			 &yyvs1, size * sizeof (*yyvsp),
			 &yyls1, size * sizeof (*yylsp),
			 &yystacksize);
#else
			yyoverflow("parser stack overflow",
			 &yyss1, size * sizeof (*yyssp),
			 &yyvs1, size * sizeof (*yyvsp),
			 &yystacksize);
#endif

			yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
			yyls = yyls1;
#endif
#else

			if (yystacksize >= YYMAXDEPTH)
			{
				yyerror("parser stack overflow");
				return 2;
			}
			yystacksize *= 2;
			if (yystacksize > YYMAXDEPTH)
			yystacksize = YYMAXDEPTH;
			yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
			__yy_memcpy ((char *)yyss, (char *)yyss1, size * sizeof (*yyssp));
			yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
			__yy_memcpy ((char *)yyvs, (char *)yyvs1, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
			yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
			__yy_memcpy ((char *)yyls, (char *)yyls1, size * sizeof (*yylsp));
#endif
#endif

			yyssp = yyss + size - 1;
			yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
			yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
			if (yydebug)
				fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif
			if (yyssp >= yyss + yystacksize - 1)
				YYABORT;
		}

#if YYDEBUG != 0
	if (yydebug)
		fprintf(stderr, "Entering state %d\n", yystate);
#endif

	goto yybackup;
yybackup:

	yyn = yypact[yystate];
	if (yyn == YYFLAG)
		goto yydefault;

	if (yychar == YYEMPTY)
		{
#if YYDEBUG != 0
			if (yydebug)
				fprintf(stderr, "Reading a token: ");
#endif
			yychar = YYLEX;
		}

		if (yychar <= 0)
		{
			yychar1 = 0;
			yychar = YYEOF;

#if YYDEBUG != 0
			if (yydebug)
				fprintf(stderr, "Now at end of input.\n");
#endif
		}
	else
		{
			yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
			if (yydebug)
			{
				fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);

#ifdef YYPRINT
				YYPRINT (stderr, yychar, yylval);
#endif
				fprintf (stderr, ")\n");
			}
#endif
		}

	yyn += yychar1;
	if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
		goto yydefault;

	yyn = yytable[yyn];

	if (yyn < 0)
		{
			if (yyn == YYFLAG)
goto yyerrlab;
			yyn = -yyn;
			goto yyreduce;
		}
	else if (yyn == 0)
		goto yyerrlab;

	if (yyn == YYFINAL)
		YYACCEPT;

#if YYDEBUG != 0
	if (yydebug)
		fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

	if (yychar != YYEOF)
		yychar = YYEMPTY;

	*++yyvsp = yylval;
#ifdef YYLSP_NEEDED
	*++yylsp = yylloc;
#endif

	if (yyerrstatus) yyerrstatus--;
	yystate = yyn;
	goto yynewstate;
yydefault:
	yyn = yydefact[yystate];
	if (yyn == 0)
		goto yyerrlab;
yyreduce:
	yylen = yyr2[yyn];
	if (yylen > 0)
		yyval = yyvsp[1-yylen];
#if YYDEBUG != 0
	if (yydebug)
		{
			int i;
			fprintf (stderr, "Reducing via rule %d (line %d), ",
				 yyn, yyrline[yyn]);
			for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
				fprintf (stderr, "%s ", yytname[yyrhs[i]]);
			fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
		}
#endif


/* data segment */

  switch (yyn) {

case 1:
#line 44 ".\\ytmf_g.y"
{ printf("<text: %s>\n", yyvsp[0].s); yyval.s = yyvsp[0].s; ;
    break;}
case 3:
#line 49 ".\\ytmf_g.y"
{
							printf("<words: word>\n");
							int l = strlen(yyvsp[0].s);
							char *buf = (char *)malloc(l + 3);
							sprintf(buf, "(%s)", yyvsp[0].s);
							free(yyvsp[0].s);
							yyval.s = buf;
						;
    break;}
case 4:
#line 57 ".\\ytmf_g.y"
{
							printf("<word conj>\n");
							int l1 = strlen(yyvsp[-2].s);
							int l2 = strlen(yyvsp[0].s);
							char *buf = (char *)malloc(l1 + l2 + 10);
							sprintf(buf, "%s (%s)", yyvsp[-2].s, yyvsp[0].s);
							free(yyvsp[-2].s);
							free(yyvsp[0].s);
							yyval.s = buf;
						;
    break;}
case 5:
#line 70 ".\\ytmf_g.y"
{ yyval.s = yyvsp[0].s; printf("<word: \"%s\">\n", yyval.s); ;
    break;}
case 6:
#line 74 ".\\ytmf_g.y"
{ yyval.s = strdup("x"); yyval.s[0] = yyvsp[0].c; ;
    break;}
case 7:
#line 75 ".\\ytmf_g.y"
{
							int l = strlen(yyvsp[-1].s);
							char *buf = (char *)malloc(l + 2);
							strcpy(buf, yyvsp[-1].s);
							free(yyvsp[-1].s);
							yyval.s = buf;
							yyval.s[l] = yyvsp[0].c;
							yyval.s[l + 1] = '\0';
						;
    break;}
case 8:
#line 88 ".\\ytmf_g.y"
{
			if (!yyvsp[0].v._r.bBind_) {	// generally, !bBind_ means the string is allocated rather than on-stack.
				yyval.s = yyvsp[0].s;
				yyvsp[0].v._r.bBind_ = true;		// unbind
			} else {
				yyval.s = strdup(yyvsp[0].s);
			}
		;
    break;}
}



#line 388 "z:/s/b/a/g/ref/misc/bison.simple"
	yyvsp -= yylen;
	yyssp -= yylen;
#ifdef YYLSP_NEEDED
	yylsp -= yylen;
#endif

#if YYDEBUG != 0
	if (yydebug)
		{
			short *ssp1 = yyss - 1;
			fprintf (stderr, "state stack now");
			while (ssp1 != yyssp)
			fprintf (stderr, " %d", *++ssp1);
			fprintf (stderr, "\n");
		}
#endif

	*++yyvsp = yyval;

#ifdef YYLSP_NEEDED
	yylsp++;
	if (yylen == 0)
		{
			yylsp->first_line = yylloc.first_line;
			yylsp->first_column = yylloc.first_column;
			yylsp->last_line = (yylsp-1)->last_line;
			yylsp->last_column = (yylsp-1)->last_column;
			yylsp->text = 0;
		}
	else
		{
			yylsp->last_line = (yylsp+yylen-1)->last_line;
			yylsp->last_column = (yylsp+yylen-1)->last_column;
		}
#endif


	yyn = yyr1[yyn];

	yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
	if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
		yystate = yytable[yystate];
	else
		yystate = yydefgoto[yyn - YYNTBASE];

	goto yynewstate;

yyerrlab:

	if (! yyerrstatus)

		{
			++yynerrs;

#ifdef YYERROR_VERBOSE
			yyn = yypact[yystate];

			if (yyn > YYFLAG && yyn < YYLAST)
	{
		int size = 0;
		char *msg;
		int x, count;

		count = 0;

		for (x = (yyn < 0 ? -yyn : 0); x < (sizeof(yytname) / sizeof(char *)); x++)
			if (yycheck[x + yyn] == x)
				size += strlen(yytname[x]) + 15, count++;
		msg = (char *) malloc(size + 15);
		if (msg != 0)
			{
				strcpy(msg, "parse error");
				if (count < 5)
				{
					count = 0;
					for (x = (yyn < 0 ? -yyn : 0); x < (sizeof(yytname) / sizeof(char *)); x++)
						if (yycheck[x + yyn] == x)
						{
						strcat(msg, count == 0 ? ", expecting `" : " or `");
						strcat(msg, yytname[x]);
						strcat(msg, "'");
						count++;
						}
				}
				yyerror(msg);
				free(msg);
			}
		else
			yyerror ("parse error; also virtual memory exceeded");
	}
	else
#endif
		yyerror("parse error");
	}

	goto yyerrlab1;
yyerrlab1:

	if (yyerrstatus == 3)
		{
			if (yychar == YYEOF)
YYABORT;

#if YYDEBUG != 0
			if (yydebug)
				fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif
			yychar = YYEMPTY;
		}
	yyerrstatus = 3;
	goto yyerrhandle;

yyerrdefault:

#if 0

	yyn = yydefact[yystate];
	if (yyn) goto yydefault;
#endif

yyerrpop:
	if (yyssp == yyss) YYABORT;
	yyvsp--;
	yystate = *--yyssp;
#ifdef YYLSP_NEEDED
	yylsp--;
#endif

#if YYDEBUG != 0
	if (yydebug)
		{
			short *ssp1 = yyss - 1;
			fprintf (stderr, "Error: state stack now");
			while (ssp1 != yyssp)
			fprintf (stderr, " %d", *++ssp1);
			fprintf (stderr, "\n");
		}
#endif

yyerrhandle:

	yyn = yypact[yystate];
	if (yyn == YYFLAG)
		goto yyerrdefault;

	yyn += YYTERROR;
	if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
		goto yyerrdefault;

	yyn = yytable[yyn];
	if (yyn < 0)
		{
			if (yyn == YYFLAG)
				goto yyerrpop;
			yyn = -yyn;
			goto yyreduce;
		}
	else if (yyn == 0)
		goto yyerrpop;

	if (yyn == YYFINAL)
		YYACCEPT;

#if YYDEBUG != 0
	if (yydebug)
		fprintf(stderr, "Shifting error token, ");
#endif

	*++yyvsp = yylval;
#ifdef YYLSP_NEEDED
	*++yylsp = yylloc;
#endif

	yystate = yyn;
	goto yynewstate;
}
#line 98 ".\\ytmf_g.y"
