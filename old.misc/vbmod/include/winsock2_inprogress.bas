Attribute VB_Name = "modWinSock2_in_progress"

Public Const WINSOCK_VERSION = =&H202&

''
' * Commands for ioctlsocket(),  taken from the BSD file fcntl.h.
' *
' *
' * Ioctl 's have the command encoded in the lower word,
' * and the size of any in or out parameters in the upper
' * word.  The high 2 bits of the upper word are used
' * to encode the in/out status of the parameter; for now
' * we restrict parameters to at most 128 bytes.
'
Public Const IOCPARM_MASK = =&H7F              ' parameters must be < 128 bytes
Public Const IOC_VOID = =&H20000000            ' no parameters
Public Const IOC_OUT = =&H40000000             ' copy out parameters
Public Const IOC_IN = =&H80000000              ' copy in parameters
Public Const IOC_INOUT = IOC_IN Or IOC_OUT    ' =&H20000000 distinguishes new & old ioctl 's

'public const _IO(x,y)        (IOC_VOID|((x)<<8)|(y))

'public const _IOR(x,y,t)     (IOC_OUT|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))

'public const _IOW(x,y,t)     (IOC_IN|(((long)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))

'public const FIONREAD    _IOR('f', 127, u_long) ' get # bytes to read
'public const FIONBIO     _IOW('f', 126, u_long) ' set/clear non-blocking i/o
'public const FIOASYNC    _IOW('f', 125, u_long) ' set/clear async i/o

' Socket I/O Controls
'public const SIOCSHIWAT  _IOW('s',  0, u_long)  ' set high watermark
'public const SIOCGHIWAT  _IOR('s',  1, u_long)  ' get high watermark
'public const SIOCSLOWAT  _IOW('s',  2, u_long)  ' set low watermark
'public const SIOCGLOWAT  _IOR('s',  3, u_long)  ' get low watermark
'public const SIOCATMARK  _IOR('s',  7, u_long)  ' at oob mark?

'
' * Structures returned by network data base library, taken from the
' * BSD file netdb.h.  All addresses are supplied in host order, and
' * returned in network order (suitable for use in system calls).

Type hostent
        h_name As String                ' official name of host
        h_aliases_addr As Long          ' alias list
        h_addrtype As Integer           ' host address type
        h_length As Integer             ' length of address
        h_addr_list_addr As Long        ' list of addresses
End Type

'
' * It is assumed here that a network number
' * fits in 32 bits.
Type netent
        n_name As String                ' official name of net
        n_aliases_addr As Long          ' alias list
        n_addrtype As Integer           ' net address type
        n_net As Long                   ' network #
End Type

Type servent
        s_name As String                ' official service name
        s_aliases_addr As Long          ' alias list
        s_port As Integer               ' port #
        s_proto As String               ' protocal to use
End Type

Type protoent
        p_name As String                ' official protocol name
        p_aliases_addr As Long          ' aliases list
        p_proto As Integer              ' protocol #
End Type

'
' * Constants and structures defined by the internet system,
' * Per RFC 790, September 1981, taken from the BSD file netinet/in.h.

' * Protocols

Public Const IPPROTO_IP = 0                           ' dummy for IP
Public Const IPPROTO_ICMP = 1                         ' control message protocol
Public Const IPPROTO_IGMP = 2                         ' internet group management protocol
Public Const IPPROTO_GGP = 3                          ' gateway^2 (deprecated)
Public Const IPPROTO_TCP = 6                          ' tcp
Public Const IPPROTO_PUP = 12                         ' pup
Public Const IPPROTO_UDP = 17                         ' user datagram protocol
Public Const IPPROTO_IDP = 22                         ' xns idp
Public Const IPPROTO_ND = 77                          ' UNOFFICIAL net disk proto

Public Const IPPROTO_RAW = 255                        ' raw IP packet
Public Const IPPROTO_MAX = 256

'
' * Port/socket numbers: network standard functions

Public Const IPPORT_ECHO = 7
Public Const IPPORT_DISCARD = 9
Public Const IPPORT_SYSTAT = 11
Public Const IPPORT_DAYTIME = 13
Public Const IPPORT_NETSTAT = 15
Public Const IPPORT_FTP = 21
Public Const IPPORT_TELNET = 23
Public Const IPPORT_SMTP = 25
Public Const IPPORT_TIMESERVER = 37
Public Const IPPORT_NAMESERVER = 42
Public Const IPPORT_WHOIS = 43
Public Const IPPORT_MTP = 57

'
' * Port/socket numbers: host specific functions

Public Const IPPORT_TFTP = 69
Public Const IPPORT_RJE = 77
Public Const IPPORT_FINGER = 79
Public Const IPPORT_TTYLINK = 87
Public Const IPPORT_SUPDUP = 95

'
' * UNIX TCP sockets

Public Const IPPORT_EXECSERVER = 512
Public Const IPPORT_LOGINSERVER = 513
Public Const IPPORT_CMDSERVER = 514
Public Const IPPORT_EFSSERVER = 520

'
' * UNIX UDP sockets

Public Const IPPORT_BIFFUDP = 512
Public Const IPPORT_WHOSERVER = 513
Public Const IPPORT_ROUTESERVER = 520
                                        ' 520+1 also used

'
' * Ports < IPPORT_RESERVED are reserved for
' * privileged processes (e.g. root).

Public Const IPPORT_RESERVED = 1024

'
' * Link numbers

Public Const IMPLINK_IP = 155
Public Const IMPLINK_LOWEXPER = 156
Public Const IMPLINK_HIGHEXPER = 158

'
' * Internet address (old style... should be updated)

Type in_addr
        s_addr As Long
End Type

's_addr:  s_addr
                                ' can be used for most tcp & ip code
's_host:  s_addr & 0x00FF0000
                                ' host on imp
's_net:   s_addr & 0xFF000000
                                ' network
's_imp:   s_addr & 0x0000FFFF
                                ' imp
's_impno: s_addr & 0x000000FF
                                ' imp #
's_lh:    s_addr & 0x0000FF00
                                ' logical host

'
' * Definitions of bits in internet address integers.
' * On subnets, the decomposition of addresses to host and net parts
' * is done according to subnet mask, not the masks here.

'public const IN_CLASSA(i)            (((long)(i) & =&H80000000) = 0)
'public const IN_CLASSA_NET           =&Hff000000
'public const IN_CLASSA_NSHIFT        24
'public const IN_CLASSA_HOST          =&H00ffffff
'public const IN_CLASSA_MAX           128

'public const IN_CLASSB(i)            (((long)(i) & =&Hc0000000) = =&H80000000)
'public const IN_CLASSB_NET           =&Hffff0000
'public const IN_CLASSB_NSHIFT        16
'public const IN_CLASSB_HOST          =&H0000ffff
'public const IN_CLASSB_MAX           65536

'public const IN_CLASSC(i)            (((long)(i) & =&He0000000) = =&Hc0000000)
'public const IN_CLASSC_NET           =&Hffffff00
'public const IN_CLASSC_NSHIFT        8
'public const IN_CLASSC_HOST          =&H000000ff

'public const IN_CLASSD(i)            (((long)(i) & =&Hf0000000) = =&He0000000)
'public const IN_CLASSD_NET           =&Hf0000000       ' These ones aren't really
'public const IN_CLASSD_NSHIFT        28               ' net and host fields, but
'public const IN_CLASSD_HOST          =&H0fffffff       ' routing needn't know.
'public const IN_MULTICAST(i)         IN_CLASSD(i)

'public const INADDR_ANY              (u_long)=&H00000000
'public const INADDR_LOOPBACK         =&H7f000001
'public const INADDR_BROADCAST        (u_long)=&Hffffffff
'public const INADDR_NONE             =&Hffffffff

'public const ADDR_ANY                INADDR_ANY

'
' * Socket address, internet style.

Type sockaddr_in
        sin_family As Integer
        sin_port As Integer
        sin_addr As Long
        sin_zero(0 To 7) As Byte
End Type

Public Const WSADESCRIPTION_LEN = 256
Public Const WSASYS_STATUS_LEN = 128

Type WSAData
        wVersion As Integer
        wHighVersion As Integer
        szDescription(1 To WSADESCRIPTION_LEN + 1) As Byte
        szSystemStatus(1 To WSASYS_STATUS_LEN + 1) As Byte
        iMaxSockets As Integer
        iMaxUdpDg As Integer
        lpVenderInfo As Long
End Type

'
' * Definitions related to sockets: types, address families, options,
' * taken from the BSD file sys/socket.h.


'
' * This is used instead of -1, since the
' * LONG type is unsigned.

'
' * The  following  may  be used in place of the address family, socket type, or
' * protocol  in  a  call  to WSASocket to indicate that the corresponding value
' * should  be taken from the supplied WSAPROTOCOL_INFO structure instead of the
' * parameter itself.

Public Const FROM_PROTOCOL_INFO = (-1)

'
' * Types

Public Const SOCK_STREAM = 1                  ' stream socket
Public Const SOCK_DGRAM = 2                   ' datagram socket
Public Const SOCK_RAW = 3                     ' raw-protocol interface
Public Const SOCK_RDM = 4                     ' reliably-delivered message
Public Const SOCK_SEQPACKET = 5               ' sequenced packet stream

'
' * Option flags per-socket.

Public Const SO_DEBUG = =&H1                   ' turn on debugging info recording
Public Const SO_ACCEPTCONN = =&H2              ' socket has had listen()
Public Const SO_REUSEADDR = =&H4               ' allow local address reuse
Public Const SO_KEEPALIVE = =&H8               ' keep connections alive
Public Const SO_DONTROUTE = =&H10              ' just use interface addresses
Public Const SO_BROADCAST = =&H20              ' permit sending of broadcast msgs
Public Const SO_USELOOPBACK = =&H40            ' bypass hardware when possible
Public Const SO_LINGER = =&H80                 ' linger on close if data present
Public Const SO_OOBINLINE = =&H100             ' leave received OOB data in line

Public Const SO_DONTLINGER = Not SO_LINGER

'
' * Additional options.

Public Const SO_SNDBUF = =&H1001               ' send buffer size
Public Const SO_RCVBUF = =&H1002               ' receive buffer size
Public Const SO_SNDLOWAT = =&H1003             ' send low-water mark
Public Const SO_RCVLOWAT = =&H1004             ' receive low-water mark
Public Const SO_SNDTIMEO = =&H1005             ' send timeout
Public Const SO_RCVTIMEO = =&H1006             ' receive timeout
Public Const SO_ERROR = =&H1007                ' get error status and clear
Public Const SO_TYPE = =&H1008                 ' get socket type

'
' * WinSock 2 extension -- new options

Public Const SO_GROUP_ID = &H2001           ' ID of a socket group
Public Const SO_GROUP_PRIORITY = &H2002     ' the relative priority within a group
Public Const SO_MAX_MSG_SIZE = &H2003       ' maximum message size
Public Const SO_PROTOCOL_INFOA = &H2004     ' WSAPROTOCOL_INFOA structure
Public Const SO_PROTOCOL_INFOW = &H2005     ' WSAPROTOCOL_INFOW structure
Public Const SO_PROTOCOL_INFO = SO_PROTOCOL_INFOW
Public Const PVD_CONFIG = &H3001                ' configuration info for service provider

'
' * TCP options.

Public Const TCP_NODELAY = &H1

'
' * Address families.

