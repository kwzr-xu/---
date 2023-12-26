#include"MediaManager.h"
CResDtMgr* CResDtMgr::m_pInstance = nullptr;
CResDtMgr::CResDtMgr()
{
}

CResDtMgr::~CResDtMgr()
{
	for (map<string, SResDt*>::iterator iter = m_MapData.begin(); iter != m_MapData.end(); ++iter) {
		SResDt* pData = iter->second;
		CC_SAFE_DELETE(pData);
	}
	m_MapData.clear();
}

CResDtMgr* CResDtMgr::getInstance()
{
	if (!m_pInstance) {
		m_pInstance = new CResDtMgr();
		m_pInstance->loadFile("Config/MediaData.json");
	}
	return m_pInstance;
}

void CResDtMgr::loadFile(const string& strPath)
{
	//获取参数路径的完整路径和内容
	string strFullPath = FileUtils::getInstance()->fullPathForFilename(strPath);
	string strData = FileUtils::getInstance()->getStringFromFile(strFullPath);

	Document doc;
	doc.Parse(strData.c_str());

	string SceneResName[FilesNumber] = { "MainScene" }; //文件名数组
	string ResType[3] = { "png","plist","audio" }; //资源类型数组
	for (int i = 0; i < FilesNumber; i++) { //遍历不同文件夹
		SResDt* pData = new SResDt();
		//获取当前文件夹对应的json数据
		rapidjson::Value& CurrentFile = doc[SceneResName[i].c_str()];
		for (int j = 0; j < 3; j++) { //遍历不同文件类型中的资源
			//获取当前文件名对应的资源数组
			rapidjson::Value& vResType = CurrentFile[ResType[j].c_str()];
			for (int m = 0; m < vResType.Size(); m++) {
				string str = vResType[m].GetString();
				//根据资源类型将路径添加到不同的容器中
				if ("png" == ResType[j]) {
					pData->m_VecPng.push_back(str);
				}
				else if ("plist" == ResType[j]) {
					pData->m_VecPlist.push_back(str);
				}
				else if ("audio" == ResType[j]) {
					pData->m_VecAudio.push_back(str);
				}
			}
		}
		m_MapData.insert(pair<string, SResDt*>(SceneResName[i], pData));
	}
}

//获取指定名称对应的MediaData
SResDt* CResDtMgr::getData(string strKey)
{
	map<string, SResDt*>::iterator iter = m_MapData.find(strKey);
	if (iter == m_MapData.end())
	{
		return nullptr;
	}
	return iter->second;
}

