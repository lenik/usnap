
// standard module port

#define GENPORT_ECHO			0
#define GENPORT_DISCARD			1
#define GENPORT_CALLER			2
#define GENPORT_CONTROL			10
#define GENPORT_TIME			13

HIENUM HIAPI default_port(int port, CDT *cdt, void *ret);

typedef HIENUM (HIAPI *PORTPROC)(int port, CDT *cdt, void *ret);
