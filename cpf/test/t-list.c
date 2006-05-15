
#include "stdhdrs.h"
#include <cpf/dt/list.h>

#include <cpf/test/stl.h>               /* simple test lang */

int _stdcall t_list_push(stl_project_t *prj, x64_t *args) {
    list_t *l = (list_t *)prj->user.p;
    char c = args[0].c;
    l = list_pushv(l, c);
    prj->user.p = l;
    return 1;
}

int _stdcall t_list_unshift(stl_project_t *prj, x64_t *args) {
    list_t *l = (list_t *)prj->user.p;
    char c = args[0].c;
    l = list_unshiftv(l, c);
    prj->user.p = l;
    return 1;
}

int _stdcall t_list_pop(stl_project_t *prj, x64_t *args) {
    list_t *l = (list_t *)prj->user.p;
    list_t *detached;
    char c = args[0].c;
    int ret;
    if (l == 0) {
        ret = c == '!';
        l = list_pop(l);
    } else {
        l = list_pop_detached(l, &detached);
        ret = c == list_getv_(detached, char);
        list_free(detached);
    }
    prj->user.p = l;
    return ret;
}

int _stdcall t_list_shift(stl_project_t *prj, x64_t *args) {
    list_t *l = (list_t *)prj->user.p;
    list_t *detached;
    char c = args[0].c;
    int ret;
    if (l == 0) {
        ret = c == '!';
        l = list_shift(l);
    } else {
        l = list_shift_detached(l, &detached);
        ret = c == list_getv_(detached, char);
        list_free(detached);
    }
    prj->user.p = l;
    return ret;
}

int _stdcall t_list_size(stl_project_t *prj, x64_t *args) {
    list_t *l = (list_t *)prj->user.p;
    size_t n = args[0].u;
    return list_size(l) == n;
}

stl_project_t t_list = {
    {
        /* type c: ! means null */
        { '+', "list_push",     "c", t_list_push },
        { '-', "list_pop",      "c", t_list_pop },
        { '>', "list_unshift",  "c", t_list_unshift },
        { '<', "list_shift",    "c", t_list_shift },
        { '=', "list_size",     "i", t_list_size },
    }, 5, " \
        =0 -! <! \
        +1 +2 +3 +4 -4 -3 -2 -1 =0 -! <! \
        >1 >2 >3 <3 <2 <1 =0 \
        +1 +2 +3 <1 <2 <3 =0 \
        +5 +6 +7 <5 >x >y -7 -6 -x -y =0 -! <! \
    ",
};

int main() {
    t_list.user.p = 0;
    stl_test(&t_list);
    stl_report(&t_list);
}
