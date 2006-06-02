VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "RSAEncrypt"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "Security::RSAEncrypt"

Implements VBExt.RuntimeEntryProvider

Private m_Value As String

Private Function RuntimeEntryProvider_Eval() As Variant
    RuntimeEntryProvider_Eval = m_Value
End Function

Private Sub RuntimeEntryProvider_Initialize(ByVal ParamMap As VBExt.Map, ByVal Value As Variant)
    Dim PublicId
    Dim KXClient As New AsymCrypto
    Dim KXData As New AsymCrypto
    Dim Registry As PKIRegistry

    PublicId = ParamMap("PublicId")
    Assert Not IsNull(PublicId), "PublicId isn't specified", LOCATION

    KXClient.GenerateKeys
    Set Registry = ConnectPKIRegistry(KXClient.PublicKey)

    KXData.PrivateKey = Registry.PrivateKey(PublicId, "")
    m_Value = KXData.DecryptMessage(Value)
End Sub
