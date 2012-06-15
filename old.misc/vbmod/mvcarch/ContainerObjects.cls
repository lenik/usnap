VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Siblings"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const LOCATION = "MVCArch::Siblings"

Private m_Container As Object
Private m_ContainerName As String
Private m_Objects As Map
'Private m_NonameId As Integer

Public Sub SetIndexed(IndexedObjects, ByVal ContainerName As String)
    Dim i As Integer
    Dim obj As Object
    m_ContainerName = ContainerName
    Set m_Objects = New Map
    For i = LBound(IndexedObjects) To UBound(IndexedObjects)
        Set obj = IndexedObjects(i)
        If LC.HasMember(obj, "Name") Then
            m_Objects.Item(obj.Name) = obj
        'Else
        '    m_Objects.Item("#Noname." & m_NonameId) = obj
        '    m_NonameId = m_NonameId + 1
        End If
    Next
End Sub

Public Sub SetEnumed(EnumedObjects, ByVal ContainerName As String)
    Dim obj As Object
    m_ContainerName = ContainerName
    Set m_Objects = New Map
    For Each obj In EnumedObjects
        If LC.HasMember(obj, "Name") Then
            m_Objects.Item(obj.Name) = obj
        'Else
        '    m_Objects.Item("#Noname." & m_NonameId) = obj
        '    m_NonameId = m_NonameId + 1
        End If
    Next
End Sub

Public Sub SetMap(ObjectsMap As Map, ByVal ContainerName As String)
    Set m_Objects = ObjectsMap
    m_ContainerName = ContainerName
End Sub

Public Property Get Objects() As Map
    Set Objects = m_Objects
End Property
