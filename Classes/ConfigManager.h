#pragma once
#ifndef __ConfigManager_H__
#define __ConfigManager_H__

#include "DataBase.h"

//用于管理配置资源数据
class CConfigMgr
{
public:
    //获取ConfigManager中的实例
    static CConfigMgr* getInstance();
    
    //通过函数来获取数据和修改数据
    CDataController* getData(string strName);
    void setData(string strName, CDataController* pDataBaseMgr);

private:
    CConfigMgr();
    ~CConfigMgr();
    //指向实例的指针
    static CConfigMgr* m_pInstance;
    //用来存储数据配置
    map<string, CDataController*> m_MapDatas;
};

#endif