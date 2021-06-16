
#include <X11/Xlib.h>
#include <errno.h>
#ifdef linux
#ifndef __FCGLX_H_
#define __FCGLX_H_
//#ifndef GL_GLEXT_PROTOTYPES
//#define GL_GLEXT_PROTOTYPES
//#endif

#include "FcError.h"

#include <GL/glx.h>
//#include <GL/glxtokens.h>
#include <FcCoreLoader.h>
#include <FcGLStatic.h>

#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

/* GLX 1.0 and later */
typedef XVisualInfo *(*PFNGLXCHOOSEVISUALPROC)(Display *dpy, int screen,
                                               int *attribList);
typedef GLXContext (*PFNGLXCREATECONTEXTPROC)(Display *dpy, XVisualInfo *vis,
                                              GLXContext shareList,
                                              Bool direct);
typedef void (*PFNGLXDESTROYCONTEXTPROC)(Display *dpy, GLXContext ctx);
typedef Bool (*PFNGLXMAKECURRENTPROC)(Display *dpy, GLXDrawable drawable,
                                      GLXContext ctx);
typedef void (*PFNGLXCOPYCONTEXTPROC)(Display *dpy, GLXContext src,
                                      GLXContext dst, unsigned long mask);
typedef void (*PFNGLXSWAPBUFFERSPROC)(Display *dpy, GLXDrawable drawable);
typedef GLXPixmap (*PFNGLXCREATEGLXPIXMAPPROC)(Display *dpy,
                                               XVisualInfo *visual,
                                               Pixmap pixmap);
typedef void (*PFNGLXDETROYGLXPIXMAPPROC)(Display *dpy, GLXPixmap pixmap);
typedef Bool (*PFNGLXQUERYEXTENSIONPROC)(Display *dpy, int *errorb, int *event);
typedef Bool (*PFNGLXQUERYVERSIONPROC)(Display *dpy, int *maj, int *min);
typedef Bool (*PFNGLXISDIRECTPROC)(Display *dpy, GLXContext ctx);
typedef int (*PFNGLXGETCONFIGPROC)(Display *dpy, XVisualInfo *visual,
                                   int attrib, int *value);
typedef GLXContext (*PFNGLXGETCURRENTCONTEXTPROC)(void);
typedef GLXDrawable (*PFNGLXGETCURRENTDRAWABLEPROC)(void);
typedef void (*PFNGLXWAITGLPROC)(void);
typedef void (*PFNGLXWAITXPROC)(void);
typedef void (*PFNGLXUSEXFONTPROC)(Font font, int first, int count, int list);
typedef const char *(*PFNGLXQUERYEXTENSIONSSTRINGPROC)(Display *dpy,
                                                       int screen);
typedef const char *(*PFNGLXQUERYSERVERSTRINGPROC)(Display *dpy, int screen,
                                                   int name);
typedef const char *(*PFNGLXGETCLIENTSTRINGPROC)(Display *dpy, int name);
typedef Display *(*PFNGLXGETCURRENTDISPLAYPROC)(void);
typedef GLXFBConfig *(*PFNGLXGETFBCONFIGSPROC)(Display *dpy, int screen,
                                               int *nelements);
typedef GLXFBConfig *(*PFNGLXCHOOSEFBCONFIGPROC)(Display *dpy, int screen,
                                                 const int *attrib_list,
                                                 int *nelements);
typedef int (*PFNGLXGETFBCONFIGATTRIBPROC)(Display *dpy, GLXFBConfig config,
                                           int attribute, int *value);
typedef XVisualInfo *(*PFNGLXGETVISUALFROMFBCONFIGPROC)(Display *dpy,
                                                        GLXFBConfig config);
typedef GLXWindow (*PFNGLXCREATEWINDOWPROC)(Display *dpy, GLXFBConfig config,
                                            Window win, const int *attrib_list);
typedef void (*PFNGLXDESTROYWINDOWPROC)(Display *dpy, GLXWindow win);
typedef GLXPixmap (*PFNGLXCREATEPIXMAPPROC)(Display *dpy, GLXFBConfig config,
                                            Pixmap pixmap,
                                            const int *attrib_list);
typedef void (*PFNGLXDESTROYPIXMAPPROC)(Display *dpy, GLXPixmap pixmap);
typedef GLXPbuffer (*PFNGLXCREATEPBUFFERPROC)(Display *dpy, GLXFBConfig config,
                                              const int *attrib_list);
