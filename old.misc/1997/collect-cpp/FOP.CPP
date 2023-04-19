
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OPEN_ERROR		1

#define data			unsigned long

typedef data (*operatecall)(data input, int param);

struct opchain {
	opchain *	next;
	operatecall	op;
	int		param;
} *mainopchain = NULL, *mainfirst;

int debugoutput = 0; 		// output debug strings, not in bit-output-mode.
char *dbgstr = NULL;

int databits = 8;
data fullbitsset = (data)(1 << databits) - 1;

data idata = 0, odata = 0;
int iusedbits = 0, ousedbits = 0;
#define BUFFSIZE		8
static data I[BUFFSIZE]; 	// input data buffer in main loop

FILE *fi = stdin, *fo = stdout;
int use_a_defaultoutput = 1; 	// output once anyway
int output_thr = 0; 		// output throttle, > 0 may disable output
int throttles = 0;
#define INITSESSION		54321
int session = INITSESSION; 	// session cookie ID
int codestatus = 0;		// 0 for encode, 1 for decode
int leadignore = 0; 		// ignore leading units

data add	(data input, int num) { return input + num; }
data sub	(data input, int num) { return input - num; }
data rsub	(data input, int num) { return num - input; }
data imul	(data input, int num) { return (data)((double)input * ((double)num / 100)); }
data idiv	(data input, int num) { return (data)((double)input / ((double)num / 100)); }
data and	(data input, int num) { return input & num; }
data or		(data input, int num) { return input | num; }
data xor	(data input, int num) { return input ^ num; }
data lshift	(data input, int num) { return input << num; }
data rshift	(data input, int num) { return input >> num; }

data swaphl(data input, int lowhalfbits) {
	data _1;
	_1 = input & ((1 << lowhalfbits) - 1);
	input >>= lowhalfbits;
	_1 <<= databits - lowhalfbits;
	return input | _1;
}

int input	(data &ret) {
	data r;
	data adjust;
	while (iusedbits < databits) {
		r = fgetc(fi);
		if (r == EOF) {
			if (iusedbits) {
				ret = idata >> 32 - databits;
				iusedbits = 0;
				idata = 0;
				return 1;
			} else {
				ret = 0;
				return 0;
			}
		}
		if (iusedbits + 8 >= 32) {
			idata |= (r >> iusedbits - 24);
			ret = idata >> (32 - databits);
			iusedbits = iusedbits - 24;
			idata = r & ((1 << iusedbits) - 1);
			return 1;
		} else {
			idata |= r << 24 - iusedbits;
			iusedbits += 8;
		}
	}
	// iusedbits >= databits, return high databits parts and
	// decrease iusedbits
	iusedbits -= databits;
	ret = idata >> (32 - databits);
	idata <<= databits;
	return 1;
}

data output(data input, int num);
data thr_output	(data input, int num) { input = input; num = num;
	static int samesession = INITSESSION + 12345; // keep difference at program start
	static int no_thr = 0;
/*
	if (samesession != session) {
		// a new session begin
		samesession = session;
		// 新一次操作首先判断是否已被封锁. 若已被封锁则本次错作不执行封锁.
		if (output_thr < 0) no_thr = 1;
		else {
			// 否则执行一次加强封锁
			output_thr--;
		}
	} else {
		// 同一次操作内尽管加强封锁
		output_thr--;
	}
*/
	if (samesession != session) {
		samesession = session;
		throttles = 1;
	} else {
		throttles++;
	}
	return input;
}

data output	(data input, int num) {	num = num;
	int nodisp = 0;
	if (output_thr != 0) nodisp = 1;
	if (throttles > 0) {
		output_thr = (output_thr + 1) % (throttles + 1);
	} else {
		output_thr = 0;
	}
	if (nodisp) return input;
	data adjustinput;
	input &= fullbitsset;
	if (ousedbits + databits >= 32) {
		adjustinput = input >> (ousedbits + databits - 32);
		odata |= adjustinput;
		fputc(odata >> 24, fo);
		fputc((odata >> 16) & 0xFF, fo);
		fputc((odata >> 8) & 0xFF, fo);
		fputc(odata & 0xFF, fo);
		ousedbits = ousedbits + databits - 32;
		adjustinput = input & ((1 << ousedbits) - 1);
		odata = adjustinput << (32 - ousedbits);
	} else {
		adjustinput = input << 32 - ousedbits - databits;
		odata |= adjustinput;
		ousedbits += databits;
	}
	return input;
}

