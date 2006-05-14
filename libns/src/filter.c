
#include "stdhdrs.h"
#include <cpf/assert.h>
#include <cpf/dt/buffer.h>

#include "libns.h"
#include "filter.h"

void _stdcall nsdef_pkt_in(nssvc_t *svc, x32_t sel, void *data, size_t size) {
    list_t *blk;
    while (blk = list_shift(&svc->pd_pkt_in)) {
        svc->bin_in(svc, sel, blk->data, blk->size);
        list_free(blk);
    }
    svc->bin_in(svc, sel, data, size);
}

void _stdcall nsdef_bin_in(nssvc_t *svc, x32_t sel, void *data, size_t size) {
    list_t *blk;
    u8_t *blk_p;
    size_t blk_size;
    size_t blk_markbegin = 0;
    size_t blk_markend = 0;
    int last = -1;
    int c;
    buffer_t *line = 0;
    for (;;) {
        /* dump blk_mark[] before switching between blocks*/
        if (blk_markend > blk_markbegin)
            line = buffer_append(line, blk->data + blk_markbegin,
                                 blk_markend - blk_markbegin);

        /* foreach block */
        if (blk = list_shift(&svc->pd_bin_in)) {
            blk_p = blk->data;
            blk_size = blk->size;
        } else if (data) {
            blk_p = data;
            blk_size = size;
            data = 0;
        } else {
            break;
        }

        blk_markbegin = 0;
        blk_markend = 0;
        while (blk_size--) {
            c = *blk_p++;
            switch (last) {
            case '\\':
                /* dump blk_mark[] . c */
                if (blk_markend > blk_markbegin) {
                    line = buffer_append(line, blk->data + blk_markbegin,
                                         blk_markend - blk_markbegin);
                    blk_markbegin = blk_markend + 1;
                    blk_markend = blk_markbegin;
                }
                buffer_append_val(line, u8_t, c);
                last = -1;
                break;
            case ';':
                svc->line_in(svc, sel, line->data, line->size - 1);
                buffer_overwrite(line, 0, &c, 1);
                last = c;
            case -1:
                last = c;
                break;
            default:
                buffer_append_val(line, u8_t, last);
                last = c;
            }
        }
    }
    /*  */
}

void _stdcall nsdef_line_in(nssvc_t *svc, x32_t sel, void *data, size_t size) {
    nscmdi_t *cmd;
    x32_t *args;
    int nopts;

    svc->cmd_in(svc, sel, cmd, args, nopts);
}

void _stdcall nsdef_cmd_in(nssvc_t *svc, x32_t sel, nscmdi_t *cmd,
                           x32_t *args, int nopts) {
    /* foreach svc->lastcmd->subcmds */
    /* foreach svc->mods */
}

void _stdcall nsdef_cmd_out(nssvc_t *svc, x32_t sel, nscmdi_t *cmd,
                            x32_t *args, int nopts) {
    buffer_t *line = 0;
    nscmd_t *proto = cmd->proto;
    nstype_t t;
    line = buffer_append(line, proto->name, strlen(proto->name));
    for (int i = 0; i < proto->nargs + nopts; i++) {
        if (i < proto->nargs)
            t = proto->args[i];
        else
            t = proto->opts[i - proto->nargs];
        switch (t) {
        case NSTYPE_INT:
            break;
        case NSTYPE_LONG:
            break;
        case NSTYPE_SHORT:
            break;
        case NSTYPE_CHAR:
            break;
        case NSTYPE_FLOAT:
            break;
        case NSTYPE_DOUBLE:
            break;
        case NSTYPE_BOOL:
            break;
        case NSTYPE_STRING:
            break;
        case NSTYPE_BIN:
            break;
        case NSTYPE_ARRAY:
            break;
        case NSTYPE_VT:
            break;
        }
        line = buffer_append(line, 0);
    }
    svc->line_out(svc, sel, line->data, line->size);
}

void _stdcall nsdef_line_out(nssvc_t *svc, x32_t sel, void *data, size_t size) {
    list_t *blk;
    while (blk = list_shift(&svc->pd_line_out)) {
        svc->bin_out(svc, sel, blk->data, blk->size);
        svc->bin_out(svc, sel, ";", 1);
        list_free(blk);
    }
    svc->bin_out(svc, sel, data, size);
    svc->bin_out(svc, sel, ";", 1);
}

void _stdcall nsdef_bin_out(nssvc_t *svc, x32_t sel, void *data, size_t size) {
    list_t *blk;
    while (blk = list_shift(&svc->pd_bin_out)) {
        svc->pkt_out(svc, sel, blk->data, blk->size);
        list_free(blk);
    }
    svc->pkt_out(svc, sel, data, size);
}

void _stdcall nsdef_pkt_out(nssvc_t *svc, x32_t sel, void *data, size_t size) {
    list_t *blk;
    while (blk = list_shift(&svc->pd_pkt_out)) {
        svc->drv->pkt_out(sel, blk->data, blk->size);
        list_free(blk);
    }
    svc->drv->pkt_out(sel, data, size);
}