typedef void (*PFNGLXDESTROYPBUFFERPROC)(Display *dpy, GLXPbuffer pbuf);
typedef void (*PFNGLXQUERYDRAWABLEPROC)(Display *dpy, GLXDrawable draw,
                                        int attribute, unsigned int *value);
typedef GLXContext (*PFNGLXCREATENEWCONTEXTPROC)(Display *dpy,
                                                 GLXFBConfig config,
                                                 int render_type,
                                                 GLXContext share_list,
                                                 Bool direct);
typedef Bool (*PFNGLXMAKECONTEXTCURRENTPROC)(Display *dpy, GLXDrawable draw,
                                             GLXDrawable read, GLXContext ctx);
typedef GLXDrawable (*PFNGLXGETCURRENTREADDRAWABLEPROC)(void);
typedef Display *(*PFNGLXGETCURRENTDISPLAYPROC)(void);
typedef int (*PFNGLXQUERYCONTEXTPROC)(Display *dpy, GLXContext ctx,
                                      int attribute, int *value);
typedef void (*PFNGLXSELECTEVENTPROC)(Display *dpy, GLXDrawable draw,
                                      unsigned long event_mask);
typedef void (*PFNGLXGETSELECTEDEVENTPROC)(Display *dpy, GLXDrawable draw,
                                           unsigned long *event_mask);

typedef struct FcGLXContext_t {
  GLXContext context;
  GLXWindow window;
} FcGLXContext_t;

typedef struct FcGLXPBufferContext_t {
  GLXContext context;
  GLXPbuffer pbuffer;
} FcGLXPBufferContext_t;

typedef struct FcGLX_t {
  FcLib_t mLib;
  // 1.0
  PFNGLXCHOOSEVISUALPROC glXChooseVisual;
  PFNGLXCREATECONTEXTPROC glXCreateContext;
  PFNGLXDESTROYCONTEXTPROC glXDestroyContext;
  PFNGLXMAKECURRENTPROC glXMakeCurrent;
  PFNGLXCOPYCONTEXTPROC glXCopyContext;
  PFNGLXSWAPBUFFERSPROC glXSwapBuffers;
  PFNGLXCREATEGLXPIXMAPPROC glXCreateGLXPixmap;
  PFNGLXDETROYGLXPIXMAPPROC glXDestroyGLXPixmap;
  PFNGLXQUERYEXTENSIONPROC glXQueryExtension;
  PFNGLXQUERYVERSIONPROC glXQueryVersion;
  PFNGLXISDIRECTPROC glXIsDirect;
  PFNGLXGETCONFIGPROC glXGetConfig;
  PFNGLXGETCURRENTCONTEXTPROC glXGetCurrentContext;
  PFNGLXGETCURRENTDRAWABLEPROC glXGetCurrentDrawable;
  PFNGLXWAITGLPROC glXWaitGL;
  PFNGLXWAITXPROC glXWaitX;
  PFNGLXUSEXFONTPROC glXUseXFont;
  // 1.1
  PFNGLXQUERYEXTENSIONSSTRINGPROC glXQueryExtensionsString;
  PFNGLXQUERYSERVERSTRINGPROC glXQueryServerString;
  PFNGLXGETCLIENTSTRINGPROC glXGetClientString;
  // 1.2
  PFNGLXGETCURRENTDISPLAYPROC glXGetCurrentDisplay;
  // 1.3
  PFNGLXCHOOSEFBCONFIGPROC glXChooseFBConfig;
  PFNGLXGETFBCONFIGATTRIBPROC glXGetFBConfigAttrib;
  PFNGLXGETFBCONFIGSPROC glXGetFBConfigs;
  PFNGLXGETVISUALFROMFBCONFIGPROC glXGetVisualFromFBConfig;
  PFNGLXCREATEWINDOWPROC glXCreateWindow;
  PFNGLXDESTROYWINDOWPROC glXDestroyWindow;
  PFNGLXCREATEPIXMAPPROC glXCreatePixmap;
  PFNGLXDESTROYPIXMAPPROC glXDestroyPixmap;
  PFNGLXCREATEPBUFFERPROC glXCreatePbuffer;
  PFNGLXDESTROYPBUFFERPROC glXDestroyPbuffer;
  PFNGLXQUERYDRAWABLEPROC glXQueryDrawable;
  PFNGLXCREATENEWCONTEXTPROC glXCreateNewContext;
  PFNGLXMAKECONTEXTCURRENTPROC glXMakeContextCurrent;
  PFNGLXGETCURRENTREADDRAWABLEPROC glXGetCurrentReadDrawable;
  PFNGLXQUERYCONTEXTPROC glXQueryContext;
  PFNGLXSELECTEVENTPROC glXSelectEvent;
  PFNGLXGETSELECTEDEVENTPROC glXGetSelectedEvent;
  // 1.4
  PFNGLXGETPROCADDRESSPROC glXGetProcAddress;
  // ARB
  PFNGLXCREATECONTEXTATTRIBSARBPROC glXCreateContextAttribsARB;
  PFNGLXSWAPINTERVALEXTPROC glXSwapIntervalEXT;
} FcGLX_t;

