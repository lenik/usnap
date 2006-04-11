VERSION 5.00
Begin VB.Form frmImageMarks
   Caption         =   "Image Marks"
   ClientHeight    =   3630
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5355
   LinkTopic       =   "Form1"
   MDIChild        =   -1  'True
   ScaleHeight     =   242
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   357
   Begin VB.PictureBox P0
      AutoRedraw      =   -1  'True
      AutoSize        =   -1  'True
      Height          =   1215
      Left            =   2880
      ScaleHeight     =   77
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   125
      TabIndex        =   8
      Top             =   1620
      Visible         =   0   'False
      Width           =   1935
   End
   Begin VB.PictureBox P
      AutoRedraw      =   -1  'True
      Height          =   1215
      Left            =   2880
      ScaleHeight     =   77
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   125
      TabIndex        =   7
      Top             =   360
      Width           =   1935
   End
   Begin VB.CommandButton btnAdd
      Caption         =   "Add"
      Height          =   795
      Left            =   1680
      Picture         =   "frmImageMarks.frx":0000
      Style           =   1  'Graphical
      TabIndex        =   3
      Top             =   360
      Width           =   1035
   End
   Begin VB.CommandButton btnRemove
      Caption         =   "Remove"
      Height          =   795
      Left            =   1680
      Picture         =   "frmImageMarks.frx":030A
      Style           =   1  'Graphical
      TabIndex        =   4
      Top             =   1200
      Width           =   1035
   End
   Begin VB.CommandButton btnProperties
      Caption         =   "Properties"
      Height          =   795
      Left            =   1680
      Picture         =   "frmImageMarks.frx":0614
      Style           =   1  'Graphical
      TabIndex        =   5
      Top             =   2040
      Width           =   1035
   End
   Begin VB.CommandButton btnPicture
      Caption         =   "Picture"
      Height          =   795
      Left            =   480
      Picture         =   "frmImageMarks.frx":0EDE
      Style           =   1  'Graphical
      TabIndex        =   0
      Top             =   360
      Width           =   1035
   End
   Begin VB.CommandButton btnLayers
      Caption         =   "Layers"
      Height          =   795
      Left            =   480
      Picture         =   "frmImageMarks.frx":11E8
      Style           =   1  'Graphical
      TabIndex        =   1
      Top             =   1200
      Width           =   1035
   End
   Begin VB.CommandButton btnObjects
      Caption         =   "Objects"
      Height          =   795
      Left            =   480
      Picture         =   "frmImageMarks.frx":14F2
      Style           =   1  'Graphical
      TabIndex        =   2
      Top             =   2040
      Width           =   1035
   End
   Begin VB.Label lblInfo
      BorderStyle     =   1  'Fixed Single
      Caption         =   "INFO"
      Height          =   315
      Left            =   480
      TabIndex        =   6
      Top             =   3000
      Width           =   4335
   End
   Begin VB.Menu mImage
      Caption         =   "&Image"
      Begin VB.Menu mIOpen
         Caption         =   "&Open"
         Shortcut        =   ^O
      End
      Begin VB.Menu mISave
         Caption         =   "&Save"
         Shortcut        =   ^S
      End
      Begin VB.Menu mI_
         Caption         =   "-"
      End
      Begin VB.Menu mIClose
         Caption         =   "&Close"
      End
   End
   Begin VB.Menu mPicture
      Caption         =   "Picture"
      Begin VB.Menu mPChangeBack
         Caption         =   "&Change Image"
         Shortcut        =   ^B
      End
      Begin VB.Menu mPLevelize
         Caption         =   "&Levelize Image"
      End
      Begin VB.Menu mP_
         Caption         =   "-"
      End
      Begin VB.Menu mPBuildIMF
         Caption         =   "Build I&MF as..."
         Shortcut        =   {F7}
      End
      Begin VB.Menu mPHtmlMap
         Caption         =   "Generate &HTML-Map Code"
         Shortcut        =   {F8}
      End
   End
   Begin VB.Menu mObject
      Caption         =   "Object"
      Begin VB.Menu mOArrange
         Caption         =   "Arrange"
         Begin VB.Menu mOATop
            Caption         =   "Bring to top"
         End
         Begin VB.Menu mOAFront
            Caption         =   "Bring to front	Ctrl-PgUp"
         End
         Begin VB.Menu mOABack
            Caption         =   "Send to back	Ctrl-PgDn"
         End
         Begin VB.Menu mOABottom
            Caption         =   "Send to bottom"
         End
         Begin VB.Menu mOA_
            Caption         =   "-"
         End
         Begin VB.Menu mOALayer
            Caption         =   "Move to &layer"
         End
      End
      Begin VB.Menu mO_
         Caption         =   "-"
      End
      Begin VB.Menu mOPosAbs
         Caption         =   "Absolutely Position"
         Begin VB.Menu mOPA_S
            Caption         =   "By Scales"
         End
         Begin VB.Menu mOPA_P
            Caption         =   "By Pixels"
         End
      End
      Begin VB.Menu mOPosRel
         Caption         =   "Relative Position"
         Begin VB.Menu mOPR_SR
            Caption         =   "Scales to right"
         End
         Begin VB.Menu mOPR_PR
            Caption         =   "Pixels to right"
         End
         Begin VB.Menu mOPR_SB
            Caption         =   "Scales to bottom"
         End
         Begin VB.Menu mOPR_PB
            Caption         =   "Pixels to bottom"
         End
         Begin VB.Menu mOPR_SBR
            Caption         =   "Scales to bottom-right"
         End
         Begin VB.Menu mOPR_PBR
            Caption         =   "Pixels to bottom-right"
         End
      End
   End
   Begin VB.Menu mHelp
      Caption         =   "&Help"
      Begin VB.Menu mHManual
         Caption         =   "&Manual"
         Shortcut        =   {F1}
      End
      Begin VB.Menu mH_
         Caption         =   "-"
      End
      Begin VB.Menu mHAbout
         Caption         =   "&About"
         Shortcut        =   +{F1}
      End
   End
   Begin VB.Menu mLayers
      Caption         =   "&Layers"
      Begin VB.Menu mLCreate
         Caption         =   "&Create new layer"
      End
      Begin VB.Menu mL_
         Caption         =   "-"
      End
      Begin VB.Menu mLItem
         Caption         =   "Layer Name"
         Index           =   0
         Begin VB.Menu mLMoveUp
            Caption         =   "Move &Up"
         End
         Begin VB.Menu mLMoveDown
            Caption         =   "Move &Down"
         End
         Begin VB.Menu mLDelete
            Caption         =   "D&elete"
         End
      End
   End
   Begin VB.Menu mLayerObjects
      Caption         =   "Objects"
      Begin VB.Menu mOItem
         Caption         =   "Object Name"
         Index           =   0
      End
   End
