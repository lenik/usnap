Option Strict Off
Option Explicit On
Friend Class frmSet
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
	Public WithEvents cAfter As System.Windows.Forms.CheckBox
	Public WithEvents tInt As System.Windows.Forms.TextBox
	Public WithEvents tProjectName As System.Windows.Forms.TextBox
	Public WithEvents lstInt As System.Windows.Forms.ComboBox
	Public WithEvents cCalc As System.Windows.Forms.Button
	Public WithEvents cCurrent As System.Windows.Forms.Button
	Public WithEvents tAfter As System.Windows.Forms.TextBox
	Public WithEvents tToTime As System.Windows.Forms.TextBox
	Public WithEvents cToTime As System.Windows.Forms.Button
	Public WithEvents m60s As System.Windows.Forms.MenuItem
	Public WithEvents m5m As System.Windows.Forms.MenuItem
	Public WithEvents m10m As System.Windows.Forms.MenuItem
	Public WithEvents m30m As System.Windows.Forms.MenuItem
	Public WithEvents m1h As System.Windows.Forms.MenuItem
	Public WithEvents m1h2 As System.Windows.Forms.MenuItem
	Public WithEvents m2h As System.Windows.Forms.MenuItem
	Public WithEvents m3h As System.Windows.Forms.MenuItem
	Public WithEvents m5h As System.Windows.Forms.MenuItem
	Public WithEvents m1d As System.Windows.Forms.MenuItem
	Public WithEvents m2d As System.Windows.Forms.MenuItem
	Public WithEvents m3d As System.Windows.Forms.MenuItem
	Public WithEvents m1w As System.Windows.Forms.MenuItem
	Public WithEvents m2w As System.Windows.Forms.MenuItem
	Public WithEvents m30d As System.Windows.Forms.MenuItem
	Public WithEvents m1y As System.Windows.Forms.MenuItem
	Public WithEvents mPredefinedPeriod As System.Windows.Forms.MenuItem
	Public WithEvents mTo8h As System.Windows.Forms.MenuItem
	Public WithEvents mTo9h As System.Windows.Forms.MenuItem
	Public WithEvents mTo12h As System.Windows.Forms.MenuItem
	Public WithEvents mTo18h As System.Windows.Forms.MenuItem
	Public WithEvents mTo20h As System.Windows.Forms.MenuItem
	Public WithEvents mTo21h As System.Windows.Forms.MenuItem
	Public WithEvents mTo22h As System.Windows.Forms.MenuItem
	Public WithEvents mTo24h As System.Windows.Forms.MenuItem
	Public WithEvents mToSaturday As System.Windows.Forms.MenuItem
	Public WithEvents mToSunday As System.Windows.Forms.MenuItem
	Public WithEvents mToMonthEnd As System.Windows.Forms.MenuItem
	Public WithEvents mToYearEnd As System.Windows.Forms.MenuItem
	Public WithEvents mPredefinedTime As System.Windows.Forms.MenuItem
	Public MainMenu1 As System.Windows.Forms.MainMenu
	'注意：以下过程是 Windows 窗体设计器所必需的
	'可以使用 Windows 窗体设计器来修改它。
	'不要使用代码编辑器来修改它。
	<System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
		Dim resources As System.Resources.ResourceManager = New System.Resources.ResourceManager(GetType(frmSet))
		Me.components = New System.ComponentModel.Container()
		Me.ToolTip1 = New System.Windows.Forms.ToolTip(components)
		Me.ToolTip1.Active = True
		Me.cAfter = New System.Windows.Forms.CheckBox
		Me.tInt = New System.Windows.Forms.TextBox
		Me.tProjectName = New System.Windows.Forms.TextBox
		Me.lstInt = New System.Windows.Forms.ComboBox
		Me.cCalc = New System.Windows.Forms.Button
		Me.cCurrent = New System.Windows.Forms.Button
		Me.tAfter = New System.Windows.Forms.TextBox
		Me.tToTime = New System.Windows.Forms.TextBox
		Me.cToTime = New System.Windows.Forms.Button
		Me.MainMenu1 = New System.Windows.Forms.MainMenu
		Me.mPredefinedPeriod = New System.Windows.Forms.MenuItem
		Me.m60s = New System.Windows.Forms.MenuItem
		Me.m5m = New System.Windows.Forms.MenuItem
		Me.m10m = New System.Windows.Forms.MenuItem
		Me.m30m = New System.Windows.Forms.MenuItem
		Me.m1h = New System.Windows.Forms.MenuItem
		Me.m1h2 = New System.Windows.Forms.MenuItem
		Me.m2h = New System.Windows.Forms.MenuItem
		Me.m3h = New System.Windows.Forms.MenuItem
		Me.m5h = New System.Windows.Forms.MenuItem
		Me.m1d = New System.Windows.Forms.MenuItem
		Me.m2d = New System.Windows.Forms.MenuItem
		Me.m3d = New System.Windows.Forms.MenuItem
		Me.m1w = New System.Windows.Forms.MenuItem
		Me.m2w = New System.Windows.Forms.MenuItem
		Me.m30d = New System.Windows.Forms.MenuItem
		Me.m1y = New System.Windows.Forms.MenuItem
		Me.mPredefinedTime = New System.Windows.Forms.MenuItem
		Me.mTo8h = New System.Windows.Forms.MenuItem
		Me.mTo9h = New System.Windows.Forms.MenuItem
		Me.mTo12h = New System.Windows.Forms.MenuItem
		Me.mTo18h = New System.Windows.Forms.MenuItem
		Me.mTo20h = New System.Windows.Forms.MenuItem
		Me.mTo21h = New System.Windows.Forms.MenuItem
		Me.mTo22h = New System.Windows.Forms.MenuItem
		Me.mTo24h = New System.Windows.Forms.MenuItem
		Me.mToSaturday = New System.Windows.Forms.MenuItem
		Me.mToSunday = New System.Windows.Forms.MenuItem
		Me.mToMonthEnd = New System.Windows.Forms.MenuItem
		Me.mToYearEnd = New System.Windows.Forms.MenuItem
		Me.StartPosition = System.Windows.Forms.FormStartPosition.Manual
		Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow
		Me.Text = "Settings"
		Me.ClientSize = New System.Drawing.Size(238, 62)
		Me.Location = New System.Drawing.Point(10, 7)
		Me.MaximizeBox = False
		Me.MinimizeBox = False
		Me.ShowInTaskbar = False
		Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
		Me.BackColor = System.Drawing.SystemColors.Control
		Me.ControlBox = True
		Me.Enabled = True
		Me.KeyPreview = False
		Me.Cursor = System.Windows.Forms.Cursors.Default
		Me.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.HelpButton = False
		Me.WindowState = System.Windows.Forms.FormWindowState.Normal
		Me.Name = "frmSet"
		Me.cAfter.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
		Me.cAfter.Text = "R"
		Me.cAfter.Size = New System.Drawing.Size(23, 21)
		Me.cAfter.Location = New System.Drawing.Point(96, 40)
		Me.cAfter.Appearance = System.Windows.Forms.Appearance.Button
		Me.cAfter.TabIndex = 6
		Me.ToolTip1.SetToolTip(Me.cAfter, "到指定时限以及是否重复")
		Me.cAfter.CheckAlign = System.Drawing.ContentAlignment.MiddleLeft
		Me.cAfter.BackColor = System.Drawing.SystemColors.Control
		Me.cAfter.CausesValidation = True
		Me.cAfter.Enabled = True
		Me.cAfter.ForeColor = System.Drawing.SystemColors.ControlText
		Me.cAfter.Cursor = System.Windows.Forms.Cursors.Default
		Me.cAfter.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.cAfter.TabStop = True
		Me.cAfter.CheckState = System.Windows.Forms.CheckState.Unchecked
		Me.cAfter.Visible = True
		Me.cAfter.Name = "cAfter"
		Me.tInt.AutoSize = False
		Me.tInt.Size = New System.Drawing.Size(95, 21)
		Me.tInt.Location = New System.Drawing.Point(1, 40)
		Me.tInt.TabIndex = 2
		Me.tInt.Text = "-"
		Me.ToolTip1.SetToolTip(Me.tInt, "详细显示单位")
		Me.tInt.AcceptsReturn = True
		Me.tInt.TextAlign = System.Windows.Forms.HorizontalAlignment.Left
		Me.tInt.BackColor = System.Drawing.SystemColors.Window
		Me.tInt.CausesValidation = True
		Me.tInt.Enabled = True
		Me.tInt.ForeColor = System.Drawing.SystemColors.WindowText
		Me.tInt.HideSelection = True
		Me.tInt.ReadOnly = False
		Me.tInt.Maxlength = 0
		Me.tInt.Cursor = System.Windows.Forms.Cursors.IBeam
		Me.tInt.MultiLine = False
		Me.tInt.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.tInt.ScrollBars = System.Windows.Forms.ScrollBars.None
		Me.tInt.TabStop = True
		Me.tInt.Visible = True
		Me.tInt.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
		Me.tInt.Name = "tInt"
		Me.tProjectName.AutoSize = False
		Me.tProjectName.Size = New System.Drawing.Size(237, 19)
		Me.tProjectName.Location = New System.Drawing.Point(1, 0)
		Me.tProjectName.TabIndex = 0
		Me.tProjectName.Text = "-"
		Me.ToolTip1.SetToolTip(Me.tProjectName, "工程名称")
		Me.tProjectName.AcceptsReturn = True
		Me.tProjectName.TextAlign = System.Windows.Forms.HorizontalAlignment.Left
		Me.tProjectName.BackColor = System.Drawing.SystemColors.Window
		Me.tProjectName.CausesValidation = True
		Me.tProjectName.Enabled = True
		Me.tProjectName.ForeColor = System.Drawing.SystemColors.WindowText
		Me.tProjectName.HideSelection = True
		Me.tProjectName.ReadOnly = False
		Me.tProjectName.Maxlength = 0
		Me.tProjectName.Cursor = System.Windows.Forms.Cursors.IBeam
		Me.tProjectName.MultiLine = False
		Me.tProjectName.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.tProjectName.ScrollBars = System.Windows.Forms.ScrollBars.None
		Me.tProjectName.TabStop = True
		Me.tProjectName.Visible = True
		Me.tProjectName.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
		Me.tProjectName.Name = "tProjectName"
		Me.lstInt.Size = New System.Drawing.Size(95, 21)
		Me.lstInt.Location = New System.Drawing.Point(1, 20)
		Me.lstInt.Items.AddRange(New Object(){"Year", "Month", "Day", "拍", "节", "分", "Hour", "Minute", "Second"})
		Me.lstInt.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
		Me.lstInt.TabIndex = 1
		Me.ToolTip1.SetToolTip(Me.lstInt, "显示单位")
		Me.lstInt.BackColor = System.Drawing.SystemColors.Window
		Me.lstInt.CausesValidation = True
		Me.lstInt.Enabled = True
		Me.lstInt.ForeColor = System.Drawing.SystemColors.WindowText
		Me.lstInt.IntegralHeight = True
		Me.lstInt.Cursor = System.Windows.Forms.Cursors.Default
		Me.lstInt.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.lstInt.Sorted = False
		Me.lstInt.TabStop = True
		Me.lstInt.Visible = True
		Me.lstInt.Name = "lstInt"
		Me.cCalc.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
		Me.cCalc.Text = "C"
		Me.cCalc.Size = New System.Drawing.Size(20, 20)
		Me.cCalc.Location = New System.Drawing.Point(218, 41)
		Me.cCalc.TabIndex = 8
		Me.ToolTip1.SetToolTip(Me.cCalc, "计算离目标时间剩余时间")
		Me.cCalc.BackColor = System.Drawing.SystemColors.Control
		Me.cCalc.CausesValidation = True
		Me.cCalc.Enabled = True
		Me.cCalc.ForeColor = System.Drawing.SystemColors.ControlText
		Me.cCalc.Cursor = System.Windows.Forms.Cursors.Default
		Me.cCalc.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.cCalc.TabStop = True
		Me.cCalc.Name = "cCalc"
		Me.cCurrent.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
		Me.cCurrent.Text = "C"
		Me.cCurrent.Size = New System.Drawing.Size(20, 22)
		Me.cCurrent.Location = New System.Drawing.Point(218, 19)
		Me.cCurrent.TabIndex = 5
		Me.ToolTip1.SetToolTip(Me.cCurrent, "取当前时间")
		Me.cCurrent.BackColor = System.Drawing.SystemColors.Control
		Me.cCurrent.CausesValidation = True
		Me.cCurrent.Enabled = True
		Me.cCurrent.ForeColor = System.Drawing.SystemColors.ControlText
		Me.cCurrent.Cursor = System.Windows.Forms.Cursors.Default
		Me.cCurrent.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.cCurrent.TabStop = True
		Me.cCurrent.Name = "cCurrent"
		Me.tAfter.AutoSize = False
		Me.tAfter.Size = New System.Drawing.Size(99, 21)
		Me.tAfter.Location = New System.Drawing.Point(119, 40)
		Me.tAfter.TabIndex = 7
		Me.tAfter.Text = "-"
		Me.ToolTip1.SetToolTip(Me.tAfter, "目标时限")
		Me.tAfter.AcceptsReturn = True
		Me.tAfter.TextAlign = System.Windows.Forms.HorizontalAlignment.Left
		Me.tAfter.BackColor = System.Drawing.SystemColors.Window
		Me.tAfter.CausesValidation = True
		Me.tAfter.Enabled = True
		Me.tAfter.ForeColor = System.Drawing.SystemColors.WindowText
		Me.tAfter.HideSelection = True
		Me.tAfter.ReadOnly = False
		Me.tAfter.Maxlength = 0
		Me.tAfter.Cursor = System.Windows.Forms.Cursors.IBeam
		Me.tAfter.MultiLine = False
		Me.tAfter.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.tAfter.ScrollBars = System.Windows.Forms.ScrollBars.None
		Me.tAfter.TabStop = True
		Me.tAfter.Visible = True
		Me.tAfter.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
		Me.tAfter.Name = "tAfter"
		Me.tToTime.AutoSize = False
		Me.tToTime.Size = New System.Drawing.Size(99, 22)
		Me.tToTime.Location = New System.Drawing.Point(119, 19)
		Me.tToTime.TabIndex = 4
		Me.tToTime.Text = "-"
		Me.ToolTip1.SetToolTip(Me.tToTime, "目标时间")
		Me.tToTime.AcceptsReturn = True
		Me.tToTime.TextAlign = System.Windows.Forms.HorizontalAlignment.Left
		Me.tToTime.BackColor = System.Drawing.SystemColors.Window
		Me.tToTime.CausesValidation = True
		Me.tToTime.Enabled = True
		Me.tToTime.ForeColor = System.Drawing.SystemColors.WindowText
		Me.tToTime.HideSelection = True
		Me.tToTime.ReadOnly = False
		Me.tToTime.Maxlength = 0
		Me.tToTime.Cursor = System.Windows.Forms.Cursors.IBeam
		Me.tToTime.MultiLine = False
		Me.tToTime.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.tToTime.ScrollBars = System.Windows.Forms.ScrollBars.None
		Me.tToTime.TabStop = True
		Me.tToTime.Visible = True
		Me.tToTime.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
		Me.tToTime.Name = "tToTime"
		Me.cToTime.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
		Me.cToTime.Text = "->"
		Me.cToTime.Size = New System.Drawing.Size(23, 21)
		Me.cToTime.Location = New System.Drawing.Point(96, 19)
		Me.cToTime.TabIndex = 3
		Me.ToolTip1.SetToolTip(Me.cToTime, "到指定时间")
		Me.cToTime.BackColor = System.Drawing.SystemColors.Control
		Me.cToTime.CausesValidation = True
		Me.cToTime.Enabled = True
		Me.cToTime.ForeColor = System.Drawing.SystemColors.ControlText
		Me.cToTime.Cursor = System.Windows.Forms.Cursors.Default
		Me.cToTime.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.cToTime.TabStop = True
		Me.cToTime.Name = "cToTime"
		Me.mPredefinedPeriod.Text = "Predefined period"
		Me.mPredefinedPeriod.Visible = False
		Me.mPredefinedPeriod.Checked = False
		Me.mPredefinedPeriod.Enabled = True
		Me.mPredefinedPeriod.MDIList = False
		Me.m60s.Text = "60s"
		Me.m60s.Checked = False
		Me.m60s.Enabled = True
		Me.m60s.Visible = True
		Me.m60s.MDIList = False
		Me.m5m.Text = "5'"
		Me.m5m.Checked = False
		Me.m5m.Enabled = True
		Me.m5m.Visible = True
		Me.m5m.MDIList = False
		Me.m10m.Text = "10'"
		Me.m10m.Checked = False
		Me.m10m.Enabled = True
		Me.m10m.Visible = True
		Me.m10m.MDIList = False
		Me.m30m.Text = "30'"
		Me.m30m.Checked = False
		Me.m30m.Enabled = True
		Me.m30m.Visible = True
		Me.m30m.MDIList = False
		Me.m1h.Text = "1 hour"
		Me.m1h.Checked = False
		Me.m1h.Enabled = True
		Me.m1h.Visible = True
		Me.m1h.MDIList = False
		Me.m1h2.Text = "1.5 hours"
		Me.m1h2.Checked = False
		Me.m1h2.Enabled = True
		Me.m1h2.Visible = True
		Me.m1h2.MDIList = False
		Me.m2h.Text = "2 hours"
		Me.m2h.Checked = False
		Me.m2h.Enabled = True
		Me.m2h.Visible = True
		Me.m2h.MDIList = False
		Me.m3h.Text = "3 hours"
		Me.m3h.Checked = False
		Me.m3h.Enabled = True
		Me.m3h.Visible = True
		Me.m3h.MDIList = False
		Me.m5h.Text = "5 hours"
		Me.m5h.Checked = False
		Me.m5h.Enabled = True
		Me.m5h.Visible = True
		Me.m5h.MDIList = False
		Me.m1d.Text = "1 day"
		Me.m1d.Checked = False
		Me.m1d.Enabled = True
		Me.m1d.Visible = True
		Me.m1d.MDIList = False
		Me.m2d.Text = "2 days"
		Me.m2d.Checked = False
		Me.m2d.Enabled = True
		Me.m2d.Visible = True
		Me.m2d.MDIList = False
		Me.m3d.Text = "3 days"
		Me.m3d.Checked = False
		Me.m3d.Enabled = True
		Me.m3d.Visible = True
		Me.m3d.MDIList = False
		Me.m1w.Text = "1 week"
		Me.m1w.Checked = False
		Me.m1w.Enabled = True
		Me.m1w.Visible = True
		Me.m1w.MDIList = False
		Me.m2w.Text = "2 weeks"
		Me.m2w.Checked = False
		Me.m2w.Enabled = True
		Me.m2w.Visible = True
		Me.m2w.MDIList = False
		Me.m30d.Text = "1 month"
		Me.m30d.Checked = False
		Me.m30d.Enabled = True
		Me.m30d.Visible = True
		Me.m30d.MDIList = False
		Me.m1y.Text = "1 year"
		Me.m1y.Checked = False
		Me.m1y.Enabled = True
		Me.m1y.Visible = True
		Me.m1y.MDIList = False
		Me.mPredefinedTime.Text = "Predefined time"
		Me.mPredefinedTime.Visible = False
		Me.mPredefinedTime.Checked = False
		Me.mPredefinedTime.Enabled = True
		Me.mPredefinedTime.MDIList = False
		Me.mTo8h.Text = "8:00 AM"
		Me.mTo8h.Checked = False
		Me.mTo8h.Enabled = True
		Me.mTo8h.Visible = True
		Me.mTo8h.MDIList = False
		Me.mTo9h.Text = "9:00 AM"
		Me.mTo9h.Checked = False
		Me.mTo9h.Enabled = True
		Me.mTo9h.Visible = True
		Me.mTo9h.MDIList = False
		Me.mTo12h.Text = "12:00 AM"
		Me.mTo12h.Checked = False
		Me.mTo12h.Enabled = True
		Me.mTo12h.Visible = True
		Me.mTo12h.MDIList = False
		Me.mTo18h.Text = "18:00 PM"
		Me.mTo18h.Checked = False
		Me.mTo18h.Enabled = True
		Me.mTo18h.Visible = True
		Me.mTo18h.MDIList = False
		Me.mTo20h.Text = "20:00 PM"
		Me.mTo20h.Checked = False
		Me.mTo20h.Enabled = True
		Me.mTo20h.Visible = True
		Me.mTo20h.MDIList = False
		Me.mTo21h.Text = "21:00 PM"
		Me.mTo21h.Checked = False
		Me.mTo21h.Enabled = True
		Me.mTo21h.Visible = True
		Me.mTo21h.MDIList = False
		Me.mTo22h.Text = "22:00 PM"
		Me.mTo22h.Checked = False
		Me.mTo22h.Enabled = True
		Me.mTo22h.Visible = True
		Me.mTo22h.MDIList = False
		Me.mTo24h.Text = "0:00 PM"
		Me.mTo24h.Checked = False
		Me.mTo24h.Enabled = True
		Me.mTo24h.Visible = True
		Me.mTo24h.MDIList = False
		Me.mToSaturday.Text = "Saturday"
		Me.mToSaturday.Checked = False
		Me.mToSaturday.Enabled = True
		Me.mToSaturday.Visible = True
		Me.mToSaturday.MDIList = False
		Me.mToSunday.Text = "Sunday"
		Me.mToSunday.Checked = False
		Me.mToSunday.Enabled = True
		Me.mToSunday.Visible = True
		Me.mToSunday.MDIList = False
		Me.mToMonthEnd.Text = "The End of Month"
		Me.mToMonthEnd.Checked = False
		Me.mToMonthEnd.Enabled = True
		Me.mToMonthEnd.Visible = True
		Me.mToMonthEnd.MDIList = False
		Me.mToYearEnd.Text = "The End of Year"
		Me.mToYearEnd.Checked = False
		Me.mToYearEnd.Enabled = True
		Me.mToYearEnd.Visible = True
		Me.mToYearEnd.MDIList = False
		Me.Controls.Add(cAfter)
		Me.Controls.Add(tInt)
		Me.Controls.Add(tProjectName)
		Me.Controls.Add(lstInt)
		Me.Controls.Add(cCalc)
		Me.Controls.Add(cCurrent)
		Me.Controls.Add(tAfter)
		Me.Controls.Add(tToTime)
		Me.Controls.Add(cToTime)
		Me.mPredefinedPeriod.Index = 0
		Me.mPredefinedTime.Index = 1
		MainMenu1.MenuItems.AddRange(New System.Windows.Forms.MenuItem(){Me.mPredefinedPeriod, Me.mPredefinedTime})
		Me.m60s.Index = 0
		Me.m5m.Index = 1
		Me.m10m.Index = 2
		Me.m30m.Index = 3
		Me.m1h.Index = 4
		Me.m1h2.Index = 5
		Me.m2h.Index = 6
		Me.m3h.Index = 7
		Me.m5h.Index = 8
		Me.m1d.Index = 9
		Me.m2d.Index = 10
		Me.m3d.Index = 11
		Me.m1w.Index = 12
		Me.m2w.Index = 13
		Me.m30d.Index = 14
		Me.m1y.Index = 15
		mPredefinedPeriod.MenuItems.AddRange(New System.Windows.Forms.MenuItem(){Me.m60s, Me.m5m, Me.m10m, Me.m30m, Me.m1h, Me.m1h2, Me.m2h, Me.m3h, Me.m5h, Me.m1d, Me.m2d, Me.m3d, Me.m1w, Me.m2w, Me.m30d, Me.m1y})
		Me.mTo8h.Index = 0
		Me.mTo9h.Index = 1
		Me.mTo12h.Index = 2
		Me.mTo18h.Index = 3
		Me.mTo20h.Index = 4
		Me.mTo21h.Index = 5
		Me.mTo22h.Index = 6
		Me.mTo24h.Index = 7
		Me.mToSaturday.Index = 8
		Me.mToSunday.Index = 9
		Me.mToMonthEnd.Index = 10
		Me.mToYearEnd.Index = 11
		mPredefinedTime.MenuItems.AddRange(New System.Windows.Forms.MenuItem(){Me.mTo8h, Me.mTo9h, Me.mTo12h, Me.mTo18h, Me.mTo20h, Me.mTo21h, Me.mTo22h, Me.mTo24h, Me.mToSaturday, Me.mToSunday, Me.mToMonthEnd, Me.mToYearEnd})
		Me.Menu = MainMenu1
	End Sub
