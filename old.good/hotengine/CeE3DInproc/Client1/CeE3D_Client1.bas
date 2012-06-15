Attribute VB_Name = "modCeE3DInproc_Client1"
Option Explicit

Public Sub display()
        Dim mat_ambient(0 To 3) As Single
        Dim mat_specular(0 To 3) As Single
        Dim mat_shininess(0 To 0) As Single
        Dim light_position(0 To 3) As Single

        mat_ambient(0) = 1
        mat_ambient(1) = 0
        mat_ambient(2) = 0
        mat_ambient(3) = 0
        mat_specular(0) = 1
        mat_specular(1) = 1
        mat_specular(2) = 1
        mat_specular(3) = 1
        mat_shininess(0) = 60

        ceBase.Materialfv CEE3D_FRONT, CEE3D_AMBIENT, mat_ambient(0)
        ceBase.Materialfv CEE3D_FRONT, CEE3D_SPECULAR, mat_specular(0)
        ceBase.Materialfv CEE3D_FRONT, CEE3D_SHININESS, mat_shininess(0)

        ceEnv.SetLightPositionf 0, 0, 0.2, zLight, 0
        ceEnv.SetTwoSideModel True

        ceAux.ClearAll
        ceBase.Color3f 1, 0, 0

        ceAux.DrawSolidTorus 0.1, 0.7

        ceBase.PushMatrix
                Static trr As Double
                ceBase.Translatef -0.8, -0.8, 0
                ceBase.Rotatef trr, 0, 1, 0
                ceAux.DrawSolidCone 0.2, 0.2
                trr = trr + 5
        ceBase.PopMatrix

        ceAux.SwapBuffers
End Sub

Public Sub CeE3DInproc_Client1()

        CeE3DInitWin "CeE3DInproc_Client1"

        Do
                DoEvents
                display
        Loop
End Sub
