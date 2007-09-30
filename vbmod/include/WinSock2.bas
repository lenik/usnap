Attribute VB_Name = "modWinSock2"

'/* Socket function prototypes */

Declare Function sock_accept Lib "WS2_32" Alias "accept" (ByVal socket As Long, ByVal addrAddr As Long, addrAddrlen As Long) As Long
'typedef Socket (WSAAPI * LPFN_ACCEPT)(
'    SOCKET s,
'    struct sockaddr FAR * addr,
'    int FAR * addrlen
'    );

Declare Function sock_bind Lib "WS2_32" Alias "bind" (ByVal socket As Long, ByVal addrName As Long, ByVal namelen As Long) As Long
'typedef int (WSAAPI * LPFN_BIND)(
'    SOCKET s,
'    const struct sockaddr FAR * name,
'    int namelen
'    );

Declare Function sock_closesocket Lib "WS2_32" Alias "closesocket" (ByVal socket As Long) As Long
'typedef int (WSAAPI * LPFN_CLOSESOCKET)(
'    Socket s
'    );

Declare Function sock_connect Lib "WS2_32" Alias "connect" (ByVal socket As Long, ByVal addrName As Long, ByVal namelen As Long) As Long
'typedef int (WSAAPI * LPFN_CONNECT)(
'    SOCKET s,
'    const struct sockaddr FAR * name,
'    int namelen
'    );

Declare Function sock_ioctlsocket Lib "WS2_32" Alias "ioctlsocket" (ByVal socket As Long, ByVal cmd As Long, argp As Long) As Long
'typedef int (WSAAPI * LPFN_IOCTLSOCKET)(
'    SOCKET s,
'    long cmd,
'    u_long FAR * argp
'    );

Declare Function sock_getpeername Lib "WS2_32" Alias "getpeername" (ByVal socket As Long, ByVal addrName As Long, ByVal namelen As Long) As Long
'typedef int (WSAAPI * LPFN_GETPEERNAME)(
'    SOCKET s,
'    struct sockaddr FAR * name,
'    int FAR * namelen
'    );

Declare Function sock_getsockname Lib "WS2_32" Alias "getsockname" (ByVal socket As Long, ByVal addrName As Long, ByVal namelen As Long) As Long
'typedef int (WSAAPI * LPFN_GETSOCKNAME)(
'    SOCKET s,
'    struct sockaddr FAR * name,
'    int FAR * namelen
'    );

Declare Function sock_getsockopt Lib "WS2_32" Alias "getsockopt" (ByVal socket As Long, ByVal level As Long, ByVal optname As Long, optval As Byte, optlen As Long) As Long
'typedef int (WSAAPI * LPFN_GETSOCKOPT)(
'    SOCKET s,
'    int level,
'    int optname,
'    char FAR * optval,
'    int FAR * optlen
'    );

Declare Function sock_htonl Lib "WS2_32" Alias "htonl" (ByVal hostlong As Long) As Long
'typedef u_long (WSAAPI * LPFN_HTONL)(
'    u_long hostlong
'    );

Declare Function sock_htons Lib "WS2_32" Alias "htons" (ByVal hostshort As Integer) As Integer
'typedef u_short (WSAAPI * LPFN_HTONS)(
'    u_short hostshort
'    );

Declare Function sock_inet_addr Lib "WS2_32" Alias "inet_addr" (ByVal cp As String) As Long
'typedef unsigned long (WSAAPI * LPFN_INET_ADDR)(
'    const char FAR * cp
'    );

Declare Function sock_inet_ntoa Lib "WS2_32" Alias "inet_ntoa" (ByVal inaddr As Long) As Long
'typedef char FAR * (WSAAPI * LPFN_INET_NTOA)(
'    struct in_addr in
'    );

Declare Function sock_listen Lib "WS2_32" Alias "listen" (ByVal socket As Long, ByVal backlog As Long) As Long
'typedef int (WSAAPI * LPFN_LISTEN)(
'    SOCKET s,
'    int backlog
'    );

Declare Function sock_ntohl Lib "WS2_32" Alias "ntohl" (ByVal netlong As Long) As Long
'typedef u_long (WSAAPI * LPFN_NTOHL)(
'    u_long netlong
'    );
Declare Function sock_ntohs Lib "WS2_32" Alias "ntohs" (ByVal netshort As Integer) As Integer
'typedef u_short (WSAAPI * LPFN_NTOHS)(
'    u_short netshort
'    );
Declare Function sock_recv Lib "WS2_32" Alias "recv" (ByVal socket As Long, ByVal lpBuf As Long, ByVal buflen As Long, ByVal flags As Long) As Long
'typedef int (WSAAPI * LPFN_RECV)(
'    SOCKET s,
'    char FAR * buf,
'    int len,
'    int flags

