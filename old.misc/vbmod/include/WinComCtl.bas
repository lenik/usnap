Attribute VB_Name = "modMSComCtl"
Option Explicit

' TREE          = {NODE}                ' 单节点
' TREE          = {TREE}{NODE}          ' 并列节点
' NODE          = #{NUM}.{NODEDESC}     ' 节点
' NODEDESC      = {NODEDESC1}           ' 简单节点
' NODEDESC      = {NODEDESC1}{TREE}     ' 复杂节点
' NODEDESC1     = {TEXT}|{KEY}|{IMAGE}|{SELECT IMAGE}|{EXPAND IMAGE}
'
'         #59.   59+4
'         #32.FILE      32+4    4
'               #13.EDIT        13+4:   4
'                       #COPY           5
'                       #CUT            4
'               #OPEN           5
'               #CLOSE          6
'         #23.OPTIONS   23+4    7
'               #GENERAL        8
'               #ADVANCE        8
'
' MENU = "#28.FILE#13.EDIT#COPY#CUT#OPEN#CLOSE#23.OPTIONS#GENERAL#ADVANCE"

Public current_node As Node

Public l_s As New LowXTool.String
Dim l_p As New LowXRuntime.Pointer
Dim l_c As New LowXRuntime.Call

Private Function init_setnode_default(ByRef Data As Variant) As Boolean
        Dim node_desc As String
        Dim parti As Integer, parts As String
        node_desc = l_s.decodePart(Data, 0)

        With current_node
                .text = l_s.decodePart(node_desc, 0, , "|", True)

                parti = 0
                Do
                        parts = l_s.decodePart(node_desc, parti, , "|", True)
                        If parts = "" Then Exit Do
                        Select Case parti
                        Case 0: .Key = parts
                        Case 1: .Image = Val(parts)
                        Case 2: .SelectedImage = Val(parts)
                        Case 3: .ExpandedImage = Val(parts)
                        End Select
                        parti = parti + 1
                Loop
        End With

        init_setnode_default = True
End Function

Public Function init_treenodes(object As Nodes, outer As Node, ByVal treeDesc As String, Optional ByVal setnode_proc As Long = 0) As Boolean
        Dim tnode As Node
        Dim parti As Integer, parts As String
        Dim r As Boolean

        r = True
        If setnode_proc = 0 Then setnode_proc = l_p.pFunc(AddressOf init_setnode_default)
        parti = 1
        Do
                parts = l_s.decodePart(treeDesc, parti)
                If parts = "" Then Exit Do
                Set tnode = object.Add(IIf(outer Is Nothing, Missing, outer), _
                        tvwChild, l_s.decodePart(parts, 0), l_s.decodePart(parts, 0))

               ' tnode.Key =

                If tnode Is Nothing Then
                        init_treenodes = False
                Else
                        Set current_node = tnode
                        r = r And CBool(l_c.Call1(setnode_proc, l_p.pAny(parts)))

                        parts = Mid(parts, l_s.decodePart(parts, 1, True))
                        If parts <> "" Then r = r And init_treenodes(object, tnode, parts)
                End If

                parti = parti + 1
        Loop
        init_treenodes = r
End Function

Public Function SetListItem(LV As ListView, LI As ListItem, Optional Column, Optional text) As ListSubItem
        If IsMissing(Column) Then
                LI.text = text
                Set SetListItem = Nothing
        Else
                Dim ColumnIndex As Integer
                On Error GoTo x
                If IsNumeric(Column) Then
                        ColumnIndex = Column
                Else
                        ColumnIndex = LV.ColumnHeaders(Column).Index - 1
                End If
                LI.SubItems(ColumnIndex) = text
                Set SetListItem = LI.ListSubItems(ColumnIndex)
        End If
        Exit Function
x:
        Set SetListItem = Nothing
End Function

Public Function Missing()
        Missing = Missing_int
End Function

Private Function Missing_int(Optional M)
        Missing_int = M
End Function
