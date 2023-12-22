#include "DynamicDt.h"

// ��ʼ����̬ʵ��ָ��Ϊ nullptr
CDynamicDt* CDynamicDt::pInstance = nullptr;

// ���캯��
CDynamicDt::CDynamicDt()
    : m_nLevelID(0), m_nMapGold(0), m_nWaveIndex(1), m_nRadishHp(0) {
}

// ��������
CDynamicDt::~CDynamicDt() {
}

// ��ȡ����ʵ��
CDynamicDt* CDynamicDt::getInstance() {
    if (!pInstance) {
        pInstance = new CDynamicDt(); // ��ʵ�������ڣ�������ʵ��
    }
    return pInstance; // ����ʵ��
}