Attribute VB_Name = "modCeE3DInproc"
Option Explicit

Public Const AUX_RGB = 0
Public Const AUX_RGBA = 0
Public Const AUX_SINGLE = 0
Public Const AUX_DOUBLE = 2
Public Const AUX_DIRECT = 0
Public Const AUX_INDIRECT = 4

Public Const GL_CURRENT_BIT = &H1&
Public Const GL_POINT_BIT = &H2&
Public Const GL_LINE_BIT = &H4&
Public Const GL_POLYGON_BIT = &H8&
Public Const GL_POLYGON_STIPPLE_BIT = &H10&
Public Const GL_PIXEL_MODE_BIT = &H20&
Public Const GL_LIGHTING_BIT = &H40&
Public Const GL_FOG_BIT = &H80&
Public Const GL_DEPTH_BUFFER_BIT = &H100&
Public Const GL_ACCUM_BUFFER_BIT = &H200&
Public Const GL_STENCIL_BUFFER_BIT = &H400&
Public Const GL_VIEWPORT_BIT = &H800&
Public Const GL_TRANSFORM_BIT = &H1000&
Public Const GL_ENABLE_BIT = &H2000&
Public Const GL_COLOR_BUFFER_BIT = &H4000&
Public Const GL_HINT_BIT = &H8000&
Public Const GL_EVAL_BIT = &H10000
Public Const GL_LIST_BIT = &H20000
Public Const GL_TEXTURE_BIT = &H40000
Public Const GL_SCISSOR_BIT = &H80000
Public Const GL_ALL_ATTRIB_BITS = &HFFFFF

Public Const GL_POINTS = &H0&
Public Const GL_LINES = &H1&
Public Const GL_LINE_LOOP = &H2&
Public Const GL_LINE_STRIP = &H3&
Public Const GL_TRIANGLES = &H4&
Public Const GL_TRIANGLE_STRIP = &H5&
Public Const GL_TRIANGLE_FAN = &H6&
Public Const GL_QUADS = &H7&
Public Const GL_QUAD_STRIP = &H8&
Public Const GL_POLYGON = &H9&

Public Const GL_ZERO = 0&
Public Const GL_ONE = 1&
Public Const GL_SRC_COLOR = &H300&
Public Const GL_ONE_MINUS_SRC_COLOR = &H301&
Public Const GL_SRC_ALPHA = &H302&
Public Const GL_ONE_MINUS_SRC_ALPHA = &H303&
Public Const GL_DST_ALPHA = &H304&
Public Const GL_ONE_MINUS_DST_ALPHA = &H305&

Public Const GL_DST_COLOR = &H306&
Public Const GL_ONE_MINUS_DST_COLOR = &H307&
Public Const GL_SRC_ALPHA_SATURATE = &H308&

Public Const GL_TRUE = 1&
Public Const GL_FALSE = 0&


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
