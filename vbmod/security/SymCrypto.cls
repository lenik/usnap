VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "SymCrypto"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const AES_KEYSIZE               As Integer = 128

Private m_Seed As Long

Private m_Key As String                 ' Hex

Private m_EncAES As New XceedEncryptionLib.XceedEncryption
Private m_AES As New XceedEncryptionLib.XceedRijndaelEncryptionMethod

Private m_Base64 As New BinaryLib.Base64

Public Property Get Key() As String
    Key = m_Key
End Property

Public Property Let Key(ByVal newval As String)
    m_Key = newval
    m_AES.SetSecretKeyFromPassPhrase m_Key, AES_KEYSIZE
End Property

Public Function EncryptMessage(ByVal DecryptedMessage As String, _
                               Optional ByVal RawMode As Boolean = False) As String
    Dim Encrypted
    Dim Encrypted_base64 As String

    If Not RawMode Then DecryptedMessage = StringToBytes(DecryptedMessage)
    Encrypted = m_EncAES.Encrypt(DecryptedMessage, True)

    m_Base64.SetStringB Encrypted

    Encrypted_base64 = m_Base64.GetBase64
    EncryptMessage = Encrypted_base64
End Function

Public Function DecryptMessage(ByVal EncryptedMessage As String, _
                               Optional ByVal RawMode As Boolean = False) As String
    Dim Encrypted_base64 As String
    Dim Encrypted As String

    Encrypted_base64 = EncryptedMessage
    m_Base64.SetBase64 Encrypted_base64

    Encrypted = m_Base64.GetStringB

    Dim Message As String
    Message = m_EncAES.Decrypt(Encrypted, True)
    If Not RawMode Then Message = BytesToString(Message)

    DecryptMessage = Message
End Function

Public Function EncryptFile(ByVal DecryptedFile As String, _
                            ByVal EncryptedFile As String) As Long
    Dim cbBytes

    m_EncAES.ProcessFile DecryptedFile, 0, 0, efpEncrypt, True, _
                         EncryptedFile, False, cbBytes

    EncryptedFile = cbBytes
End Function

Public Function DecryptFile(ByVal EncryptedFile As String, _
                            ByVal DecryptedFile As String) As Long
    Dim cbBytes

    m_EncAES.ProcessFile EncryptedFile, 0, 0, efpDecrypt, True, _
                         DecryptedFile, False, cbBytes

    DecryptedFile = cbBytes
End Function

Private Sub Class_Initialize()
    m_Seed = CLng(Rnd * &H7FFFFFFF)

    m_EncAES.License LICENSE_XC_ENCRYPT
    Set m_AES.HashingMethod = New XceedEncryptionLib.XceedSHAHashingMethod
    ' m_AES.HashingMethod.HashSize = 128
    ' m_AES.EncryptionMode = emoChainedBlocks
    ' m_AES.PaddingMethod = epmFIPS81
    Set m_EncAES.EncryptionMethod = m_AES

    m_Key = Secret
    m_AES.SetSecretKeyFromPassPhrase m_Key, AES_KEYSIZE
End Sub