Public Const AF_UNSPEC = 0                    ' unspecified
'
' * Although  AF_UNSPEC  is  defined for backwards compatibility, using
' * AF_UNSPEC for the "af" parameter when creating a socket is STRONGLY
' * DISCOURAGED.    The  interpretation  of  the  "protocol"  parameter
' * depends  on the actual address family chosen.  As environments grow
' * to  include  more  and  more  address families that use overlapping
' * protocol  values  there  is  more  and  more  chance of choosing an
' * undesired address family when AF_UNSPEC is used.

Public Const AF_UNIX = 1                      ' local to host (pipes, portals)
Public Const AF_INET = 2                      ' internetwork: UDP, TCP, etc.
Public Const AF_IMPLINK = 3                   ' arpanet imp addresses
Public Const AF_PUP = 4                       ' pup protocols: e.g. BSP
Public Const AF_CHAOS = 5                     ' mit CHAOS protocols
Public Const AF_NS = 6                        ' XEROX NS protocols
Public Const AF_IPX = AF_NS                   ' IPX protocols: IPX, SPX, etc.
Public Const AF_ISO = 7                       ' ISO protocols
Public Const AF_OSI = AF_ISO                  ' OSI is ISO
Public Const AF_ECMA = 8                      ' european computer manufacturers
Public Const AF_DATAKIT = 9                   ' datakit protocols
Public Const AF_CCITT = 10                    ' CCITT protocols, X.25 etc
Public Const AF_SNA = 11                      ' IBM SNA
Public Const AF_DECnet = 12                   ' DECnet
Public Const AF_DLI = 13                      ' Direct data link interface
Public Const AF_LAT = 14                      ' LAT
Public Const AF_HYLINK = 15                   ' NSC Hyperchannel
Public Const AF_APPLETALK = 16                ' AppleTalk
Public Const AF_NETBIOS = 17                  ' NetBios-style addresses
Public Const AF_VOICEVIEW = 18                ' VoiceView
Public Const AF_FIREFOX = 19                  ' Protocols from Firefox
Public Const AF_UNKNOWN1 = 20                 ' Somebody is using this!
Public Const AF_BAN = 21                      ' Banyan
Public Const AF_ATM = 22                      ' Native ATM Services
Public Const AF_INET6 = 23                    ' Internetwork Version 6
Public Const AF_CLUSTER = 24                  ' Microsoft Wolfpack
Public Const AF_12844 = 25                    ' IEEE 1284.4 WG AF


Public Const AF_MAX = 26

'
' * Structure used by kernel to store most
' * addresses.

Type sockaddr
        sa_family As Integer
        sa_data(1 To 14) As Byte
End Type

'
' * Structure used by kernel to pass protocol
' * information in raw sockets.

Type sockproto
        sp_family As Integer              ' address family
        sp_protocol As Integer            ' protocol
End Type

'
' * Protocol families, same as address families for now.

Public Const PF_UNSPEC = AF_UNSPEC
Public Const PF_UNIX = AF_UNIX
Public Const PF_INET = AF_INET
Public Const PF_IMPLINK = AF_IMPLINK
Public Const PF_PUP = AF_PUP
Public Const PF_CHAOS = AF_CHAOS
Public Const PF_NS = AF_NS
Public Const PF_IPX = AF_IPX
Public Const PF_ISO = AF_ISO
Public Const PF_OSI = AF_OSI
Public Const PF_ECMA = AF_ECMA
Public Const PF_DATAKIT = AF_DATAKIT
Public Const PF_CCITT = AF_CCITT
Public Const PF_SNA = AF_SNA
Public Const PF_DECnet = AF_DECnet
Public Const PF_DLI = AF_DLI
Public Const PF_LAT = AF_LAT
Public Const PF_HYLINK = AF_HYLINK
Public Const PF_APPLETALK = AF_APPLETALK
Public Const PF_VOICEVIEW = AF_VOICEVIEW
Public Const PF_FIREFOX = AF_FIREFOX
Public Const PF_UNKNOWN1 = AF_UNKNOWN1
Public Const PF_BAN = AF_BAN
Public Const PF_ATM = AF_ATM
Public Const PF_INET6 = AF_INET6

Public Const PF_MAX = AF_MAX

'
' * Structure used for manipulating linger option.

Type linger
        l_onoff As Integer                ' option on/off
        l_linger As Integer               ' linger time
End Type

'
' * Level number for (get/set)sockopt() to apply to socket itself.

Public Const SOL_LONG = &HFFFF              ' options for socket level

'
' * Maximum queue length specifiable by listen.

Public Const SOMAXCONN = &H7FFFFFFF

Public Const MSG_OOB = &H1                    ' process out-of-band data
Public Const MSG_PEEK = &H2                   ' peek at incoming message
Public Const MSG_DONTROUTE = &H4              ' send without using routing tables

Public Const MSG_PARTIAL = &H8000             ' partial send or recv for message xport

'
' * WinSock 2 extension -- new flags for WSASend(), WSASendTo(), WSARecv() and
' *                          WSARecvFrom()

Public Const MSG_INTERRUPT = &H10             ' send/recv in the interrupt context

Public Const MSG_MAXIOVLEN = 16

'
' * Define constant based on rfc883, used by gethostbyxxxx() calls.

Public Const MAXGETHOSTSTRUCT = 1024

'
' * WinSock 2 extension -- bit values and indices for FD_XXX network events

'public const FD_READ_BIT      0
'public const FD_READ          (1 << FD_READ_BIT)

'public const FD_WRITE_BIT     1
'public const FD_WRITE         (1 << FD_WRITE_BIT)

'public const FD_OOB_BIT       2
'public const FD_OOB           (1 << FD_OOB_BIT)

'public const FD_ACCEPT_BIT    3
'public const FD_ACCEPT        (1 << FD_ACCEPT_BIT)

'public const FD_CONNECT_BIT   4
'public const FD_CONNECT       (1 << FD_CONNECT_BIT)

'public const FD_CLOSE_BIT     5
'public const FD_CLOSE         (1 << FD_CLOSE_BIT)

'public const FD_QOS_BIT       6
'public const FD_QOS           (1 << FD_QOS_BIT)

'public const FD_GROUP_QOS_BIT 7
'public const FD_GROUP_QOS     (1 << FD_GROUP_QOS_BIT)

'public const FD_ROUTING_INTERFACE_CHANGE_BIT 8
'public const FD_ROUTING_INTERFACE_CHANGE     (1 << FD_ROUTING_INTERFACE_CHANGE_BIT)

'public const FD_ADDRESS_LIST_CHANGE_BIT 9
'public const FD_ADDRESS_LIST_CHANGE     (1 << FD_ADDRESS_LIST_CHANGE_BIT)

'public const FD_MAX_EVENTS    10
'public const FD_ALL_EVENTS    ((1 << FD_MAX_EVENTS) - 1)


'
' * All Windows Sockets error constants are biased by WSABASEERR from
' * the "normal"

Public Const WSABASEERR = 10000
'
' * Windows Sockets definitions of regular Microsoft C error constants

Public Const WSAEINTR = (WSABASEERR + 4)
Public Const WSAEBADF = (WSABASEERR + 9)
Public Const WSAEACCES = (WSABASEERR + 13)
Public Const WSAEFAULT = (WSABASEERR + 14)
Public Const WSAEINVAL = (WSABASEERR + 22)
Public Const WSAEMFILE = (WSABASEERR + 24)

'
' * Windows Sockets definitions of regular Berkeley error constants

Public Const WSAEWOULDBLOCK = (WSABASEERR + 35)
Public Const WSAEINPROGRESS = (WSABASEERR + 36)
Public Const WSAEALREADY = (WSABASEERR + 37)
Public Const WSAENOTSOCK = (WSABASEERR + 38)
Public Const WSAEDESTADDRREQ = (WSABASEERR + 39)
Public Const WSAEMSGSIZE = (WSABASEERR + 40)
Public Const WSAEPROTOTYPE = (WSABASEERR + 41)
Public Const WSAENOPROTOOPT = (WSABASEERR + 42)
Public Const WSAEPROTONOSUPPORT = (WSABASEERR + 43)
Public Const WSAESOCKTNOSUPPORT = (WSABASEERR + 44)
Public Const WSAEOPNOTSUPP = (WSABASEERR + 45)
Public Const WSAEPFNOSUPPORT = (WSABASEERR + 46)
Public Const WSAEAFNOSUPPORT = (WSABASEERR + 47)
Public Const WSAEADDRINUSE = (WSABASEERR + 48)
Public Const WSAEADDRNOTAVAIL = (WSABASEERR + 49)
Public Const WSAENETDOWN = (WSABASEERR + 50)
Public Const WSAENETUNREACH = (WSABASEERR + 51)
Public Const WSAENETRESET = (WSABASEERR + 52)
Public Const WSAECONNABORTED = (WSABASEERR + 53)
Public Const WSAECONNRESET = (WSABASEERR + 54)
Public Const WSAENOBUFS = (WSABASEERR + 55)
Public Const WSAEISCONN = (WSABASEERR + 56)
Public Const WSAENOTCONN = (WSABASEERR + 57)
Public Const WSAESHUTDOWN = (WSABASEERR + 58)
Public Const WSAETOOMANYREFS = (WSABASEERR + 59)
Public Const WSAETIMEDOUT = (WSABASEERR + 60)
Public Const WSAECONNREFUSED = (WSABASEERR + 61)
Public Const WSAELOOP = (WSABASEERR + 62)
Public Const WSAENAMETOOLONG = (WSABASEERR + 63)
Public Const WSAEHOSTDOWN = (WSABASEERR + 64)
Public Const WSAEHOSTUNREACH = (WSABASEERR + 65)
Public Const WSAENOTEMPTY = (WSABASEERR + 66)
Public Const WSAEPROCLIM = (WSABASEERR + 67)
Public Const WSAEUSERS = (WSABASEERR + 68)
Public Const WSAEDQUOT = (WSABASEERR + 69)
Public Const WSAESTALE = (WSABASEERR + 70)
Public Const WSAEREMOTE = (WSABASEERR + 71)

'
' * Extended Windows Sockets error constant definitions

Public Const WSASYSNOTREADY = (WSABASEERR + 91)
Public Const WSAVERNOTSUPPORTED = (WSABASEERR + 92)
Public Const WSANOTINITIALISED = (WSABASEERR + 93)
Public Const WSAEDISCON = (WSABASEERR + 101)
Public Const WSAENOMORE = (WSABASEERR + 102)
Public Const WSAECANCELLED = (WSABASEERR + 103)
Public Const WSAEINVALIDPROCTABLE = (WSABASEERR + 104)
Public Const WSAEINVALIDPROVIDER = (WSABASEERR + 105)
Public Const WSAEPROVIDERFAILEDINIT = (WSABASEERR + 106)
Public Const WSASYSCALLFAILURE = (WSABASEERR + 107)
Public Const WSASERVICE_NOT_FOUND = (WSABASEERR + 108)
Public Const WSATYPE_NOT_FOUND = (WSABASEERR + 109)
Public Const WSA_E_NO_MORE = (WSABASEERR + 110)
Public Const WSA_E_CANCELLED = (WSABASEERR + 111)
Public Const WSAEREFUSED = (WSABASEERR + 112)

'
' * Error return codes from gethostbyname() and gethostbyaddr()
' * (when using the resolver). Note that these errors are
' * retrieved via WSAGetLastError() and must therefore follow
' * the rules for avoiding clashes with error numbers from
' * specific implementations or language run-time systems.
' * For this reason the codes are based at WSABASEERR+1001.
' * Note also that [WSA]NO_ADDRESS is defined only for
' * compatibility purposes.


