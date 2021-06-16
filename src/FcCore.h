#ifndef _FCCORE_H_
#define _FCCORE_H_

#ifdef __FCGLX_H_
typedef FcGLX_t FcGLFunctions_t;
#define FcCoreGL FcGLX
#define FcCoreGL_free FcGLX_free
#elif defined __FCWGL_H__
typedef FcWGL_t FcGLFunctions_t;
#define FcCoreGL FcWGL
#define FcCoreGL_free FcWGL_free
#endif

#define FC_BUTTON_BASIC (1 << 0)

#define INIT_X11_THREAD  (1 << 0)
#define INIT_X11_DISPLAY (1 << 1)

#include "FcGL.h"
#include "FcGL_UI.h"
#include "FcWindow.h"

typedef struct FcCore_t {
    Display* m_display;
    FcGL_t m_gl;
    FcGLX_t m_glx;
} FcCore_t;

#include "FcGLStatic.h"

static inline FcError_t FcCore_init() {
    FcError_t mError;
    FcGLXPBufferContext_t mPBufferContext;

    XInitThreads();
    FcDisplay = XOpenDisplay(NULL);
    XFlush(FcDisplay);

    mError = FcGLX(&s_fcGLX);
    if (mError)
        goto gError;
    mError = FcGLX_PBufferContext(&s_fcGLX, &mPBufferContext, FcDisplay, DefaultScreen(FcDisplay), 0, 0);
    if (mError)
        goto gError;
    mError = FcGL(&s_fcGL, (void *(*)(const char *const)) s_fcGLX.glXGetProcAddress);
    if (mError)
        goto gError;
    const GLubyte* name = glGetString(GL_VENDOR);
    const GLubyte* rend = glGetString(GL_RENDERER);
    const GLubyte* vers = glGetString(GL_VERSION);
    printf("%s\n %s\n %s\n", name, rend, vers);
    gError:
    FcGLX_PBufferFreeContext(&s_fcGLX, &mPBufferContext, FcDisplay);

    return mError;
}

static inline FcError_t FcCore_free() {
    FcError_t mError;
    XCloseDisplay(FcDisplay);

    mError = FcGL_free(&s_fcGL);
    if (mError) goto gError;
    mError = FcGLX_free(&s_fcGLX);
    if (mError) goto gError;
    gError:
    return mError;
}


static inline FcError_t FcCoreL_init(FcCore_t* core) {
    FcError_t mError;
    FcGLXPBufferContext_t mPBufferContext;

    XInitThreads();
    core->m_display = XOpenDisplay(NULL);

    mError = FcGLX(&core->m_glx);
    if (mError)
        goto gError;
    mError = FcGLX_PBufferContext(&core->m_glx, &mPBufferContext, core->m_display, DefaultScreen(core->m_display), 0, 0);
    if (mError)
        goto gError;
    mError = FcGL(&core->m_gl, (void *(*)(const char *const)) core->m_glx.glXGetProcAddress);
    if (mError)
        goto gError;
    const GLubyte* name = core->m_gl.m_glGetString(GL_VENDOR);
    const GLubyte* rend = core->m_gl.m_glGetString(GL_RENDERER);
    const GLubyte* vers = core->m_gl.m_glGetString(GL_VERSION);
    printf("%s\n %s\n %s\n", name, rend, vers);
    gError:
    FcGLX_PBufferFreeContext(&core->m_glx, &mPBufferContext, core->m_display);

    return mError;
}

static inline FcError_t FcCoreL_free(FcCore_t* core) {
    FcError_t mError;
    XCloseDisplay(core->m_display);

    mError = FcGL_free(&core->m_gl);
    if (mError) goto gError;
    mError = FcGLX_free(&core->m_glx);
    if (mError) goto gError;

    gError:
    return mError;
}

#endif