VERSION 5.00
Begin VB.Form frm_Snow
   BorderStyle     =   0  'None
   Caption         =   "ѩ��ƮѽƮ"
   ClientHeight    =   1530
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   1590
   Icon            =   "f2_snow.frx":0000
   LinkTopic       =   "Form1"
   Picture         =   "f2_snow.frx":0E42
   ScaleHeight     =   102
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   106
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  'Windows Default
End
Attribute VB_Name = "frm_Snow"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Load()
        Dim pts(0 To 14) As POINTAPI
        Dim startpoly As String
        Dim pa As String
        Dim I As Integer
        Dim hRgn As Long

        startpoly = "# 7, 6 # 48, 12 # 89, 2 # 101, 25 # 95, 47 # 76, 51 # 86, 76 " & _
                        "# 67, 75 # 56, 96 # 22, 81 # 4, 89 # 19, 58 # 0, 47 # 15, 32"

        For I = 0 To 13
                pa = lt_s.decodePart(startpoly, I + 1)
                pts(I).X = val(lt_s.decodePart(pa, 0, False, ","))
                pts(I).Y = val(lt_s.decodePart(pa, 1, False, ","))
        Next

        hRgn = CreatePolygonRgn(pts(0), 14, 1)
        If hRgn <> 0 Then
                SelectClipRgn frm_Snow.hdc, hRgn
        End If
End Sub
