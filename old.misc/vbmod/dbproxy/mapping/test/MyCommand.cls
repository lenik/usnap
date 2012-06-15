VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "MyCommand"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private m_Raw As ADODB.Command

Implements ADOMapping.ICommand

Private Sub Class_Initialize()
    Set m_Raw = New Command
End Sub

Private Property Set ICommand_ActiveConnection(ByVal RHS As ADODB.Connection)
    Set m_Raw.ActiveConnection = RHS
End Property

Private Property Let ICommand_ActiveConnection(ByVal RHS As Variant)
    m_Raw.ActiveConnection = RHS
End Property

Private Property Get ICommand_ActiveConnection() As ADODB.Connection
    Set ICommand_ActiveConnection = m_Raw.ActiveConnection
End Property

Private Sub ICommand_Cancel()
    m_Raw.Cancel
End Sub

Private Property Set ICommand_CommandStream(ByVal RHS As Object)
    Set m_Raw.CommandStream = RHS
End Property

Private Property Get ICommand_CommandStream() As Variant
    Set ICommand_CommandStream = m_Raw.CommandStream
End Property

Private Property Let ICommand_CommandText(ByVal RHS As String)
    m_Raw.CommandText = RHS
End Property

Private Property Get ICommand_CommandText() As String
    ICommand_CommandText = m_Raw.CommandText
End Property

Private Property Let ICommand_CommandTimeout(ByVal RHS As Long)
    m_Raw.CommandTimeout = RHS
End Property

Private Property Get ICommand_CommandTimeout() As Long
    ICommand_CommandTimeout = m_Raw.CommandTimeout
End Property

Private Property Let ICommand_CommandType(ByVal RHS As ADODB.CommandTypeEnum)
    m_Raw.CommandType = RHS
End Property

Private Property Get ICommand_CommandType() As ADODB.CommandTypeEnum
    ICommand_CommandType = m_Raw.CommandType
End Property

Private Function ICommand_CreateParameter(Optional ByVal Name As String = "", Optional ByVal Type_ As ADODB.DataTypeEnum = 0&, Optional ByVal Direction As ADODB.ParameterDirectionEnum = 1&, Optional ByVal Size As Long = 0&, Optional ByVal Value As Variant) As ADODB.Parameter
    Set ICommand_CreateParameter = m_Raw.CreateParameter(Name, Type_, Direction, Size, Value)
End Function

Private Property Let ICommand_Dialect(ByVal RHS As String)
    m_Raw.Dialect = RHS
End Property

Private Property Get ICommand_Dialect() As String
    ICommand_Dialect = m_Raw.Dialect
End Property

Private Function ICommand_Execute(Optional RecordsAffected As Variant, Optional Parameters As Variant, Optional ByVal Options As Long = -1&) As ADODB.Recordset
    Set ICommand_Execute = m_Raw.Execute(RecordsAffected, Parameters, Options)
End Function

Private Property Let ICommand_Name(ByVal RHS As String)
    m_Raw.Name = RHS
End Property

Private Property Get ICommand_Name() As String
    ICommand_Name = m_Raw.Name
End Property

Private Property Let ICommand_NamedParameters(ByVal RHS As Boolean)
    m_Raw.NamedParameters = RHS
End Property

Private Property Get ICommand_NamedParameters() As Boolean
    ICommand_NamedParameters = m_Raw.NamedParameters
End Property

Private Property Get ICommand_Parameters() As ADODB.Parameters
    Set ICommand_Parameters = m_Raw.Parameters
End Property

Private Property Let ICommand_Prepared(ByVal RHS As Boolean)
    m_Raw.Prepared = RHS
End Property

Private Property Get ICommand_Prepared() As Boolean
    ICommand_Prepared = m_Raw.Prepared
End Property

Private Property Get ICommand_Properties() As ADODB.Properties
    Set ICommand_Properties = m_Raw.Properties
End Property

Private Property Get ICommand_State() As Long
    ICommand_State = m_Raw.State
End Property