End
Attribute VB_Name = "frmImageMarks"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Enum PositionModeConstants
    ABSOLUTE_SCALE = 0
    ABSOLUTE_PIXEL
    RELATIVE_SCALE_RIGHT
    RELATIVE_PIXEL_RIGHT
    RELATIVE_SCALE_BOTTOM
    RELATIVE_PIXEL_BOTTOM
    RELATIVE_SCALE_BOTTOMRIGHT
    RELATIVE_PIXEL_BOTTOMRIGHT
End Enum

Enum EventConstants
    EVENT_MOUSE_DOWN
    EVENT_MOUSE_MOVE
    EVENT_MOUSE_UP
    EVENT_CANCEL
End Enum


Public document As IMFDocument

Dim M_Back As CeICU1_Image

Dim st_lastx As Single, st_lasty As Single
Dim shapeArgs As ShapeType


Property Get PositionMode() As PositionModeConstants
    If mOPA_S.Checked Then PositionMode = ABSOLUTE_SCALE: Exit Property
    If mOPA_P.Checked Then PositionMode = ABSOLUTE_PIXEL: Exit Property
    If mOPR_SR.Checked Then PositionMode = RELATIVE_SCALE_RIGHT: Exit Property
    If mOPR_PR.Checked Then PositionMode = RELATIVE_PIXEL_RIGHT: Exit Property
    If mOPR_SB.Checked Then PositionMode = RELATIVE_SCALE_BOTTOM: Exit Property
    If mOPR_PB.Checked Then PositionMode = RELATIVE_PIXEL_BOTTOM: Exit Property
    If mOPR_SBR.Checked Then PositionMode = RELATIVE_SCALE_BOTTOMRIGHT: Exit Property
    If mOPR_PBR.Checked Then PositionMode = RELATIVE_PIXEL_BOTTOMRIGHT: Exit Property

    ' Default
    PositionMode = ABSOLUTE_SCALE
