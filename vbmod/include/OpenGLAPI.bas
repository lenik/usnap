Attribute VB_Name = "OpenGLAPI"
' OpenGL API      By DanSei

'typedef unsigned int as integer
'typedef unsigned char as byte
'typedef unsigned int as integer
'typedef signed char as byte
'typedef short as integer
'typedef int as integer
'typedef int as integer
'typedef unsigned char as byte
'typedef unsigned short as integer
'typedef unsigned int as integer
'typedef float as single
'typedef float as single
'typedef double as double
'typedef double as double
'typedef void as any


'***********************************************************

' AccumOp
Public Const GL_ACCUM = &H100
Public Const GL_LOAD = &H101
Public Const GL_RETURN = &H102
Public Const GL_MULT = &H103
Public Const GL_ADD = &H104

' AlphaFunction
Public Const GL_NEVER = &H200
Public Const GL_LESS = &H201
Public Const GL_EQUAL = &H202
Public Const GL_LEQUAL = &H203
Public Const GL_GREATER = &H204
Public Const GL_NOTEQUAL = &H205
Public Const GL_GEQUAL = &H206
Public Const GL_ALWAYS = &H207

' AttribMask
Public Const GL_CURRENT_BIT = &H1
Public Const GL_POINT_BIT = &H2
Public Const GL_LINE_BIT = &H4
Public Const GL_POLYGON_BIT = &H8
Public Const GL_POLYGON_STIPPLE_BIT = &H10
Public Const GL_PIXEL_MODE_BIT = &H20
Public Const GL_LIGHTING_BIT = &H40
Public Const GL_FOG_BIT = &H80
Public Const GL_DEPTH_BUFFER_BIT = &H100
Public Const GL_ACCUM_BUFFER_BIT = &H200
Public Const GL_STENCIL_BUFFER_BIT = &H400
Public Const GL_VIEWPORT_BIT = &H800
Public Const GL_TRANSFORM_BIT = &H1000
Public Const GL_ENABLE_BIT = &H2000
Public Const GL_COLOR_BUFFER_BIT = &H4000
Public Const GL_HINT_BIT = &H8000
Public Const GL_EVAL_BIT = &H10000
Public Const GL_LIST_BIT = &H20000
Public Const GL_TEXTURE_BIT = &H40000
Public Const GL_SCISSOR_BIT = &H80000
Public Const GL_ALL_ATTRIB_BITS = &HFFFFF

' BeginMode
Public Const GL_POINTS = &H0
Public Const GL_LINES = &H1
Public Const GL_LINE_LOOP = &H2
Public Const GL_LINE_STRIP = &H3
Public Const GL_TRIANGLES = &H4
Public Const GL_TRIANGLE_STRIP = &H5
Public Const GL_TRIANGLE_FAN = &H6
Public Const GL_QUADS = &H7
Public Const GL_QUAD_STRIP = &H8
Public Const GL_POLYGON = &H9

' BlendingFactorDest
Public Const GL_ZERO = 0
Public Const GL_ONE = 1
Public Const GL_SRC_COLOR = &H300
Public Const GL_ONE_MINUS_SRC_COLOR = &H301
Public Const GL_SRC_ALPHA = &H302
Public Const GL_ONE_MINUS_SRC_ALPHA = &H303
Public Const GL_DST_ALPHA = &H304
Public Const GL_ONE_MINUS_DST_ALPHA = &H305

' BlendingFactorSrc
'      GL_ZERO
'      GL_ONE
Public Const GL_DST_COLOR = &H306
Public Const GL_ONE_MINUS_DST_COLOR = &H307
Public Const GL_SRC_ALPHA_SATURATE = &H308
'      GL_SRC_ALPHA
'      GL_ONE_MINUS_SRC_ALPHA
'      GL_DST_ALPHA
'      GL_ONE_MINUS_DST_ALPHA

' Boolean
Public Const GL_TRUE = 1
Public Const GL_FALSE = 0

' ClearBufferMask
'      GL_COLOR_BUFFER_BIT
'      GL_ACCUM_BUFFER_BIT
'      GL_STENCIL_BUFFER_BIT
'      GL_DEPTH_BUFFER_BIT

' ClipPlaneName
Public Const GL_CLIP_PLANE0 = &H3000
Public Const GL_CLIP_PLANE1 = &H3001
Public Const GL_CLIP_PLANE2 = &H3002
Public Const GL_CLIP_PLANE3 = &H3003
Public Const GL_CLIP_PLANE4 = &H3004
Public Const GL_CLIP_PLANE5 = &H3005

' ColorMaterialFace
'      GL_FRONT
'      GL_BACK
'      GL_FRONT_AND_BACK

' ColorMaterialParameter
'      GL_AMBIENT
'      GL_DIFFUSE
'      GL_SPECULAR
'      GL_EMISSION
'      GL_AMBIENT_AND_DIFFUSE

' ColorPointerType
'      GL_BYTE
'      GL_UNSIGNED_BYTE
'      GL_SHORT
'      GL_UNSIGNED_SHORT
'      GL_INT
'      GL_UNSIGNED_INT
'      GL_FLOAT
'      GL_DOUBLE_EXT

' CullFaceMode
'      GL_FRONT
'      GL_BACK
'      GL_FRONT_AND_BACK

' DepthFunction
'      GL_NEVER
'      GL_LESS
'      GL_EQUAL
'      GL_LEQUAL
'      GL_GREATER
'      GL_NOTEQUAL
'      GL_GEQUAL
'      GL_ALWAYS

' DrawBufferMode
Public Const GL_NONE = 0
Public Const GL_FRONT_LEFT = &H400
Public Const GL_FRONT_RIGHT = &H401
Public Const GL_BACK_LEFT = &H402
Public Const GL_BACK_RIGHT = &H403
Public Const GL_FRONT = &H404
Public Const GL_BACK = &H405
Public Const GL_LEFT = &H406
Public Const GL_RIGHT = &H407
Public Const GL_FRONT_AND_BACK = &H408
Public Const GL_AUX0 = &H409
Public Const GL_AUX1 = &H40A
Public Const GL_AUX2 = &H40B
Public Const GL_AUX3 = &H40C

' Enable
'      GL_FOG
'      GL_LIGHTING
'      GL_TEXTURE_1D
'      GL_TEXTURE_2D
'      GL_LINE_STIPPLE
'      GL_POLYGON_STIPPLE
'      GL_CULL_FACE
'      GL_ALPHA_TEST
'      GL_BLEND
'      GL_LOGIC_OP
'      GL_DITHER
'      GL_STENCIL_TEST
'      GL_DEPTH_TEST
'      GL_CLIP_PLANE0
'      GL_CLIP_PLANE1
'      GL_CLIP_PLANE2
'      GL_CLIP_PLANE3
'      GL_CLIP_PLANE4
'      GL_CLIP_PLANE5
'      GL_LIGHT0
'      GL_LIGHT1
'      GL_LIGHT2
'      GL_LIGHT3
'      GL_LIGHT4
'      GL_LIGHT5
'      GL_LIGHT6
'      GL_LIGHT7
'      GL_TEXTURE_GEN_S
'      GL_TEXTURE_GEN_T
'      GL_TEXTURE_GEN_R
'      GL_TEXTURE_GEN_Q
'      GL_MAP1_VERTEX_3
'      GL_MAP1_VERTEX_4
'      GL_MAP1_COLOR_4
'      GL_MAP1_INDEX
'      GL_MAP1_NORMAL
'      GL_MAP1_TEXTURE_COORD_1
'      GL_MAP1_TEXTURE_COORD_2
'      GL_MAP1_TEXTURE_COORD_3
'      GL_MAP1_TEXTURE_COORD_4
'      GL_MAP2_VERTEX_3
'      GL_MAP2_VERTEX_4
'      GL_MAP2_COLOR_4
'      GL_MAP2_INDEX
'      GL_MAP2_NORMAL
'      GL_MAP2_TEXTURE_COORD_1
'      GL_MAP2_TEXTURE_COORD_2
'      GL_MAP2_TEXTURE_COORD_3
'      GL_MAP2_TEXTURE_COORD_4
'      GL_POINT_SMOOTH
'      GL_LINE_SMOOTH
'      GL_POLYGON_SMOOTH
'      GL_SCISSOR_TEST
'      GL_COLOR_MATERIAL
'      GL_NORMALIZE
'      GL_AUTO_NORMAL
'      GL_VERTEX_ARRAY_EXT
'      GL_NORMAL_ARRAY_EXT
'      GL_COLOR_ARRAY_EXT
'      GL_INDEX_ARRAY_EXT
'      GL_TEXTURE_COORD_ARRAY_EXT
'      GL_EDGE_FLAG_ARRAY_EXT

' ErrorCode
Public Const GL_NO_ERROR = 0
Public Const GL_INVALID_ENUM = &H500
Public Const GL_INVALID_VALUE = &H501
Public Const GL_INVALID_OPERATION = &H502
Public Const GL_STACK_OVERFLOW = &H503
Public Const GL_STACK_UNDERFLOW = &H504
Public Const GL_OUT_OF_MEMORY = &H505

' FeedBackMode
Public Const GL_2D = &H600
Public Const GL_3D = &H601
Public Const GL_3D_COLOR = &H602
Public Const GL_3D_COLOR_TEXTURE = &H603
Public Const GL_4D_COLOR_TEXTURE = &H604

