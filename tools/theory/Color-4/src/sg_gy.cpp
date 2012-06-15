
/*
 * decoded parser by Zauj. G. D.
 * January 1st a.D.2000
 */

#define YYBISON 1  /* Identify Bison output.  */

#define yyparse SimGraphparse
#define yylex SimGraphlex
#define yyerror SimGrapherror
#define yylval SimGraphlval
#define yychar SimGraphchar
#define yydebug SimGraphdebug
#define yynerrs SimGraphnerrs
#define	NUMBER	258
#define	STRING	259
#define	ID	260
#define	D_LINK	261
#define	G_LINK	262

#line 5 ".\\sg_g.y"

	#include "stdafx.h"

	#include <pos/variant.h>
	#include <pos/graph.h>
	using namespace pos;
	using graph::iolinks_node_t;

	#include <posic/parse/parse_env.h>
	using namespace pos::posic::parse;

	typedef graph::iolinks_node_t::list_t	nodes_t;

	struct node_tran_t {
		asz_t name;
		iolinks_node_t *pnode;
	};
	typedef bdt::list_t<node_tran_t> node_decls_t;

	#include "poy_nodes.h"

#line 28 ".\\sg_g.y"
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
#line 44 ".\\sg_g.y"

	#define YYPARSE_PARAM	pvParse
	#define YYPARSE_HEAD	\
		parse_env_t&		_e = *(parse_env_t *)pvParse;		\
		graph_t *		_graph = (graph_t *)_e.target.body._pv;	\
		parse_env_t::_stop&	_e_l = _e.s[0];				\
		parse_env_t::_stop&	_e_g = _e.s[1];				\
		YYSTYPE *& _e_lval = (YYSTYPE *&)_e_l.out.L;			\
		int& _col = (int&)_e_l.loc.x;					\
		int& _line = (int&)_e_l.loc.y;					\
		_e_lval = &yylval;

	#define YYLEX_PARAM	pvParse

	int SimGraphlex(YYSTYPE *plval, void *pParse);
	int SimGrapherror(const char *);

	node_decls_t	*node_decls;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		22
#define	YYFLAG		-32768
#define	YYNTBASE	12

#define YYTRANSLATE(x) ((unsigned)(x) <= 262 ? yytranslate[x] : 20)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,    11,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     8,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     9,     2,    10,     2,     2,     2,     2,     2,
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
     0,     6,     8,    11,    15,    19,    21,    25,    27,    29,
    31
};

static const short yyrhs[] = {    17,
     8,     9,    13,    10,     0,    14,     0,    13,    14,     0,
    16,     6,    15,     0,    16,     7,    15,     0,    16,     0,
    15,    11,    16,     0,    18,     0,    19,     0,    19,     0,
     5,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    76,    95,   101,   107,   115,   124,   132,   145,   192,   196,
   200
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","NUMBER",
"STRING","ID","D_LINK","G_LINK","':'","'{'","'}'","','","Graph","GraphDefs",
"GraphDef","Nodes","Node","GraphName","NodeName","_ID", NULL
};
#endif

static const short yyr1[] = {     0,
    12,    13,    13,    14,    14,    15,    15,    16,    17,    18,
    19
};

static const short yyr2[] = {     0,
     5,     1,     2,     3,     3,     1,     3,     1,     1,     1,
     1
};

static const short yydefact[] = {     0,
    11,     0,     9,     0,     0,     0,     2,     0,     8,    10,
     1,     3,     0,     0,     4,     6,     5,     0,     7,     0,
     0,     0
};

static const short yydefgoto[] = {    20,
     6,     7,    15,     8,     2,     9,    10
};

static const short yypact[] = {    -2,
-32768,    -4,-32768,     1,    -2,    -3,-32768,     2,-32768,-32768,
-32768,-32768,    -2,    -2,    -5,-32768,    -5,    -2,-32768,    11,
    12,-32768
};

static const short yypgoto[] = {-32768,
-32768,     7,     0,   -13,-32768,-32768,    15
};


#define	YYLAST		15


static const short yytable[] = {    16,
    16,     1,     1,     4,    19,    18,    11,    13,    14,     5,
    21,    22,    12,    17,     3
};

