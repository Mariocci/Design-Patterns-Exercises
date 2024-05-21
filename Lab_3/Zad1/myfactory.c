#include "myfactory.h"
#include <windows.h>
#include <stddef.h>

typedef void* (*FUNC)(char const*, void*);
typedef size_t (*FUNC_SIZE)(void);
typedef void* (*FUNC_CONSTRUCT)(void*, char const*);

void* myfactory(char const* libname, char const* ctorarg, void* memory, char const* arg) {
    HMODULE moduleId = LoadLibrary(libname);
    if (moduleId == NULL) {
        return NULL;
    }
    if (strcmp(arg, "construct") == 0) {
        return ((FUNC_CONSTRUCT)GetProcAddress(moduleId, "construct"))(memory, ctorarg);
    } else {
        return ((FUNC)GetProcAddress(moduleId, "create"))(ctorarg, memory);
    }
}
size_t my_sizeof(char const* libname){
    HMODULE moduleId = LoadLibrary(libname);
    if (moduleId == NULL) {
        return 0;
    }
    
    return ((FUNC_SIZE)GetProcAddress(moduleId, "size_of"))();
}