VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Begin VB.Form frmMain
   Caption         =   "Form1"
   ClientHeight    =   4170
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5715
   LinkTopic       =   "Form1"
   ScaleHeight     =   4170
   ScaleWidth      =   5715
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin MSComctlLib.TreeView tv
      Height          =   3915
      Left            =   195
      TabIndex        =   1
      Top             =   210
      Width           =   3585
      _ExtentX        =   6324
      _ExtentY        =   6906
      _Version        =   393217
      Style           =   7
      Appearance      =   1
   End
   Begin VB.CommandButton Command1
      Caption         =   "Command1"
      Height          =   690
      Left            =   4050
      TabIndex        =   0
      Top             =   3315
      Width           =   1425
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim WithEvents parser As OeSOParser
Attribute parser.VB_VarHelpID = -1
Dim myparser As New OeSOParser

Dim r As Boolean

Private Sub att_onChanged()
        MsgBox "HELLO"
End Sub

Public Sub pcoll(n As Node, coll As OeSOLib.OeSOCollection)
        Dim cn As Node
        Dim i As Integer
        For i = 0 To coll.Count - 1
                Set cn = tv.Nodes.Add(n, tvwChild, , coll.member(i))
        Next
End Sub

Private Sub Command1_Click()
        Dim ss As String
        Dim j As Long
        ss = _
                "<?xml version=""1.0"" encoding=""GB2312""?>" & _
                "<soml><i n=""Animal""><m n=""Bite""><p n=""power"" c=""real"" v=""1.0""/>" & _
                "<p n=""target"" c=""Animal""/></m><e n=""Bitten""><p n=""power"" c=""real"" v=""1.0""/>" & _
                "<p n=""source"" c=""Animal""/></e><i n=""Dog""><m n=""Scream""><p n=""dB"" c=""real"" v=""1.0""/>" & _
                "</m></i></i><c n=""Alaskya"" mapto=""sox:CaDogCat"">" & _
                "<ao n=""owner"" c=""string"" mapto=""Owner""/><i n=""Animal - Dog"" mapto=""IDog"">" & _
                "<m n=""Bite"" mapto=""Bite""/><e n=""Bitten"" mapto=""Bitten""/></i><c n=""AlaskyaL"" mapto=""sox:CaDogCatWithLongTail"">" & _
                "<ao n=""length"" c=""real""/><e n=""jie""><p n=""jie's topologic"" c=""complex""/></e></c></c></soml>"

        j = ct.reference(myparser)
        j = ct.reference(ct)
        j = ct.forceAddRef(myparser)
        j = ct.forceAddRef(myparser)
        j = ct.forceRelease(myparser)
        j = ct.forceRelease(myparser)

        Dim xx As Object
        Set xx = ct

        r = myparser.loadSOML(ss)
        If r Then
                Dim ap As OeSOLib.OeSOApplication
                Set ap = myparser.createApplication

                MsgBox ct.reference(ap)

                Dim nroot As Node, n As Node
                Set nroot = tv.Nodes.Add(, tvwChild, , ap.Name)
                Set n = tv.Nodes.Add(nroot, tvwChild, "i", "i")
                        pcoll n, ap.interfaces
                Set n = tv.Nodes.Add(nroot, tvwChild, "c", "c")
                        pcoll n, ap.classes
                Set n = tv.Nodes.Add(nroot, tvwChild, "o", "o")
                        'pcoll n, ap.objects
                Set n = Nothing
                Set nroot = Nothing
                Set ap = Nothing
        Else
                MsgBox "couldn't create application"
        End If
End Sub

Private Sub parser_onLoaded()
        MsgBox "parser_onLoaded"
End Sub
