VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "easyminipic"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False

Const EVAL              As Long = &H80000000

Public srchdc           As Long
Public desthdc          As Long
Public drawop           As Long

Private srcx            As Long
Private srcy            As Long
Private srcw            As Long
Private srch            As Long

Private mapdx           As Long
Private mapdy           As Long

Private visible_        As Boolean
Private onshow_         As Boolean
Private destx_          As Long         ' center x
Private desty_          As Long         ' center y

Public Sub srcrect(nsrcx, nsrcy, nsrcw, nsrch)
        srcx = nsrcx
        srcy = nsrcy
        srcw = nsrcw
        srch = nsrch
        mapdx = -srcw / 2
        mapdy = -srch / 2
End Sub

Public Property Get visible() As Boolean: visible = visible_: End Property
Public Property Get onshow() As Boolean: onshow = onshow_: End Property
Public Property Get destx() As Long: destx = destx_: End Property
Public Property Get desty() As Long: desty = desty_: End Property

Public Property Let visible(ByVal newv As Boolean)
        If newv = False Then
                If visible_ Then
                        Me.clear
                        visible_ = False
                End If
        Else
                If Not visible_ Then
                        Me.draw
                        visible_ = True
                End If
        End If
End Property

Public Property Let onshow(ByVal newv As Boolean)
        If newv = False Then
                Me.clear
        Else
                Me.draw
        End If
End Property

Public Property Let destx(ByVal newv As Long)
        If destx_ <> newv Then
                If onshow Then
                        Me.clear
                        destx_ = newx
                        Me.draw
                Else
                        destx_ = newx
                End If
        End If
End Property

Public Property Let desty(ByVal newv As Long)
        If desty_ <> newv Then
                If onshow Then
                        Me.clear
                        desty_ = newv
                        Me.draw
                Else
                        desty_ = newv
                End If
        End If
End Property

Public Function draw(Optional ByVal x As Long = EVAL, Optional ByVal y As Long = EVAL) As Boolean
        If Not visible Then Exit Function
        If onshow_ Then
                If destx = x And desty = y Then Exit Function
                Me.clear
        End If
        ' draw
        onshow_ = True
End Function

Public Function clear() As Boolean
        If Not visible Then Exit Function
        If Not onshow_ Then Exit Function
        ' clear
        onshow_ = False
End Function
