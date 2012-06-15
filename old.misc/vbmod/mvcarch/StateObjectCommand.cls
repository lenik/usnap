VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "StateObjectCommand"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private Const LOCATION                  As String = "MVCArch::StateObjectCommand"

Public Enum MethodConstants
    methodGoto = 0
    methodCall
End Enum

Private Const DEFAULT_NAME              As String = "Noname"
Private Const DEFAULT_DEFAULT           As Boolean = False
Private Const DEFAULT_TARGETNAME        As String = ""
Private Const DEFAULT_METHOD            As Integer = methodGoto
Private Const DEFAULT_GRAYED            As Boolean = False
Private Const DEFAULT_VISIBLE           As Boolean = True
Private Const DEFAULT_TITLE             As String = ""

Private m_Name As String                ' The name will be passed as "message" to Process event
Private m_Default As Boolean            ' Default command
Private m_TargetName As String          ' Target state name
Private m_Method As MethodConstants     ' How to jump into TargetName state
Private m_Grayed As Boolean             ' Button disabled
Private m_Visible As Boolean            ' Button visible
Private m_Title As String               ' Button text
Private m_Icon As IPictureDisp          ' Button icon

Event Changed()

Public Property Get Name() As String
    Name = m_Name
End Property
Public Property Let Name(ByVal newval As String)
    If m_Name <> newval Then
        m_Name = newval
        RaiseEvent Changed
    End If
End Property

Public Property Get Default() As Boolean
    Default = m_Default
End Property
Public Property Let Default(ByVal newval As Boolean)
    If m_Default <> newval Then
        m_Default = newval
        RaiseEvent Changed
    End If
End Property

Public Property Get TargetName() As String
    TargetName = m_TargetName
End Property
Public Property Let TargetName(ByVal newval As String)
    If m_TargetName <> newval Then
        m_TargetName = newval
        RaiseEvent Changed
    End If
End Property

Public Property Get Method() As MethodConstants
    Method = m_Method
End Property
Public Property Let Method(ByVal newval As MethodConstants)
    If m_Method <> newval Then
        m_Method = newval
        RaiseEvent Changed
    End If
End Property

Public Property Get Grayed() As Boolean
    Grayed = m_Grayed
End Property
Public Property Let Grayed(ByVal newval As Boolean)
    If m_Grayed <> newval Then
        m_Grayed = newval
        RaiseEvent Changed
    End If
End Property

Public Property Get Visible() As Boolean
    Visible = m_Visible
End Property
Public Property Let Visible(ByVal newval As Boolean)
    If m_Visible <> newval Then
        m_Visible = newval
        RaiseEvent Changed
    End If
End Property

Public Property Get Title() As String
    Title = IIf(m_Title = "", m_Name, m_Title)
End Property
Public Property Let Title(ByVal newval As String)
    If m_Title <> newval Then
        m_Title = newval
        RaiseEvent Changed
    End If
End Property

Public Property Get Icon() As IPictureDisp
    Set Icon = m_Icon
End Property
Public Property Let Icon(ByVal newval As IPictureDisp)
    If Not m_Icon Is newval Then
        Set m_Icon = newval
        RaiseEvent Changed
    End If
End Property

Public Property Get Target(Context) As Object
    Set Target = FindControl(Context, m_TargetName)
End Property
