int printf(const char *format, ...);
long strtol(const char *s,char **endptr,int radix);
char *ltoa(long value,char *string,int radix);
void main(int argc,char **argv)
{long l;
 char *s;
 if(argc<4) {printf("Usage: JZ <OldNum> <OldJZ> <NewJZ>\n");return;}
 l=strtol(argv[1],0,strtol(argv[2],0,10));
 printf("%s\n",ltoa(l,s,strtol(argv[3],0,10)));
}