// coma1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

interface IGlyph {
	public:
	virtual void a() = 0;
};

class CGlyph : public IGlyph {
	void a() {
		printf("A");
	}
};

int main(int argc, char* argv[])
{
	printf("Hello World!\n");
	return 0;
}
