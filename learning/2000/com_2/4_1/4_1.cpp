// 4_1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/timeb.h>

#include "4_1.h"

static char *g_astrFortunes[] = {
	"You are strong is body and spirit. ",
	"You are strong in perspiration and odor. ",
	"Good fortune smiles upon the distributed. ",
	"You will solve the world hunger problem. ",
	"I never met an object I didn't like. ",
	"Edit, compile, link, crash, sigh. ",
	"Never judge a stack dump by its arguments. ",
	"Card carrying member off the Bug Police. ",
	"You make dilbert lok charming and sophisticated. "
};

static const ULONG g_ulNumFortunes = sizeof(g_astrFortunes) / sizeof(char *);

CFortuneTeller::CFortuneTeller() {
	struct _timeb timebuffer;
	_ftime(&timebuffer);
	srand(timebuffer.millitm);
}

char *CFortuneTeller::GetFortune() {
	return g_astrFortunes[rand() % g_ulNumFortunes];
}
