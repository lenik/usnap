// Automation compiler 编译模板文件
// C++ 版本

// 状态常量


#define A_ig_s                   	0x00000000
#define A_ig_v                   	0x00000001
#define A_ig_e                   	0x00000002
#define A_ig_START               	0x00000000
#define A_ig_END                 	0x00000002

// 类型定义
#define A_ig_calltype	_stdcall

#include <list>
#include <stack>
using namespace std;

typedef long character;
typedef list<character> buffer;
typedef list<buffer> buffers;

typedef long state;
typedef stack<state> statestack;

typedef character (A_ig_calltype *A_ig_input_proc)(buffers& ib, int protect_level);
typedef void (A_ig_calltype *A_ig_user_proc)(state S1, state S2, character c, buffer& accept_buffer);

// 函数原型

character A_ig_calltype A_ig_getc();
character A_ig_calltype A_ig_input(buffers& ib, int pl);
state A_ig_calltype A_ig_loop(A_ig_input_proc ip, int& pl, buffers& ib, buffers& ab, statestack& ss, state& s);
bool A_ig_calltype A_ig_main();

// 用户函数原型

void A_ig_calltype A_ig_out(state S1, state S2, character c, buffer& ab);
void A_ig_calltype A_ig_out(state S1, state S2, character c, buffer& ab);
void A_ig_calltype A_ig_clear(state S1, state S2, character c, buffer& ab);
void A_ig_calltype A_ig_clear(state S1, state S2, character c, buffer& ab);

// 默认处理

character A_ig_calltype A_ig_getc() {
	return (character)fgetc(stdin);
}

character A_ig_calltype A_ig_input(buffers& ib, int pl) {
	character r;
	if (ib.front().size() > 0) {
		r = ib.front().front();
		ib.front().pop_front();
	} else {
		r = A_ig_getc();
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


state A_ig_calltype A_ig_loop(
	A_ig_input_proc ip,
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
case A_ig_s:
	switch (c) {
	default:
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ig_v;
		break;
}
break;
case A_ig_v:
	switch (c) {
	default:
		jump_type	= 1;
		jump_switchs	= NULL;
		new_state	= A_ig_s;
		break;
}
break;
}

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
case A_ig_s:
	switch (c) {
	default:
		A_ig_out(s, new_state, c, ab.front());
		break;
}
}
break;
case A_ig_v:
	switch (c) {
	default:
		A_ig_clear(s, new_state, c, ab.front());
		break;
}
}
break;
}


s	= new_state;


	// Ea

	if (jump_type) {
		switch (s) {
}
}

// Ee

if (jump_type) {
switch (oldstate) {
}


	return s;
}

bool A_ig_calltype A_ig_main() {
	buffers		protect_input_buffers;
	buffers		protect_accept_buffers;
	statestack	nestcall_statestack;

	state		current_state = A_ig_START;
	int		protect_level = 0;

	protect_input_buffers.push_front(*(new buffer));
	protect_accept_buffers.push_front(*(new buffer));

	do {
		A_ig_loop(
			A_ig_input,
			protect_level,
			protect_input_buffers,
			protect_accept_buffers,
			nestcall_statestack,
			current_state);
	} while (current_state != A_ig_END);			// B2
	return true;
}

void A_ig_calltype A_ig_out(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ig_calltype A_ig_out(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ig_calltype A_ig_clear(state S1, state S2, character c, buffer& ab) {
	return;
}

void A_ig_calltype A_ig_clear(state S1, state S2, character c, buffer& ab) {
	return;
}


// 缺省框架

#ifdef USE_A_ig_FRAME
void main() {
	A_ig_main();
}
#endif