#End Region
#Region "升级支持"
	Private Shared m_vb6FormDefInstance As frmSet
	Private Shared m_InitializingDefInstance As Boolean
	Public Shared Property DefInstance() As frmSet
		Get
			If m_vb6FormDefInstance Is Nothing OrElse m_vb6FormDefInstance.IsDisposed Then
				m_InitializingDefInstance = True
				m_vb6FormDefInstance = New frmSet()
				m_InitializingDefInstance = False
			End If
			DefInstance = m_vb6FormDefInstance
		End Get
		Set
			m_vb6FormDefInstance = Value
		End Set
	End Property
#End Region

	Const iss As String = "yyyy,1;m,1;d,1;h,3;h,1;n,15;h,1;n,1;s,1"

	Public Sub SetInt()
		Dim ss As Object
		Dim tf As String
		Dim tk As Double
		'UPGRADE_WARNING: 未能解析对象 ss 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		ss = Split(tInt.Text, ",")
		'UPGRADE_WARNING: 未能解析对象 ss() 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		tf = ss(0)
		'UPGRADE_WARNING: 未能解析对象 ss() 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		If (UBound(ss) > 0) Then tk = ss(1) Else tk = 1
		'UPGRADE_WARNING: 未能解析对象 frmMain.cIntFormat 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		frmMain.DefInstance.cIntFormat = tf
		frmMain.DefInstance.cIntK = tk
	End Sub

	'UPGRADE_WARNING: 初始化窗体时可能激发事件 cAfter.CheckStateChanged。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup2075"'
	Public Sub cAfter_CheckStateChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles cAfter.CheckStateChanged
		Dim di, ds, dv As Object
		'UPGRADE_WARNING: 未能解析对象 ds 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		ds = Split(tAfter.Text, " ")
		'UPGRADE_WARNING: 未能解析对象 di 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		di = "s"
		If UBound(ds) - LBound(ds) > 0 Then
			'UPGRADE_WARNING: 未能解析对象 ds() 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
			'UPGRADE_WARNING: 未能解析对象 di 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
			di = ds(1)
		End If
		'UPGRADE_WARNING: 未能解析对象 ds() 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		'UPGRADE_WARNING: 未能解析对象 dv 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		dv = ds(0)

		On Error Resume Next
		'UPGRADE_WARNING: 未能解析对象 dv 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		tToTime.Text = CStr(DateAdd(CStr(di), dv, System.Date.FromOADate(Today.ToOADate + TimeOfDay.ToOADate)))
		cToTime_Click(cToTime, New System.EventArgs())
	End Sub

	Public Sub cCalc_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles cCalc.Click
		tAfter.Text = CStr(DateDiff(Microsoft.VisualBasic.DateInterval.Second, System.Date.FromOADate(Today.ToOADate + TimeOfDay.ToOADate), CDate(tToTime.Text)))
		cAfter_CheckStateChanged(cAfter, New System.EventArgs())
	End Sub

	Public Sub cCurrent_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles cCurrent.Click
		tToTime.Text = CStr(System.Date.FromOADate(Today.ToOADate + TimeOfDay.ToOADate))
		cToTime_Click(cToTime, New System.EventArgs())
	End Sub

	Public Sub cToTime_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles cToTime.Click
		On Error Resume Next
		'UPGRADE_WARNING: 未能解析对象 frmMain.To_Time 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		frmMain.DefInstance.To_Time = CDate(tToTime.Text)
		frmMain.DefInstance.bMsged = False
	End Sub

	'UPGRADE_WARNING: Form 事件 frmSet.Activate 具有新的行为。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup2065"'
	Public Sub frmSet_Activated(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Activated
		'UPGRADE_WARNING: 未能解析对象 frmMain.lastappname 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		tProjectName.Text = frmMain.DefInstance.lastappname
	End Sub

	Public Sub frmSet_DoubleClick(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.DoubleClick
		tProjectName.Text = Trim(tProjectName.Text)
		If tProjectName.Text = "" Then tProjectName.Text = "Noname project # " & System.Date.FromOADate(Today.ToOADate + TimeOfDay.ToOADate)
		'UPGRADE_WARNING: 未能解析对象 frmMain.lastappname 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		frmMain.DefInstance.lastappname = tProjectName.Text
		frmMain.DefInstance.ToolTip1.SetToolTip(frmMain.DefInstance.l, tProjectName.Text)
		SetInt()
		Me.Hide()
	End Sub

	Public Sub frmSet_Load(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Load
		lstInt.SelectedIndex = 8
	End Sub

	'UPGRADE_WARNING: Form 事件 frmSet.Unload 具有新的行为。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup2065"'
	Private Sub frmSet_Closed(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Closed
		'UPGRADE_ISSUE: 事件参数 Cancel 未升级。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1057"'
		Cancel = True
		Me.Hide()
	End Sub

	'UPGRADE_WARNING: 初始化窗体时可能激发事件 lstInt.SelectedIndexChanged。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup2075"'
	Public Sub lstInt_SelectedIndexChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles lstInt.SelectedIndexChanged
		tInt.Text = Split(iss, ";")(lstInt.SelectedIndex)
		SetInt()
	End Sub

	Public Sub lstInt_KeyPress(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.KeyPressEventArgs) Handles lstInt.KeyPress
		Dim KeyAscii As Short = Asc(eventArgs.KeyChar)
		If KeyAscii = 13 Then
			KeyAscii = 0
			tInt.Focus()
		End If
		If KeyAscii = 0 Then
			eventArgs.Handled = True
		End If
	End Sub

	Public Sub m10m_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m10m.Popup
		m10m_Click(eventSender, eventArgs)
	End Sub
	Public Sub m10m_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m10m.Click
		tAfter.Text = "10 n"
	End Sub

	Public Sub m1d_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m1d.Popup
		m1d_Click(eventSender, eventArgs)
	End Sub
	Public Sub m1d_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m1d.Click
		tAfter.Text = "1 d"
	End Sub

	Public Sub m1h_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m1h.Popup
		m1h_Click(eventSender, eventArgs)
	End Sub
	Public Sub m1h_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m1h.Click
		tAfter.Text = "1 h"
	End Sub

	Public Sub m1h2_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m1h2.Popup
		m1h2_Click(eventSender, eventArgs)
	End Sub
	Public Sub m1h2_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m1h2.Click
		tAfter.Text = "90 n"
	End Sub

	Public Sub m1w_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m1w.Popup
		m1w_Click(eventSender, eventArgs)
	End Sub
	Public Sub m1w_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m1w.Click
		tAfter.Text = "1 ww"
	End Sub

	Public Sub m1y_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m1y.Popup
		m1y_Click(eventSender, eventArgs)
	End Sub
	Public Sub m1y_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m1y.Click
		tAfter.Text = "1 yyyy"
	End Sub

	Public Sub m2d_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m2d.Popup
		m2d_Click(eventSender, eventArgs)
	End Sub
	Public Sub m2d_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m2d.Click
		tAfter.Text = "2 d"
	End Sub

	Public Sub m2h_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m2h.Popup
		m2h_Click(eventSender, eventArgs)
	End Sub
	Public Sub m2h_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m2h.Click
		tAfter.Text = "2 h"
	End Sub

	Public Sub m2w_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m2w.Popup
		m2w_Click(eventSender, eventArgs)
	End Sub
	Public Sub m2w_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m2w.Click
		tAfter.Text = "2 ww"
	End Sub

	Public Sub m30d_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m30d.Popup
		m30d_Click(eventSender, eventArgs)
	End Sub
	Public Sub m30d_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m30d.Click
		tAfter.Text = "1 m"
	End Sub

	Public Sub m30m_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m30m.Popup
		m30m_Click(eventSender, eventArgs)
	End Sub
	Public Sub m30m_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m30m.Click
		tAfter.Text = "30 n"
	End Sub

	Public Sub m3d_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m3d.Popup
		m3d_Click(eventSender, eventArgs)
	End Sub
	Public Sub m3d_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m3d.Click
		tAfter.Text = "3 d"
	End Sub

	Public Sub m3h_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m3h.Popup
		m3h_Click(eventSender, eventArgs)
	End Sub
	Public Sub m3h_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m3h.Click
		tAfter.Text = "3 h"
	End Sub

	Public Sub m5h_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m5h.Popup
		m5h_Click(eventSender, eventArgs)
	End Sub
	Public Sub m5h_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m5h.Click
		tAfter.Text = "5 h"
	End Sub

	Public Sub m5m_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m5m.Popup
		m5m_Click(eventSender, eventArgs)
	End Sub
	Public Sub m5m_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m5m.Click
		tAfter.Text = "5 n"
	End Sub

	Public Sub m60s_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m60s.Popup
		m60s_Click(eventSender, eventArgs)
	End Sub
	Public Sub m60s_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles m60s.Click
		tAfter.Text = "60 s"
	End Sub

	Public Sub mTo12h_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo12h.Popup
		mTo12h_Click(eventSender, eventArgs)
	End Sub
	Public Sub mTo12h_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo12h.Click
		tToTime.Text = CStr(DateAdd(Microsoft.VisualBasic.DateInterval.Hour, 12, Today))
	End Sub

	Public Sub mTo18h_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo18h.Popup
		mTo18h_Click(eventSender, eventArgs)
	End Sub
	Public Sub mTo18h_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo18h.Click
		tToTime.Text = CStr(DateAdd(Microsoft.VisualBasic.DateInterval.Hour, 18, Today))
	End Sub

	Public Sub mTo20h_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo20h.Popup
		mTo20h_Click(eventSender, eventArgs)
	End Sub
	Public Sub mTo20h_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo20h.Click
		tToTime.Text = CStr(DateAdd(Microsoft.VisualBasic.DateInterval.Hour, 20, Today))
	End Sub

	Public Sub mTo21h_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo21h.Popup
		mTo21h_Click(eventSender, eventArgs)
	End Sub
	Public Sub mTo21h_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo21h.Click
		tToTime.Text = CStr(DateAdd(Microsoft.VisualBasic.DateInterval.Hour, 21, Today))
	End Sub

	Public Sub mTo22h_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo22h.Popup
		mTo22h_Click(eventSender, eventArgs)
	End Sub
	Public Sub mTo22h_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo22h.Click
		tToTime.Text = CStr(DateAdd(Microsoft.VisualBasic.DateInterval.Hour, 22, Today))
	End Sub

	Public Sub mTo24h_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo24h.Popup
		mTo24h_Click(eventSender, eventArgs)
	End Sub
	Public Sub mTo24h_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo24h.Click
		tToTime.Text = CStr(DateAdd(Microsoft.VisualBasic.DateInterval.Hour, 24, Today))
	End Sub

	Public Sub mTo8h_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo8h.Popup
		mTo8h_Click(eventSender, eventArgs)
	End Sub
	Public Sub mTo8h_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo8h.Click
		tToTime.Text = CStr(DateAdd(Microsoft.VisualBasic.DateInterval.Hour, 8, Today))
	End Sub

	Public Sub mTo9h_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo9h.Popup
		mTo9h_Click(eventSender, eventArgs)
	End Sub
	Public Sub mTo9h_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mTo9h.Click
		tToTime.Text = CStr(DateAdd(Microsoft.VisualBasic.DateInterval.Hour, 9, Today))
	End Sub

	Public Sub mToMonthEnd_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mToMonthEnd.Popup
		mToMonthEnd_Click(eventSender, eventArgs)
	End Sub
	Public Sub mToMonthEnd_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mToMonthEnd.Click
		tToTime.Text = CStr(DateAdd(Microsoft.VisualBasic.DateInterval.Day, -1, DateSerial(Year(Today), Month(Today) + 1, 1)))
	End Sub

	Public Sub mToSaturday_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mToSaturday.Popup
		mToSaturday_Click(eventSender, eventArgs)
	End Sub
	Public Sub mToSaturday_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mToSaturday.Click
		Dim days As Object
		'UPGRADE_WARNING: 未能解析对象 days 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		days = FirstDayOfWeek.Saturday - WeekDay(Today, FirstDayOfWeek.Sunday)
		'UPGRADE_WARNING: 未能解析对象 days 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		tToTime.Text = CStr(DateAdd(Microsoft.VisualBasic.DateInterval.Day, days, Today))
	End Sub

	Public Sub mToSunday_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mToSunday.Popup
		mToSunday_Click(eventSender, eventArgs)
	End Sub
	Public Sub mToSunday_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mToSunday.Click
		Dim days As Object
		'UPGRADE_WARNING: 未能解析对象 days 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		days = FirstDayOfWeek.Sunday + 7 - WeekDay(Today, FirstDayOfWeek.Sunday)
		'UPGRADE_WARNING: 未能解析对象 days 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		'UPGRADE_WARNING: Mod 有新行为。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1041"'
		days = (days - 1) Mod 7 + 1
		'UPGRADE_WARNING: 未能解析对象 days 的默认属性。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup1037"'
		tToTime.Text = CStr(DateAdd(Microsoft.VisualBasic.DateInterval.Day, days, Today))
	End Sub

	Public Sub mToYearEnd_Popup(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mToYearEnd.Popup
		mToYearEnd_Click(eventSender, eventArgs)
	End Sub
	Public Sub mToYearEnd_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles mToYearEnd.Click
		tToTime.Text = CStr(DateAdd(Microsoft.VisualBasic.DateInterval.Day, -1, DateSerial(Year(Today) + 1, 1, 1)))
	End Sub

	Public Sub tAfter_KeyPress(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.KeyPressEventArgs) Handles tAfter.KeyPress
		Dim KeyAscii As Short = Asc(eventArgs.KeyChar)
		If KeyAscii = 13 Then
			KeyAscii = 0
			cAfter_CheckStateChanged(cAfter, New System.EventArgs())
			tProjectName.Focus()
		End If
		If KeyAscii = 0 Then
			eventArgs.Handled = True
		End If
	End Sub

	Public Sub tAfter_MouseDown(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.MouseEventArgs) Handles tAfter.MouseDown
		Dim Button As Short = eventArgs.Button \ &H100000
		Dim Shift As Short = System.Windows.Forms.Control.ModifierKeys \ &H10000
		Dim x As Single = VB6.PixelsToTwipsX(eventArgs.X)
		Dim y As Single = VB6.PixelsToTwipsY(eventArgs.Y)
		If Button And VB6.MouseButtonConstants.LeftButton Then
			'UPGRADE_ISSUE: Form 方法 frmSet.PopupMenu 未升级。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup2064"'
			PopupMenu(mPredefinedPeriod)
		End If
	End Sub

	Public Sub tInt_KeyPress(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.KeyPressEventArgs) Handles tInt.KeyPress
		Dim KeyAscii As Short = Asc(eventArgs.KeyChar)
		If KeyAscii = 13 Then
			KeyAscii = 0
			SetInt()
			tToTime.Focus()
		End If
		If KeyAscii = 0 Then
			eventArgs.Handled = True
		End If
	End Sub

	Public Sub tProjectName_KeyPress(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.KeyPressEventArgs) Handles tProjectName.KeyPress
		Dim KeyAscii As Short = Asc(eventArgs.KeyChar)
		If KeyAscii = 13 Then
			KeyAscii = 0
			lstInt.Focus()
		End If
		If KeyAscii = 0 Then
			eventArgs.Handled = True
		End If
	End Sub

	Public Sub tToTime_KeyPress(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.KeyPressEventArgs) Handles tToTime.KeyPress
		Dim KeyAscii As Short = Asc(eventArgs.KeyChar)
		If KeyAscii = 13 Then
			KeyAscii = 0
			cCalc_Click(cCalc, New System.EventArgs())
			cToTime_Click(cToTime, New System.EventArgs())
			tAfter.Focus()
		End If
		If KeyAscii = 0 Then
			eventArgs.Handled = True
		End If
	End Sub

	Public Sub tToTime_MouseDown(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.MouseEventArgs) Handles tToTime.MouseDown
		Dim Button As Short = eventArgs.Button \ &H100000
		Dim Shift As Short = System.Windows.Forms.Control.ModifierKeys \ &H10000
		Dim x As Single = VB6.PixelsToTwipsX(eventArgs.X)
		Dim y As Single = VB6.PixelsToTwipsY(eventArgs.Y)
		If Button And VB6.MouseButtonConstants.LeftButton Then
			'UPGRADE_ISSUE: Form 方法 frmSet.PopupMenu 未升级。 单击以获得更多信息：'ms-help://MS.VSCC/commoner/redir/redirect.htm?keyword="vbup2064"'
			PopupMenu(mPredefinedTime)
		End If
	End Sub
End Class