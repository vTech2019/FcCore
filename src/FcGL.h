#ifndef __FCGL_H__
#define __FCGL_H__

#include "FcGLX.h"

#undef GL_VERSION_1_1   
#undef GL_VERSION_1_2   
#undef GL_VERSION_1_3   

#include <GL/glcorearb.h>

#include <FcCoreLoader.h>	
#include <stdlib.h>		
#include <stdbool.h>		
#include <string.h>
#include <stdio.h>


void APIENTRY glCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

typedef struct _FcGL_t{
    FcLib_t mLib;
//GL 1.0
    PFNGLCULLFACEPROC m_glCullFace;
    PFNGLFRONTFACEPROC m_glFrontFace;
    PFNGLHINTPROC m_glHint;
    PFNGLLINEWIDTHPROC m_glLineWidth;
    PFNGLPOINTSIZEPROC m_glPointSize;
    PFNGLPOLYGONMODEPROC m_glPolygonMode;
    PFNGLSCISSORPROC m_glScissor;
    PFNGLTEXPARAMETERFPROC m_glTexParameterf;
    PFNGLTEXPARAMETERFVPROC m_glTexParameterfv;
    PFNGLTEXPARAMETERIPROC m_glTexParameteri;
    PFNGLTEXPARAMETERIVPROC m_glTexParameteriv;
    PFNGLTEXIMAGE1DPROC m_glTexImage1D;
    PFNGLTEXIMAGE2DPROC m_glTexImage2D;
    PFNGLDRAWBUFFERPROC m_glDrawBuffer;
    PFNGLCLEARPROC m_glClear;
    PFNGLCLEARCOLORPROC m_glClearColor;
    PFNGLCLEARSTENCILPROC m_glClearStencil;
    PFNGLCLEARDEPTHPROC m_glClearDepth;
    PFNGLSTENCILMASKPROC m_glStencilMask;
    PFNGLCOLORMASKPROC m_glColorMask;
    PFNGLDEPTHMASKPROC m_glDepthMask;
    PFNGLDISABLEPROC m_glDisable;
    PFNGLENABLEPROC m_glEnable;
    PFNGLFINISHPROC m_glFinish;
    PFNGLFLUSHPROC m_glFlush;
    PFNGLBLENDFUNCPROC m_glBlendFunc;
    PFNGLLOGICOPPROC m_glLogicOp;
    PFNGLSTENCILFUNCPROC m_glStencilFunc;
    PFNGLSTENCILOPPROC m_glStencilOp;
    PFNGLDEPTHFUNCPROC m_glDepthFunc;
    PFNGLPIXELSTOREFPROC m_glPixelStoref;
    PFNGLPIXELSTOREIPROC m_glPixelStorei;
    PFNGLREADBUFFERPROC m_glReadBuffer;
    PFNGLREADPIXELSPROC m_glReadPixels;
    PFNGLGETBOOLEANVPROC m_glGetBooleanv;
    PFNGLGETDOUBLEVPROC m_glGetDoublev;
    PFNGLGETERRORPROC m_glGetError;
    PFNGLGETFLOATVPROC m_glGetFloatv;
    PFNGLGETINTEGERVPROC m_glGetIntegerv;
    PFNGLGETSTRINGPROC m_glGetString;
    PFNGLGETTEXIMAGEPROC m_glGetTexImage;
    PFNGLGETTEXPARAMETERFVPROC m_glGetTexParameterfv;
    PFNGLGETTEXPARAMETERIVPROC m_glGetTexParameteriv;
    PFNGLGETTEXLEVELPARAMETERFVPROC m_glGetTexLevelParameterfv;
    PFNGLGETTEXLEVELPARAMETERIVPROC m_glGetTexLevelParameteriv;
    PFNGLISENABLEDPROC m_glIsEnabled;
    PFNGLDEPTHRANGEPROC m_glDepthRange;
    PFNGLVIEWPORTPROC m_glViewport;
//GL 1.0
//GL 1.1
	PFNGLDRAWARRAYSPROC m_glDrawArrays;
	PFNGLDRAWELEMENTSPROC m_glDrawElements;
	PFNGLGETPOINTERVPROC m_glGetPointerv;
	PFNGLPOLYGONOFFSETPROC m_glPolygonOffset;
	PFNGLCOPYTEXIMAGE1DPROC m_glCopyTexImage1D;
	PFNGLCOPYTEXIMAGE2DPROC m_glCopyTexImage2D;
	PFNGLCOPYTEXSUBIMAGE1DPROC m_glCopyTexSubImage1D;
	PFNGLCOPYTEXSUBIMAGE2DPROC m_glCopyTexSubImage2D;
	PFNGLTEXSUBIMAGE1DPROC m_glTexSubImage1D;
	PFNGLTEXSUBIMAGE2DPROC m_glTexSubImage2D;
	PFNGLBINDTEXTUREPROC m_glBindTexture;
	PFNGLDELETETEXTURESPROC m_glDeleteTextures;
	PFNGLGENTEXTURESPROC m_glGenTextures;
    PFNGLISTEXTUREPROC m_glIsTexture;
//GL 1.1
//GL 1.2
    PFNGLDRAWRANGEELEMENTSPROC m_glDrawRangeElements;
    PFNGLTEXIMAGE3DPROC m_glTexImage3D;
    PFNGLTEXSUBIMAGE3DPROC m_glTexSubImage3D;
    PFNGLCOPYTEXSUBIMAGE3DPROC m_glCopyTexSubImage3D;
//GL 1.2
//GL 1.3
	PFNGLACTIVETEXTUREPROC m_glActiveTexture;
	PFNGLSAMPLECOVERAGEPROC m_glSampleCoverage;
	PFNGLCOMPRESSEDTEXIMAGE3DPROC m_glCompressedTexImage3D;
	PFNGLCOMPRESSEDTEXIMAGE2DPROC m_glCompressedTexImage2D;
	PFNGLCOMPRESSEDTEXIMAGE1DPROC m_glCompressedTexImage1D;
	PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC m_glCompressedTexSubImage3D;
	PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC m_glCompressedTexSubImage2D;
	PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC m_glCompressedTexSubImage1D;
	PFNGLGETCOMPRESSEDTEXIMAGEPROC m_glGetCompressedTexImage;
//GL 1.3
//GL 1.4
	PFNGLBLENDFUNCSEPARATEPROC m_glBlendFuncSeparate;
	PFNGLMULTIDRAWARRAYSPROC m_glMultiDrawArrays;
	PFNGLMULTIDRAWELEMENTSPROC m_glMultiDrawElements;
	PFNGLPOINTPARAMETERFPROC m_glPointParameterf;
	PFNGLPOINTPARAMETERFVPROC m_glPointParameterfv;
	PFNGLPOINTPARAMETERIPROC m_glPointParameteri;
	PFNGLPOINTPARAMETERIVPROC m_glPointParameteriv;
	PFNGLBLENDCOLORPROC m_glBlendColor;
	PFNGLBLENDEQUATIONPROC m_glBlendEquation;
//GL 1.4
//GL 1.5
	PFNGLGENQUERIESPROC m_glGenQueries;
	PFNGLDELETEQUERIESPROC m_glDeleteQueries;
	PFNGLISQUERYPROC m_glIsQuery;
	PFNGLBEGINQUERYPROC m_glBeginQuery;
	PFNGLENDQUERYPROC m_glEndQuery;
	PFNGLGETQUERYIVPROC m_glGetQueryiv;
	PFNGLGETQUERYOBJECTIVPROC m_glGetQueryObjectiv;
	PFNGLGETQUERYOBJECTUIVPROC m_glGetQueryObjectuiv;
	PFNGLBINDBUFFERPROC m_glBindBuffer;
	PFNGLDELETEBUFFERSPROC m_glDeleteBuffers;
	PFNGLGENBUFFERSPROC m_glGenBuffers;
	PFNGLISBUFFERPROC m_glIsBuffer;
	PFNGLBUFFERDATAPROC m_glBufferData;
	PFNGLBUFFERSUBDATAPROC m_glBufferSubData;
	PFNGLGETBUFFERSUBDATAPROC m_glGetBufferSubData;
	PFNGLMAPBUFFERPROC m_glMapBuffer;
	PFNGLUNMAPBUFFERPROC m_glUnmapBuffer;
	PFNGLGETBUFFERPARAMETERIVPROC m_glGetBufferParameteriv;
	PFNGLGETBUFFERPOINTERVPROC m_glGetBufferPointerv;
//GL 1.5
//GL 2.0
	PFNGLBLENDEQUATIONSEPARATEPROC m_glBlendEquationSeparate;
	PFNGLDRAWBUFFERSPROC m_glDrawBuffers;
	PFNGLSTENCILOPSEPARATEPROC m_glStencilOpSeparate;
	PFNGLSTENCILFUNCSEPARATEPROC m_glStencilFuncSeparate;
	PFNGLSTENCILMASKSEPARATEPROC m_glStencilMaskSeparate;
	PFNGLATTACHSHADERPROC m_glAttachShader;
	PFNGLBINDATTRIBLOCATIONPROC m_glBindAttribLocation;
	PFNGLCOMPILESHADERPROC m_glCompileShader;
	PFNGLCREATEPROGRAMPROC m_glCreateProgram;
	PFNGLCREATESHADERPROC m_glCreateShader;
	PFNGLDELETEPROGRAMPROC m_glDeleteProgram;
	PFNGLDELETESHADERPROC m_glDeleteShader; 
	PFNGLDETACHSHADERPROC m_glDetachShader;
	PFNGLDISABLEVERTEXATTRIBARRAYPROC m_glDisableVertexAttribArray;
	PFNGLENABLEVERTEXATTRIBARRAYPROC m_glEnableVertexAttribArray;
	PFNGLGETACTIVEATTRIBPROC m_glGetActiveAttrib;
	PFNGLGETACTIVEUNIFORMPROC m_glGetActiveUniform;
	PFNGLGETATTACHEDSHADERSPROC m_glGetAttachedShaders;
	PFNGLGETATTRIBLOCATIONPROC m_glGetAttribLocation;
	PFNGLGETPROGRAMIVPROC m_glGetProgramiv;
	PFNGLGETPROGRAMINFOLOGPROC m_glGetProgramInfoLog;
	PFNGLGETSHADERIVPROC m_glGetShaderiv;
	PFNGLGETSHADERINFOLOGPROC m_glGetShaderInfoLog;
	PFNGLGETSHADERSOURCEPROC m_glGetShaderSource;
	PFNGLGETUNIFORMLOCATIONPROC m_glGetUniformLocation;
	PFNGLGETUNIFORMFVPROC m_glGetUniformfv;
	PFNGLGETUNIFORMIVPROC m_glGetUniformiv;
	PFNGLGETVERTEXATTRIBDVPROC m_glGetVertexAttribdv;
	PFNGLGETVERTEXATTRIBFVPROC m_glGetVertexAttribfv;
	PFNGLGETVERTEXATTRIBIVPROC m_glGetVertexAttribiv;
	PFNGLGETVERTEXATTRIBPOINTERVPROC m_glGetVertexAttribPointerv;
	PFNGLISPROGRAMPROC m_glIsProgram; 
	PFNGLISSHADERPROC m_glIsShader;
	PFNGLLINKPROGRAMPROC m_glLinkProgram;
	PFNGLSHADERSOURCEPROC m_glShaderSource;
	PFNGLUSEPROGRAMPROC m_glUseProgram;
	PFNGLUNIFORM1FPROC m_glUniform1f;
	PFNGLUNIFORM2FPROC m_glUniform2f;
	PFNGLUNIFORM3FPROC m_glUniform3f;
	PFNGLUNIFORM4FPROC m_glUniform4f;
	PFNGLUNIFORM1IPROC m_glUniform1i;
	PFNGLUNIFORM2IPROC m_glUniform2i;
	PFNGLUNIFORM3IPROC m_glUniform3i;
	PFNGLUNIFORM4IPROC m_glUniform4i;
	PFNGLUNIFORM1FVPROC m_glUniform1fv;
	PFNGLUNIFORM2FVPROC m_glUniform2fv;
	PFNGLUNIFORM3FVPROC m_glUniform3fv;
	PFNGLUNIFORM4FVPROC m_glUniform4fv;
	PFNGLUNIFORM1IVPROC m_glUniform1iv;
	PFNGLUNIFORM2IVPROC m_glUniform2iv;
	PFNGLUNIFORM3IVPROC m_glUniform3iv;
	PFNGLUNIFORM4IVPROC m_glUniform4iv;
	PFNGLUNIFORMMATRIX2FVPROC m_glUniformMatrix2fv;
	PFNGLUNIFORMMATRIX3FVPROC m_glUniformMatrix3fv;
	PFNGLUNIFORMMATRIX4FVPROC m_glUniformMatrix4fv;
	PFNGLVALIDATEPROGRAMPROC m_glValidateProgram;
	PFNGLVERTEXATTRIB1DPROC m_glVertexAttrib1d;
	PFNGLVERTEXATTRIB1DVPROC m_glVertexAttrib1dv;
	PFNGLVERTEXATTRIB1FPROC m_glVertexAttrib1f;
	PFNGLVERTEXATTRIB1FVPROC m_glVertexAttrib1fv;
	PFNGLVERTEXATTRIB1SPROC m_glVertexAttrib1s;
	PFNGLVERTEXATTRIB1SVPROC m_glVertexAttrib1sv;
	PFNGLVERTEXATTRIB2DPROC m_glVertexAttrib2d;
	PFNGLVERTEXATTRIB2DVPROC m_glVertexAttrib2dv;
	PFNGLVERTEXATTRIB2FPROC m_glVertexAttrib2f;
	PFNGLVERTEXATTRIB2FVPROC m_glVertexAttrib2fv;
	PFNGLVERTEXATTRIB2SPROC m_glVertexAttrib2s;
	PFNGLVERTEXATTRIB2SVPROC m_glVertexAttrib2sv;
	PFNGLVERTEXATTRIB3DPROC m_glVertexAttrib3d;
	PFNGLVERTEXATTRIB3DVPROC m_glVertexAttrib3dv;
	PFNGLVERTEXATTRIB3FPROC m_glVertexAttrib3f;
	PFNGLVERTEXATTRIB3FVPROC m_glVertexAttrib3fv;
	PFNGLVERTEXATTRIB3SPROC m_glVertexAttrib3s;
	PFNGLVERTEXATTRIB3SVPROC m_glVertexAttrib3sv;
	PFNGLVERTEXATTRIB4NBVPROC m_glVertexAttrib4Nbv;
	PFNGLVERTEXATTRIB4NIVPROC m_glVertexAttrib4Niv;
	PFNGLVERTEXATTRIB4NSVPROC m_glVertexAttrib4Nsv;
	PFNGLVERTEXATTRIB4NUBPROC m_glVertexAttrib4Nub;
	PFNGLVERTEXATTRIB4NUBVPROC m_glVertexAttrib4Nubv;
	PFNGLVERTEXATTRIB4NUIVPROC m_glVertexAttrib4Nuiv;
	PFNGLVERTEXATTRIB4NUSVPROC m_glVertexAttrib4Nusv;
	PFNGLVERTEXATTRIB4BVPROC m_glVertexAttrib4bv;
	PFNGLVERTEXATTRIB4DPROC m_glVertexAttrib4d;
	PFNGLVERTEXATTRIB4DVPROC m_glVertexAttrib4dv;
	PFNGLVERTEXATTRIB4FPROC m_glVertexAttrib4f;
	PFNGLVERTEXATTRIB4FVPROC m_glVertexAttrib4fv;
	PFNGLVERTEXATTRIB4IVPROC m_glVertexAttrib4iv;
	PFNGLVERTEXATTRIB4SPROC m_glVertexAttrib4s;
	PFNGLVERTEXATTRIB4SVPROC m_glVertexAttrib4sv;
	PFNGLVERTEXATTRIB4UBVPROC m_glVertexAttrib4ubv;
	PFNGLVERTEXATTRIB4UIVPROC m_glVertexAttrib4uiv;
	PFNGLVERTEXATTRIB4USVPROC m_glVertexAttrib4usv;
	PFNGLVERTEXATTRIBPOINTERPROC m_glVertexAttribPointer;
//GL 2.0
    PFNGLBINDVERTEXARRAYPROC m_glBindVertexArray;
    PFNGLDELETEVERTEXARRAYSPROC m_glDeleteVertexArrays;
    PFNGLGENVERTEXARRAYSPROC m_glGenVertexArrays;
    PFNGLISVERTEXARRAYPROC m_glIsVertexArray;
    PFNGLBINDVERTEXBUFFERPROC m_glBindVertexBuffer;
    PFNGLVERTEXATTRIBFORMATPROC m_glVertexAttribFormat;
    PFNGLVERTEXATTRIBIFORMATPROC m_glVertexAttribIFormat;
    PFNGLVERTEXATTRIBLFORMATPROC m_glVertexAttribLFormat;
    PFNGLVERTEXATTRIBBINDINGPROC m_glVertexAttribBinding;
    PFNGLVERTEXBINDINGDIVISORPROC m_glVertexBindingDivisor;
    PFNGLDEBUGMESSAGECONTROLPROC m_glDebugMessageControl;
    PFNGLDEBUGMESSAGEINSERTPROC m_glDebugMessageInsert;
    PFNGLDEBUGMESSAGECALLBACKPROC m_glDebugMessageCallback;
    PFNGLGETDEBUGMESSAGELOGPROC m_glGetDebugMessageLog;
    //PFNGLGETPOINTERVPROC m_glGetPointerv;
    PFNGLPUSHDEBUGGROUPPROC m_glPushDebugGroup;
    PFNGLPOPDEBUGGROUPPROC m_glPopDebugGroup;
    PFNGLOBJECTLABELPROC m_glObjectLabel;
    PFNGLGETOBJECTLABELPROC m_glGetObjectLabel;
    PFNGLOBJECTPTRLABELPROC m_glObjectPtrLabel;
    PFNGLGETOBJECTPTRLABELPROC m_glGetObjectPtrLabel;
    PFNGLGETUNIFORMINDICESPROC m_glGetUniformIndices;
    PFNGLGETACTIVEUNIFORMSIVPROC m_glGetActiveUniformsiv;
    PFNGLGETACTIVEUNIFORMNAMEPROC m_glGetActiveUniformName;
    PFNGLGETUNIFORMBLOCKINDEXPROC m_glGetUniformBlockIndex;
    PFNGLGETACTIVEUNIFORMBLOCKIVPROC m_glGetActiveUniformBlockiv;
    PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC m_glGetActiveUniformBlockName;
    PFNGLBINDBUFFERRANGEPROC m_glBindBufferRange;
    PFNGLBINDBUFFERBASEPROC m_glBindBufferBase;
    PFNGLGETINTEGERI_VPROC m_glGetIntegeri_v;
    PFNGLUNIFORMBLOCKBINDINGPROC m_glUniformBlockBinding;
}FcGL_t;