End Property

Property Let PositionMode(ByVal newMode As PositionModeConstants)
    mOPA_S.Checked = False
    mOPA_P.Checked = False
    mOPR_SR.Checked = False
    mOPR_PR.Checked = False
    mOPR_SB.Checked = False
    mOPR_PB.Checked = False
    mOPR_SBR.Checked = False
    mOPR_PBR.Checked = False

    Select Case newMode
    Case ABSOLUTE_SCALE: mOPA_S.Checked = True
    Case ABSOLUTE_PIXEL: mOPA_P.Checked = True
    Case RELATIVE_SCALE_RIGHT: mOPR_SR.Checked = True
    Case RELATIVE_PIXEL_RIGHT: mOPR_PR.Checked = True
    Case RELATIVE_SCALE_BOTTOM: mOPR_SB.Checked = True
    Case RELATIVE_PIXEL_BOTTOM: mOPR_PB.Checked = True
    Case RELATIVE_SCALE_BOTTOMRIGHT: mOPR_SBR.Checked = True
    Case RELATIVE_PIXEL_BOTTOMRIGHT: mOPR_PBR.Checked = True
    Case Else
        Err.Raise -1, , "Invalid position mode " & newMode
    End Select
End Property

Private Sub btnLayers_Click()
    PopupMenu mLayers, , btnLayers.left + btnLayers.width
End Sub

Private Sub btnObjects_Click()
    PopupMenu mLayerObjects, , btnObjects.left + btnObjects.width
End Sub

Private Sub btnRemove_Click()
    ' delete current selection
    document.State = NAVIGATE
End Sub

Private Sub Form_Load()
    mPicture.visible = False
    mObject.visible = False
    mLayers.visible = False
    mLayerObjects.visible = False
End Sub

Private Sub Form_Unload(Cancel As Integer)
    If document.Dirty Then
        Dim id As VbMsgBoxResult
        id = MsgBox("IMF changed, save before close? ", vbYesNoCancel, "Close")
        If id = vbCancel Then Cancel = True: Exit Sub
        If id = vbYes Then mISave_Click
    End If

    ' unload
End Sub

Private Sub mIClose_Click()
    Unload Me
End Sub

Private Sub mIOpen_Click()
    frmIMStudio.mIOpen_Click
End Sub

Private Sub mISave_Click()
    Dim path
    path = GetPathToSave("Save to file", "ImageMarks File (*.imf)|*.imf||")
    If path = CANCELED_STRING Then Exit Sub

    ' Save
    document.Dirty = False
End Sub

Private Sub mOPA_S_Click(): PositionMode = ABSOLUTE_SCALE: End Sub
Private Sub mOPA_P_Click(): PositionMode = ABSOLUTE_PIXEL: End Sub
Private Sub mOPR_SR_Click(): PositionMode = RELATIVE_SCALE_RIGHT: End Sub
Private Sub mOPR_PR_Click(): PositionMode = RELATIVE_PIXEL_RIGHT: End Sub
Private Sub mOPR_SB_Click(): PositionMode = RELATIVE_SCALE_BOTTOM: End Sub
Private Sub mOPR_PB_Click(): PositionMode = RELATIVE_PIXEL_BOTTOM: End Sub
Private Sub mOPR_SBR_Click(): PositionMode = RELATIVE_SCALE_BOTTOMRIGHT: End Sub
Private Sub mOPR_PBR_Click(): PositionMode = RELATIVE_PIXEL_BOTTOMRIGHT: End Sub


