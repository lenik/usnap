Attribute VB_Name = "modLMCons"
Option Explicit

Public Const CNLEN       As Integer = 15                 ' Computer name length
Public Const LM20_CNLEN  As Integer = 15                 ' LM 2.0 Computer name length
Public Const DNLEN       As Integer = CNLEN              ' Maximum domain name length
Public Const LM20_DNLEN  As Integer = LM20_CNLEN         ' LM 2.0 Maximum domain name length

Public Const UNCLEN      As Integer = (CNLEN + 2)        ' UNC computer name length
Public Const LM20_UNCLEN As Integer = (LM20_CNLEN + 2)   ' LM 2.0 UNC computer name length

Public Const NNLEN       As Integer = 80                 ' Net name length (share name)
Public Const LM20_NNLEN  As Integer = 12                 ' LM 2.0 Net name length

Public Const RMLEN       As Integer = (UNCLEN + 1 + NNLEN) ' Max remote name length
Public Const LM20_RMLEN  As Integer = (LM20_UNCLEN + 1 + LM20_NNLEN) ' LM 2.0 Max remote name length

Public Const SNLEN       As Integer = 80                 ' Service name length
Public Const LM20_SNLEN  As Integer = 15                 ' LM 2.0 Service name length
Public Const STXTLEN     As Integer = 256                ' Service text length
Public Const LM20_STXTLEN As Integer = 63                ' LM 2.0 Service text length

Public Const PATHLEN     As Integer = 256                ' Max. path (not including drive name)
Public Const LM20_PATHLEN As Integer = 256               ' LM 2.0 Max. path

Public Const DEVLEN      As Integer = 80                 ' Device name length
Public Const LM20_DEVLEN As Integer = 8                  ' LM 2.0 Device name length

Public Const EVLEN       As Integer = 16                 ' Event name length

'
' User, Group and Password lengths
'

Public Const UNLEN       As Integer = 256                ' Maximum user name length
Public Const LM20_UNLEN  As Integer = 20                 ' LM 2.0 Maximum user name length

Public Const GNLEN       As Integer = UNLEN              ' Group name
Public Const LM20_GNLEN  As Integer = LM20_UNLEN         ' LM 2.0 Group name

Public Const PWLEN       As Integer = 256                ' Maximum password length
Public Const LM20_PWLEN  As Integer = 14                 ' LM 2.0 Maximum password length

Public Const SHPWLEN     As Integer = 8                  ' Share password length (bytes)


Public Const CLTYPE_LEN  As Integer = 12                 ' Length of client type string


Public Const MAXCOMMENTSZ As Integer = 256               ' Multipurpose comment length
Public Const LM20_MAXCOMMENTSZ As Integer = 48           ' LM 2.0 Multipurpose comment length

Public Const QNLEN       As Integer = NNLEN              ' Queue name maximum length
Public Const LM20_QNLEN  As Integer = LM20_NNLEN         ' LM 2.0 Queue name maximum length

Public Const ALERTSZ     As Integer = 128                ' size of alert string in server
Public Const MAXDEVENTRIES As Integer = 32               ' Max number of device entries

                                        '
                                        ' We use int bitmap to represent
                                        '

Public Const NETBIOS_NAME_LEN  As Integer = 16           ' NetBIOS net name (bytes)

'
' Value to be used with APIs which have a "preferred maximum length"
' parameter.  This value indicates that the API should just allocate
' "as much as it takes."
'

Public Const MAX_PREFERRED_LENGTH    As Integer = -1

'
'        Constants used with encryption
'

Public Const CRYPT_KEY_LEN           As Integer = 7
Public Const CRYPT_TXT_LEN           As Integer = 8
Public Const ENCRYPTED_PWLEN         As Integer = 16
Public Const SESSION_PWLEN           As Integer = 24
Public Const SESSION_CRYPT_KLEN      As Integer = 21

Public Const PARM_ERROR_UNKNOWN      As Integer = -1
Public Const PARM_ERROR_NONE         As Integer = 0
Public Const PARMNUM_BASE_INFOLEVEL  As Integer = 1000


Public Const MESSAGE_FILENAME        As String = "NETMSG"
Public Const OS2MSG_FILENAME         As String = "BASE"
Public Const HELP_MSG_FILENAME       As String = "NETH"

Public Const BACKUP_MSG_FILENAME     As String = "BAK.MSG"

Public Const PLATFORM_ID_DOS As Integer = 300
Public Const PLATFORM_ID_OS2 As Integer = 400
Public Const PLATFORM_ID_NT  As Integer = 500
Public Const PLATFORM_ID_OSF As Integer = 600
Public Const PLATFORM_ID_VMS As Integer = 700

'
'      There message numbers assigned to different LANMAN components
'      are as defined below.
'
'      lmerr.h:        2100 - 2999     NERR_BASE
'      alertmsg.h:     3000 - 3049     ALERT_BASE
'      lmsvc.h:        3050 - 3099     SERVICE_BASE
'      lmerrlog.h:     3100 - 3299     ERRLOG_BASE
'      msgtext.h:      3300 - 3499     MTXT_BASE
'      apperr.h:       3500 - 3999     APPERR_BASE
'      apperrfs.h:     4000 - 4299     APPERRFS_BASE
'      apperr2.h:      4300 - 5299     APPERR2_BASE
'      ncberr.h:       5300 - 5499     NRCERR_BASE
'      alertmsg.h:     5500 - 5599     ALERT2_BASE
'      lmsvc.h:        5600 - 5699     SERVICE2_BASE
'      lmerrlog.h      5700 - 5799     ERRLOG2_BASE
'

Public Const NERR_BASE = 2100

Public Const MIN_LANMAN_MESSAGE_ID  As Integer = NERR_BASE
Public Const MAX_LANMAN_MESSAGE_ID  As Integer = 5799
