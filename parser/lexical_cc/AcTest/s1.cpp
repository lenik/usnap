
// Automation compiler ����ģ���ļ�
// C++ �汾

// ״̬����

~constants

// ���Ͷ���

#define @calltype	_stdcall

#include <list>
#include <stack>
using namespace std;

typedef long character;
typedef list<character> buffer;
typedef list<buffer> buffers;

typedef long state;
typedef stack<state> statestack;

typedef character (@calltype *@input_proc)(buffers& ib, int protect_level);
typedef void (@calltype *@user_proc)(state S1, state S2, character c, buffer& accept_buffer);

// ����ԭ��

character @calltype @getc();
character @calltype @input(buffers& ib, int pl);
state @calltype @loop(@input_proc ip, int& pl, buffers& ib, buffers& ab, statestack& ss, state& s);
bool @calltype @main();

// �û�����ԭ��

~userprocs

// Ĭ�ϴ���

character @calltype @getc() {
	return (character)fgetc(stdin);
}

character @calltype @input(buffers& ib, int pl) {
	character r;
	if (ib.front().size() > 0) {
		r = ib.front().front();
		ib.front().pop_front();
	} else {
		r = @getc();
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

// ��������

state @calltype @loop(
	@input_proc ip,
	int& pl,		// protect level. 0 default
	buffers& ib,
	buffers& ab,
	statestack& ss,
	state& s) {
	state	old_state	= s;
	state	new_state	= s;
	state	jump_type	= 0; // none:0 j1 c2 x3
	char *	jump_switchs	= NULL;

	~mainproc

	return s;
}

bool @calltype @main() {
	buffers		protect_input_buffers;
	buffers		protect_accept_buffers;
	statestack	nestcall_statestack;

	state		current_state = @START;
	int		protect_level = 0;

	protect_input_buffers.push_front(*(new buffer));
	protect_accept_buffers.push_front(*(new buffer));

	do {
		@loop(
			@input,
			protect_level,
			protect_input_buffers,
			protect_accept_buffers,
			nestcall_statestack,
			current_state);
	} while (current_state != @END);			// B2
	return true;
}

// ȱʡ���

#ifdef USE_DEFAULT_FRAME
void main() {
	@main();
}
#endif
