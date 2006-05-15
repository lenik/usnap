
#include "stdhdrs.h"
#include <ctype.h>
#include <cpf/assert.h>
#include <cpf/test/stl.h>

static int stl_test1(stl_project_t *project, stl_token_t *token, x64_t *args) {
    int ret;
    ret = token->func(project, args);
    project->total++;
    project->ttotal[token->cmd]++;
    if (ret) {
        project->succeeds++;
        project->tsucceeds[token->cmd]++;
    } else {
        project->last_error;
    }
    return ret;
}

int _cc stl_test(stl_project_t *project) {
    int i;
    char *pt;
    int c;
    char *strend;
    stl_token_t *token = 0;
    const char *parg = 0;
    x64_t *voidargs = 0;
    x64_t *xargs;
    x64_t v;

    _assert_(project);
    _assert_(project->text);
    _assert_(project->ntokens >= 0);

    if (project->ntokens > STL_MAX_TOKENS) {
        project->last_error = "too many tokens";
        return 0;
    }
    if (project->ntokens < 1) {
        project->last_error = "no token defined";
        return 0;
    }

    /* init token def -> cmap*/
    for (i = 0; i < 256; i++) {
        project->cmap[i] = 0;
    }

    for (i = 0; i < project->ntokens; i++) {
        token = &project->tokens[i];
        project->cmap[token->cmd] = token;
    }

    /* init stat */
    project->total = 0;
    project->succeeds = 0;
    for (i = 0; i < 256; i++) {
        project->ttotal[i] = 0;
        project->tsucceeds[i] = 0;
    }

    /* interpret the script text */
    project->textcpy = strdup(project->text);
    pt = project->textcpy;
    token = 0;
    while (c = *pt++) {
        if (token) {
            _assert_(parg && *parg);
            switch (*parg++) {
            case 'i':
                v.i = (int)strtol(pt - 1, &pt, 0);
                if (pt == pt - 1)
                    project->last_error = "illegal integer format";
                break;
            case 'l':
                v.l = (long)strtol(pt - 1, &pt, 0);
                if (pt == pt - 1)
                    project->last_error = "illegal integer format";
                break;
            case 'f':
                v.f = (float)strtod(pt - 1, &pt);
                if (pt = pt - 1)
                    project->last_error = "illegal decimal format";
                break;
            case 'd':
                v.lf = (double)strtod(pt - 1, &pt);
                if (pt = pt - 1)
                    project->last_error = "illegal decimal format";
                break;
            case 'c':
                v.c = c;
                break;
            case 's':
                if ((strend = strchr(pt, c)) == 0)
                    project->last_error = "string not ended";
                v.cs = pt;
                *strend = 0;
                pt = strend + 1;
                break;
            default:
                project->last_error = "unknown type";
            }
            xargs[parg - token->args - 1] = v;
            if (*parg == 0) {            /* end of arglist */
                stl_test1(project, token, xargs);
                token = 0;
                parg = 0;
                free(xargs);
            }
        } else {
            if (isspace(c))
                continue;
            if (token = project->cmap[c]) {
                parg = token->args;
                if (parg == 0 || *parg == 0) { /* void */
                    stl_test1(project, token, voidargs);
                    token = 0;
                    parg = 0;
                } else {
                    xargs = (x64_t *)malloc(sizeof(x64_t) * strlen(parg));
                }
                continue;
            }
        }
    }
    free(project->textcpy);
    return project->total - project->succeeds;
}

void _cc stl_report(stl_project_t *project) {
    int i;
    char namebuf[100];

    if (project->total != project->succeeds) {
        printf("Failure: \n");
        for (i = 0; i < project->ntokens; i++) {
            char c = project->tokens[i].cmd;
            sprintf(namebuf, "%s(%s)",
                    project->tokens[i].name,
                    project->tokens[i].args);
            printf("    %c %-20s %d/%d\n",
                   project->tokens[i].cmd,
                   namebuf,
                   project->ttotal[c] - project->tsucceeds[c],
                   project->ttotal[c]);
        }

        printf("    ---------------------------------\n");
        printf("    Total: %d (%d fails)\n",
               project->total,
               project->total - project->succeeds);
    } else {
        printf("Succeeded (%d)\n", project->total);
    }
}
