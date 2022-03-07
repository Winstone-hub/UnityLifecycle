#include "ObjectManager.h"
#include "GameObject.h"
#include "MathManager.h"

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

GameObject* ObjectManager::GetTarget(GameObject* _Origin, string _Key)
{
	multimap<float, GameObject*> SortObject;

	vector<GameObject*>* pTargetList = GetObjectList(_Key);

	for (vector<GameObject*>::iterator iter = pTargetList->begin();
		iter != pTargetList->end(); ++iter)
	{
		float Distance = MathManager::GetDistance(_Origin->GetTransform(), (*iter)->GetTransform());

		SortObject.insert(make_pair(Distance, (*iter)));
	}

	return SortObject.begin()->second;
}


/*
void ObjectManager::Update()
{

}
*/