Private Sub btnAdd_Click()
    Dim shape As String
    shape = frmA1_SelectType.selectType
    If shape = "NONE" Then Exit Sub

    Select Case frmA1_SelectType.shape
    Case "RECT"
        shapeArgs.shape = shapeRectangle
        document.State = DRAW_RECT
    Case "ROUNDRECT"
        shapeArgs.shape = shapeRoundRectangle
        document.State = DRAW_ROUNDRECT
    Case "ELLIPSE"
        shapeArgs.shape = shapeEllipse
        document.State = DRAW_ELLIPSE
    Case "POLY"
        shapeArgs.shape = shapePolygon
        document.State = DRAW_POLYGON
    Case "COLOR"
        shapeArgs.shape = shapeColorRange
        document.State = DRAW_COLORRANGE
    Case Else
        CaAssert CaErrUnexpected
    End Select

    shapeArgs.isArray = frmA1_SelectType.chkArray
    If shapeArgs.isArray Then
        With frmA1_SelectType.array_info
            If .array_type = "MAT" Then
                shapeArgs.array = arrayMatrix
                shapeArgs.matRows = .mat_rows
                shapeArgs.matColumns = .mat_cols
                shapeArgs.matRowPadding = .mat_rowpad
                shapeArgs.matColumnPadding = .mat_colpad
            ElseIf .array_type = "RING" Then
                shapeArgs.array = arrayRing
                shapeArgs.ringNumber = .ring_number
                shapeArgs.ringStartAngle = .ring_start_angle
                shapeArgs.ringPadding = .ring_pad
            Else
                CaAssert CaErrUnexpected
            End If
        End With
        document.State = DRAW_ARRAY
    End If

End Sub

Private Sub btnPicture_Click()
    PopupMenu mPicture, , _
        btnPicture.left + btnPicture.width, btnPicture.top
End Sub

Private Sub Form_Resize()
    If Me.WindowState = vbMinimized Then Exit Sub

    On Error Resume Next

    Dim W, H

    lblInfo.left = 0
    lblInfo.width = Me.ScaleWidth
    lblInfo.top = Me.ScaleHeight - lblInfo.height

    H = Me.ScaleHeight - lblInfo.height - 50
    H = (H - btnPicture.height * 3) / 2
    btnPicture.left = 20
    btnPicture.top = 25
    btnLayers.left = btnPicture.left
    btnLayers.top = btnPicture.top + btnPicture.height + H
    btnObjects.left = btnPicture.left
    btnObjects.top = btnLayers.top + btnLayers.height + H
    btnAdd.left = Me.ScaleWidth - btnAdd.width - 20
    btnAdd.top = btnPicture.top
    btnRemove.left = btnAdd.left
    btnRemove.top = btnLayers.top
    btnProperties.left = btnAdd.left
    btnProperties.top = btnObjects.top

    H = Me.ScaleHeight - lblInfo.height
    W = btnAdd.left - (btnPicture.left + btnPicture.width) - 20 * 2

    P.left = btnPicture.left + btnPicture.width + 20 + (W - P.width) / 2
    P.top = (H - P.height) / 2

End Sub

Public Sub SetImage(picture As IPictureDisp)
    Dim e As CaError

    Set P0.picture = picture

    CaAssert GetBitsFromHDC(P0.hDC, M_Back, 0, 0, P0.ScaleWidth, P0.ScaleHeight, CaTrue)

    P.width = P0.width
    P.height = P0.height

    Dim moreW, moreH
    moreW = Me.width / Screen.TwipsPerPixelX - Me.ScaleWidth
    moreH = Me.height / Screen.TwipsPerPixelY - Me.ScaleHeight

    Me.width = (moreW + P.width + btnPicture.width * 2 + 20 * 4) * Screen.TwipsPerPixelX

    If P.height > btnPicture.height * 3 Then
        Me.height = (moreH + P.height + 20 * 2 + lblInfo.height) * Screen.TwipsPerPixelY
    Else
        Me.height = (moreH + btnPicture.height * 3 + 20 * 2 + lblInfo.height) * Screen.TwipsPerPixelY
    End If

    Repaint
End Sub

Public Sub RepaintSpec(image As CeICU1_Image)
    CaAssert StretchToHDC(P.hDC, 0, 0, P.ScaleWidth, P.ScaleHeight, _
        0, 0, image.width, image.height, image, CaTrue)

    P.Refresh
End Sub

Public Sub Repaint()
    CaAssert StretchToHDC(P.hDC, 0, 0, P.ScaleWidth, P.ScaleHeight, _
        0, 0, M_Back.width, M_Back.height, M_Back, CaTrue)

    P.Refresh
