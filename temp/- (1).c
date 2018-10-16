#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void* (*PtrFunc)(size_t, size_t);

int main()
{
    void* handle;
    PtrFunc func;
    char* error;
    void* vector = NULL;

    handle = dlopen("/home/meir/Experis/work/Lib/libDDS.so", RTLD_LAZY);

    if (!handle)
    {
        fputs("Error", stderr);
        exit(1);
    }

    func = (PtrFunc) dlsym(handle, "Vector_Create");

    if ((error = dlerror()) != NULL)
    {
        fputs("Error", stderr);
        exit(1);
    }

    vector = func(3, 4);

    printf("%p", vector);

    dlclose(handle);

    return 0;
}