#include "DataBase.h"

// ���캯��
CDataController::CDataController() {
}

// ��������
CDataController::~CDataController() {
}

// �Ӹ���·�������ļ�
void CDataController::loadFile(const string& strPath) {
    // ��ȡȫ·��
    string strFullPath = FileUtils::getInstance()->fullPathForFilename(strPath);
    // ��ȡ�ļ���Ϣ
    string strData = FileUtils::getInstance()->getStringFromFile(strFullPath);

    Document doc;
    doc.Parse(strData.c_str());

    this->parse(doc);

    doc.Clear();
}

// ͨ�� ID ��ȡ����
SData* CDataController::getDataByID(int nID) {
    for (SData* pData : m_VecData) {
        if (pData->nID == nID) {
            return pData;
        }
    }
    return nullptr;
}

// ͨ��������ȡ����
SData* CDataController::getDataByIndex(int nIndex) {
    if (nIndex < 0 || nIndex >= m_VecData.size()) {
        return nullptr;
    }
    return m_VecData[nIndex];
}

// ��ȡ��������
vector<SData*> CDataController::getAllData() {
    return m_VecData;
}

// ��ȡ���ݵ�����
int CDataController::getSize() {
    return m_VecData.size();
}