'public const h_errno         WSAGetLastError()

' Authoritative Answer: Host not found
Public Const WSAHOST_NOT_FOUND = (WSABASEERR + 1001)
Public Const HOST_NOT_FOUND = WSAHOST_NOT_FOUND

' Non-Authoritative: Host not found, or SERVERFAIL
Public Const WSATRY_AGAIN = (WSABASEERR + 1002)
Public Const TRY_AGAIN = WSATRY_AGAIN

' Non-recoverable errors, FORMERR, REFUSED, NOTIMP
Public Const WSANO_RECOVERY = (WSABASEERR + 1003)
Public Const NO_RECOVERY = WSANO_RECOVERY

' Valid name, no data record of requested type
Public Const WSANO_DATA = (WSABASEERR + 1004)
Public Const NO_DATA = WSANO_DATA

' no address, look for MX record
Public Const WSANO_ADDRESS = WSANO_DATA
Public Const NO_ADDRESS = WSANO_ADDRESS

'
' * Define QOS related error return codes
' *

Public Const WSA_QOS_RECEIVERS = (WSABASEERR + 1005)
' at least one Reserve has arrived
Public Const WSA_QOS_SENDERS = (WSABASEERR + 1006)
' at least one Path has arrived
Public Const WSA_QOS_NO_SENDERS = (WSABASEERR + 1007)
' there are no senders
Public Const WSA_QOS_NO_RECEIVERS = (WSABASEERR + 1008)
' there are no receivers
Public Const WSA_QOS_REQUEST_CONFIRMED = (WSABASEERR + 1009)
' Reserve has been confirmed
Public Const WSA_QOS_ADMISSION_FAILURE = (WSABASEERR + 1010)
' error due to lack of resources
Public Const WSA_QOS_POLICY_FAILURE = (WSABASEERR + 1011)
' rejected for administrative reasons - bad credentials
Public Const WSA_QOS_BAD_STYLE = (WSABASEERR + 1012)
' unknown or conflicting style
Public Const WSA_QOS_BAD_OBJECT = (WSABASEERR + 1013)
' problem with some part of the filterspec or providerspecific
' * buffer in general
Public Const WSA_QOS_TRAFFIC_CTRL_ERROR = (WSABASEERR + 1014)
' problem with some part of the flowspec
Public Const WSA_QOS_GENERIC_ERROR = (WSABASEERR + 1015)
' general error

'
' * Windows Sockets errors redefined as regular Berkeley error constants.
' * These are commented out in Windows NT to avoid conflicts with errno.h.
' * Use the WSA constants instead.

Public Const EWOULDBLOCK = WSAEWOULDBLOCK
Public Const EINPROGRESS = WSAEINPROGRESS
Public Const EALREADY = WSAEALREADY
Public Const ENOTSOCK = WSAENOTSOCK
Public Const EDESTADDRREQ = WSAEDESTADDRREQ
Public Const EMSGSIZE = WSAEMSGSIZE
Public Const EPROTOTYPE = WSAEPROTOTYPE
Public Const ENOPROTOOPT = WSAENOPROTOOPT
Public Const EPROTONOSUPPORT = WSAEPROTONOSUPPORT
Public Const ESOCKTNOSUPPORT = WSAESOCKTNOSUPPORT
Public Const EOPNOTSUPP = WSAEOPNOTSUPP
Public Const EPFNOSUPPORT = WSAEPFNOSUPPORT
Public Const EAFNOSUPPORT = WSAEAFNOSUPPORT
Public Const EADDRINUSE = WSAEADDRINUSE
Public Const EADDRNOTAVAIL = WSAEADDRNOTAVAIL
Public Const ENETDOWN = WSAENETDOWN
Public Const ENETUNREACH = WSAENETUNREACH
Public Const ENETRESET = WSAENETRESET
Public Const ECONNABORTED = WSAECONNABORTED
Public Const ECONNRESET = WSAECONNRESET
Public Const ENOBUFS = WSAENOBUFS
Public Const EISCONN = WSAEISCONN
Public Const ENOTCONN = WSAENOTCONN
Public Const ESHUTDOWN = WSAESHUTDOWN
Public Const ETOOMANYREFS = WSAETOOMANYREFS
Public Const ETIMEDOUT = WSAETIMEDOUT
Public Const ECONNREFUSED = WSAECONNREFUSED
Public Const ELOOP = WSAELOOP
Public Const ENAMETOOLONG = WSAENAMETOOLONG
Public Const EHOSTDOWN = WSAEHOSTDOWN
Public Const EHOSTUNREACH = WSAEHOSTUNREACH
Public Const ENOTEMPTY = WSAENOTEMPTY
Public Const EPROCLIM = WSAEPROCLIM
Public Const EUSERS = WSAEUSERS
Public Const EDQUOT = WSAEDQUOT
Public Const ESTALE = WSAESTALE
Public Const EREMOTE = WSAEREMOTE

'
' * WinSock 2 extension -- new error codes and type definition


public const WSAAPI                  FAR PASCAL
typedef DWORD                   WSAEVENT, FAR' * LPWSAEVENT;

type _WSAOVERLAPPED {
    DWORD    Internal;
    DWORD    InternalHigh;
    DWORD    Offset;
    DWORD    OffsetHigh;
    WSAEVENT hEvent;
} WSAOVERLAPPED, FAR' * LPWSAOVERLAPPED;

public const WSA_IO_PENDING          (WSAEWOULDBLOCK)
public const WSA_IO_INCOMPLETE       (WSAEWOULDBLOCK)
public const WSA_INVALID_HANDLE      (WSAENOTSOCK)
public const WSA_INVALID_PARAMETER   (WSAEINVAL)
public const WSA_NOT_ENOUGH_MEMORY   (WSAENOBUFS)
public const WSA_OPERATION_ABORTED   (WSAEINTR)

public const WSA_INVALID_EVENT       ((WSAEVENT)NULL)
public const WSA_MAXIMUM_WAIT_EVENTS (MAXIMUM_WAIT_OBJECTS)
public const WSA_WAIT_FAILED         ((DWORD)-1L)
public const WSA_WAIT_EVENT_0        ((DWORD)0)
public const WSA_WAIT_TIMEOUT        ((DWORD)=&H102L)
public const WSA_INFINITE            ((DWORD)-1L)

#End If ' WIN32

'
' * WinSock 2 extension -- WSABUF and QOS struct, include qos.h
' * to pull in FLOWSPEC and related definitions


type _WSABUF {
    u_long      len;     ' the length of the buffer
    char FAR ' *  buf;     ' the pointer to the buffer
} WSABUF, FAR' * LPWSABUF;

#include <qos.h>

type _QualityOfService
{
    FLOWSPEC      SendingFlowspec;       ' the flow spec for data sending
    FLOWSPEC      ReceivingFlowspec;     ' the flow spec for data receiving
    WSABUF        ProviderSpecific;      ' additional provider specific stuff
} QOS, FAR' * LPQOS;

'
' * WinSock 2 extension -- manifest constants for return values of the condition function

Public Const CF_ACCEPT = &H0
Public Const CF_REJECT = &H1
Public Const CF_DEFER = &H2

'
' * WinSock 2 extension -- manifest constants for shutdown()

Public Const SD_RECEIVE = &H0
Public Const SD_SEND = &H1
Public Const SD_BOTH = &H2

'
' * WinSock 2 extension -- data type and manifest constants for socket groups

typedef unsigned int             GROUP;

Public Const SG_UNCONSTRAINED_GROUP = &H1
Public Const SG_CONSTRAINED_GROUP = &H2

'
' * WinSock 2 extension -- data type for WSAEnumNetworkEvents()

type _WSANETWORKEVENTS {
       long lNetworkEvents;
       int iErrorCode[FD_MAX_EVENTS];
} WSANETWORKEVENTS, FAR' * LPWSANETWORKEVENTS;

'
' * WinSock 2 extension -- WSAPROTOCOL_INFO structure and associated
' * manifest constants


#ifndef GUID_DEFINED
public const GUID_DEFINED
type _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;
#End If ' GUID_DEFINED

#ifndef __LPGUID_DEFINED__
public const __LPGUID_DEFINED__
typedef Guid ' *LPGUID;
#End If

public const MAX_PROTOCOL_CHAIN 7

public const BASE_PROTOCOL      1
public const LAYERED_PROTOCOL   0

type _WSAPROTOCOLCHAIN {
    int ChainLen;                                 ' the length of the chain,
                                                  ' length = 0 means layered protocol,
                                                  ' length = 1 means base protocol,
                                                  ' length > 1 means protocol chain
    DWORD ChainEntries[MAX_PROTOCOL_CHAIN];       ' a list of dwCatalogEntryIds
} WSAPROTOCOLCHAIN, FAR' * LPWSAPROTOCOLCHAIN;

public const WSAPROTOCOL_LEN  255

type _WSAPROTOCOL_INFOA {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dwCatalogEntryId;
    WSAPROTOCOLCHAIN ProtocolChain;
    int iVersion;
    int iAddressFamily;
    int iMaxSockAddr;
    int iMinSockAddr;
    int iSocketType;
    int iProtocol;
    int iProtocolMaxOffset;
    int iNetworkByteOrder;
    int iSecurityScheme;
    DWORD dwMessageSize;
    DWORD dwProviderReserved;
    CHAR   szProtocol[WSAPROTOCOL_LEN+1];
} WSAPROTOCOL_INFOA, FAR' * LPWSAPROTOCOL_INFOA;
type _WSAPROTOCOL_INFOW {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dwCatalogEntryId;
    WSAPROTOCOLCHAIN ProtocolChain;
    int iVersion;
    int iAddressFamily;
    int iMaxSockAddr;
    int iMinSockAddr;
    int iSocketType;
    int iProtocol;
    int iProtocolMaxOffset;
    int iNetworkByteOrder;
    int iSecurityScheme;
    DWORD dwMessageSize;
    DWORD dwProviderReserved;
    WCHAR  szProtocol[WSAPROTOCOL_LEN+1];
} WSAPROTOCOL_INFOW, FAR' * LPWSAPROTOCOL_INFOW;
#ifdef UNICODE
typedef WSAPROTOCOL_INFOW WSAPROTOCOL_INFO;
typedef LPWSAPROTOCOL_INFOW LPWSAPROTOCOL_INFO;
#Else
typedef WSAPROTOCOL_INFOA WSAPROTOCOL_INFO;
typedef LPWSAPROTOCOL_INFOA LPWSAPROTOCOL_INFO;
#endif // UNICODE

' Flag bit definitions for dwProviderFlags
Public Const PFL_MULTIPLE_PROTO_ENTRIES = &H1
Public Const PFL_RECOMMENDED_PROTO_ENTRY = &H2
Public Const PFL_HIDDEN = &H4
Public Const PFL_MATCHES_PROTOCOL_ZERO = &H8

