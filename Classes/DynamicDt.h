#ifndef __DynamicDt_H__
#define __DynamicDt_H__

#include "cocos2d.h"

// CDynamicDt �ࣺ���ڹ���̬��Ϸ����
class CDynamicDt {
public:
    // ��ȡ����ʵ��
    static CDynamicDt* getInstance();

    // ʹ�ú� CC_SYNTHESIZE ʵ�� getter �� setter ����
    CC_SYNTHESIZE(int, m_nLevelID, LevelID);      // ��ǰ�ؿ�ID
    CC_SYNTHESIZE(int, m_nMapGold, MapGold);      // ��ͼ�ϵĽ����
    CC_SYNTHESIZE(int, m_nWaveIndex, WaveIndex);  // ��������
    CC_SYNTHESIZE(int, m_nRadishHp, RadishHp);    // �ܲ�������ֵ

private:
    CDynamicDt();                                // ���캯��
    ~CDynamicDt();                               // ��������
    static CDynamicDt* m_pInstance;              // ��̬ʵ��
};

#endif
