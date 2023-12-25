#include"MediaManager.h"
MediaManager* MediaManager::pInstance = nullptr;
MediaManager::MediaManager()
{
}

MediaManager::~MediaManager()
{
	for (map<string, MediaData*>::iterator iter = DataMap.begin(); iter != DataMap.end(); ++iter) {
		MediaData* pData = iter->second;
		CC_SAFE_DELETE(pData);
	}
	DataMap.clear();
}

MediaManager* MediaManager::getInstance()
{
	if (!pInstance) {//若为空则创建并加载文件
		pInstance = new MediaManager();
		pInstance->loadFile("Config/MediaData.json");
	}
	return pInstance;
}

void MediaManager::loadFile(const string& strPath)
{
	//获取参数路径的完整路径和内容
	string strFullPath = FileUtils::getInstance()->fullPathForFilename(strPath);
	string strData = FileUtils::getInstance()->getStringFromFile(strFullPath);

	Document doc;
	doc.Parse(strData.c_str());

	string FilesName[FilesNumber] = { "MainScene" }; //文件名数组
	string ResType[3] = { "png","plist","audio" }; //资源类型数组
	for (int i = 0; i < FilesNumber; i++) { //遍历不同文件夹
		MediaData* pData = new MediaData();
		//获取当前文件夹对应的json数据
		rapidjson::Value& CurrentFile = doc[FilesName[i].c_str()];
		for (int j = 0; j < 3; j++) { //遍历不同文件类型中的资源
			//获取当前文件名对应的资源数组
			rapidjson::Value& vResType = CurrentFile[ResType[j].c_str()];
			for (int m = 0; m < vResType.Size(); m++) {
				string str = vResType[m].GetString();
				//根据资源类型将路径添加到不同的容器中
				if ("png" == ResType[j]) {
					pData->VecPng.push_back(str);
				}
				else if ("plist" == ResType[j]) {
					pData->VecPlist.push_back(str);
				}
				else if ("audio" == ResType[j]) {
					pData->VecAudio.push_back(str);
				}
			}
		}
		DataMap.insert(pair<string, MediaData*>(FilesName[i], pData));
	}
}

//获取指定名称对应的MediaData
MediaData* MediaManager::getData(string strKey)
{
	map<string, MediaData*>::iterator iter = DataMap.find(strKey);
	if (iter == DataMap.end())
	{
		return nullptr;
	}
	return iter->second;
}
