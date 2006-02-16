VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Layout"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit
Option Base 0

Private Const LOCATION = "VBExt::Layout"
Private Const MAX_SIZE = 256
Private Const MIN_WIDTH = 10
Private Const MIN_HEIGHT = 10

Private LC As New LowXRuntime.Component

Private m_Item(MAX_SIZE, 1) As Object
Private m_Items As Integer
Private m_ItemPos(MAX_SIZE) As Position

Private m_Container(MAX_SIZE) As Object
Private m_Containers As Integer
Private m_ContainerPos(MAX_SIZE) As Position

Private Function GetItemIndex(object As Object) As Integer
    Dim i As Integer
    GetItemIndex = -1
    For i = 0 To m_Items - 1
        If m_Item(i, 0) Is object Then
            GetItemIndex = i
            Exit Function
        End If
    Next
End Function

Private Function GetContainerIndex(object As Object) As Integer
    Dim i As Integer
    GetContainerIndex = -1
    For i = 0 To m_Containers - 1
        If m_Container(i) Is object Then
            GetContainerIndex = i
            Exit Function
        End If
    Next
End Function

Private Function GetItemPosition(object As Object) As Position
    Dim i As Integer
    i = GetItemIndex(object)
    Assert i >= 0
    GetItemPosition = m_ItemPos(i)
End Function

Private Function GetContainerPosition(object As Object) As Position
    Dim i As Integer
    i = GetContainerIndex(object)
    Assert i >= 0
    GetContainerPosition = m_ContainerPos(i)
End Function

Public Sub InitializeCoordinations(objectsContainer As Object)
    Dim child As Object
    For Each child In objectsContainer
        If LC.HasMember(child, "Container") Then
            Assert m_Items < MAX_SIZE - 1
            Set m_Item(m_Items, 0) = child
            Set m_Item(m_Items, 1) = child.container
            m_ItemPos(m_Items).x0 = child.Left
            m_ItemPos(m_Items).y0 = child.Top
            m_ItemPos(m_Items).x1 = child.Left + child.Width
            m_ItemPos(m_Items).y1 = child.Top + child.Height
            m_Items = m_Items + 1

            Assert m_Containers < MAX_SIZE - 1
            Set m_Container(m_Containers) = child.container
            m_ContainerPos(m_Containers).x0 = child.container.Left
            m_ContainerPos(m_Containers).y0 = child.container.Top

            Assert child.container.Width > MIN_WIDTH, "原始容器尺寸不能过小", LOCATION
            Assert child.container.Height > MIN_HEIGHT, "原始容器尺寸不能过小", LOCATION
            m_ContainerPos(m_Containers).x1 = child.container.Left + child.container.Width
            m_ContainerPos(m_Containers).y1 = child.container.Top + child.container.Height
            m_Containers = m_Containers + 1
        End If
    Next
End Sub

Public Sub Relayout(Optional container)
    Dim child As Object
    Dim i As Integer

    If IsMissing(container) Then
        ' All
        For i = 0 To m_Items - 1
            RelayoutItem m_Item(i, 0), m_Item(i, 1)
        Next
    Else
        ' Only m_Items in the containerObject
        Assert IsObject(container)
        Dim containerObject As Object
        Set containerObject = container ' reinterpret_cast<>
        For i = 0 To m_Items - 1
            If m_Item(i, 1) Is containerObject Then
                RelayoutItem m_Item(i, 0), containerObject
            End If
        Next
    End If
End Sub

Private Sub RelayoutItem(itemObject As Object, containerObject As Object)
    Dim i As Integer
    Dim oldContainer As Position
    Dim oldItem As Position
    Dim newContainer As Position
    Dim newItem As Position
    Dim oldW As Double, newW As Double
    Dim oldH As Double, newH As Double
    Dim scaleX As Double, scaleY As Double
    Dim doVertical As Boolean

    If containerObject Is Nothing Then
        Set containerObject = itemObject.container
        Assert Not containerObject Is Nothing
    End If

    ' Original coordinations
    oldItem = GetItemPosition(itemObject)
    oldContainer = GetContainerPosition(containerObject)
    newContainer.x0 = containerObject.Left
    newContainer.y0 = containerObject.Top
    newContainer.x1 = containerObject.Left + containerObject.Width
    newContainer.y1 = containerObject.Top + containerObject.Height
    oldW = oldContainer.x1 - oldContainer.x0
    oldH = oldContainer.y1 - oldContainer.y0
    newW = newContainer.x1 - newContainer.x0
    newH = newContainer.y1 - newContainer.y0

    ' New coordination
    ' For Label/Text, don't do vertical-resize
    Select Case TypeName(itemObject)
    Case "Label", "TextBox"
        doVertical = False
    Case Else
        doVertical = True
    End Select

    scaleX = newW / oldW    ' oldW > MIN_WIDTH
    scaleY = newH / oldH    ' oldH > MIN_HEIGHT

    newItem.x0 = oldItem.x0 * scaleX
    newItem.x1 = oldItem.x1 * scaleX
    If doVertical Then
        newItem.y0 = oldItem.y0 * scaleY
        newItem.y1 = oldItem.y1 * scaleY
    Else
        newItem.y0 = oldItem.y0 * scaleY + _
            (oldItem.y1 - oldItem.y0) * scaleY / 2 - _
            (oldItem.y1 - oldItem.y0) / 2
        newItem.y1 = newItem.y0 + _
            oldItem.y1 - oldItem.y0
    End If

    On Error Resume Next
    itemObject.Left = newItem.x0
    itemObject.Top = newItem.y0
    itemObject.Width = newItem.x1 - newItem.x0
    itemObject.Height = newItem.y1 - newItem.y0
End Sub