extern FcGL_t s_fcGL;
void APIENTRY glCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);




static GLboolean GET_GL_FUNCTIONS_GL_VERSION_1_0(FcGL_t* lib) {
    GLboolean r = GL_FALSE;
    r = ((lib->m_glCullFace = (PFNGLCULLFACEPROC)FcLib_loadFunction(lib->mLib, "glCullFace")) == NULL) || r;
    r = ((lib->m_glFrontFace = (PFNGLFRONTFACEPROC)FcLib_loadFunction(lib->mLib, "glFrontFace")) == NULL) || r;
    r = ((lib->m_glHint = (PFNGLHINTPROC)FcLib_loadFunction(lib->mLib, "glHint")) == NULL) || r;
    r = ((lib->m_glLineWidth = (PFNGLLINEWIDTHPROC)FcLib_loadFunction(lib->mLib, "glLineWidth")) == NULL) || r;
    r = ((lib->m_glPointSize = (PFNGLPOINTSIZEPROC)FcLib_loadFunction(lib->mLib, "glPointSize")) == NULL) || r;
    r = ((lib->m_glPolygonMode = (PFNGLPOLYGONMODEPROC)FcLib_loadFunction(lib->mLib, "glPolygonMode")) == NULL) || r;
    r = ((lib->m_glScissor = (PFNGLSCISSORPROC)FcLib_loadFunction(lib->mLib, "glScissor")) == NULL) || r;
    r = ((lib->m_glTexParameterf = (PFNGLTEXPARAMETERFPROC)FcLib_loadFunction(lib->mLib, "glTexParameterf")) == NULL) || r;
    r = ((lib->m_glTexParameterfv = (PFNGLTEXPARAMETERFVPROC)FcLib_loadFunction(lib->mLib, "glTexParameterfv")) == NULL) || r;
    r = ((lib->m_glTexParameteri = (PFNGLTEXPARAMETERIPROC)FcLib_loadFunction(lib->mLib, "glTexParameteri")) == NULL) || r;
    r = ((lib->m_glTexParameteriv = (PFNGLTEXPARAMETERIVPROC)FcLib_loadFunction(lib->mLib, "glTexParameteriv")) == NULL) || r;
    r = ((lib->m_glTexImage1D = (PFNGLTEXIMAGE1DPROC)FcLib_loadFunction(lib->mLib, "glTexImage1D")) == NULL) || r;
    r = ((lib->m_glTexImage2D = (PFNGLTEXIMAGE2DPROC)FcLib_loadFunction(lib->mLib, "glTexImage2D")) == NULL) || r;
    r = ((lib->m_glDrawBuffer = (PFNGLDRAWBUFFERPROC)FcLib_loadFunction(lib->mLib, "glDrawBuffer")) == NULL) || r;
    r = ((lib->m_glClear = (PFNGLCLEARPROC)FcLib_loadFunction(lib->mLib, "glClear")) == NULL) || r;
    r = ((lib->m_glClearColor = (PFNGLCLEARCOLORPROC)FcLib_loadFunction(lib->mLib, "glClearColor")) == NULL) || r;
    r = ((lib->m_glClearStencil = (PFNGLCLEARSTENCILPROC)FcLib_loadFunction(lib->mLib, "glClearStencil")) == NULL) || r;
    r = ((lib->m_glClearDepth = (PFNGLCLEARDEPTHPROC)FcLib_loadFunction(lib->mLib, "glClearDepth")) == NULL) || r;
    r = ((lib->m_glStencilMask = (PFNGLSTENCILMASKPROC)FcLib_loadFunction(lib->mLib, "glStencilMask")) == NULL) || r;
    r = ((lib->m_glColorMask = (PFNGLCOLORMASKPROC)FcLib_loadFunction(lib->mLib, "glColorMask")) == NULL) || r;
    r = ((lib->m_glDepthMask = (PFNGLDEPTHMASKPROC)FcLib_loadFunction(lib->mLib, "glDepthMask")) == NULL) || r;
    r = ((lib->m_glDisable = (PFNGLDISABLEPROC)FcLib_loadFunction(lib->mLib, "glDisable")) == NULL) || r;
    r = ((lib->m_glEnable = (PFNGLENABLEPROC)FcLib_loadFunction(lib->mLib, "glEnable")) == NULL) || r;
    r = ((lib->m_glFinish = (PFNGLFINISHPROC)FcLib_loadFunction(lib->mLib, "glFinish")) == NULL) || r;
    r = ((lib->m_glFlush = (PFNGLFLUSHPROC)FcLib_loadFunction(lib->mLib, "glFlush")) == NULL) || r;
    r = ((lib->m_glBlendFunc = (PFNGLBLENDFUNCPROC)FcLib_loadFunction(lib->mLib, "glBlendFunc")) == NULL) || r;
    r = ((lib->m_glLogicOp = (PFNGLLOGICOPPROC)FcLib_loadFunction(lib->mLib, "glLogicOp")) == NULL) || r;
    r = ((lib->m_glStencilFunc = (PFNGLSTENCILFUNCPROC)FcLib_loadFunction(lib->mLib, "glStencilFunc")) == NULL) || r;
    r = ((lib->m_glStencilOp = (PFNGLSTENCILOPPROC)FcLib_loadFunction(lib->mLib, "glStencilOp")) == NULL) || r;
    r = ((lib->m_glDepthFunc = (PFNGLDEPTHFUNCPROC)FcLib_loadFunction(lib->mLib, "glDepthFunc")) == NULL) || r;
    r = ((lib->m_glPixelStoref = (PFNGLPIXELSTOREFPROC)FcLib_loadFunction(lib->mLib, "glPixelStoref")) == NULL) || r;
    r = ((lib->m_glPixelStorei = (PFNGLPIXELSTOREIPROC)FcLib_loadFunction(lib->mLib, "glPixelStorei")) == NULL) || r;
    r = ((lib->m_glReadBuffer = (PFNGLREADBUFFERPROC)FcLib_loadFunction(lib->mLib, "glReadBuffer")) == NULL) || r;
    r = ((lib->m_glReadPixels = (PFNGLREADPIXELSPROC)FcLib_loadFunction(lib->mLib, "glReadPixels")) == NULL) || r;
    r = ((lib->m_glGetBooleanv = (PFNGLGETBOOLEANVPROC)FcLib_loadFunction(lib->mLib, "glGetBooleanv")) == NULL) || r;
    r = ((lib->m_glGetDoublev = (PFNGLGETDOUBLEVPROC)FcLib_loadFunction(lib->mLib, "glGetDoublev")) == NULL) || r;
    r = ((lib->m_glGetError = (PFNGLGETERRORPROC)FcLib_loadFunction(lib->mLib, "glGetError")) == NULL) || r;
    r = ((lib->m_glGetFloatv = (PFNGLGETFLOATVPROC)FcLib_loadFunction(lib->mLib, "glGetFloatv")) == NULL) || r;
    r = ((lib->m_glGetIntegerv = (PFNGLGETINTEGERVPROC)FcLib_loadFunction(lib->mLib, "glGetIntegerv")) == NULL) || r;
    r = ((lib->m_glGetString = (PFNGLGETSTRINGPROC)FcLib_loadFunction(lib->mLib, "glGetString")) == NULL) || r;
    r = ((lib->m_glGetTexImage = (PFNGLGETTEXIMAGEPROC)FcLib_loadFunction(lib->mLib, "glGetTexImage")) == NULL) || r;
    r = ((lib->m_glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC)FcLib_loadFunction(lib->mLib, "glGetTexParameterfv")) == NULL) || r;
    r = ((lib->m_glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC)FcLib_loadFunction(lib->mLib, "glGetTexParameteriv")) == NULL) || r;
    r = ((lib->m_glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC)FcLib_loadFunction(lib->mLib, "glGetTexLevelParameterfv")) == NULL) || r;
    r = ((lib->m_glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC)FcLib_loadFunction(lib->mLib, "glGetTexLevelParameteriv")) == NULL) || r;
    r = ((lib->m_glIsEnabled = (PFNGLISENABLEDPROC)FcLib_loadFunction(lib->mLib, "glIsEnabled")) == NULL) || r;
    r = ((lib->m_glDepthRange = (PFNGLDEPTHRANGEPROC)FcLib_loadFunction(lib->mLib, "glDepthRange")) == NULL) || r;
    r = ((lib->m_glViewport = (PFNGLVIEWPORTPROC)FcLib_loadFunction(lib->mLib, "glViewport")) == NULL) || r;
    return r;
}