' Flag bit definitions for dwServiceFlags1
Public Const XP1_CONNECTIONLESS = &H1
Public Const XP1_GUARANTEED_DELIVERY = &H2
Public Const XP1_GUARANTEED_ORDER = &H4
Public Const XP1_MESSAGE_ORIENTED = &H8
Public Const XP1_PSEUDO_STREAM = &H10
Public Const XP1_GRACEFUL_CLOSE = &H20
Public Const XP1_EXPEDITED_DATA = &H40
Public Const XP1_CONNECT_DATA = &H80
Public Const XP1_DISCONNECT_DATA = &H100
Public Const XP1_SUPPORT_BROADCAST = &H200
Public Const XP1_SUPPORT_MULTIPOINT = &H400
Public Const XP1_MULTIPOINT_CONTROL_PLANE = &H800
Public Const XP1_MULTIPOINT_DATA_PLANE = &H1000
Public Const XP1_QOS_SUPPORTED = &H2000
Public Const XP1_INTERRUPT = &H4000
Public Const XP1_UNI_SEND = &H8000
Public Const XP1_UNI_RECV = &H10000
Public Const XP1_IFS_HANDLES = &H20000
Public Const XP1_PARTIAL_MESSAGE = &H40000

Public Const BIGENDIAN = &H0
Public Const LITTLEENDIAN = &H1

Public Const SECURITY_PROTOCOL_NONE = &H0

'
' * WinSock 2 extension -- manifest constants for WSAJoinLeaf()

Public Const JL_SENDER_ONLY = &H1
Public Const JL_RECEIVER_ONLY = &H2
Public Const JL_BOTH = &H4

'
' * WinSock 2 extension -- manifest constants for WSASocket()

Public Const WSA_FLAG_OVERLAPPED = &H1
Public Const WSA_FLAG_MULTIPOINT_C_ROOT = &H2
Public Const WSA_FLAG_MULTIPOINT_C_LEAF = &H4
Public Const WSA_FLAG_MULTIPOINT_D_ROOT = &H8
Public Const WSA_FLAG_MULTIPOINT_D_LEAF = &H10

'
' * WinSock 2 extension -- manifest constants for WSAIoctl()

Public Const IOC_UNIX = &H0
Public Const IOC_WS2 = &H8000000
Public Const IOC_PROTOCOL = &H10000000
Public Const IOC_VENDOR = &H18000000

public const _WSAIO(x,y)                   (IOC_VOID|(x)|(y))
public const _WSAIOR(x,y)                  (IOC_OUT|(x)|(y))
public const _WSAIOW(x,y)                  (IOC_IN|(x)|(y))
public const _WSAIORW(x,y)                 (IOC_INOUT|(x)|(y))

public const SIO_ASSOCIATE_HANDLE          _WSAIOW(IOC_WS2,1)
public const SIO_ENABLE_CIRCULAR_QUEUEING  _WSAIO(IOC_WS2,2)
public const SIO_FIND_ROUTE                _WSAIOR(IOC_WS2,3)
public const SIO_FLUSH                     _WSAIO(IOC_WS2,4)
public const SIO_GET_BROADCAST_ADDRESS     _WSAIOR(IOC_WS2,5)
public const SIO_GET_EXTENSION_FUNCTION_POINTER  _WSAIORW(IOC_WS2,6)
public const SIO_GET_QOS                   _WSAIORW(IOC_WS2,7)
public const SIO_GET_GROUP_QOS             _WSAIORW(IOC_WS2,8)
public const SIO_MULTIPOINT_LOOPBACK       _WSAIOW(IOC_WS2,9)
public const SIO_MULTICAST_SCOPE           _WSAIOW(IOC_WS2,10)
public const SIO_SET_QOS                   _WSAIOW(IOC_WS2,11)
public const SIO_SET_GROUP_QOS             _WSAIOW(IOC_WS2,12)
public const SIO_TRANSLATE_HANDLE          _WSAIORW(IOC_WS2,13)
public const SIO_ROUTING_INTERFACE_QUERY   _WSAIORW(IOC_WS2,20)
public const SIO_ROUTING_INTERFACE_CHANGE  _WSAIOW(IOC_WS2,21)
public const SIO_ADDRESS_LIST_QUERY        _WSAIOR(IOC_WS2,22)
public const SIO_ADDRESS_LIST_CHANGE       _WSAIO(IOC_WS2,23)
public const SIO_QUERY_TARGET_PNP_HANDLE   _WSAIOR(IOC_W32,24)

'
' * WinSock 2 extension -- manifest constants for SIO_TRANSLATE_HANDLE ioctl

Public Const TH_NETDEV = &H1
Public Const TH_TAPI = &H2


'
' * Microsoft Windows Extended data types required for the functions to
' * convert   back  and  forth  between  binary  and  string  forms  of
' * addresses.

type sockaddr SOCKADDR;
Type sockaddr ' *PSOCKADDR;
type sockaddr FAR' *LPSOCKADDR;

'
' * Manifest constants and type definitions related to name resolution and
' * registration (RNR) API


#ifndef _tagBLOB_DEFINED
public const _tagBLOB_DEFINED
public const _BLOB_DEFINED
public const _LPBLOB_DEFINED
type _BLOB {
    ULONG cbSize ;
#ifdef MIDL_PASS
    [size_is(cbSize)] BYTE' *pBlobData;
#Else  ' MIDL_PASS
    BYTE' *pBlobData ;
#End If ' MIDL_PASS
} BLOB,' *LPBLOB ;
#End If

'
' * Service Install Flags


public const SERVICE_MULTIPLE       (=&H00000001)

'
' *& Name Spaces


public const NS_ALL                      (0)

public const NS_SAP                      (1)
public const NS_NDS                      (2)
public const NS_PEER_BROWSE              (3)

public const NS_TCPIP_LOCAL              (10)
public const NS_TCPIP_HOSTS              (11)
public const NS_DNS                      (12)
public const NS_NETBT                    (13)
public const NS_WINS                     (14)

public const NS_NBP                      (20)

public const NS_MS                       (30)
public const NS_STDA                     (31)
public const NS_NTDS                     (32)

public const NS_X500                     (40)
public const NS_NIS                      (41)
public const NS_NISPLUS                  (42)

public const NS_WRQ                      (50)

'
' * Resolution flags for WSAGetAddressByName().
' * Note these are also used by the 1.1 API GetAddressByName, so
' * leave them around.

public const RES_UNUSED_1                (=&H00000001)
public const RES_FLUSH_CACHE             (=&H00000002)
#ifndef RES_SERVICE
public const RES_SERVICE                 (=&H00000004)
#End If ' RES_SERVICE

'
' * Well known value names for Service Types


public const SERVICE_TYPE_VALUE_IPXPORTA      "IpxSocket"
public const SERVICE_TYPE_VALUE_IPXPORTW     L"IpxSocket"
public const SERVICE_TYPE_VALUE_SAPIDA        "SapId"
public const SERVICE_TYPE_VALUE_SAPIDW       L"SapId"

public const SERVICE_TYPE_VALUE_TCPPORTA      "TcpPort"
public const SERVICE_TYPE_VALUE_TCPPORTW     L"TcpPort"

public const SERVICE_TYPE_VALUE_UDPPORTA      "UdpPort"
public const SERVICE_TYPE_VALUE_UDPPORTW     L"UdpPort"

public const SERVICE_TYPE_VALUE_OBJECTIDA     "ObjectId"
public const SERVICE_TYPE_VALUE_OBJECTIDW    L"ObjectId"

#ifdef UNICODE

public const SERVICE_TYPE_VALUE_SAPID        SERVICE_TYPE_VALUE_SAPIDW
public const SERVICE_TYPE_VALUE_TCPPORT      SERVICE_TYPE_VALUE_TCPPORTW
public const SERVICE_TYPE_VALUE_UDPPORT      SERVICE_TYPE_VALUE_UDPPORTW
public const SERVICE_TYPE_VALUE_OBJECTID     SERVICE_TYPE_VALUE_OBJECTIDW

#Else ' not UNICODE

public const SERVICE_TYPE_VALUE_SAPID        SERVICE_TYPE_VALUE_SAPIDA
public const SERVICE_TYPE_VALUE_TCPPORT      SERVICE_TYPE_VALUE_TCPPORTA
public const SERVICE_TYPE_VALUE_UDPPORT      SERVICE_TYPE_VALUE_UDPPORTA
public const SERVICE_TYPE_VALUE_OBJECTID     SERVICE_TYPE_VALUE_OBJECTIDA

#End If

#ifndef __CSADDR_DEFINED__
public const __CSADDR_DEFINED__


'
' * SockAddr Information

type _LONG_ADDRESS {
    LPSOCKADDR lpSockaddr ;
    INT iSockaddrLength ;
} LONG_ADDRESS,' *PSOCKET_ADDRESS, FAR' * LPSOCKET_ADDRESS ;

'
' * CSAddr Information

type _CSADDR_INFO {
    LONG_ADDRESS LocalAddr ;
    LONG_ADDRESS RemoteAddr ;
    INT iSocketType ;
    INT iProtocol ;
} CSADDR_INFO,' *PCSADDR_INFO, FAR' * LPCSADDR_INFO ;
#endif // __CSADDR_DEFINED__

'
' * Address list returned via SIO_ADDRESS_LIST_QUERY

type _LONG_ADDRESS_LIST {
    INT             iAddressCount;
    LONG_ADDRESS  Address[1];
} LONG_ADDRESS_LIST, FAR' * LPSOCKET_ADDRESS_LIST;

'
' *  Address Family/Protocol Tuples

type _AFPROTOCOLS {
    INT iAddressFamily;
    INT iProtocol;
} AFPROTOCOLS,' *PAFPROTOCOLS,' *LPAFPROTOCOLS;

'
' * Client Query API Typedefs


'
' * The comparators

typedef enum _WSAEcomparator
{
    COMP_EQUAL = 0,
    COMP_NOTLESS
} WSAECOMPARATOR,' *PWSAECOMPARATOR,' *LPWSAECOMPARATOR;

type _WSAVersion
{
    DWORD           dwVersion;
    WSAECOMPARATOR  ecHow;
}WSAVERSION,' *PWSAVERSION,' *LPWSAVERSION;

type _WSAQuerySetA
{
    DWORD           dwSize;
    LPSTR           lpszServiceInstanceName;
    LPGUID          lpServiceClassId;
    LPWSAVERSION    lpVersion;
    LPSTR           lpszComment;
    DWORD           dwNameSpace;
    LPGUID          lpNSProviderId;
    LPSTR           lpszContext;
    DWORD           dwNumberOfProtocols;
    LPAFPROTOCOLS   lpafpProtocols;
    LPSTR           lpszQueryString;
    DWORD           dwNumberOfCsAddrs;
    LPCSADDR_INFO   lpcsaBuffer;
    DWORD           dwOutputFlags;
    LPBLOB          lpBlob;
} WSAQUERYSETA,' *PWSAQUERYSETA,' *LPWSAQUERYSETA;
type _WSAQuerySetW
{
    DWORD           dwSize;
    LPWSTR          lpszServiceInstanceName;
    LPGUID          lpServiceClassId;
    LPWSAVERSION    lpVersion;
    LPWSTR          lpszComment;
    DWORD           dwNameSpace;
    LPGUID          lpNSProviderId;
    LPWSTR          lpszContext;
    DWORD           dwNumberOfProtocols;
    LPAFPROTOCOLS   lpafpProtocols;
    LPWSTR          lpszQueryString;
    DWORD           dwNumberOfCsAddrs;
    LPCSADDR_INFO   lpcsaBuffer;
    DWORD           dwOutputFlags;
    LPBLOB          lpBlob;
} WSAQUERYSETW,' *PWSAQUERYSETW,' *LPWSAQUERYSETW;
#ifdef UNICODE
typedef WSAQUERYSETW WSAQUERYSET;
typedef PWSAQUERYSETW PWSAQUERYSET;
typedef LPWSAQUERYSETW LPWSAQUERYSET;
#Else
typedef WSAQUERYSETA WSAQUERYSET;
typedef PWSAQUERYSETA PWSAQUERYSET;
typedef LPWSAQUERYSETA LPWSAQUERYSET;
#endif // UNICODE

