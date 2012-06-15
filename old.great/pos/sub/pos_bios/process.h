

struct process {
	//
};

struct thread {
	SEH *pException;
	struct {
		int bRunning: 1;
	};

	int priority;

};
