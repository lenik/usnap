Attribute VB_Name = "Module1"
Option Explicit

Type POINT
        X As Double
        Y As Double
        k As Double
End Type

Public ps(0 To 100) As POINT
Public ps2(0 To 100) As POINT
Public nps As Long

Public k(0 To 2, 0 To 2) As Double

Public u_w As Double
Public u_h As Double
Public Const K_range As Double = 1
Public area As Double

Public Sub init()
        nps = 5
        ps(0).X = 10
        ps(0).Y = 10
        ps(0).k = 1
        ps(1).X = 1000
        ps(1).Y = 10
        ps(1).k = 1
        ps(2).X = 1000
        ps(2).Y = 800
        ps(2).k = 1
        ps(3).X = 10
        ps(3).Y = 800
        ps(3).k = 1
        ps(4).X = 10
        ps(4).Y = 10
        ps(4).k = 1
End Sub
