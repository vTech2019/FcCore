
#include <GL/glx.h>
#ifdef __linux__
#ifndef _FCWINDOWXLIB_H_
#define _FCWINDOWXLIB_H_

#include "FcProducerConsumer.h"
#include "FcKeyboardXLIB.h"
#include "FcGL.h"

#include <X11/Xutil.h>
#include <X11/keysymdef.h>

extern FcGLX_t s_fcGLX;
extern FcGL_t s_fcGL;
extern Display *FcDisplay;

enum FcMouseKeyCode {
    FCWINDOW_MOUSE_LBUTTONDOWN = Button1,
    FCWINDOW_MOUSE_MBUTTONDOWN = Button2,
    FCWINDOW_MOUSE_RBUTTONDOWN = Button3,
    FCWINDOW_MOUSE_LBUTTONUP = Button1 + 3,
    FCWINDOW_MOUSE_MBUTTONUP = Button2 + 3,
    FCWINDOW_MOUSE_RBUTTONUP = Button3 + 3,
    FCWINDOW_MOUSE_UPWHEEL = 7,
    FCWINDOW_MOUSE_DOWNWHEEL = 8,
    FCWINDOW_MOUSE_MOTION = 9
};




typedef struct FcGLWindow_t {
    Fc_ProducerConsumer_t glThread;
    FcGLXContext_t mContext;
    Atom m_wmDeleteWindow;
    

    Colormap m_colorMap;
    Window window;
    XEvent event;
    int screenId;
    unsigned m_width, m_height;

    void *dataKeyboardCallback[2];

    void (*callbackKeyboard)(unsigned int keyCode, unsigned int keyEvent, void *data_0, void *data_1);

    void *dataMouseCallback;

    void (*callbackMouse)(unsigned int x, unsigned int y, unsigned int mouseKeyCode, void *data_0);

    void *dataResizeCallback[2];

    void (*callbackResizeWindow)(unsigned int width, unsigned int height, void *data_0, void *data_1);
} FcGLWindow_t;

extern void FcGLWindow_freeThreadContext(FcGLWindow_t *window);
extern void FcGLWindow_initThreadContext(GLXFBConfig mConfig, FcGLWindow_t *window);

static inline void FcGLWindow_swapBuffers(FcGLWindow_t *window) {
    s_fcGLX.glXSwapBuffers(FcDisplay, window->window);
};


static inline void FcGLWindow_initContext(FcGLWindow_t *window, GLXFBConfig mConfig) {

    Fc_ProducerConsumer(&window->glThread);
    Fc_ProducerConsumerData_t init = {e_FcGL_callFunction_fpp, FcGLWindow_initThreadContext, mConfig, window};
    Fc_threadProducer(&window->glThread, init);
}

static inline void FcGLWindow_freeContext(FcGLWindow_t *window) {
    Fc_ProducerConsumerData_t init = {e_FcGL_callFunction_fpp, FcGLWindow_freeThreadContext, window, NULL};
    Fc_threadProducer(&window->glThread, init);
}

