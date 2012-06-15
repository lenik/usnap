
#include "stdhdrs.h"
#include <cpf/assert.h>

#include "modfs_sh.h"

#define BLOCK_SIZE 4096

/* simple shell object */

shctx_t * _cc sh_new() {
    shctx_t *shctx = (shctx_t *)malloc(sizeof(shctx_t));
    getcwd(shctx->pwd, sizeof(shctx->pwd));
    return shctx;
}

void _cc sh_free(shctx_t *shctx) {
    _assert_(shctx);
    free(shctx);
}

int _cc sh_using(shctx_t *shctx) {
    _assert_(shctx);
    chdir(shctx->pwd);
    return 0;
}

int _cc sh_mkdir(shctx_t *shctx, const char *path, int mk_parents) {
    int ret;
    char *_path;
    char *token;
    const char *old_path;
    _assert_(shctx);
    _assert_(path);
    sh_using(shctx);
    if (mk_parents) {
        old_path = shctx->pwd;
        _path = strdup(path);
        _assert_(path);
        token = strtok(_path, "\\/");
        while (token) {
            ret = mkdir(token);
            if (ret != 0) {
                sprintf(shctx->last_error,
                        "cannot mkdir %s in %s",
                        token, shctx->pwd);
                ret = 10;
                break;
            }
            ret = sh_chdir(shctx, token);
            _assert_(ret == 0);
            token = strtok(0, "\\/");
        }
        free(_path);
        chdir(old_path);
        ret = 0;
    } else {
        ret = mkdir(path);
    }
    return ret;
}

int _cc sh_rmdir(shctx_t *shctx, const char *path, int recursive) {
    /* recursive isn't supported, yet*/
    int ret;
    _assert_(shctx);
    _assert_(path);
    sh_using(shctx);
    ret = rmdir(path);
    return ret;
}

int _cc sh_chdir(shctx_t *shctx, const char *path) {
    int ret;
    _assert_(shctx);
    _assert_(path);
    sh_using(shctx);
    ret = chdir(path);
    if (ret == 0)
        getcwd(shctx->pwd, sizeof(shctx->pwd));
    return ret;
}

int _cc sh_cp(shctx_t *shctx, const char *src_path, const char *dst_path) {
    int ret = 0;
    FILE *fd_src;
    FILE *fd_dst;
    u8_t buf[BLOCK_SIZE];
    size_t cb_read;
    size_t cb_write;
    int try_read = 0;
    int try_write = 0;
    size_t total_read = 0;
    size_t total_write = 0;
    _assert_(shctx);
    _assert_(path);

    sh_using(shctx);

    fd_src = fopen(src_path, "rb");
    if (fd_src == 0) {
        sprintf(shctx->last_error,
                "cannot open file %s for read", src_path);
        return 1;
    }
    fd_dst = fopen(dst_path, "wb");
    if (fd_dst == 0) {
        fclose(fd_src);
        sprintf(shctx->last_error,
                "cannot open file %s for write", dst_path);
        return 2;
    }

    for (;;) {
        cb_read = fread(buf, 1, BLOCK_SIZE, fd_src);
        total_read += cb_read;
        if (cb_read <= 0) {
            if (feof(fd_src))
                break;                  /* src ended */
            else {
                if (try_read++ < 3)
                    continue;           /* retry #3 */
                else {
                    ret = 10;
                    sprintf(shctx->last_error,
                            "try to read file %s error at %ld",
                            src_path, ftell(fd_src));
                    break;
                }
            }
        }
        try_read = 0;
        try_write = 0;
        do {
            if (try_write++ >= 3) {
                ret = 11;
                sprintf(shctx->last_error,
                        "try to write file %s error at %ld",
                        dst_path, ftell(fd_dst));
                break;
            }
            cb_write = fwrite(buf, 1, cb_read, fd_dst);
            total_write += cb_write;
            cb_read -= cb_write;
        } while (cb_read > 0);
    }
    fclose(fd_src);
    fclose(fd_dst);
    return 0;
}

int _cc sh_mv(shctx_t *shctx, const char *src_path, const char *dst_path) {
    int ret;
    _assert_(shctx);
    _assert_(path);
    sh_using(shctx);
    ret = rename(src_path, dst_path);
    return ret;
}

int _cc sh_rm(shctx_t *shctx, const char *path) {
    int ret;
    _assert_(shctx);
    _assert_(path);
    sh_using(shctx);
    ret = unlink(path);
    return ret;
}

int _cc sh_crc(shctx_t *shctx, const char *path, u8_t *buf) {
    _assert_(shctx);
    _assert_(buf);
    memset(buf, 0, 4);                  /* 32-bit */
    return 0;
}

int _cc sh_md5(shctx_t *shctx, const char *path, u8_t *buf) {
    _assert_(shctx);
    _assert_(buf);
    memset(buf, 0, 16);                 /* 128-bit */
    return 0;
}

int _cc sh_sha1(shctx_t *shctx, const char *path, u8_t *buf) {
    _assert_(shctx);
    _assert_(buf);
    memset(buf, 0, 20);                 /* 160-bit */
    return 0;
}

int _cc sh_exec(shctx_t *shctx, const char *cmdline) {
    int ret;
    _assert_(shctx);
    _assert_(cmdline);
    sh_using(shctx);
    ret = system(cmdline);
    return ret;
}
