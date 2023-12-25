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
	if (!pInstance) {//��Ϊ���򴴽��������ļ�
		pInstance = new MediaManager();
		pInstance->loadFile("Config/MediaData.json");
	}
	return pInstance;
}

void MediaManager::loadFile(const string& strPath)
{
	//��ȡ����·��������·��������
	string strFullPath = FileUtils::getInstance()->fullPathForFilename(strPath);
	string strData = FileUtils::getInstance()->getStringFromFile(strFullPath);

	Document doc;
	doc.Parse(strData.c_str());

	string FilesName[FilesNumber] = { "MainScene" }; //�ļ�������
	string ResType[3] = { "png","plist","audio" }; //��Դ��������
	for (int i = 0; i < FilesNumber; i++) { //������ͬ�ļ���
		MediaData* pData = new MediaData();
		//��ȡ��ǰ�ļ��ж�Ӧ��json����
		rapidjson::Value& CurrentFile = doc[FilesName[i].c_str()];
		for (int j = 0; j < 3; j++) { //������ͬ�ļ������е���Դ
			//��ȡ��ǰ�ļ�����Ӧ����Դ����
			rapidjson::Value& vResType = CurrentFile[ResType[j].c_str()];
			for (int m = 0; m < vResType.Size(); m++) {
				string str = vResType[m].GetString();
				//������Դ���ͽ�·����ӵ���ͬ��������
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

//��ȡָ�����ƶ�Ӧ��MediaData
MediaData* MediaManager::getData(string strKey)
{
	map<string, MediaData*>::iterator iter = DataMap.find(strKey);
	if (iter == DataMap.end())
	{
		return nullptr;
	}
	return iter->second;
}