static const short yycheck[] = {    13,
    14,     5,     5,     8,    18,    11,    10,     6,     7,     9,
     0,     0,     6,    14,     0
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
#line 78 ".\\sg_g.y"
{
			yyval.graph = _graph;
			_graph->_agg.m_pInfo = (var_t *)new util::v32_t;
			_graph->_agg.m_pInfo->hdr = PVTF_AUTO | pvt_asz;
			_graph->_agg.m_pInfo->_body()->p.m_asz = yyvsp[-4].s;

			((graph::iolinks_t *)_graph->m_pDetail)->s = yyvsp[-1].nodes;

			// release node_decls
			while (node_decls) {
				node_decls_t *p = node_decls;
				node_decls = node_decls->l;
				delete p;
			}
		;
    break;}
case 2:
#line 97 ".\\sg_g.y"
{
			yyval.nodes = NULL;
			graph::iolinks::nodes_add(yyval.nodes, yyvsp[0].node);
		;
    break;}
case 3:
#line 102 ".\\sg_g.y"
{
			graph::iolinks::nodes_add(yyvsp[-1].nodes, yyvsp[0].node);
		;
    break;}
case 4:
#line 109 ".\\sg_g.y"
{
			while (yyvsp[0].nodes->_l) yyvsp[0].nodes = yyvsp[0].nodes->_l;
			graph::iolinks::node_link_d(yyvsp[-2].node, yyvsp[0].nodes);
			graph::iolinks::nodes_destroy_list(yyvsp[0].nodes);
			yyval.node = yyvsp[-2].node;
		;
    break;}
case 5:
#line 116 ".\\sg_g.y"
{
			while (yyvsp[0].nodes->_l) yyvsp[0].nodes = yyvsp[0].nodes->_l;
			graph::iolinks::node_link(yyvsp[-2].node, yyvsp[0].nodes);
			graph::iolinks::nodes_destroy_list(yyvsp[0].nodes);
			yyval.node = yyvsp[-2].node;
		;
    break;}
case 6:
#line 126 ".\\sg_g.y"
{
			yyval.nodes = new nodes_t;
			yyval.nodes->data = yyvsp[0].node;
			yyval.nodes->_l = NULL;
			yyval.nodes->l = NULL;
		;
    break;}
case 7:
#line 133 ".\\sg_g.y"
{
			yyval.nodes = new nodes_t;
			yyvsp[-2].nodes->l = yyval.nodes;

			// NOTICE: here $$=$1.s, hence speed up,
			//	so Nodes shall be scaned back anywhere use Nodes.
			yyval.nodes->data = yyvsp[0].node;
			yyval.nodes->_l = yyvsp[-2].nodes;
			yyval.nodes->l = NULL;
		;
    break;}
case 8:
#line 147 ".\\sg_g.y"
{
			node_tran_t *item;
			node_decls_t *p = node_decls;

			bool bFound = false;
			while (p != NULL) {
				item = &(p->data);
				if (strcmp(item->name, yyvsp[0].s) == 0) {
					yyval.node = item->pnode;
					bFound = true;
					break;
				}

				// break at somewhere the "p" just != NULL, so can speed up the insertion.
				if (p->l) {
					p = p->l;
				} else {
					break;
				}
			}

			if (!bFound) {
				if (p) {
					p->l = new node_decls_t;
					p->l->_l = p;
					p = p->l;
					p->l = NULL;
				} else {
					// the node_decls must be empty.
					node_decls = p = new node_decls_t;
					p->l = p->_l = NULL;
				}
				p->data.name = yyvsp[0].s;	// not [auto]

				iolinks_node_t *_node = new iolinks_node_t;
				yyval.node = p->data.pnode = _node;

				// init the graph node
				__zero(*_node);
				_node->bAuto	= true;
				_node->_p0	= yyvsp[0].s;	// [auto]
			}
		;
    break;}
case 9:
#line 193 ".\\sg_g.y"
{ yyval.s = yyvsp[0].s; ;
    break;}
case 10:
#line 197 ".\\sg_g.y"
{ yyval.s = yyvsp[0].s; ;
    break;}
case 11:
#line 202 ".\\sg_g.y"
{
			if (yyvsp[0].v._r.bAuto) {	// generally, bAuto means the string is allocated rather than on-stack.
				yyval.s = yyvsp[0].s;
				yyvsp[0].v._r.bAuto = false;		// unbind
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
#line 212 ".\\sg_g.y"


#define yyFlexLexer SimGraphFlexLexer
#include <FlexLexer.h>

int SimGraphlex(YYSTYPE *plval, void *pvParse) {
	parse_env_t *_e;
	_e = (parse_env_t *)pvParse;

	SimGraphFlexLexer *pSGL =
		(SimGraphFlexLexer *)_e->source.body._pv;

	int i;
	i = pSGL->yylex();

	return i;
}
int SimGrapherror(const char *) {
	return 0;
}
