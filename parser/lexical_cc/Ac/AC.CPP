// Ac.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "..\helper\helper.h"
#include "..\helper\statehelper.h"

#include "achelper.h"

static state state0;
static jmp jmp0;
static chars chars0;

void refragout();

void parse() {
	state currentst;
	jmp currentjmp;
	enum _pos_enum {
		wait_state = 1,		// wait state
		wait_range,		// wait range
		wait_cmd,		// wait cmd
		wait_param,		// wait param
		wait_proc_body
	} pos = wait_state;
	enum _jmpclass_enum {
		alljmp = 1,
		anyjmp,
		elsejmp,
		specialjmp
	} currentjmpclass;
	enum _eproc_enum {
		nonproc = 0,
		ebproc,
		eeproc,
		ejproc,
		eaproc
	} currentproc = nonproc;

	// S1:
	//	a:	j S2;
	//	[b-z]:	j S3
	//		Eb { xx }
	//		Ee { tt }
	//		;
	//	all:
	//		;
	// ;

	while (readword(fa)) {
		if (!strcmp(t, "//")) {
			int c;
			do {
				c = fgetc(fa);
			} while (c != '\n' && c != EOF);
			continue;
		}
		switch (pos) {
		case wait_state:
			currentst = state0;
			if (right(t, 0) == ':') {
				// a state name
				t[strlen(t) - 1] = 0;
				state *pexist = findsts(t);
				if (pexist) {
					currentst = *pexist;
				} else {
					currentst.name	= t;
				}
				pos = wait_range;
			}
			break;
		case wait_range:
			currentjmp = jmp0;
			currentjmp.defined = true;
			if (right(t, 0) == ':') {
				// a char name
				t[strlen(t) - 1] = 0;
				character c = 0;
				if (!strcmp(t, "all")) {
					c = CHAR_ALL;
					currentjmpclass = alljmp;
				} else if (!strcmp(t, "any")) {
					c = CHAR_ANY;
					currentjmpclass = anyjmp;
				} else if (!strcmp(t, "else") || !strcmp(t, "~")) {
					c = CHAR_ELSE;
					currentjmpclass = elsejmp;
				}
				if (c) {
					currentjmp.chars.push_back(c);
					pos = wait_cmd;
					continue;
				}
				// analyse chars desired.
				// [a-z], ., \n..
				chars cs;
				switch (t[0]) {
				case '.':
					// [\x0-\xff]
					cs.push_back(CHAR_FULLRANGE);
					break;
				case '[':
					{
						if (right(t, 0) == ']') {
							t[strlen(t) - 1] = 0;
						}
						int i;
						bool notprefix = t[1] == '^';
						for (i = notprefix ? 2 : 1; i < strlen(t); i++) {
							if (t[i + 1] == '-') {
								// a-b
								cs.push_back(0x01000000 |
									(((unsigned char)t[i]) << 8) |
									(unsigned char)t[i + 2]
									);
								i += 2;
							} else if (t[i] == '\\') {
								int d;
								char *endptr;
								if ((t[1] == 'x') || (t[1] >= '0' && t[1] <= '9')) {
									if (t[1] == 'x') {
										d = strtol(t + 2, &endptr, 16);
									} else if (t[1] >= '0' && t[1] <= '9') {
										d = strtol(t + 1, &endptr, 8);
									}
									cs.push_back((character)d);
									i += endptr - t - 1;	// + 1 by default
								} else {
									character tn = t[i + 1];

									switch (tn) {
									case 'n':
										cs.push_back('\n');
										break;
									case 't':
										cs.push_back('\t');
										break;
									case 'r':
										cs.push_back('\r');
										break;
									default:
										cs.push_back(tn);
									}
									i++;
								} // if \x
							} else {
								cs.push_back(t[i]);
							} // a-z or \ or else
						}
						if (notprefix) {
							chars::iterator ci;
							bool outset[256];	// in real, it was "result"
							for (i = 0; i < 256; i++) outset[i] = i >= 0x20 && i <= 0x7E;
							for (ci = cs.begin(); ci != cs.end(); ++ci) {
								/*
								switch ((*ci) >> 24) {
								case 0:
									outset[*ci] = true;
									break;
								case 1:
									int ci1 = ((*ci) & 0x0000FF00) >> 8;
									int ci2 = (*ci) & 0xFF;
									for (int cii = ci1; cii <= ci2; cii++) outset[cii] = true;
									break;
								}
								*/
								for (int ix = 0; ix < 0xFF; ix++) {
									if (inrange(ix, *ci)) {
										outset[ix] = false;
									}
								}
							}
							// recombine
							cs.clear();
							long firsti = 0;
							bool breaked = false;
							for (i = 0; i < 256; i++) {
								if (!outset[i]) {
									if (!breaked) {
										if (i == firsti + 1) {
											cs.push_back(firsti);
										} else {
											cs.push_back(
												0x01000000 |
												(firsti << 8) |
												(i - 1)
												);
										}
										breaked = true;
									}
								} else {
									firsti = i;
									breaked = false;
								}
							}
						} // not prefix
					}
					break;
				case '\\':
					{
						switch (t[1]) {
						case 'n':
							cs.push_back('\n');
							break;
						case 't':
							cs.push_back('\t');
							break;
						case 'r':
							cs.push_back('\r');
							break;
						case 'x':
							cs.push_back(strtol(t + 2, NULL, 16));
							break;
						case '0':
						case '1':
						case '2':
						case '3':
						case '4':
						case '5':
						case '6':
						case '7':
							cs.push_back(strtol(t + 1, NULL, 8));
							break;
						default:
							cs.push_back(t[1]);
						}
					}
					break;
				default:
					cs.push_back(t[0]);
					break;
				}
				currentjmp.chars	= cs;
				currentjmpclass = specialjmp;
				pos = wait_cmd;
			} else if (t[0] =  ';') {
				pos = wait_state;
				sts.push_back(currentst);
			}
			break; // case wait_range
		case wait_cmd:
			// in range, here get cmd
			{
				currentproc = nonproc;
				switch (t[0]) {
				case 'j':
					currentjmp.type	= jmp_normal;
					break;
				case 'c':
					currentjmp.type = jmp_call;
					break;
				case 'x':
					currentjmp.type = jmp_exit;
					break;
				case 'E':
					{
						switch (t[1]) {
						case 'b':
							currentproc = ebproc;
							break;
						case 'j':
							currentproc = ejproc;
							break;
						case 'e':
							currentproc = eeproc;
							break;
						case 'a':
							currentproc = eaproc;
							break;
						default:
							break;
						}
						pos = wait_param;
						continue;
					}
				case ';':
					switch (currentjmpclass) {
					case alljmp:
						currentst.all	= currentjmp;
						break;
					case anyjmp:
						currentst.any	= currentjmp;
						break;
					case elsejmp:
						currentst.other	= currentjmp;
						break;
					case specialjmp:
						currentst.jmptable.push_back(currentjmp);
						break;
					}
					pos = wait_range;
					continue;
				default:
					;
				}
				currentjmp.switchs = "";
				for (int i = 1; i < strlen(t); i++) {
					switch (t[i]) {
					case '+':
					case '-':
					case '*':
						currentjmp.switchs += t[i];
						break;
					default: ;
					}
				}
				pos = wait_param;
			}
			break;
		case wait_param:
			pos = wait_cmd;
			if (currentproc == 0) { // nonproc
				currentjmp.target = t;
				continue;
			}
			if (!strcmp(t, "{")) {
				// read all
				int c;
				string procbody = "{ ";
				int bracelevel = 0;
				while ((c = fgetc(fa)) != EOF) {
					procbody += c;
					if (c == '{') bracelevel++;
					if (c == '}') bracelevel--;
					if (bracelevel < 0) break;
				}
				switch (currentproc) {
				case ebproc:
					currentjmp.Eb = procbody;
					break;
				case ejproc:
					currentjmp.Ej = procbody;
					break;
				case eeproc:
					currentjmp.Ee = procbody;
					break;
				case eaproc:
					currentjmp.Ea = procbody;
					break;
				}
			} else {
				char buf[2000];
				sprintf(buf, "state %s accept %x (proctype=%d)", currentst.name.c_str(), 0, currentproc);
				adduserproc(t, buf);
				sprintf(buf, "{ %s(); }", t);
				switch (currentproc) {
				case ebproc:
					currentjmp.Eb = t;
					break;
				case ejproc:
					currentjmp.Ej = t;
					break;
				case eeproc:
					currentjmp.Ee = t;
					break;
				case eaproc:
					currentjmp.Ea = t;
					break;
				}
			}
			break;
		} // switch pos
	} // while readword
	fclose(fa);
}

