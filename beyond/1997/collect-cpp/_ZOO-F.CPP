#include <stdio.h>
#include <alloc.h>
#include "TopType.cpp"
#include "TopBin.cpp"
#include "TopFile.cpp"
#include <io.h>
#include <fcntl.h>

// ObjectData Percolate-Compressed-D2 (Zoo)-00 (Reserved) Macros
#define ODPC_D2_0210_INIT_ALREADYINIT		1
#define ODPC_D2_0210_INIT_FILEOPENERROR		2
#define ODPC_D2_0210_INIT_NOFILEIDENT		4
#define ODPC_D2_0210_INIT_OTHERFILEERROR	6

#define ODPC_D2_0210_STATUS_INIT		1
#define ODPC_D2_0210_STATUS_FILERWERROR		2
#define ODPC_D2_0210_STATUS_MEMORYERROR		4
#define ODPC_D2_0210_STATUS_ZOOERROR		8

class aZoo{
public:
  char *Filename;
public:
  struct _ZooHeader{
    char  HeaderText_1A[20]; //"ZOO 2.10 Archive."
    DWord ID;
    DWord OffsetToFirstFile;
    DWord Reserved;
    Byte  Version;
    Byte  MinVersion;
  } ZooHeader;
  DWord ZooID;
  struct _FileHeaderChain{
    _FileHeaderChain *Prev;
    _FileHeaderChain *Next;
    struct _EachFileHeader{
      DWord ID;
      Byte  DirEntryType;
      Byte  CompressionMethod;
      DWord OffsetToNextDir;
      DWord OffsetToNextHeader;
      Word  OriginalDataTime;
      Word  Unknown1;	// 81F6
      Word  CRC16;
      DWord UncompressedSize;
      DWord CompressedSize;
      Byte  CompressedVersion;
      Byte  CompressedMinVersion;
      Byte  DeletedFlag;
      DWord OffsetToComment;
      Word  CommentLength;
      Byte  Unknown2;
    } FileHeader;
    char* ASCIIZPathFilename;
    _FileHeaderChain(void);
    ~_FileHeaderChain(void);
  } *FileHeaderChain;
  Word FileNum;
public:
  Word Initialize(void);
public:
  int Handle;
  DWord CurPosition;
  int Status;
  _ZooHeader* GetHeader(void);
  _FileHeaderChain* GetFileHeaders(void);
  Word ReadFileStructure(void) {return 0;}
public:
  Word ReadFile(void) {return 0;}
public:
  aZoo(void);
  aZoo(char *_Filename);
  ~aZoo(void);
};

Word aZoo::Initialize(void){
  if (Filename==NULL) return ODPC_D2_0210_INIT_NOFILEIDENT;
  if (Status&ODPC_D2_0210_STATUS_INIT) return ODPC_D2_0210_INIT_ALREADYINIT;
  if (Handle) return ODPC_D2_0210_INIT_OTHERFILEERROR;
  if ((Handle=open(Filename, O_RDONLY|O_BINARY))==-1) {
    Handle=0;
    return ODPC_D2_0210_INIT_FILEOPENERROR;
  }
  Status=ODPC_D2_0210_STATUS_INIT;
  return 0;
}

_FileHeaderChain::_FileHeaderChain(void){
  ASCIIZPathFilename==NULL;
}
_FileHeaderChain::~_FileHeaderChain(void){
  if (ASCIIZPathFilename!=NULL) delete ASCIIZPathFilename;
}

_ZooHeader *aZoo::GetHeader(void){
  if (Status!=ODPC_D2_0210_STATUS_INIT) return NULL;
  if (read(Handle, &ZooHeader, sizeof(ZooHeader))==-1) {
    Status|=ODPC_D2_0210_STATUS_FILERWERROR;
    return NULL;
  }
  if (ZooHeader.ID!=ZooID) {
    Status|=ODPC_D2_0210_STATUS_ZOOERROR;
    return &ZooHeader;
  }
  return &ZooHeader;
}

