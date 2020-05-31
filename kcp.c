#include <Python2.7/Python.h>

// extern void initModule();

// PyMODINIT_FUNC initkcp(void)
// {
//     // initModule();
// }


static PyObject* helloworld(PyObject* self) {
   return Py_BuildValue("s", "Hello, Python extensions!!");
}

static char helloworld_docs[] =
   "helloworld( ): Any message you want to put here!!\n";

static PyMethodDef helloworld_funcs[] = {
   {"kcp", (PyCFunction)helloworld, 
      METH_NOARGS, helloworld_docs},
      {NULL}
};

PyMODINIT_FUNC initkcp(void){
   Py_InitModule("kcp", helloworld_funcs);
}