static inline FcError_t FcGLWindow(FcGLWindow_t *window, uint32_t width, uint32_t height) {
    XSetWindowAttributes m_attrib = {0};
    FcError_t mError = FC_NO_ERROR;
    GLXFBConfig mConfig;
    int m_rootWindow;
    XVisualInfo *m_visual = NULL;

    window->screenId = DefaultScreen(FcDisplay);
    m_rootWindow = DefaultRootWindow(FcDisplay);


    mError = FcGLX_chooseVisualFramebuffer(&s_fcGLX, FcDisplay, window->screenId, &m_visual, &mConfig);
    if (mError) goto gError;
    window->m_colorMap = XCreateColormap(FcDisplay, m_rootWindow, m_visual->visual, AllocNone);
    


    m_attrib.border_pixel = BlackPixel(FcDisplay, window->screenId);
    m_attrib.background_pixel = WhitePixel(FcDisplay, window->screenId);
    m_attrib.colormap = window->m_colorMap;
    m_attrib.override_redirect = True;
    m_attrib.event_mask = StructureNotifyMask |
                          EnterWindowMask |
                          LeaveWindowMask |
                          ExposureMask |
                          OwnerGrabButtonMask |
                          //Button5MotionMask |
                          //Button4MotionMask |
                          Button3MotionMask |
                          Button2MotionMask |
                          Button1MotionMask |
                          ButtonMotionMask |
                          ButtonPressMask |
                          ButtonReleaseMask |
                          KeyPressMask |
                          KeyReleaseMask |
                          PointerMotionMask;
                          
    window->window = XCreateWindow(FcDisplay, m_rootWindow, 0, 0, width, height, 0, m_visual->depth,
                                   InputOutput, m_visual->visual,
                                   CWBackPixel | CWColormap | CWBorderPixel | CWEventMask, &m_attrib);
                                   
    window->m_width = width;
    window->m_height = height;
    
    window->m_wmDeleteWindow = XInternAtom(FcDisplay, "WM_DELETE_WINDOW", False);


    int error = XClearWindow(FcDisplay, window->window);
    error = XMapWindow(FcDisplay, window->window);
    
    
    error = XSetWMProtocols(FcDisplay, window->window, &window->m_wmDeleteWindow, 1);

    FcGLWindow_initContext(window, mConfig);
    gError:
    if (m_visual) XFree(m_visual);
    return mError;
}



static inline void FcGLWindow_show(FcGLWindow_t *window) {
    int error = 0;
    //BadRequest
    error = XClearWindow(FcDisplay, window->window);
    error = XMapWindow(FcDisplay, window->window);
    error = 0;
}

static inline FcError_t FcGLWindow_free(FcGLWindow_t *window) {
    FcError_t mResult = FC_NO_ERROR;
    if (!window->glThread.m_thread) goto gThreadDrawNotExist;
    Fc_ProducerConsumerData_t init = {e_FcGL_callFunction_fpp, FcGLWindow_freeContext, window, NULL};
    Fc_threadProducer(&window->glThread, init);
    mResult = Fc_ProducerConsumer_freeLock(&window->glThread);
    if (mResult) goto gError;
    gThreadDrawNotExist:

    if (FcDisplay && window->window) {
        //mResult = XRaiseWindow(FcDisplay, window->window);
        mResult = XUnmapWindow(FcDisplay, window->window);
        //if (mResult) goto gError;
        mResult = XDestroyWindow(FcDisplay, window->window);
        //if (mResult) goto gError;
        mResult = XFreeColormap(FcDisplay, window->m_colorMap);
       // if (mResult) goto gError;
        *window = (FcGLWindow_t){0};
    }
    gError:
    return mResult;
}

static inline void FcGLWindow_setCenterCursorPosition(FcGLWindow_t *window) {
    XSelectInput(FcDisplay, window->window, KeyReleaseMask);
    XWarpPointer(FcDisplay, None, window->window, 0, 0, window->m_width, window->m_height, 100, 100);
    XFlush(FcDisplay);
}

static inline void FcGLWindow_setCallbackResizeWindow(FcGLWindow_t *window,
                                        void (*callbackResizeWindow)(unsigned int width, unsigned int height,
                                                                     void *data_0, void *data_1), void *data_0,
                                        void *data_1) {
    window->callbackResizeWindow = callbackResizeWindow;
    window->dataResizeCallback[0] = data_0;
    window->dataResizeCallback[1] = data_1;
}

static inline void FcGLWindow_setCallbackKeyboard(FcGLWindow_t *window,
                                    void (*callbackKeyboard)(unsigned int keyCode, unsigned int keyEvent, void *data_1,
                                                             void *data_2),
                                    void *data_0, void *data_1) {
    window->callbackKeyboard = callbackKeyboard;
    window->dataResizeCallback[0] = data_0;
    window->dataResizeCallback[1] = data_1;
}