_FileHeaderChain *aZoo::GetFileHeaders(void){
  long Len;
  if (Status!=ODPC_D2_0210_STATUS_INIT) return NULL;
  if (FileNum!=0) return NULL;
  if (lseek(Handle, ZooHeader.OffsetToFirstFile, SEEK_SET)==-1L) {
    Status|=ODPC_D2_0210_STATUS_FILERWERROR;
    return NULL;
  }
  if (!(FileHeaderChain=new _FileHeaderChain)) {
    Status|=ODPC_D2_0210_STATUS_MEMORYERROR;
    return NULL;
  } //Alloc the first header
  FileHeaderChain->Prev=FileHeaderChain->Next=NULL;
  if (read(Handle, &FileHeaderChain->FileHeader, sizeof(_EachFileHeader))==-1) {
    Status|=ODPC_D2_0210_STATUS_FILERWERROR;
    return NULL;
  } //Read the first header
  Len=topfileGetForwardASCIIZLength(Handle);
  if (!(FileHeaderChain->ASCIIZPathFilename=new char[Len+1])) {
    Status|=ODPC_D2_0210_STATUS_MEMORYERROR;
    return NULL;
  } //Alloc the first path/filename
  if (read(Handle, FileHeaderChain->ASCIIZPathFilename, Len)==-1) {
    Status|=ODPC_D2_0210_STATUS_FILERWERROR;
    return NULL;
  } //Read the first path/filename
  FileHeaderChain->ASCIIZPathFilename[Len]=0;
  if (FileHeaderChain->FileHeader.ID!=ZooID) {
    Status|=ODPC_D2_0210_STATUS_ZOOERROR;
    return NULL;
  }
  while (FileHeaderChain->FileHeader.ID==ZooID) {
    _FileHeaderChain *Last=FileHeaderChain;
    if (!(FileHeaderChain=new _FileHeaderChain)) {
      Status|=ODPC_D2_0210_STATUS_MEMORYERROR;
      FileHeaderChain=Last;
      return NULL;
    } //Alloc the next header
    Last->Next=FileHeaderChain;
    FileHeaderChain->Prev=Last;
    FileHeaderChain->Next=NULL;
    if (lseek(Handle, Last->FileHeader.OffsetToNextDir, SEEK_SET)==-1L){
      Status|=ODPC_D2_0210_STATUS_FILERWERROR;
      return NULL;
    } //Seek to next header
    if (read(Handle, &FileHeaderChain->FileHeader, sizeof(_EachFileHeader))==-1) {
      Status|=ODPC_D2_0210_STATUS_FILERWERROR;
      return NULL;
    } //Read the next header
    Len=topfileGetForwardASCIIZLength(Handle);
    if (!(FileHeaderChain->ASCIIZPathFilename=new char[Len+1])) {
      Status|=ODPC_D2_0210_STATUS_MEMORYERROR;
      return NULL;
    } //Alloc the next path/filename
    if (read(Handle, FileHeaderChain->ASCIIZPathFilename, Len)==-1) {
      Status|=ODPC_D2_0210_STATUS_FILERWERROR;
      return NULL;
    } //Read the next path/filename
    FileHeaderChain->ASCIIZPathFilename[Len]=0;
    FileNum++;
    if (FileHeaderChain->FileHeader.OffsetToNextDir==0L) return FileHeaderChain;
  } //while
  Status|=ODPC_D2_0210_STATUS_ZOOERROR;
  return NULL;
}

aZoo::aZoo(void){
  Filename=NULL;
  Handle=CurPosition=0;
  FileNum=0;
  ZooID=0xFDC4A7DC;
  FileHeaderChain=NULL;
  Status=0;
  return;
}
aZoo::aZoo(char *_Filename){
  Filename=NULL;
  Handle=CurPosition=0;
  FileNum=0;
  ZooID=0xFDC4A7DC;
  FileHeaderChain=NULL;
  Status=0;
  Filename=_Filename;
  return;
}
aZoo::~aZoo(void){
  if (Filename!=NULL) delete Filename;
  if (FileHeaderChain!=NULL) {
    while (FileHeaderChain->Prev!=NULL) FileHeaderChain=FileHeaderChain->Prev;
    while (FileHeaderChain->Next!=NULL) {
      FileHeaderChain=FileHeaderChain->Next;
      delete FileHeaderChain->Prev;
    } delete FileHeaderChain;
  }
  if (Handle) close(Handle);
  return;
}

void main(int argc, char **argv){
  DWord cl=coreleft();
  aZoo *ZooF;
  cl=coreleft();
  if (argc<2) { printf("Usage: %s %s\n", argv[0], argv[1]); return; }
  ZooF=new aZoo(argv[1]);
  cl=coreleft();
  if (ZooF->Initialize()!=0) {
    perror("Error in initializing ");
    return;
  } cl=coreleft();
  if (ZooF->GetHeader()==NULL) {
    perror("Error in reading zoo header ");
    return;
  } cl=coreleft();
  if (ZooF->GetFileHeaders()==NULL) {
    perror("Error in reading zoo file headers ");
    return;
  } cl=coreleft();
  while (ZooF->FileHeaderChain->Prev!=NULL) ZooF->FileHeaderChain=ZooF->FileHeaderChain->Prev;
  printf("\t    File\tComSize\tUnSize\tNext\n");
  while (ZooF->FileHeaderChain->Next!=NULL) {
    printf("%16s\t%lu\t%lu\t%lu\n", ZooF->FileHeaderChain->ASCIIZPathFilename,
		ZooF->FileHeaderChain->FileHeader.UncompressedSize,
		ZooF->FileHeaderChain->FileHeader.CompressedSize,
		ZooF->FileHeaderChain->FileHeader.OffsetToNextDir
    );
    ZooF->FileHeaderChain=ZooF->FileHeaderChain->Next;
  }
  printf("Total : %d files.\n", ZooF->FileNum);
  delete ZooF;
  cl=coreleft();
  return;
}
