#ifndef __FC_GL_UI_H__
#define __FC_GL_UI_H__

#include "FcGL.h"
#include "FcGL_Program.h"
#include "FcGL_Texture.h"
#include "FcGL_Button.h"
#include <GL/glcorearb.h>

#define FC_GL_MAX_CONTROLS 64;

extern const char s_FcShaderVsDefault[];
extern const char s_FcShaderFsDefault[];

typedef struct _FcGL_UI_options_t {
    GLuint mWindowWidth, mWindowHeight;
    GLuint mControls;
    FcGL_Button_options_t mButton[1];
} FcGL_UI_options_t;

typedef struct _FcGL_UI_update_t {
    GLfloat mWindow_WidthHeight[2];
    GLfloat mMouse_X_Y_PRESS[4];
} FcGL_UI_update_t;

typedef struct _FcGL_UI_t {
    FcGL_Program_t mProgram;
    GLuint mControls;
    GLuint mTexture[2];
    GLint mMouseID;
    GLint mWindowID;
    GLint mPositionID;
    GLuint mBufferID;
    GLuint mVAO_ID;
    GLfloat mWindow_WidthHeight[2];
    GLfloat mMouse_X_Y_PRESS[4];
    FcGL_Button_t mButton[1];
} FcGL_UI_t;

static inline FcError_t FcGL_UI(FcGL_UI_options_t *options, FcGL_UI_t* ui);
static inline FcError_t FcGL_UI_draw(FcGL_UI_t* ui);
static inline void FcGL_UI_update(FcGL_UI_t* ui, FcGL_UI_update_t* updateValues);
static inline FcError_t FcGL_UI_free(FcGL_UI_t *ui);



static inline FcError_t FcGL_UI(FcGL_UI_options_t *options, FcGL_UI_t* ui){
    FcError_t mError = FC_NO_ERROR;
    FcGL_UI_t mUI;
    GLuint i0, i1;
    GLubyte* memory = NULL;
    GLfloat vertices[] = {
            0.5f,  0.5f,
            0.5f, -0.5f,
            -0.5f,  0.5f,
            0.5f, -0.5f,
            -0.5f, -0.5f,
            -0.5f,  0.5f
    };
    *ui = (FcGL_UI_t){0};
    memory = (GLubyte*)calloc(1, options->mWindowWidth * options->mWindowHeight * 8 * sizeof(GLubyte));
    if (mError) goto gError;
    FcGL_Program_parameters_t mParameters = {
        {FcGL_PROGRAM_VERTEX, FcGL_PROGRAM_FRAGMENT},
        {s_FcShaderVsDefault, s_FcShaderFsDefault}
    };
    mError = FcGL_Program(&mParameters, &ui->mProgram);
    if (mError) goto gError;
    
    const GLubyte* imageColor[2] = {
        memory + options->mWindowWidth * options->mWindowHeight * 0,
        memory + options->mWindowWidth * options->mWindowHeight * 4
    };
    const GLuint widthHeight[2][2] = {
        { options->mWindowWidth, options->mWindowWidth },
        { options->mWindowHeight, options->mWindowHeight }
    };
    for (i0 = 0; i0 < options->mControls; i0++){
        mError = FcGL_Button(&options->mButton[i0], &mUI.mButton[i0]);
        if (mError)
            goto gError;
    }
    mError = FcGL_Textures_RGBA8(ui->mTexture, 2, imageColor, widthHeight[0], widthHeight[1]);
    ui->mWindowID = FcGL_Program_getUniformLocation(&ui->mProgram, "window");
    ui->mMouseID = FcGL_Program_getUniformLocation(&ui->mProgram, "mouse");
    ui->mPositionID = FcGL_Program_getAttribLocation(&ui->mProgram, "positions");



    glGenBuffers(1, &ui->mBufferID);
    glGenVertexArrays(1, &ui->mVAO_ID);
    glBindVertexArray(ui->mVAO_ID);
    glBindBuffer(GL_ARRAY_BUFFER, ui->mBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(ui->mPositionID);
    glVertexAttribPointer(ui->mPositionID,  2, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    if (memory) free(memory);
    return mError;
    gError:
    if (memory) free(memory);
    FcGL_Program_free(&ui->mProgram);
    return mError;
}
static inline FcError_t FcGL_UI_draw(FcGL_UI_t* ui){
    FcError_t mError = FC_NO_ERROR;
    FcGL_Program_use(&ui->mProgram);
    //glUniform2fv(ui->mWindowID, 1, ui->mWindow_WidthHeight);
    //glUniform4fv(ui->mWindowID, 1, ui->mMouse_X_Y_PRESS);

    glBindVertexArray(ui->mVAO_ID);

    glDrawArrays(GL_TRIANGLES, 0, 512);
    //glDisableVertexAttribArray(ui->mPositionID);
    return mError;
}
static inline void FcGL_UI_update(FcGL_UI_t* ui, FcGL_UI_update_t* updateValues){
    ui->mWindow_WidthHeight[0] = updateValues->mWindow_WidthHeight[0];
    ui->mWindow_WidthHeight[1] = updateValues->mWindow_WidthHeight[1];
    ui->mMouse_X_Y_PRESS[0] = updateValues->mMouse_X_Y_PRESS[0];
    ui->mMouse_X_Y_PRESS[1] = updateValues->mMouse_X_Y_PRESS[1];
    ui->mMouse_X_Y_PRESS[2] = updateValues->mMouse_X_Y_PRESS[2];
    ui->mMouse_X_Y_PRESS[3] = updateValues->mMouse_X_Y_PRESS[3];
}

static inline FcError_t FcGL_UI_free(FcGL_UI_t *ui){
    FcError_t mError = FC_NO_ERROR;
    GLuint i0;
    for (i0 = 0; i0 < ui->mControls; i0++){
        mError = FcGL_Button_free(&ui->mButton[i0]);
        if (mError)
            goto gError;
    }
    glDeleteBuffers(1, &ui->mBufferID);
    FcGL_Textures_free(ui->mTexture, 2);
    FcGL_Program_free(&ui->mProgram);
    gError:
    return mError;
}


#endif
