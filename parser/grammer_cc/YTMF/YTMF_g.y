%pure_parser

%{
#include "stdafx.h"
#include "YTMF_util.h"
%}

%union {
    char        c;
    int         i;
    long        l;
    char *      s;
    float       f;
    double      r;
    void *      p;
    v128_t      v;
};

%{
    /*
     * Add your declaration here
     */
%}


%type<s>        _ID

%token<l>       NUMBER
%token<s>       STRING
%token<s>       ID

%type<s>        word1 word words text

%token<c>       ANYCHAR NEWLINE


%%

text:
    words               { printf("<text: %s>\n", $1); $$ = $1; }
    | text NEWLINE text
    ;

words:
    word                {
                            printf("<words: word>\n");
                            int l = strlen($1);
                            char *buf = (char *)malloc(l + 3);
                            sprintf(buf, "(%s)", $1);
                            free($1);
                            $$ = buf;
                        }
    | words ',' word    {
                            printf("<word conj>\n");
                            int l1 = strlen($1);
                            int l2 = strlen($3);
                            char *buf = (char *)malloc(l1 + l2 + 10);
                            sprintf(buf, "%s (%s)", $1, $3);
                            free($1);
                            free($3);
                            $$ = buf;
                        }
    ;

word:
                        { $$ = strdup(""); printf("<empty word>\n"); }
    | word1             { $$ = $1; printf("<word: \"%s\">\n", $$); }
    ;

word1:
    ANYCHAR             { $$ = strdup("x"); $$[0] = $1; }
    | word1 ANYCHAR     {
                            int l = strlen($1);
                            char *buf = (char *)malloc(l + 2);
                            strcpy(buf, $1);
                            free($1);
                            $$ = buf;
                            $$[l] = $2;
                            $$[l + 1] = '\0';
                        }
    ;

_ID:
    ID
        {
            if (!$<v>1._r.bBind_) { // generally, !bBind_ means the string is allocated rather than on-stack.
                $$ = $1;
                $<v>1._r.bBind_ = true;     // unbind
            } else {
                $$ = strdup($1);
            }
        }
    ;

%%