static bool find_GL_extensions(FcGL_t* lib, const char* pName) {
    const char* extensions = (const char*)lib->m_glGetString(GL_EXTENSIONS);
    size_t size = strlen(pName);
    while (extensions) {
        if (!strncmp(extensions, pName, size) && (*(extensions + size) == 0 || *(extensions + size) == ' '))
            return true;
        extensions = strchr(extensions, ' ');
        if (extensions)
            extensions++;
    }
    return false;
}

static inline bool find_GL_version(FcGL_t* lib, GLint majorVersion, GLint minorVersion) {
    GLint m_majorVersion = 0, m_minorVersion = 0;
    lib->m_glGetIntegerv(GL_MAJOR_VERSION, &m_majorVersion);
    lib->m_glGetIntegerv(GL_MINOR_VERSION, &m_minorVersion);
    if (m_majorVersion > majorVersion)
        return true;
    else if (m_majorVersion == majorVersion)
        if (m_minorVersion >= minorVersion) {
            return true;
        }
    return false;
}


static GLboolean GET_GL_FUNCTIONS_GL_VERSION_1_1(FcGL_t* lib) {
    GLboolean r = GL_FALSE;
    r = ((lib->m_glDrawArrays = (PFNGLDRAWARRAYSPROC)FcLib_loadFunction(lib->mLib, "glDrawArrays")) == NULL) || r;
    r = ((lib->m_glDrawElements = (PFNGLDRAWELEMENTSPROC)FcLib_loadFunction(lib->mLib, "glDrawElements")) == NULL) || r;
    r = ((lib->m_glGetPointerv = (PFNGLGETPOINTERVPROC)FcLib_loadFunction(lib->mLib, "glGetPointerv")) == NULL) || r;
    r = ((lib->m_glPolygonOffset = (PFNGLPOLYGONOFFSETPROC)FcLib_loadFunction(lib->mLib, "glPolygonOffset")) == NULL) || r;
    r = ((lib->m_glCopyTexImage1D = (PFNGLCOPYTEXIMAGE1DPROC)FcLib_loadFunction(lib->mLib, "glCopyTexImage1D")) == NULL) || r;
    r = ((lib->m_glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC)FcLib_loadFunction(lib->mLib, "glCopyTexImage2D")) == NULL) || r;
    r = ((lib->m_glCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC)FcLib_loadFunction(lib->mLib, "glCopyTexSubImage1D")) == NULL) || r;
    r = ((lib->m_glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC)FcLib_loadFunction(lib->mLib, "glCopyTexSubImage2D")) == NULL) || r;
    r = ((lib->m_glTexSubImage1D = (PFNGLTEXSUBIMAGE1DPROC)FcLib_loadFunction(lib->mLib, "glTexSubImage1D")) == NULL) || r;
    r = ((lib->m_glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC)FcLib_loadFunction(lib->mLib, "glTexSubImage2D")) == NULL) || r;
    r = ((lib->m_glBindTexture = (PFNGLBINDTEXTUREPROC)FcLib_loadFunction(lib->mLib, "glBindTexture")) == NULL) || r;
    r = ((lib->m_glDeleteTextures = (PFNGLDELETETEXTURESPROC)FcLib_loadFunction(lib->mLib, "glDeleteTextures")) == NULL) || r;
    r = ((lib->m_glGenTextures = (PFNGLGENTEXTURESPROC)FcLib_loadFunction(lib->mLib, "glGenTextures")) == NULL) || r;
    r = ((lib->m_glIsTexture = (PFNGLISTEXTUREPROC)FcLib_loadFunction(lib->mLib, "glIsTexture")) == NULL) || r;
    return r;
}


