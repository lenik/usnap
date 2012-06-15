#ifndef __XMS_H
#define __XMS_H

typedef struct {
        unsigned long numLong;
        unsigned      sHandle;
        unsigned long sPtr;
        unsigned      tHandle;
        unsigned long tPtr;
    } XMS_MOVE;

extern void far * call_xms;
extern unsigned char xms_error;
extern int INIT_XMS, XMS_handle_16, XMS_handle_16k;

int xms_test(void);
unsigned xms_version(void);
unsigned xms_freemem(void);
unsigned xms_malloc(unsigned num);
unsigned xms_free(unsigned handle);
int xms_move(unsigned long numLong, unsigned sHandle,unsigned long sPtr,
             unsigned tHandle,unsigned long tPtr);
void * xms_lock(unsigned handle);
int xms_unlock(unsigned handle);
unsigned xms_remalloc(unsigned num, unsigned handle);
unsigned long xms_ptr(unsigned handle);
unsigned xms_embhandle(unsigned handle);
unsigned umb_freemem(void);
unsigned umb_malloc(unsigned num);
unsigned umb_free(unsigned UMBHandle);
unsigned hma_malloc(unsigned num);
unsigned hma_free(void);
unsigned A20_ctrl(char num);
int read_file_to_xms(char *fn, int *Thandle);

#endif