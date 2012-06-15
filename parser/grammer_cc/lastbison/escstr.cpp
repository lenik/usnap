
#include "escstr.h"

#include "escstr_lex.cpp"

#include <strstrea.h>
#include <string.h>

int make_escaped_string(char *instr, size_t cInstr, char *outstr, size_t cOutstr, size_t *pcNeeded) {
	if (!instr) return false;

	bool bRet = true;
	istrstream iss(instr);
	ostrstream oss;

	LastBisonLexFlexLexer lexer(&iss, &oss);
	lexer.yylex();

	size_t cNeeded = (size_t)oss.pcount();

	char *pOutstr = oss.str();

	if (outstr != NULL) {
		if (cOutstr < cNeeded + 1) {
			strncpy(outstr, pOutstr, cOutstr - 1);
			outstr[cOutstr - 1] = '\0';
			bRet = false;
		} else {
			strncpy(outstr, pOutstr, cNeeded);
			outstr[cNeeded] = '\0';
		}
	} else {
		bRet = false;
	}

	if (pcNeeded) *pcNeeded = cNeeded;

	return bRet;
}

char *l_make_escaped_string(char *instr) {
	static char l_buf[4096];
	size_t cNeeded;
	int iRet;
	iRet = make_escaped_string(instr, strlen(instr) + 1, l_buf, sizeof(l_buf), &cNeeded);

	if (!iRet || cNeeded > sizeof(l_buf)) {
		return NULL;
	}

	return l_buf;
}
