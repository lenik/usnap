
%option noyywrap

%%


[0-9a-zA-Z]	ECHO;

\\		{ *yyout << "\\\\"; }

\"		{ *yyout << "\\\""; }
\'		{ *yyout << "\\\'"; }

\n		{ *yyout << "\\n"; }
\a		{ *yyout << "\\a"; }
\r		{ *yyout << "\\r"; }

.		ECHO;
