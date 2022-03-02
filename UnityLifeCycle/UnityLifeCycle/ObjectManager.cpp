#include "ObjectManager.h"
#include "Object.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::AddObject(Object* _pObj)
{
	map<string, vector<Object*>>::iterator iter = 
		m_pObjectList.find(_pObj->GetKey());

	if (iter == m_pObjectList.end())
	{
		vector<Object*> vecList;
		vecList.push_back(_pObj);
		m_pObjectList.insert(make_pair(_pObj->GetKey(), vecList));
	}
	else
		iter->second.push_back(_pObj);
}

void ObjectManager::Update()
{

}