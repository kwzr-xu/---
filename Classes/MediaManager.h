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

