Attribute VB_Name = "modCeE3D_Window"
Option Explicit

Public ceBase As New CeE3DBase
Public ceAux As New CeE3DAux
Public ceModel As New CeE3DModel
Public ceUtil As New CeE3DUtil
Public ceEnv As New CeE3DEnv
Public ceRender As New CeE3DRender

Public Const nStep = 5
Public nLight As Integer, xLight As Double, yLight As Double, zLight As Double

Public Sub Reshape(ByVal w As Long, ByVal h As Long)
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
Public Sub cmdScaleIn()
        ceBase.Scaled 1.05, 1.05, 1.05
End Sub
Public Sub cmdScaleout()
        ceBase.Scaled 0.952, 0.952, 0.952
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

Public Sub cmdLnLeft()
        xLight = xLight - 0.02
End Sub
Public Sub cmdLnRight()
        xLight = xLight + 0.02
End Sub
Public Sub cmdLnUp()
        yLight = yLight - 0.02
End Sub
Public Sub cmdLnDown()
        yLight = yLight + 0.02
End Sub
Public Sub cmdLnNear()
        zLight = zLight - 0.02
End Sub
Public Sub cmdLnFar()
        zLight = zLight + 0.02
End Sub
Public Sub cmdLnPrev()
        nLight = (nLight + 7) Mod 8
End Sub
Public Sub cmdLnNext()
        nLight = (nLight + 1) Mod 8
End Sub

Public Sub cmdTest()
End Sub

Public Sub cmdTest2()
        MsgBox "Test"
End Sub

Public Sub CeE3DInitWin(ByVal title As String)
        ceAux.InitDisplayMode 2
        ceAux.InitPosition 0, 0, 400, 400
        ceAux.InitWindow title

        ceAux.ReshapeFunc AddressOf Reshape

        ceAux.KeyFunc Asc("q"), AddressOf cmdQuit
        ceAux.KeyFunc 37, AddressOf cmdLeft
        ceAux.KeyFunc 38, AddressOf cmdUp
        ceAux.KeyFunc 39, AddressOf cmdRight
        ceAux.KeyFunc 40, AddressOf cmdDown
        ceAux.KeyFunc Asc("o"), AddressOf cmdCW
        ceAux.KeyFunc Asc("p"), AddressOf cmdCCW
        ceAux.KeyFunc Asc("z"), AddressOf cmdScaleIn
        ceAux.KeyFunc Asc("Z"), AddressOf cmdScaleout
        ceAux.KeyFunc Asc("0"), AddressOf cmdL0
        ceAux.KeyFunc Asc("1"), AddressOf cmdL1
        ceAux.KeyFunc Asc("2"), AddressOf cmdL2
        ceAux.KeyFunc Asc("3"), AddressOf cmdL3
        ceAux.KeyFunc Asc("4"), AddressOf cmdL4
        ceAux.KeyFunc Asc("5"), AddressOf cmdL5
        ceAux.KeyFunc Asc("6"), AddressOf cmdL6
        ceAux.KeyFunc Asc("7"), AddressOf cmdL7

        ceAux.KeyFunc Asc("s"), AddressOf cmdLnLeft
        ceAux.KeyFunc Asc("f"), AddressOf cmdLnRight
        ceAux.KeyFunc Asc("e"), AddressOf cmdLnUp
        ceAux.KeyFunc Asc("d"), AddressOf cmdLnDown
        ceAux.KeyFunc Asc("w"), AddressOf cmdLnNear
        ceAux.KeyFunc Asc("r"), AddressOf cmdLnFar
        ceAux.KeyFunc Asc("x"), AddressOf cmdLnPrev
        ceAux.KeyFunc Asc("v"), AddressOf cmdLnNext

        ceAux.KeyFunc Asc("t"), AddressOf cmdTest
        ceAux.KeyFunc Asc("T"), AddressOf cmdTest2

        nLight = 0
        xLight = 0.5
        yLight = 0.5
        zLight = 0.5

        ceBase.ShadeModel CEE3D_SMOOTH

        ceEnv.StartLighting
        ceEnv.EnableLight 0
        'ceEnv.SetLightPositionf 0, 0.5, 0.5, zLight, 0

        ceRender.SetDepthFunc DEPTHFUNC_LEQUAL
        ceEnv.SetTwoSideModel True

End Sub