static GLboolean GET_GL_FUNCTIONS_GL_VERSION_1_2(FcGL_t* lib, void* glGetProcAddress(const char* const)) {
    GLboolean r = GL_FALSE;
    r = ((lib->m_glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)glGetProcAddress("glDrawRangeElements")) == NULL) || r;
    r = ((lib->m_glTexImage3D = (PFNGLTEXIMAGE3DPROC)glGetProcAddress("glTexImage3D")) == NULL) || r;
    r = ((lib->m_glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)glGetProcAddress("glTexSubImage3D")) == NULL) || r;
    r = ((lib->m_glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)glGetProcAddress("glCopyTexSubImage3D")) == NULL) || r;
    return r;
}

static GLboolean GET_GL_FUNCTIONS_GL_VERSION_1_3(FcGL_t* lib, void* glGetProcAddress(const char* const)) {
    GLboolean r = GL_FALSE;
    r = ((lib->m_glActiveTexture = (PFNGLACTIVETEXTUREPROC)glGetProcAddress("glActiveTexture")) == NULL) || r;
    r = ((lib->m_glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)glGetProcAddress("glSampleCoverage")) == NULL) || r;
    r = ((lib->m_glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)glGetProcAddress("glCompressedTexImage3D")) == NULL) || r;
    r = ((lib->m_glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)glGetProcAddress("glCompressedTexImage2D")) == NULL) || r;
    r = ((lib->m_glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)glGetProcAddress("glCompressedTexImage1D")) == NULL) || r;
    r = ((lib->m_glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)glGetProcAddress("glCompressedTexSubImage3D")) == NULL) || r;
    r = ((lib->m_glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)glGetProcAddress("glCompressedTexSubImage2D")) == NULL) || r;
    r = ((lib->m_glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)glGetProcAddress("glCompressedTexSubImage1D")) == NULL) || r;
    r = ((lib->m_glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)glGetProcAddress("glGetCompressedTexImage")) == NULL) || r;
    return r;
}

