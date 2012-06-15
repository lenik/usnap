Attribute VB_Name = "modClock"
Option Explicit

Public Const PI As Double = 3.14159265358979

Public CeAux As New CeE3DAux
Public CeBase As New CeE3DBase
Public CeModel As New CeE3DModel
Public CeEnv As New CeE3DEnv
Public CeRender As New CeE3DRender
Public CeUtil As New CeE3DUtil

Public dStep As Double
Public wndWidth As Double, wndHeight As Double

Public lp As LowXTool.Pointer

Public Sub cmdAbout()
      frmAbout.Show 1
End Sub

Public Sub cmdQuit()
      End
End Sub

Public Sub OnResize(ByVal W As Long, ByVal H As Long)
      wndWidth = W
      wndHeight = H
      CeBase.Viewport 0, 0, wndWidth, wndHeight
End Sub

Public Sub display(ByVal t As Variant)
      Dim nHour As Double, nMinute As Double, nSecond As Double
      Dim mat_ambient(0 To 3) As Single

      nHour = Hour(t)
      nMinute = Minute(t)
      nSecond = Second(t)

      ' ≥ı ºªØ◊˜Õº«¯
            ' …Ë÷√µ◊…´
            CeBase.ClearColor 0, 0, 0, 1
            CeAux.ClearAll
            ' …Ë÷√π‚’’
            CeEnv.StartLighting
            CeEnv.EnableLight 0
            CeEnv.SetLightPositionf 0, 1, 1, 3, 0
            CeEnv.SetLightAmbientf 0, 1, 0, 0, 0
            CeEnv.EnableLight 1
            CeEnv.SetLightPositionf 1, -1, -1, -3, 0
            CeEnv.SetLightAmbientf 1, 1, 0, 0, 0

            CeEnv.SetTwoSideModel True
      ' ª≠µ◊≈Ã
            ' ª≠±ﬂøÚ
            CeBase.Color3d 0.9, 0.9, 1
            CeAux.DrawSolidTorus 1 / 20, 1

            SetBkColor CeAux.GetHDC, 0
            SetTextColor CeAux.GetHDC, &HFFFFFF
            'TextOut CeE3DGetHDC, 10, 10, Time, Len(Time)

            ' ª≠øÃ∂»
            Dim i As Integer
            Dim a As Double, tx As Double, ty As Double
            CeBase.Color3d 0.9, 1, 0.9
            For i = 0 To 11
                  a = i * PI / 6
                  tx = Cos(a) * 0.9
                  ty = Sin(a) * 0.9
                  CeBase.PushMatrix
                        CeBase.Rotated 90, 0, 0, 1
                        CeBase.Translated tx, -ty, 0
                        CeBase.Rotated -90 - a * 180 / PI, 0, 0, 1
                        CeAux.DrawSolidBox 1 / 20, 1 / 5, 1 / 20
                  CeBase.PopMatrix
            Next
            ' ª≠◊™÷·
            CeBase.Color3d 1, 1, 0.9
            CeBase.PushMatrix
                  'CeBase.Rotated 90, 1, 0, 0
                  'CeBase.Translated 0, -1, 0
                  'CeAux.DrawSolidCylinder 1 / 10, 1 / 20
                  Static coneRotation As Double
                  coneRotation = coneRotation + 5
                  CeBase.Rotated coneRotation, 0, 0, 1
                  'CeAux.DrawSolidCone 1 / 10, 1 / 10
                  CeAux.DrawSolidDodecahedron 1 / 10
            CeBase.PopMatrix
      ' ª≠÷∏’Î
            ' ª≠ ±’Î
            CeBase.Color3d 1, 0.9, 0.9
            CeBase.PushMatrix
                  a = nHour / 6 * PI
                  tx = Cos(a) * 0.43
                  ty = Sin(a) * 0.43

                  CeBase.Rotated 90, 0, 0, 1
                  CeBase.Translated tx, -ty, 0
                  CeBase.Rotated 90 - a * 180 / PI, 0, 0, 1
                  CeAux.DrawSolidBox 1 / 15, 0.5, 1 / 20
            CeBase.PopMatrix
            ' ª≠∑÷’Î
            CeBase.Color3d 0.8, 0.8, 1
            CeBase.PushMatrix
                  a = nMinute / 30 * PI
                  tx = Cos(a) * 0.45
                  ty = Sin(a) * 0.45

                  CeBase.Rotated 90, 0, 0, 1
                  CeBase.Translated tx, -ty, 0
                  CeBase.Rotated 90 - a * 180 / PI, 0, 0, 1
                  CeAux.DrawSolidBox 1 / 17, 0.6, 1 / 20
            CeBase.PopMatrix
            ' ª≠√Î’Î
            CeBase.Color3d 1, 0.9, 1
            CeBase.PushMatrix
                  a = nSecond / 30 * PI
                  tx = Cos(a) * 0.5
                  ty = Sin(a) * 0.5

                  CeBase.Rotated 90, 0, 0, 1
                  CeBase.Translated tx, -ty, 0
                  CeBase.Rotated 90 - a * 180 / PI, 0, 0, 1
                  CeAux.DrawSolidBox 1 / 20, 0.7, 1 / 20
            CeBase.PopMatrix

      CeAux.SwapBuffers
