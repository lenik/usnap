
/* modfs - File System */

/* .section.  mod def */

u32_t _stdcall modfs_pwd(nssvc_t *svc, x32_t *args, int nopts) {
    char pwd[_MAX_PATH];
    getpwd(pwd);
    return nserr(NSERR_OK, pwd);
}

u32_t _stdcall modfs_md(nssvc_t *svc, x32_t *args, int nopts) {
    const char *path = args[0].s;
    int makeparents = 0;
    if (nopts > 0)
        makeparents = args[1].i;
    if (mkdir(path) == 0)
        return NSERR_OK;
    if (makeparents) {
        char path[_MAX_PATH];
        /* ... */
        nsinfo(parent);
    }
    return nserr(NSERR_FAIL, errmsg);
}

u32_t _stdcall modfs_cd(nssvc_t *svc, x32_t *args, int nopts) {
    const char *path = (const char *)args[0].s;
    if (chdir(path) == 0)
        return NSERR_OK;
    return nserr(NSERR_FAIL, errmsg);
}

u32_t _stdcall modfs_ls(nssvc_t *svc, x32_t *args, int nopts) {
    const char *path = args[0].s;
    const char *opts = NULL;

    int fmt = 'S';                      /* Short, Long, Comma, Xml */
    int list = 'N';                     /* Normal, All */
    int sort = 'N';                     /* None, Size, Date, Name, eXt */

    if (nopts > 0)
        opts = args[1].s;
    if (opts) {
    }

    return nserr(NSERR_OK);
}

u32_t _stdcall modfs_mv(nssvc_t *svc, x32_t *args, int nopts) {
    const char *src = args[0].s;
    const char *dst = args[1].s;
    if (move(src, dst) == 0)
        return nserr(NSERR_OK);
    return nserr(NSERR_FAIL, errmsg);
}

u32_t _stdcall modfs_cp(nssvc_t *svc, x32_t *args, int nopts) {
    const char *src = args[0].s;
    const char *dst = args[1].s;
    int recursive = 0;
    if (nopts > 0)
        recursive = args[2].i;
    return nserr(NSERR_FAIL, errmsg);
}

u32_t _stdcall modfs_rm(nssvc_t *svc, x32_t *args, int nopts) {
    const char *path = args[0].s;
    int recursive = 0;
    if (nopts > 0)
        recursive = args[1].i;
    if (unlink(path) == 0)
        return nserr(NSERR_OK);
    return nserr(NSERR_FAIL, errmsg);
}

u32_t _stdcall modfs_get(nssvc_t *svc, x32_t *args, int nopts) {
    const char *path = args[0];
    /* XXX  64-bit */
    size_t offset = 0;
    size_t size = -1;

    if (nopts > 0) {
        offset = (size_t)args[1].l;
        if (nopts > 1) {
            size = (size_t)args[2].l;
        }
    }

    return nserr(NSERR_NEXT);
}

u32_t _stdcall modfs_get_next(nssvc_t *svc, x32_t *args, int nopts) {
}

u32_t _stdcall modfs_get_end(nssvc_t *svc, x32_t *args, int nopts) {
}

u32_t _stdcall modfs_put(nssvc_t *svc, x32_t *args, int nopts) {
    const char *path = args[0];
    /* XXX  64-bit */
    size_t offset = 0;
    size_t size = -1;

    if (nopts > 0) {
        offset = (size_t)args[1].l;
        if (nopts > 1) {
            size = (size_t)args[2].l;
        }
    }

    return nserr(NSERR_NEXT);
}

u32_t _stdcall modfs_put_chunk(nssvc_t *svc, x32_t *args, int nopts) {
    /* XXX  64-bit */
    size_t offset = last_offset;
    size_t size = -1;

    if (nopts > 0) {
        offset = (size_t)args[0].l;
        if (nopts > 1) {
            size = (size_t)args[1].l;
        }
    }
}

u32_t _stdcall modfs_put_end(nssvc_t *svc, x32_t *args, int nopts) {
}

u32_t _stdcall modfs_size(nssvc_t *svc, x32_t *args, int nopts) {
    const char *path = args[0].s;
    size_t newsize = (size_t)args[1].l;
    return NSERR_OK;
}

u32_t _stdcall modfs_crc(nssvc_t *svc, x32_t *args, int notps) {
    const char *path = args[0].s;
    return NSERR_OK;
}

u32_t _stdcall modfs_md5(nssvc_t *svc, x32_t *args, int notps) {
    const char *path = args[0].s;
    return NSERR_OK;
}

u32_t _stdcall modfs_sha1(nssvc_t *svc, x32_t *args, int notps) {
    const char *path = args[0].s;
    return NSERR_OK;
}

/* .section.  mod exports */

#define MODFS_VER "modfs $Revision: 1.3 $"
#define MODFS_HELP "modfs provides the functionalities to access the remote file system. "

enum MODFS_CMD {
    MODFS_PWD = 0,
    MODFS_CD,
    MODFS_MD,
    MODFS_RD,
    MODFS_LS,
    MODFS_MV,
    MODFS_CP,
    MODFS_RM,
    MODFS_GET,
    MODFS_PUT,
    MODFS_SIZE,
    MODFS_CRC,
    MODFS_MD5,
    MODFS_SHA1,
};