' FeedBackToken
Public Const GL_PASS_THROUGH_TOKEN = &H700
Public Const GL_POINT_TOKEN = &H701
Public Const GL_LINE_TOKEN = &H702
Public Const GL_POLYGON_TOKEN = &H703
Public Const GL_BITMAP_TOKEN = &H704
Public Const GL_DRAW_PIXEL_TOKEN = &H705
Public Const GL_COPY_PIXEL_TOKEN = &H706
Public Const GL_LINE_RESET_TOKEN = &H707

' FogMode
'      GL_LINEAR
Public Const GL_EXP = &H800
Public Const GL_EXP2 = &H801

' FogParameter
'      GL_FOG_COLOR
'      GL_FOG_DENSITY
'      GL_FOG_END
'      GL_FOG_INDEX
'      GL_FOG_MODE
'      GL_FOG_START

' FrontFaceDirection
Public Const GL_CW = &H900
Public Const GL_CCW = &H901

' GetMapTarget
Public Const GL_COEFF = &HA00
Public Const GL_ORDER = &HA01
Public Const GL_DOMAIN = &HA02

' GetPixelMap
'      GL_PIXEL_MAP_I_TO_I
'      GL_PIXEL_MAP_S_TO_S
'      GL_PIXEL_MAP_I_TO_R
'      GL_PIXEL_MAP_I_TO_G
'      GL_PIXEL_MAP_I_TO_B
'      GL_PIXEL_MAP_I_TO_A
'      GL_PIXEL_MAP_R_TO_R
'      GL_PIXEL_MAP_G_TO_G
'      GL_PIXEL_MAP_B_TO_B
'      GL_PIXEL_MAP_A_TO_A

' GetPointerTarget
'      GL_VERTEX_ARRAY_POINTER_EXT
'      GL_NORMAL_ARRAY_POINTER_EXT
'      GL_COLOR_ARRAY_POINTER_EXT
'      GL_INDEX_ARRAY_POINTER_EXT
'      GL_TEXTURE_COORD_ARRAY_POINTER_EXT
'      GL_EDGE_FLAG_ARRAY_POINTER_EXT

' GetTarget
Public Const GL_CURRENT_COLOR = &HB00
Public Const GL_CURRENT_INDEX = &HB01
Public Const GL_CURRENT_NORMAL = &HB02
Public Const GL_CURRENT_TEXTURE_COORDS = &HB03
Public Const GL_CURRENT_RASTER_COLOR = &HB04
Public Const GL_CURRENT_RASTER_INDEX = &HB05
Public Const GL_CURRENT_RASTER_TEXTURE_COORDS = &HB06
Public Const GL_CURRENT_RASTER_POSITION = &HB07
Public Const GL_CURRENT_RASTER_POSITION_VALID = &HB08
Public Const GL_CURRENT_RASTER_DISTANCE = &HB09
Public Const GL_POINT_SMOOTH = &HB10
Public Const GL_POINT_SIZE = &HB11
Public Const GL_POINT_SIZE_RANGE = &HB12
Public Const GL_POINT_SIZE_GRANULARITY = &HB13
Public Const GL_LINE_SMOOTH = &HB20
Public Const GL_LINE_WIDTH = &HB21
Public Const GL_LINE_WIDTH_RANGE = &HB22
Public Const GL_LINE_WIDTH_GRANULARITY = &HB23
Public Const GL_LINE_STIPPLE = &HB24
Public Const GL_LINE_STIPPLE_PATTERN = &HB25
Public Const GL_LINE_STIPPLE_REPEAT = &HB26
Public Const GL_LIST_MODE = &HB30
Public Const GL_MAX_LIST_NESTING = &HB31
Public Const GL_LIST_BASE = &HB32
Public Const GL_LIST_INDEX = &HB33
Public Const GL_POLYGON_MODE = &HB40
Public Const GL_POLYGON_SMOOTH = &HB41
Public Const GL_POLYGON_STIPPLE = &HB42
Public Const GL_EDGE_FLAG = &HB43
Public Const GL_CULL_FACE = &HB44
Public Const GL_CULL_FACE_MODE = &HB45
Public Const GL_FRONT_FACE = &HB46
Public Const GL_LIGHTING = &HB50
Public Const GL_LIGHT_MODEL_LOCAL_VIEWER = &HB51
Public Const GL_LIGHT_MODEL_TWO_SIDE = &HB52
Public Const GL_LIGHT_MODEL_AMBIENT = &HB53
Public Const GL_SHADE_MODEL = &HB54
Public Const GL_COLOR_MATERIAL_FACE = &HB55
Public Const GL_COLOR_MATERIAL_PARAMETER = &HB56
Public Const GL_COLOR_MATERIAL = &HB57
Public Const GL_FOG = &HB60
Public Const GL_FOG_INDEX = &HB61
Public Const GL_FOG_DENSITY = &HB62
Public Const GL_FOG_START = &HB63
Public Const GL_FOG_END = &HB64
Public Const GL_FOG_MODE = &HB65
Public Const GL_FOG_COLOR = &HB66
Public Const GL_DEPTH_RANGE = &HB70
Public Const GL_DEPTH_TEST = &HB71
Public Const GL_DEPTH_WRITEMASK = &HB72
Public Const GL_DEPTH_CLEAR_VALUE = &HB73
Public Const GL_DEPTH_FUNC = &HB74
Public Const GL_ACCUM_CLEAR_VALUE = &HB80
Public Const GL_STENCIL_TEST = &HB90
Public Const GL_STENCIL_CLEAR_VALUE = &HB91
Public Const GL_STENCIL_FUNC = &HB92
Public Const GL_STENCIL_VALUE_MASK = &HB93
Public Const GL_STENCIL_FAIL = &HB94
Public Const GL_STENCIL_PASS_DEPTH_FAIL = &HB95
Public Const GL_STENCIL_PASS_DEPTH_PASS = &HB96
Public Const GL_STENCIL_REF = &HB97
Public Const GL_STENCIL_WRITEMASK = &HB98
Public Const GL_MATRIX_MODE = &HBA0
Public Const GL_NORMALIZE = &HBA1
Public Const GL_VIEWPORT = &HBA2
Public Const GL_MODELVIEW_STACK_DEPTH = &HBA3
Public Const GL_PROJECTION_STACK_DEPTH = &HBA4
Public Const GL_TEXTURE_STACK_DEPTH = &HBA5
Public Const GL_MODELVIEW_MATRIX = &HBA6
Public Const GL_PROJECTION_MATRIX = &HBA7
Public Const GL_TEXTURE_MATRIX = &HBA8
Public Const GL_ATTRIB_STACK_DEPTH = &HBB0
Public Const GL_ALPHA_TEST = &HBC0
Public Const GL_ALPHA_TEST_FUNC = &HBC1
Public Const GL_ALPHA_TEST_REF = &HBC2
Public Const GL_DITHER = &HBD0
Public Const GL_BLEND_DST = &HBE0
Public Const GL_BLEND_SRC = &HBE1
Public Const GL_BLEND = &HBE2
Public Const GL_LOGIC_OP_MODE = &HBF0
Public Const GL_LOGIC_OP = &HBF1
Public Const GL_AUX_BUFFERS = &HC00
Public Const GL_DRAW_BUFFER = &HC01
Public Const GL_READ_BUFFER = &HC02
Public Const GL_SCISSOR_BOX = &HC10
Public Const GL_SCISSOR_TEST = &HC11
Public Const GL_INDEX_CLEAR_VALUE = &HC20
Public Const GL_INDEX_WRITEMASK = &HC21
Public Const GL_COLOR_CLEAR_VALUE = &HC22
Public Const GL_COLOR_WRITEMASK = &HC23
Public Const GL_INDEX_MODE = &HC30
Public Const GL_RGBA_MODE = &HC31
Public Const GL_DOUBLEBUFFER = &HC32
Public Const GL_STEREO = &HC33
Public Const GL_RENDER_MODE = &HC40
Public Const GL_PERSPECTIVE_CORRECTION_HINT = &HC50
Public Const GL_POINT_SMOOTH_HINT = &HC51
Public Const GL_LINE_SMOOTH_HINT = &HC52
Public Const GL_POLYGON_SMOOTH_HINT = &HC53
Public Const GL_FOG_HINT = &HC54
Public Const GL_TEXTURE_GEN_S = &HC60
Public Const GL_TEXTURE_GEN_T = &HC61
Public Const GL_TEXTURE_GEN_R = &HC62
Public Const GL_TEXTURE_GEN_Q = &HC63
Public Const GL_PIXEL_MAP_I_TO_I = &HC70
Public Const GL_PIXEL_MAP_S_TO_S = &HC71
Public Const GL_PIXEL_MAP_I_TO_R = &HC72
Public Const GL_PIXEL_MAP_I_TO_G = &HC73
Public Const GL_PIXEL_MAP_I_TO_B = &HC74
Public Const GL_PIXEL_MAP_I_TO_A = &HC75
Public Const GL_PIXEL_MAP_R_TO_R = &HC76
Public Const GL_PIXEL_MAP_G_TO_G = &HC77
Public Const GL_PIXEL_MAP_B_TO_B = &HC78
Public Const GL_PIXEL_MAP_A_TO_A = &HC79
Public Const GL_PIXEL_MAP_I_TO_I_SIZE = &HCB0
Public Const GL_PIXEL_MAP_S_TO_S_SIZE = &HCB1
Public Const GL_PIXEL_MAP_I_TO_R_SIZE = &HCB2
Public Const GL_PIXEL_MAP_I_TO_G_SIZE = &HCB3
Public Const GL_PIXEL_MAP_I_TO_B_SIZE = &HCB4
Public Const GL_PIXEL_MAP_I_TO_A_SIZE = &HCB5
Public Const GL_PIXEL_MAP_R_TO_R_SIZE = &HCB6
Public Const GL_PIXEL_MAP_G_TO_G_SIZE = &HCB7
Public Const GL_PIXEL_MAP_B_TO_B_SIZE = &HCB8
Public Const GL_PIXEL_MAP_A_TO_A_SIZE = &HCB9
Public Const GL_UNPACK_SWAP_BYTES = &HCF0
Public Const GL_UNPACK_LSB_FIRST = &HCF1
Public Const GL_UNPACK_ROW_LENGTH = &HCF2
Public Const GL_UNPACK_SKIP_ROWS = &HCF3
Public Const GL_UNPACK_SKIP_PIXELS = &HCF4
Public Const GL_UNPACK_ALIGNMENT = &HCF5
Public Const GL_PACK_SWAP_BYTES = &HD00
Public Const GL_PACK_LSB_FIRST = &HD01
Public Const GL_PACK_ROW_LENGTH = &HD02
Public Const GL_PACK_SKIP_ROWS = &HD03
Public Const GL_PACK_SKIP_PIXELS = &HD04
Public Const GL_PACK_ALIGNMENT = &HD05
Public Const GL_MAP_COLOR = &HD10
Public Const GL_MAP_STENCIL = &HD11
Public Const GL_INDEX_SHIFT = &HD12
Public Const GL_INDEX_OFFSET = &HD13
Public Const GL_RED_SCALE = &HD14
Public Const GL_RED_BIAS = &HD15
Public Const GL_ZOOM_X = &HD16
Public Const GL_ZOOM_Y = &HD17
Public Const GL_GREEN_SCALE = &HD18
Public Const GL_GREEN_BIAS = &HD19
Public Const GL_BLUE_SCALE = &HD1A
Public Const GL_BLUE_BIAS = &HD1B
Public Const GL_ALPHA_SCALE = &HD1C
Public Const GL_ALPHA_BIAS = &HD1D
Public Const GL_DEPTH_SCALE = &HD1E
Public Const GL_DEPTH_BIAS = &HD1F
Public Const GL_MAX_EVAL_ORDER = &HD30
Public Const GL_MAX_LIGHTS = &HD31
Public Const GL_MAX_CLIP_PLANES = &HD32
Public Const GL_MAX_TEXTURE_SIZE = &HD33
Public Const GL_MAX_PIXEL_MAP_TABLE = &HD34
Public Const GL_MAX_ATTRIB_STACK_DEPTH = &HD35
Public Const GL_MAX_MODELVIEW_STACK_DEPTH = &HD36
Public Const GL_MAX_NAME_STACK_DEPTH = &HD37
Public Const GL_MAX_PROJECTION_STACK_DEPTH = &HD38
Public Const GL_MAX_TEXTURE_STACK_DEPTH = &HD39
Public Const GL_MAX_VIEWPORT_DIMS = &HD3A
Public Const GL_SUBPIXEL_BITS = &HD50
Public Const GL_INDEX_BITS = &HD51
Public Const GL_RED_BITS = &HD52
Public Const GL_GREEN_BITS = &HD53
Public Const GL_BLUE_BITS = &HD54
Public Const GL_ALPHA_BITS = &HD55
Public Const GL_DEPTH_BITS = &HD56
Public Const GL_STENCIL_BITS = &HD57
Public Const GL_ACCUM_RED_BITS = &HD58
Public Const GL_ACCUM_GREEN_BITS = &HD59
Public Const GL_ACCUM_BLUE_BITS = &HD5A
Public Const GL_ACCUM_ALPHA_BITS = &HD5B
Public Const GL_NAME_STACK_DEPTH = &HD70
Public Const GL_AUTO_NORMAL = &HD80
Public Const GL_MAP1_COLOR_4 = &HD90
Public Const GL_MAP1_INDEX = &HD91
Public Const GL_MAP1_NORMAL = &HD92
Public Const GL_MAP1_TEXTURE_COORD_1 = &HD93
Public Const GL_MAP1_TEXTURE_COORD_2 = &HD94
Public Const GL_MAP1_TEXTURE_COORD_3 = &HD95
Public Const GL_MAP1_TEXTURE_COORD_4 = &HD96
Public Const GL_MAP1_VERTEX_3 = &HD97
Public Const GL_MAP1_VERTEX_4 = &HD98
Public Const GL_MAP2_COLOR_4 = &HDB0
Public Const GL_MAP2_INDEX = &HDB1
Public Const GL_MAP2_NORMAL = &HDB2
Public Const GL_MAP2_TEXTURE_COORD_1 = &HDB3
Public Const GL_MAP2_TEXTURE_COORD_2 = &HDB4
Public Const GL_MAP2_TEXTURE_COORD_3 = &HDB5
Public Const GL_MAP2_TEXTURE_COORD_4 = &HDB6
Public Const GL_MAP2_VERTEX_3 = &HDB7
Public Const GL_MAP2_VERTEX_4 = &HDB8
Public Const GL_MAP1_GRID_DOMAIN = &HDD0
Public Const GL_MAP1_GRID_SEGMENTS = &HDD1
Public Const GL_MAP2_GRID_DOMAIN = &HDD2
Public Const GL_MAP2_GRID_SEGMENTS = &HDD3
Public Const GL_TEXTURE_1D = &HDE0
Public Const GL_TEXTURE_2D = &HDE1
'      GL_VERTEX_ARRAY_EXT
'      GL_NORMAL_ARRAY_EXT
'      GL_COLOR_ARRAY_EXT
'      GL_INDEX_ARRAY_EXT
'      GL_TEXTURE_COORD_ARRAY_EXT
'      GL_EDGE_FLAG_ARRAY_EXT
'      GL_VERTEX_ARRAY_SIZE_EXT
'      GL_VERTEX_ARRAY_TYPE_EXT
'      GL_VERTEX_ARRAY_STRIDE_EXT
'      GL_VERTEX_ARRAY_COUNT_EXT
'      GL_NORMAL_ARRAY_TYPE_EXT
'      GL_NORMAL_ARRAY_STRIDE_EXT
'      GL_NORMAL_ARRAY_COUNT_EXT
'      GL_COLOR_ARRAY_SIZE_EXT
'      GL_COLOR_ARRAY_TYPE_EXT
'      GL_COLOR_ARRAY_STRIDE_EXT
'      GL_COLOR_ARRAY_COUNT_EXT
'      GL_INDEX_ARRAY_TYPE_EXT
'      GL_INDEX_ARRAY_STRIDE_EXT
'      GL_INDEX_ARRAY_COUNT_EXT
'      GL_TEXTURE_COORD_ARRAY_SIZE_EXT
'      GL_TEXTURE_COORD_ARRAY_TYPE_EXT
'      GL_TEXTURE_COORD_ARRAY_STRIDE_EXT
'      GL_TEXTURE_COORD_ARRAY_COUNT_EXT
'      GL_EDGE_FLAG_ARRAY_STRIDE_EXT
'      GL_EDGE_FLAG_ARRAY_COUNT_EXT

