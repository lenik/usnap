Attribute VB_Name = "modCeE3D_Client1"
Option Explicit

Dim ceBase As New CeE3DBase

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

Public Sub display()
        ceBase.Clear GL_COLOR_BUFFER_BIT
        ceBase.Color4f 0.2, 0.8, 1#, 1#
        CeE3DWireCube 1#
        ceBase.Flush
End Sub

Public Sub reshape(ByVal w As Long, ByVal h As Long)
        ceBase.Viewport 0, 0, w, h
End Sub

Public Sub e3dmain()
        CeE3DInitDisplayMode 0
        CeE3DInitPosition 0, 0, 400, 400
        CeE3DInitWindowA "Sample"
        ceBase.ClearColor 0, 0, 0, 0

        CeE3DReshapeFunc AddressOf reshape
        CeE3DMainLoop AddressOf display

End Sub
