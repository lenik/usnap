Attribute VB_Name = "Constants"
Option Explicit


Public Const MTU_MAX                    As Long = 65535
Public Const MTU_HYPERCHANNEL           As Long = 65535
Public Const MTU_IBM_TOKEN_RING         As Long = 17914
Public Const MTU_IEEE_802_4             As Long = 8166
Public Const MTU_IEEE_802_5_MAX         As Long = 4464
Public Const MTU_FDDI                   As Long = 4352
Public Const MTU_WIDEBAND               As Long = 2048
Public Const MTU_EXP_ETH                As Long = 1536
Public Const MTU_ETH                    As Long = 1500
Public Const MTU_P2P                    As Long = 1500
Public Const MTU_IEEE_802_3             As Long = 1492
Public Const MTU_SLIP                   As Long = 1006
Public Const MTU_ARPANET                As Long = 1006
Public Const MTU_X25                    As Long = 576
Public Const MTU_DEC_IP_PORTAL          As Long = 512
Public Const MTU_NETBIOS                As Long = 508
Public Const MTU_IEEE_802_SRCRT_BRIDGE  As Long = 508
Public Const MTU_ARCNET                 As Long = 508
Public Const MTU_P2P_LOWDELAY           As Long = 296
Public Const MTU_MIN                    As Long = 68

' TCP/IP Packet Size
'
Public Const DEFAULT_PKTSIZE            As Long = (MTU_ETH - MTU_MIN - 50)

Public Const DEFAULT_PORT               As Long = 5103

Public Const FILEHASH_PREFIX            As String = "FiLeHaSHPReFiX"
Public Const FILEHASH_SUFFIX            As String = "fIlEhAshsUffIx"

' Base-64 Charset
' ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/
