
#pragma once

FILE *fa = stdin, *fc = stdout;
char a_name[2000];

int indent = 0;
char outbuf[5000];

char *chardesc(char c) {
	static char sb[100];
	char cc;
	switch (c) {
	case '\n':
		cc = 'n';
		break;
	case '\r':
		cc = 'r';
		break;
	case '\t':
		cc = 't';
		break;
	case '.':
	case ':':
	case '\\':
	case ' ':
	case '\'':
	case '\"':
		cc = c;
		break;
	default:
		if (c < 0x20 || c > 0x7F) sprintf(sb, "\\x%x", (int)c);
		else sprintf(sb, "%c", c);
		return sb;
	}
	sprintf(sb, "\\%c", cc);
	return sb;
}

char *regcdesc(character c) {
	static char retbuf[1000];

	switch (c >> 24) {
	case 0:
		sprintf(retbuf, "%s", chardesc(c));
		break;
	case 1:
		sprintf(retbuf, "%s", chardesc((c & 0x0000FF00) >> 8));
		// strcat
		sprintf(retbuf, "%s-%s", retbuf, chardesc(c & 0xFF));
		break;
	case 4:
		sprintf(retbuf, "all");
		break;
	case 5:
		sprintf(retbuf, "any");
		break;
	case 6:
		sprintf(retbuf, "~");
		break;
	default:
		sprintf(retbuf, "?");
	}
	return retbuf;
}

char *regcdesc2(jmp& j) {
	chars::iterator i;
	character c;
	bool c_multi = false;
	static char retbuf[2000];

	if (!j.defined) return NULL;
	if (j.chars.size() > 1) c_multi = true;
	else if ((j.chars.front() & 0x01000000) == 0x01000000) c_multi = true;

	strcpy(retbuf, c_multi ? "[" : "");
	for (i = j.chars.begin(); i != j.chars.end() ; ++i) {
		c = *i;
		strcat(retbuf, regcdesc(c));
	}
	if (c_multi) strcat(retbuf, "]");
	return retbuf;
}

void outjmp(jmp& j) {
	if (!j.defined) return;

	fout(fc, indent, regcdesc2(j));
	fout(fc, 0, ": ");

	// 1. jump, then E?
	char c = 0;
	switch (j.type) {
	case jmp_normal:
		c = 'j';
		break;
	case jmp_call:
		c = 'c';
		break;
	case jmp_exit:
		c = 'x';
		break;
	}
	if (c) {
		sprintf(outbuf, "%c%s %s ", c, j.switchs.c_str(), j.target.c_str());
		fout(fc, 0, outbuf);
	}
	if (j.Eb.size()) {
		fout(fc, 0, "Eb ");
		fout(fc, 0, j.Eb.c_str());
	}
	if (j.Ej.size()) {
		fout(fc, 0, "Ej ");
		fout(fc, 0, j.Ej.c_str());
	}
	if (j.Ee.size()) {
		fout(fc, 0, "Ee ");
		fout(fc, 0, j.Ee.c_str());
	}
	if (j.Ea.size()) {
		fout(fc, 0, "Ea ");
		fout(fc, 0, j.Ea.c_str());
	}

	fout(fc, 0, " ;\n");
}

void refragout() {
	states::iterator i;
	jmps::iterator j;
	chars::iterator k;
	for (i = sts.begin(); i != sts.end(); ++i) {
		sprintf(outbuf, "%s:\n", (*i).name.c_str());
		fout(fc, indent++, outbuf);

		outjmp((*i).all);
		outjmp((*i).any);
		outjmp((*i).other);

		for (j = (*i).jmptable.begin(); j != (*i).jmptable.end(); ++j) {
			outjmp(*j);
		}

		fout(fc, indent--, ";\n");
	}
}