Public Const LUP_DEEP = &H1
Public Const LUP_CONTAINERS = &H2
Public Const LUP_NOCONTAINERS = &H4
Public Const LUP_NEAREST = &H8
Public Const LUP_RETURN_NAME = &H10
Public Const LUP_RETURN_TYPE = &H20
Public Const LUP_RETURN_VERSION = &H40
Public Const LUP_RETURN_COMMENT = &H80
Public Const LUP_RETURN_ADDR = &H100
Public Const LUP_RETURN_BLOB = &H200
Public Const LUP_RETURN_ALIASES = &H400
Public Const LUP_RETURN_QUERY_STRING = &H800
Public Const LUP_RETURN_ALL = &HFF0
Public Const LUP_RES_SERVICE = &H8000

Public Const LUP_FLUSHCACHE = &H1000
Public Const LUP_FLUSHPREVIOUS = &H2000


//
// Return flags
//

Public Const RESULT_IS_ALIAS = &H1

'
' * Service Address Registration and Deregistration Data Types.


typedef enum _WSAESETSERVICEOP
{
    RNRSERVICE_REGISTER=0,
    RNRSERVICE_DEREGISTER,
    RNRSERVICE_DELETE
} WSAESETSERVICEOP,' *PWSAESETSERVICEOP,' *LPWSAESETSERVICEOP;

'
' * Service Installation/Removal Data Types.


type _WSANSClassInfoA
{
    LPSTR   lpszName;
    DWORD   dwNameSpace;
    DWORD   dwValueType;
    DWORD   dwValueSize;
    LPVOID  lpValue;
}WSANSCLASSINFOA,' *PWSANSCLASSINFOA,' *LPWSANSCLASSINFOA;
type _WSANSClassInfoW
{
    LPWSTR  lpszName;
    DWORD   dwNameSpace;
    DWORD   dwValueType;
    DWORD   dwValueSize;
    LPVOID  lpValue;
}WSANSCLASSINFOW,' *PWSANSCLASSINFOW,' *LPWSANSCLASSINFOW;
#ifdef UNICODE
typedef WSANSCLASSINFOW WSANSCLASSINFO;
typedef PWSANSCLASSINFOW PWSANSCLASSINFO;
typedef LPWSANSCLASSINFOW LPWSANSCLASSINFO;
#Else
typedef WSANSCLASSINFOA WSANSCLASSINFO;
typedef PWSANSCLASSINFOA PWSANSCLASSINFO;
typedef LPWSANSCLASSINFOA LPWSANSCLASSINFO;
#endif // UNICODE

type _WSAServiceClassInfoA
{
    LPGUID              lpServiceClassId;
    LPSTR               lpszServiceClassName;
    DWORD               dwCount;
    LPWSANSCLASSINFOA   lpClassInfos;
}WSASERVICECLASSINFOA,' *PWSASERVICECLASSINFOA,' *LPWSASERVICECLASSINFOA;
type _WSAServiceClassInfoW
{
    LPGUID              lpServiceClassId;
    LPWSTR              lpszServiceClassName;
    DWORD               dwCount;
    LPWSANSCLASSINFOW   lpClassInfos;
}WSASERVICECLASSINFOW,' *PWSASERVICECLASSINFOW,' *LPWSASERVICECLASSINFOW;
#ifdef UNICODE
typedef WSASERVICECLASSINFOW WSASERVICECLASSINFO;
typedef PWSASERVICECLASSINFOW PWSASERVICECLASSINFO;
typedef LPWSASERVICECLASSINFOW LPWSASERVICECLASSINFO;
#Else
typedef WSASERVICECLASSINFOA WSASERVICECLASSINFO;
typedef PWSASERVICECLASSINFOA PWSASERVICECLASSINFO;
typedef LPWSASERVICECLASSINFOA LPWSASERVICECLASSINFO;
#endif // UNICODE

type _WSANAMESPACE_INFOA {
    GUID                NSProviderId;
    DWORD               dwNameSpace;
    BOOL                fActive;
    DWORD               dwVersion;
    LPSTR               lpszIdentifier;
} WSANAMESPACE_INFOA,' *PWSANAMESPACE_INFOA,' *LPWSANAMESPACE_INFOA;
type _WSANAMESPACE_INFOW {
    GUID                NSProviderId;
    DWORD               dwNameSpace;
    BOOL                fActive;
    DWORD               dwVersion;
    LPWSTR              lpszIdentifier;
} WSANAMESPACE_INFOW,' *PWSANAMESPACE_INFOW,' *LPWSANAMESPACE_INFOW;
#ifdef UNICODE
typedef WSANAMESPACE_INFOW WSANAMESPACE_INFO;
typedef PWSANAMESPACE_INFOW PWSANAMESPACE_INFO;
typedef LPWSANAMESPACE_INFOW LPWSANAMESPACE_INFO;
#Else
typedef WSANAMESPACE_INFOA WSANAMESPACE_INFO;
typedef PWSANAMESPACE_INFOA PWSANAMESPACE_INFO;
typedef LPWSANAMESPACE_INFOA LPWSANAMESPACE_INFO;
#endif // UNICODE

