Attribute VB_Name = "modCeE3D_Client2"
Option Explicit

Public ceBase As New CeE3DBase
Public ceAux As New CeE3DAux
Public ceModel As New CeE3DModel
Public ceUtil As New CeE3DUtil
Public ceEnv As New CeE3DEnv
Public ceRender As New CeE3DRender

Public lt As Object

Public Const AUX_RGB = 0
Public Const AUX_RGBA = 0
Public Const AUX_SINGLE = 0
Public Const AUX_DOUBLE = 2
Public Const AUX_DIRECT = 0
Public Const AUX_INDIRECT = 4

Public Const nStep = 5
Public zLight As Double

Public ctrlpoints(0 To 3, 0 To 3, 0 To 2) As Single
Public theNurb As Long

Public Sub initLights()
        ceEnv.StartLighting
        ceEnv.SetLightAmbientf 0, 0.4, 0.6, 0.2, 1
        ceEnv.SetLightPositionf 0, 0, 1, 3, 1

        Dim mat_diffuse(0 To 3) As Single
        Dim mat_specular(0 To 3) As Single
        Dim mat_shininess(0 To 0) As Single

        ceBase.Materialf CEE3D_FRONT, CEE3D_DIFFUSE, mat_diffuse(0)
        ceBase.Materialf CEE3D_FRONT, CEE3D_SPECULAR, mat_specular(0)
        ceBase.Materialf CEE3D_FRONT, CEE3D_SHININESS, mat_shininess(0)

End Sub
Public Sub initSurface()
        Dim u As Integer, v As Integer
        For u = 0 To 3
                For v = 0 To 3
                        ctrlpoints(u, v, 0) = 2 * (u - 1.5)
                        ctrlpoints(u, v, 1) = 2 * (v - 1.5)
                        ctrlpoints(u, v, 2) = 8 * ((u + v) Mod 2 - 0.5)
                Next
        Next
End Sub

Public Sub myinit()
        ceBase.ClearColor 0, 0, 0, 1
        ceBase.Clear CEE3D_COLOR_BUFFER_BIT + CEE3D_DEPTH_BUFFER_BIT
        ceBase.Enable CEE3D_DEPTH_TEST
        ceBase.Map2f CEE3D_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, ctrlpoints(0, 0, 0)
        ceBase.Enable CEE3D_MAP2_VERTEX_3
        ceBase.Enable CEE3D_AUTO_NORMAL
        ceBase.Enable CEE3D_NORMALIZE
        ceBase.MapGrid2f 30, 0, 1, 30, 0, 1
        theNurb = ceUtil.NewNurbsRenderer
        ceUtil.NurbsProperty theNurb, CEE3DU_SAMPLING_TOLERANCE, 5
        ceUtil.NurbsProperty theNurb, CEE3DU_DISPLAY_MODE, CEE3DU_FILL

        initLights
        initSurface
End Sub

Public Sub display()

        Dim knots(0 To 7) As Single
        lt.initarray1f knots, "0,0,0,0,1,1,1,1"

        Dim trimA(0 To 4, 0 To 1) As Single
        lt.initarray2f trimA, "-10,-10;16,-10;16,16;-10,16;-10,-10"

        Dim curveknots(0 To 7) As Single
        lt.initarray1f curveknots, "0,0,0,0,0,0,0,0"

        Dim trimB(0 To 3, 0 To 1) As Single
        lt.initarray2f trimB, ".25,.7;.4,.68;.68,.4;.7,.25"

        Dim trimC(0 To 2, 0 To 1) As Single
        lt.initarray2f trimC, ".7,.25;.2,.2;.25,.7"

        Dim trimD(0 To 2, 0 To 1) As Single
        lt.initarray2f trimD, "1,1;.8,.6;1,.8"

        myinit

                ceBase.PushMatrix
                        ceBase.Rotatef 30, 1, 1, 1
                        ceBase.Rotatef -40, 0, 1, 0
                        ceBase.Scalef 0.8, 0.8, 0.8

                        ceUtil.BeginSurface theNurb
                                ceUtil.NurbsSurface theNurb, _
                                        8, knots(0), _
                                        8, knots(0), _
                                        4 * 3, 3, _
                                        ctrlpoints(0, 0, 0), _
                                        4, 4, _
                                        CEE3D_MAP2_VERTEX_3
                        If False Then
                                ceUtil.BeginTrim theNurb
                                        ceUtil.PwlCurve theNurb, 5, trimA(0, 0), 2, CEE3DU_MAP1_TRIM_2
                                ceUtil.EndTrim theNurb
                                ceUtil.BeginTrim theNurb
                                        ceUtil.NurbsCurve theNurb, 8, curveknots(0), 2, trimB(0, 0), 4, CEE3DU_MAP1_TRIM_2
                                        ceUtil.PwlCurve theNurb, 3, trimC(0, 0), 2, CEE3DU_MAP1_TRIM_2
                                ceUtil.EndTrim theNurb
                                ' ceutil.begintrim thenurb
                                ' ceutil.pwlcurve thenurb,3,trimd(0,0),2,CEE3Du_map1_trim_2
                                ' ceutil.pwlcurbe thenurb,3,trimd(0, 0), 2, CEE3Du_map1_trim_2
                                ' ceutil.endtrim thenurb
                        End If
                        ceUtil.EndSurface theNurb
                ceBase.PopMatrix

        ceBase.Flush
        ceAux.SwapBuffers

