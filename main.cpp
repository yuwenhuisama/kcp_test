#include <iostream>
#include <dlfcn.h>

typedef void (*initKcp)(void);


int main(int, char**) {
    void* handle = dlopen("./build/lib.macosx-10.14-x86_64-2.7/kcp.so", RTLD_LAZY);
    if(!handle)
    {        
            printf("ERROR, Message(%s).\n", dlerror());
            return -1;
    }

    auto g_Test = (initKcp)dlsym(handle, "initkcp");
    char* szError = dlerror();
    if(szError != NULL)
    {
        printf("ERROR, Message(%s).\n", szError);
        dlclose(handle);
        return -1;
    }

    if(g_Test != NULL)
    {
        g_Test();
    }
    dlclose(handle);


    return 0;
}
