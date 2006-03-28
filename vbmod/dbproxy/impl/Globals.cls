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

Public Property Get DBConnectionString(Optional ByVal Driver, _
                                       Optional ByVal Server, _
                                       Optional ByVal Database, _
                                       Optional ByVal UserID, _
                                       Optional ByVal Password, _
                                       Optional ByVal Options As Long = -1&) As String
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

    ' chop leading ';'
    If connstr <> "" Then connstr = Mid(connstr, 2)

    If connstr = "" Then connstr = Config.DBConnectionString

    DBConnectionString = connstr
End Property

Public Property Get Dictionary() As DBDict
    Set Dictionary = GlobalsSingleton.Dict
End Property

Public Function DBConnect(Optional ByVal ConnectionString) As DBConnection
    Set DBConnect = New DBConnection

    If IsMissing(ConnectionString) Then ConnectionString = DBConnectionString
    If ConnectionString = "" Then
        DBConnect.Allocate
    Else
        DBConnect.Allocate ConnectionString
    End If
End Function

Public Function DBConnectFast(Optional ByVal ConnectionString) As DBConnection
    Set DBConnectFast = New DBConnection

    If IsMissing(ConnectionString) Then ConnectionString = DBConnectionString
    If ConnectionString = "" Then
        DBConnectFast.Allocate , , , adAsyncConnect
    Else
        DBConnectFast.Allocate ConnectionString, , , adAsyncConnect
    End If
End Function

Public Property Get SQLF() As SQLFunctions
    Set SQLF = GlobalsSingleton.SQLF
End Property
