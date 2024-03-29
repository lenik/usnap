' ------------------------------------------------------------------------
'
'    MAPI32.TXT -- MAPI32 API Declarations for Visual Basic
'
'              Copyright (C) 1994 Microsoft Corporation
'
'
'  This file contains only the Const, Type,
'  and Declare statements for  MAPI32 APIs.
'
'  You have a royalty-free right to use, modify, reproduce and distribute
'  this file (and/or any modified version) in any way you find useful,
'  provided that you agree that Microsoft has no warranty, obligation or
'  liability for its contents.
'
' ------------------------------------------------------------------------

'***************************************************
'   MAPI Message holds information about a message
'***************************************************

Type MAPIMessage
    Reserved As Long
    Subject As String
    NoteText As String
    MessageType As String
    DateReceived As String
    ConversationID As String
    Flags As Long
    RecipCount As Long
    FileCount As Long
End Type


'************************************************
'   MAPIRecip holds information about a message
'   originator or recipient
'************************************************

Type MapiRecip
    Reserved As Long
    RecipClass As Long
    Name As String
    Address As String
    EIDSize As Long
    EntryID As String
End Type


'******************************************************
'   MapiFile holds information about file attachments
'******************************************************

Type MapiFile
    Reserved As Long
    Flags As Long
    Position As Long
    PathName As String
    FileName As String
    FileType As String
End Type


'***************************
'   FUNCTION Declarations
'***************************

Declare Function MAPILogon Lib "MAPI32.DLL" (ByVal UIParam&, ByVal User$, ByVal Password$, ByVal Flags&, ByVal Reserved&, Session&) As Long
Declare Function MAPILogoff Lib "MAPI32.DLL" (ByVal Session&, ByVal UIParam&, ByVal Flags&, ByVal Reserved&) As Long
Declare Function BMAPIReadMail Lib "MAPI32.DLL" (lMsg&, nRecipients&, nFiles&, ByVal Session&, ByVal UIParam&, MessageID$, ByVal Flag&, ByVal Reserved&) As Long
Declare Function BMAPIGetReadMail Lib "MAPI32.DLL" (ByVal lMsg&, Message As MAPIMessage, Recip() As MapiRecip, File() As MapiFile, Originator As MapiRecip) As Long
Declare Function MAPIFindNext Lib "MAPI32.DLL" Alias "BMAPIFindNext" (ByVal Session&, ByVal UIParam&, MsgType$, SeedMsgID$, ByVal Flag&, ByVal Reserved&, MsgID$) As Long
Declare Function MAPISendDocuments Lib "MAPI32.DLL" (ByVal UIParam&, ByVal DelimStr$, ByVal FilePaths$, ByVal FileNames$, ByVal Reserved&) As Long
Declare Function MAPIDeleteMail Lib "MAPI32.DLL" (ByVal Session&, ByVal UIParam&, ByVal MsgID$, ByVal Flags&, ByVal Reserved&) As Long
Declare Function MAPISendMail Lib "MAPI32.DLL" Alias "BMAPISendMail" (ByVal Session&, ByVal UIParam&, Message As MAPIMessage, Recipient() As MapiRecip, File() As MapiFile, ByVal Flags&, ByVal Reserved&) As Long
Declare Function MAPISaveMail Lib "MAPI32.DLL" Alias "BMAPISaveMail" (ByVal Session&, ByVal UIParam&, Message As MAPIMessage, Recipient() As MapiRecip, File() As MapiFile, ByVal Flags&, ByVal Reserved&, MsgID$) As Long
Declare Function BMAPIAddress Lib "MAPI32.DLL" (lInfo&, ByVal Session&, ByVal UIParam&, Caption$, ByVal nEditFields&, Label$, nRecipients&, Recip() As MapiRecip, ByVal Flags&, ByVal Reserved&) As Long
Declare Function BMAPIGetAddress Lib "MAPI32.DLL" (ByVal lInfo&, ByVal nRecipients&, Recipients() As MapiRecip) As Long
Declare Function MAPIDetails Lib "MAPI32.DLL" Alias "BMAPIDetails" (ByVal Session&, ByVal UIParam&, Recipient As MapiRecip, ByVal Flags&, ByVal Reserved&) As Long
Declare Function MAPIResolveName Lib "MAPI32.DLL" Alias "BMAPIResolveName" (ByVal Session&, ByVal UIParam&, ByVal UserName$, ByVal Flags&, ByVal Reserved&, Recipient As MapiRecip) As Long



