#include <Python.h>
#pragma comment(lib, "./build/kcpwrapper.lib")

extern void initModule(void);

PyMODINIT_FUNC initkcp(void) {
    initModule();
}