static inline FcError_t FcGLX(FcGLX_t *glx);

static inline FcError_t FcGLX_chooseVisualFramebuffer(const FcGLX_t *glx,
                                                      Display *display,
                                                      int screenId,
                                                      XVisualInfo **visual,
                                                      GLXFBConfig *FBConfig);
static inline FcError_t FcGLX_chooseVisual(const FcGLX_t *glx, Display *display,
                                           int screenId, XVisualInfo **visual);

static inline FcError_t
FcGLX_initDebugContext(FcGLX_t *glx, FcGLXContext_t *context, Display *display,
                       GLXFBConfig *FBConfig, Window window);

static inline FcError_t FcGLX_initContext(FcGLX_t *glx, FcGLXContext_t *context,
                                          Display *display, XVisualInfo *visual,
                                          Window window);

static inline FcError_t FcGLX_freeContext(FcGLX_t *glx, FcGLXContext_t *context,
                                          Display *display);

static inline FcError_t FcGLX_free(FcGLX_t *glx);

extern int FcErrors(Display *display, XErrorEvent *event);

static inline FcError_t FcGLX_PBufferContext(const FcGLX_t *glx,
                                             FcGLXPBufferContext_t *context,
                                             Display *display, int screenId,
                                             int width, int height) {

  int mNumberConfigs;
  FcError_t mError = FC_NO_ERROR;
  int fbAttrib[] = {GLX_RENDER_TYPE,
                    GLX_RGBA_BIT,
                    GLX_RED_SIZE,
                    1,
                    GLX_GREEN_SIZE,
                    1,
                    GLX_BLUE_SIZE,
                    1,
                    GLX_DOUBLEBUFFER,
                    False,
                    None};

  int (*oldHandler)(Display *, XErrorEvent *) = XSetErrorHandler(&FcErrors);

  GLXFBConfig *configs =
      glx->glXChooseFBConfig(display, screenId, fbAttrib, &mNumberConfigs);
  context->context = 0;
  context->pbuffer = 0;

  if (configs && mNumberConfigs) {
    int pb_attribs[] = {GLX_PBUFFER_WIDTH, width, GLX_PBUFFER_HEIGHT, height,
                        None};
    context->pbuffer = glx->glXCreatePbuffer(display, configs[0], pb_attribs);
    if (!context->pbuffer) {
      mError = FC_GLX_BadPbuffer;
      goto gError;
    }
    context->context =
        glx->glXCreateNewContext(display, configs[0], GLX_RGBA_TYPE, 0, True);
    if (!context->context) {
      mError = FC_GLX_BadContext;
      goto gError;
    }
    XSync(display, False);
    if (!glx->glXIsDirect(display, context->context)) {
      mError = FC_GLX_ContextNotDirect;
      goto gError;
    }
    if (!glx->glXMakeContextCurrent(display, context->pbuffer, context->pbuffer,
                                    context->context)) {
      mError = FC_GLX_MakeCurrent;
      goto gError;
    }
  }
gError:
  if (mError) {
    if (context->context)
      glx->glXDestroyContext(display, context->context);
    if (context->pbuffer)
      glx->glXDestroyPbuffer(display, context->pbuffer);
  }
  XSync(display, False);
  XSetErrorHandler(oldHandler);
  if (configs)
    XFree(configs);
  return mError;
}

static inline FcError_t FcGLX_PBufferFreeContext(FcGLX_t *glx,
                                                 FcGLXPBufferContext_t *context,
                                                 Display *display) {
  if (context->context)
    glx->glXDestroyContext(display, context->context);
  if (context->pbuffer)
    glx->glXDestroyPbuffer(display, context->pbuffer);
  return FC_NO_ERROR;
}

