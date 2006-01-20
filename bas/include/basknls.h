
#ifndef __BASKNLS_H__
#define __BASKNLS_H__

#define BAS_MSG(id) (msg_factory->get_message(BAS_MSG_##id))

typedef struct _bas_msg_factory_t {
    bas_str_t get_message(int msg_id);
} bas_msg_factory;

#endif
