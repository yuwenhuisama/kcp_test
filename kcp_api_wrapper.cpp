#include "kcp.h"

struct PyKcpObject {
    PyObject_HEAD;
    Kcp *m_pKcp = nullptr;
};

PyObject *PyKcp_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
    PyKcpObject *self;
    self = reinterpret_cast<PyKcpObject *>(type->tp_alloc(type, 0));

    self->m_pKcp = new Kcp();

    return reinterpret_cast<PyObject *>(self);
}

void PyKcp_dealloc(PyObject *obj) {
    delete reinterpret_cast<PyKcpObject *>(obj)->m_pKcp;
    Py_TYPE(obj)->tp_free(obj);
}

static PyMethodDef KcpMethods[] = {{nullptr}};

static PyTypeObject KcpType = {
    PyVarObject_HEAD_INIT(nullptr, 0) "matrix.Matrix", /* tp_name */
    sizeof(PyKcpObject),                               /* tp_basicsize */
    0,                                                 /* tp_itemsize */
    (destructor)PyKcp_dealloc,                         /* tp_dealloc */
    nullptr,                                           /* tp_print */
    nullptr,                                           /* tp_getattr */
    nullptr,                                           /* tp_setattr */
    nullptr,                                           /* tp_reserved */
    nullptr,                                           /* tp_repr */
    nullptr,                                           /* tp_as_number */
    nullptr,                                           /* tp_as_sequence */
    nullptr,                                           /* tp_as_mapping */
    nullptr,                                           /* tp_hash  */
    nullptr,                                           /* tp_call */
    nullptr,                                           /* tp_str */
    nullptr,                                           /* tp_getattro */
    nullptr,                                           /* tp_setattro */
    nullptr,                                           /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,          /* tp_flags */
    "Coustom kcp class.",                              /* tp_doc */
    nullptr,                                           /* tp_traverse */
    nullptr,                                           /* tp_clear */
    nullptr,                                           /* tp_richcompare */
    0,                                                 /* tp_weaklistoffset */
    nullptr,                                           /* tp_iter */
    nullptr,                                           /* tp_iternext */
    KcpMethods,                                        /* tp_methods */
    nullptr,                                           /* tp_members */
    nullptr,                                           /* tp_getset */
    nullptr,                                           /* tp_base */
    nullptr,                                           /* tp_dict */
    nullptr,                                           /* tp_descr_get */
    nullptr,                                           /* tp_descr_set */
    0,                                                 /* tp_dictoffset */
    nullptr,                                           /* tp_init */
    nullptr,                                           /* tp_alloc */
    PyKcp_new                                          /* tp_new */
};

static PyMethodDef kcpMethods[] = {{nullptr}};

extern "C" {
void initModule(void) { Py_InitModule3("kcp", kcpMethods, "Kcp for python2"); }
}