' Socket function prototypes

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
LONG
WSAAPI
accept(
    LONG s,
    struct sockaddr FAR' * addr,
    int FAR' * addrlen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
LONG
(WSAAPI' * LPFN_ACCEPT)(
    LONG s,
    struct sockaddr FAR' * addr,
    int FAR' * addrlen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
bind(
    LONG s,
    const struct sockaddr FAR' * name,
    int namelen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_BIND)(
    LONG s,
    const struct sockaddr FAR' * name,
    int namelen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
closesocket(
    LONG s
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_CLOSESOCKET)(
    LONG s
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
connect(
    LONG s,
    const struct sockaddr FAR' * name,
    int namelen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_CONNECT)(
    LONG s,
    const struct sockaddr FAR' * name,
    int namelen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
ioctlsocket(
    LONG s,
    long cmd,
    u_long FAR ' * argp
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_IOCTLSOCKET)(
    LONG s,
    long cmd,
    u_long FAR ' * argp
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
getpeername(
    LONG s,
    struct sockaddr FAR' * name,
    int FAR' * namelen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_GETPEERNAME)(
    LONG s,
    struct sockaddr FAR' * name,
    int FAR' * namelen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
getsockname(
    LONG s,
    struct sockaddr FAR' * name,
    int FAR' * namelen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_GETSOCKNAME)(
    LONG s,
    struct sockaddr FAR' * name,
    int FAR' * namelen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
getsockopt(
    LONG s,
    int level,
    int optname,
    char FAR ' * optval,
    int FAR' * optlen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_GETSOCKOPT)(
    LONG s,
    int level,
    int optname,
    char FAR ' * optval,
    int FAR' * optlen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
u_long
WSAAPI
htonl(
    u_long hostlong
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
u_long
(WSAAPI' * LPFN_HTONL)(
    u_long hostlong
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
u_short
WSAAPI
htons(
    u_short hostshort
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
u_short
(WSAAPI' * LPFN_HTONS)(
    u_short hostshort
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
unsigned long
WSAAPI
inet_addr(
    const char FAR' * cp
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
unsigned long
(WSAAPI' * LPFN_INET_ADDR)(
    const char FAR' * cp
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
char FAR ' *
WSAAPI
inet_ntoa(
    struct in_addr in
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
char FAR ' *
(WSAAPI' * LPFN_INET_NTOA)(
    struct in_addr in
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
listen(
    LONG s,
    int backlog
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_LISTEN)(
    LONG s,
    int backlog
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
u_long
WSAAPI
ntohl(
    u_long netlong
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
u_long
(WSAAPI' * LPFN_NTOHL)(
    u_long netlong
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
u_short
WSAAPI
ntohs(
    u_short netshort
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
u_short
(WSAAPI' * LPFN_NTOHS)(
    u_short netshort
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
recv(
    LONG s,
    char FAR ' * buf,
    int len,
    int flags
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_RECV)(
    LONG s,
    char FAR ' * buf,
    int len,
    int flags
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
recvfrom(
    LONG s,
    char FAR ' * buf,
    int len,
    int flags,
    struct sockaddr FAR' * from,
    int FAR' * fromlen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_RECVFROM)(
    LONG s,
    char FAR ' * buf,
    int len,
    int flags,
    struct sockaddr FAR' * from,
    int FAR' * fromlen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
select(
    int nfds,
    fd_set FAR ' * readfds,
    fd_set FAR ' * writefds,
    fd_set FAR ' *exceptfds,
    const struct timeval FAR' * timeout
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_SELECT)(
    int nfds,
    fd_set FAR ' * readfds,
    fd_set FAR ' * writefds,
    fd_set FAR ' *exceptfds,
    const struct timeval FAR' * timeout
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
send(
    LONG s,
    const char FAR' * buf,
    int len,
    int flags
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_SEND)(
    LONG s,
    const char FAR' * buf,
    int len,
    int flags
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
sendto(
    LONG s,
    const char FAR' * buf,
    int len,
    int flags,
    const struct sockaddr FAR' * to,
    int tolen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_SENDTO)(
    LONG s,
    const char FAR' * buf,
    int len,
    int flags,
    const struct sockaddr FAR' * to,
    int tolen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
setsockopt(
    LONG s,
    int level,
    int optname,
    const char FAR' * optval,
    int optlen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_SETSOCKOPT)(
    LONG s,
    int level,
    int optname,
    const char FAR' * optval,
    int optlen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
shutdown(
    LONG s,
    int how
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_SHUTDOWN)(
    LONG s,
    int how
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
LONG
WSAAPI
socket(
    int af,
    int type,
    int protocol
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
LONG
(WSAAPI' * LPFN_LONG)(
    int af,
    int type,
    int protocol
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

' Database function prototypes

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
struct hostent FAR' *
WSAAPI
gethostbyaddr(
    const char FAR' * addr,
    int len,
    int type
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
struct hostent FAR' *
(WSAAPI' * LPFN_GETHOSTBYADDR)(
    const char FAR' * addr,
    int len,
    int type
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
struct hostent FAR' *
WSAAPI
gethostbyname(
    const char FAR' * name
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
struct hostent FAR' *
(WSAAPI' * LPFN_GETHOSTBYNAME)(
    const char FAR' * name
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
gethostname(
    char FAR ' * name,
    int namelen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_GETHOSTNAME)(
    char FAR ' * name,
    int namelen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
struct servent FAR' *
WSAAPI
getservbyport(
    int port,
    const char FAR' * proto
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
struct servent FAR' *
(WSAAPI' * LPFN_GETSERVBYPORT)(
    int port,
    const char FAR' * proto
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
struct servent FAR' *
WSAAPI
getservbyname(
    const char FAR' * name,
    const char FAR' * proto
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
struct servent FAR' *
(WSAAPI' * LPFN_GETSERVBYNAME)(
    const char FAR' * name,
    const char FAR' * proto
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
struct protoent FAR' *
WSAAPI
getprotobynumber(
    int number
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
struct protoent FAR' *
(WSAAPI' * LPFN_GETPROTOBYNUMBER)(
    int number
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
struct protoent FAR' *
WSAAPI
getprotobyname(
    const char FAR' * name
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
struct protoent FAR' *
(WSAAPI' * LPFN_GETPROTOBYNAME)(
    const char FAR' * name
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

' Microsoft Windows Extension function prototypes

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSAStartup(
    WORD wVersionRequested,
    lpWSAData lpWSAData
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSASTARTUP)(
    WORD wVersionRequested,
    lpWSAData lpWSAData
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSACleanup(
    void
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSACLEANUP)(
    void
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
void
WSAAPI
WSASetLastError(
    int iError
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
void
(WSAAPI' * LPFN_WSASETLASTERROR)(
    int iError
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSAGetLastError(
    void
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSAGETLASTERROR)(
    void
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
BOOL
WSAAPI
WSAIsBlocking(
    void
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
BOOL
(WSAAPI' * LPFN_WSAISBLOCKING)(
    void
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSAUnhookBlockingHook(
    void
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSAUNHOOKBLOCKINGHOOK)(
    void
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
FARPROC
WSAAPI
WSASetBlockingHook(
    FARPROC lpBlockFunc
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
FARPROC
(WSAAPI' * LPFN_WSASETBLOCKINGHOOK)(
    FARPROC lpBlockFunc
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSACancelBlockingCall(
    void
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSACANCELBLOCKINGCALL)(
    void
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
handle
WSAAPI
WSAAsyncGetServByName(
    HWND hWnd,
    u_int wMsg,
    const char FAR' * name,
    const char FAR' * proto,
    char FAR ' * buf,
    int buflen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
handle
(WSAAPI' * LPFN_WSAASYNCGETSERVBYNAME)(
    HWND hWnd,
    u_int wMsg,
    const char FAR' * name,
    const char FAR' * proto,
    char FAR ' * buf,
    int buflen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
handle
WSAAPI
WSAAsyncGetServByPort(
    HWND hWnd,
    u_int wMsg,
    int port,
    const char FAR' * proto,
    char FAR ' * buf,
    int buflen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
handle
(WSAAPI' * LPFN_WSAASYNCGETSERVBYPORT)(
    HWND hWnd,
    u_int wMsg,
    int port,
    const char FAR' * proto,
    char FAR ' * buf,
    int buflen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
handle
WSAAPI
WSAAsyncGetProtoByName(
    HWND hWnd,
    u_int wMsg,
    const char FAR' * name,
    char FAR ' * buf,
    int buflen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
handle
(WSAAPI' * LPFN_WSAASYNCGETPROTOBYNAME)(
    HWND hWnd,
    u_int wMsg,
    const char FAR' * name,
    char FAR ' * buf,
    int buflen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
handle
WSAAPI
WSAAsyncGetProtoByNumber(
    HWND hWnd,
    u_int wMsg,
    int number,
    char FAR ' * buf,
    int buflen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
handle
(WSAAPI' * LPFN_WSAASYNCGETPROTOBYNUMBER)(
    HWND hWnd,
    u_int wMsg,
    int number,
    char FAR ' * buf,
    int buflen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
handle
WSAAPI
WSAAsyncGetHostByName(
    HWND hWnd,
    u_int wMsg,
    const char FAR' * name,
    char FAR ' * buf,
    int buflen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
handle
(WSAAPI' * LPFN_WSAASYNCGETHOSTBYNAME)(
    HWND hWnd,
    u_int wMsg,
    const char FAR' * name,
    char FAR ' * buf,
    int buflen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
handle
WSAAPI
WSAAsyncGetHostByAddr(
    HWND hWnd,
    u_int wMsg,
    const char FAR' * addr,
    int len,
    int type,
    char FAR ' * buf,
    int buflen
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
handle
(WSAAPI' * LPFN_WSAASYNCGETHOSTBYADDR)(
    HWND hWnd,
    u_int wMsg,
    const char FAR' * addr,
    int len,
    int type,
    char FAR ' * buf,
    int buflen
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSACancelAsyncRequest(
    handle hAsyncTaskHandle
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSACANCELASYNCREQUEST)(
    handle hAsyncTaskHandle
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSAAsyncSelect(
    LONG s,
    HWND hWnd,
    u_int wMsg,
    long lEvent
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSAASYNCSELECT)(
    LONG s,
    HWND hWnd,
    u_int wMsg,
    long lEvent
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

'
' * WinSock 2 extensions -- data types for the condition function in
' * WSAAccept() and overlapped I/O completion routine.


typedef
int
(CALLBACK' * LPCONDITIONPROC)(
    LPWSABUF lpCallerId,
    LPWSABUF lpCallerData,
    LPQOS lpSQOS,
    LPQOS lpGQOS,
    LPWSABUF lpCalleeId,
    LPWSABUF lpCalleeData,
    Group FAR ' * g,
    DWORD dwCallbackData
    );

typedef
void
(CALLBACK' * LPWSAOVERLAPPED_COMPLETION_ROUTINE)(
    DWORD dwError,
    DWORD cbTransferred,
    LPWSAOVERLAPPED lpOverlapped,
    DWORD dwFlags
    );

' WinSock 2 API new function prototypes

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
LONG
WSAAPI
WSAAccept(
    LONG s,
    struct sockaddr FAR' * addr,
    LPINT addrlen,
    LPCONDITIONPROC lpfnCondition,
    DWORD dwCallbackData
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
LONG
(WSAAPI' * LPFN_WSAACCEPT)(
    LONG s,
    struct sockaddr FAR' * addr,
    LPINT addrlen,
    LPCONDITIONPROC lpfnCondition,
    DWORD dwCallbackData
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
BOOL
WSAAPI
WSACloseEvent(
    WSAEVENT hEvent
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
BOOL
(WSAAPI' * LPFN_WSACLOSEEVENT)(
    WSAEVENT hEvent
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSAConnect(
    LONG s,
    const struct sockaddr FAR' * name,
    int namelen,
    LPWSABUF lpCallerData,
    LPWSABUF lpCalleeData,
    LPQOS lpSQOS,
    LPQOS lpGQOS
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSACONNECT)(
    LONG s,
    const struct sockaddr FAR' * name,
    int namelen,
    LPWSABUF lpCallerData,
    LPWSABUF lpCalleeData,
    LPQOS lpSQOS,
    LPQOS lpGQOS
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
WSAEVENT
WSAAPI
WSACreateEvent(
    void
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
WSAEVENT
(WSAAPI' * LPFN_WSACREATEEVENT)(
    void
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSADuplicateSocketA(
    LONG s,
    DWORD dwProcessId,
    LPWSAPROTOCOL_INFOA lpProtocolInfo
    );
WINSOCK_API_LINKAGE
int
WSAAPI
WSADuplicateSocketW(
    LONG s,
    DWORD dwProcessId,
    LPWSAPROTOCOL_INFOW lpProtocolInfo
    );
#ifdef UNICODE
public const WSADuplicateSocket  WSADuplicateSocketW
#Else
public const WSADuplicateSocket  WSADuplicateSocketA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSADUPLICATESOCKETA)(
    LONG s,
    DWORD dwProcessId,
    LPWSAPROTOCOL_INFOA lpProtocolInfo
    );
typedef
int
(WSAAPI' * LPFN_WSADUPLICATESOCKETW)(
    LONG s,
    DWORD dwProcessId,
    LPWSAPROTOCOL_INFOW lpProtocolInfo
    );
#ifdef UNICODE
public const LPFN_WSADUPLICATESOCKET  LPFN_WSADUPLICATESOCKETW
#Else
public const LPFN_WSADUPLICATESOCKET  LPFN_WSADUPLICATESOCKETA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSAEnumNetworkEvents(
    LONG s,
    WSAEVENT hEventObject,
    LPWSANETWORKEVENTS lpNetworkEvents
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSAENUMNETWORKEVENTS)(
    LONG s,
    WSAEVENT hEventObject,
    LPWSANETWORKEVENTS lpNetworkEvents
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSAEnumProtocolsA(
    LPINT lpiProtocols,
    LPWSAPROTOCOL_INFOA lpProtocolBuffer,
    LPDWORD lpdwBufferLength
    );
WINSOCK_API_LINKAGE
int
WSAAPI
WSAEnumProtocolsW(
    LPINT lpiProtocols,
    LPWSAPROTOCOL_INFOW lpProtocolBuffer,
    LPDWORD lpdwBufferLength
    );
#ifdef UNICODE
public const WSAEnumProtocols  WSAEnumProtocolsW
#Else
public const WSAEnumProtocols  WSAEnumProtocolsA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSAENUMPROTOCOLSA)(
    LPINT lpiProtocols,
    LPWSAPROTOCOL_INFOA lpProtocolBuffer,
    LPDWORD lpdwBufferLength
    );
typedef
int
(WSAAPI' * LPFN_WSAENUMPROTOCOLSW)(
    LPINT lpiProtocols,
    LPWSAPROTOCOL_INFOW lpProtocolBuffer,
    LPDWORD lpdwBufferLength
    );
#ifdef UNICODE
public const LPFN_WSAENUMPROTOCOLS  LPFN_WSAENUMPROTOCOLSW
#Else
public const LPFN_WSAENUMPROTOCOLS  LPFN_WSAENUMPROTOCOLSA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSAEventSelect(
    LONG s,
    WSAEVENT hEventObject,
    long lNetworkEvents
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSAEVENTSELECT)(
    LONG s,
    WSAEVENT hEventObject,
    long lNetworkEvents
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
BOOL
WSAAPI
WSAGetOverlappedResult(
    LONG s,
    LPWSAOVERLAPPED lpOverlapped,
    LPDWORD lpcbTransfer,
    BOOL fWait,
    LPDWORD lpdwFlags
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
BOOL
(WSAAPI' * LPFN_WSAGETOVERLAPPEDRESULT)(
    LONG s,
    LPWSAOVERLAPPED lpOverlapped,
    LPDWORD lpcbTransfer,
    BOOL fWait,
    LPDWORD lpdwFlags
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
BOOL
WSAAPI
WSAGetQOSByName(
    LONG s,
    LPWSABUF lpQOSName,
    LPQOS LPQOS
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
BOOL
(WSAAPI' * LPFN_WSAGETQOSBYNAME)(
    LONG s,
    LPWSABUF lpQOSName,
    LPQOS LPQOS
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSAHtonl(
    LONG s,
    u_long hostlong,
    u_long FAR ' * lpnetlong
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSAHTONL)(
    LONG s,
    u_long hostlong,
    u_long FAR ' * lpnetlong
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSAHtons(
    LONG s,
    u_short hostshort,
    u_short FAR ' * lpnetshort
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSAHTONS)(
    LONG s,
    u_short hostshort,
    u_short FAR ' * lpnetshort
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSAIoctl(
    LONG s,
    DWORD dwIoControlCode,
    LPVOID lpvInBuffer,
    DWORD cbInBuffer,
    LPVOID lpvOutBuffer,
    DWORD cbOutBuffer,
    LPDWORD lpcbBytesReturned,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSAIOCTL)(
    LONG s,
    DWORD dwIoControlCode,
    LPVOID lpvInBuffer,
    DWORD cbInBuffer,
    LPVOID lpvOutBuffer,
    DWORD cbOutBuffer,
    LPDWORD lpcbBytesReturned,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
LONG
WSAAPI
WSAJoinLeaf(
    LONG s,
    const struct sockaddr FAR' * name,
    int namelen,
    LPWSABUF lpCallerData,
    LPWSABUF lpCalleeData,
    LPQOS lpSQOS,
    LPQOS lpGQOS,
    DWORD dwFlags
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
LONG
(WSAAPI' * LPFN_WSAJOINLEAF)(
    LONG s,
    const struct sockaddr FAR' * name,
    int namelen,
    LPWSABUF lpCallerData,
    LPWSABUF lpCalleeData,
    LPQOS lpSQOS,
    LPQOS lpGQOS,
    DWORD dwFlags
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSANtohl(
    LONG s,
    u_long netlong,
    u_long FAR ' * lphostlong
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSANTOHL)(
    LONG s,
    u_long netlong,
    u_long FAR ' * lphostlong
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSANtohs(
    LONG s,
    u_short netshort,
    u_short FAR ' * lphostshort
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSANTOHS)(
    LONG s,
    u_short netshort,
    u_short FAR ' * lphostshort
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSARecv(
    LONG s,
    LPWSABUF lpBuffers,
    DWORD dwBufferCount,
    LPDWORD lpNumberOfBytesRecvd,
    LPDWORD lpFlags,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSARECV)(
    LONG s,
    LPWSABUF lpBuffers,
    DWORD dwBufferCount,
    LPDWORD lpNumberOfBytesRecvd,
    LPDWORD lpFlags,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSARecvDisconnect(
    LONG s,
    LPWSABUF lpInboundDisconnectData
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSARECVDISCONNECT)(
    LONG s,
    LPWSABUF lpInboundDisconnectData
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSARecvFrom(
    LONG s,
    LPWSABUF lpBuffers,
    DWORD dwBufferCount,
    LPDWORD lpNumberOfBytesRecvd,
    LPDWORD lpFlags,
    struct sockaddr FAR' * lpFrom,
    LPINT lpFromlen,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSARECVFROM)(
    LONG s,
    LPWSABUF lpBuffers,
    DWORD dwBufferCount,
    LPDWORD lpNumberOfBytesRecvd,
    LPDWORD lpFlags,
    struct sockaddr FAR' * lpFrom,
    LPINT lpFromlen,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
BOOL
WSAAPI
WSAResetEvent(
    WSAEVENT hEvent
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
BOOL
(WSAAPI' * LPFN_WSARESETEVENT)(
    WSAEVENT hEvent
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSASend(
    LONG s,
    LPWSABUF lpBuffers,
    DWORD dwBufferCount,
    LPDWORD lpNumberOfBytesSent,
    DWORD dwFlags,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSASEND)(
    LONG s,
    LPWSABUF lpBuffers,
    DWORD dwBufferCount,
    LPDWORD lpNumberOfBytesSent,
    DWORD dwFlags,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSASendDisconnect(
    LONG s,
    LPWSABUF lpOutboundDisconnectData
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSASENDDISCONNECT)(
    LONG s,
    LPWSABUF lpOutboundDisconnectData
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
int
WSAAPI
WSASendTo(
    LONG s,
    LPWSABUF lpBuffers,
    DWORD dwBufferCount,
    LPDWORD lpNumberOfBytesSent,
    DWORD dwFlags,
    const struct sockaddr FAR' * lpTo,
    int iTolen,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI' * LPFN_WSASENDTO)(
    LONG s,
    LPWSABUF lpBuffers,
    DWORD dwBufferCount,
    LPDWORD lpNumberOfBytesSent,
    DWORD dwFlags,
    const struct sockaddr FAR' * lpTo,
    int iTolen,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
BOOL
WSAAPI
WSASetEvent(
    WSAEVENT hEvent
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
BOOL
(WSAAPI' * LPFN_WSASETEVENT)(
    WSAEVENT hEvent
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
LONG
WSAAPI
WSASocketA(
    int af,
    int type,
    int protocol,
    LPWSAPROTOCOL_INFOA lpProtocolInfo,
    GROUP g,
    DWORD dwFlags
    );
WINSOCK_API_LINKAGE
LONG
WSAAPI
WSASocketW(
    int af,
    int type,
    int protocol,
    LPWSAPROTOCOL_INFOW lpProtocolInfo,
    GROUP g,
    DWORD dwFlags
    );
#ifdef UNICODE
public const WSASocket  WSASocketW
#Else
public const WSASocket  WSASocketA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
LONG
(WSAAPI' * LPFN_WSASOCKETA)(
    int af,
    int type,
    int protocol,
    LPWSAPROTOCOL_INFOA lpProtocolInfo,
    GROUP g,
    DWORD dwFlags
    );
typedef
LONG
(WSAAPI' * LPFN_WSASOCKETW)(
    int af,
    int type,
    int protocol,
    LPWSAPROTOCOL_INFOW lpProtocolInfo,
    GROUP g,
    DWORD dwFlags
    );
#ifdef UNICODE
public const LPFN_WSASOCKET  LPFN_WSASOCKETW
#Else
public const LPFN_WSASOCKET  LPFN_WSASOCKETA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
DWORD
WSAAPI
WSAWaitForMultipleEvents(
    DWORD cEvents,
    const WSAEVENT FAR' * lphEvents,
    BOOL fWaitAll,
    DWORD dwTimeout,
    BOOL fAlertable
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
DWORD
(WSAAPI' * LPFN_WSAWAITFORMULTIPLEEVENTS)(
    DWORD cEvents,
    const WSAEVENT FAR' * lphEvents,
    BOOL fWaitAll,
    DWORD dwTimeout,
    BOOL fAlertable
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
INT
WSAAPI
WSAAddressToStringA(
    IN     LPSOCKADDR          lpsaAddress,
    IN     DWORD               dwAddressLength,
    IN     LPWSAPROTOCOL_INFOA lpProtocolInfo,
    IN OUT LPSTR             lpszAddressString,
    IN OUT LPDWORD             lpdwAddressStringLength
    );
WINSOCK_API_LINKAGE
INT
WSAAPI
WSAAddressToStringW(
    IN     LPSOCKADDR          lpsaAddress,
    IN     DWORD               dwAddressLength,
    IN     LPWSAPROTOCOL_INFOW lpProtocolInfo,
    IN OUT LPWSTR             lpszAddressString,
    IN OUT LPDWORD             lpdwAddressStringLength
    );
#ifdef UNICODE
public const WSAAddressToString  WSAAddressToStringW
#Else
public const WSAAddressToString  WSAAddressToStringA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
INT
(WSAAPI' * LPFN_WSAADDRESSTOSTRINGA)(
    IN     LPSOCKADDR          lpsaAddress,
    IN     DWORD               dwAddressLength,
    IN     LPWSAPROTOCOL_INFOA lpProtocolInfo,
    IN OUT LPSTR             lpszAddressString,
    IN OUT LPDWORD             lpdwAddressStringLength
    );
typedef
INT
(WSAAPI' * LPFN_WSAADDRESSTOSTRINGW)(
    IN     LPSOCKADDR          lpsaAddress,
    IN     DWORD               dwAddressLength,
    IN     LPWSAPROTOCOL_INFOW lpProtocolInfo,
    IN OUT LPWSTR             lpszAddressString,
    IN OUT LPDWORD             lpdwAddressStringLength
    );
#ifdef UNICODE
public const LPFN_WSAADDRESSTOSTRING  LPFN_WSAADDRESSTOSTRINGW
#Else
public const LPFN_WSAADDRESSTOSTRING  LPFN_WSAADDRESSTOSTRINGA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
INT
WSAAPI
WSAStringToAddressA(
    IN     LPSTR             AddressString,
    IN     INT                 AddressFamily,
    IN     LPWSAPROTOCOL_INFOA lpProtocolInfo,
    IN OUT LPSOCKADDR          lpAddress,
    IN OUT LPINT               lpAddressLength
    );
WINSOCK_API_LINKAGE
INT
WSAAPI
WSAStringToAddressW(
    IN     LPWSTR             AddressString,
    IN     INT                 AddressFamily,
    IN     LPWSAPROTOCOL_INFOW lpProtocolInfo,
    IN OUT LPSOCKADDR          lpAddress,
    IN OUT LPINT               lpAddressLength
    );
#ifdef UNICODE
public const WSAStringToAddress  WSAStringToAddressW
#Else
public const WSAStringToAddress  WSAStringToAddressA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
INT
(WSAAPI' * LPFN_WSASTRINGTOADDRESSA)(
    IN     LPSTR             AddressString,
    IN     INT                 AddressFamily,
    IN     LPWSAPROTOCOL_INFOA lpProtocolInfo,
    IN OUT LPSOCKADDR          lpAddress,
    IN OUT LPINT               lpAddressLength
    );
typedef
INT
(WSAAPI' * LPFN_WSASTRINGTOADDRESSW)(
    IN     LPWSTR             AddressString,
    IN     INT                 AddressFamily,
    IN     LPWSAPROTOCOL_INFOW lpProtocolInfo,
    IN OUT LPSOCKADDR          lpAddress,
    IN OUT LPINT               lpAddressLength
    );
#ifdef UNICODE
public const LPFN_WSASTRINGTOADDRESS  LPFN_WSASTRINGTOADDRESSW
#Else
public const LPFN_WSASTRINGTOADDRESS  LPFN_WSASTRINGTOADDRESSA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_TYPEDEFS

' Registration and Name Resolution API functions


#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
INT
WSAAPI
WSALookupServiceBeginA(
    IN  LPWSAQUERYSETA lpqsRestrictions,
    IN  DWORD          dwControlFlags,
    OUT LPHANDLE       lphLookup
    );
WINSOCK_API_LINKAGE
INT
WSAAPI
WSALookupServiceBeginW(
    IN  LPWSAQUERYSETW lpqsRestrictions,
    IN  DWORD          dwControlFlags,
    OUT LPHANDLE       lphLookup
    );
#ifdef UNICODE
public const WSALookupServiceBegin  WSALookupServiceBeginW
#Else
public const WSALookupServiceBegin  WSALookupServiceBeginA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
INT
(WSAAPI' * LPFN_WSALOOKUPSERVICEBEGINA)(
    IN  LPWSAQUERYSETA lpqsRestrictions,
    IN  DWORD          dwControlFlags,
    OUT LPHANDLE       lphLookup
    );
typedef
INT
(WSAAPI' * LPFN_WSALOOKUPSERVICEBEGINW)(
    IN  LPWSAQUERYSETW lpqsRestrictions,
    IN  DWORD          dwControlFlags,
    OUT LPHANDLE       lphLookup
    );
#ifdef UNICODE
public const LPFN_WSALOOKUPSERVICEBEGIN  LPFN_WSALOOKUPSERVICEBEGINW
#Else
public const LPFN_WSALOOKUPSERVICEBEGIN  LPFN_WSALOOKUPSERVICEBEGINA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
INT
WSAAPI
WSALookupServiceNextA(
    IN     HANDLE           hLookup,
    IN     DWORD            dwControlFlags,
    IN OUT LPDWORD          lpdwBufferLength,
    OUT    LPWSAQUERYSETA   lpqsResults
    );
WINSOCK_API_LINKAGE
INT
WSAAPI
WSALookupServiceNextW(
    IN     HANDLE           hLookup,
    IN     DWORD            dwControlFlags,
    IN OUT LPDWORD          lpdwBufferLength,
    OUT    LPWSAQUERYSETW   lpqsResults
    );
#ifdef UNICODE
public const WSALookupServiceNext  WSALookupServiceNextW
#Else
public const WSALookupServiceNext  WSALookupServiceNextA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
INT
(WSAAPI' * LPFN_WSALOOKUPSERVICENEXTA)(
    IN     HANDLE           hLookup,
    IN     DWORD            dwControlFlags,
    IN OUT LPDWORD          lpdwBufferLength,
    OUT    LPWSAQUERYSETA   lpqsResults
    );
typedef
INT
(WSAAPI' * LPFN_WSALOOKUPSERVICENEXTW)(
    IN     HANDLE           hLookup,
    IN     DWORD            dwControlFlags,
    IN OUT LPDWORD          lpdwBufferLength,
    OUT    LPWSAQUERYSETW   lpqsResults
    );
#ifdef UNICODE
public const LPFN_WSALOOKUPSERVICENEXT  LPFN_WSALOOKUPSERVICENEXTW
#Else
public const LPFN_WSALOOKUPSERVICENEXT  LPFN_WSALOOKUPSERVICENEXTA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
INT
WSAAPI
WSALookupServiceEnd(
    IN HANDLE  hLookup
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
INT
(WSAAPI' * LPFN_WSALOOKUPSERVICEEND)(
    IN HANDLE  hLookup
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
INT
WSAAPI
WSAInstallServiceClassA(
    IN  LPWSASERVICECLASSINFOA   lpServiceClassInfo
    );
WINSOCK_API_LINKAGE
INT
WSAAPI
WSAInstallServiceClassW(
    IN  LPWSASERVICECLASSINFOW   lpServiceClassInfo
    );
#ifdef UNICODE
public const WSAInstallServiceClass  WSAInstallServiceClassW
#Else
public const WSAInstallServiceClass  WSAInstallServiceClassA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
INT
(WSAAPI' * LPFN_WSAINSTALLSERVICECLASSA)(
    IN  LPWSASERVICECLASSINFOA   lpServiceClassInfo
    );
typedef
INT
(WSAAPI' * LPFN_WSAINSTALLSERVICECLASSW)(
    IN  LPWSASERVICECLASSINFOW   lpServiceClassInfo
    );
#ifdef UNICODE
public const LPFN_WSAINSTALLSERVICECLASS  LPFN_WSAINSTALLSERVICECLASSW
#Else
public const LPFN_WSAINSTALLSERVICECLASS  LPFN_WSAINSTALLSERVICECLASSA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
INT
WSAAPI
WSARemoveServiceClass(
    IN  LPGUID  lpServiceClassId
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
INT
(WSAAPI' * LPFN_WSAREMOVESERVICECLASS)(
    IN  LPGUID  lpServiceClassId
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
INT
WSAAPI
WSAGetServiceClassInfoA(
    IN  LPGUID  lpProviderId,
    IN  LPGUID  lpServiceClassId,
    IN OUT LPDWORD  lpdwBufSize,
    OUT LPWSASERVICECLASSINFOA lpServiceClassInfo
    );
WINSOCK_API_LINKAGE
INT
WSAAPI
WSAGetServiceClassInfoW(
    IN  LPGUID  lpProviderId,
    IN  LPGUID  lpServiceClassId,
    IN OUT LPDWORD  lpdwBufSize,
    OUT LPWSASERVICECLASSINFOW lpServiceClassInfo
    );
#ifdef UNICODE
public const WSAGetServiceClassInfo  WSAGetServiceClassInfoW
#Else
public const WSAGetServiceClassInfo  WSAGetServiceClassInfoA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
INT
(WSAAPI' * LPFN_WSAGETSERVICECLASSINFOA)(
    IN  LPGUID  lpProviderId,
    IN  LPGUID  lpServiceClassId,
    IN OUT LPDWORD  lpdwBufSize,
    OUT LPWSASERVICECLASSINFOA lpServiceClassInfo
    );
typedef
INT
(WSAAPI' * LPFN_WSAGETSERVICECLASSINFOW)(
    IN  LPGUID  lpProviderId,
    IN  LPGUID  lpServiceClassId,
    IN OUT LPDWORD  lpdwBufSize,
    OUT LPWSASERVICECLASSINFOW lpServiceClassInfo
    );
#ifdef UNICODE
public const LPFN_WSAGETSERVICECLASSINFO  LPFN_WSAGETSERVICECLASSINFOW
#Else
public const LPFN_WSAGETSERVICECLASSINFO  LPFN_WSAGETSERVICECLASSINFOA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
INT
WSAAPI
WSAEnumNameSpaceProvidersA(
    IN OUT LPDWORD              lpdwBufferLength,
    IN     LPWSANAMESPACE_INFOA lpnspBuffer
    );
WINSOCK_API_LINKAGE
INT
WSAAPI
WSAEnumNameSpaceProvidersW(
    IN OUT LPDWORD              lpdwBufferLength,
    IN     LPWSANAMESPACE_INFOW lpnspBuffer
    );
#ifdef UNICODE
public const WSAEnumNameSpaceProviders  WSAEnumNameSpaceProvidersW
#Else
public const WSAEnumNameSpaceProviders  WSAEnumNameSpaceProvidersA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
INT
(WSAAPI' * LPFN_WSAENUMNAMESPACEPROVIDERSA)(
    IN OUT LPDWORD              lpdwBufferLength,
    IN     LPWSANAMESPACE_INFOA lpnspBuffer
    );
typedef
INT
(WSAAPI' * LPFN_WSAENUMNAMESPACEPROVIDERSW)(
    IN OUT LPDWORD              lpdwBufferLength,
    IN     LPWSANAMESPACE_INFOW lpnspBuffer
    );
#ifdef UNICODE
public const LPFN_WSAENUMNAMESPACEPROVIDERS  LPFN_WSAENUMNAMESPACEPROVIDERSW
#Else
public const LPFN_WSAENUMNAMESPACEPROVIDERS  LPFN_WSAENUMNAMESPACEPROVIDERSA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
INT
WSAAPI
WSAGetServiceClassNameByClassIdA(
    IN      LPGUID  lpServiceClassId,
    OUT     LPSTR lpszServiceClassName,
    IN OUT  LPDWORD lpdwBufferLength
    );
WINSOCK_API_LINKAGE
INT
WSAAPI
WSAGetServiceClassNameByClassIdW(
    IN      LPGUID  lpServiceClassId,
    OUT     LPWSTR lpszServiceClassName,
    IN OUT  LPDWORD lpdwBufferLength
    );
#ifdef UNICODE
public const WSAGetServiceClassNameByClassId  WSAGetServiceClassNameByClassIdW
#Else
public const WSAGetServiceClassNameByClassId  WSAGetServiceClassNameByClassIdA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
INT
(WSAAPI' * LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA)(
    IN      LPGUID  lpServiceClassId,
    OUT     LPSTR lpszServiceClassName,
    IN OUT  LPDWORD lpdwBufferLength
    );
typedef
INT
(WSAAPI' * LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW)(
    IN      LPGUID  lpServiceClassId,
    OUT     LPWSTR lpszServiceClassName,
    IN OUT  LPDWORD lpdwBufferLength
    );
#ifdef UNICODE
public const LPFN_WSAGETSERVICECLASSNAMEBYCLASSID  LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW
#Else
public const LPFN_WSAGETSERVICECLASSNAMEBYCLASSID  LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
INT
WSAAPI
WSASetServiceA(
    IN LPWSAQUERYSETA lpqsRegInfo,
    IN WSAESETSERVICEOP essoperation,
    IN DWORD dwControlFlags
    );
WINSOCK_API_LINKAGE
INT
WSAAPI
WSASetServiceW(
    IN LPWSAQUERYSETW lpqsRegInfo,
    IN WSAESETSERVICEOP essoperation,
    IN DWORD dwControlFlags
    );
#ifdef UNICODE
public const WSASetService  WSASetServiceW
#Else
public const WSASetService  WSASetServiceA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
INT
(WSAAPI' * LPFN_WSASETSERVICEA)(
    IN LPWSAQUERYSETA lpqsRegInfo,
    IN WSAESETSERVICEOP essoperation,
    IN DWORD dwControlFlags
    );
typedef
INT
(WSAAPI' * LPFN_WSASETSERVICEW)(
    IN LPWSAQUERYSETW lpqsRegInfo,
    IN WSAESETSERVICEOP essoperation,
    IN DWORD dwControlFlags
    );
#ifdef UNICODE
public const LPFN_WSASETSERVICE  LPFN_WSASETSERVICEW
#Else
public const LPFN_WSASETSERVICE  LPFN_WSASETSERVICEA
#endif // !UNICODE
#endif // INCL_WINSOCK_API_TYPEDEFS

#if INCL_WINSOCK_API_PROTOTYPES
WINSOCK_API_LINKAGE
INT
WSAAPI
WSAProviderConfigChange(
    IN OUT LPHANDLE lpNotificationHandle,
    IN LPWSAOVERLAPPED lpOverlapped,
    IN LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );
#endif // INCL_WINSOCK_API_PROTOTYPES

#if INCL_WINSOCK_API_TYPEDEFS
typedef
INT
(WSAAPI' * LPFN_WSAPROVIDERCONFIGCHANGE)(
    IN OUT LPHANDLE lpNotificationHandle,
    IN LPWSAOVERLAPPED lpOverlapped,
    IN LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );
#endif // INCL_WINSOCK_API_TYPEDEFS

' Microsoft Windows Extended data types
type sockaddr_in SOCKADDR_IN;
Type sockaddr_in ' *PSOCKADDR_IN;
type sockaddr_in FAR' *LPSOCKADDR_IN;

type linger LINGER;
Type linger ' *PLINGER;
type linger FAR' *LPLINGER;

type in_addr IN_ADDR;
Type in_addr ' *PIN_ADDR;
type in_addr FAR' *LPIN_ADDR;

type fd_set FD_SET;
Type fd_set ' *PFD_SET;
type fd_set FAR' *LPFD_SET;

type hostent HOSTENT;
Type hostent ' *PHOSTENT;
type hostent FAR' *LPHOSTENT;

type servent SERVENT;
Type servent ' *PSERVENT;
type servent FAR' *LPSERVENT;

type protoent PROTOENT;
Type protoent ' *PPROTOENT;
type protoent FAR' *LPPROTOENT;

type timeval TIMEVAL;
Type timeval ' *PTIMEVAL;
type timeval FAR' *LPTIMEVAL;

'
' * Windows message parameter composition and decomposition
' * macros.
' *
' * WSAMAKEASYNCREPLY is intended for use by the Windows Sockets implementation
' * when constructing the response to a WSAAsyncGetXByY() routine.

public const WSAMAKEASYNCREPLY(buflen,error)     MAKELONG(buflen,error)
'
' * WSAMAKESELECTREPLY is intended for use by the Windows Sockets implementation
' * when constructing the response to WSAAsyncSelect().

public const WSAMAKESELECTREPLY(event,error)     MAKELONG(event,error)
'
' * WSAGETASYNCBUFLEN is intended for use by the Windows Sockets application
' * to extract the buffer length from the lParam in the response
' * to a WSAAsyncGetXByY().

public const WSAGETASYNCBUFLEN(lParam)           LOWORD(lParam)
'
' * WSAGETASYNCERROR is intended for use by the Windows Sockets application
' * to extract the error code from the lParam in the response
' * to a WSAGetXByY().

public const WSAGETASYNCERROR(lParam)            HIWORD(lParam)
'
' * WSAGETSELECTEVENT is intended for use by the Windows Sockets application
' * to extract the event code from the lParam in the response
' * to a WSAAsyncSelect().

public const WSAGETSELECTEVENT(lParam)           LOWORD(lParam)
'
' * WSAGETSELECTERROR is intended for use by the Windows Sockets application
' * to extract the error code from the lParam in the response
' * to a WSAAsyncSelect().

public const WSAGETSELECTERROR(lParam)           HIWORD(lParam)

#ifdef __cplusplus
}
#End If

#include <poppack.h>

#End If ' _WINSOCK2API_
