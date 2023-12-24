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

//�������ֲ��Ҳ���ȡ����
CDataController* ConfigManager::getData(string strName)
{
	if (strName.empty()) {
		return nullptr;
	}
	map<string, CDataController*>::iterator iter = DataMap.find(strName);
	return iter->second;
}

//��������
void ConfigManager::setData(string strName, CDataController* pDataController)
{
	//�������ò�������
	if (!pDataController || strName.empty()) {
		return;
	}
	DataMap.insert(pair<string, CDataController*>(strName, pDataController));
}
