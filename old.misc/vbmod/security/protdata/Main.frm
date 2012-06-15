VERSION 5.00
Begin VB.Form Main
   Caption         =   "Protected Information Builder"
   ClientHeight    =   5520
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7800
   LinkTopic       =   "Form1"
   ScaleHeight     =   5520
   ScaleWidth      =   7800
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnDecrypt
      Caption         =   "&Decrypt"
      Height          =   375
      Left            =   4020
      TabIndex        =   6
      Top             =   2880
      Width           =   1635
   End
   Begin VB.CommandButton btnEncrypt
      Caption         =   "&Encrypt"
      Height          =   375
      Left            =   1680
      TabIndex        =   5
      Top             =   2880
      Width           =   1635
   End
   Begin VB.TextBox txtEncrypt
      Height          =   1815
      Left            =   300
      TabIndex        =   7
      Text            =   "Text2"
      Top             =   3420
      Width           =   7155
   End
   Begin VB.TextBox txtDecrypt
      Height          =   1755
      Left            =   300
      TabIndex        =   4
      Text            =   "Text1"
      Top             =   960
      Width           =   7155
   End
   Begin VB.ComboBox lstSysId
      Height          =   315
      ItemData        =   "Main.frx":0000
      Left            =   5580
      List            =   "Main.frx":000A
      Style           =   2  'Dropdown List
      TabIndex        =   3
      Top             =   360
      Width           =   1875
   End
   Begin VB.ComboBox lstType
      Height          =   315
      ItemData        =   "Main.frx":001C
      Left            =   1800
      List            =   "Main.frx":002C
      Style           =   2  'Dropdown List
      TabIndex        =   1
      Top             =   360
      Width           =   1875
   End
   Begin VB.Label Label2
      Caption         =   "System Id"
      Height          =   255
      Left            =   4140
      TabIndex        =   2
      Top             =   420
      Width           =   1335
   End
   Begin VB.Label Label1
      Caption         =   "Information &Type"
      Height          =   255
      Left            =   300
      TabIndex        =   0
      Top             =   420
      Width           =   1335
   End
End
Attribute VB_Name = "Main"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private layout As New AutoScaleLayout
Private b64 As New BinaryLib.Base64

Private Property Get Value() As String
    Select Case lstType.ListIndex
    Case 0  ' Plain Text
        Value = txtDecrypt
    Case 1  ' Base-64
        Value = Base64ToString(txtDecrypt)
    Case 2  ' HEX
        Value = HexToString(txtDecrypt)
    Case 3  ' File
        b64.ReadFile txtDecrypt
        Value = b64.GetStringB
    End Select
End Property

Property Let Value(ByVal newval As String)
    Select Case lstType.ListIndex
    Case 0  ' Plain Text
        txtDecrypt = newval
    Case 1  ' Base-64
        txtDecrypt = StringToBase64(newval)
    Case 2  ' HEX
        txtDecrypt = StringToHex(newval)
    Case 3  ' File
        ' Force to display in Base-64
        lstType.ListIndex = 1
        txtDecrypt = StringToBase64(newval)
    End Select
End Property

Private Sub btnEncrypt_Click()
    Dim xRSA As New Security.RSAEncrypt
    Dim REP As VBExt.RuntimeEntryProvider
    Dim PM As New VBExt.Map

    Set REP = xRSA
    PM("PublicId") = lstSysId.Text

    REP.Initialize PM, Value
End Sub

Private Sub Form_Load()
    lstType.ListIndex = 0
    lstSysId.ListIndex = 0
    layout.InitializeCoordinations Me
End Sub

Private Sub Form_Resize()
    layout.Relayout
End Sub
