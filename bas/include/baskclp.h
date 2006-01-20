
#ifndef __baskclp_h__
#define __baskclp_h__

#include <cpf/types.h>


#define CLP_TYPEMASK        0x00ff
#define CLP_FORMMASK        0x0f00
#define CLP_OPTIONAL        0x1000
#define CLP_SUBROUTINE      0x8000


typedef enum _BAS_K_CLP_TYPE {
    CLP_BOOL,
    CLP_INT,
    CLP_LONG,
    CLP_FLOAT,
    CLP_DOUBLE,
    CLP_STRING,
    CLP_DATE,
    CLP_FILE,
    } CLP_TYPE;


typedef enum _BAS_K_CLP_FORM {
    CLP_SCALAR,
    CLP_LIST,
    CLP_MAP,
    } CLP_FORM;


typedef struct _BAS_K_CLP_ARGUMENT {
    STRING name,
    int flags,
    BAS_K_CLP_FORM form,
    BAS_K_CLP_TYPE type,
    POINTER ptr,
    } BAS_K_CLP_ARGUMENT;


#endif
