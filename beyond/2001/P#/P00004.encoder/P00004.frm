VERSION 5.00
Begin VB.Form Form1
   Caption         =   "Form1"
   ClientHeight    =   5295
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6360
   LinkTopic       =   "Form1"
   ScaleHeight     =   5295
   ScaleWidth      =   6360
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text3
      Height          =   1455
      Left            =   300
      MultiLine       =   -1  'True
      TabIndex        =   4
      Top             =   1560
      Width           =   5715
   End
   Begin VB.CommandButton Command2
      Caption         =   "decrypt"
      Height          =   375
      Left            =   3660
      TabIndex        =   3
      Top             =   3120
      Width           =   1575
   End
   Begin VB.CommandButton Command1
      Caption         =   "encrypt"
      Height          =   375
      Left            =   780
      TabIndex        =   2
      Top             =   3120
      Width           =   1695
   End
   Begin VB.TextBox Text2
      Height          =   1635
      Left            =   300
      MultiLine       =   -1  'True
      TabIndex        =   1
      Top             =   3540
      Width           =   5715
   End
   Begin VB.TextBox Text1
      Height          =   1395
      Left            =   300
      MultiLine       =   -1  'True
      TabIndex        =   0
      Top             =   120
      Width           =   5715
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Public Sub encrypt(s())
        ReDim d(LBound(s) To UBound(s))

        Dim i, N
        N = UBound(s) - LBound(s) + 1

        For i = LBound(s) To UBound(s)
                d(i) = s(i) + s((i + N - 1) Mod N)
        Next

        s = d
End Sub

Public Function decrypt(d(), i) As Long
        Dim N
        Dim j, ss As Long

        N = UBound(d) - LBound(d) + 1
        ss = 0
        For j = 0 To i
                ss = ss + (-1) ^ (i - j) * d(j)
        Next
        For j = i + 1 To N - 1
                ss = ss + (-1) ^ (i + N - j) * d(j)
        Next
        decrypt = ss / 2
End Function

Private Sub Command1_Click()

        If Len(Text1) Mod 2 = 0 Then
                Text1 = Text1 & ""
        End If

        Dim i, l
        l = Len(Text1)
        ReDim c(0 To l - 1)

        Text3 = ""
        For i = 0 To l - 1
                c(i) = Asc(Mid(Text1, i + 1, 1))
                Text3 = Text3 & c(i)
                If i <> l - 1 Then Text3 = Text3 & ":"
                DoEvents
        Next

        encrypt c

        Text2 = ""
        For i = 0 To l - 1
                Text2 = Text2 & c(i)
                If i <> l - 1 Then Text2 = Text2 & ":"
                DoEvents
        Next
End Sub

Private Sub Command2_Click()

        Dim ds, i
        ds = Split(Text2, ":")
        ReDim dn(LBound(ds) To UBound(ds))
        For i = LBound(ds) To UBound(ds)
                dn(i) = Val(ds(i))
        Next

        Dim cn, c
        Text1 = ""
        For i = LBound(dn) To UBound(dn)
                cn = decrypt(dn, i)
                c = Chr(cn)
                Text1 = Text1 & c
                DoEvents
        Next
End Sub
