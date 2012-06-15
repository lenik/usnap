// YTMF.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream.h>

#include <pos/pos.h>
using namespace pos;

#include "YTMF_script.h"


struct MyContext : public ResultContext {
	int field;
};


int main(int argc, char* argv[])
{
	MyContext result;

	if (!YTMFParse(&result, &cin, &cout)) {
		cerr << "error parsing!" << endl;
		return -1;
	}

	// parse the result...

	return 0;
}