static inline FcError_t FcGLX(FcGLX_t *glx) {
  unsigned i;
  const char *m_libs[] = {"libGL.so.1", "libGL.so.1.0.0", "libGL.so",
                          "libGL-1.so"};
  *glx = (FcGLX_t){0};
  for (i = 0; i < 4 && glx->mLib == NULL; i++)
    glx->mLib = FcLib_load(m_libs[i]);
  if (glx->mLib == NULL)
    return FC_GLX_LoadLibrary;

  glx->glXChooseVisual =
      (PFNGLXCHOOSEVISUALPROC)FcLib_loadFunction(glx->mLib, "glXChooseVisual");
  glx->glXCreateContext = (PFNGLXCREATECONTEXTPROC)FcLib_loadFunction(
      glx->mLib, "glXCreateContext");
  glx->glXDestroyContext = (PFNGLXDESTROYCONTEXTPROC)FcLib_loadFunction(
      glx->mLib, "glXDestroyContext");
  glx->glXMakeCurrent =
      (PFNGLXMAKECURRENTPROC)FcLib_loadFunction(glx->mLib, "glXMakeCurrent");
  glx->glXCopyContext =
      (PFNGLXCOPYCONTEXTPROC)FcLib_loadFunction(glx->mLib, "glXCopyContext");
  glx->glXSwapBuffers =
      (PFNGLXSWAPBUFFERSPROC)FcLib_loadFunction(glx->mLib, "glXSwapBuffers");
  glx->glXCreateGLXPixmap = (PFNGLXCREATEGLXPIXMAPPROC)FcLib_loadFunction(
      glx->mLib, "glXCreateGLXPixmap");
  glx->glXDestroyGLXPixmap = (PFNGLXDETROYGLXPIXMAPPROC)FcLib_loadFunction(
      glx->mLib, "glXDestroyGLXPixmap");
  glx->glXQueryExtension = (PFNGLXQUERYEXTENSIONPROC)FcLib_loadFunction(
      glx->mLib, "glXQueryExtension");
  glx->glXQueryVersion =
      (PFNGLXQUERYVERSIONPROC)FcLib_loadFunction(glx->mLib, "glXQueryVersion");
  glx->glXIsDirect =
      (PFNGLXISDIRECTPROC)FcLib_loadFunction(glx->mLib, "glXIsDirect");
  glx->glXGetConfig =
      (PFNGLXGETCONFIGPROC)FcLib_loadFunction(glx->mLib, "glXGetConfig");
  glx->glXGetCurrentContext = (PFNGLXGETCURRENTCONTEXTPROC)FcLib_loadFunction(
      glx->mLib, "glXGetCurrentContext");
  glx->glXGetCurrentDrawable = (PFNGLXGETCURRENTDRAWABLEPROC)FcLib_loadFunction(
      glx->mLib, "glXGetCurrentDrawable");
  glx->glXWaitGL = (PFNGLXWAITGLPROC)FcLib_loadFunction(glx->mLib, "glXWaitGL");
  glx->glXWaitX = (PFNGLXWAITXPROC)FcLib_loadFunction(glx->mLib, "glXWaitX");
  glx->glXUseXFont =
      (PFNGLXUSEXFONTPROC)FcLib_loadFunction(glx->mLib, "glXUseXFont");

  glx->glXQueryExtensionsString =
      (PFNGLXQUERYEXTENSIONSSTRINGPROC)FcLib_loadFunction(
          glx->mLib, "glXQueryExtensionsString");
  glx->glXQueryServerString = (PFNGLXQUERYSERVERSTRINGPROC)FcLib_loadFunction(
      glx->mLib, "glXQueryServerString");
  glx->glXGetClientString = (PFNGLXGETCLIENTSTRINGPROC)FcLib_loadFunction(
      glx->mLib, "glXGetClientString");

  glx->glXGetCurrentDisplay = (PFNGLXGETCURRENTDISPLAYPROC)FcLib_loadFunction(
      glx->mLib, "glXGetCurrentDisplay");

  glx->glXChooseFBConfig = (PFNGLXCHOOSEFBCONFIGPROC)FcLib_loadFunction(
      glx->mLib, "glXChooseFBConfig");
  glx->glXGetFBConfigAttrib = (PFNGLXGETFBCONFIGATTRIBPROC)FcLib_loadFunction(
      glx->mLib, "glXGetFBConfigAttrib");
  glx->glXGetFBConfigs =
      (PFNGLXGETFBCONFIGSPROC)FcLib_loadFunction(glx->mLib, "glXGetFBConfigs");
  glx->glXGetVisualFromFBConfig =
      (PFNGLXGETVISUALFROMFBCONFIGPROC)FcLib_loadFunction(
          glx->mLib, "glXGetVisualFromFBConfig");
  glx->glXCreateWindow =
      (PFNGLXCREATEWINDOWPROC)FcLib_loadFunction(glx->mLib, "glXCreateWindow");
  glx->glXDestroyWindow = (PFNGLXDESTROYWINDOWPROC)FcLib_loadFunction(
      glx->mLib, "glXDestroyWindow");
  glx->glXCreatePixmap =
      (PFNGLXCREATEPIXMAPPROC)FcLib_loadFunction(glx->mLib, "glXCreatePixmap");
  glx->glXDestroyPixmap = (PFNGLXDESTROYPIXMAPPROC)FcLib_loadFunction(
      glx->mLib, "glXDestroyPixmap");
  glx->glXCreatePbuffer = (PFNGLXCREATEPBUFFERPROC)FcLib_loadFunction(
      glx->mLib, "glXCreatePbuffer");
  glx->glXDestroyPbuffer = (PFNGLXDESTROYPBUFFERPROC)FcLib_loadFunction(
      glx->mLib, "glXDestroyPbuffer");
  glx->glXQueryDrawable = (PFNGLXQUERYDRAWABLEPROC)FcLib_loadFunction(
      glx->mLib, "glXQueryDrawable");
  glx->glXCreateNewContext = (PFNGLXCREATENEWCONTEXTPROC)FcLib_loadFunction(
      glx->mLib, "glXCreateNewContext");
  glx->glXMakeContextCurrent = (PFNGLXMAKECONTEXTCURRENTPROC)FcLib_loadFunction(
      glx->mLib, "glXMakeContextCurrent");
  glx->glXGetCurrentReadDrawable =
      (PFNGLXGETCURRENTREADDRAWABLEPROC)FcLib_loadFunction(
          glx->mLib, "glXGetCurrentReadDrawable");
  glx->glXQueryContext =
      (PFNGLXQUERYCONTEXTPROC)FcLib_loadFunction(glx->mLib, "glXQueryContext");
  glx->glXSelectEvent =
      (PFNGLXSELECTEVENTPROC)FcLib_loadFunction(glx->mLib, "glXSelectEvent");
  glx->glXGetSelectedEvent = (PFNGLXGETSELECTEDEVENTPROC)FcLib_loadFunction(
      glx->mLib, "glXGetSelectedEvent");

  glx->glXGetProcAddress = (PFNGLXGETPROCADDRESSPROC)FcLib_loadFunction(
      glx->mLib, "glXGetProcAddress");

  glx->glXChooseVisual =
      (PFNGLXCHOOSEVISUALPROC)FcLib_loadFunction(glx->mLib, "glXChooseVisual");
  glx->glXCreateContext = (PFNGLXCREATECONTEXTPROC)FcLib_loadFunction(
      glx->mLib, "glXCreateContext");
  glx->glXDestroyContext = (PFNGLXDESTROYCONTEXTPROC)FcLib_loadFunction(
      glx->mLib, "glXDestroyContext");
  glx->glXMakeCurrent =
      (PFNGLXMAKECURRENTPROC)FcLib_loadFunction(glx->mLib, "glXMakeCurrent");
  glx->glXCopyContext =
      (PFNGLXCOPYCONTEXTPROC)FcLib_loadFunction(glx->mLib, "glXCopyContext");
  glx->glXSwapBuffers =
      (PFNGLXSWAPBUFFERSPROC)FcLib_loadFunction(glx->mLib, "glXSwapBuffers");
  glx->glXCreateGLXPixmap = (PFNGLXCREATEGLXPIXMAPPROC)FcLib_loadFunction(
      glx->mLib, "glXCreateGLXPixmap");
  glx->glXDestroyGLXPixmap = (PFNGLXDETROYGLXPIXMAPPROC)FcLib_loadFunction(
      glx->mLib, "glXDestroyGLXPixmap");
  glx->glXQueryExtension = (PFNGLXQUERYEXTENSIONPROC)FcLib_loadFunction(
      glx->mLib, "glXQueryExtension");
  glx->glXQueryVersion =
      (PFNGLXQUERYVERSIONPROC)FcLib_loadFunction(glx->mLib, "glXQueryVersion");
  glx->glXIsDirect =
      (PFNGLXISDIRECTPROC)FcLib_loadFunction(glx->mLib, "glXIsDirect");
  glx->glXGetConfig =
      (PFNGLXGETCONFIGPROC)FcLib_loadFunction(glx->mLib, "glXGetConfig");
  glx->glXGetCurrentContext = (PFNGLXGETCURRENTCONTEXTPROC)FcLib_loadFunction(
      glx->mLib, "glXGetCurrentContext");
  glx->glXGetCurrentDrawable = (PFNGLXGETCURRENTDRAWABLEPROC)FcLib_loadFunction(
      glx->mLib, "glXGetCurrentDrawable");
  glx->glXWaitGL = (PFNGLXWAITGLPROC)FcLib_loadFunction(glx->mLib, "glXWaitGL");
  glx->glXWaitX = (PFNGLXWAITXPROC)FcLib_loadFunction(glx->mLib, "glXWaitX");
  glx->glXUseXFont =
      (PFNGLXUSEXFONTPROC)FcLib_loadFunction(glx->mLib, "glXUseXFont");

  glx->glXQueryExtensionsString =
      (PFNGLXQUERYEXTENSIONSSTRINGPROC)FcLib_loadFunction(
          glx->mLib, "glXQueryExtensionsString");
  glx->glXQueryServerString = (PFNGLXQUERYSERVERSTRINGPROC)FcLib_loadFunction(
      glx->mLib, "glXQueryServerString");
  glx->glXGetClientString = (PFNGLXGETCLIENTSTRINGPROC)FcLib_loadFunction(
      glx->mLib, "glXGetClientString");

  glx->glXGetCurrentDisplay = (PFNGLXGETCURRENTDISPLAYPROC)FcLib_loadFunction(
      glx->mLib, "glXGetCurrentDisplay");

  glx->glXChooseFBConfig = (PFNGLXCHOOSEFBCONFIGPROC)FcLib_loadFunction(
      glx->mLib, "glXChooseFBConfig");
  glx->glXGetFBConfigAttrib = (PFNGLXGETFBCONFIGATTRIBPROC)FcLib_loadFunction(
      glx->mLib, "glXGetFBConfigAttrib");
  glx->glXGetFBConfigs =
      (PFNGLXGETFBCONFIGSPROC)FcLib_loadFunction(glx->mLib, "glXGetFBConfigs");
  glx->glXGetVisualFromFBConfig =
      (PFNGLXGETVISUALFROMFBCONFIGPROC)FcLib_loadFunction(
          glx->mLib, "glXGetVisualFromFBConfig");
  glx->glXCreateWindow =
      (PFNGLXCREATEWINDOWPROC)FcLib_loadFunction(glx->mLib, "glXCreateWindow");
  glx->glXDestroyWindow = (PFNGLXDESTROYWINDOWPROC)FcLib_loadFunction(
      glx->mLib, "glXDestroyWindow");
  glx->glXCreatePixmap =
      (PFNGLXCREATEPIXMAPPROC)FcLib_loadFunction(glx->mLib, "glXCreatePixmap");
  glx->glXDestroyPixmap = (PFNGLXDESTROYPIXMAPPROC)FcLib_loadFunction(
      glx->mLib, "glXDestroyPixmap");
  glx->glXCreatePbuffer = (PFNGLXCREATEPBUFFERPROC)FcLib_loadFunction(
      glx->mLib, "glXCreatePbuffer");
  glx->glXDestroyPbuffer = (PFNGLXDESTROYPBUFFERPROC)FcLib_loadFunction(
      glx->mLib, "glXDestroyPbuffer");
  glx->glXQueryDrawable = (PFNGLXQUERYDRAWABLEPROC)FcLib_loadFunction(
      glx->mLib, "glXQueryDrawable");
  glx->glXCreateNewContext = (PFNGLXCREATENEWCONTEXTPROC)FcLib_loadFunction(
      glx->mLib, "glXCreateNewContext");
  glx->glXMakeContextCurrent = (PFNGLXMAKECONTEXTCURRENTPROC)FcLib_loadFunction(
      glx->mLib, "glXMakeContextCurrent");
  glx->glXGetCurrentReadDrawable =
      (PFNGLXGETCURRENTREADDRAWABLEPROC)FcLib_loadFunction(
          glx->mLib, "glXGetCurrentReadDrawable");
  glx->glXQueryContext =
      (PFNGLXQUERYCONTEXTPROC)FcLib_loadFunction(glx->mLib, "glXQueryContext");

  if (glx->glXGetProcAddress == NULL)
    return FC_GLX_Version14IsRequired;

  // GLX_ARB_create_context_profile

  glx->glXCreateContextAttribsARB =
      (PFNGLXCREATECONTEXTATTRIBSARBPROC)glx->glXGetProcAddress(
          (const GLubyte *)"glXCreateContextAttribsARB");

  return FC_NO_ERROR;
}