data param_useprev(data input, int num) {
	opchain *c = mainopchain;
	operatecall mask[] = {
		param_useprev, output, thr_output
	};
	int i, nmask = sizeof(mask) / sizeof(operatecall);
	while (c != NULL) {
		for (i = 0; i < nmask; i++) if (c->op == mask[i]) goto skipthis;
		c->param = (int)I[num];
	skipthis:
		c = c->next;
	}
	return I[num];
}

void dumpleftdata() {
	while (odata || ousedbits > 0) {
		fputc(odata >> 24, fo);
		odata <<= 8;
		ousedbits -= 8;
	}
}

int getnum	(char *str, char **endptr, int _default) {
	int r;
	r = (int)strtol(str, endptr, 0);
	if (*endptr == str) r = _default;
	return r;
}

char *getstr	(char *str, char **endptr, char *buf, size_t bufsize) {
	char n[5];
	int p = 0;
	int i, i0, escaped = 0;
	FILE *df;

	if (str == NULL) return NULL;
	if (buf == NULL) buf = str;

	if (str[0] == '@') {
		if ((df = fopenx(str + 1, "rb")) == NULL) {
			if (silent == FALSE) { perror("error in opening param. file"); }
		}
		for (;p < bufsize - 1;p++) {
			if ((i = fgetc(df)) == EOF) { break; }
			buf[p] = i;
		}
		buf[p] = '\0';
		fclose(df);
		return buf;
	}

	while (str[p] && p < bufsize - 1) {
		i = str[p];
		if (!escaped) {
			if (i == '\\') escaped = 1;
			else {
		} else {
			switch (str[p]) {
			case 'a': i = '\a'; break;
			case 'b': i = '\b'; break;
			case 'n': i = '\n'; break;
			case 't': i = '\t'; break;
			default:
				if (
			if ((*s >= '0') && (*s <= '7')) {
	    for (pi = 0;(*s >= '0') && (*s <= '7');pi++) {
	      n[pi] = *s++;
	      if (pi >= 2) {
		break;
	      }
	    }
	    n[pi + 1] = '\0';
	    r[p++] = (char)strtol(n, (char **)NULL, 8);
	  } else {
	    if (tolower(*s) == 'x') {
	      s++;
	      for (pi = 0;;pi++) {
		if ((tolower(*s) >= 'a' && tolower(*s) <= 'f') || ( (*s >= '0') && (*s <= '9'))) {
		  n[pi] = *s++;
		  if (pi >= 1) {
		    break;
		  }
		} else {
		  break;
		}
	      }
	      n[pi + 1] = '\0';
	      r[p++] = (char)strtol(n, (char **)NULL, 16);
	    }
	    else {
	      r[p++] = *s;
	    } /* is a numeric trans */
	  }
      } /* switch (*s) */
    } /* if '\\' */
  } /* while *s */
}

int addchain	(operatecall op, data num) {
	if (mainopchain == NULL) {
		mainopchain = new opchain;
		mainfirst = mainopchain;
	} else {
		opchain *last = mainopchain;
		mainopchain = new opchain;
		last->next = mainopchain;
	}
	mainopchain->op = op;
	mainopchain->param = num;
	mainopchain->next = NULL;
	return 1;
}

int backchain	() {
	if (mainopchain != NULL) {
		opchain *c = mainopchain;
		while (c->next != NULL && c->next->next != NULL) c = c->next;
		c->next = NULL;
	} else {
		return 1;
	}
	return 0;
}

main(int argc, char **argv) {

	if (argc < 2 || strchr(argv[1], '?') != NULL ) {
		fprintf(stderr, "%s <method> [<input>] [<output>]\n\
	w.#	unit width (bits, default = 8, should between 1-32 ) \n\
	p+#	.+#=1		a&# *	.&#=-1	\n\
	s-#	.-#=1		o|# *	.|#=0	\n\
	S$#	#=0-. 		x^#	.^#=-1	\n\
	m*# *	.*#%=110	l<# *	.<<#=1	\n\
	d/# *	./#%=110	r># *	.>>#=1	\n\
	h%#	swap high-half-bits and low-half-bits \n\
	t:# *	throttle output # times ( = 1 ) \n\
	n!#	output once again \n\
		( #: number, *: undecodable ) \n\
	b~	erase back from op-chain \n\
	I,#	ignore leading units ( = 1 ) \n\
	E[	encode mode	D]	decode mode\n\
	P(	make previous data as parameter (cycle)\n\
	D"...	debug output string \n\
\n", argv[0]);
		return 0;
	}

	if (argc > 2)
		if ((fi = fopen(argv[2], "rb")) == NULL) {
			fprintf(stderr, "open %s for read: ", argv[2]);
			perror("");
			return OPEN_ERROR;
		}
	if (argc > 3)
		if ((fo = fopen(argv[3], "wb")) == NULL) {
			fprintf(stderr, "open %s for write: ", argv[3]);
			perror("");
			return OPEN_ERROR;
		}

	char *p = argv[1];
	int num;
	while (*p) {
		switch (*p) {
		case 'w':
		case '.':
			num = getnum(p + 1, &p, 8);
			num = ((num - 1) % 32) + 1;
			databits = num;
			fullbitsset = (data)(1 << databits) - 1;
			break;
		case 'p':
		case '+':
			addchain(codestatus ? sub : add, getnum(p + 1, &p, 1));
			break;
		case 's':
		case '-':
			addchain(codestatus ? add : sub, getnum(p + 1, &p, 1));
			break;
		case 'S':
		case '$':
			addchain(rsub, getnum(p + 1, &p, 1));
			break;
		case 'm':
		case '*':
			addchain(codestatus ? idiv : imul, getnum(p + 1, &p, 110));
			break;
		case 'd':
		case '/':
			addchain(codestatus ? imul : idiv, getnum(p + 1, &p, 110));
			break;
		case 'a':
		case '&':
			addchain(codestatus ? or : and, getnum(p + 1, &p, fullbitsset));
			break;
		case 'o':
		case '|':
			addchain(codestatus ? and : or, getnum(p + 1, &p, 0));
			break;
		case 'x':
		case '^':
			addchain(xor, getnum(p + 1, &p, fullbitsset));
			break;
		case 'l':
		case '<':
			addchain(codestatus ? rshift : lshift, getnum(p + 1, &p, 1));
			break;
		case 'r':
		case '>':
			addchain(codestatus ? lshift : rshift, getnum(p + 1, &p, 1));
			break;
		case 'h':
		case '%':
			num = getnum(p + 1, &p, databits / 2);
			// 当发生奇数位交换时保证编码时分成[*,num],而解码时分成[num,*]
			addchain(swaphl, codestatus ? databits - num : num);
			break;
		case 't':
		case ':':
			num = getnum(p + 1, &p, 1);
			while (num-- > 0)
				addchain(codestatus ? output : thr_output, 0);
			break;
		case 'n':
		case '!':
			num = getnum(p + 1, &p, 1);
			while (num-- > 0)
				addchain(codestatus ? thr_output : output, 0);
			break;
		case 'b':
		case '~':
			if (backchain() && use_a_defaultoutput == 0)
				fprintf(stderr, "warning: back a NULL-chain\n");
			use_a_defaultoutput = 0;
			p++;
			break;
		case 'E':
		case '[':
			codestatus = 0;
			p++;
			break;
		case 'D':
		case ']':
			codestatus = 1;
			p++;
			break;
		case 'P':
		case '(':
			addchain(param_useprev, 0);
			p++;
			break;
		case 'I':
		case ',':
			num = getnum(p + 1, &p, 1);
			leadignore += num;
			break;
		case 'D':
		case '\"':
			dbgstr = getstr(p + 1, &p);
			debugoutput = 1;
			break;
		case ' ':
		case '\t':
		case '_':
			p++;
			break;
		default:
			fprintf(stderr, "warning: unknown control: '%c'\n", *p);
			p++;
		}
	}

	while (input(I[0])) {
		int i;
		if (leadignore-- > 0) goto skipinput;
		mainopchain = mainfirst;
		while (mainopchain != NULL) {
			I[0] = mainopchain->op(I[0], mainopchain->param);
			mainopchain = mainopchain->next;
		}
		if (use_a_defaultoutput) output(I[0], 0);
	skipinput:
		for (i = BUFFSIZE - 2; i >= 0; i--) I[i + 1] = I[i];
		session++;
	}
	dumpleftdata();

	fclose(fi);
	fclose(fo);

	return 0;
}