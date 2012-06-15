
#include "stdafx.h"

typedef char	character;

// -------------------------------------

#define A_upper_START			0
#define A_upper_S1			1
#define A_upper_S2			2
#define A_upper_S3			3
#define A_upper_S4			4
#define A_upper_S5			5
#define A_upper_END			-1


// -------------------------------------
#define A_upper_calltype	_stdcall	// C1

typedef list<character> charlist;
typedef charlist buffer;
typedef list<buffer> buffers;

typedef long state;
typedef stack<state> statestack;

typedef character (A_upper_calltype *A_upper_input_proc)(buffers& ib, int protect_level);
typedef void (A_upper_calltype *A_upper_user_proc)(state S1, state S2, character c, buffer& accept_buffer);
// ------------------------------------------------------------------

// A1
void A_upper_calltype out(state S1, state S2, character c, buffer& ab) {
	while (ab.size()) {
		character c = ab.back();
		printf("%c", c);
		ab.pop_back();
	}
}
void A_upper_calltype clear(state S1, state S2, character c, buffer& ab) {
	ab.clear();
}

character A_upper_calltype A_upper_input(buffers& ib, int pl) {
	character r;
	if (ib.front().size() > 0) {
		r = ib.front().front();
		ib.front().pop_front();
	} else {
		r = fgetc(stdin);
		if (pl > 0) {
			buffers::iterator i = ib.begin();
			++i;	// not include the front
			// save c for c now is not in stdin, we must put it in buffer to simulate
			for (; i != ib.end(); ++i) {
				(*i).push_back(r);
			}
		}
	}
	return r;
}

// MAIN PROCESS
state A_upper_calltype A_upper_loop(A_upper_input_proc ip,
				    int& pl,		// protect level. 0 default
				    buffers& ib,
				    buffers& ab,
				    statestack& ss,
				    state& s) {
	//
	state	old_state	= s;
	state	new_state	= s;
	state	jump_type	= 0; // none:0 j1 c2 x3
	int	jump_level	= 0;
	bool	jump_forced	= false;

	/* S is s */
	character c = ip(ib, pl);
	// Eb
		switch (s) {
		case A_upper_START:
			switch (c) {
			case '/':
				jump_type	= 1;
				jump_level	= -1;
				new_state	= A_upper_S1;
				break;
			case '!':
				jump_type	= 1;
				new_state	= A_upper_END;
				break;
			default:
				// j s Ej out
				jump_type	= 1;
				new_state	= A_upper_START;
				break;
			}
			break;
		case A_upper_S1:
			switch (c) {
			case '*':
				jump_type	= 1;
				jump_level	= -1;
				new_state	= A_upper_S2;
				break;
			default:
				jump_type	= 1;
				jump_level	= 1;
				new_state	= A_upper_S5;
				break;
			}
			break;
		case A_upper_S5:
			jump_type	= 1;
			new_state	= A_upper_START;
			break;
		case A_upper_S2:
			switch (c) {
			case '*':
				jump_type	= 1;
				new_state	= A_upper_S3;
				break;
			default:
				jump_type	= 1;
				jump_level	= 1;
				new_state	= A_upper_S4;
				break;
			}
			break;
		case A_upper_S3:
			switch (c) {
			case '/':
				// j+* s Ej clear
				jump_type	= 1;
				jump_level	= 2;
				jump_forced	= true;
				new_state	= A_upper_START;
				break;
			default:
				jump_type	= 1;
				jump_level	= 1;
				new_state	= A_upper_S4;
				break;
			}
			break;
		case A_upper_S4:
			jump_type	= 1;
			jump_level	= -1;
			new_state	= A_upper_S2;
			break;
		} // switch s
	// Eb -->

	// B
		ab.front().push_front(c);
		/*
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
		*/
		if (jump_level != 0) {
			int i;
			if (jump_level < 0) {
				for (i = 0; i < -jump_level; i++) {
					ib.push_front(ib.front());
					ab.push_front(ab.front());
				}
			} else {
				if (pl - jump_level < 0) {
					jump_level = pl;
				}
				buffer ib2 = ib.front();
				buffer ab2 = ab.front();
				for (i = 0; i < jump_level; i++) {
					ib.pop_front();
					ab.pop_front();
				}
				if (jump_forced) {
					ib.front() = ib2;
					ab.front() = ab2;
				}
			}
			pl	-= jump_level;
		}

	// Ej
		if (jump_type) {
			switch (s) {
			case A_upper_START:
				switch (c) {
				case '/':
				case '!':
					break;
				default:
					out(s, new_state, c, ab.front());
					break;
				}
				break;
			case A_upper_S3:
				switch (c) {
				case '/':
					clear(s, new_state, c, ab.front());
					break;
				}
				break;
			}
		}
	// S
		s	= new_state;
	// Ee
	// Ea
		return s;
}

bool A_upper_calltype A_upper_main() {
	buffers		protect_input_buffers;
	buffers		protect_accept_buffers;
	statestack	nestcall_statestack;

	state		current_state = A_upper_START;	// B1
	int		protect_level = 0;

	protect_input_buffers.push_front(*(new buffer));
	protect_accept_buffers.push_front(*(new buffer));

	do {
		A_upper_loop(
			A_upper_input,
			protect_level,
			protect_input_buffers,
			protect_accept_buffers,
			nestcall_statestack,
			current_state);
	} while (current_state != A_upper_END);			// B2
	return true;
}
