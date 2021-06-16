

#ifndef _FCPRODUCERCONSUMER_H_
#define _FCPRODUCERCONSUMER_H_

#include "FcThread.h"
#include <stdint.h>
#include <string.h>

#ifdef WIN32
extern DWORD __stdcall Fc_ThreadConsumer(void* m_window);
#elif (__linux)
extern void *Fc_ThreadConsumer(void *m_window);
#endif

#define QUEUE_SIZE 256

enum FcGLWindow_graphicsQueue {
    e_FcGL_exit,
    e_FcGL_callFunction_fp,
    e_FcGL_callFunction_fpp,
    e_FcGL_callFunction_fup,
    e_FcGL_callFunction_fff,

    e_FcGL_callbackFunction_fp,
    e_FcGL_callbackFunction_fpp,
    e_FcGL_callbackFunction_fup,
    e_FcGL_callbackFunction_fff,
    e_FcGL_callbackFunction_exit
};
union _Fc_ProducerConsumerTypeData_t {
    void *v;
    float f;
    unsigned u;
};
typedef struct _Fc_ProducerConsumerData_t {
    uintptr_t id;
    union _Fc_ProducerConsumerTypeData_t s0;
    union _Fc_ProducerConsumerTypeData_t s1;
    union _Fc_ProducerConsumerTypeData_t s2;
} Fc_ProducerConsumerData_t;

typedef struct _Fc_ProducerConsumer_t {
    FcThread_t m_thread;
    FcMutex_t m_mutex;
    FcSemaphore_t m_full;
    FcSemaphore_t m_empty;
    uintptr_t i, offset;
    Fc_ProducerConsumerData_t m_callbackFunction;
    Fc_ProducerConsumerData_t m_queue[QUEUE_SIZE];
} Fc_ProducerConsumer_t;


static inline FcError_t Fc_ProducerConsumer(Fc_ProducerConsumer_t *glThread);

static inline FcError_t Fc_ProducerConsumer_freeLock(Fc_ProducerConsumer_t *m_thread);

static inline FcError_t Fc_threadProducer(Fc_ProducerConsumer_t *glThread, Fc_ProducerConsumerData_t value);




static inline FcError_t Fc_ProducerConsumer(Fc_ProducerConsumer_t *glThread) {
    FcError_t l_error = FC_NO_ERROR;
    memset(glThread, 0, sizeof(Fc_ProducerConsumer_t));
    l_error = FcMutex(&glThread->m_mutex);
    if (l_error) goto g_error;
    l_error = FcSemaphore(&glThread->m_full, QUEUE_SIZE);
    if (l_error) goto g_error;
    l_error = FcSemaphore(&glThread->m_empty, 0);
    if (l_error) goto g_error;
    l_error = FcThread_create(&glThread->m_thread, Fc_ThreadConsumer, glThread);
    g_error:
    return l_error;
}

static inline FcError_t Fc_ProducerConsumer_freeLock(Fc_ProducerConsumer_t *m_thread) {
    FcError_t l_error = FC_NO_ERROR;
    Fc_threadProducer(m_thread, (Fc_ProducerConsumerData_t) {e_FcGL_exit, 0, 0, 0});
    l_error = FcThread_join(&m_thread->m_thread);
    if (l_error) goto g_error;
    l_error = FcMutex_Free(&m_thread->m_mutex);
    if (l_error) goto g_error;
    l_error = FcSemaphore_Free(&m_thread->m_full);
    if (l_error) goto g_error;
    l_error = FcSemaphore_Free(&m_thread->m_empty);
    memset(m_thread, 0, sizeof(*m_thread));
    g_error:
    return l_error;
}

static inline FcError_t Fc_threadProducer(Fc_ProducerConsumer_t *glThread, Fc_ProducerConsumerData_t value) {
    FcError_t l_error = FC_NO_ERROR;
    l_error = FcSemaphore_Dec(&glThread->m_full);
    if (l_error) goto g_error;
    l_error = FcMutex_Lock(&glThread->m_mutex);
    if (l_error) goto g_error;
    glThread->offset = glThread->i ? glThread->offset + 1 : 0;
    glThread->m_queue[glThread->offset] = value;
    glThread->i++;
    l_error = FcMutex_Unlock(&glThread->m_mutex);
    if (l_error) goto g_error;
    l_error = FcSemaphore_Inc(&glThread->m_empty);
    g_error:
    return l_error;
}
#endif //_FCPRODUCERCONSUMER_H_