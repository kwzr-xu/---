#pragma once
#ifndef __ConfigManager_H__
#define __ConfigManager_H__

#include "DataBase.h"

//���ڹ���������Դ����
class CConfigMgr
{
public:
    //��ȡConfigManager�е�ʵ��
    static CConfigMgr* getInstance();
    
    //ͨ����������ȡ���ݺ��޸�����
    CDataController* getData(string strName);
    void setData(string strName, CDataController* pDataBaseMgr);

private:
    CConfigMgr();
    ~CConfigMgr();
    //ָ��ʵ����ָ��
    static CConfigMgr* m_pInstance;
    //�����洢��������
    map<string, CDataController*> m_MapDatas;
};

#endif