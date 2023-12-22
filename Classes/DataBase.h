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

// SData �ṹ�壺���ڱ�ʾ�������ݿ���Ŀ��
struct SData
{
public:
    SData() : nID(0) {}  // ���캯������ʼ�� ID Ϊ 0��
    int nID;  // ���ݵ�Ψһ��ʶ����
};

// CDataController �ࣺ���ڹ������ݿ����ݡ�
class CDataController
{
public:
    CDataController();  // ���캯����
    ~CDataController(); // ����������

    // �Ӹ���·�������ļ���
    virtual void loadFile(const string& strPath);

    // ͨ�� ID ��ȡ���ݡ�
    SData* getDataByID(int nID);

    // ���麯�������ڽ����ĵ�����������������ʵ�֡�
    virtual void parse(Document& doc) = 0;

    // ͨ��������ȡ���ݡ�
    SData* getDataByIndex(int nIndex);

    // ��ȡ�������ݡ�
    vector<SData*> getAllData();

    // ��ȡ���ݵ�������
    int getSize();

protected:
    vector<SData*> m_VecData; // �洢���ݵ�����
};

#endif
