#include "ObjectManager.h"
#include "GameObject.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::AddObject(GameObject* _pObj)
{
	map<string, vector<GameObject*>>::iterator iter = m_pObjectList.find(_pObj->GetKey());

	if (iter == m_pObjectList.end())
	{
		vector<GameObject*> vecList;
		vecList.push_back(_pObj);
		m_pObjectList.insert(make_pair(_pObj->GetKey(), vecList));
	}
	else
		iter->second.push_back(_pObj);
}

void ObjectManager::Update()
{

}