' GetTextureParameter
'      GL_TEXTURE_MAG_FILTER
'      GL_TEXTURE_MIN_FILTER
'      GL_TEXTURE_WRAP_S
'      GL_TEXTURE_WRAP_T
Public Const GL_TEXTURE_WIDTH = &H1000
Public Const GL_TEXTURE_HEIGHT = &H1001
Public Const GL_TEXTURE_COMPONENTS = &H1003
Public Const GL_TEXTURE_BORDER_COLOR = &H1004
Public Const GL_TEXTURE_BORDER = &H1005

' HintMode
Public Const GL_DONT_CARE = &H1100
Public Const GL_FASTEST = &H1101
Public Const GL_NICEST = &H1102

' HintTarget
'      GL_PERSPECTIVE_CORRECTION_HINT
'      GL_POINT_SMOOTH_HINT
'      GL_LINE_SMOOTH_HINT
'      GL_POLYGON_SMOOTH_HINT
'      GL_FOG_HINT

' IndexPointerType
'      GL_SHORT
'      GL_INT
'      GL_FLOAT
'      GL_DOUBLE_EXT

' LightModelParameter
'      GL_LIGHT_MODEL_AMBIENT
'      GL_LIGHT_MODEL_LOCAL_VIEWER
'      GL_LIGHT_MODEL_TWO_SIDE

' LightName
Public Const GL_LIGHT0 = &H4000
Public Const GL_LIGHT1 = &H4001
Public Const GL_LIGHT2 = &H4002
Public Const GL_LIGHT3 = &H4003
Public Const GL_LIGHT4 = &H4004
Public Const GL_LIGHT5 = &H4005
Public Const GL_LIGHT6 = &H4006
Public Const GL_LIGHT7 = &H4007

' LightParameter
Public Const GL_AMBIENT = &H1200
Public Const GL_DIFFUSE = &H1201
Public Const GL_SPECULAR = &H1202
Public Const GL_POSITION = &H1203
Public Const GL_SPOT_DIRECTION = &H1204
Public Const GL_SPOT_EXPONENT = &H1205
Public Const GL_SPOT_CUTOFF = &H1206
Public Const GL_CONSTANT_ATTENUATION = &H1207
Public Const GL_LINEAR_ATTENUATION = &H1208
Public Const GL_QUADRATIC_ATTENUATION = &H1209