End Sub

Public Sub mainDisplay()
      display time
End Sub

Public Sub cmdRotUp()
      CeBase.MatrixMode CEE3D_PROJECTION_MATRIX
      CeBase.Rotated dStep, 1, 0, 0
      CeBase.MatrixMode CEE3D_MODELVIEW_MATRIX
End Sub
Public Sub cmdRotDown()
      CeBase.MatrixMode CEE3D_PROJECTION_MATRIX
      CeBase.Rotated -dStep, 1, 0, 0
      CeBase.MatrixMode CEE3D_MODELVIEW_MATRIX
End Sub
Public Sub cmdRotLeft()
      CeBase.MatrixMode CEE3D_PROJECTION_MATRIX
      CeBase.Rotated dStep, 0, 1, 0
      CeBase.MatrixMode CEE3D_MODELVIEW_MATRIX
End Sub
Public Sub cmdRotRight()
      CeBase.MatrixMode CEE3D_PROJECTION_MATRIX
      CeBase.Rotated -dStep, 0, 1, 0
      CeBase.MatrixMode CEE3D_MODELVIEW_MATRIX
End Sub
Public Sub cmdRotCCW()
      CeBase.MatrixMode CEE3D_PROJECTION_MATRIX
      CeBase.Rotated dStep, 0, 0, 1
      CeBase.MatrixMode CEE3D_MODELVIEW_MATRIX
End Sub
Public Sub cmdRotCW()
      CeBase.MatrixMode CEE3D_PROJECTION_MATRIX
      CeBase.Rotated -dStep, 0, 0, 1
      CeBase.MatrixMode CEE3D_MODELVIEW_MATRIX
End Sub
Public Sub cmdScaleIn()
      CeBase.MatrixMode CEE3D_PROJECTION_MATRIX
      CeBase.Scaled 1.1, 1.1, 1.1
      CeBase.MatrixMode CEE3D_MODELVIEW_MATRIX
End Sub
Public Sub cmdScaleOut()
      CeBase.MatrixMode CEE3D_PROJECTION_MATRIX
      CeBase.Scaled 0.9, 0.9, 0.9
      CeBase.MatrixMode CEE3D_MODELVIEW_MATRIX
End Sub
Public Sub cmdCoarser()
      dStep = dStep * 1.1
End Sub
Public Sub cmdPreciser()
      dStep = dStep * 0.9
End Sub

Public Sub Main()
      Dim t As Long

      Set lp = New LowXTool.Pointer

      dStep = 5

      CeAux.InitDisplayMode 2

      wndWidth = 320
      wndHeight = 200
      CeAux.InitPosition 0, 0, wndWidth, wndHeight

      CeAux.InitWindow "≥¨º∂ƒ÷÷”3D∞Ê"

      CeAux.KeyFunc Asc("a"), lp.pFunc(AddressOf cmdAbout)
      CeAux.KeyFunc Asc("q"), lp.pFunc(AddressOf cmdQuit)
      CeAux.KeyFunc Asc("8"), lp.pFunc(AddressOf cmdRotUp)
      CeAux.KeyFunc Asc("2"), lp.pFunc(AddressOf cmdRotDown)
      CeAux.KeyFunc Asc("4"), lp.pFunc(AddressOf cmdRotLeft)
      CeAux.KeyFunc Asc("6"), lp.pFunc(AddressOf cmdRotRight)
      CeAux.KeyFunc Asc("7"), lp.pFunc(AddressOf cmdRotCCW)
      CeAux.KeyFunc Asc("9"), lp.pFunc(AddressOf cmdRotCW)
      CeAux.KeyFunc Asc("z"), lp.pFunc(AddressOf cmdScaleIn)
      CeAux.KeyFunc Asc("Z"), lp.pFunc(AddressOf cmdScaleOut)
      CeAux.KeyFunc Asc("v"), lp.pFunc(AddressOf cmdCoarser)
      CeAux.KeyFunc Asc("V"), lp.pFunc(AddressOf cmdPreciser)

      CeAux.ReshapeFunc lp.pFunc(AddressOf OnResize)

      CeRender.ShadeSmooth
      CeRender.SetDepthFunc DEPTHFUNC_LEQUAL
      'CeBase.Enable CEE3D_COLOR_MATERIAL

      CeBase.Scaled 0.8, 0.8, 0.8
      Do
            DoEvents
            mainDisplay
      Loop
End Sub