static inline FcError_t FcGLX_free(FcGLX_t *glx) {
  FcError_t mError = FC_NO_ERROR;
  FcLib_free(glx->mLib);
  *glx = (FcGLX_t){0};
  // memset(glx, 0, sizeof(FcGLX_t));
  return mError;
}

static inline FcError_t FcGLX_chooseVisualFramebuffer(const FcGLX_t *glx,
                                                      Display *display,
                                                      int screenId,
                                                      XVisualInfo **visual,
                                                      GLXFBConfig *FBConfig) {
  GLXFBConfig *mFBConfigs;
  GLXFBConfig *mFBSelectConfig;
  FcError_t mError;
  int mCount, i, j;
  int mFBConfig[][2] = {{GLX_FBCONFIG_ID,       GLX_DONT_CARE},
                        {GLX_BUFFER_SIZE,       0},
                        {GLX_LEVEL,             0},
                        {GLX_DOUBLEBUFFER,      GLX_DONT_CARE},
                        {GLX_STEREO,            False},
                        {GLX_AUX_BUFFERS,       0},
                        {GLX_RED_SIZE,          0},
                        {GLX_GREEN_SIZE,        0},
                        {GLX_BLUE_SIZE,         0},
                        {GLX_ALPHA_SIZE,        0},
                        {GLX_DEPTH_SIZE,        0},
                        {GLX_STENCIL_SIZE,      0},
                        {GLX_ACCUM_RED_SIZE,    0},
                        {GLX_ACCUM_GREEN_SIZE,  0},
                        {GLX_ACCUM_BLUE_SIZE,   0},
                        {GLX_ACCUM_ALPHA_SIZE,  0},
                        {GLX_RENDER_TYPE,       GLX_DONT_CARE},
                        {GLX_DRAWABLE_TYPE,     GLX_DONT_CARE},
                        {GLX_X_RENDERABLE,      GLX_DONT_CARE},
                        {GLX_VISUAL_ID,         GLX_DONT_CARE},
                        {GLX_X_VISUAL_TYPE,     GLX_DONT_CARE},
                        {GLX_CONFIG_CAVEAT,     GLX_DONT_CARE},
                        {GLX_TRANSPARENT_TYPE,  GLX_NONE},
                        {GLX_TRANSPARENT_RED_VALUE,  GLX_DONT_CARE},
                        {GLX_TRANSPARENT_GREEN_VALUE,GLX_DONT_CARE},
                        {GLX_TRANSPARENT_BLUE_VALUE, GLX_DONT_CARE},
                        {GLX_TRANSPARENT_ALPHA_VALUE,GLX_DONT_CARE},
                        {GLX_MAX_PBUFFER_WIDTH,      GLX_DONT_CARE},
                        {GLX_MAX_PBUFFER_HEIGHT,     GLX_DONT_CARE},
                        {GLX_MAX_PBUFFER_PIXELS,     GLX_DONT_CARE},
                        {0,0}};
  mError = FC_NO_ERROR;
  mFBConfigs = NULL;

  mFBConfigs = glx->glXGetFBConfigs(display, screenId, &mCount);
  if (!mFBConfigs || !mCount) {
    mError = FC_GLX_FBConfigsNotFound;
    goto gError;
  }
  for (i = 0; i < mCount; i++) {
    GLXFBConfig n = mFBConfigs[i];
    for (j = 0; j < 32; j++)
      glx->glXGetFBConfigAttrib(display, n, mFBConfig[j][0],  mFBConfig[j] + 1);

    if (!(mFBConfig[16][1] & GLX_RGBA_BIT))
      continue;
    if (!(mFBConfig[17][1] & GLX_WINDOW_BIT))
      continue;
    if (!mFBConfig[3][1])
      continue;
    else
      i = mCount;
  }

  mFBSelectConfig = glx->glXChooseFBConfig(display, screenId, mFBConfig, &mCount);
  *FBConfig = *mFBSelectConfig;
  *visual = glx->glXGetVisualFromFBConfig(display, *mFBSelectConfig);

gError:
  if (mFBSelectConfig)
    XFree(mFBSelectConfig);
  if (mFBConfigs)
    XFree(mFBConfigs);
  return mError;
}

