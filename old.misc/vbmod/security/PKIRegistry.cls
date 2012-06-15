VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "PKIRegistry"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

' PKIRegistry may be running on a safe host, later
' So the private keys should be safe thru remoting

Private m_Key As New AsymCrypto
Private m_Peerkey As New AsymCrypto

Private m_Registry As New VBExt.Map

Public Property Get ServerKey() As String
    ServerKey = m_Key.PublicKey
End Property

Public Property Let ClientKey(ByVal newval As String)
    m_Peerkey.PublicKey = newval
End Property

Public Property Get PublicKey(ByVal Id As String) As String
    If Not m_Registry.Contain(Id) Then Exit Property

    Dim e As PKIEntity
    Set e = m_Registry(Id)

    PublicKey = m_Peerkey.EncryptMessage(e.PublicKey)
End Property

Public Property Get PrivateKey(ByVal Id As String, ByVal Passphrase As String) As String
    If Not m_Registry.Contain(Id) Then Exit Property

    Dim e As PKIEntity
    Set e = m_Registry(Id)

    ' not used, yet
    Passphrase = m_Key.DecryptMessage(Passphrase)

    PrivateKey = m_Peerkey.EncryptMessage(e.PrivateKey)
End Property

Private Sub Class_Initialize()
    m_Key.GenerateKeys

    m_Registry("GENERAL") = CreatePKIEntity( _
        "MFowDQYJKoZIhvcNAQEBBQADSQAwRgJBALQD7zh2wdP2tGoNopjtuRqqiZdrZo+t3FdYAREovREk6kTq/7m7OIx2ALh0AKMGrF3ThIWq8drH0qbz4oUN38MCARE=", _
        "MIIBUwIBADANBgkqhkiG9w0BAQEFAASCAT0wggE5AgEAAkEAtAPvOHbB0/a0ag2imO25GqqJl2tmj63cV1gBESi9ESTqROr/ubs4jHYAuHQAowasXdOEharx2sfSpvPihQ3fwwIBEQJAFS2jrEo068Kr0D3W5NCsXX15mVft8sko+zeHp6pwmJq7nCCgBL1GNzBQnTMny3i6TdHcR95knY0VZqJAVqdYQQIhAMHTd6dJDSuVhs8H9KLBK9XHRz4SnckCoUxKz0xMtMXNAiEA7cJeCEhlOCHUhHhMi6BYpwEUdhAq0Zz3UHPBc1fKq88CIQC2bKzZriqDX43wB3zVaoOcBtmj1Uk1qB9W3P9W3shBsQIgG/i/xL05FamgiA4nH3xGqjxcwph9ghJ3cuBxHKDqqs0CIQCMCiiJKE48NNxS7IbROCpBNjGGgdSUyRzF7QiiHDE4Kw==")

    m_Registry("TEST") = CreatePKIEntity( _
        "MFowDQYJKoZIhvcNAQEBBQADSQAwRgJBALQD7zh2wdP2tGoNopjtuRqqiZdrZo+t3FdYAREovREk6kTq/7m7OIx2ALh0AKMGrF3ThIWq8drH0qbz4oUN38MCARE=", _
        "MIIBUwIBADANBgkqhkiG9w0BAQEFAASCAT0wggE5AgEAAkEAtAPvOHbB0/a0ag2imO25GqqJl2tmj63cV1gBESi9ESTqROr/ubs4jHYAuHQAowasXdOEharx2sfSpvPihQ3fwwIBEQJAFS2jrEo068Kr0D3W5NCsXX15mVft8sko+zeHp6pwmJq7nCCgBL1GNzBQnTMny3i6TdHcR95knY0VZqJAVqdYQQIhAMHTd6dJDSuVhs8H9KLBK9XHRz4SnckCoUxKz0xMtMXNAiEA7cJeCEhlOCHUhHhMi6BYpwEUdhAq0Zz3UHPBc1fKq88CIQC2bKzZriqDX43wB3zVaoOcBtmj1Uk1qB9W3P9W3shBsQIgG/i/xL05FamgiA4nH3xGqjxcwph9ghJ3cuBxHKDqqs0CIQCMCiiJKE48NNxS7IbROCpBNjGGgdSUyRzF7QiiHDE4Kw==")

End Sub
