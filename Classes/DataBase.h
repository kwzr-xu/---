#ifndef __DataBase_H__
#define __DataBase_H__

#include<string>
#include<vector>
#include"cocos2d.h"
#include"json/document.h"
#include"json/rapidjson.h"

using namespace std;
using namespace rapidjson;
USING_NS_CC;

// SData 结构体：用于表示基本数据库条目。
struct SData
{
public:
    SData() : nID(0) {}  // 构造函数，初始化 ID 为 0。
    int nID;  // 数据的唯一标识符。
};

// CDataController 类：用于管理数据库数据。
class CDataController
{
public:
    CDataController();  // 构造函数。
    ~CDataController(); // 析构函数。

    // 从给定路径加载文件。
    virtual void loadFile(const string& strPath);

    // 通过 ID 获取数据。
    SData* getDataByID(int nID);

    // 纯虚函数，用于解析文档，必须在派生类中实现。
    virtual void parse(Document& doc) = 0;

    // 通过索引获取数据。
    SData* getDataByIndex(int nIndex);

    // 获取所有数据。
    vector<SData*> getAllData();

    // 获取数据的数量。
    int getSize();

protected:
    vector<SData*> m_VecData; // 存储数据的容器
};

#endif
