// MP3 to WAV converter (c) '97 N. Beisert (nbeisert@physik.tu-muenchen.de)
// you are free to do with this stuff whatever you like. it's freeware.

#include <conio.h>
#include <dos.h>
#include <direct.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>

const int buflen=16384;
static char buf[buflen];

struct
{
  char riff[4];
  long rifflen;
  char wave[4];
  char fmt[4];
  long fmtlen;
  short format;
  short chan;
  long freq;
  long rate;
  short align;
  short bits;
  short extra;
  short dunno1;
  short dunno2;
  short dunno3;
  short blklen;
  short dunno4;
  short dunno5;
  char data[4];
  long datalen;
} wavehdr;

int getheader(unsigned long hdr, int &layer, int &ver, int &freq, int &stereo, int &rate)
{
  if ((hdr&0xF0FF)!=0xF0FF)
    return 0;
  ver=(hdr>>11)&1;
  layer=4-((hdr>>9)&3);
  if (layer==4)
    return 0;
  int rateidx=(hdr>>20)&15;
  int frqidx=(hdr>>18)&3;
  stereo="\x02\x02\x02\x01"[(hdr>>30)&3];
  switch (frqidx)
  {
  case 0: freq=44100; break;
  case 1: freq=48000; break;
  case 2: freq=32000; break;
  default: return 0;
  }
  if (ver)
    switch (layer)
    {
    case 1: rate="\x00\x04\x08\x0C\x10\x14\x18\x1C\x20\x24\x28\x2C\x30\x34\x38\x00"[rateidx]*1000; break;
    case 2: rate="\x00\x04\x06\x07\x08\x0A\x0C\x0E\x10\x14\x18\x1C\x20\x28\x30\x00"[rateidx]*1000; break;
    case 3: rate="\x00\x04\x05\x06\x07\x08\x0A\x0C\x0E\x10\x14\x18\x1C\x20\x28\x00"[rateidx]*1000; break;
    default: return 0;
    }
  else
    switch (layer)
    {
    case 1: rate="\x00\x04\x06\x07\x08\x0A\x0C\x0E\x10\x12\x14\x16\x18\x1C\x20\x00"[rateidx]*1000; break;
    case 2: rate="\x00\x01\x02\x03\x04\x05\x06\x07\x08\x0A\x0C\x0E\x10\x12\x14\x00"[rateidx]*1000; break;
    case 3: rate="\x00\x01\x02\x03\x04\x05\x06\x07\x08\x0A\x0C\x0E\x10\x12\x14\x00"[rateidx]*1000; break;
    default: return 0;
    }

  if (!ver)
    freq>>=1;
  if (!rate)
    return 0;
  return 1;
}

int conv(const char *name, int kill, int ext, int excl)
{
  static char outname[300];

  strcpy(outname, name);
  if (!ext&&!stricmp(outname+strlen(outname)-4, ".mp3"))
    outname[strlen(outname)-4]=0;
  strcat(outname, ".wav");

  char tag[128];
  int fi=open(name, O_RDONLY|O_BINARY);
  if (fi<0)
    return 1;
  long len=filelength(fi);
  lseek(fi, -128, SEEK_END);
  *tag=0;
  read(fi, tag, 128);
  if (!memcmp(tag, "TAG", 3))
    len-=128;
  lseek(fi, 0, SEEK_SET);
  unsigned long hdr;
  read(fi, &hdr, 4);
  lseek(fi, 0, SEEK_SET);

  int chan=2;
  int layer,freq,rate,ver;
  if (!getheader(hdr, layer, ver, freq, chan, rate))
    return 1;
  if (layer!=3)
    return 1;
  int blklen=(288<<ver)*chan*rate/freq;

  memcpy(wavehdr.riff, "RIFF", 4);
  wavehdr.rifflen=sizeof(wavehdr)-8+(memcmp(tag, "TAG", 3)?0:136)+len;
  memcpy(wavehdr.wave, "WAVE", 4);
  memcpy(wavehdr.fmt, "fmt ", 4);
  wavehdr.fmtlen=30;
  wavehdr.format=0x55;
  wavehdr.bits=0;
  wavehdr.chan=chan;
  wavehdr.freq=freq;
  wavehdr.rate=rate;
  wavehdr.align=(layer==1)?4:1;
  wavehdr.extra=12;
  wavehdr.dunno1=1;
  wavehdr.dunno2=2;
  wavehdr.dunno3=0;
  wavehdr.blklen=blklen;
  wavehdr.dunno4=1;
  wavehdr.dunno5=0x571;
  memcpy(wavehdr.data, "data", 4);
  wavehdr.datalen=len;

  int fo=open(outname, O_WRONLY|O_BINARY|O_TRUNC|O_CREAT|(excl?O_EXCL:0), S_IREAD|S_IWRITE);
  if (fo<0)
    return 0;
  write(fo, &wavehdr, sizeof(wavehdr));
  cputs(name);

  long pos=0;
  while (1)
  {
    long l=len-pos;
    if (l>buflen)
      l=buflen;
    if (!l)
      break;
    read(fi, buf, l);
    write(fo, buf, l);
    pos+=l;
  }
  if (!memcmp(tag, "TAG", 3))
  {
    write(fo, "$TAG", 4);
    write(fo, "\x80\0\0\0", 4);
    write(fo, tag, 128);
  }
  len=filelength(fo)-8;
  lseek(fo, 4, SEEK_SET);
  write(fo, &len, 4);
  close(fi);
  close(fo);
  if (kill)
    unlink(name);
  cputs("\n");
  return 0;
}

