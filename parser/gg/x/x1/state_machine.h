


struct in_stream {
};

//struct out_stream?

struct state {

	// acceptable.
	//	for multi-level acceptable, is it can implemented in 1-level?
	int bAccept: 1;

	// referred state won't be removed, when doing optimizing.
	int bReferred: 1;

	// trigger the arrival event.
	int bArrival: 1;

	// trigger the leave event.
	int bLeave: 1;

	list trans;

	// remove this state when in_counts == 0.
	int in_counts;

	int out_counts;
};


struct state_tran {
	struct unit {
		struct {
			int bEnter;		// enter into a state sub-procedure
			int bLeave;		// leave and return to outer proc.
			int bSave;		// save current stream pos.
			int bLoad;		// restore stream pos to saved.
		};
		input		in_char;
		input		look_ahead;
		state *		target;
		int		prior;		// for same in_char(s), the prior for this tran-unit.
	};
};


struct input_event {

	// pvt_void for epsilon(empty).
	PVT input_desc;
};


nfa_to_dfa();
get_reverse_dfa();
