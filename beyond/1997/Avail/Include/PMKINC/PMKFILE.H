#ifndef __PMKFILE_H
	#define __PMKFILE_H
	#ifndef Fpmk
	#define Fpmk 0
	#endif
	#ifndef Fbas
	#define Fbas 1
	#endif
	#ifndef Fpas
	#define Fpas 2
	#endif
	#ifndef Fc
	#define Fc   3
	#endif
	char far*getfiletype(char filetype) {char *Fileextn[4]={".Pmk",".Bas",".Pas",".C"};return (Fileextn[filetype]);}
//	int  far createfile(char *filename,char *data,long len)
//	{FILE *f;long c;
//	 if((f=fopen(filename,"wb"))==-1)return -1;
//	 for(c=0;c<len;c++)fwrite(data[c],1,1,f);
//	 fclose(f);
//	 return 0;
//	}
#endif