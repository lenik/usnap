#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<errno.h>

main(int argc,char *argv[])
{
 int s=0,f;

 printf("File Protecter v1.00 (Shareware)\n\n");

 if (argc!=3)
   do {
     printf("File name:");
     scanf("%s",argv[1]);
     if ((f=open(argv[1],O_RDONLY))==-1) {
	perror("Error ");
	continue;} //if
     close(f);
     printf("\n0 --- Change file name\n");
     printf("1 --- Protect\n");
     printf("2 --- Unprotect\n");
     printf("Select> ");
     scanf("%d",&s);
   } while (s!=0);
 else
 f=open(argv[1],O_RDONLY);
