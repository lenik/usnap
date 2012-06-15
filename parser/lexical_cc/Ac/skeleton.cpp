
#include "stdafx.h"

typedef char	character;

// -------------------------------------

#define A_upper_calltype	_stdcall	// C1

typedef list<character> charlist;
typedef charlist buffer;
typedef list<buffer> bufferlist;

typedef char state;
typedef stack<state> statestack;

typedef character (A_upper_calltype *A_upper_input_proc)(bool writeback, character c, buffer& input_buffer);
// ------------------------------------------------------------------

// A1
void A_upper_calltype userproc(state S1, state S2, character c);

character A_upper_calltype A_upper_input(bool writeback, character c, buffer& ib) {
	if (writeback) {
		ib.push_front(c);
		return 0;
	} else {
		if (ib.size() > 0) return ib.pop_front();
		return (character)fgetc(stdin);
	}
}

// MAIN PROCESS
state A_upper_calltype A_upper_loop(A_upper_input_proc ip,
				    buffer& ib,
				    bufferlist& pbs,
				    statestack& ss,
				    state& s) {
	//
	state	old_state	= s;
	state	new_state	= s;
	state	jump_type	= 0; // none:0 j1 c2 x3
	int	jump_level	= 0;
	bool	jump_forced	= false;

	/* S is s */
	character c = ip(0, 0, ib);

	// Eb
		switch (s) {
		case 's':
			switch (c) {
			case '/':
				jump_type	= 1;
				jump_level	= -1;
				new_state	= 'a';
				break;
			case '!':
				jump_type	= 1;
				new_state	= 'e';
				break;
			default:
				// j s Ej out
				jump_type	= 1;
				new_state	= 's';
				break;
			}
			break;
		case 'a':
			switch (c) {
			case '*':
				jump_type	= 1;
				jump_level	= -1;
				new_state	= 'b';
				break;
			default:
				jump_type	= 1;
				jump_level	= 1;
				new_state	= 'n';
				break;
			}
			break;
		case 'n':
			jump_type	= 1;
			new_state	= 's';
			break;
		case 'b':
			switch (c) {
			case '*':
				jump_type	= 1;
				new_state	= 'c';
				break;
			default:
				jump_type	= 1;
				jump_level	= 1;
				new_state	= 'd';
				break;
			}
			break;
		case 'c':
			switch (c) {
			case '/':
				// j+* s Ej clear
				jump_type	= 1;
				jump_level	= 2;
				jump_forced	= true;
				new_state	= 's';
				break;
			default:
				jump_type	= 1;
				jump_level	= 1;
				new_state	= 'd';
				break;
			}
			break;
		case 'd':
			jump_type	= 1;
			jump_level	= -1;
			new_state	= 'b';
			break;
		} // switch s
	// Eb -->

	// B
		ib.push_front(c);
	// Ej
		if (jump_type) {
			switch (s) {
			case 's':
				switch (c) {
				case '/':
				case '!':
					break;
				default:
					out(s, new_state, c, ib);
					break;
				}
				break;
			case 'c':
				switch (c) {
				case '/':
					clear(s, new_state, c, ib);
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
	buffer		input_buffer;
	bufferlist	protect_buffers;
	statestack	nestcall_statestack;

	state		current_state = "s";	// B1
	do {
		A_upper_loop(
			A_upper_input,
			input_buffer,
			protect_buffers,
			nestcall_statestack,
			current_state);
	} while (state != "e");			// B2
}
