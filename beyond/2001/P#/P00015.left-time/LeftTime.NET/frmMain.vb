Option Strict Off
Option Explicit On
Friend Class frmMain
	Inherits System.Windows.Forms.Form
#Region "Windows 窗体设计器生成的代码"
	Public Sub New()
		MyBase.New()
		If m_vb6FormDefInstance Is Nothing Then
			If m_InitializingDefInstance Then
				m_vb6FormDefInstance = Me
			Else
				Try
					'对于启动窗体，所创建的第一个实例为默认实例。
					If System.Reflection.Assembly.GetExecutingAssembly.EntryPoint.DeclaringType Is Me.GetType Then
						m_vb6FormDefInstance = Me
					End If
				Catch
				End Try
			End If
		End If
		'此调用是 Windows 窗体设计器所必需的。
		InitializeComponent()
	End Sub
	'窗体重写处置，以清理组件列表。
	Protected Overloads Overrides Sub Dispose(ByVal Disposing As Boolean)
		If Disposing Then
			If Not components Is Nothing Then
				components.Dispose()
			End If
		End If
		MyBase.Dispose(Disposing)
	End Sub
	'Windows 窗体设计器所必需的
	Private components As System.ComponentModel.IContainer
	Public ToolTip1 As System.Windows.Forms.ToolTip
	Public WithEvents t As System.Windows.Forms.Timer
	Public WithEvents l As System.Windows.Forms.Label
	'注意：以下过程是 Windows 窗体设计器所必需的
	'可以使用 Windows 窗体设计器来修改它。
	'不要使用代码编辑器来修改它。
	<System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
		Dim resources As System.Resources.ResourceManager = New System.Resources.ResourceManager(GetType(frmMain))
		Me.components = New System.ComponentModel.Container()
		Me.ToolTip1 = New System.Windows.Forms.ToolTip(components)
		Me.ToolTip1.Active = True
		Me.t = New System.Windows.Forms.Timer(components)
		Me.l = New System.Windows.Forms.Label
		Me.BackColor = System.Drawing.Color.Black
		Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
		Me.Text = "Left Time"
		Me.ClientSize = New System.Drawing.Size(112, 19)
		Me.Location = New System.Drawing.Point(10, 29)
		Me.ControlBox = False
		Me.MaximizeBox = False
		Me.MinimizeBox = False
		Me.ShowInTaskbar = False
		Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent
		Me.AutoScaleBaseSize = New System.Drawing.Size(6, 14)
		Me.Enabled = True
		Me.KeyPreview = False
		Me.Cursor = System.Windows.Forms.Cursors.Default
		Me.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.HelpButton = False
		Me.WindowState = System.Windows.Forms.FormWindowState.Normal
		Me.Name = "frmMain"
		Me.t.Interval = 250
		Me.t.Enabled = True
		Me.l.BackColor = System.Drawing.Color.Transparent
		Me.l.Text = "00"
		Me.l.Font = New System.Drawing.Font("Times New Roman", 24!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
		Me.l.ForeColor = System.Drawing.Color.White
		Me.l.Size = New System.Drawing.Size(32, 36)
		Me.l.Location = New System.Drawing.Point(0, 0)
		Me.l.TabIndex = 0
		Me.ToolTip1.SetToolTip(Me.l, "双击退出,左右键调整大小")
		Me.l.TextAlign = System.Drawing.ContentAlignment.TopLeft
		Me.l.Enabled = True
		Me.l.Cursor = System.Windows.Forms.Cursors.Default
		Me.l.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.l.UseMnemonic = True
		Me.l.Visible = True
		Me.l.AutoSize = True
		Me.l.BorderStyle = System.Windows.Forms.BorderStyle.None
		Me.l.Name = "l"
		Me.Controls.Add(l)
	End Sub
#End Region
#Region "升级支持"
	Private Shared m_vb6FormDefInstance As frmMain
	Private Shared m_InitializingDefInstance As Boolean
	Public Shared Property DefInstance() As frmMain
		Get
			If m_vb6FormDefInstance Is Nothing OrElse m_vb6FormDefInstance.IsDisposed Then
				m_InitializingDefInstance = True
				m_vb6FormDefInstance = New frmMain()
				m_InitializingDefInstance = False
			End If
			DefInstance = m_vb6FormDefInstance
		End Get
		Set
			m_vb6FormDefInstance = Value
		End Set
	End Property
#End Region

	Public To_Time As Object
	Public cIntFormat As Object
	Public cIntK As Double
	Public d_x, d_y As Object

	Public app_name As Object
	Public lastappname As Object

	Public bMsged As Boolean

	Public Sub quit()
		'UPGRADE_WARNING: 未能解析对象 lastappname 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		SaveSetting("LeftTime", "_Global", "LastAppName", lastappname)
		'UPGRADE_WARNING: 未能解析对象 lastappname 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		SaveSetting("LeftTime", "_Recent", lastappname, CStr(System.Date.FromOADate(Today.ToOADate + TimeOfDay.ToOADate)))

		'UPGRADE_WARNING: 未能解析对象 To_Time 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		SaveSetting(app_name, "Options", "To_Time", To_Time)
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		SaveSetting(app_name, "Options", "Repeat", CStr(frmSet.DefInstance.cAfter.CheckState))
		'UPGRADE_WARNING: 未能解析对象 cIntFormat 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		SaveSetting(app_name, "Options", "cIntFormat", cIntFormat)
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		SaveSetting(app_name, "Options", "cIntK", CStr(cIntK))
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		SaveSetting(app_name, "frmSet", "lstInt", CStr(frmSet.DefInstance.lstInt.SelectedIndex))
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		SaveSetting(app_name, "frmSet", "tToTime", frmSet.DefInstance.tToTime.Text)
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		SaveSetting(app_name, "frmSet", "tAfter", frmSet.DefInstance.tAfter.Text)
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		SaveSetting(app_name, "Options", "FontSize", CStr(l.Font.SizeInPoints))
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		SaveSetting(app_name, "Options", "Left", CStr(VB6.PixelsToTwipsX(Left)))
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		SaveSetting(app_name, "Options", "Top", CStr(VB6.PixelsToTwipsY(Top)))
		End
	End Sub

	'UPGRADE_WARNING: Form 事件 frmMain.Activate 具有新的行为。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup2065"'
	Private Sub frmMain_Activated(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Activated
		Dim ll, tt As Object
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		'UPGRADE_WARNING: 未能解析对象 ll 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		ll = GetSetting(app_name, "Options", "Left", CStr(-1000))
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		'UPGRADE_WARNING: 未能解析对象 tt 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		tt = GetSetting(app_name, "Options", "Top", CStr(-1000))
		'UPGRADE_WARNING: 未能解析对象 tt 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		'UPGRADE_WARNING: 未能解析对象 ll 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		If ll > -1000 And tt > -1000 Then
			'UPGRADE_WARNING: 未能解析对象 ll 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
			Left = VB6.TwipsToPixelsX(ll)
			'UPGRADE_WARNING: 未能解析对象 tt 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
			Top = VB6.TwipsToPixelsY(tt)
		End If
	End Sub

	Private Sub frmMain_KeyDown(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.KeyEventArgs) Handles MyBase.KeyDown
		Dim KeyCode As Short = eventArgs.KeyCode
		Dim Shift As Short = eventArgs.KeyData \ &H10000
		If KeyCode = 37 Then
			If l.Font.SizeInPoints > 3 Then l.Font = VB6.FontChangeSize(l.Font, l.Font.SizeInPoints - 1)
		ElseIf KeyCode = 39 Then
			If l.Font.SizeInPoints < 1000 Then l.Font = VB6.FontChangeSize(l.Font, l.Font.SizeInPoints + 1)
		Else
			Exit Sub
		End If
		'UPGRADE_WARNING: Label 事件 l.Change 未升级。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup2050"'
		l_Change()
	End Sub

	Private Sub frmMain_Load(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Load
		'UPGRADE_ISSUE: 不支持 Load 语句。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1039"'
		Load(frmSet)

		'UPGRADE_WARNING: 未能解析对象 lastappname 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		app_name = "LeftTime\" & lastappname

		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		'UPGRADE_WARNING: 未能解析对象 To_Time 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		To_Time = CDate(GetSetting(app_name, "Options", "To_Time", CStr(System.Date.FromOADate(Today.ToOADate + TimeOfDay.ToOADate + CDate("0:1:0").ToOADate))))
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		'UPGRADE_WARNING: 未能解析对象 cIntFormat 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		cIntFormat = GetSetting(app_name, "Options", "cIntFormat", "s")
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		cIntK = CDbl(GetSetting(app_name, "Options", "cIntK", CStr(1)))
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		frmSet.DefInstance.lstInt.SelectedIndex = GetSetting(app_name, "frmSet", "lstInt", CStr(8))
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		frmSet.DefInstance.tToTime.Text = GetSetting(app_name, "frmSet", "tToTime", CStr(DateAdd(Microsoft.VisualBasic.DateInterval.Second, 60, System.Date.FromOADate(Today.ToOADate + TimeOfDay.ToOADate))))
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		frmSet.DefInstance.tAfter.Text = GetSetting(app_name, "frmSet", "tAfter", "60 s")
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		frmSet.DefInstance.cAfter.CheckState = CShort(GetSetting(app_name, "Options", "Repeat", CStr(0)))
		'UPGRADE_WARNING: 未能解析对象 app_name 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		l.Font = VB6.FontChangeSize(l.Font, CDec(GetSetting(app_name, "Options", "FontSize", CStr(32))))
		SetTopMostWindow(Me.Handle.ToInt32, True)
	End Sub

	Private Sub frmMain_MouseDown(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.MouseEventArgs) Handles MyBase.MouseDown
		Dim Button As Short = eventArgs.Button \ &H100000
		Dim Shift As Short = System.Windows.Forms.Control.ModifierKeys \ &H10000
		Dim x As Single = VB6.PixelsToTwipsX(eventArgs.X)
		Dim y As Single = VB6.PixelsToTwipsY(eventArgs.Y)
		'UPGRADE_WARNING: 未能解析对象 d_x 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		d_x = x
		'UPGRADE_WARNING: 未能解析对象 d_y 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		d_y = y
	End Sub

	Private Sub frmMain_MouseMove(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.MouseEventArgs) Handles MyBase.MouseMove
		Dim Button As Short = eventArgs.Button \ &H100000
		Dim Shift As Short = System.Windows.Forms.Control.ModifierKeys \ &H10000
		Dim x As Single = VB6.PixelsToTwipsX(eventArgs.X)
		Dim y As Single = VB6.PixelsToTwipsY(eventArgs.Y)
		If Button And VB6.MouseButtonConstants.LeftButton Then
			'UPGRADE_WARNING: 未能解析对象 d_x 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
			Left = VB6.TwipsToPixelsX(VB6.PixelsToTwipsX(Left) + x - d_x)
			'UPGRADE_WARNING: 未能解析对象 d_y 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
			Top = VB6.TwipsToPixelsY(VB6.PixelsToTwipsY(Top) + y - d_y)
		End If
	End Sub

	'UPGRADE_WARNING: Form 事件 frmMain.Unload 具有新的行为。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup2065"'
	Private Sub frmMain_Closed(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Closed
		quit()
	End Sub

	'UPGRADE_WARNING: Label 事件 l.Change 未升级。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup2050"'
	Private Sub l_Change()
		If VB6.PixelsToTwipsX(l.Width) <> VB6.PixelsToTwipsX(Me.Width) Then
			Me.Width = l.Width
		End If
		If VB6.PixelsToTwipsY(l.Height) <> VB6.PixelsToTwipsY(Me.Height) Then
			Me.Height = l.Height
		End If
	End Sub

	Private Sub l_DoubleClick(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles l.DoubleClick
		quit()
	End Sub

	Private Sub l_MouseDown(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.MouseEventArgs) Handles l.MouseDown
		Dim Button As Short = eventArgs.Button \ &H100000
		Dim Shift As Short = System.Windows.Forms.Control.ModifierKeys \ &H10000
		Dim x As Single = VB6.PixelsToTwipsX(eventArgs.X)
		Dim y As Single = VB6.PixelsToTwipsY(eventArgs.Y)
		If Button And VB6.MouseButtonConstants.LeftButton Then
			frmMain_MouseDown(Me, New System.Windows.Forms.MouseEventArgs(Button * &H100000, 0, VB6.TwipsToPixelsX(x), VB6.TwipsToPixelsY(y), 0))
		End If
		If Button And VB6.MouseButtonConstants.RightButton Then
			If VB6.PixelsToTwipsX(Left) + VB6.PixelsToTwipsX(frmSet.DefInstance.Width) > VB6.PixelsToTwipsX(System.Windows.Forms.Screen.PrimaryScreen.Bounds.Width) Then
				frmSet.DefInstance.Left = VB6.TwipsToPixelsX(VB6.PixelsToTwipsX(Left) - VB6.PixelsToTwipsX(frmSet.DefInstance.Width))
			ElseIf VB6.PixelsToTwipsX(Left) + VB6.PixelsToTwipsX(Width) + VB6.PixelsToTwipsX(frmSet.DefInstance.Width) < VB6.PixelsToTwipsX(System.Windows.Forms.Screen.PrimaryScreen.Bounds.Width) Then
				frmSet.DefInstance.Left = VB6.TwipsToPixelsX(VB6.PixelsToTwipsX(Left) + VB6.PixelsToTwipsX(Width))
			Else
				frmSet.DefInstance.Left = Left
			End If
			If VB6.PixelsToTwipsX(frmSet.DefInstance.Left) <> VB6.PixelsToTwipsX(Left) Then
				frmSet.DefInstance.Top = Top
			Else
				frmSet.DefInstance.Top = VB6.TwipsToPixelsY(VB6.PixelsToTwipsY(Top) + VB6.PixelsToTwipsY(Height))
			End If
			frmSet.DefInstance.ShowDialog()
			bMsged = False
		End If
	End Sub

	Private Sub l_MouseMove(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.MouseEventArgs) Handles l.MouseMove
		Dim Button As Short = eventArgs.Button \ &H100000
		Dim Shift As Short = System.Windows.Forms.Control.ModifierKeys \ &H10000
		Dim x As Single = VB6.PixelsToTwipsX(eventArgs.X)
		Dim y As Single = VB6.PixelsToTwipsY(eventArgs.Y)
		frmMain_MouseMove(Me, New System.Windows.Forms.MouseEventArgs(Button * &H100000, 0, VB6.TwipsToPixelsX(x), VB6.TwipsToPixelsY(y), 0))
	End Sub

	Private Sub t_Tick(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles t.Tick
		'UPGRADE_WARNING: 未能解析对象 To_Time 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		l.Text = CStr(Int(DateDiff(CStr(cIntFormat), System.Date.FromOADate(Today.ToOADate + TimeOfDay.ToOADate), To_Time) / cIntK))
		If CDbl(l.Text) < 0 Then
			If Not bMsged Then
				MsgBox(frmSet.DefInstance.tProjectName.Text & " timeout.", MsgBoxStyle.OKOnly, frmSet.DefInstance.tProjectName.Text)
				bMsged = True

				If frmSet.DefInstance.cAfter.CheckState = 1 Then
					frmSet.DefInstance.cAfter_CheckStateChanged(frmSet.DefInstance.cAfter, New System.EventArgs())
					bMsged = False
				End If
			End If
		End If
	End Sub
End Class