static GLboolean GET_GL_FUNCTIONS_GL_VERSION_1_4(FcGL_t* lib, void* glGetProcAddress(const char* const)) {
    GLboolean r = GL_FALSE;
    r = ((lib->m_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)glGetProcAddress("glBlendFuncSeparate")) == NULL) || r;
    r = ((lib->m_glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)glGetProcAddress("glMultiDrawArrays")) == NULL) || r;
    r = ((lib->m_glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)glGetProcAddress("glMultiDrawElements")) == NULL) || r;
    r = ((lib->m_glPointParameterf = (PFNGLPOINTPARAMETERFPROC)glGetProcAddress("glPointParameterf")) == NULL) || r;
    r = ((lib->m_glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)glGetProcAddress("glPointParameterfv")) == NULL) || r;
    r = ((lib->m_glPointParameteri = (PFNGLPOINTPARAMETERIPROC)glGetProcAddress("glPointParameteri")) == NULL) || r;
    r = ((lib->m_glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC)glGetProcAddress("glPointParameteriv")) == NULL) || r;
    r = ((lib->m_glBlendColor = (PFNGLBLENDCOLORPROC)glGetProcAddress("glBlendColor")) == NULL) || r;
    r = ((lib->m_glBlendEquation = (PFNGLBLENDEQUATIONPROC)glGetProcAddress("glBlendEquation")) == NULL) || r;
    return r;
}