End Sub

Sub info(ByVal str As String)
    lblInfo.Caption = str
End Sub

Private Sub mPChangeBack_Click()
    Dim path As String
    path = GetPathToOpen("Select image file to open", _
            "All image files (*.jpg, *.bmp, *.gif, *.wmf)|*.jpg;*.bmp;*.gif;*.wmf|" + _
            "JPEG Image (*.jpg)|*.jpg|Bitmap (*.bmp)|*.bmp|GIF Image (*.gif)|*.gif|Windows Meta-File (*.wmf)|*.wmf|All files (*.*)|*.*||")
    If path = CANCELED_STRING Then Exit Sub

    On Error GoTo epic
    SetImage LoadPicture(path)
    Exit Sub
epic:
    MsgBox "Invalid image file: " + Err.Description, vbExclamation
End Sub

Private Sub mPLevelize_Click()
    frmLevelizeAdjust.DoAdjust M_Back, P
End Sub

Private Sub P_KeyDown(KeyCode As Integer, Shift As Integer)
    Select Case KeyCode
    Case vbKeyDelete
        '        delete current selection
        btnRemove_Click
    Case vbKeyInsert
        '        add new object
        btnAdd_Click
    Case vbKeyLeft, vbKeyRight, vbKeyUp, vbKeyDown
        '        select object around current selection
        ' shift- move current selection by small unit
    Case vbKeyPageUp, vbKeyPageDown
        '        switch to up/down page
        ' shift- move current selection to up/down page
    End Select
End Sub

Private Sub P_KeyPress(KeyAscii As Integer)
    Dim button As Integer, Shift As Integer, x As Single, y As Single

    If KeyAscii = 27 Then 'Escape
        Select Case document.State
        Case SELECTING
            document.State = NAVIGATE
            If Not document.Selection Is Nothing Then
                If document.Selection.Count > 0 Then
                    document.State = Selected
                End If
            End If
        Case Selected
            Set document.Selection = Nothing
            document.State = NAVIGATE
        Case MOVING
            document.State = Selected
        Case SIZING
            document.State = Selected

        Case DRAW_ARRAY
            DrawArray EVENT_CANCEL, button, Shift, x, y
            document.State = NAVIGATE
        Case DRAW_RECT
            DrawRect EVENT_CANCEL, button, Shift, x, y
            document.State = NAVIGATE
        Case DRAW_ROUNDRECT
            DrawRoundRect EVENT_CANCEL, button, Shift, x, y
            document.State = NAVIGATE
        Case DRAW_ELLIPSE
            DrawEllipse EVENT_CANCEL, button, Shift, x, y
            document.State = NAVIGATE
        Case DRAW_POLYGON
            DrawPolygon EVENT_CANCEL, button, Shift, x, y
            document.State = NAVIGATE
        Case DRAW_COLORRANGE
            DrawColorRange EVENT_CANCEL, button, Shift, x, y
            document.State = NAVIGATE

        Case NAVIGATE
        Case Else
            CaAssert CaErrUnexpected
        End Select
    End If
End Sub

Private Sub P_MouseDown(button As Integer, Shift As Integer, x As Single, y As Single)
    Select Case document.State
    Case NAVIGATE
        document.State = SELECTING
    Case DRAW_ARRAY
        DrawArray EVENT_MOUSE_DOWN, button, Shift, x, y
    Case DRAW_RECT
        DrawRect EVENT_MOUSE_DOWN, button, Shift, x, y
    Case DRAW_ROUNDRECT
        DrawRoundRect EVENT_MOUSE_DOWN, button, Shift, x, y
    Case DRAW_ELLIPSE
        DrawEllipse EVENT_MOUSE_DOWN, button, Shift, x, y
    Case DRAW_POLYGON
        DrawPolygon EVENT_MOUSE_DOWN, button, Shift, x, y
    Case DRAW_COLORRANGE
        DrawColorRange EVENT_MOUSE_DOWN, button, Shift, x, y
    Case Selected
        If Shift And vbShiftMask Then
            ' union/xor/clear depends on shift of MouseUp
            document.State = SELECTING
        ElseIf Shift And vbCtrlMask Then
            ' union/xor/clear depends on shift of MouseUp
            document.State = SELECTING
        Else
            ' if click on body
                document.State = MOVING
            ' elseif click on border
                document.State = SIZING
            ' else: click outside
                ' clear last selection
                document.Selection = New Collection
                document.State = SELECTING
            ' end if
        End If

    Case SELECTING
    Case MOVING
    Case SIZING
    Case Else
        CaAssert CaErrUnexpected
    End Select

    st_lastx = x
    st_lasty = y