static inline void FcGLWindow_setCallbackMouse(FcGLWindow_t *window,
                                 void (*callbackMouse)(unsigned int x, unsigned int y, unsigned int mouseKeyCode,
                                                       void *data_0),
                                 void *data_0) {
    window->callbackMouse = callbackMouse;
    window->dataMouseCallback = data_0;
}

static inline void FcGLWindow_getClientSize(const FcGLWindow_t *window, int *width, int *height) {
    XWindowAttributes attributes;
    XGetWindowAttributes(FcDisplay, window->window, &attributes);
    *height = attributes.height;
    *width = attributes.width;

}

static inline void FcGLWindow_getWindowSize(const FcGLWindow_t *window, int *width, int *height) {
    XWindowAttributes attributes;
    XGetWindowAttributes(FcDisplay, window->window, &attributes);
    *height = attributes.height;
    *width = attributes.width + 2 * attributes.border_width;
}

static inline FcError_t FcGLWindow_dispatch(FcGLWindow_t *window) {
    int exit = 0;
    if (window->window && FcDisplay)
        while (!exit) {
            if (XPending(FcDisplay) > 0) {
                XNextEvent(FcDisplay, &window->event);
                switch (window->event.type) {
                    case ConfigureNotify:
                        window->m_width = window->event.xconfigure.width;
                        window->m_height = window->event.xconfigure.height;
                        if (window->callbackResizeWindow)
                            window->callbackResizeWindow(window->m_width, window->m_height,
                                                         window->dataResizeCallback[0], window->dataResizeCallback[1]);
                        break;
                    case Expose:
                        //callbacks.draw ();
                        //XGetWindowAttributes(window->ptr_display, window->window, &attributes);
                        //if (window->callbackResizeWindow)
                        //    window->callbackResizeWindow(attributes.width, attributes.height, window->dataResizeCallback[0], window->dataResizeCallback[1]);
                        // window->m_width = attributes.width;
                        //window->m_height = attributes.height;
                        break;
                    case LeaveNotify:
                        break;
                    case EnterNotify:
                        break;
                    case ClientMessage:
                        if (window->event.xclient.data.l[0] == window->m_wmDeleteWindow)
                            exit = 1;
                        break;
                    case DestroyNotify:
                        exit = 1;
                        break;
                    case MotionNotify:
                        if (window->callbackMouse)
                            window->callbackMouse(window->event.xmotion.x, window->m_height - window->event.xmotion.y,
                                                  FCWINDOW_MOUSE_MOTION, window->dataMouseCallback);
                        break;
                    case ButtonPress:
                    {
                        if (window->callbackMouse)
                            window->callbackMouse(window->event.xmotion.x, window->m_height - window->event.xmotion.y,
                                                  window->event.xbutton.button, window->dataMouseCallback);
                        break;
                    }
                    case ButtonRelease:
                    {
                        if (window->callbackMouse)
                            window->callbackMouse(window->event.xmotion.x, window->m_height - window->event.xmotion.y,
                                                  window->event.xbutton.button + 3, window->dataMouseCallback);
                        break;
                    }
                    case KeyPress:
                    {

                        if (window->callbackKeyboard)
                            window->callbackKeyboard(window->event.xkey.keycode, window->event.xkey.state,
                                                     window->dataKeyboardCallback[0], window->dataKeyboardCallback[1]);
                        break;
                    }
                    case KeyRelease:
                    {
                        if (window->callbackKeyboard)
                            window->callbackKeyboard(window->event.xkey.keycode, window->event.xkey.state,
                                                     window->dataKeyboardCallback[0], window->dataKeyboardCallback[1]);
                        break;
                    }
                    case FocusIn:
                    {
                        break;
                    }
                }
            }
        }
    return FcGLWindow_free(window);
}



#endif
#endif

