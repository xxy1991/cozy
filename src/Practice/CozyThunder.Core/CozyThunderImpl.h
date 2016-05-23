#ifndef __COZY_THUNDER_IMPL__
#define __COZY_THUNDER_IMPL__

#include "ICozyThunder.h"
#include <vector>
#include "ThreadPool.h"

namespace Cozy
{
    class CozyThunderImpl : public ICozyThunder
    {
    public:
        virtual bool Initialize();
        virtual void UnInitialize();

        virtual ICozyThunderTask* CreateTask(const wchar_t* sCfgPath);
        virtual ICozyThunderTask* LoadTask(const wchar_t* sCfgPath);
        virtual bool SaveTask(ICozyThunderTask* pTask);

        // �ͷ�task
        virtual bool ReleaseTask(ICozyThunderTask* pTask);
        // ����task��صĻ����ļ��������ļ����ͷ�task�����������������ɵ��ļ�
        virtual bool ClearTask(ICozyThunderTask* pTask);

    private:
        std::vector<ICozyThunderTask*>  m_ThunderTaskList;
    };
}

#endif // __COZY_THUNDER_IMPL__