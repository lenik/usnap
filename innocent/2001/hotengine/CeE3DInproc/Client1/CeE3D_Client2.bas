Attribute VB_Name = "modCeE3DInproc_Client2"
Option Explicit

Public Sub display()
        ceEnv.SetLightPositionf 0, xLight, yLight, zLight, 0

        ceBase.ClearColor 0, 0, 0, 1
        ceBase.Clear CEE3D_COLOR_BUFFER_BIT + CEE3D_DEPTH_BUFFER_BIT

        ceBase.Color3f 1, 0, 0
        ceAux.DrawSolidTorus 0.1, 0.7

        ceBase.Flush
        ceAux.SwapBuffers
End Sub

Public Sub CeE3DInproc_Client2()
        CeE3DInitWin "CeE3DInproc_Client2"

        ceEnv.StartLighting
        ceEnv.EnableLight 0

        Do
                DoEvents
                display
        Loop
End Sub
