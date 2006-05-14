
#include "stdhdrs.h"
#include <cpf/dt/list.h>

#include <cpf/test/stl.h>               /* simple test lang */

stl_project_t t_list = {
    {
        /* type c: ! means null */
        { '+', "list_push", "c", t_list_push },
        { '-', "list_pop", "c", t_list_pop },
        { '>', "list_unshift", "c", t_list_unshift },
        { '<', "list_shift", "c", t_list_shift },
        { '=', "list_size", "i", t_list_size },
    }, 5,
    " =0 -! <!
      +1 +2 +3 +4 -4 -3 -2 -1 =0 -! <!
      >1 >2 >3 <3 <2 <1 =0
      +1 +2 +3 <1 <2 <3 =0
      +5 +6 +7 <5 >x >y -7 -6 -x -y =0 -! <! ",
};

int main() {
    stl_test(&t_list);

}
