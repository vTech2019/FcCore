
#ifndef __FCGL_PROGRAM_H__
#define __FCGL_PROGRAM_H__

#include "FcError.h"
#include "FcGL.h"

#define LENGTH(value) (sizeof(value) / sizeof(*value))

typedef GLint FcGL_ProgramType;

enum FCGL_PROGRAMTYPE {
    FcGL_PROGRAM_VERTEX,
    FcGL_PROGRAM_FRAGMENT
};

struct ubo_data {
    GLuint block_active_uniforms;
    GLuint id;
    GLint index;
    GLchar *block_name;
    GLchar **uniform_names;
    GLuint *indices;
    GLuint *offset;
};

typedef struct _FcGL_Program_t {
    GLuint m_program_id;
} FcGL_Program_t;

typedef struct _FcGL_Program_parameters_t {
    FcGL_ProgramType typeShaders[2];
    const GLchar *codeShaders[2];
} FcGL_Program_parameters_t;

static inline FcError_t FcGL_Program(FcGL_Program_parameters_t *parameters, FcGL_Program_t *program);

static inline void FcGL_Program_free(FcGL_Program_t *program);

static inline void FcGL_Program_bind(FcGL_Program_t *program) { 
    glUseProgram(program->m_program_id); 
};

static inline GLint FcGL_Program_getVertexId(FcGL_Program_t *program, const char *name) {
    return glGetAttribLocation(program->m_program_id, name);
};

static inline GLint FcGL_Program_getUniformId(FcGL_Program_t *program, const char *name) {
    return glGetUniformLocation(program->m_program_id, name);
};


static inline FcError_t checkErrorShader(GLuint shader, const char *text, GLuint status) {
    FcError_t mError = FC_NO_ERROR;
    GLint infoLength = 1;
    GLint messageLength = 0;
    glGetShaderiv(shader, status, &infoLength);
    if (infoLength == GL_FALSE) {
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLength);
        GLchar *infoLog = (GLchar *) malloc(infoLength * sizeof(GLchar));
        glGetShaderInfoLog(shader, infoLength, &messageLength, infoLog);
        fprintf(stderr, "%s - %s\n", text, infoLog);
        free(infoLog);
        mError = FC_GL_COMPILE_STATUS;
    }
    return mError;
}

static inline FcError_t programInfoLog(GLuint shader) {
    FcError_t mError = FC_NO_ERROR;
    GLint infoLength = 0;
    GLint lengthWriteInfo = 0;
    glGetProgramiv(shader, GL_INFO_LOG_LENGTH, &infoLength);
    if (infoLength > 0) {
        GLchar *log = (GLchar *) malloc(infoLength * sizeof(GLchar));
        glGetProgramInfoLog(shader, infoLength, &lengthWriteInfo, log);
        fprintf(stderr, "Information - %s	\n", log);
        free(log);
        mError = FC_GL_LINK_STATUS;
    }
    return mError;
}

static inline void programValidateLog(GLuint shader) {
    GLint infoLength = 0;
    GLint lengthWriteInfo = 0;
    glValidateProgram(shader);
    glGetProgramiv(shader, GL_VALIDATE_STATUS, &infoLength);
    if (infoLength == GL_FALSE) {
        infoLength= 1;
        GLint messageLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLength);
        GLchar *infoLog = (GLchar *) malloc(infoLength * sizeof(GLchar));
        glGetShaderInfoLog(shader, infoLength, &messageLength, infoLog);
        fprintf(stderr, "%s\n", infoLog);
        free(infoLog);
    }
}

static inline GLuint createProgram(FcGL_Program_parameters_t *parameters, GLuint* glProgram) {
    FcError_t mError;
    GLuint i;
    GLuint vertexShaders = 0;
    GLuint fragmentShaders = 0;
    GLuint computeShaders = 0;
    mError = FC_NO_ERROR;
    *glProgram = 0;
    for (i = 0; i < LENGTH(parameters->typeShaders); i++) {
        switch (parameters->typeShaders[i]) {
            case FcGL_PROGRAM_VERTEX: {
                vertexShaders = glCreateShader(GL_VERTEX_SHADER);
                glShaderSource(vertexShaders, 1, &parameters->codeShaders[i], NULL);
                glCompileShader(vertexShaders);
                mError = checkErrorShader(vertexShaders, "GL_VERTEX_SHADER", GL_COMPILE_STATUS);
                if (mError) goto gError;
                break;
            }
            case FcGL_PROGRAM_FRAGMENT: {
                fragmentShaders = glCreateShader(GL_FRAGMENT_SHADER);
                glShaderSource(fragmentShaders, 1, &parameters->codeShaders[i], NULL);
                glCompileShader(fragmentShaders);
                mError = checkErrorShader(fragmentShaders, "GL_FRAGMENT_SHADER", GL_COMPILE_STATUS);
                if (mError) goto gError;
                break;
            }
            case GL_TESS_CONTROL_SHADER:
            case GL_TESS_EVALUATION_SHADER:
            case GL_GEOMETRY_SHADER:
            case GL_COMPUTE_SHADER: {
                //computeShaders = glCreateShader(GL_COMPUTE_SHADER);
                //glShaderSourceARB(computeShaders, 1, &parameters->codeShaders[i], NULL);
                //glCompileShaderARB(computeShaders);
                //mError = checkErrorShader(computeShaders, "GL_COMPUTE_SHADER", GL_COMPILE_STATUS);
                //if (mError) goto gError;
                break;
            }
            default: {
                break;
            }
        }
    }
    *glProgram = glCreateProgram();
    if (fragmentShaders) glAttachShader(*glProgram, fragmentShaders);
    if (vertexShaders) glAttachShader(*glProgram, vertexShaders);
    if (computeShaders) glAttachShader(*glProgram, computeShaders);
    glLinkProgram(*glProgram);
    mError = programInfoLog(*glProgram);
    if (mError) goto gError;
    programValidateLog(*glProgram);

gError :
    if (vertexShaders) glDetachShader(*glProgram, vertexShaders);
    if (fragmentShaders) glDetachShader(*glProgram, fragmentShaders);
    if (computeShaders) glDetachShader(*glProgram, computeShaders);

    if (fragmentShaders) glDeleteShader(fragmentShaders);
    if (vertexShaders) glDeleteShader(vertexShaders);
    if (computeShaders) glDeleteShader(computeShaders);
    return mError;
}

static inline FcError_t FcGL_Program(FcGL_Program_parameters_t *parameters, FcGL_Program_t* program) {
    FcError_t mError = createProgram(parameters, &program->m_program_id);
    return mError;
}
static inline GLint FcGL_Program_getUniformLocation(FcGL_Program_t* program, const GLchar* name) {
    return glGetUniformLocation(program->m_program_id, name);
}
static inline GLint FcGL_Program_getAttribLocation(FcGL_Program_t* program, const GLchar* name) {
    return glGetAttribLocation(program->m_program_id, name);
}

static inline FcError_t FcGL_Program_use(FcGL_Program_t* program) {
    glUseProgram(program->m_program_id);
    return FC_NO_ERROR;
}

static inline void FcGL_Program_free(FcGL_Program_t *program) {
    glDeleteProgram(program->m_program_id);

}
#endif
