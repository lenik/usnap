VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Begin VB.Form frmCOMAdmin
   Caption         =   "Form1"
   ClientHeight    =   5100
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   9105
   LinkTopic       =   "Form1"
   ScaleHeight     =   5100
   ScaleWidth      =   9105
   StartUpPosition =   3  '窗口缺省
   Begin VB.Frame Frame1
      Caption         =   "Frame1"
      Height          =   4275
      Left            =   4335
      TabIndex        =   2
      Top             =   735
      Width           =   4635
      Begin VB.Label lblObjectValid
         AutoSize        =   -1  'True
         Caption         =   "Valid"
         Height          =   180
         Left            =   165
         TabIndex        =   5
         Top             =   1020
         Width           =   450
      End
      Begin VB.Label lblObjectName
         AutoSize        =   -1  'True
         Caption         =   "Name"
         Height          =   180
         Left            =   165
         TabIndex        =   4
         Top             =   660
         Width           =   360
      End
      Begin VB.Label lblObjectKey
         AutoSize        =   -1  'True
         Caption         =   "Key"
         Height          =   180
         Left            =   180
         TabIndex        =   3
         Top             =   285
         Width           =   270
      End
   End
   Begin VB.CommandButton cmdInitTree
      Caption         =   "InitTree"
      Height          =   435
      Left            =   4275
      TabIndex        =   1
      Top             =   240
      Width           =   1365
   End
   Begin MSComctlLib.TreeView tvCatalog
      Height          =   4785
      Left            =   135
      TabIndex        =   0
      Top             =   225
      Width           =   4020
      _ExtentX        =   7091
      _ExtentY        =   8440
      _Version        =   393217
      Sorted          =   -1  'True
      Style           =   7
      Appearance      =   1
   End
End
Attribute VB_Name = "frmCOMAdmin"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Public Catalog As New comadmin.COMAdminCatalog

Public Function GetCatColl(ByVal pos As String) As comadmin.COMAdminCatalogCollection
        Dim CollName As String
        Dim coll As comadmin.COMAdminCatalogCollection
        Dim nLevels As Integer
        Dim i As Integer

        nLevels = val(decodePart(pos, 0))

        Set coll = Catalog.GetCollection("Root")
        For i = 1 To nLevels
                CollName = decodePart(pos, i)
                Set coll = coll.GetCollection(CollName, "")
        Next
        Set GetCatColl = coll
        If Not GetCatColl Is Nothing Then GetCatColl.Populate
        Set coll = Nothing
End Function

Public Function GetCatObject(ByVal pos As String) As comadmin.COMAdminCatalogObject
        Dim coll As comadmin.COMAdminCatalogCollection
        Dim obj As comadmin.COMAdminCatalogObject
        Dim nLevels As Integer
        Dim CollPos As String
        Dim objName As String
        Dim i As Integer

        nLevels = val(decodePart(pos, 0))
        CollPos = pos
        objName = departPart(CollPos, nLevels)
        CollPos = Trim(nLevels - 1) & Mid(CollPos, decodePart(CollPos, 1, True))
        Set coll = GetCatColl(CollPos)

        For i = 0 To coll.Count - 1
                Set obj = coll.Item(i)
                If obj.name = objName Then Exit For
                Set obj = Nothing
        Next

        Set GetCatObject = obj
End Function

Private Sub cmdInitTree_Click()
        InitTreePart Nothing, GetCatColl("0")
End Sub

Public Sub InitTreePart(tvn As Node, coll As comadmin.COMAdminCatalogCollection)
        Dim n As Node
        Dim i As Integer
        Dim pKeyN As Integer
        Dim pKeyPos As String
        Dim posName As String, objName As String
        Dim subColl As comadmin.COMAdminCatalogCollection

        If coll Is Nothing Then Exit Sub
        coll.Populate

        If tvn Is Nothing Then
                pKeyN = 0
                pKeyPos = ""
        Else
                pKeyN = val(decodePart(tvn.Tag, 0))
                pKeyPos = Mid(tvn.Tag, decodePart(tvn.Tag, 1, True))
        End If

        ' 获取集合中的子集合
        Set subColl = coll.GetCollection("RelatedCollectionInfo", "")
        subColl.Populate
        For i = 0 To subColl.Count - 1
                objName = subColl.Item(i).name
                posName = Trim(pKeyN + 1) & pKeyPos & encodePart(objName)
                With tvCatalog.Nodes
                        If tvn Is Nothing Then
                                Set n = .Add(, tvwChild, , objName)
                        Else
                                Set n = .Add(tvn, tvwChild, , objName)
                        End If
                End With
                If Not n Is Nothing Then
                        n.Tag = posName
                        n.Bold = True
                        Set n = Nothing
                End If
        Next

        ' 获取集合中的结点元素
        For i = 0 To coll.Count - 1
                objName = coll.Item(i).name
                posName = Trim(pKeyN + 1) & pKeyPos & encodePart(objName)
                With tvCatalog.Nodes
                        If tvn Is Nothing Then
                                Set n = .Add(, tvwChild, , objName)
                        Else
                                Set n = .Add(tvn, tvwChild, , objName)
                        End If
                End With
                If Not n Is Nothing Then
                        n.Tag = posName
                        n.Bold = False
                        Set n = Nothing
                End If
        Next
End Sub

Private Sub tvCatalog_Click()
        Dim obj As comadmin.COMAdminCatalogObject
        Dim selected As Node

        Set selected = tvCatalog.SelectedItem
        If Not selected.Bold Then
                Set obj = GetCatObject(selected.Tag)
                lblObjectKey.Caption = obj.Key
                lblObjectName.Caption = obj.name
                lblObjectValid.Caption = obj.Valid
                Set obj = Nothing
        End If
End Sub

Private Sub tvCatalog_DblClick()
        Dim coll As comadmin.COMAdminCatalogCollection
        Dim selected As Node

        Set selected = tvCatalog.SelectedItem
        If selected.Bold Then     ' Collection
                If selected.Children = 0 Then
                        Set coll = GetCatColl(selected.Tag)
                        InitTreePart selected, coll
                        selected.Expanded = True
                End If
        End If
End Sub
