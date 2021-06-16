#ifndef __FC_GL_BUTTON_H__
#define __FC_GL_BUTTON_H__
#include "FcError.h"
#include "FcGL.h"
#include "FcMath.h"


typedef struct _FcGL_Button_options_t {
    GLubyte* image;
    GLuint widthImage, heightImage;

    GLuint width, height;
    GLuint x, y;
    GLuint color;
    GLuint fontSize;
    GLubyte *text;
} FcGL_Button_options_t;

typedef struct _FcGL_Button_t {
    GLfloat m_width, m_height;
    GLfloat m_x, m_y;
    GLint m_texture;
} FcGL_Button_t;

static inline FcError_t FcGL_Button(FcGL_Button_options_t *options, FcGL_Button_t* button);
static inline FcError_t FcGL_Button_free(FcGL_Button_t *button);

static inline GLint FcGL_Button_IsWithinRegion(const GLuint x, const GLuint y);


static inline FcError_t FcGL_Button(FcGL_Button_options_t *options, FcGL_Button_t* button){
    GLuint i, j;
    FcError_t mError = FC_NO_ERROR;

    if (!options->image){
        mError = FC_IMAGE_NOIMAGE;
        goto gError;
    }
    for (i = options->y; i < options->heightImage; i++){
        for (j = options->x; j < options->widthImage; j++){
            options->image[(i * options->heightImage + j) * 4 + 0] = 255;
            options->image[(i * options->heightImage + j) * 4 + 1] = 255;
            options->image[(i * options->heightImage + j) * 4 + 2] = 255;
            options->image[(i * options->heightImage + j) * 4 + 3] = 255;
        }
    }
    gError:
    return mError;
}
static inline FcError_t FcGL_Button_free(FcGL_Button_t *button){
    FcError_t mError = FC_NO_ERROR;
    
    return mError;
}


#endif
