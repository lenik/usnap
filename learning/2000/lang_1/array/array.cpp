// array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class fish {
	static int lastid;
public:
	int id;

	int weight;

	fish() {
		id = lastid++;
		printf("Fish%d\tfish::fish()\n", id);
	}
	fish(const fish& o_o) {
		weight = o_o.weight;
	}
	~fish() {
		printf("Fish%d\tfish::~~fish()\n", id);
	}

	void run() {
		printf("oh, my lovely fish%d\n", id);
	}
};

int fish::lastid = 0;

typedef CArray<fish, fish> fisharray;

struct aaa {
	int x;
	aaa(int _x) {
		x = _x;
	}
};

int main(int argc, char* argv[])
{

	aaa A1[3](10);
	aaa *pA2 = new aaa[3];

	//

	fisharray myfishes;
	fish fish1;
	fish fish2;
	fish fish3;

	fish2 = fish1;

	myfishes.Add(fish1);
	myfishes.Add(fish2);
	myfishes.Add(fish3);

	myfishes[0].run();
	myfishes[1].run();
	myfishes[2].run();

	return 0;
}
