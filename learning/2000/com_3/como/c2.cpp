
#pragma once

#include "stdafx.h"

class c1 {
	int m1;
};

typedef c1	TC1;

class c2 : public TC1 {
	int m2;
};

static c2 g_c2_1;
