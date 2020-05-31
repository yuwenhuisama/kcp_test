#include "kcp.h"

int Kcp::UdpOutput(const char* buf, int len, ikcpcb* kcp, void* user) {
    auto pKcp = static_cast<Kcp*>(user);
    auto pCallBackObj = const_cast<PyObject*>(pKcp->GetPyCallBack());
    if (PyCallable_Check(pCallBackObj)) {
        PyEval_CallObject(pCallBackObj, PyByteArray_FromStringAndSize(buf, len));
        return 0;
    }
    return -1;
}

Kcp::~Kcp() { ikcp_release(m_pKcb); }

void Kcp::Initialize(PyObject* pfSendCallBack, unsigned long uToken) {
    m_pKcb = ikcp_create(uToken, this);
    m_uToken = uToken;

    m_pKcb->output = Kcp::UdpOutput;

    ikcp_wndsize(m_pKcb, 128, 128);
    ikcp_nodelay(m_pKcb, 2, 10, 2, 1);
    m_pKcb->rx_minrto = 10;
    m_pKcb->fastresend = 1;
}

void Kcp::Update(unsigned long uCurTime) {
    ikcp_update(m_pKcb, (IUINT32)(uCurTime & 0xfffffffful));
}

void Kcp::Input(PyObject* pPyByteArray) {
    if (PyByteArray_Check(pPyByteArray)) {
        auto pBytes = PyByteArray_AS_STRING(pPyByteArray);
        auto pLen = PyByteArray_GET_SIZE(pPyByteArray);

        ikcp_input(m_pKcb, pBytes, pLen);
    }
}

void Kcp::Recv(PyObject* pPyByteArray) {
    if (PyByteArray_Check(pPyByteArray)) {
        auto pBytes = PyByteArray_AS_STRING(pPyByteArray);
        auto pLen = PyByteArray_GET_SIZE(pPyByteArray);

        auto hr = ikcp_recv(m_pKcb, pBytes, pLen);
    }
}

void Kcp::Send(PyObject* pPyByteArray) {
    if (PyByteArray_Check(pPyByteArray)) {
        auto pBytes = PyByteArray_AS_STRING(pPyByteArray);
        auto pLen = PyByteArray_GET_SIZE(pPyByteArray);

        ikcp_send(m_pKcb, pBytes, pLen);
    }
}
