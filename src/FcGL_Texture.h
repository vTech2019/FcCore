#ifndef __FC_GL_TEXTURE_H__
#define __FC_GL_TEXTURE_H__
#include <FcGL.h>

static inline FcError_t FcGL_Textures_RGBA8(GLuint* textures, const GLuint numberTextures, const GLubyte** data, const GLuint* width, const GLuint* height){
    GLuint i;
    glGenTextures(2, textures);
    for (i = 0; i < numberTextures; i++){
        glBindTexture(GL_TEXTURE_2D, textures[i]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width[i], height[i], 0, GL_RGBA, GL_UNSIGNED_BYTE, data[i]);
    }
    glBindTexture(GL_TEXTURE_2D, 0);
    return FC_NO_ERROR;
}
static inline void FcGL_Textures_free(GLuint* textures, const GLuint numberTextures){
    glDeleteTextures(numberTextures, textures);
}





#endif
