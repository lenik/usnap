#include<stdio.h>
#include<dir.h>
int main(int argc,char *argv[])
{int t;
 if (getdisk()!='f'-'a') {printf("Sorry, you couldn't execute DOS command at C: to E: Drive.\n\a");return (getdisk());}
