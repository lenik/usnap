// ActiveObjectGateIO.cpp : Defines the entry point for the application.
//

#include "stdafx.h"



BOOL ActiveObject_Activity(ACTIVEOBJECT_DESCRIPTION, ACTIVITY_DESCRIPTION) {
	if (ACTIVEOBJECT_DESCRIPTION->bHasID) {
		if (ACTIVITY_DESCRIPTION->direction == IN) {
			DATABASE.ADD;
			HGATE = OPEN_WHICH_GATE(ACTIVEOBJECT_DESCRIPTION->OBJECT_TYPE);

			SET_GATE_STATUS(HGATE, AUTO_CLOSE | TIMEOUT_CLOSE);
		} else {
			HGATE = OPEN_WHICH_GATE(ACTIVEOBJECT_DESCRIPTION->OBJECT_TYPE);

			SET_GATE_STATUS(HGATE, AUTO_CLOSE | TIMEOUT_CLOSE);
			WAIT_GATE_EVENT {
				IF (OBJECT_COMPLETE_OUT) {
					DATABASE.REMOVE
				}
			}
		}
	}
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.

	return 0;
}
