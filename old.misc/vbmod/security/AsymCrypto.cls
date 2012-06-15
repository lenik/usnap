VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "AsymCrypto"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const RSA_KEYSIZE               As Integer = 512

Private m_Seed As Long

Private m_EncRSA As New XceedEncryptionLib.XceedEncryption
Private m_RSA As New XceedEncryptionLib.XceedRSAEncryptionMethod

Private m_Base64 As New BinaryLib.Base64
Private m_PublicKey As String           ' Hex
Private m_PrivateKey As String          ' Hex

Public Sub GenerateKeys()
    m_Base64.SetStringB m_RSA.PublicKey
    m_PublicKey = m_Base64.GetBase64

    m_Base64.SetStringB m_RSA.PrivateKey
    m_PrivateKey = m_Base64.GetBase64
End Sub

Public Property Get PrivateKey() As String
    m_Base64.SetStringB m_RSA.PrivateKey
    PrivateKey = m_Base64.GetBase64
End Property

Public Property Let PrivateKey(ByVal newval As String)
    m_Base64.SetBase64 newval
    m_RSA.PrivateKey = m_Base64.GetStringB
End Property

Public Property Get PublicKey() As String
    m_Base64.SetStringB m_RSA.PublicKey
    PublicKey = m_Base64.GetBase64
End Property

Public Property Let PublicKey(ByVal newval As String)
    m_Base64.SetBase64 newval
    m_RSA.PublicKey = m_Base64.GetStringB
End Property

Public Function EncryptMessage(ByVal DecryptedMessage As String, _
                               Optional ByVal RawMode As Boolean = False) As String
    Dim Encrypted
    Dim Encrypted_base64 As String

    If Not RawMode Then DecryptedMessage = StringToBytes(DecryptedMessage)
    Encrypted = m_EncRSA.Encrypt(DecryptedMessage, True)

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
    Message = m_EncRSA.Decrypt(Encrypted, True)
    If Not RawMode Then Message = BytesToString(Message)

    DecryptMessage = Message
End Function

Public Function EncryptFile(ByVal DecryptedFile As String, _
                            ByVal EncryptedFile As String) As Long
    Dim cbBytes

    m_EncRSA.ProcessFile DecryptedFile, 0, 0, efpEncrypt, True, _
                         EncryptedFile, False, cbBytes

    EncryptedFile = cbBytes
End Function

Public Function DecryptFile(ByVal EncryptedFile As String, _
                            ByVal DecryptedFile As String) As Long
    Dim cbBytes

    m_EncRSA.ProcessFile EncryptedFile, 0, 0, efpDecrypt, True, _
                         DecryptedFile, False, cbBytes

    DecryptedFile = cbBytes
End Function

Public Function Slave_PrepareForRecvSecret() As String
    GenerateKeys
    Slave_PrepareForRecvSecret = Me.PublicKey
End Function

Public Function Master_SendSecret(ByVal Prepared As String, ByVal Secret As String) As String
    Dim Encrypted
    Dim Encrypted_base64
    Me.PublicKey = Prepared
    Master_SendSecret = EncryptMessage(Secret)
End Function

Public Function Slave_RecvSecret(ByVal EncryptedSecret As String) As String
    Slave_RecvSecret = DecryptMessage(EncryptedSecret)
End Function

Private Sub Class_Initialize()
    m_Seed = CLng(Rnd * &H7FFFFFFF)

    m_EncRSA.License LICENSE_XC_ENCRYPT
    m_RSA.SetRandomKeyPair RSA_KEYSIZE, m_Seed
    Set m_EncRSA.EncryptionMethod = m_RSA
End Sub