static GLboolean GET_GL_FUNCTIONS_GL_VERSION_1_5(FcGL_t* lib, void* glGetProcAddress(const char* const)) {
    GLboolean r = GL_FALSE;
    r = ((lib->m_glGenQueries = (PFNGLGENQUERIESPROC)glGetProcAddress("glGenQueries")) == NULL) || r;
    r = ((lib->m_glDeleteQueries = (PFNGLDELETEQUERIESPROC)glGetProcAddress("glDeleteQueries")) == NULL) || r;
    r = ((lib->m_glIsQuery = (PFNGLISQUERYPROC)glGetProcAddress("glIsQuery")) == NULL) || r;
    r = ((lib->m_glBeginQuery = (PFNGLBEGINQUERYPROC)glGetProcAddress("glBeginQuery")) == NULL) || r;
    r = ((lib->m_glEndQuery = (PFNGLENDQUERYPROC)glGetProcAddress("glEndQuery")) == NULL) || r;
    r = ((lib->m_glGetQueryiv = (PFNGLGETQUERYIVPROC)glGetProcAddress("glGetQueryiv")) == NULL) || r;
    r = ((lib->m_glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)glGetProcAddress("glGetQueryObjectiv")) == NULL) || r;
    r = ((lib->m_glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)glGetProcAddress("glGetQueryObjectuiv")) == NULL) || r;
    r = ((lib->m_glBindBuffer = (PFNGLBINDBUFFERPROC)glGetProcAddress("glBindBuffer")) == NULL) || r;
    r = ((lib->m_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)glGetProcAddress("glDeleteBuffers")) == NULL) || r;
    r = ((lib->m_glGenBuffers = (PFNGLGENBUFFERSPROC)glGetProcAddress("glGenBuffers")) == NULL) || r;
    r = ((lib->m_glIsBuffer = (PFNGLISBUFFERPROC)glGetProcAddress("glIsBuffer")) == NULL) || r;
    r = ((lib->m_glBufferData = (PFNGLBUFFERDATAPROC)glGetProcAddress("glBufferData")) == NULL) || r;
    r = ((lib->m_glBufferSubData = (PFNGLBUFFERSUBDATAPROC)glGetProcAddress("glBufferSubData")) == NULL) || r;
    r = ((lib->m_glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)glGetProcAddress("glGetBufferSubData")) == NULL) || r;
    r = ((lib->m_glMapBuffer = (PFNGLMAPBUFFERPROC)glGetProcAddress("glMapBuffer")) == NULL) || r;
    r = ((lib->m_glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)glGetProcAddress("glUnmapBuffer")) == NULL) || r;
    r = ((lib->m_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)glGetProcAddress("glGetBufferParameteriv")) == NULL) || r;
    r = ((lib->m_glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)glGetProcAddress("glGetBufferPointerv")) == NULL) || r;
    return r;
}