static bool bufferempty = true;
void fcout(char *buf, bool buffered = false, bool reset_befores = false) {
	static char obuf[20000];
	if (reset_befores) {
		obuf[0] = 0;
		bufferempty = true;
	}
	if (buffered) {
		if (buf != NULL) strcat(obuf, buf);
		bufferempty = false;
	} else {
		if (obuf[0]) fprintf(fc, obuf);
		if (buf != NULL) fprintf(fc, buf);
		obuf[0] = 0;
		bufferempty = true;
	}
}

void compile() {
	// 分配状态号
	long current_state_id	= 0;
	long start_state	= 0;
	long end_state		= -1;
	states::iterator i;
	jmps::iterator j;

	for (i = sts.begin(); i != sts.end(); ++i) {
		(*i).s_id	= current_state_id;
		if ((*i).name == "s") {
			start_state	= current_state_id;
		} else if ((*i).name == "e") {
			end_state	= current_state_id;
		}
		// 合并特殊符号
			if ((*i).all.defined) {
				(*i).jmptable.push_back((*i).all);
			}
			if ((*i).any.defined) {
				(*i).jmptable.push_back((*i).any);
			}
			if ((*i).other.defined) {
				(*i).jmptable.push_back((*i).other);
			}
		current_state_id++;
	}

	// 写文件头
	fprintf(fc,
		"// Automation compiler 编译模板文件\n"
		"// C++ 版本\n"
		"\n"
		"// 状态常量\n"
		"\n"
		"\n"
		);

	for (i = sts.begin(); i != sts.end(); ++i) {
		fprintf(fc,
			"#define %s%-20s\t0x%08X\n",
			a_name,
			(*i).name.c_str(),
			(*i).s_id
			);
	}
	fprintf(fc,
		"#define %s%-20s\t0x%08X\n",
		a_name,
		"START",
		start_state
		);
	fprintf(fc,
		"#define %s%-20s\t0x%08X\n",
		a_name,
		"END",
		end_state
		);

	fprintf(fc,
		"\n"
		"// 类型定义\n"
		"#define %scalltype	_stdcall\n"	// 1
		"\n"
		"#include <list>\n"
		"#include <stack>\n"
		"using namespace std; \n"
		"\n"
		"typedef long character; \n"
		"typedef list<character> buffer; \n"
		"typedef list<buffer> buffers; \n"
		"\n"
		"typedef long state; \n"
		"typedef stack<state> statestack; \n"
		"\n"
		"typedef character (%scalltype *%sinput_proc)(buffers& ib, int protect_level); \n"
							// 2, 3
		"typedef void (%scalltype *%suser_proc)(state S1, state S2, character c, buffer& accept_buffer); \n"
							// 4, 5
		"\n"
		"// 函数原型\n"
		"\n"
		"character %scalltype %sgetc(); \n"	// 6, 7
		"character %scalltype %sinput(buffers& ib, int pl); \n"
							// 8, 9
		"state %scalltype %sloop(%sinput_proc ip, int& pl, buffers& ib, buffers& ab, statestack& ss, state& s); \n"
							// 10, 11, 12
		"bool %scalltype %smain(); \n"
							// 13, 14
		"\n"
		"// 用户函数原型\n"
		"\n",
		a_name,
		a_name, a_name,
		a_name, a_name,
		a_name, a_name,
		a_name, a_name,
		a_name, a_name, a_name,
		a_name, a_name
		);

	// 写用户函数原型
	strings fnames;
	strings::iterator fi;
	for (i = sts.begin(); i != sts.end(); ++i) {
		jmps::iterator j;
		for (j = (*i).jmptable.begin(); j != (*i).jmptable.end(); ++j) {
			if ((*j).Eb.size() > 0) {
				switch ((*j).Eb.at(0)) {
				case '{':
				case '\0':
				case ' ':
					break;
				default:
					fnames.insert(fnames.end(), (*j).Eb);
				}
			}
			if ((*j).Ej.size() > 0) {
				switch ((*j).Ej.at(0)) {
				case '{':
				case '\0':
				case ' ':
					break;
				default:
					fnames.insert(fnames.end(), (*j).Ej);
				}
			}
			if ((*j).Ee.size() > 0) {
				switch ((*j).Ee.at(0)) {
				case '{':
				case '\0':
				case ' ':
					break;
				default:
					fnames.insert(fnames.end(), (*j).Ee);
				}
			}
			if ((*j).Ea.size() > 0) {
				switch ((*j).Ea.at(0)) {
				case '{':
				case '\0':
				case ' ':
					break;
				default:
					fnames.insert(fnames.end(), (*j).Ea);
				}
			}
		}
	}

	// 取消重复项
	// iterator删除后对list状态的影响, 如删除i后(*i)指向何处.
	for (fi = fnames.begin(); fi != fnames.end(); ++fi) {
		strings::iterator fi2;
		for (fi2 = fi, ++fi2; fi2 != fnames.end(); ) {
			if ((*fi) == (*fi2)) {
				fi2 = fnames.erase(fi2);
			} else {
				++fi2;
			}
		}
	}

	for (fi = fnames.begin(); fi != fnames.end(); ++fi) {
		fprintf(fc,
			"void %scalltype %s%s(state S1, state S2, character c, buffer& ab); \n",
			a_name, a_name, (*fi).c_str()
			);
	}

	// 写默认处理 (1)
	fprintf(fc,
		"\n"
		"// 默认处理\n"
		"\n"
		"character %scalltype %sgetc() {\n"		// 1, 2
		"	return (character)fgetc(stdin); \n"
		"}\n"
		"\n"
		"character %scalltype %sinput(buffers& ib, int pl) {\n"
								// 3, 4
		"	character r; \n"
		"	if (ib.front().size() > 0) {\n"
		"		r = ib.front().front(); \n"
		"		ib.front().pop_front(); \n"
		"	} else {\n"
		"		r = %sgetc(); \n"		// 5
		"		if (pl > 0) {\n"
		"			buffers::iterator i = ib.begin(); \n"
		"			++i; \n"
		"			for (; i != ib.end(); ++i) {\n"
		"				(*i).push_back(r); \n"
		"			}\n"
		"		}\n"
		"	}\n"
		"	return r; \n"
		"}\n"
		"\n"
		"\n"
		"state %scalltype %sloop(\n"			// 6, 7
		"	%sinput_proc ip, \n"			// 8
		"	int& pl,		// protect level. 0 default\n"
		"	buffers& ib, \n"
		"	buffers& ab, \n"
		"	statestack& ss, \n"
		"	state& s) {\n"
		"	state	old_state	= s; \n"
		"	state	new_state	= s; \n"
		"	state	jump_type	= 0; // none:0 j1 c2 x3\n"
		"	char *	jump_switchs	= NULL; \n"
		"\n"
		"	/* S is s */\n"
		"	character c = ip(ib, pl); \n"
		"\n"
		"// 主处理函数\n"
		"\n",
		a_name, a_name,
		a_name, a_name,
		a_name,
		a_name, a_name,
		a_name
		);
	// 写主处理部分

	// 1. Eb处理, 处理的同时记录是否跳转及跳转类型
		fprintf(fc,
			"// Eb\n"
			"\n"
			"switch (s) {\n"
			);
		for (i = sts.begin(); i != sts.end(); ++i) {
			sprintf(outbuf,
				"case %s%s: \n",
				a_name, (*i).name.c_str());
			fcout(outbuf, true);
			// case's contents
			fcout("	switch (c) {\n", true);
			for (j = (*i).jmptable.begin(); j != (*i).jmptable.end(); ++j) {
				chars::iterator ci;
				if (!(*j).defined) continue;
				bool casehdr_outed = true;
				for (ci = (*j).chars.begin(); ci != (*j).chars.end(); ++ci) {
					switch (((*ci) & 0xFF000000) >> 24) {
					case 0:
						fcout(NULL);
						fprintf(fc, "\tcase '%s':\n", chardesc(*ci));
						break;
					case 1:
						{
							fcout(NULL);
							for (int cci = ((*ci) & 0x0000FF00) >> 8; cci <= ((*ci) & 0xFF); cci++) {
								fprintf(fc, "\tcase '%s': \n", chardesc(cci));
							}
						}
						break;
					case 2: // CHAR_ELSE
						fcout("\tdefault: \n");
						break;
					default:
						casehdr_outed = false;
						break;
					}
				}
				// 不能保证bufferempty就已输出case (char), 如"case all: "
				// 所以增设casehdr_outed触发
				if (casehdr_outed) {
					fprintf(fc, "\t\tjump_type	= %d; \n", (*j).type);
					fprintf(fc, "\t\tjump_switchs	= ");
					if ((*j).switchs.size() > 0) {
						fprintf(fc, "\"%s\"; \n", (*j).switchs.c_str());
					} else {
						fprintf(fc, "NULL; \n");
					}
					fprintf(fc, "\t\tnew_state	= %s%s; \n",
						a_name,
						(*j).target.c_str()
						);
					if ((*j).Eb.size() > 0) {
						fprintf(fc, "\t\t");
						if ((*j).Eb.at(0) == '{') {
							fprintf(fc, (*j).Eb.c_str());
						} else {
							fprintf(fc, "%s%s(s, new_state, c, ab.front()); ", a_name, (*j).Eb.c_str());
						}
						fprintf(fc, "\n");
					}
					// case (char) outed if bufferempty
					// and case (state) outed if any case (char) outed
					fprintf(fc, "\t\tbreak; \n");
				}
			} // for jmptable
			if (bufferempty) {
				// 结束case (state)
				fprintf(fc, "} // switch c\n");
				fprintf(fc, "break; \n");
			} else {
				// 没有case(state)输出, 清除fc缓冲
				fcout(NULL, false, true);
			}
		} // for sts
		fprintf(fc,
			"} // switch s\n"
			"\n"
			);

	// 2. B (缓冲) 处理
		fprintf(fc,
			"		ab.front().push_front(c); \n"
			"		if (jump_switchs != NULL) {\n"
			"			for (char *js = jump_switchs; *js; js++) {\n"
			"				switch (*js) {\n"
			"				case '-': \n"
			"					ib.push_front(ib.front()); \n"
			"					ab.push_front(ab.front()); \n"
			"					pl++; \n"
			"					break; \n"
			"				case '+': \n"
			"					ib.pop_front(); \n"
			"					ab.pop_front(); \n"
			"					pl--; \n"
			"					break; \n"
			"				case '*': \n"
			"					{\n"
			"						buffer ib2 = ib.front(); \n"
			"						buffer ab2 = ab.front(); \n"
			"						ib.pop_front(); \n"
			"						ab.pop_front(); \n"
			"						ib.front() = ib2; \n"
			"						ab.front() = ab2; \n"
			"					}\n"
			"					pl--; \n"
			"					break; \n"
			"				} // switch *js\n"
			"			} // for js\n"
			"		} // if jump_switchs\n"
			);

	// 3. Ej处理, 执行状态尚未改变前的操作
		fprintf(fc,
			"// Ej\n"
			"\n"
			"if (jump_type) {\n"
			"switch (s) {\n"
			);
		for (i = sts.begin(); i != sts.end(); ++i) {
			sprintf(outbuf,
				"case %s%s: \n",
				a_name, (*i).name.c_str());
			fcout(outbuf, true);
			// case's contents
			fcout("	switch (c) {\n", true);
			for (j = (*i).jmptable.begin(); j != (*i).jmptable.end(); ++j) {
				chars::iterator ci;
				if (!(*j).defined) continue;
				bool casehdr_outed = true;
				// 因为else:的存在, 所以不能因为(*j).Ej不存在就不输出casehdr
				for (ci = (*j).chars.begin(); ci != (*j).chars.end(); ++ci) {
					switch (((*ci) & 0xFF000000) >> 24) {
					case 0:
						fcout(NULL);
						fprintf(fc, "\tcase '%s':\n", chardesc(*ci));
						break;
					case 1:
						{
							fcout(NULL);
							for (int cci = ((*ci) & 0x0000FF00) >> 8; cci <= ((*ci) & 0xFF); cci++) {
								fprintf(fc, "\tcase '%s': \n", chardesc(cci));
							}
						}
						break;
					case 2: // CHAR_ELSE
						fcout("\tdefault: \n");
						break;
					default:
						casehdr_outed = false;
						break;
					}
				}
				// 不能保证bufferempty就已输出case (char), 如"case all: "
				// 所以增设casehdr_outed触发
				if (casehdr_outed) {
					if ((*j).Ej.size() > 0) {
						fprintf(fc, "\t\t");
						if ((*j).Ej.at(0) == '{') {
							fprintf(fc, (*j).Ej.c_str());
						} else {
							fprintf(fc, "%s%s(s, new_state, c, ab.front()); ", a_name, (*j).Ej.c_str());
						}
						fprintf(fc, "\n");
					}
					// case (char) outed if bufferempty
					// and case (state) outed if any case (char) outed
					fprintf(fc, "\t\tbreak; \n");
				}
			} // for jmptable
			if (bufferempty) {
				// 结束case (state)
				fprintf(fc, "} // switch c\n");
				fprintf(fc, "break; \n");
			} else {
				// 没有case(state)输出, 清除fc缓冲
				fcout(NULL, false, true);
			}
		} // for
		fprintf(fc,
			"} // switch s\n"
			"} // if jump\n"
			"\n"
			);

	// 4. S (状态切换) 操作
		fprintf(fc,
			"\n"
			"s	= new_state; \n"
			"\n"
			);

	// 6. 根据目标状态进行Ea处理, 执行状态抵达时的操作
		fprintf(fc,
			"\n"
			"	// Ea\n"
			"\n"
			"	if (jump_type) {\n"
			"		switch (s) {\n"
			);
		for (i = sts.begin(); i != sts.end(); ++i) {
			bool outed = false;
			sprintf(outbuf, "case %s%s: \n", a_name, (*i).name.c_str());
			if ((*i).all.defined && (*i).all.Ea.size() > 0) {
				if (!outed) {
					fprintf(fc, outbuf);
					outed = true;
				}
				fprintf(fc, "\t");
				if ((*i).all.Ea.at(0) == '{') {
					fprintf(fc, (*i).all.Ea.c_str());
				} else {
					fprintf(fc, "%s%s(s, new_state, c, ab.front()); ", a_name, (*i).all.Ea.c_str());
				}
				fprintf(fc, "\n");
				fprintf(fc, "\tbreak; \n");
			}
		}
		fprintf(fc,
			"} // switch s\n"
			"} // if jump\n"
			"\n"
			);

	// 5. Ee处理, 执行跳转结束后的操作
		fprintf(fc,
			"// Ee\n"
			"\n"
			"if (jump_type) {\n"
			"switch (old_state) {\n"
			);
		for (i = sts.begin(); i != sts.end(); ++i) {
			sprintf(outbuf,
				"case %s%s: \n",
				a_name, (*i).name.c_str());
			fcout(outbuf, true);
			// case's contents
			fcout("	switch (c) {\n", true);
			for (j = (*i).jmptable.begin(); j != (*i).jmptable.end(); ++j) {
				chars::iterator ci;
				if (!(*j).defined) continue;
				// 因为else:的存在, 所以不能因为(*j).Ee不存在就不输出casehdr
				bool casehdr_outed = true;
				for (ci = (*j).chars.begin(); ci != (*j).chars.end(); ++ci) {
					switch (((*ci) & 0xFF000000) >> 24) {
					case 0:
						fcout(NULL);
						fprintf(fc, "\tcase '%s':\n", chardesc(*ci));
						break;
					case 1:
						{
							fcout(NULL);
							for (int cci = ((*ci) & 0x0000FF00) >> 8; cci <= ((*ci) & 0xFF); cci++) {
								fprintf(fc, "\tcase '%s': \n", chardesc(cci));
							}
						}
						break;
					case 2: // CHAR_ELSE
						fcout("\tdefault: \n");
						break;
					default:
						casehdr_outed = false;
						break;
					}
				}
				// 不能保证bufferempty就已输出case (char), 如"case all: "
				// 所以增设casehdr_outed触发
				if (casehdr_outed) {
					if ((*j).Eb.size() > 0) {
						fprintf(fc, "\t\t");
						if ((*j).Eb.at(0) == '{') {
							fprintf(fc, (*j).Eb.c_str());
						} else {
							fprintf(fc, "%s%s(s, new_state, c, ab.front()); ", a_name, (*j).Eb.c_str());
						}
						fprintf(fc, "\n");
					}
					// case (char) outed if bufferempty
					// and case (state) outed if any case (char) outed
					fprintf(fc, "\t\tbreak; \n");
				}
			} // for jmptable
			if (bufferempty) {
				// 结束case (state)
				fprintf(fc, "} // switch c\n");
				fprintf(fc, "break; \n");
			} else {
				// 没有case(state)输出, 清除fc缓冲
				fcout(NULL, false, true);
			}
		} // for
		fprintf(fc,
			"} // switch s\n"
			"} // if jump\n"
			"\n"
			);

	// 写默认处理 (2)
	fprintf(fc,
		"\n"
		"	return s; \n"
		"}\n"
		"\n"
		"bool %scalltype %smain() {\n"		// 1, 2
		"	buffers		protect_input_buffers; \n"
		"	buffers		protect_accept_buffers; \n"
		"	statestack	nestcall_statestack; \n"
		"	\n"
		"	state		current_state = %sSTART;	\n"
							// 3
		"	int		protect_level = 0; \n"
		"\n"
		"	protect_input_buffers.push_front(*(new buffer)); \n"
		"	protect_accept_buffers.push_front(*(new buffer)); \n"
		"\n"
		"	do {\n"
		"		%sloop(\n"		// 4
		"			%sinput, \n"	// 5
		"			protect_level, \n"
		"			protect_input_buffers, \n"
		"			protect_accept_buffers, \n"
		"			nestcall_statestack, \n"
		"			current_state); \n"
		"	} while (current_state != %sEND);			// B2\n"
							// 6
		"	return true; \n"
		"}\n"
		"\n",
		a_name, a_name,
		a_name,
		a_name,
		a_name,
		a_name
		);


	fprintf(fc,
		"\n"
		"// 缺省框架\n"
		"\n"
		"#ifdef USE_%sFRAME\n"			// 1
		"\n",
		a_name
		);

		// 用户函数体
		for (fi = fnames.begin(); fi != fnames.end(); ++fi) {
			fprintf(fc,
				"void %scalltype %s%s(state S1, state S2, character c, buffer& ab) {\n"
				"\treturn; \n"
				"}\n"
				"\n",
				a_name, a_name, (*fi).c_str()
				);
		}

		// 辅助元素
		fprintf(fc,
			"void main() {\n"
			"	%smain(); \n"			// 2
			"}\n",
			a_name
			);
	fprintf(fc,
		"\n"
		"#endif\n"
		"\n"
		);
}

int main(int argc, char* argv[])
{
	bool reout = false;

	if (argc > 1 && strstr(argv[1], "/?")) {
		printf("Ac <automation> <c>\n");
		return 0;
	}

	if (argc > 1 && !strcmp(argv[1], "/r")) {
		argc--;
		argv++;
		reout = true;
	}

	strcpy(a_name, "A_");
	if (argc > 1) {
		fa = fopen(argv[1], "r");
		if (!fa) {
			perror(argv[1]);
			return -1;
		}
		strcat(a_name, argv[1]);
		if (strchr(a_name, '.')) *strchr(a_name, '.') = 0;
		strcat(a_name, "_");
	}
	if (argc > 2) {
		fc = fopen(argv[2], "w");
		if (!fc) {
			perror(argv[2]);
			return -1;
		}
	}

	parse();
	fclose(fa);

	if (reout) {
		refragout();
	} else {
		compile();
	}

	fclose(fc);
	return 0;
}
