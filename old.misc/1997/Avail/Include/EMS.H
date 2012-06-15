#ifndef __EMS_H
#define __EMS_H

extern unsigned char ems_error;
extern int INIT_EMS, EMS_handle_16, EMS_handle_16k;

unsigned ems_test(void);
unsigned ems_version(void);
unsigned ems_status(void);
unsigned ems_pageseg(void);
unsigned ems_freepage(void);
unsigned ems_malloc(unsigned num);
unsigned ems_pagemap(unsigned page, unsigned log_page, unsigned handle);
unsigned ems_free(unsigned handle);
unsigned ems_savepage(unsigned handle);
unsigned ems_restorepage(unsigned handle);
unsigned ems_freeheadle(void);
unsigned ems_headlepages(unsigned handle);
unsigned ems_allheadlepages(unsigned char * buffer);
unsigned ems_getpagemap(unsigned char *buffer);
unsigned ems_setpagemap(unsigned char *buffer);
unsigned ems_changepagemap(unsigned char *in_buffer,
                           unsigned char *out_buffer);
unsigned ems_pagemapsize(void);
int ems_move(unsigned long numLong, unsigned sHandle,unsigned long  sPtr,
                                    unsigned tHandle,unsigned long  tPtr);
int read_file_to_ems(char *fn, int *Thandle);

#endif