Declare Function sock_recvfrom Lib "WS2_32" Alias "recvfrom" (ByVal socket As Long, ByVal lpBuf As Long, ByVal buflen As Long, ByVal flags As Long, ByVal addrFrom As Long, fromLen As Long) As Long
' typedef int (WSAAPI * LPFN_RECVFROM)(
'    SOCKET s,
'    char FAR * buf,
'    int len,
'    int flags,
'    struct sockaddr FAR * from,
'    int FAR * fromlen
'    );

Declare Function sock_select Lib "WS2_32" Alias "select" (ByVal nfds As Long, ByVal addr_readfds As Long, ByVal addr_writefds As Long, ByVal addr_exceptfds As Long, ByVal addr_timeout As Long) As Long
'typedef int (WSAAPI * LPFN_SELECT)(
'    int nfds,
'    fd_set FAR * readfds,
'    fd_set FAR * writefds,
'    fd_set FAR *exceptfds,
'    const struct timeval FAR * timeout
'    );

Declare Function sock_send Lib "WS2_32" Alias "send" (ByVal socket As Long, ByVal lpBuf As Long, ByVal buflen As Long, ByVal flags As Long) As Long
'typedef int (WSAAPI * LPFN_SEND)(
'    SOCKET s,
'    const char FAR * buf,
'    int len,
'    int flags
'    );

Declare Function sock_sendto Lib "WS2_32" Alias "sendto" (ByVal socket As Long, ByVal lpBuf As Long, ByVal buflen As Long, ByVal flags As Long, ByVal addrTo As Long, ByVal tolen As Long) As Long
'typedef int (WSAAPI * LPFN_SENDTO)(
'    SOCKET s,
'    const char FAR * buf,
'    int len,
'    int flags,
'    const struct sockaddr FAR * to,
'    int tolen
'    );

Declare Function sock_setsockopt Lib "WS2_32" Alias "setsockopt" (ByVal socket As Long, ByVal level As Long, ByVal optname As Long, ByVal optval As String, ByVal optlen As Long) As Long
'typedef int (WSAAPI * LPFN_SETSOCKOPT)(
'    SOCKET s,
'    int level,
'    int optname,
'    const char FAR * optval,
'    int optlen
'    );

Declare Function sock_shutdown Lib "WS2_32" Alias "shutdown" (ByVal socket As Long, ByVal how As Long) As Long
'typedef int (WSAAPI * LPFN_SHUTDOWN)(
'    SOCKET s,
'    int how
'    );

Declare Function sock_socket Lib "WS2_32" Alias "socket" (ByVal af As Long, ByVal socktype As Long, ByVal protocol As Long) As Long
'typedef socket (WSAAPI * LPFN_SOCKET)(
'    int af,
'    int type,
'    int protocol

'/* Database function prototypes */

Declare Function sock_gethostbyaddr Lib "WS2_32" Alias "gethostbyaddr" (ByVal addr As String, ByVal addrlen As Long, ByVal addrtype As Long) As Long
'typedef struct hostent FAR * (WSAAPI * LPFN_GETHOSTBYADDR)(
'    const char FAR * addr,
'    int len,
'    int type
'    );

Declare Function sock_gethostbyname Lib "WS2_32" Alias "gethostbyname" (ByVal name As String) As Long
'typedef struct hostent FAR * (WSAAPI * LPFN_GETHOSTBYNAME)(
'    const char FAR * name
'    );

Declare Function sock_gethostname Lib "WS2_32" Alias "gethostname" (ByVal name As String, ByVal namelen As Long) As Long
'typedef int (WSAAPI * LPFN_GETHOSTNAME)(
'    char FAR * name,
'    int namelen
'    );

Declare Function sock_getservbyport Lib "WS2_32" Alias "getservbyport" (ByVal port As Long, ByVal proto As String) As Long
'typedef struct servent FAR * (WSAAPI * LPFN_GETSERVBYPORT)(
'    int port,
'    const char FAR * proto
'    );

Declare Function sock_getservbyname Lib "WS2_32" Alias "getservbyname" (ByVal name As String, ByVal proto As String) As Long
'typedef struct servent FAR * (WSAAPI * LPFN_GETSERVBYNAME)(
'    const char FAR * name,
'    const char FAR * proto
'    );

Declare Function sock_getprotobynumber Lib "WS2_32" Alias "getprotobynumber" (ByVal number As Long) As Long
'typedef struct protoent FAR * (WSAAPI * LPFN_GETPROTOBYNUMBER)(
'    int number
'    );

Declare Function sock_getprotobyname Lib "WS2_32" Alias "getprotobyname" (ByVal name As String) As Long
'typedef struct protoent FAR * (WSAAPI * LPFN_GETPROTOBYNAME)(
'    const char FAR * name
'    );