End Sub

Private Sub P_MouseMove(button As Integer, Shift As Integer, x As Single, y As Single)
    Select Case document.State
    Case NAVIGATE
        ' highlight
    Case SELECTING
        ' dragging
    Case DRAW_ARRAY
        DrawArray EVENT_MOUSE_MOVE, button, Shift, x, y
    Case DRAW_RECT
        DrawRect EVENT_MOUSE_MOVE, button, Shift, x, y
    Case DRAW_ROUNDRECT
        DrawRoundRect EVENT_MOUSE_MOVE, button, Shift, x, y
    Case DRAW_ELLIPSE
        DrawEllipse EVENT_MOUSE_MOVE, button, Shift, x, y
    Case DRAW_POLYGON
        DrawPolygon EVENT_MOUSE_MOVE, button, Shift, x, y
    Case DRAW_COLORRANGE
        DrawColorRange EVENT_MOUSE_MOVE, button, Shift, x, y

    Case MOVING
        ' moving
    Case SIZING
        ' sizing

    Case Selected
    Case Else
        CaAssert CaErrUnexpected
    End Select
End Sub

Private Sub P_MouseUp(button As Integer, Shift As Integer, x As Single, y As Single)
    Select Case document.State
    Case SELECTING
        If Shift And vbShiftMask Then
            ' union to selection
        ElseIf Shift And vbCtrlMask Then
            ' xor to selection
        Else
            ' clear last selection
            Set document.Selection = New Collection
        End If
    Case DRAW_ARRAY
        DrawArray EVENT_MOUSE_UP, button, Shift, x, y
    Case DRAW_RECT
        DrawRect EVENT_MOUSE_UP, button, Shift, x, y
    Case DRAW_ROUNDRECT
        DrawRoundRect EVENT_MOUSE_UP, button, Shift, x, y
    Case DRAW_ELLIPSE
        DrawEllipse EVENT_MOUSE_UP, button, Shift, x, y
    Case DRAW_POLYGON
        DrawPolygon EVENT_MOUSE_UP, button, Shift, x, y
    Case DRAW_COLORRANGE
        DrawColorRange EVENT_MOUSE_UP, button, Shift, x, y
    Case MOVING
        ' moved
        document.State = Selected
    Case SIZING
        ' sized
        document.State = Selected

    Case NAVIGATE
    Case Selected
    End Select
End Sub

Sub DrawArray(ByVal eventType As EventConstants, button As Integer, Shift As Integer, x As Single, y As Single)
    Select Case eventType
    Case EVENT_MOUSE_UP
        Select Case shapeArgs.shape
        Case shapeRectangle
            document.State = DRAW_RECT
        Case shapeRoundRectangle
            document.State = DRAW_ROUNDRECT
        Case shapeEllipse
            document.State = DRAW_ELLIPSE
        Case shapePolygon
            document.State = DRAW_POLYGON
        Case shapeColorRange
            document.State = DRAW_COLORRANGE
        End Select
    End Select
End Sub

Sub DrawRect(ByVal eventType As EventConstants, button As Integer, Shift As Integer, x As Single, y As Single)

End Sub

Sub DrawRoundRect(ByVal eventType As EventConstants, button As Integer, Shift As Integer, x As Single, y As Single)

End Sub

Sub DrawEllipse(ByVal eventType As EventConstants, button As Integer, Shift As Integer, x As Single, y As Single)

End Sub

Sub DrawPolygon(ByVal eventType As EventConstants, button As Integer, Shift As Integer, x As Single, y As Single)

End Sub

Sub DrawColorRange(ByVal eventType As EventConstants, button As Integer, Shift As Integer, x As Single, y As Single)

End Sub
