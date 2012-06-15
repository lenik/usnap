Attribute VB_Name = "modVars"
Global Const PClassMax = 6
Global Const PItemMax = 12

Global Const XorValue = &HFF

Global FSystemDir As String, CurDir As String
Global DataDir As String
Global ClassDataFile As String, UserFile As String
Public Const SysDrive = "C:"
Public Const SI_UNKNOWN = "Images\Unknown.ico"
Public Const SI_EXECUTABLE = "Images\Execable.ico"

Global CurClass As Integer
' Number used
Global MaxClass As Integer

Type UserRecord
  Name As String * 10
  Password As String * 10
  ClassOp As Boolean
  UserOp As Boolean
  ManageSelf As Boolean
  ViewLog As Boolean
End Type

Global CurUser As UserRecord


'   IconFile: Icon should show on screen
'       way:
'           add icon analyzer in CClass::SetIconName
'             and place setpicture in it.
'   User
