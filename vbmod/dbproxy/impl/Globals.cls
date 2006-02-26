VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Globals"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Property Get ConnectionString() As String
    If Config.ConnectionString Then
        ConnectionString = Config.ConnectionString
    Else
        ConnectionString = "DRIVER=" & Config.DBDriver & _
                           ";DBQ=" & Config.DBPath & _
                           ";UserID=" & Config.DBUserId & _
                           ";Password=" & Config.DBPassword
    End If
End Property

Public Property Get DefaultConnection() As Connection
    Dim conn As Connection

    Set conn = Dict
    ' Create the newest versioft of coclass
    Set conn = CreateObject("ADODB.Connection")

    conn.Open ConnectionString

    If Not IsNull(Config.dbdatabase) Then
        conn.DefaultDatabase = Config.dbdatabase
    End If
End Property

Public Property Get Dict() As DBDict
    Set Dict = GlobalsSingleton.Dict
End Property
