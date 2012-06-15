
/*
	Automation Compiler 1b.0

	ʹ�ò�ͬʵ�ַ����ĵ�һ���Զ������Ա�����
				( �����ǿ )

	G �﷨����
*/

%union {
	char *strval;
	long intval;
	double realval;
	char chrval;
};

%token _NoProbably _ _E

%%

_: _NoProbablyTerm;
_E: /* empty */;

program:
	_E
	| states
	;

states:
	state
	| states state
	;

state:
	_E
	| ID ':' jumps ';' { }
	;

ID: ;

jumps:
	jump
	| jumps jump
;

jump:
	acceptchar jumptype ';' {
		// use C to analyse acceptchar
	}


acceptchar:
	| char_range
	| ID
;

jumptype:
	eats jumpops
;

eats:
	'-'
	| eats '-'
	;

jumpops:
	'>'
	| '['
	| ']'
	| '}'
	| 'v'
	| '^'