' ListMode
Public Const GL_COMPILE = &H1300
Public Const GL_COMPILE_AND_EXECUTE = &H1301

' ListNameType
Public Const GL_BYTE = &H1400
Public Const GL_UNSIGNED_BYTE = &H1401
Public Const GL_SHORT = &H1402
Public Const GL_UNSIGNED_SHORT = &H1403
Public Const GL_INT = &H1404
Public Const GL_UNSIGNED_INT = &H1405
Public Const GL_FLOAT = &H1406
Public Const GL_2_BYTES = &H1407
Public Const GL_3_BYTES = &H1408
Public Const GL_4_BYTES = &H1409
Public Const GL_DOUBLE_EXT = &H140A

' LogicOp
Public Const GL_CLEAR = &H1500
Public Const GL_AND = &H1501
Public Const GL_AND_REVERSE = &H1502
Public Const GL_COPY = &H1503
Public Const GL_AND_INVERTED = &H1504
Public Const GL_NOOP = &H1505
Public Const GL_XOR = &H1506
Public Const GL_OR = &H1507
Public Const GL_NOR = &H1508
Public Const GL_EQUIV = &H1509
Public Const GL_INVERT = &H150A
Public Const GL_OR_REVERSE = &H150B
Public Const GL_COPY_INVERTED = &H150C
Public Const GL_OR_INVERTED = &H150D
Public Const GL_NAND = &H150E
Public Const GL_SET = &H150F

' MapTarget
'      GL_MAP1_COLOR_4
'      GL_MAP1_INDEX
'      GL_MAP1_NORMAL
'      GL_MAP1_TEXTURE_COORD_1
'      GL_MAP1_TEXTURE_COORD_2
'      GL_MAP1_TEXTURE_COORD_3
'      GL_MAP1_TEXTURE_COORD_4
'      GL_MAP1_VERTEX_3
'      GL_MAP1_VERTEX_4
'      GL_MAP2_COLOR_4
'      GL_MAP2_INDEX
'      GL_MAP2_NORMAL
'      GL_MAP2_TEXTURE_COORD_1
'      GL_MAP2_TEXTURE_COORD_2
'      GL_MAP2_TEXTURE_COORD_3
'      GL_MAP2_TEXTURE_COORD_4
'      GL_MAP2_VERTEX_3
'      GL_MAP2_VERTEX_4

' MaterialFace
'      GL_FRONT
'      GL_BACK
'      GL_FRONT_AND_BACK

' MaterialParameter
Public Const GL_EMISSION = &H1600
Public Const GL_SHININESS = &H1601
Public Const GL_AMBIENT_AND_DIFFUSE = &H1602
Public Const GL_COLOR_INDEXES = &H1603
'      GL_AMBIENT
'      GL_DIFFUSE
'      GL_SPECULAR

' MatrixMode
Public Const GL_MODELVIEW = &H1700
Public Const GL_PROJECTION = &H1701
Public Const GL_TEXTURE = &H1702

' MeshMode1
'      GL_POINT
'      GL_LINE

' MeshMode2
'      GL_POINT
'      GL_LINE
'      GL_FILL

' NormalPointerType
'      GL_BYTE
'      GL_SHORT
'      GL_INT
'      GL_FLOAT
'      GL_DOUBLE_EXT

' PixelCopyType
Public Const GL_COLOR = &H1800
Public Const GL_DEPTH = &H1801
Public Const GL_STENCIL = &H1802

' PixelFormat
Public Const GL_COLOR_INDEX = &H1900
Public Const GL_STENCIL_INDEX = &H1901
Public Const GL_DEPTH_COMPONENT = &H1902
Public Const GL_RED = &H1903
Public Const GL_GREEN = &H1904
Public Const GL_BLUE = &H1905
Public Const GL_ALPHA = &H1906
Public Const GL_RGB = &H1907
Public Const GL_RGBA = &H1908
Public Const GL_LUMINANCE = &H1909
Public Const GL_LUMINANCE_ALPHA = &H190A

' PixelMap
'      GL_PIXEL_MAP_I_TO_I
'      GL_PIXEL_MAP_S_TO_S
'      GL_PIXEL_MAP_I_TO_R
'      GL_PIXEL_MAP_I_TO_G
'      GL_PIXEL_MAP_I_TO_B
'      GL_PIXEL_MAP_I_TO_A
'      GL_PIXEL_MAP_R_TO_R
'      GL_PIXEL_MAP_G_TO_G
'      GL_PIXEL_MAP_B_TO_B
'      GL_PIXEL_MAP_A_TO_A

' PixelStore
'      GL_UNPACK_SWAP_BYTES
'      GL_UNPACK_LSB_FIRST
'      GL_UNPACK_ROW_LENGTH
'      GL_UNPACK_SKIP_ROWS
'      GL_UNPACK_SKIP_PIXELS
'      GL_UNPACK_ALIGNMENT
'      GL_PACK_SWAP_BYTES
'      GL_PACK_LSB_FIRST
'      GL_PACK_ROW_LENGTH
'      GL_PACK_SKIP_ROWS
'      GL_PACK_SKIP_PIXELS
'      GL_PACK_ALIGNMENT

' PixelTransfer
'      GL_MAP_COLOR
'      GL_MAP_STENCIL
'      GL_INDEX_SHIFT
'      GL_INDEX_OFFSET
'      GL_RED_SCALE
'      GL_RED_BIAS
'      GL_GREEN_SCALE
'      GL_GREEN_BIAS
'      GL_BLUE_SCALE
'      GL_BLUE_BIAS
'      GL_ALPHA_SCALE
'      GL_ALPHA_BIAS
'      GL_DEPTH_SCALE
'      GL_DEPTH_BIAS

' PixelType
Public Const GL_BITMAP = &H1A00
'      GL_BYTE
'      GL_UNSIGNED_BYTE
'      GL_SHORT
'      GL_UNSIGNED_SHORT
'      GL_INT
'      GL_UNSIGNED_INT
'      GL_FLOAT

' PolygonMode
Public Const GL_POINT = &H1B00
Public Const GL_LINE = &H1B01
Public Const GL_FILL = &H1B02

' ReadBufferMode
'      GL_FRONT_LEFT
'      GL_FRONT_RIGHT
'      GL_BACK_LEFT
'      GL_BACK_RIGHT
'      GL_FRONT
'      GL_BACK
'      GL_LEFT
'      GL_RIGHT
'      GL_AUX0
'      GL_AUX1
'      GL_AUX2
'      GL_AUX3

' RenderingMode
Public Const GL_RENDER = &H1C00
Public Const GL_FEEDBACK = &H1C01
Public Const GL_SELECT = &H1C02

' ShadingModel
Public Const GL_FLAT = &H1D00
Public Const GL_SMOOTH = &H1D01

' StencilFunction
'      GL_NEVER
'      GL_LESS
'      GL_EQUAL
'      GL_LEQUAL
'      GL_GREATER
'      GL_NOTEQUAL
'      GL_GEQUAL
'      GL_ALWAYS

' StencilOp
'      GL_ZERO
Public Const GL_KEEP = &H1E00
Public Const GL_REPLACE = &H1E01
Public Const GL_INCR = &H1E02
Public Const GL_DECR = &H1E03
'      GL_INVERT

' StringName
Public Const GL_VENDOR = &H1F00
Public Const GL_RENDERER = &H1F01
Public Const GL_VERSION = &H1F02
Public Const GL_EXTENSIONS = &H1F03

' TextureCoordName
Public Const GL_S = &H2000
Public Const GL_T = &H2001
Public Const GL_R = &H2002
Public Const GL_Q = &H2003

' TexCoordPointerType
'      GL_SHORT
'      GL_INT
'      GL_FLOAT
'      GL_DOUBLE_EXT

' TextureEnvMode
Public Const GL_MODULATE = &H2100
Public Const GL_DECAL = &H2101
'      GL_BLEND

' TextureEnvParameter
Public Const GL_TEXTURE_ENV_MODE = &H2200
Public Const GL_TEXTURE_ENV_COLOR = &H2201

' TextureEnvTarget
Public Const GL_TEXTURE_ENV = &H2300

' TextureGenMode
Public Const GL_EYE_LINEAR = &H2400
Public Const GL_OBJECT_LINEAR = &H2401
Public Const GL_SPHERE_MAP = &H2402

' TextureGenParameter
Public Const GL_TEXTURE_GEN_MODE = &H2500
Public Const GL_OBJECT_PLANE = &H2501
Public Const GL_EYE_PLANE = &H2502

' TextureMagFilter
Public Const GL_NEAREST = &H2600
Public Const GL_LINEAR = &H2601

' TextureMinFilter
'      GL_NEAREST
'      GL_LINEAR
Public Const GL_NEAREST_MIPMAP_NEAREST = &H2700
Public Const GL_LINEAR_MIPMAP_NEAREST = &H2701
Public Const GL_NEAREST_MIPMAP_LINEAR = &H2702
Public Const GL_LINEAR_MIPMAP_LINEAR = &H2703

' TextureParameterName
Public Const GL_TEXTURE_MAG_FILTER = &H2800
Public Const GL_TEXTURE_MIN_FILTER = &H2801
Public Const GL_TEXTURE_WRAP_S = &H2802
Public Const GL_TEXTURE_WRAP_T = &H2803
'      GL_TEXTURE_BORDER_COLOR

' TextureTarget
'      GL_TEXTURE_1D
'      GL_TEXTURE_2D

