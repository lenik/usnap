Option Strict Off
Option Explicit On
Imports VB = Microsoft.VisualBasic
Friend Class frmSelectProject
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
	Public WithEvents cboList As System.Windows.Forms.ComboBox
	Public WithEvents Label1 As System.Windows.Forms.Label
	'注意：以下过程是 Windows 窗体设计器所必需的
	'可以使用 Windows 窗体设计器来修改它。
	'不要使用代码编辑器来修改它。
	<System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
		Dim resources As System.Resources.ResourceManager = New System.Resources.ResourceManager(GetType(frmSelectProject))
		Me.components = New System.ComponentModel.Container()
		Me.ToolTip1 = New System.Windows.Forms.ToolTip(components)
		Me.ToolTip1.Active = True
		Me.cboList = New System.Windows.Forms.ComboBox
		Me.Label1 = New System.Windows.Forms.Label
		Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog
		Me.Text = "New/Open LeftTime Project"
		Me.ClientSize = New System.Drawing.Size(348, 217)
		Me.Location = New System.Drawing.Point(3, 22)
		Me.MaximizeBox = False
		Me.MinimizeBox = False
		Me.ShowInTaskbar = False
		Me.StartPosition = System.Windows.Forms.FormStartPosition.WindowsDefaultLocation
		Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
		Me.BackColor = System.Drawing.SystemColors.Control
		Me.ControlBox = True
		Me.Enabled = True
		Me.KeyPreview = False
		Me.Cursor = System.Windows.Forms.Cursors.Default
		Me.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.HelpButton = False
		Me.WindowState = System.Windows.Forms.FormWindowState.Normal
		Me.Name = "frmSelectProject"
		Me.cboList.Size = New System.Drawing.Size(307, 144)
		Me.cboList.Location = New System.Drawing.Point(18, 48)
		Me.cboList.DropDownStyle = System.Windows.Forms.ComboBoxStyle.Simple
		Me.cboList.TabIndex = 0
		Me.cboList.Text = "-"
		Me.cboList.BackColor = System.Drawing.SystemColors.Window
		Me.cboList.CausesValidation = True
		Me.cboList.Enabled = True
		Me.cboList.ForeColor = System.Drawing.SystemColors.WindowText
		Me.cboList.IntegralHeight = True
		Me.cboList.Cursor = System.Windows.Forms.Cursors.Default
		Me.cboList.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.cboList.Sorted = False
		Me.cboList.TabStop = True
		Me.cboList.Visible = True
		Me.cboList.Name = "cboList"
		Me.Label1.Text = "Select an existed project or, create a new project by entering the project name in the project name textbox: "
		Me.Label1.Size = New System.Drawing.Size(308, 43)
		Me.Label1.Location = New System.Drawing.Point(19, 9)
		Me.Label1.TabIndex = 1
		Me.Label1.TextAlign = System.Drawing.ContentAlignment.TopLeft
		Me.Label1.BackColor = System.Drawing.SystemColors.Control
		Me.Label1.Enabled = True
		Me.Label1.ForeColor = System.Drawing.SystemColors.ControlText
		Me.Label1.Cursor = System.Windows.Forms.Cursors.Default
		Me.Label1.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.Label1.UseMnemonic = True
		Me.Label1.Visible = True
		Me.Label1.AutoSize = False
		Me.Label1.BorderStyle = System.Windows.Forms.BorderStyle.None
		Me.Label1.Name = "Label1"
		Me.Controls.Add(cboList)
		Me.Controls.Add(Label1)
	End Sub
#End Region
#Region "升级支持"
	Private Shared m_vb6FormDefInstance As frmSelectProject
	Private Shared m_InitializingDefInstance As Boolean
	Public Shared Property DefInstance() As frmSelectProject
		Get
			If m_vb6FormDefInstance Is Nothing OrElse m_vb6FormDefInstance.IsDisposed Then
				m_InitializingDefInstance = True
				m_vb6FormDefInstance = New frmSelectProject()
				m_InitializingDefInstance = False
			End If
			DefInstance = m_vb6FormDefInstance
		End Get
		Set
			m_vb6FormDefInstance = Value
		End Set
	End Property
