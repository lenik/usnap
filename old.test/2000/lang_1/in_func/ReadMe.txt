

不能通过这种方法传递变量
	{
		int x;
		void f1();
		f1();
	}

	void f1() {
		x = 0;
	}
