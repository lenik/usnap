// langtest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"

struct CA {
	static char *name;
};

char *CA::name = "struct CA";

struct CB : public CA {
	static char *name2;
};

char *CB::name2 = "struct CB";

struct CC : public CA {
	static char *name;
};

char *CC::name = "struct CC";

class CStr {
	char *m_str;
public:
	void fcc() { cout << m_str << endl; }

	CStr& operator = (char *lpstr) {
		int len = strlen(lpstr);
		if (m_str == NULL) {
			m_str = new char[len + 1];
			strcpy(m_str, lpstr);
		}
	}

};

#define main4	main

int main1(int argc, char* argv[])
{
	long l;
	double xx;
	l = 123;
	xx = (static_cast<double>(l));
	//l = reinterpret_cast<long>(xx);

	return 0;
}

void main2() {
//	CStr bb;
}

// shortest
void main3() {
	coSetINT	ints;

	coINT c = (coINT)ints;

	ints += 3;
	ints += 4;

	coSetINT	o_i;
	o_i = ints;
	ints[0]<<=1;
	ints[1]<<=1;
	o_i += ints;
	c = (coINT)o_i;
	for (int i = 0; i < c; i++) {
		printf("ints[%d] = %d\n", i, o_i[i]);
	}

	return;
}

void main4() {
	coSetF<int>	intf;

	coINT c = (coINT)intf;

	//intf
}

// 跨平台 回调 的 实现
void main5() {
}
