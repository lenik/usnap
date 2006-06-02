Attribute VB_Name = "Test_Crypto"
Option Explicit

Public sk As New SymCrypto
Public ak As New AsymCrypto

Public Sub t1()
    ak.GenerateKeys
    sk.Key = "123"

    ' sk ~ 1:1
    ' s = "123ÖÐ¹út¿¨@*+": v = sk.EncryptMessage(s): t = sk.DecryptMessage(v): Print t, v, Len(s), Len(t), Len(v) * 0.75

    ' ak ~ 1:3
    ' s="1234567890123456789012345678901234567890123": v=ak.EncryptMessage(s): t=ak.DecryptMessage(v): ?t, len(s), len(t), len(v)*0.75
End Sub
