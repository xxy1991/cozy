#ifndef __COZY_TEST_CALLBACK__
#define __COZY_TEST_CALLBACK__

#include "../CozyThunder.Core/ICozyThunderTaskCallback.h"
#include <mutex>
#include <iostream>

class TestCallback : public Cozy::ICozyThunderTaskCallback
{
public:
    virtual void OnStart();

    // ����ֹͣ��reason = 0 ������ɣ�����Ϊ���ִ����룩
    virtual void OnStop(int reason);

    // ������״̬��blockIdΪ1��count��state = 0 ���ؿ�ʼ 1 ������� 2����ʧ�ܣ�
    virtual void OnBlockState(unsigned int blockId, int state);

    void Wait();

private:
    std::condition_variable m_cvOK;
    std::mutex m_finishMutex;
    std::mutex m_outMutex;
};

#endif // __COZY_TEST_CALLBACK__
