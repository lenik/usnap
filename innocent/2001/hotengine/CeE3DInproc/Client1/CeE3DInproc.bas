Attribute VB_Name = "modCeE3DInproc"
Option Explicit

Declare Sub glGetBooleanv Lib "opengl32.dll" (ByVal x As GLenum, ByRef ret As Byte)
Declare Sub glGetIntegerv Lib "opengl32.dll" (ByVal x As GLenum, ByVal ret As Long)

Declare Sub CeE3DInitDisplayMode Lib "CeE3DInproc" (ByVal m As Integer)
Declare Sub CeE3DInitPosition Lib "CeE3DInproc" (ByVal i As Long, ByVal i As Long, ByVal i As Long, ByVal i As Long)

Declare Function CeE3DInitWindowA Lib "CeE3DInproc" (ByVal caption As String) As Long
Declare Function CeE3DInitWindowW Lib "CeE3DInproc" (ByVal caption As String) As Long

Declare Sub CeE3DCloseWindow Lib "CeE3DInproc" ()
Declare Sub CeE3DQuit Lib "CeE3DInproc" ()
Declare Sub CeE3DSwapBuffers Lib "CeE3DInproc" ()

Declare Sub CeE3DMainLoop Lib "CeE3DInproc" (ByVal proc As Long)
Declare Sub CeE3DExposeFunc Lib "CeE3DInproc" (ByVal proc As Long)
Declare Sub CeE3DReshapeFunc Lib "CeE3DInproc" (ByVal proc As Long)
Declare Sub CeE3DIdleFunc Lib "CeE3DInproc" (ByVal proc As Long)
Declare Sub CeE3DKeyFunc Lib "CeE3DInproc" (ByVal i As Long, ByVal proc As Long)
Declare Sub CeE3DMouseFunc Lib "CeE3DInproc" (ByVal i1 As Long, ByVal i2 As Long, ByVal proc As Long)

Declare Function CeE3DGetColorMapSize Lib "CeE3DInproc" () As Long
Declare Function CeE3DGetMouseLoc Lib "CeE3DInproc" (ByRef x As Long, ByRef y As Long)
Declare Sub CeE3DSetOneColor Lib "CeE3DInproc" (ByVal i As Long, ByVal red As Single, ByVal green As Single, ByVal blue As Single)
Declare Sub CeE3DSetFogRamp Lib "CeE3DInproc" (ByVal i As Long, ByVal i As Long)
Declare Sub CeE3DSetGreyRamp Lib "CeE3DInproc" ()
Declare Sub CeE3DSetRGBMap Lib "CeE3DInproc" (ByVal i As Long, ByRef map As Single)

Declare Function CeE3DRGBImageLoadA Lib "CeE3DInproc" (ByVal s As String) As Long
Declare Function CeE3DRGBImageLoadW Lib "CeE3DInproc" (ByVal s As String) As Long
Declare Function CeE3DDIBImageLoadA Lib "CeE3DInproc" (ByVal s As String) As Long
Declare Function CeE3DDIBImageLoadW Lib "CeE3DInproc" (ByVal s As String) As Long

Declare Sub CeE3DCreateFont Lib "CeE3DInproc" ()
Declare Sub CeE3DDrawStrA Lib "CeE3DInproc" (ByVal text As String)
Declare Sub CeE3DDrawStrW Lib "CeE3DInproc" (ByVal text As String)

Declare Sub CeE3DWireSphere Lib "CeE3DInproc" (ByVal a As Double)
Declare Sub CeE3DSolidSphere Lib "CeE3DInproc" (ByVal a As Double)
Declare Sub CeE3DWireCube Lib "CeE3DInproc" (ByVal a As Double)
Declare Sub CeE3DSolidCube Lib "CeE3DInproc" (ByVal a As Double)
Declare Sub CeE3DWireBox Lib "CeE3DInproc" (ByVal a As Double, ByVal b As Double, ByVal c As Double)
Declare Sub CeE3DSolidBox Lib "CeE3DInproc" (ByVal a As Double, ByVal b As Double, ByVal c As Double)
Declare Sub CeE3DWireTorus Lib "CeE3DInproc" (ByVal a As Double, ByVal b As Double)
Declare Sub CeE3DSolidTorus Lib "CeE3DInproc" (ByVal a As Double, ByVal b As Double)
Declare Sub CeE3DWireCylinder Lib "CeE3DInproc" (ByVal a As Double, ByVal b As Double)
Declare Sub CeE3DSolidCylinder Lib "CeE3DInproc" (ByVal a As Double, ByVal b As Double)
Declare Sub CeE3DWireIcosahedron Lib "CeE3DInproc" (ByVal a As Double)
Declare Sub CeE3DSolidIcosahedron Lib "CeE3DInproc" (ByVal a As Double)
Declare Sub CeE3DWireOctahedron Lib "CeE3DInproc" (ByVal a As Double)
Declare Sub CeE3DSolidOctahedron Lib "CeE3DInproc" (ByVal a As Double)
Declare Sub CeE3DWireTetrahedron Lib "CeE3DInproc" (ByVal a As Double)
Declare Sub CeE3DSolidTetrahedron Lib "CeE3DInproc" (ByVal a As Double)
Declare Sub CeE3DWireDodecahedron Lib "CeE3DInproc" (ByVal a As Double)
Declare Sub CeE3DSolidDodecahedron Lib "CeE3DInproc" (ByVal a As Double)
Declare Sub CeE3DWireCone Lib "CeE3DInproc" (ByVal a As Double, ByVal b As Double)
Declare Sub CeE3DSolidCone Lib "CeE3DInproc" (ByVal a As Double, ByVal b As Double)
Declare Sub CeE3DWireTeapot Lib "CeE3DInproc" (ByVal a As Double)
Declare Sub CeE3DSolidTeapot Lib "CeE3DInproc" (ByVal a As Double)
Declare Function CeE3DGetHWND Lib "CeE3DInproc" () As Long
Declare Function CeE3DGetHDC Lib "CeE3DInproc" () As Long
Declare Function CeE3DGetHGLRC Lib "CeE3DInproc" () As Long
Declare Sub CeE3DInitDisplayModePolicy Lib "CeE3DInproc" (ByVal m As Long)
Declare Function CeE3DInitDisplayModeID Lib "CeE3DInproc" (ByVal i As Long) As Long
Declare Function CeE3DGetDisplayModePolicy Lib "CeE3DInproc" () As Long
Declare Function CeE3DGetDisplayModeID Lib "CeE3DInproc" () As Long
Declare Function CeE3DGetDisplayMode Lib "CeE3DInproc" () As Long

Public Function getbool(ByVal x As GLenum) As Byte
        Dim xx As Byte
        glGetBooleanv x, xx
        getbool = xx
End Function
Public Function getint(ByVal x As GLenum) As Long
        Dim xx As Long
        glGetIntegerv x, xx
        getint = xx
End Function