static GLboolean GET_GL_FUNCTIONS_GL_VERSION_2_0(FcGL_t* lib, void* glGetProcAddress(const char* const)) {
    GLboolean r = GL_FALSE;
    r = ((lib->m_glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)glGetProcAddress("glBlendEquationSeparate")) == NULL) || r;
    r = ((lib->m_glDrawBuffers = (PFNGLDRAWBUFFERSPROC)glGetProcAddress("glDrawBuffers")) == NULL) || r;
    r = ((lib->m_glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)glGetProcAddress("glStencilOpSeparate")) == NULL) || r;
    r = ((lib->m_glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)glGetProcAddress("glStencilFuncSeparate")) == NULL) || r;
    r = ((lib->m_glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)glGetProcAddress("glStencilMaskSeparate")) == NULL) || r;
    r = ((lib->m_glAttachShader = (PFNGLATTACHSHADERPROC)glGetProcAddress("glAttachShader")) == NULL) || r;
    r = ((lib->m_glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)glGetProcAddress("glBindAttribLocation")) == NULL) || r;
    r = ((lib->m_glCompileShader = (PFNGLCOMPILESHADERPROC)glGetProcAddress("glCompileShader")) == NULL) || r;
    r = ((lib->m_glCreateProgram = (PFNGLCREATEPROGRAMPROC)glGetProcAddress("glCreateProgram")) == NULL) || r;
    r = ((lib->m_glCreateShader = (PFNGLCREATESHADERPROC)glGetProcAddress("glCreateShader")) == NULL) || r;
    r = ((lib->m_glDeleteProgram = (PFNGLDELETEPROGRAMPROC)glGetProcAddress("glDeleteProgram")) == NULL) || r;
    r = ((lib->m_glDeleteShader = (PFNGLDELETESHADERPROC)glGetProcAddress("glDeleteShader")) == NULL) || r;
    r = ((lib->m_glDetachShader = (PFNGLDETACHSHADERPROC)glGetProcAddress("glDetachShader")) == NULL) || r;
    r = ((lib->m_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)glGetProcAddress("glDisableVertexAttribArray")) == NULL) || r;
    r = ((lib->m_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)glGetProcAddress("glEnableVertexAttribArray")) == NULL) || r;
    r = ((lib->m_glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)glGetProcAddress("glGetActiveAttrib")) == NULL) || r;
    r = ((lib->m_glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)glGetProcAddress("glGetActiveUniform")) == NULL) || r;
    r = ((lib->m_glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)glGetProcAddress("glGetAttachedShaders")) == NULL) || r;
    r = ((lib->m_glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)glGetProcAddress("glGetAttribLocation")) == NULL) || r;
    r = ((lib->m_glGetProgramiv = (PFNGLGETPROGRAMIVPROC)glGetProcAddress("glGetProgramiv")) == NULL) || r;
    r = ((lib->m_glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)glGetProcAddress("glGetProgramInfoLog")) == NULL) || r;
    r = ((lib->m_glGetShaderiv = (PFNGLGETSHADERIVPROC)glGetProcAddress("glGetShaderiv")) == NULL) || r;
    r = ((lib->m_glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)glGetProcAddress("glGetShaderInfoLog")) == NULL) || r;
    r = ((lib->m_glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)glGetProcAddress("glGetShaderSource")) == NULL) || r;
    r = ((lib->m_glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)glGetProcAddress("glGetUniformLocation")) == NULL) || r;
    r = ((lib->m_glGetUniformfv = (PFNGLGETUNIFORMFVPROC)glGetProcAddress("glGetUniformfv")) == NULL) || r;
    r = ((lib->m_glGetUniformiv = (PFNGLGETUNIFORMIVPROC)glGetProcAddress("glGetUniformiv")) == NULL) || r;
    r = ((lib->m_glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)glGetProcAddress("glGetVertexAttribdv")) == NULL) || r;
    r = ((lib->m_glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)glGetProcAddress("glGetVertexAttribfv")) == NULL) || r;
    r = ((lib->m_glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)glGetProcAddress("glGetVertexAttribiv")) == NULL) || r;
    r = ((lib->m_glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)glGetProcAddress("glGetVertexAttribPointerv")) == NULL) || r;
    r = ((lib->m_glIsProgram = (PFNGLISPROGRAMPROC)glGetProcAddress("glIsProgram")) == NULL) || r;
    r = ((lib->m_glIsShader = (PFNGLISSHADERPROC)glGetProcAddress("glIsShader")) == NULL) || r;
    r = ((lib->m_glLinkProgram = (PFNGLLINKPROGRAMPROC)glGetProcAddress("glLinkProgram")) == NULL) || r;
    r = ((lib->m_glShaderSource = (PFNGLSHADERSOURCEPROC)glGetProcAddress("glShaderSource")) == NULL) || r;
    r = ((lib->m_glUseProgram = (PFNGLUSEPROGRAMPROC)glGetProcAddress("glUseProgram")) == NULL) || r;
    r = ((lib->m_glUniform1f = (PFNGLUNIFORM1FPROC)glGetProcAddress("glUniform1f")) == NULL) || r;
    r = ((lib->m_glUniform2f = (PFNGLUNIFORM2FPROC)glGetProcAddress("glUniform2f")) == NULL) || r;
    r = ((lib->m_glUniform3f = (PFNGLUNIFORM3FPROC)glGetProcAddress("glUniform3f")) == NULL) || r;
    r = ((lib->m_glUniform4f = (PFNGLUNIFORM4FPROC)glGetProcAddress("glUniform4f")) == NULL) || r;
    r = ((lib->m_glUniform1i = (PFNGLUNIFORM1IPROC)glGetProcAddress("glUniform1i")) == NULL) || r;
    r = ((lib->m_glUniform2i = (PFNGLUNIFORM2IPROC)glGetProcAddress("glUniform2i")) == NULL) || r;
    r = ((lib->m_glUniform3i = (PFNGLUNIFORM3IPROC)glGetProcAddress("glUniform3i")) == NULL) || r;
    r = ((lib->m_glUniform4i = (PFNGLUNIFORM4IPROC)glGetProcAddress("glUniform4i")) == NULL) || r;
    r = ((lib->m_glUniform1fv = (PFNGLUNIFORM1FVPROC)glGetProcAddress("glUniform1fv")) == NULL) || r;
    r = ((lib->m_glUniform2fv = (PFNGLUNIFORM2FVPROC)glGetProcAddress("glUniform2fv")) == NULL) || r;
    r = ((lib->m_glUniform3fv = (PFNGLUNIFORM3FVPROC)glGetProcAddress("glUniform3fv")) == NULL) || r;
    r = ((lib->m_glUniform4fv = (PFNGLUNIFORM4FVPROC)glGetProcAddress("glUniform4fv")) == NULL) || r;
    r = ((lib->m_glUniform1iv = (PFNGLUNIFORM1IVPROC)glGetProcAddress("glUniform1iv")) == NULL) || r;
    r = ((lib->m_glUniform2iv = (PFNGLUNIFORM2IVPROC)glGetProcAddress("glUniform2iv")) == NULL) || r;
    r = ((lib->m_glUniform3iv = (PFNGLUNIFORM3IVPROC)glGetProcAddress("glUniform3iv")) == NULL) || r;
    r = ((lib->m_glUniform4iv = (PFNGLUNIFORM4IVPROC)glGetProcAddress("glUniform4iv")) == NULL) || r;
    r = ((lib->m_glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)glGetProcAddress("glUniformMatrix2fv")) == NULL) || r;
    r = ((lib->m_glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)glGetProcAddress("glUniformMatrix3fv")) == NULL) || r;
    r = ((lib->m_glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)glGetProcAddress("glUniformMatrix4fv")) == NULL) || r;
    r = ((lib->m_glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)glGetProcAddress("glValidateProgram")) == NULL) || r;
    r = ((lib->m_glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)glGetProcAddress("glVertexAttrib1d")) == NULL) || r;
    r = ((lib->m_glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)glGetProcAddress("glVertexAttrib1dv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)glGetProcAddress("glVertexAttrib1f")) == NULL) || r;
    r = ((lib->m_glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)glGetProcAddress("glVertexAttrib1fv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)glGetProcAddress("glVertexAttrib1s")) == NULL) || r;
    r = ((lib->m_glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)glGetProcAddress("glVertexAttrib1sv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)glGetProcAddress("glVertexAttrib2d")) == NULL) || r;
    r = ((lib->m_glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)glGetProcAddress("glVertexAttrib2dv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)glGetProcAddress("glVertexAttrib2f")) == NULL) || r;
    r = ((lib->m_glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)glGetProcAddress("glVertexAttrib2fv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)glGetProcAddress("glVertexAttrib2s")) == NULL) || r;
    r = ((lib->m_glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)glGetProcAddress("glVertexAttrib2sv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)glGetProcAddress("glVertexAttrib3d")) == NULL) || r;
    r = ((lib->m_glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)glGetProcAddress("glVertexAttrib3dv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)glGetProcAddress("glVertexAttrib3f")) == NULL) || r;
    r = ((lib->m_glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)glGetProcAddress("glVertexAttrib3fv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)glGetProcAddress("glVertexAttrib3s")) == NULL) || r;
    r = ((lib->m_glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)glGetProcAddress("glVertexAttrib3sv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)glGetProcAddress("glVertexAttrib4Nbv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)glGetProcAddress("glVertexAttrib4Niv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)glGetProcAddress("glVertexAttrib4Nsv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)glGetProcAddress("glVertexAttrib4Nub")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)glGetProcAddress("glVertexAttrib4Nubv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)glGetProcAddress("glVertexAttrib4Nuiv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)glGetProcAddress("glVertexAttrib4Nusv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)glGetProcAddress("glVertexAttrib4bv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)glGetProcAddress("glVertexAttrib4d")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)glGetProcAddress("glVertexAttrib4dv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)glGetProcAddress("glVertexAttrib4f")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)glGetProcAddress("glVertexAttrib4fv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)glGetProcAddress("glVertexAttrib4iv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)glGetProcAddress("glVertexAttrib4s")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)glGetProcAddress("glVertexAttrib4sv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)glGetProcAddress("glVertexAttrib4ubv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)glGetProcAddress("glVertexAttrib4uiv")) == NULL) || r;
    r = ((lib->m_glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)glGetProcAddress("glVertexAttrib4usv")) == NULL) || r;
    r = ((lib->m_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)glGetProcAddress("glVertexAttribPointer")) == NULL) || r;
    return r;
}

static GLboolean GET_GL_FUNCTIONS_GL_vertex_array_object(FcGL_t* lib, void* glGetProcAddress(const char* const)){
    GLboolean r = GL_FALSE;
    r = ((lib->m_glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)glGetProcAddress("glBindVertexArray")) == NULL) || r;
    r = ((lib->m_glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)glGetProcAddress("glDeleteVertexArrays")) == NULL) || r;
    r = ((lib->m_glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)glGetProcAddress("glGenVertexArrays")) == NULL) || r;
    r = ((lib->m_glIsVertexArray = (PFNGLISVERTEXARRAYPROC)glGetProcAddress("glIsVertexArray")) == NULL) || r;
    return r;
}
static GLboolean GET_GL_FUNCTIONS_GL_vertex_attrib_binding(FcGL_t* lib, void* glGetProcAddress(const char* const)){

    GLboolean r = GL_FALSE;

        //void VertexArrayBindVertexBufferEXT(uint vaobj, uint bindingindex, uint buffer, intptr offset, sizei stride);
        //void VertexArrayVertexAttribFormatEXT(uint vaobj, uint attribindex, int size, enum type, boolean normalized, uint relativeoffset);
        //void VertexArrayVertexAttribIFormatEXT(uint vaobj, uint attribindex, int size, enum type, uint relativeoffset);
        //void VertexArrayVertexAttribLFormatEXT(uint vaobj, uint attribindex, int size, enum type, uint relativeoffset);
        //void VertexArrayVertexAttribBindingEXT(uint vaobj, uint attribindex, uint bindingindex);
        //void VertexArrayVertexBindingDivisorEXT(uint vaobj, uint bindingindex, uint divisor);

    r = ((lib->m_glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)glGetProcAddress("glBindVertexBuffer")) == NULL) || r;
    r = ((lib->m_glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)glGetProcAddress("glVertexAttribFormat")) == NULL) || r;
    r = ((lib->m_glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)glGetProcAddress("glVertexAttribIFormat")) == NULL) || r;
    r = ((lib->m_glVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC)glGetProcAddress("glVertexAttribLFormat")) == NULL) || r;
    r = ((lib->m_glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)glGetProcAddress("glVertexAttribBinding")) == NULL) || r;
    r = ((lib->m_glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)glGetProcAddress("glVertexBindingDivisor")) == NULL) || r;
    return r;
}
static GLboolean GET_GL_FUNCTIONS_GL_KHR_debug(FcGL_t* lib, void* glGetProcAddress(const char* const)) {
    GLboolean r = GL_FALSE;
    r = ((lib->m_glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)glGetProcAddress("glDebugMessageControl")) == NULL) || r;
    r = ((lib->m_glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)glGetProcAddress("glDebugMessageInsert")) == NULL) || r;
    r = ((lib->m_glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)glGetProcAddress("glDebugMessageCallback")) == NULL) || r;
    r = ((lib->m_glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)glGetProcAddress("glGetDebugMessageLog")) == NULL) || r;
    //r = ((lib->m_glGetPointerv = (PFNGLGETPOINTERVPROC)glGetProcAddress("glGetPointerv")) == NULL) || r;
    r = ((lib->m_glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)glGetProcAddress("glPushDebugGroup")) == NULL) || r;
    r = ((lib->m_glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)glGetProcAddress("glPopDebugGroup")) == NULL) || r;
    r = ((lib->m_glObjectLabel = (PFNGLOBJECTLABELPROC)glGetProcAddress("glObjectLabel")) == NULL) || r;
    r = ((lib->m_glGetObjectLabel = (PFNGLGETOBJECTLABELPROC)glGetProcAddress("glGetObjectLabel")) == NULL) || r;
    r = ((lib->m_glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)glGetProcAddress("glObjectPtrLabel")) == NULL) || r;
    r = ((lib->m_glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)glGetProcAddress("glGetObjectPtrLabel")) ==
        NULL) || r;
    return r;
}

