// local_rest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
__std;
#include <math.h>


enum funcs {
    f_calc,                 // void **param, to hold the state
    f_restore,              // void *param
    f_last_unavailable,     // param unused

    f_internal_save_state,  // void **param
};

enum ret_value {
    ret_ok,
    ret_value_negative,
    ret_pointer_error
};

ret_value func1(int func, DWORD param,
          int a1, int b1, int c1,
          int a2, int b2, int c2,
          double *px, double *py) {

    //  a1x + b1y + c1 = 0
    //  a2x + b2y + c2 = 0

    //      the result must x > 0, y > 0,
    //      otherwise a exception is made.

    double D;
    double Dx;
    double Dy;
    double x, y;

    switch (func) {
    case f_internal_save_state:
        {
            DWORD x;
            __asm mov x, esp
            *(DWORD *)param = x;
        }
        return ret_ok;

    case f_restore:
        if (param) {
            BYTE *state_block = (BYTE *)param;
            DWORD inc_esp, cesp;
            func1(f_internal_save_state, (DWORD)&inc_esp, 0, 0, 0, 0, 0, 0, 0, 0);
            __asm mov cesp, esp;
            long state_size = cesp - inc_esp;
            void *c_state_begin = (void *)(cesp);
            memcpy(c_state_begin, state_block, state_size);
        }
    case f_calc:
        c1 = -c1;
        c2 = -c2;
        D =     a1 * b2 - a2 * b1;
        Dx =    c1 * b2 - c2 * b1;
        Dy =    a1 * c2 - a2 * c1;

        if (param) {
            if (*(void **)param) {
                delete *(void **)param;
            }
            BYTE *state_block = 0;
            DWORD inc_esp, cesp;
            func1(f_internal_save_state, (DWORD)&inc_esp, 0, 0, 0, 0, 0, 0, 0, 0);
            __asm mov cesp, esp
            long state_size = cesp - inc_esp;
            void *c_state_begin = (void *)(cesp);
            state_block = new BYTE[state_size];
            memcpy(state_block, c_state_begin, state_size);
            *(void **)param = state_block;
        }

        x = Dx / D;
        y = Dy / D;

        if (!px || !py) {
            return ret_pointer_error;
        }
        *px = x;
        *py = y;

        if (x < 0 || y < 0) {
            return ret_value_negative;
        }

        return ret_ok;
    default:
        __asm int 3
    }

    return ret_ok;
}


int main(int argc, char* argv[])
{
	double x, y;

    double f1[] = { 3, 5,  29 };
    double f2[] = { -7, 2, 13 };

    void *pstate = 0;
    int iCount = 0;
    ret_value rv;
    rv = func1(                              // <---+
        f_calc, (DWORD)&pstate,              //     |
        f1[0], f1[1], f1[2],                 //     |
        f2[0], f2[1], f2[2],                 //     |
        &x, &y);                             //     |
    iCount++;                                //     |
    __asm int 3
    if (iCount < 10 && rv != ret_ok) {       //     |
        rv = func1(                          //     |
            f_restore, (DWORD)pstate,        //     |
            0, 0, 0, 0, 0, 0, &x, &y         //     |
            );                               //     |
        // this returns to -------------------------+
    }

    cout << f1[0] << "x + " << f1[1] << "y + " << f1[2] << " = 0" << endl;
    cout << f2[0] << "x + " << f2[1] << "y + " << f2[2] << " = 0" << endl;
    cout << "x = " << x << endl
         << "y = " << y << endl;

    cout << f1[0] << "x + " << f1[1] << "y + " << f1[2] << " = "
         << f1[0] * x + f1[1] * y + f1[2]
         << endl;
    cout << f2[0] << "x + " << f2[1] << "y + " << f2[2] << " = "
         << f2[0] * x + f2[1] * y + f2[2]
         << endl;

    cout << "Count: " << iCount << endl;
	return 0;
}