'**************************
'   CONSTANT Declarations
'**************************
'

Global Const SUCCESS_SUCCESS = 0
Global Const MAPI_USER_ABORT = 1
Global Const MAPI_E_USER_ABORT = MAPI_USER_ABORT
Global Const MAPI_E_FAILURE = 2
Global Const MAPI_E_LOGIN_FAILURE = 3
Global Const MAPI_E_LOGON_FAILURE = MAPI_E_LOGIN_FAILURE
Global Const MAPI_E_DISK_FULL = 4
Global Const MAPI_E_INSUFFICIENT_MEMORY = 5
Global Const MAPI_E_BLK_TOO_SMALL = 6
Global Const MAPI_E_TOO_MANY_SESSIONS = 8
Global Const MAPI_E_TOO_MANY_FILES = 9
Global Const MAPI_E_TOO_MANY_RECIPIENTS = 10
Global Const MAPI_E_ATTACHMENT_NOT_FOUND = 11
Global Const MAPI_E_ATTACHMENT_OPEN_FAILURE = 12
Global Const MAPI_E_ATTACHMENT_WRITE_FAILURE = 13
Global Const MAPI_E_UNKNOWN_RECIPIENT = 14
Global Const MAPI_E_BAD_RECIPTYPE = 15
Global Const MAPI_E_NO_MESSAGES = 16
Global Const MAPI_E_INVALID_MESSAGE = 17
Global Const MAPI_E_TEXT_TOO_LARGE = 18
Global Const MAPI_E_INVALID_SESSION = 19
Global Const MAPI_E_TYPE_NOT_SUPPORTED = 20
Global Const MAPI_E_AMBIGUOUS_RECIPIENT = 21
Global Const MAPI_E_AMBIG_RECIP = MAPI_E_AMBIGUOUS_RECIPIENT
Global Const MAPI_E_MESSAGE_IN_USE = 22
Global Const MAPI_E_NETWORK_FAILURE = 23
Global Const MAPI_E_INVALID_EDITFIELDS = 24
Global Const MAPI_E_INVALID_RECIPS = 25
Global Const MAPI_E_NOT_SUPPORTED = 26

Global Const MAPI_ORIG = 0
Global Const MAPI_TO = 1
Global Const MAPI_CC = 2
Global Const MAPI_BCC = 3


'***********************
'   FLAG Declarations
'***********************

'* MAPILogon() flags *

Global Const MAPI_LOGON_UI = &H1
Global Const MAPI_NEW_SESSION = &H2
Global Const MAPI_FORCE_DOWNLOAD = &H1000

'* MAPILogoff() flags *

Global Const MAPI_LOGOFF_SHARED = &H1
Global Const MAPI_LOGOFF_UI = &H2

'* MAPISendMail() flags *

Global Const MAPI_DIALOG = &H8

'* MAPIFindNext() flags *

Global Const MAPI_UNREAD_ONLY = &H20
Global Const MAPI_GUARANTEE_FIFO = &H100

'* MAPIReadMail() flags *

Global Const MAPI_ENVELOPE_ONLY = &H40
Global Const MAPI_PEEK = &H80
Global Const MAPI_BODY_AS_FILE = &H200
Global Const MAPI_SUPPRESS_ATTACH = &H800

'* MAPIDetails() flags *

Global Const MAPI_AB_NOMODIFY = &H400

'* Attachment flags *

Global Const MAPI_OLE = &H1
Global Const MAPI_OLE_STATIC = &H2

'* MapiMessage flags *

Global Const MAPI_UNREAD = &H1
Global Const MAPI_RECEIPT_REQUESTED = &H2
Global Const MAPI_SENT = &H4
