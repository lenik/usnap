// Automation compiler 编译模板文件
// C++ 版本

// 状态常量


#define A_ac_s                   	0x00000000
#define A_ac_s01                 	0x00000001
#define A_ac_s02                 	0x00000002
#define A_ac_s04                 	0x00000003
#define A_ac_s05                 	0x00000004
#define A_ac_s06                 	0x00000005
#define A_ac_s07                 	0x00000006
#define A_ac_s1                  	0x00000007
#define A_ac_s11                 	0x00000008
#define A_ac_s12                 	0x00000009
#define A_ac_s13                 	0x0000000A
#define A_ac_s15                 	0x0000000B
#define A_ac_s16                 	0x0000000C
#define A_ac_s17                 	0x0000000D
#define A_ac_s18                 	0x0000000E
#define A_ac_s19                 	0x0000000F
#define A_ac_s1a                 	0x00000010
#define A_ac_s1b                 	0x00000011
#define A_ac_s1c                 	0x00000012
#define A_ac_s1d                 	0x00000013
#define A_ac_s2                  	0x00000014
#define A_ac_s21                 	0x00000015
#define A_ac_s22                 	0x00000016
#define A_ac_s3                  	0x00000017
#define A_ac_s31                 	0x00000018
#define A_ac_s32                 	0x00000019
#define A_ac_s4                  	0x0000001A
#define A_ac_s41                 	0x0000001B
#define A_ac_s42                 	0x0000001C
#define A_ac_s43                 	0x0000001D
#define A_ac_START               	0x00000000
#define A_ac_END                 	0xFFFFFFFF

// 类型定义
#define A_ac_calltype	_stdcall

#include <list>
#include <stack>
using namespace std;

typedef long character;
typedef list<character> buffer;
typedef list<buffer> buffers;

typedef long state;
typedef stack<state> statestack;

typedef character (A_ac_calltype *A_ac_input_proc)(buffers& ib, int protect_level);
typedef void (A_ac_calltype *A_ac_user_proc)(state S1, state S2, character c, buffer& accept_buffer);

// 函数原型

character A_ac_calltype A_ac_getc();
character A_ac_calltype A_ac_input(buffers& ib, int pl);
state A_ac_calltype A_ac_loop(A_ac_input_proc ip, int& pl, buffers& ib, buffers& ab, statestack& ss, state& s);
bool A_ac_calltype A_ac_main();

// 用户函数原型

