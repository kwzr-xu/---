#pragma once
#ifndef __ResDtMgr_H__
#define __ResDtMgr_H__

#include<string>
#include<vector>
#include<map>
#include"cocos2d.h"
#include"json/rapidjson.h"
#include"json/document.h"
#define FilesNumber 1 //资源文件的个数
using namespace std;
using namespace rapidjson;
USING_NS_CC;

struct MediaData
{
	vector<string> VecPng;
	vector<string> VecPlist;
	vector<string> VecAudio;
};

class MediaManager
{
public:
	static MediaManager* getInstance();
	void loadFile(const string& strPath);
	MediaData* getData(string strKey);
private:
	MediaManager();
	~MediaManager();
	map<string, MediaData*> DataMap;
	static MediaManager* pInstance;
};

#endif

