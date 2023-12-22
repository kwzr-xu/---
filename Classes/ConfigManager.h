#pragma once
#ifndef __ConfigMgr_H__
#define __ConfigMgr_H__

#include "DataBase.h"

//���ڹ���������Դ����
class ConfigManager
{
public:
    //��ȡConfigManager�е�ʵ��
    static ConfigManager* getInstance();

    //ͨ����������ȡ���ݺ��޸�����
    void setData(string strName, CDataController* pDataController);
    CDataController* getData(string strName);

private:
    //ָ��ʵ����ָ��
    static ConfigManager* pInstance;
    //�����洢��������
    map<string, CDataController*> DataMap;
};

#endif