void convdir(const char *base, const char *sub, const char *mask, int recurse, int kill, int ext, int excl)
{
  char *pathbuf=new char [400];
  strcpy(pathbuf, base);
  strcat(pathbuf, sub);
  strcat(pathbuf, mask);

  const int buflen=4096;
  static char buffer[buflen];
  find_t fnd;
  int found;
  for (found=!_dos_findfirst(pathbuf, _A_NORMAL, &fnd); found; found=!_dos_findnext(&fnd))
  {
    strcpy(pathbuf, base);
    strcat(pathbuf, sub);
    strcat(pathbuf, fnd.name);
    conv(pathbuf, kill, ext, excl);
  }
  if (!recurse)
    return;
  strcpy(pathbuf, base);
  strcat(pathbuf, sub);
  strcat(pathbuf, "*");
  for (found=!_dos_findfirst(pathbuf, _A_SUBDIR, &fnd); found; found=!_dos_findnext(&fnd))
  {
    if (!(fnd.attrib&_A_SUBDIR)||!strcmp(fnd.name, ".")||!strcmp(fnd.name, ".."))
      continue;
    strcpy(pathbuf, sub);
    strcat(pathbuf, fnd.name);
    strcat(pathbuf, "\\");

    convdir(base, pathbuf, mask, 1, kill, ext, excl);
  }
  delete pathbuf;
}

int isdir(const char *x)
{
  find_t fnd;
  if (strchr(x, '?')||strchr(x, '*')||_dos_findfirst(x, _A_SUBDIR, &fnd))
    return 0;
  return (fnd.attrib&_A_SUBDIR)?1:0;
}


int main(int argn, char **argv)
{
  cputs("mp3 to mp3-wav converter (c) '97 Niklas Beisert\n\n");

  int excl=1;
  int help=1;
  int kill=0;
  int recurse=0;
  int ext=0;
  int i;
  for (i=1; i<argn; i++)
  {
    if (!stricmp(argv[i], "/k"))
      kill=1;
    if (!stricmp(argv[i], "/r"))
      recurse=1;
    if (!stricmp(argv[i], "/e"))
      ext=1;
    if (!stricmp(argv[i], "/o"))
      excl=0;
  }
  for (i=1; i<argn; i++)
  {
    if (argv[i][0]=='/')
      continue;

    char path[300];
    strcpy(path, argv[i]);
    if (path[0]&&(path[1]==':')&&(path[2]!='\\'))
    {
      memmove(path+4, path+2, strlen(path)-1);
      path[2]='.';
      path[3]='\\';
    }
    char mask[300];
    if (isdir(path))
      strcat(path, "\\");
    char *p=strrchr(path, '\\')?(strrchr(path, '\\')+1):path;
    strcpy(mask, p);
    *p=0;
    if (!*path)
      strcpy(path, ".\\");
    if (!*mask)
      strcpy(mask, "*");

    convdir(path, "", mask, recurse, kill, ext, excl);
    help=0;
  }

  if (help)
  {
    cputs("syntax: mp3wav [/r] [/k] [/o] [/e] files\n");
    cputs("  /r: recurse subdirectories\n");
    cputs("  /o: overwrite existing files\n");
    cputs("  /k: kill originals\n");
    cputs("  /e: always add .wav extension (otherwise replace .mp3 by .wav)\n");
  }
  return 0;
}