static GLboolean GET_GL_FUNCTIONS_GL_ARB_uniform_buffer_object(FcGL_t* lib, void* glGetProcAddress(const char* const)) {
    GLboolean r = GL_FALSE;
    r = ((lib->m_glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)glGetProcAddress("glGetUniformIndices")) == NULL) || r;
    r = ((lib->m_glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)glGetProcAddress("glGetActiveUniformsiv")) == NULL) || r;
    r = ((lib->m_glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)glGetProcAddress("glGetActiveUniformName")) == NULL) || r;
    r = ((lib->m_glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)glGetProcAddress("glGetUniformBlockIndex")) == NULL) || r;
    r = ((lib->m_glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)glGetProcAddress("glGetActiveUniformBlockiv")) == NULL) || r;
    r = ((lib->m_glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)glGetProcAddress("glGetActiveUniformBlockName")) == NULL) || r;
    r = ((lib->m_glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)glGetProcAddress("glBindBufferRange")) == NULL) || r;
    r = ((lib->m_glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)glGetProcAddress("glBindBufferBase")) == NULL) || r;
    r = ((lib->m_glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)glGetProcAddress("glGetIntegeri_v")) == NULL) || r;
    r = ((lib->m_glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)glGetProcAddress("glUniformBlockBinding")) ==
        NULL) || r;
    return r;
}

extern void APIENTRY
glCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message,
    const void* userParam);

static inline FcError_t FcGL_setDebugCallback(FcGL_t* lib){
    GLint flags;
    FcError_t mError = FC_GL_KHR_debug;
    lib->m_glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
    if (flags & GL_CONTEXT_FLAG_DEBUG_BIT) {
        lib->m_glEnable(GL_DEBUG_OUTPUT);
        lib->m_glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        lib->m_glDebugMessageCallback(glCallback, NULL);
        lib->m_glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);
        mError = FC_NO_ERROR;
    }
    return mError;
}
static FcError_t FcGL(FcGL_t* lib, void* glGetProcAddress(const char* const)) {
    FcError_t mError = FC_NO_ERROR;
    GLint flags;
    lib->mLib = FcLib_load("libOpenGL.so");
    if (!lib->mLib) {
        mError = FC_GL_LoadLibrary; 
        goto gError;
    }
    GET_GL_FUNCTIONS_GL_VERSION_1_0(lib);
    if (!find_GL_version(lib, 1, 1)) {
        mError = FC_GL_VERSION_1_1; 
        goto gError;
    }
    GET_GL_FUNCTIONS_GL_VERSION_1_1(lib);
    if (!find_GL_version(lib, 1, 2))  {
        mError = FC_GL_VERSION_1_2; 
        goto gError;
    }
    GET_GL_FUNCTIONS_GL_VERSION_1_2(lib, glGetProcAddress);
    if (!find_GL_version(lib, 1, 3))  {
        mError = FC_GL_VERSION_1_3; 
        goto gError;
    }
    GET_GL_FUNCTIONS_GL_VERSION_1_3(lib, glGetProcAddress);
    if (!find_GL_version(lib, 1, 4))  {
        mError = FC_GL_VERSION_1_4; 
        goto gError;
    }
    GET_GL_FUNCTIONS_GL_VERSION_1_4(lib, glGetProcAddress);
    if (!find_GL_version(lib, 1, 5))  {
        mError = FC_GL_VERSION_1_5; 
        goto gError;
    }
    GET_GL_FUNCTIONS_GL_VERSION_1_5(lib, glGetProcAddress);
    if (!find_GL_version(lib, 2, 0))  {
        mError = FC_GL_VERSION_2_0; 
        goto gError;
    }
    GET_GL_FUNCTIONS_GL_VERSION_2_0(lib, glGetProcAddress);

    if (!find_GL_extensions(lib, "GL_ARB_vertex_array_object"))  {
        mError = FC_GL_ARB_vertex_array_object; 
        goto gError;
    }
    GET_GL_FUNCTIONS_GL_vertex_array_object(lib, glGetProcAddress);
    if (!find_GL_extensions(lib, "GL_ARB_vertex_attrib_binding")) {
        mError = FC_GL_ARB_vertex_attrib_binding; 
        goto gError;
    }
    GET_GL_FUNCTIONS_GL_vertex_attrib_binding(lib, glGetProcAddress);
    if (!find_GL_extensions(lib, "GL_ARB_uniform_buffer_object")) {
        mError = FC_GL_ARB_uniform_buffer_object; 
        goto gError;
    }
    GET_GL_FUNCTIONS_GL_ARB_uniform_buffer_object(lib, glGetProcAddress);
    if (!find_GL_extensions(lib, "GL_KHR_debug")) {
        mError = FC_GL_KHR_debug; 
        goto gError;
    }
    GET_GL_FUNCTIONS_GL_KHR_debug(lib, glGetProcAddress);
gError:
    return mError;
}
static inline FcError_t FcGL_free(FcGL_t* lib) {
    FcLib_free(lib->mLib);
    *lib = (FcGL_t){0};
    return FC_NO_ERROR;
}

#endif