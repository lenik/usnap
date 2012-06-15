// scomp2_client1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <_scomp2.h>

class bytecomp : public stream_units_work {
public:
	virtual int operator ++();
	virtual int operator --();
	virtual int operator ==(const bytecomp& o_o) const;
};

int bytecomp::operator ++() {
	this->p.front() = (char *)this->p.front() + 1;
	return stream_units_work::operator ++();
}

int bytecomp::operator --() {
	this->p.front() = (char *)this->p.front() - 1;
	return stream_units_work::operator --();
}

int bytecomp::operator ==(const bytecomp& o_o) const {
	return *(char *)this->p.front() == *(char *)o_o.p.front();
}

int main(int argc, char* argv[])
{
	printf("Hello World!\n");
	return 0;
}
