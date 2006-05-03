
#define MODHACK_VER "modhack $Revision: 1.2 $"
#define MODHACK_HELP "modhack is designed for hacking purpose. "

enum MODHACK_CMD {
    MODHACK_PS,
    MODHACK_KILL,
    MODHACK_EXEC,
    MODHACK_SHELLCODE,
    MODHACK_PORTS,
    MODHACK_BIND,
    MODHACK_CONNECT,
    MODHACK_HIDE,
};

static nscmd_t *modhack_cmds = {
    { "ps", NSCMDF_HIDDEN, modhack_ps,  /* ps([options]) */
      NULL, 0, { NSTYPE_STRING }, 1,
      NULL, 0, 0,
      "ps [-<options>]\n"
      "\t" "show process info",
      MODHACK_VER },
};

nsmod_t modhack = {
    "modhack", NSMODF_HIDDEN, modhack_cmds,
    sizeof(modhack_cmds) / sizeof(modhack_cmds[0]),
    MODHACK_HELP, MODHACK_VER
};