' TextureWrapMode
Public Const GL_CLAMP = &H2900
Public Const GL_REPEAT = &H2901

' VertexPointerType
'      GL_SHORT
'      GL_INT
'      GL_FLOAT
'      GL_DOUBLE_EXT

' Extensions
Public Const GL_EXT_vertex_array = 1
Public Const GL_WIN_swap_hint = 1

' EXT_vertex_array
Public Const GL_VERTEX_ARRAY_EXT = &H8074
Public Const GL_NORMAL_ARRAY_EXT = &H8075
Public Const GL_COLOR_ARRAY_EXT = &H8076
Public Const GL_INDEX_ARRAY_EXT = &H8077
Public Const GL_TEXTURE_COORD_ARRAY_EXT = &H8078
Public Const GL_EDGE_FLAG_ARRAY_EXT = &H8079
Public Const GL_VERTEX_ARRAY_SIZE_EXT = &H807A
Public Const GL_VERTEX_ARRAY_TYPE_EXT = &H807B
Public Const GL_VERTEX_ARRAY_STRIDE_EXT = &H807C
Public Const GL_VERTEX_ARRAY_COUNT_EXT = &H807D
Public Const GL_NORMAL_ARRAY_TYPE_EXT = &H807E
Public Const GL_NORMAL_ARRAY_STRIDE_EXT = &H807F
Public Const GL_NORMAL_ARRAY_COUNT_EXT = &H8080
Public Const GL_COLOR_ARRAY_SIZE_EXT = &H8081
Public Const GL_COLOR_ARRAY_TYPE_EXT = &H8082
Public Const GL_COLOR_ARRAY_STRIDE_EXT = &H8083
Public Const GL_COLOR_ARRAY_COUNT_EXT = &H8084
Public Const GL_INDEX_ARRAY_TYPE_EXT = &H8085
Public Const GL_INDEX_ARRAY_STRIDE_EXT = &H8086
Public Const GL_INDEX_ARRAY_COUNT_EXT = &H8087
Public Const GL_TEXTURE_COORD_ARRAY_SIZE_EXT = &H8088
Public Const GL_TEXTURE_COORD_ARRAY_TYPE_EXT = &H8089
Public Const GL_TEXTURE_COORD_ARRAY_STRIDE_EXT = &H808A
Public Const GL_TEXTURE_COORD_ARRAY_COUNT_EXT = &H808B
Public Const GL_EDGE_FLAG_ARRAY_STRIDE_EXT = &H808C
Public Const GL_EDGE_FLAG_ARRAY_COUNT_EXT = &H808D
Public Const GL_VERTEX_ARRAY_POINTER_EXT = &H808E
Public Const GL_NORMAL_ARRAY_POINTER_EXT = &H808F
Public Const GL_COLOR_ARRAY_POINTER_EXT = &H8090
Public Const GL_INDEX_ARRAY_POINTER_EXT = &H8091
Public Const GL_TEXTURE_COORD_ARRAY_POINTER_EXT = &H8092
Public Const GL_EDGE_FLAG_ARRAY_POINTER_EXT = &H8093

'***********************************************************

Declare Sub glAccum Lib "OpenGL32.dll" (ByVal op As Integer, ByVal value As Single)
Declare Sub glAlphaFunc Lib "OpenGL32.dll" (ByVal func As Integer, ByVal ref As Single)
Declare Sub glBegin Lib "OpenGL32.dll" (ByVal mode As Integer)
Declare Sub glBitmap Lib "OpenGL32.dll" (ByVal width As Integer, ByVal height As Integer, ByVal xorig As Single, ByVal yorig As Single, ByVal xmove As Single, ByVal ymove As Single, bitmap As Byte)
Declare Sub glBlendFunc Lib "OpenGL32.dll" (ByVal sfactor As Integer, ByVal dfactor As Integer)
Declare Sub glCallList Lib "OpenGL32.dll" (ByVal list As Integer)
Declare Sub glCallLists Lib "OpenGL32.dll" (ByVal n As Integer, ByVal typeA As Integer, lists As Any)
Declare Sub glClear Lib "OpenGL32.dll" (ByVal mask As Integer)
Declare Sub glClearAccum Lib "OpenGL32.dll" (ByVal red As Single, ByVal green As Single, ByVal blue As Single, ByVal alpha As Single)
'Declare Sub glClearColor Lib "OpenGL32.dll" (ByVal red As Single, ByVal green As Single, ByVal blue As Single, ByVal alpha As Single)
Declare Sub glClearDepth Lib "OpenGL32.dll" (ByVal depth As Double)
Declare Sub glClearIndex Lib "OpenGL32.dll" (ByVal c As Single)
Declare Sub glClearStencil Lib "OpenGL32.dll" (ByVal s As Integer)
Declare Sub glClipPlane Lib "OpenGL32.dll" (ByVal plane As Integer, equation As Double)
Declare Sub glColor3b Lib "OpenGL32.dll" (ByVal red As Byte, ByVal green As Byte, ByVal blue As Byte)
Declare Sub glColor3bv Lib "OpenGL32.dll" (v As Byte)
Declare Sub glColor3d Lib "OpenGL32.dll" (ByVal red As Double, ByVal green As Double, ByVal blue As Double)
Declare Sub glColor3dv Lib "OpenGL32.dll" (v As Double)
Declare Sub glColor3f Lib "OpenGL32.dll" (ByVal red As Single, ByVal green As Single, ByVal blue As Single)
Declare Sub glColor3fv Lib "OpenGL32.dll" (v As Single)
Declare Sub glColor3i Lib "OpenGL32.dll" (ByVal red As Integer, ByVal greens As Integer, ByVal blue As Integer)
Declare Sub glColor3iv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glColor3s Lib "OpenGL32.dll" (ByVal red As Integer, ByVal green As Integer, ByVal blue As Integer)
Declare Sub glColor3sv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glColor3ub Lib "OpenGL32.dll" (ByVal red As Byte, ByVal green As Byte, ByVal blue As Byte)
Declare Sub glColor3ubv Lib "OpenGL32.dll" (v As Byte)
Declare Sub glColor3ui Lib "OpenGL32.dll" (ByVal red As Integer, ByVal green As Integer, ByVal blue As Integer)
Declare Sub glColor3uiv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glColor3us Lib "OpenGL32.dll" (ByVal red As Integer, ByVal green As Integer, ByVal blue As Integer)
Declare Sub glColor3usv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glColor4b Lib "OpenGL32.dll" (ByVal red As Byte, ByVal green As Byte, ByVal blue As Byte, ByVal alpha As Byte)
Declare Sub glColor4bv Lib "OpenGL32.dll" (v As Byte)
Declare Sub glColor4d Lib "OpenGL32.dll" (ByVal red As Double, ByVal green As Double, ByVal blue As Double, ByVal alpha As Double)
Declare Sub glColor4dv Lib "OpenGL32.dll" (v As Double)
Declare Sub glColor4f Lib "OpenGL32.dll" (ByVal red As Single, ByVal green As Single, ByVal blue As Single, ByVal alpha As Single)
Declare Sub glColor4fv Lib "OpenGL32.dll" (v As Single)
Declare Sub glColor4i Lib "OpenGL32.dll" (ByVal red As Integer, ByVal green As Integer, ByVal blue As Integer, ByVal alpha As Integer)
Declare Sub glColor4iv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glColor4s Lib "OpenGL32.dll" (ByVal red As Integer, ByVal green As Integer, ByVal blue As Integer, ByVal alpha As Integer)
Declare Sub glColor4sv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glColor4ub Lib "OpenGL32.dll" (ByVal red As Byte, ByVal green As Byte, ByVal blue As Byte, ByVal alpha As Byte)
Declare Sub glColor4ubv Lib "OpenGL32.dll" (v As Byte)
Declare Sub glColor4ui Lib "OpenGL32.dll" (ByVal red As Integer, ByVal green As Integer, ByVal blue As Integer, ByVal alpha As Integer)
Declare Sub glColor4uiv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glColor4us Lib "OpenGL32.dll" (ByVal red As Integer, ByVal green As Integer, ByVal blue As Integer, ByVal alpha As Integer)
Declare Sub glColor4usv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glColorMask Lib "OpenGL32.dll" (ByVal red As Byte, ByVal green As Byte, ByVal blue As Byte, ByVal alpha As Byte)
Declare Sub glColorMaterial Lib "OpenGL32.dll" (ByVal face As Integer, ByVal mode As Integer)
Declare Sub glCopyPixels Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer, ByVal width As Integer, ByVal height As Integer, ByVal typeA As Integer)
Declare Sub glCullFace Lib "OpenGL32.dll" (ByVal mode As Integer)
Declare Sub glDeleteLists Lib "OpenGL32.dll" (ByVal list As Integer, ByVal range As Integer)
Declare Sub glDepthFunc Lib "OpenGL32.dll" (ByVal func As Integer)
Declare Sub glDepthMask Lib "OpenGL32.dll" (ByVal flag As Byte)
Declare Sub glDepthRange Lib "OpenGL32.dll" (ByVal zNear As Double, ByVal zFar As Double)
Declare Sub glDisable Lib "OpenGL32.dll" (ByVal cap As Integer)
Declare Sub glDrawBuffer Lib "OpenGL32.dll" (ByVal mode As Integer)
Declare Sub glDrawPixels Lib "OpenGL32.dll" (ByVal width As Integer, ByVal height As Integer, ByVal format As Integer, ByVal typeA As Integer, pixels As Any)
Declare Sub glEdgeFlag Lib "OpenGL32.dll" (ByVal flag As Byte)
Declare Sub glEdgeFlagv Lib "OpenGL32.dll" (flag As Byte)
Declare Sub glEnable Lib "OpenGL32.dll" (ByVal cap As Integer)
Declare Sub glEnd Lib "OpenGL32.dll" ()
Declare Sub glEndList Lib "OpenGL32.dll" ()
Declare Sub glEvalCoord1d Lib "OpenGL32.dll" (ByVal u As Double)
Declare Sub glEvalCoord1dv Lib "OpenGL32.dll" (u As Double)
Declare Sub glEvalCoord1f Lib "OpenGL32.dll" (ByVal u As Single)
Declare Sub glEvalCoord1fv Lib "OpenGL32.dll" (u As Single)
Declare Sub glEvalCoord2d Lib "OpenGL32.dll" (ByVal u As Double, ByVal v As Double)
Declare Sub glEvalCoord2dv Lib "OpenGL32.dll" (u As Double)
Declare Sub glEvalCoord2f Lib "OpenGL32.dll" (ByVal u As Single, ByVal v As Single)
Declare Sub glEvalCoord2fv Lib "OpenGL32.dll" (u As Single)
Declare Sub glEvalMesh1 Lib "OpenGL32.dll" (ByVal mode As Integer, ByVal i1 As Integer, ByVal i2 As Integer)
Declare Sub glEvalMesh2 Lib "OpenGL32.dll" (ByVal mode As Integer, ByVal i1 As Integer, ByVal i2 As Integer, ByVal j1 As Integer, ByVal j2 As Integer)
Declare Sub glEvalPoint1 Lib "OpenGL32.dll" (ByVal i As Integer)
Declare Sub glEvalPoint2 Lib "OpenGL32.dll" (ByVal i As Integer, ByVal j As Integer)
Declare Sub glFeedbackBuffer Lib "OpenGL32.dll" (ByVal size As Integer, ByVal typeA As Integer, ByVal buffer As Single)
Declare Sub glFinish Lib "OpenGL32.dll" ()
Declare Sub glFlush Lib "OpenGL32.dll" ()
Declare Sub glFogf Lib "OpenGL32.dll" (ByVal pname As Integer, ByVal param As Single)
Declare Sub glFogfv Lib "OpenGL32.dll" (ByVal pname As Integer, params As Single)
Declare Sub glFogi Lib "OpenGL32.dll" (ByVal pname As Integer, ByVal param As Integer)
Declare Sub glFogiv Lib "OpenGL32.dll" (ByVal pname As Integer, params As Integer)
Declare Sub glFrontFace Lib "OpenGL32.dll" (ByVal mode As Integer)
Declare Sub glFrustum Lib "OpenGL32.dll" (ByVal left As Double, ByVal right As Double, ByVal bottom As Double, ByVal top As Double, ByVal zNear As Double, ByVal zFar As Double)
Declare Function glGenLists Lib "OpenGL32.dll" (ByVal range As Integer) As Integer
Declare Sub glGetBooleanv Lib "OpenGL32.dll" (ByVal pname As Integer, ByVal params As Byte)
Declare Sub glGetClipPlane Lib "OpenGL32.dll" (ByVal plane As Integer, ByVal equation As Double)
Declare Sub glGetDoublev Lib "OpenGL32.dll" (ByVal pname As Integer, ByVal params As Double)
Declare Function glGetError Lib "OpenGL32.dll" () As Integer
Declare Sub glGetFloatv Lib "OpenGL32.dll" (ByVal pname As Integer, ByVal params As Single)
Declare Sub glGetIntegerv Lib "OpenGL32.dll" (ByVal pname As Integer, ByVal params As Integer)
Declare Sub glGetLightfv Lib "OpenGL32.dll" (ByVal light As Integer, ByVal pname As Integer, ByVal params As Single)
Declare Sub glGetLightiv Lib "OpenGL32.dll" (ByVal light As Integer, ByVal pname As Integer, ByVal params As Integer)
Declare Sub glGetMapdv Lib "OpenGL32.dll" (ByVal target As Integer, ByVal query As Integer, ByVal v As Double)
Declare Sub glGetMapfv Lib "OpenGL32.dll" (ByVal target As Integer, ByVal query As Integer, ByVal v As Single)
Declare Sub glGetMapiv Lib "OpenGL32.dll" (ByVal target As Integer, ByVal query As Integer, ByVal v As Integer)
Declare Sub glGetMaterialfv Lib "OpenGL32.dll" (ByVal face As Integer, ByVal pname As Integer, ByVal params As Single)
Declare Sub glGetMaterialiv Lib "OpenGL32.dll" (ByVal face As Integer, ByVal pname As Integer, ByVal params As Integer)
Declare Sub glGetPixelMapfv Lib "OpenGL32.dll" (ByVal map As Integer, ByVal values As Single)
Declare Sub glGetPixelMapuiv Lib "OpenGL32.dll" (ByVal map As Integer, ByVal values As Integer)
Declare Sub glGetPixelMapusv Lib "OpenGL32.dll" (ByVal map As Integer, ByVal values As Integer)
Declare Sub glGetPolygonStipple Lib "OpenGL32.dll" (ByVal mask As Byte)
Declare Function glGetString Lib "OpenGL32.dll" (ByVal name As Integer) As Integer


