
#include "stdhdrs.h"
#include <char.h>
#include <cpf/test/stl.h>

static int stl_test1(stl_project_t *project, stl_token_t *token, x64_t *args) {
    int ret;
    ret = token->func(args);
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

int stl_test(stl_project_t *project) {
    const char *pt;
    int c;
    const char *strend;
    stl_token_t *token;
    const char *arg = 0;
    x64_t *voidargs = 0;
    x64_t args[STL_MAX_ARGS];
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
    for (i = 0; i < 256; i++)
        project->cmap[i] = 0;

    for (i = 0; i < project->ntokens; i++) {
        token = &project->tokens[i];
        project->cmap[token->cmd] = token;
    }

    /* interpret the script text */
    project->textcpy = strdup(project->text);
    pt = project->textcpy;
    while (c = *pt++) {
        if (token) {
            _assert_(arg && *arg);
            switch (*arg++) {
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
            args[arg - token->args] = v;
            if (*arg == 0) {            /* end of arglist */
                stl_test1(project, token, args);
                token = 0;
                arg = 0;
            }
        } else {
            if (isspace(c))
                continue;
            if (token = project->cmap[c]) {
                arg = token->args;
                if (arg == 0 || *arg == 0) { /* void */
                    stl_test1(project, token, voidargs);
                    token = 0;
                    arg = 0;
                }
                continue;
            }
        }
    }
    free(project->textcpy);
    return project->total - project->succeeds;
}

void stl_report(stl_project_t *project) {
    int i;
    for (i = 0; i < project->ntokens; i++) {
        printf("Function %s (%c%s): %d (%d/%d)\n",
               project->tokens[i].name,
               project->tokens[i].cmd,
               project->tokens[i].args,
               project->ttotal[i],
               project->tsucceeds[i],
               project->ttotal[i] - project->tsucceeds[i]);
    }

    printf("---------------------------------\n");
    printf("Total: %d (%d/%d)\n",
           project->total,
           project->succeeds,
           project->total - project->succeeds);
}
