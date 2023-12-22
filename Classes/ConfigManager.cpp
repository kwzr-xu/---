#include"ConfigManager.h"
ConfigManager* ConfigManager::pInstance = nullptr;

ConfigManager* ConfigManager::getInstance()
{
	if (!pInstance)
	{
		pInstance = new ConfigManager();
	}
	return pInstance;
}

//根据名字查找并获取数据
CDataController* ConfigManager::getData(string strName)
{
	if (strName.empty()) {
		return nullptr;
	}
	map<string, CDataController*>::iterator itor = DataMap.find(strName);
	return itor->second;
}

//设置数据
void ConfigManager::setData(string strName, CDataController* pDataController)
{
	//查找所用参数出错
	if (!pDataController || strName.empty()) {
		return;
	}
	DataMap.insert(pair<string, CDataController*>(strName, pDataController));
}
