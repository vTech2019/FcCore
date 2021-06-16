
#ifndef _FCCORELOADER_H_
#define _FCCORELOADER_H_

typedef void (*func_t)(void);

#ifndef WIN32
#include <dlfcn.h>
#include <stdio.h>

typedef void* FcLib_t;

#else
#include <windows.h>

typedef  HMODULE FcLib_t;

#endif

#ifdef __cplusplus
extern "C" {
#endif


static inline FcLib_t FcLib_load(const char* const name) {
    
#ifndef WIN32
    FcLib_t lib = dlopen(name, RTLD_LAZY | RTLD_LOCAL);
#else
   FcLib_t lib = LoadLibrary(name);
#endif
    return lib;
    
}

static inline func_t FcLib_loadFunction(FcLib_t lib, const char* const nameFunction) {
    #ifndef WIN32
        void (*f)(void) = (void (*)(void))dlsym(lib, nameFunction);
    #else
        void (*f)(void) = (void (*)(void))GetProcAddress((HINSTANCE)lib, nameFunction);
    #endif
    
    return f;
}

static inline void FcLib_free(FcLib_t lib) {
    #ifndef WIN32
        if (lib) dlclose(lib);
    #else
        FreeLibrary((HINSTANCE)lib);
    #endif
}

#ifdef __cplusplus
}
#endif

#endif //_FCCORELOADER_H_