#ifndef _modfs_sh_utim_dfn8s35qejER3425_
#define _modfs_sh_utim_dfn8s35qejER3425_ "$Header: /mnt/c/.radiko/.miaj/cvs/com/campofrontier/libns/inc/modfs_sh.h,v 1.1 2006-05-15 15:17:11 lenik Exp $"

#include <cpf/config.h>
#include <cpf/dt/raw.h>

typedef struct _shctx_t shctx_t;

struct _shctx_t {
    char pwd[256];
    char last_error[1024];
};

shctx_t * _cc sh_new();
void _cc sh_free(shctx_t *shctx);
int  _cc sh_using(shctx_t *shctx);
int  _cc sh_mkdir(shctx_t *shctx, const char *path, int mk_parents);
int  _cc sh_rmdir(shctx_t *shctx, const char *path, int recursive);
int  _cc sh_chdir(shctx_t *shctx, const char *path);
int  _cc sh_cp(shctx_t *shctx, const char *src_path, const char *dst_path);
int  _cc sh_mv(shctx_t *shctx, const char *src_path, const char *dst_path);
int  _cc sh_rm(shctx_t *shctx, const char *path);
int  _cc sh_crc(shctx_t *shctx, const char *path, u8_t *buf);
int  _cc sh_md5(shctx_t *shctx, const char *path, u8_t *buf);
int  _cc sh_sha1(shctx_t *shctx, const char *path, u8_t *buf);
int  _cc sh_exec(shctx_t *shctx, const char *cmdline);

#endif
