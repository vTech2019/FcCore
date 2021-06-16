#ifdef _WIN32

#ifndef __FCWGL_H__
#define __FCWGL_H__


static inline BOOL find_WGL_extensions(const char* pName, HDC hdc, const char* (WINAPI* glGetExtensionsStringARB)(HDC hdc)) {
    const char* extensions = (const char*)glGetExtensionsStringARB(hdc);
    size_t size = strlen(pName);
    while (extensions) {
        if (!strncmp(extensions, pName, size) && (*(extensions + size) == 0 || *(extensions + size) == ' '))
            return TRUE;
        extensions = strchr(extensions, ' ');
        if (extensions)
            extensions++;
    }
    return FALSE;
}

#endif
#endif