static nscmd_t modfs_cmds[] = {
    { "pwd", 0, modfs_pwd,              /* pwd() */
      NULL, 0, NULL, 0,
      NULL, 0,
      "pwd\n"
      "\t" "get the path of current working directory",
      MODFS_VER },

    { "cd", 0, modfs_cd,                /* cd([path]) */
      NULL, 0, { PARAMTYPE_STRING }, 1,
      NULL, 0,
      "cd <destination directory>\n"
      "\t" "change the current working directory",
      MODFS_VER },

    { "md", 0, modfs_md,                /* md(path, [make-parents]) */
      { PARAMTYPE_STRING }, 1, { PARAMTYPE_BOOL }, 1,
      NULL, 0,
      "md <new directory name> [<bool auto-create-parents>]\n"
      "\t" "make a new sub-directory in the current working directory",
      MODFS_VER },

    { "rd", 0, modfs_rd,                /* md(path) */
      { PARAMTYPE_STRING }, 1, NULL, 0,
      NULL, 0,
      "rd <directory name to remove>\n"
      "   remove the specified sub-directory in the current working directory",
      MODFS_VER },

    { "ls", 0, modfs_ls,                /* ls([path], [options]) */
      NULL, 0, { PARAMTYPE_STRING, PARAMTYPE_STRING }, 2,
      NULL, 0,
      "ls [<path> [-<options>]]\n"
      "\t" "list the directory content in the specified path\n"
      "options: \n"
      "\t" "l  long format\n"
      "\t" "c  separate by comma(,)\n"
      "\t" "n  sort by file name\n"
      "\t" "x  sort by extension name\n"
      "\t" "s  sort by size\n"
      "\t" "d  sort by datetime\n"
      "\t" "a  list all files (include hidden files)\n",
      MODFS_VER },

    { "mv", 0, modfs_mv,                /* mv(path1, path2) */
      { PARAMTYPE_STRING, PARAMTYPE_STRING }, 2, NULL, 0,
      NULL, 0,
      "mv <source> <destination>\n"
      "\t" "move or rename file specified by <source> to <destination>\n",
      MODFS_VER },

    { "cp", 0, modfs_cp,                /* cp(path1, path2, [recursive]) */
      { PARAMTYPE_STRING, PARAMTYPE_STRING }, 2, { PARAMTYPE_BOOL }, 1,
      NULL, 0,
      "cp <source> <destination> [<bool recursive>]\n"
      "\t" "copy file <source> to file <destination>\n",
      MODFS_VER },

    { "rm", 0, modfs_rm,                /* rm(path, [recursive]) */
      { PARAMTYPE_STRING }, 1, { PARAMTYPE_BOOL }, 1,
      NULL, 0,
      "rm <path> [<bool recursive>]\n"
      "\t" "remove the specified file\n",
      MODFS_VER },

    { "get", 0, modfs_get,              /* get(path, [offset], [size]) */
      { PARAMTYPE_STRING }, 1, { PARAMTYPE_LONG, PARAMTYPE_LONG }, 2,
      { get_next, get_end }, 2,
      "get <path> [<offset>] [<size>]\n"
      "\t" "get the file specified by path, begin at offset (default 0)."
      "\t" "if <size> is specified, only <size> bytes will be returned."
      "\t" "otherwise, all bytes after <offset> will be returned. \n",
      MODFS_VER },

    { "put", 0, modfs_put,              /* put(path, [offset], [size]) */
      { PARAMTYPE_STRING }, 1, { PARAMTYPE_LONG, PARAMTYPE_LONG }, 2,
      { put_chunk, put_end }, 2,
      "put <path> [<offset>] [<size>]\n"
      "\t" "put to the specified file, begin at offset (default 0)."
      "\t" "if <size> is specified, only <size> bytes will be written."
      "\t" "otherwise, all bytes after <offset> will be written. \n",
      MODFS_VER },

    { "size", 0, modfs_size,            /* size(path, [new-size]) */
      { PARAMTYPE_STRING }, 1, { PARAMTYPE_LONG }, 1,
      NULL, 0,
      "size <path> [<new-size>]\n"
      "\t" "get file size, and truncate to new-size if new-size is specified",
      MODFS_VER },

    { "crc", 0, modfs_crc,              /* crc(path) */
      { PARAMTYPE_STRING }, 1, NULL, 0,
      NULL, 0,
      "crc <path>\n"
      "\t" "calculate the CRC checksum of specified file",
      MODFS_VER },

    { "md5", 0, modfs_md5,
      { PARAMTYPE_STRING }, 1, NULL, 0,
      NULL, 0,
      "md5 <path>\n"
      "\t" "calculate the MD5 checksum of specified file",
      MODFS_VER },

    { "sha1", 0, modfs_sha1,
      { PARAMTYPE_STRING }, 1, NULL, 0,
      NULL, 0,
      "sha1 <path>\n"
      "\t" "calculate the SHA-1 checksum of specified file",
      MODFS_VER },
};

nsmod_t modfs = {
    "modfs",
    modfs_cmds,
    sizeof(modfs_cmds) / sizeof(modfs_cmds[0]),
    MODFS_HELP, MODFS_VER
};