#End Region

	'UPGRADE_WARNING: ComboBox 事件 cboList.DblClick 未升级。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup2050"'
	Private Sub cboList_DblClick()
		If cboList.Text = "" Then cboList.Text = "Noname project # " & System.Date.FromOADate(Today.ToOADate + TimeOfDay.ToOADate)
		'UPGRADE_WARNING: 未能解析对象 frmMain.lastappname 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		frmMain.DefInstance.lastappname = cboList.Text
		'UPGRADE_WARNING: 未能解析对象 frmMain.lastappname 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		frmMain.DefInstance.ToolTip1.SetToolTip(frmMain.DefInstance.l, frmMain.DefInstance.lastappname & " : " & frmMain.DefInstance.ToolTip1.GetToolTip(frmMain.DefInstance.l))

		Me.Hide()
		frmMain.DefInstance.Show()
	End Sub

	Private Sub cboList_KeyPress(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.KeyPressEventArgs) Handles cboList.KeyPress
		Dim KeyAscii As Short = Asc(eventArgs.KeyChar)
		If KeyAscii = 13 Then
			KeyAscii = 0
			'UPGRADE_WARNING: ComboBox 事件 cboList.DblClick 未升级。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup2050"'
			cboList_DblClick()
		End If
		If KeyAscii = 0 Then
			eventArgs.Handled = True
		End If
	End Sub

	Private Sub frmSelectProject_Load(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Load
		Dim lastlist As Object

		'UPGRADE_WARNING: 未能解析对象 lastlist 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		lastlist = GetAllSettings("LeftTime", "_Recent")

		cboList.Items.Clear()
		'UPGRADE_WARNING: IsEmpty 已升级到 IsNothing 并具有新行为。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1041"'
		Dim i As Object
		Dim ds, dt As Object
		Dim j As Object
		Dim insert_before As Boolean
		If Not IsNothing(lastlist) Then
			For i = LBound(lastlist) To UBound(lastlist)
				'UPGRADE_WARNING: 未能解析对象 lastlist() 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
				'UPGRADE_WARNING: 未能解析对象 ds 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
				ds = lastlist(i, 0)
				'UPGRADE_WARNING: 未能解析对象 lastlist() 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
				'UPGRADE_WARNING: 未能解析对象 dt 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
				dt = lastlist(i, 1)
				'UPGRADE_WARNING: 未能解析对象 dt 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
				If dt <> "" Then
					'UPGRADE_WARNING: 未能解析对象 dt 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
					dt = DateDiff(Microsoft.VisualBasic.DateInterval.Second, CDate(dt), System.Date.FromOADate(Today.ToOADate + TimeOfDay.ToOADate))
				Else
					'UPGRADE_WARNING: 未能解析对象 dt 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
					dt = 0
				End If

				insert_before = False
				'UPGRADE_WARNING: 未能解析对象 dt 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
				If dt <> 0 Then
					For j = 0 To cboList.Items.Count - 1
						'UPGRADE_WARNING: 未能解析对象 dt 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
						If dt < VB6.GetItemData(cboList, j) Then
							insert_before = True
							Exit For
						End If
					Next
				End If
				If insert_before Then
					'UPGRADE_WARNING: 未能解析对象 ds 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
					cboList.Items.Insert(j, ds)
					'UPGRADE_WARNING: 未能解析对象 dt 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
					VB6.SetItemData(cboList, j, dt)
				Else
					'UPGRADE_WARNING: 未能解析对象 ds 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
					cboList.Items.Add(ds)
					'UPGRADE_WARNING: 未能解析对象 dt 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
					VB6.SetItemData(cboList, i, dt)
				End If
			Next
		End If

		If VB.Command() <> "" Then
			cboList.Text = VB.Command()
		Else
			cboList.Text = GetSetting("LeftTime", "_Global", "LastAppName", "My First LeftTime Project")
		End If
	End Sub

	'UPGRADE_WARNING: Form 事件 frmSelectProject.QueryUnload 具有新的行为。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup2065"'
	Private Sub frmSelectProject_Closing(ByVal eventSender As System.Object, ByVal eventArgs As System.ComponentModel.CancelEventArgs) Handles MyBase.Closing
		Dim Cancel As Short = eventArgs.Cancel
		On Error GoTo x
		'UPGRADE_WARNING: ComboBox 事件 cboList.DblClick 未升级。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup2050"'
		cboList_DblClick()
		GoTo EventExitSub
x:
		Cancel = 1
EventExitSub:
		eventArgs.Cancel = Cancel
	End Sub
End Class