Declare Sub glGetTexEnvfv Lib "OpenGL32.dll" (ByVal target As Integer, ByVal pname As Integer, ByVal params As Single)
Declare Sub glGetTexEnviv Lib "OpenGL32.dll" (ByVal target As Integer, ByVal pname As Integer, ByVal params As Integer)
Declare Sub glGetTexGendv Lib "OpenGL32.dll" (ByVal coord As Integer, ByVal pname As Integer, ByVal params As Double)
Declare Sub glGetTexGenfv Lib "OpenGL32.dll" (ByVal coord As Integer, ByVal pname As Integer, ByVal params As Single)
Declare Sub glGetTexGeniv Lib "OpenGL32.dll" (ByVal coord As Integer, ByVal pname As Integer, ByVal params As Integer)
Declare Sub glGetTexImage Lib "OpenGL32.dll" (ByVal target As Integer, ByVal level As Integer, ByVal format As Integer, ByVal typeA As Integer, ByVal pixels As Any)
Declare Sub glGetTexLevelParameterfv Lib "OpenGL32.dll" (ByVal target As Integer, ByVal level As Integer, ByVal pname As Integer, ByVal params As Single)
Declare Sub glGetTexLevelParameteriv Lib "OpenGL32.dll" (ByVal target As Integer, ByVal level As Integer, ByVal pname As Integer, ByVal params As Integer)
Declare Sub glGetTexParameterfv Lib "OpenGL32.dll" (ByVal target As Integer, ByVal pname As Integer, ByVal params As Single)
Declare Sub glGetTexParameteriv Lib "OpenGL32.dll" (ByVal target As Integer, ByVal pname As Integer, ByVal params As Integer)
Declare Sub glHint Lib "OpenGL32.dll" (ByVal target As Integer, ByVal mode As Integer)
Declare Sub glIndexMask Lib "OpenGL32.dll" (ByVal mask As Integer)
Declare Sub glIndexd Lib "OpenGL32.dll" (ByVal c As Double)
Declare Sub glIndexdv Lib "OpenGL32.dll" (c As Double)
Declare Sub glIndexf Lib "OpenGL32.dll" (ByVal c As Single)
Declare Sub glIndexfv Lib "OpenGL32.dll" (c As Single)
Declare Sub glIndexi Lib "OpenGL32.dll" (ByVal c As Integer)
Declare Sub glIndexiv Lib "OpenGL32.dll" (c As Integer)
Declare Sub glIndexs Lib "OpenGL32.dll" (ByVal c As Integer)
Declare Sub glIndexsv Lib "OpenGL32.dll" (c As Integer)
Declare Sub glInitNames Lib "OpenGL32.dll" ()
Declare Function glIsEnabled Lib "OpenGL32.dll" (ByVal cap As Integer) As Byte
Declare Function glIsList Lib "OpenGL32.dll" (ByVal list As Integer) As Byte
Declare Sub glLightModelf Lib "OpenGL32.dll" (ByVal pname As Integer, ByVal param As Single)
Declare Sub glLightModelfv Lib "OpenGL32.dll" (ByVal pname As Integer, params As Single)
Declare Sub glLightModeli Lib "OpenGL32.dll" (ByVal pname As Integer, ByVal param As Integer)
Declare Sub glLightModeliv Lib "OpenGL32.dll" (ByVal pname As Integer, params As Integer)
Declare Sub glLightf Lib "OpenGL32.dll" (ByVal light As Integer, ByVal pname As Integer, ByVal param As Single)
Declare Sub glLightfv Lib "OpenGL32.dll" (ByVal light As Integer, ByVal pname As Integer, params As Single)
Declare Sub glLighti Lib "OpenGL32.dll" (ByVal light As Integer, ByVal pname As Integer, ByVal param As Integer)
Declare Sub glLightiv Lib "OpenGL32.dll" (ByVal light As Integer, ByVal pname As Integer, params As Integer)
Declare Sub glLineStipple Lib "OpenGL32.dll" (ByVal factor As Integer, ByVal pattern As Integer)
Declare Sub glLineWidth Lib "OpenGL32.dll" (ByVal width As Single)
Declare Sub glListBase Lib "OpenGL32.dll" (ByVal base As Integer)
Declare Sub glLoadIdentity Lib "OpenGL32.dll" ()
Declare Sub glLoadMatrixd Lib "OpenGL32.dll" (m As Double)
Declare Sub glLoadMatrixf Lib "OpenGL32.dll" (m As Single)
Declare Sub glLoadName Lib "OpenGL32.dll" (ByVal name As Integer)
Declare Sub glLogicOp Lib "OpenGL32.dll" (ByVal opcode As Integer)
Declare Sub glMap1d Lib "OpenGL32.dll" (ByVal target As Integer, ByVal u1 As Double, ByVal u2 As Double, ByVal stride As Integer, ByVal order As Integer, points As Double)
Declare Sub glMap1f Lib "OpenGL32.dll" (ByVal target As Integer, ByVal u1 As Single, ByVal u2 As Single, ByVal stride As Integer, ByVal order As Integer, points As Single)
Declare Sub glMap2d Lib "OpenGL32.dll" (ByVal target As Integer, ByVal u1 As Double, ByVal u2 As Double, ByVal ustride As Integer, ByVal uorder As Integer, ByVal v1 As Double, ByVal v2 As Double, ByVal vstride As Integer, ByVal vorder As Integer, points As Double)
Declare Sub glMap2f Lib "OpenGL32.dll" (ByVal target As Integer, ByVal u1 As Single, ByVal u2 As Single, ByVal ustride As Integer, ByVal uorder As Integer, ByVal v1 As Single, ByVal v2 As Single, ByVal vstride As Integer, ByVal vorder As Integer, points As Single)
Declare Sub glMapGrid1d Lib "OpenGL32.dll" (ByVal un As Integer, ByVal u1 As Double, ByVal u2 As Double)
Declare Sub glMapGrid1f Lib "OpenGL32.dll" (ByVal un As Integer, ByVal u1 As Single, ByVal u2 As Single)
Declare Sub glMapGrid2d Lib "OpenGL32.dll" (ByVal un As Integer, ByVal u1 As Double, ByVal u2 As Double, ByVal vn As Integer, ByVal v1 As Double, ByVal v2 As Double)
Declare Sub glMapGrid2f Lib "OpenGL32.dll" (ByVal un As Integer, ByVal u1 As Single, ByVal u2 As Single, ByVal vn As Integer, ByVal v1 As Single, ByVal v2 As Single)
Declare Sub glMaterialf Lib "OpenGL32.dll" (ByVal face As Integer, ByVal pname As Integer, ByVal param As Single)
Declare Sub glMaterialfv Lib "OpenGL32.dll" (ByVal face As Integer, ByVal pname As Integer, params As Single)
Declare Sub glMateriali Lib "OpenGL32.dll" (ByVal face As Integer, ByVal pname As Integer, ByVal param As Integer)
Declare Sub glMaterialiv Lib "OpenGL32.dll" (ByVal face As Integer, ByVal pname As Integer, params As Integer)
Declare Sub glMatrixMode Lib "OpenGL32.dll" (ByVal mode As Integer)
Declare Sub glMultMatrixd Lib "OpenGL32.dll" (m As Double)
Declare Sub glMultMatrixf Lib "OpenGL32.dll" (m As Single)
Declare Sub glNewList Lib "OpenGL32.dll" (ByVal list As Integer, ByVal mode As Integer)
Declare Sub glNormal3b Lib "OpenGL32.dll" (ByVal nx As Byte, ByVal ny As Byte, ByVal nz As Byte)
Declare Sub glNormal3bv Lib "OpenGL32.dll" (v As Byte)
Declare Sub glNormal3d Lib "OpenGL32.dll" (ByVal nx As Double, ByVal ny As Double, ByVal nz As Double)
Declare Sub glNormal3dv Lib "OpenGL32.dll" (v As Double)
Declare Sub glNormal3f Lib "OpenGL32.dll" (ByVal nx As Single, ByVal ny As Single, ByVal nz As Single)
Declare Sub glNormal3fv Lib "OpenGL32.dll" (v As Single)
Declare Sub glNormal3i Lib "OpenGL32.dll" (ByVal nx As Integer, ByVal ny As Integer, ByVal nz As Integer)
Declare Sub glNormal3iv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glNormal3s Lib "OpenGL32.dll" (ByVal nx As Integer, ByVal ny As Integer, ByVal nz As Integer)
Declare Sub glNormal3sv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glOrtho Lib "OpenGL32.dll" (ByVal left As Double, ByVal right As Double, ByVal bottom As Double, ByVal top As Double, ByVal zNear As Double, ByVal zFar As Double)
Declare Sub glPassThrough Lib "OpenGL32.dll" (ByVal token As Single)
Declare Sub glPixelMapfv Lib "OpenGL32.dll" (ByVal map As Integer, ByVal mapsize As Integer, values As Single)
Declare Sub glPixelMapuiv Lib "OpenGL32.dll" (ByVal map As Integer, ByVal mapsize As Integer, values As Integer)
Declare Sub glPixelMapusv Lib "OpenGL32.dll" (ByVal map As Integer, ByVal mapsize As Integer, values As Integer)
Declare Sub glPixelStoref Lib "OpenGL32.dll" (ByVal pname As Integer, ByVal param As Single)
Declare Sub glPixelStorei Lib "OpenGL32.dll" (ByVal pname As Integer, ByVal param As Integer)
Declare Sub glPixelTransferf Lib "OpenGL32.dll" (ByVal pname As Integer, ByVal param As Single)
Declare Sub glPixelTransferi Lib "OpenGL32.dll" (ByVal pname As Integer, ByVal param As Integer)
Declare Sub glPixelZoom Lib "OpenGL32.dll" (ByVal xfactor As Single, ByVal yfactor As Single)
Declare Sub glPointSize Lib "OpenGL32.dll" (ByVal size As Single)
Declare Sub glPolygonMode Lib "OpenGL32.dll" (ByVal face As Integer, ByVal mode As Integer)
Declare Sub glPolygonStipple Lib "OpenGL32.dll" (mask As Byte)
Declare Sub glPopAttrib Lib "OpenGL32.dll" ()
Declare Sub glPopMatrix Lib "OpenGL32.dll" ()
Declare Sub glPopName Lib "OpenGL32.dll" ()
Declare Sub glPushAttrib Lib "OpenGL32.dll" (ByVal mask As Integer)
Declare Sub glPushMatrix Lib "OpenGL32.dll" ()
Declare Sub glPushName Lib "OpenGL32.dll" (ByVal name As Integer)
Declare Sub glRasterPos2d Lib "OpenGL32.dll" (ByVal x As Double, ByVal y As Double)
Declare Sub glRasterPos2dv Lib "OpenGL32.dll" (v As Double)
Declare Sub glRasterPos2f Lib "OpenGL32.dll" (ByVal x As Single, ByVal y As Single)
Declare Sub glRasterPos2fv Lib "OpenGL32.dll" (v As Single)
Declare Sub glRasterPos2i Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer)
Declare Sub glRasterPos2iv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glRasterPos2s Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer)
Declare Sub glRasterPos2sv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glRasterPos3d Lib "OpenGL32.dll" (ByVal x As Double, ByVal y As Double, ByVal z As Double)
Declare Sub glRasterPos3dv Lib "OpenGL32.dll" (v As Double)
Declare Sub glRasterPos3f Lib "OpenGL32.dll" (ByVal x As Single, ByVal y As Single, ByVal z As Single)
Declare Sub glRasterPos3fv Lib "OpenGL32.dll" (v As Single)
Declare Sub glRasterPos3i Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer, ByVal z As Integer)
Declare Sub glRasterPos3iv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glRasterPos3s Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer, ByVal z As Integer)
Declare Sub glRasterPos3sv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glRasterPos4d Lib "OpenGL32.dll" (ByVal x As Double, ByVal y As Double, ByVal z As Double, ByVal w As Double)
Declare Sub glRasterPos4dv Lib "OpenGL32.dll" (v As Double)
Declare Sub glRasterPos4f Lib "OpenGL32.dll" (ByVal x As Single, ByVal y As Single, ByVal z As Single, ByVal w As Single)
Declare Sub glRasterPos4fv Lib "OpenGL32.dll" (v As Single)
Declare Sub glRasterPos4i Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal w As Integer)
Declare Sub glRasterPos4iv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glRasterPos4s Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal w As Integer)
Declare Sub glRasterPos4sv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glReadBuffer Lib "OpenGL32.dll" (ByVal mode As Integer)
Declare Sub glReadPixels Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer, ByVal width As Integer, ByVal height As Integer, ByVal format As Integer, ByVal typeA As Integer, ByVal pixels As Any)
Declare Sub glRectd Lib "OpenGL32.dll" (ByVal x1 As Double, ByVal y1 As Double, ByVal x2 As Double, ByVal y2 As Double)
Declare Sub glRectdv Lib "OpenGL32.dll" (v1 As Double, v2 As Double)
Declare Sub glRectf Lib "OpenGL32.dll" (ByVal x1 As Single, ByVal y1 As Single, ByVal x2 As Single, ByVal y2 As Single)
Declare Sub glRectfv Lib "OpenGL32.dll" (v1 As Single, v2 As Single)
Declare Sub glRecti Lib "OpenGL32.dll" (ByVal x1 As Integer, ByVal y1 As Integer, ByVal x2 As Integer, ByVal y2 As Integer)
Declare Sub glRectiv Lib "OpenGL32.dll" (v1 As Integer, v2 As Integer)
Declare Sub glRects Lib "OpenGL32.dll" (ByVal x1 As Integer, ByVal y1 As Integer, ByVal x2 As Integer, ByVal y2 As Integer)
Declare Sub glRectsv Lib "OpenGL32.dll" (v1 As Integer, v2 As Integer)
Declare Function glRenderMode Lib "OpenGL32.dll" (ByVal mode As Integer) As Integer
Declare Sub glRotated Lib "OpenGL32.dll" (ByVal angle As Double, ByVal x As Double, ByVal y As Double, ByVal z As Double)
Declare Sub glRotatef Lib "OpenGL32.dll" (ByVal angle As Single, ByVal x As Single, ByVal y As Single, ByVal z As Single)
Declare Sub glScaled Lib "OpenGL32.dll" (ByVal x As Double, ByVal y As Double, ByVal z As Double)
Declare Sub glScalef Lib "OpenGL32.dll" (ByVal x As Single, ByVal y As Single, ByVal z As Single)
Declare Sub glScissor Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer, ByVal width As Integer, ByVal height As Integer)
Declare Sub glSelectBuffer Lib "OpenGL32.dll" (ByVal size As Integer, ByVal buffer As Integer)
Declare Sub glShadeModel Lib "OpenGL32.dll" (ByVal mode As Integer)
Declare Sub glStencilFunc Lib "OpenGL32.dll" (ByVal func As Integer, ByVal ref As Integer, ByVal mask As Integer)
Declare Sub glStencilMask Lib "OpenGL32.dll" (ByVal mask As Integer)
Declare Sub glStencilOp Lib "OpenGL32.dll" (ByVal fail As Integer, ByVal zfail As Integer, ByVal zpass As Integer)
Declare Sub glTexCoord1d Lib "OpenGL32.dll" (ByVal s As Double)
Declare Sub glTexCoord1dv Lib "OpenGL32.dll" (v As Double)
Declare Sub glTexCoord1f Lib "OpenGL32.dll" (ByVal s As Single)
Declare Sub glTexCoord1fv Lib "OpenGL32.dll" (v As Single)
Declare Sub glTexCoord1i Lib "OpenGL32.dll" (ByVal s As Integer)
Declare Sub glTexCoord1iv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glTexCoord1s Lib "OpenGL32.dll" (ByVal s As Integer)
Declare Sub glTexCoord1sv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glTexCoord2d Lib "OpenGL32.dll" (ByVal s As Double, ByVal t As Double)
Declare Sub glTexCoord2dv Lib "OpenGL32.dll" (v As Double)
Declare Sub glTexCoord2f Lib "OpenGL32.dll" (ByVal s As Single, ByVal t As Single)
Declare Sub glTexCoord2fv Lib "OpenGL32.dll" (v As Single)
Declare Sub glTexCoord2i Lib "OpenGL32.dll" (ByVal s As Integer, ByVal t As Integer)
Declare Sub glTexCoord2iv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glTexCoord2s Lib "OpenGL32.dll" (ByVal s As Integer, ByVal t As Integer)
Declare Sub glTexCoord2sv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glTexCoord3d Lib "OpenGL32.dll" (ByVal s As Double, ByVal t As Double, ByVal r As Double)
Declare Sub glTexCoord3dv Lib "OpenGL32.dll" (v As Double)
Declare Sub glTexCoord3f Lib "OpenGL32.dll" (ByVal s As Single, ByVal t As Single, ByVal r As Single)
Declare Sub glTexCoord3fv Lib "OpenGL32.dll" (v As Single)
Declare Sub glTexCoord3i Lib "OpenGL32.dll" (ByVal s As Integer, ByVal t As Integer, ByVal r As Integer)
Declare Sub glTexCoord3iv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glTexCoord3s Lib "OpenGL32.dll" (ByVal s As Integer, ByVal t As Integer, ByVal r As Integer)
Declare Sub glTexCoord3sv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glTexCoord4d Lib "OpenGL32.dll" (ByVal s As Double, ByVal t As Double, ByVal r As Double, ByVal q As Double)
Declare Sub glTexCoord4dv Lib "OpenGL32.dll" (v As Double)
Declare Sub glTexCoord4f Lib "OpenGL32.dll" (ByVal s As Single, ByVal t As Single, ByVal r As Single, ByVal q As Single)
Declare Sub glTexCoord4fv Lib "OpenGL32.dll" (v As Single)
Declare Sub glTexCoord4i Lib "OpenGL32.dll" (ByVal s As Integer, ByVal t As Integer, ByVal r As Integer, ByVal q As Integer)
Declare Sub glTexCoord4iv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glTexCoord4s Lib "OpenGL32.dll" (ByVal s As Integer, ByVal t As Integer, ByVal r As Integer, ByVal q As Integer)
Declare Sub glTexCoord4sv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glTexEnvf Lib "OpenGL32.dll" (ByVal target As Integer, ByVal pname As Integer, ByVal param As Single)
Declare Sub glTexEnvfv Lib "OpenGL32.dll" (ByVal target As Integer, ByVal pname As Integer, params As Single)
Declare Sub glTexEnvi Lib "OpenGL32.dll" (ByVal target As Integer, ByVal pname As Integer, ByVal param As Integer)
Declare Sub glTexEnviv Lib "OpenGL32.dll" (ByVal target As Integer, ByVal pname As Integer, params As Integer)
Declare Sub glTexGend Lib "OpenGL32.dll" (ByVal coord As Integer, ByVal pname As Integer, ByVal param As Double)
Declare Sub glTexGendv Lib "OpenGL32.dll" (ByVal coord As Integer, ByVal pname As Integer, params As Double)
Declare Sub glTexGenf Lib "OpenGL32.dll" (ByVal coord As Integer, ByVal pname As Integer, ByVal param As Single)
Declare Sub glTexGenfv Lib "OpenGL32.dll" (ByVal coord As Integer, ByVal pname As Integer, params As Single)
Declare Sub glTexGeni Lib "OpenGL32.dll" (ByVal coord As Integer, ByVal pname As Integer, ByVal param As Integer)
Declare Sub glTexGeniv Lib "OpenGL32.dll" (ByVal coord As Integer, ByVal pname As Integer, params As Integer)
Declare Sub glTexImage1D Lib "OpenGL32.dll" (ByVal target As Integer, ByVal level As Integer, ByVal components As Integer, ByVal width As Integer, ByVal border As Integer, ByVal format As Integer, ByVal typeA As Integer, pixels As Any)
Declare Sub glTexImage2D Lib "OpenGL32.dll" (ByVal target As Integer, ByVal level As Integer, ByVal components As Integer, ByVal width As Integer, ByVal height As Integer, ByVal border As Integer, ByVal format As Integer, ByVal typeA As Integer, pixels As Any)
Declare Sub glTexParameterf Lib "OpenGL32.dll" (ByVal target As Integer, ByVal pname As Integer, ByVal param As Single)
Declare Sub glTexParameterfv Lib "OpenGL32.dll" (ByVal target As Integer, ByVal pname As Integer, params As Single)
Declare Sub glTexParameteri Lib "OpenGL32.dll" (ByVal target As Integer, ByVal pname As Integer, ByVal param As Integer)
Declare Sub glTexParameteriv Lib "OpenGL32.dll" (ByVal target As Integer, ByVal pname As Integer, params As Integer)
Declare Sub glTranslated Lib "OpenGL32.dll" (ByVal x As Double, ByVal y As Double, ByVal z As Double)
Declare Sub glTranslatef Lib "OpenGL32.dll" (ByVal x As Single, ByVal y As Single, ByVal z As Single)
Declare Sub glVertex2d Lib "OpenGL32.dll" (ByVal x As Double, ByVal y As Double)
Declare Sub glVertex2dv Lib "OpenGL32.dll" (v As Double)
Declare Sub glVertex2f Lib "OpenGL32.dll" (ByVal x As Single, ByVal y As Single)
Declare Sub glVertex2fv Lib "OpenGL32.dll" (v As Single)
Declare Sub glVertex2i Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer)
Declare Sub glVertex2iv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glVertex2s Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer)
Declare Sub glVertex2sv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glVertex3d Lib "OpenGL32.dll" (ByVal x As Double, ByVal y As Double, ByVal z As Double)
Declare Sub glVertex3dv Lib "OpenGL32.dll" (v As Double)
Declare Sub glVertex3f Lib "OpenGL32.dll" (ByVal x As Single, ByVal y As Single, ByVal z As Single)
Declare Sub glVertex3fv Lib "OpenGL32.dll" (v As Single)
Declare Sub glVertex3i Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer, ByVal z As Integer)
Declare Sub glVertex3iv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glVertex3s Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer, ByVal z As Integer)
Declare Sub glVertex3sv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glVertex4d Lib "OpenGL32.dll" (ByVal x As Double, ByVal y As Double, ByVal z As Double, ByVal w As Double)
Declare Sub glVertex4dv Lib "OpenGL32.dll" (v As Double)
Declare Sub glVertex4f Lib "OpenGL32.dll" (ByVal x As Single, ByVal y As Single, ByVal z As Single, ByVal w As Single)
Declare Sub glVertex4fv Lib "OpenGL32.dll" (v As Single)
Declare Sub glVertex4i Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal w As Integer)
Declare Sub glVertex4iv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glVertex4s Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer, ByVal z As Integer, ByVal w As Integer)
Declare Sub glVertex4sv Lib "OpenGL32.dll" (v As Integer)
Declare Sub glViewport Lib "OpenGL32.dll" (ByVal x As Integer, ByVal y As Integer, ByVal width As Integer, ByVal height As Integer)
