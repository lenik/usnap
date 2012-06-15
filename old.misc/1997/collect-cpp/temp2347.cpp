#include "stdio.h"

void main()
{
    int* p = 0x00000000;    // pointer to NULL
    puts("hello");
    try{
        puts("in try");
        try{
            puts("in try");
            *p = 13;    // causes an access violation exception;
        }__finally{
            puts("in finally");
        }
    }__except(puts("in filter"), 1){
        puts("in except");
    }
    puts("world");
}