static inline FcError_t FcGLX_chooseVisual(const FcGLX_t *glx, Display *display,
                                           int screenId,
                                           XVisualInfo **xVisual) {
  FcError_t mError = FC_NO_ERROR;
  int attributes[] = {GLX_RGBA, GLX_RED_SIZE,   8,  GLX_GREEN_SIZE,
                      8,        GLX_BLUE_SIZE,  8,  GLX_DOUBLEBUFFER,
                      True,     GLX_DEPTH_SIZE, 24, None};
  *xVisual = glx->glXChooseVisual(display, screenId, attributes);
  if (!*xVisual)
    mError = FC_GLX_XVisualNotFound;
  return mError;
}

static inline FcError_t
FcGLX_initDebugContext(FcGLX_t *glx, FcGLXContext_t *context, Display *display,
                       GLXFBConfig *FBConfig, Window window) {
  int i, n;
  FcError_t m_error;

  int m_contextAttrib0[] = {GLX_CONTEXT_FLAGS_ARB, GLX_CONTEXT_DEBUG_BIT_ARB,
                            0, 0 };
  int m_contextAttrib1[] = {GLX_CONTEXT_MAJOR_VERSION_ARB,   3,
                            GLX_CONTEXT_MINOR_VERSION_ARB,   0,
                            GLX_CONTEXT_PROFILE_MASK_ARB,
                            GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
                            GLX_CONTEXT_FLAGS_ARB,
                            GLX_CONTEXT_DEBUG_BIT_ARB | GLX_CONTEXT_ROBUST_ACCESS_BIT_ARB,
                            0,
                            0};

  m_error = FC_NO_ERROR;
  if (glx->glXCreateContextAttribsARB == NULL) {
    m_error = FC_GLX_ARBCreateContextProfile;
    goto g_error;
  }

  for (i = 6; i >= 0 && context->context == NULL; --i) {
    m_contextAttrib1[1] = 4;
    m_contextAttrib1[3] = i;
    context->context = glx->glXCreateContextAttribsARB(display, *FBConfig, NULL, True, m_contextAttrib1);
  }
  for (i = 3; i >= 0 && context->context == NULL; --i) {
    m_contextAttrib1[1] = 3;
    m_contextAttrib1[3] = i;
    context->context = glx->glXCreateContextAttribsARB(display, *FBConfig, NULL, True, m_contextAttrib1);
  }
  if (context->context == NULL)
    context->context = glx->glXCreateContextAttribsARB(display, *FBConfig, NULL, True, m_contextAttrib0);
  if (context->context == NULL) {
    m_error = FC_GLX_ContextNotDebug;
    goto g_error;
  }
  XSync(display, False);
  if (!glx->glXIsDirect(display, context->context)) {
    m_error = FC_GLX_ContextNotDirect;
    goto g_error;
  }
  if (glx->glXMakeCurrent(display, window, context->context) == False) {
    m_error = FC_GLX_MakeCurrent;
    goto g_error;
  }

  return m_error;
g_error:
  if (context->context)
    FcGLX_freeContext(glx, context, display);
  return m_error;
}

static inline FcError_t FcGLX_initContext(FcGLX_t *glx, FcGLXContext_t *context,
                                          Display *display, XVisualInfo *visual,
                                          Window window) {
  FcError_t m_error = FC_NO_ERROR;
  context->context = glx->glXCreateContext(display, visual, NULL, True);
  XSync(display, False);
  if (glx->glXIsDirect(display, context->context) == False) {
    m_error = FC_GLX_ContextNotDirect;
    goto g_error;
  }
  if (glx->glXMakeCurrent(display, window, context->context) == False) {
    m_error = FC_GLX_MakeCurrent;
    goto g_error;
  }
  return m_error;
g_error:
  if (context->context)
    FcGLX_freeContext(glx, context, display);
  return m_error;
}

static inline FcError_t FcGLX_freeContext(FcGLX_t *glx, FcGLXContext_t *context,
                                          Display *display) {
  if (context->context)
    glx->glXDestroyContext(display, context->context);
  if (context->window)
    glx->glXDestroyWindow(display, context->window);
  return FC_NO_ERROR;
}

#endif //_FCGLX_H

#endif