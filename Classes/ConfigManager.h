#pragma once
#ifndef __ConfigMgr_H__
#define __ConfigMgr_H__

#include "DataBase.h"

//用于管理配置资源数据
class ConfigManager
{
public:
    //获取ConfigManager中的实例
    static ConfigManager* getInstance();

    //通过函数来获取数据和修改数据
    void setData(string strName, CDataController* pDataController);
    CDataController* getData(string strName);

private:
    //指向实例的指针
    static ConfigManager* pInstance;
    //用来存储数据配置
    map<string, CDataController*> DataMap;
};

#endif