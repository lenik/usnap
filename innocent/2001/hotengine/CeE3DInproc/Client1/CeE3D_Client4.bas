Attribute VB_Name = "Module1"
Option Explicit

Public Sub display()
        ceBase.ClearColor 0, 0, 0, 1
        ceBase.Clear CEE3D_COLOR_BUFFER_BIT + CEE3D_DEPTH_BUFFER_BIT
        'ceAux.ClearAll
        ceBase.Rotatef 1, 1, 1, 1
        ceAux.DrawSolidCone 0.6, 0.6
        ceAux.SwapBuffers
End Sub

Public Sub Main()
        CeE3DInitWin "Hello"
        Do
                display
                DoEvents
        Loop
End Sub