End Sub

Public Sub reshape(ByVal w As Long, ByVal h As Long)
        ceBase.Viewport 0, 0, w, h
End Sub

Public Sub cmdQuit()
        End
End Sub
Public Sub cmdLeft()
        ceBase.Rotated nStep, 0, 1, 0
End Sub
Public Sub cmdRight()
        ceBase.Rotated -nStep, 0, 1, 0
End Sub
Public Sub cmdUp()
        ceBase.Rotated nStep, 1, 0, 0
End Sub
Public Sub cmdDown()
        ceBase.Rotated -nStep, 1, 0, 0
End Sub
Public Sub cmdCW()
        ceBase.Rotated nStep, 0, 0, 1
End Sub
Public Sub cmdCCW()
        ceBase.Rotated -nStep, 0, 0, 1
End Sub

Public Sub cmdL0()
        If ceBase.IsEnabled(CEE3D_LIGHT0) Then
                ceBase.Disable CEE3D_LIGHT0
                ceBase.Disable CEE3D_LIGHTING
        Else
                ceBase.Enable CEE3D_LIGHT0
                ceBase.Enable CEE3D_LIGHTING
        End If
End Sub
Public Sub cmdL1()
        If ceBase.IsEnabled(CEE3D_LIGHT1) Then
                ceBase.Disable CEE3D_LIGHT1
        Else
                ceBase.Enable CEE3D_LIGHT1
        End If
End Sub
Public Sub cmdL2()
        If ceBase.IsEnabled(CEE3D_LIGHT2) Then
                ceBase.Disable CEE3D_LIGHT2
        Else
                ceBase.Enable CEE3D_LIGHT2
        End If
End Sub
Public Sub cmdL3()
        If ceBase.IsEnabled(CEE3D_LIGHT3) Then
                ceBase.Disable CEE3D_LIGHT3
        Else
                ceBase.Enable CEE3D_LIGHT3
        End If
End Sub
Public Sub cmdL4()
        If ceBase.IsEnabled(CEE3D_LIGHT4) Then
                ceBase.Disable CEE3D_LIGHT4
        Else
                ceBase.Enable CEE3D_LIGHT4
        End If
End Sub
Public Sub cmdL5()
        If ceBase.IsEnabled(CEE3D_LIGHT5) Then
                ceBase.Disable CEE3D_LIGHT5
        Else
                ceBase.Enable CEE3D_LIGHT5
        End If
End Sub
Public Sub cmdL6()
        If ceBase.IsEnabled(CEE3D_LIGHT6) Then
                ceBase.Disable CEE3D_LIGHT6
        Else
                ceBase.Enable CEE3D_LIGHT6
        End If
End Sub
Public Sub cmdL7()
        If ceBase.IsEnabled(CEE3D_LIGHT7) Then
                ceBase.Disable CEE3D_LIGHT7
        Else
                ceBase.Enable CEE3D_LIGHT7
        End If
End Sub

Public Sub cmdLNear()
        zLight = zLight - 0.2
End Sub
Public Sub cmdLFar()
        zLight = zLight + 0.2
End Sub

Public Sub cmdTest()
End Sub

Public Sub cmdTest2()
End Sub

Public Sub e3dMain()
        ceAux.InitDisplayMode AUX_DOUBLE
        ceAux.InitPosition 0, 0, 400, 400
        ceAux.InitWindowA "CeE3DInproc_Client2"
        ceBase.ClearColor 0, 0, 0, 1

        ceAux.ReshapeFunc AddressOf reshape
        ceAux.KeyFunc Asc("q"), AddressOf cmdQuit
        ceAux.KeyFunc 37, AddressOf cmdLeft
        ceAux.KeyFunc 38, AddressOf cmdUp
        ceAux.KeyFunc 39, AddressOf cmdRight
        ceAux.KeyFunc 40, AddressOf cmdDown
        ceAux.KeyFunc Asc("c"), AddressOf cmdCW
        ceAux.KeyFunc Asc("C"), AddressOf cmdCCW
        ceAux.KeyFunc Asc("0"), AddressOf cmdL0
        ceAux.KeyFunc Asc("1"), AddressOf cmdL1
        ceAux.KeyFunc Asc("2"), AddressOf cmdL2
        ceAux.KeyFunc Asc("3"), AddressOf cmdL3
        ceAux.KeyFunc Asc("4"), AddressOf cmdL4
        ceAux.KeyFunc Asc("5"), AddressOf cmdL5
        ceAux.KeyFunc Asc("6"), AddressOf cmdL6
        ceAux.KeyFunc Asc("7"), AddressOf cmdL7
        ceAux.KeyFunc Asc("N"), AddressOf cmdLNear
        ceAux.KeyFunc Asc("n"), AddressOf cmdLFar
        ceAux.KeyFunc Asc("t"), AddressOf cmdTest
        ceAux.KeyFunc Asc("T"), AddressOf cmdTest2

        ceBase.ShadeModel CEE3D_SMOOTH
        zLight = 0.6

        'ceEnv.StartLighting
        'ceEnv.EnableLight 0

        Do
                DoEvents
                display
        Loop
End Sub

Public Sub Main()
        Set lt = CreateObject("LowXTool.Array")

        e3dMain
End Sub
