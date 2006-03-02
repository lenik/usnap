VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Globals"
Attribute VB_GlobalNameSpace = True
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Public Property Get ConnectionString() As String
    If Config.ConnectionString Then
        ConnectionString = Config.ConnectionString
    Else
        ConnectionString = "DRIVER=" & Config.DBDriver & _
                           ";SERVER=" & Config.DBServer & _
                           ";UID=" & Config.DBUserID & _
                           ";PWD=" & Config.DBPassword
    End If
End Property

Public Property Get Dict() As DBDict
    Set Dict = GlobalsSingleton.Dict
End Property

Public Function DBConnectEx(Optional ByVal Driver, _
                            Optional ByVal Server, _
                            Optional ByVal Database, _
                            Optional ByVal UserID, _
                            Optional ByVal Password, _
                            Optional ByVal Options As Long = -1&) As DBConnection
    If IsMissing(Driver) Then Driver = Config.DBDriver
    If IsMissing(Server) Then Server = Config.DBServer
    If IsMissing(Database) Then Database = Config.DBDatabase
    If IsMissing(UserID) Then UserID = Config.DBUserID
    If IsMissing(Password) Then Password = Config.DBPassword

    Dim connstr As String
    If Driver <> "" Then connstr = connstr & ";DRIVER={" & Driver & "}"
    If Server <> "" Then connstr = connstr & ";SERVER=" & Server
    If Database <> "" Then connstr = connstr & ";DATABASE=" & Database
    If UserID <> "" Then connstr = connstr & ";UID=" & UserID
    If Password <> "" Then connstr = connstr & ";PWD=" & Password

    If connstr = "" Then
        Set DBConnectEx = DBConnect(, Options)
    Else
        Set DBConnectEx = DBConnect(Mid(connstr, 2), Options)
    End If
End Function

Public Function DBConnect(Optional ByVal ConnectionString, Optional ByVal Options As Long = -1) As DBConnection
    Set DBConnect = New DBConnection

    If IsMissing(ConnectionString) Then ConnectionString = Config.DBConnectionString
    If ConnectionString = "" Then
        DBConnect.Allocate , , , Options
    Else
        DBConnect.Allocate ConnectionString, , , Options
    End If
End Function
