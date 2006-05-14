
#include "stdhdrs.h"
#include <cpf/assert.h>

/**
 * TODO
 *   - built-in commands:
 *     .ver [<cmd-name>]
 *     .help [<cmd-name>]
 *     .osinfo (uname, uid/gid, netinfo, etc.)
 *
 *     .bind <application> [<port>]
 *     .connect <remote-ip:port> [<port>]
 *
 *     .pwd .cd .mkdir .rmdir
 *     .cp .mv .rm
 *     .ps .kill
 *
 *     .get "<path>" [<offset> [<size>]]
 *         recv: 200 { <chunk-base64> }
 *     .put "<path>" [<offset> [<size>]] { <chunk-base64> }
 *         recv: 200
 *     .resize "<path>" <new-size>
 *
 *   - command syntax
 *     char-escape:
 *       \x?? \u???? \n \t
 *       \h{XXYYZZ...}
 *
 *
 */
