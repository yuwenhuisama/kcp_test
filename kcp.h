#ifndef _H_KCP_
#define _H_KCP_

#include <ikcp.h>
#include <python2.7/Python.h>

class Kcp {
private:
    ikcpcb *m_pKcb = nullptr;
    uint32_t m_uToken = 0;

    PyObject* m_pfSendCallBack = nullptr;

public:
    Kcp() = default;
    Kcp(Kcp &&) = delete;
    Kcp(const Kcp &) = delete;
    Kcp &operator=(Kcp &&) = delete;
    Kcp &operator=(const Kcp &) = delete;
    ~Kcp();

    const PyObject* GetPyCallBack() const { return m_pfSendCallBack; }

    void Initialize(PyObject* pfSendCallBack, uint32_t uToken);
    void Update(uint64_t uCurTime);
    void Input(PyObject* pPyByteArray);
    void Recv(PyObject* pPyByteArray);
    void Send(PyObject* pPyByteArray);

    static int UdpOutput(const char *buf, int len, ikcpcb *kcp, void *user);
};
#endif  // !_H_KCP_
