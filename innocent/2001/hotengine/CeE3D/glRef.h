
/* EXT_vertex_array */
typedef void (APIENTRY * PFNGLARRAYELEMENTEXTPROC) (GLint i);
typedef void (APIENTRY * PFNGLDRAWARRAYSEXTPROC) (GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRY * PFNGLVERTEXPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
typedef void (APIENTRY * PFNGLNORMALPOINTEREXTPROC) (GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
typedef void (APIENTRY * PFNGLCOLORPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
typedef void (APIENTRY * PFNGLINDEXPOINTEREXTPROC) (GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
typedef void (APIENTRY * PFNGLTEXCOORDPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
typedef void (APIENTRY * PFNGLEDGEFLAGPOINTEREXTPROC) (GLsizei stride, GLsizei count, const GLboolean *pointer);
typedef void (APIENTRY * PFNGLGETPOINTERVEXTPROC) (GLenum pname, GLvoid* *params);
typedef void (APIENTRY * PFNGLARRAYELEMENTARRAYEXTPROC)(GLenum mode, GLsizei count, const GLvoid* pi);

/* WIN_draw_range_elements */
typedef void (APIENTRY * PFNGLDRAWRANGEELEMENTSWINPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);

/* WIN_swap_hint */
typedef void (APIENTRY * PFNGLADDSWAPHINTRECTWINPROC)  (GLint x, GLint y, GLsizei width, GLsizei height);

/* EXT_paletted_texture */
typedef void (APIENTRY * PFNGLCOLORTABLEEXTPROC)
    (GLenum target, GLenum internalFormat, GLsizei width, GLenum format,
     GLenum type, const GLvoid *data);
typedef void (APIENTRY * PFNGLCOLORSUBTABLEEXTPROC)
    (GLenum target, GLsizei start, GLsizei count, GLenum format,
     GLenum type, const GLvoid *data);
typedef void (APIENTRY * PFNGLGETCOLORTABLEEXTPROC)
    (GLenum target, GLenum format, GLenum type, GLvoid *data);
typedef void (APIENTRY * PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)
    (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)
    (GLenum target, GLenum pname, GLfloat *params);


const GLubyte* APIENTRY gluErrorString (
    GLenum   errCode);

const wchar_t* APIENTRY gluErrorUnicodeStringEXT (
    GLenum   errCode);

const GLubyte* APIENTRY gluGetString (
    GLenum   name);

void APIENTRY gluOrtho2D (
    GLdouble left,
    GLdouble right,
    GLdouble bottom,
    GLdouble top);

void APIENTRY gluPerspective (
    GLdouble fovy,
    GLdouble aspect,
    GLdouble zNear,
    GLdouble zFar);

void APIENTRY gluPickMatrix (
    GLdouble x,
    GLdouble y,
    GLdouble width,
    GLdouble height,
    GLint    viewport[4]);

void APIENTRY gluLookAt (
    GLdouble eyex,
    GLdouble eyey,
    GLdouble eyez,
    GLdouble centerx,
    GLdouble centery,
    GLdouble centerz,
    GLdouble upx,
    GLdouble upy,
    GLdouble upz);

int APIENTRY gluProject (
    GLdouble        objx,
    GLdouble        objy,
    GLdouble        objz,
    const GLdouble  modelMatrix[16],
    const GLdouble  projMatrix[16],
    const GLint     viewport[4],
    GLdouble        *winx,
    GLdouble        *winy,
    GLdouble        *winz);

int APIENTRY gluUnProject (
    GLdouble       winx,
    GLdouble       winy,
    GLdouble       winz,
    const GLdouble modelMatrix[16],
    const GLdouble projMatrix[16],
    const GLint    viewport[4],
    GLdouble       *objx,
    GLdouble       *objy,
    GLdouble       *objz);


int APIENTRY gluScaleImage (
    GLenum      format,
    GLint       widthin,
    GLint       heightin,
    GLenum      typein,
    const void  *datain,
    GLint       widthout,
    GLint       heightout,
    GLenum      typeout,
    void        *dataout);


int APIENTRY gluBuild1DMipmaps (
    GLenum      target,
    GLint       components,
    GLint       width,
    GLenum      format,
    GLenum      type,
    const void  *data);

int APIENTRY gluBuild2DMipmaps (
    GLenum      target,
    GLint       components,
    GLint       width,
    GLint       height,
    GLenum      format,
    GLenum      type,
    const void  *data);

#ifdef __cplusplus

class GLUnurbs;
class GLUquadric;
class GLUtesselator;

/* backwards compatibility: */
typedef class GLUnurbs GLUnurbsObj;
typedef class GLUquadric GLUquadricObj;
typedef class GLUtesselator GLUtesselatorObj;
typedef class GLUtesselator GLUtriangulatorObj;

#else

typedef struct GLUnurbs GLUnurbs;
typedef struct GLUquadric GLUquadric;
typedef struct GLUtesselator GLUtesselator;

/* backwards compatibility: */
typedef struct GLUnurbs GLUnurbsObj;
typedef struct GLUquadric GLUquadricObj;
typedef struct GLUtesselator GLUtesselatorObj;
typedef struct GLUtesselator GLUtriangulatorObj;

#endif


GLUquadric* APIENTRY gluNewQuadric (void);
void APIENTRY gluDeleteQuadric (
    GLUquadric          *state);

void APIENTRY gluQuadricNormals (
    GLUquadric          *quadObject,
    GLenum              normals);

void APIENTRY gluQuadricTexture (
    GLUquadric          *quadObject,
    GLboolean           textureCoords);

void APIENTRY gluQuadricOrientation (
    GLUquadric          *quadObject,
    GLenum              orientation);

void APIENTRY gluQuadricDrawStyle (
    GLUquadric          *quadObject,
    GLenum              drawStyle);

void APIENTRY gluCylinder (
    GLUquadric          *qobj,
    GLdouble            baseRadius,
    GLdouble            topRadius,
    GLdouble            height,
    GLint               slices,
    GLint               stacks);

void APIENTRY gluDisk (
    GLUquadric          *qobj,
    GLdouble            innerRadius,
    GLdouble            outerRadius,
    GLint               slices,
    GLint               loops);

void APIENTRY gluPartialDisk (
    GLUquadric          *qobj,
    GLdouble            innerRadius,
    GLdouble            outerRadius,
    GLint               slices,
    GLint               loops,
    GLdouble            startAngle,
    GLdouble            sweepAngle);

void APIENTRY gluSphere (
    GLUquadric          *qobj,
    GLdouble            radius,
    GLint               slices,
    GLint               stacks);

void APIENTRY gluQuadricCallback (
    GLUquadric          *qobj,
    GLenum              which,
    void                (CALLBACK* fn)());

GLUtesselator* APIENTRY  gluNewTess(
    void );

void APIENTRY  gluDeleteTess(
    GLUtesselator       *tess );

void APIENTRY  gluTessBeginPolygon(
    GLUtesselator       *tess,
    void                *polygon_data );

void APIENTRY  gluTessBeginContour(
    GLUtesselator       *tess );

void APIENTRY  gluTessVertex(
    GLUtesselator       *tess,
    GLdouble            coords[3],
    void                *data );

void APIENTRY  gluTessEndContour(
    GLUtesselator       *tess );

void APIENTRY  gluTessEndPolygon(
    GLUtesselator       *tess );

void APIENTRY  gluTessProperty(
    GLUtesselator       *tess,
    GLenum              which,
    GLdouble            value );

void APIENTRY  gluTessNormal(
    GLUtesselator       *tess,
    GLdouble            x,
    GLdouble            y,
    GLdouble            z );

void APIENTRY  gluTessCallback(
    GLUtesselator       *tess,
    GLenum              which,
    void                (CALLBACK *fn)());

void APIENTRY  gluGetTessProperty(
    GLUtesselator       *tess,
    GLenum              which,
    GLdouble            *value );

GLUnurbs* APIENTRY gluNewNurbsRenderer (void);

void APIENTRY gluDeleteNurbsRenderer (
    GLUnurbs            *nobj);

void APIENTRY gluBeginSurface (
    GLUnurbs            *nobj);

void APIENTRY gluBeginCurve (
    GLUnurbs            *nobj);

void APIENTRY gluEndCurve (
    GLUnurbs            *nobj);

void APIENTRY gluEndSurface (
    GLUnurbs            *nobj);

void APIENTRY gluBeginTrim (
    GLUnurbs            *nobj);

void APIENTRY gluEndTrim (
    GLUnurbs            *nobj);

void APIENTRY gluPwlCurve (
    GLUnurbs            *nobj,
    GLint               count,
    GLfloat             *array,
    GLint               stride,
    GLenum              type);

void APIENTRY gluNurbsCurve (
    GLUnurbs            *nobj,
    GLint               nknots,
    GLfloat             *knot,
    GLint               stride,
    GLfloat             *ctlarray,
    GLint               order,
    GLenum              type);

void APIENTRY
gluNurbsSurface(
    GLUnurbs            *nobj,
    GLint               sknot_count,
    float               *sknot,
    GLint               tknot_count,
    GLfloat             *tknot,
    GLint               s_stride,
    GLint               t_stride,
    GLfloat             *ctlarray,
    GLint               sorder,
    GLint               torder,
    GLenum              type);

void APIENTRY
gluLoadSamplingMatrices (
    GLUnurbs            *nobj,
    const GLfloat       modelMatrix[16],
    const GLfloat       projMatrix[16],
    const GLint         viewport[4] );

void APIENTRY
gluNurbsProperty (
    GLUnurbs            *nobj,
    GLenum              property,
    GLfloat             value );

void APIENTRY
gluGetNurbsProperty (
    GLUnurbs            *nobj,
    GLenum              property,
    GLfloat             *value );

void APIENTRY
gluNurbsCallback (
    GLUnurbs            *nobj,
    GLenum              which,
    void                (CALLBACK* fn)() );


/****           Callback function prototypes    ****/

/* gluQuadricCallback */
void APIENTRY   gluBeginPolygon( GLUtesselator *tess );

void APIENTRY   gluNextContour(  GLUtesselator *tess,
                                 GLenum        type );

void APIENTRY   gluEndPolygon(   GLUtesselator *tess );
