#ifndef __MediaManager_H__
#define __MediaManager_H__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "cocos2d.h"
#include "json/rapidjson.h"
#include "json/document.h"

using namespace std;
using namespace rapidjson;
USING_NS_CC;

const int FilesNumber = 1; //资源文件的个数

struct SResDt
{
	vector<string> m_VecPng;
	vector<string> m_VecPlist;
	vector<string> m_VecAudio;
};

class CResDtMgr
{
public:
	static CResDtMgr* getInstance();
	void loadFile(const string& strPath);
	SResDt* getData(string strKey);
private:
	CResDtMgr();
	~CResDtMgr();
	map<string, SResDt*> m_MapData;
	static CResDtMgr* m_pInstance;
};
#endif