void A_ac_calltype A_ac_clearB(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_init_S(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_submit_S(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_cond(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_submit_J(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_set_j_type(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_set_c_type(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_set_x_type(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_submit_Char(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_set_jump_level_inc(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_set_jump_level_d(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_set_jump_forced(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_set_E_begin(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_set_E_jumping(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_set_E_end(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_set_E_arrival(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_read_until_right_brace(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_set_procbody(state S1, state S2, character c, buffer& ab);
void A_ac_calltype A_ac_save_userproc(state S1, state S2, character c, buffer& ab);

// 默认处理

character A_ac_calltype A_ac_getc() {
	return (character)fgetc(stdin);
}

character A_ac_calltype A_ac_input(buffers& ib, int pl) {
	character r;
	if (ib.front().size() > 0) {
		r = ib.front().front();
		ib.front().pop_front();
	} else {
		r = A_ac_getc();
		if (pl > 0) {
			buffers::iterator i = ib.begin();
			++i;
			for (; i != ib.end(); ++i) {
				(*i).push_back(r);
			}
		}
	}
	return r;
}


state A_ac_calltype A_ac_loop(
	A_ac_input_proc ip,
	int& pl,		// protect level. 0 default
	buffers& ib,
	buffers& ab,
	statestack& ss,
	state& s) {
	state	old_state	= s;
	state	new_state	= s;
	state	jump_type	= 0; // none:0 j1 c2 x3
	char *	jump_switchs	= NULL;

	/* S is s */
	character c = ip(ib, pl);

// 主处理函数

// Eb

switch (s) {
case A_ac_s:
	switch (c) {
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s;
		break;
	case '/':
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_ac_s01;
		break;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_ac_s05;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s;
		break;
} // switch c
break;
case A_ac_s01:
	switch (c) {
	case '/':
		jump_type	= 1;
		jump_switchs	= "*";
		new_state	= A_ac_s02;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s;
		break;
} // switch c
break;
case A_ac_s02:
	switch (c) {
	case '\n':
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s04;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s02;
		break;
} // switch c
break;
case A_ac_s04:
	switch (c) {
	default:
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s;
		break;
} // switch c
break;
case A_ac_s05:
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s06;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= "+-";
		new_state	= A_ac_s07;
		break;
} // switch c
break;
case A_ac_s06:
	switch (c) {
	default:
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_ac_s05;
		break;
} // switch c
break;
case A_ac_s07:
	switch (c) {
	case '\:':
		jump_type	= 1;
		jump_switchs	= "*-";
		new_state	= A_ac_s07;
		break;
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		jump_type	= 1;
		jump_switchs	= "*-";
		new_state	= A_ac_s07;
		break;
	case ';':
		jump_type	= 1;
		jump_switchs	= "*";
		new_state	= A_ac_s;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s1;
		break;
} // switch c
break;
case A_ac_s1:
	switch (c) {
	case ';':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s;
		break;
	case '\.':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s2;
		break;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s2;
		break;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_ac_s11;
		break;
	case '\\':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s15;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s1;
		break;
} // switch c
break;
case A_ac_s11:
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s12;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s2;
		break;
} // switch c
break;
case A_ac_s12:
	switch (c) {
	default:
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_ac_s13;
		break;
} // switch c
break;
case A_ac_s13:
	switch (c) {
	case '\:':
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s2;
		break;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s12;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= "*-";
		new_state	= A_ac_s13;
		break;
} // switch c
break;
case A_ac_s15:
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_ac_s16;
		break;
	case 'x':
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_ac_s1a;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s2;
		break;
} // switch c
break;
case A_ac_s16:
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s17;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s2;
		break;
} // switch c
break;
case A_ac_s17:
	switch (c) {
	default:
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_ac_s18;
		break;
} // switch c
break;
case A_ac_s18:
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s19;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s2;
		break;
} // switch c
break;
case A_ac_s19:
	switch (c) {
	default:
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s2;
		break;
} // switch c
break;
case A_ac_s1a:
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s16;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s2;
		break;
} // switch c
break;
case A_ac_s1b:
	switch (c) {
	default:
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_ac_s1c;
		break;
} // switch c
break;
case A_ac_s1c:
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s1d;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s2;
		break;
} // switch c
break;
case A_ac_s1d:
	switch (c) {
	default:
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s2;
		break;
} // switch c
break;
case A_ac_s2:
	switch (c) {
	case '\:':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s2;
		break;
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s2;
		break;
	case ';':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s1;
		break;
	case 'j':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s21;
		break;
	case 'c':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s21;
		break;
	case 'x':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s21;
		break;
	case 'E':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s22;
		break;
} // switch c
break;
case A_ac_s21:
	switch (c) {
	case '+':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s21;
		break;
	case '-':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s21;
		break;
	case '*':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s21;
		break;
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s3;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s21;
		break;
} // switch c
break;
case A_ac_s22:
	switch (c) {
	case 'b':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s4;
		break;
	case 'j':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s4;
		break;
	case 'e':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s4;
		break;
	case 'a':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s4;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s22;
		break;
} // switch c
break;
case A_ac_s3:
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_ac_s31;
		break;
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s3;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s2;
		break;
} // switch c
break;
case A_ac_s31:
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s32;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s2;
		break;
} // switch c
break;
case A_ac_s32:
	switch (c) {
	default:
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_ac_s32;
		break;
} // switch c
break;
case A_ac_s4:
	switch (c) {
	case '{':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s41;
		break;
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s4;
		break;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_ac_s42;
		A_ac_clearB(s, new_state, c, ab.front());
		break;
	default:
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s2;
		break;
} // switch c
break;
case A_ac_s41:
	switch (c) {
	default:
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ac_s2;
		break;
} // switch c
break;
case A_ac_s42:
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s43;
		break;
	default:
		jump_type	= 1;
		jump_switchs	= "+";
		new_state	= A_ac_s2;
		break;
} // switch c
break;
case A_ac_s43:
	switch (c) {
	default:
		jump_type	= 1;
		jump_switchs	= "-";
		new_state	= A_ac_s42;
		break;
} // switch c
break;
} // switch s

		ab.front().push_front(c);
		if (jump_switchs != NULL) {
			for (char *js = jump_switchs; *js; js++) {
				switch (*js) {
				case '-':
					ib.push_front(ib.front());
					ab.push_front(ab.front());
					pl++;
					break;
				case '+':
					ib.pop_front();
					ab.pop_front();
					pl--;
					break;
				case '*':
					{
						buffer ib2 = ib.front();
						buffer ab2 = ab.front();
						ib.pop_front();
						ab.pop_front();
						ib.front() = ib2;
						ab.front() = ab2;
					}
					pl--;
					break;
				} // switch *js
			} // for js
		} // if jump_switchs
// Ej

if (jump_type) {
switch (s) {
case A_ac_s:
	switch (c) {
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		break;
	case '/':
		break;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
		break;
	default:
		{ adderror("获取状态名时发现非法字符"); }
		break;
} // switch c
break;
case A_ac_s01:
	switch (c) {
	case '/':
		A_ac_clearB(s, new_state, c, ab.front());
		break;
	default:
		{ adderror("获取状态名时发现非法字符。如果写注释请用双斜杠“//”"); }
		break;
} // switch c
break;
case A_ac_s02:
	switch (c) {
	case '\n':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s04:
	switch (c) {
	default:
		A_ac_clearB(s, new_state, c, ab.front());
		break;
} // switch c
break;
case A_ac_s05:
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		break;
	default:
		A_ac_init_S(s, new_state, c, ab.front());
		break;
} // switch c
break;
case A_ac_s06:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s07:
	switch (c) {
	case '\:':
		break;
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		break;
	case ';':
		A_ac_submit_S(s, new_state, c, ab.front());
		break;
	default:
		break;
} // switch c
break;
case A_ac_s1:
	switch (c) {
	case ';':
		A_ac_submit_S(s, new_state, c, ab.front());
		break;
	case '\.':
		break;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		break;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
		break;
	case '\\':
		break;
	default:
		{ adderror("获取跳转接受表达式时发现非法字符。"); }
		break;
} // switch c
break;
case A_ac_s11:
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s12:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s13:
	switch (c) {
	case '\:':
		A_ac_cond(s, new_state, c, ab.front());
		break;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		break;
	default:
		{ adderror("获取特殊接受字符时发现非法字符。"); }
		break;
} // switch c
break;
case A_ac_s15:
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
		break;
	case 'x':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s16:
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s17:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s18:
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s19:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s1a:
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s1b:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s1c:
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s1d:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s2:
	switch (c) {
	case '\:':
		A_ac_clearB(s, new_state, c, ab.front());
		break;
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		A_ac_clearB(s, new_state, c, ab.front());
		break;
	case ';':
		A_ac_submit_J(s, new_state, c, ab.front());
		break;
	case 'j':
		A_ac_set_j_type(s, new_state, c, ab.front());
		break;
	case 'c':
		A_ac_set_c_type(s, new_state, c, ab.front());
		break;
	case 'x':
		A_ac_set_x_type(s, new_state, c, ab.front());
		break;
	case 'E':
		break;
} // switch c
break;
case A_ac_s21:
	switch (c) {
	case '+':
		A_ac_set_jump_level_inc(s, new_state, c, ab.front());
		break;
	case '-':
		A_ac_set_jump_level_d(s, new_state, c, ab.front());
		break;
	case '*':
		A_ac_set_jump_forced(s, new_state, c, ab.front());
		break;
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		break;
	default:
		{ adderror("获取跳转类型时发现非法字符。"); }
		break;
} // switch c
break;
case A_ac_s22:
	switch (c) {
	case 'b':
		A_ac_set_E_begin(s, new_state, c, ab.front());
		break;
	case 'j':
		A_ac_set_E_jumping(s, new_state, c, ab.front());
		break;
	case 'e':
		A_ac_set_E_end(s, new_state, c, ab.front());
		break;
	case 'a':
		A_ac_set_E_arrival(s, new_state, c, ab.front());
		break;
	default:
		{ adderror("非法事件类型。"); }
		break;
} // switch c
break;
case A_ac_s3:
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
		break;
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		A_ac_clearB(s, new_state, c, ab.front());
		break;
	default:
		{ adderror("获取跳转目标状态时发现非法状态名。"); }
		break;
} // switch c
break;
case A_ac_s31:
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		break;
	default:
		A_ac_submit_J(s, new_state, c, ab.front());
		break;
} // switch c
break;
case A_ac_s32:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s4:
	switch (c) {
	case '{':
		A_ac_read_until_right_brace(s, new_state, c, ab.front());
		break;
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		break;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
		break;
	default:
		A_ac_submit_J(s, new_state, c, ab.front());
		break;
} // switch c
break;
case A_ac_s41:
	switch (c) {
	default:
		A_ac_set_procbody(s, new_state, c, ab.front());
		break;
} // switch c
break;
case A_ac_s42:
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		break;
	default:
		A_ac_save_userproc(s, new_state, c, ab.front());
		break;
} // switch c
break;
case A_ac_s43:
	switch (c) {
	default:
		break;
} // switch c
break;
} // switch s
} // if jump


s	= new_state;


	// Ea

	if (jump_type) {
		switch (s) {
case A_ac_s:
	A_ac_clearB(s, new_state, c, ab.front());
	break;
case A_ac_s1:
	A_ac_clearB(s, new_state, c, ab.front());
	break;
case A_ac_s2:
	A_ac_submit_Char(s, new_state, c, ab.front());
	break;
case A_ac_s3:
	A_ac_clearB(s, new_state, c, ab.front());
	break;
} // switch s
} // if jump

// Ee

if (jump_type) {
switch (old_state) {
case A_ac_s:
	switch (c) {
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		break;
	case '/':
		break;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s01:
	switch (c) {
	case '/':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s02:
	switch (c) {
	case '\n':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s04:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s05:
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s06:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s07:
	switch (c) {
	case '\:':
		break;
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		break;
	case ';':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s1:
	switch (c) {
	case ';':
		break;
	case '\.':
		break;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		break;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
		break;
	case '\\':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s11:
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s12:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s13:
	switch (c) {
	case '\:':
		break;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s15:
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
		break;
	case 'x':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s16:
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s17:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s18:
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s19:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s1a:
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s1b:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s1c:
	switch (c) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s1d:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s2:
	switch (c) {
	case '\:':
		break;
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		break;
	case ';':
		break;
	case 'j':
		break;
	case 'c':
		break;
	case 'x':
		break;
	case 'E':
		break;
} // switch c
break;
case A_ac_s21:
	switch (c) {
	case '+':
		break;
	case '-':
		break;
	case '*':
		break;
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s22:
	switch (c) {
	case 'b':
		break;
	case 'j':
		break;
	case 'e':
		break;
	case 'a':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s3:
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
		break;
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s31:
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s32:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s4:
	switch (c) {
	case '{':
		break;
	case '\ ':
	case '\n':
	case '\t':
	case '\r':
		break;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
		A_ac_clearB(s, new_state, c, ab.front());
		break;
	default:
		break;
} // switch c
break;
case A_ac_s41:
	switch (c) {
	default:
		break;
} // switch c
break;
case A_ac_s42:
	switch (c) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		break;
	default:
		break;
} // switch c
break;
case A_ac_s43:
	switch (c) {
	default:
		break;
} // switch c
break;
} // switch s
} // if jump


	return s;
}

bool A_ac_calltype A_ac_main() {
	buffers		protect_input_buffers;
	buffers		protect_accept_buffers;
	statestack	nestcall_statestack;

	state		current_state = A_ac_START;
	int		protect_level = 0;

	protect_input_buffers.push_front(*(new buffer));
	protect_accept_buffers.push_front(*(new buffer));

	do {
		A_ac_loop(
			A_ac_input,
			protect_level,
			protect_input_buffers,
			protect_accept_buffers,
			nestcall_statestack,
			current_state);
	} while (current_state != A_ac_END);			// B2
	return true;
}


// 缺省框架

#ifdef USE_A_ac_FRAME

void A_ac_calltype A_ac_clearB(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_init_S(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_submit_S(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_cond(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_submit_J(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_set_j_type(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_set_c_type(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_set_x_type(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_submit_Char(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_set_jump_level_inc(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_set_jump_level_d(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_set_jump_forced(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_set_E_begin(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_set_E_jumping(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_set_E_end(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_set_E_arrival(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_read_until_right_brace(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_set_procbody(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ac_calltype A_ac_save_userproc(state S1, state S2, character c, buffer& ab) {
	return;
}

void main() {
	A_ac_main();
}

#endif
