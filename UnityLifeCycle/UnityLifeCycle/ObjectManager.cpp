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

// ** _Origin 과의 가장 가까운 오브젝트를 구함.
GameObject* ObjectManager::GetTarget(GameObject* _Origin, string _Key)
{
	// ** multimap = 키값이 중복 가능함 (list와 비슷한 컨테이너)
	multimap<float, GameObject*> SortObject;

	// ** 오브젝트 리스트를 탐색하고 받아오는 과정에서
	// ** 리스트목록이 있다면 목록을 반환 하고
	vector<GameObject*>* pTargetList = GetObjectList(_Key);

	// ** 없다면 nullptr을 반환.
	if (pTargetList == nullptr)
		return nullptr;
	else
	{
		// ** 모든 목록을 확인함
		for (vector<GameObject*>::iterator iter = pTargetList->begin();
			iter != pTargetList->end(); ++iter)
		{
			// ** 거리를 구함
			float Distance = MathManager::GetDistance(_Origin->GetTransform(), (*iter)->GetTransform());

			// ** 구한 거리를 Key값으로 추가. (오름차순 정렬)
			SortObject.insert(make_pair(Distance, (*iter)));
		}

		// ** 가장 처음에 있는 원소가 가장 가까운 원소이기때문에 처음 오브젝트를 반환.
		return SortObject.begin()->second;
	}
}

/*
void ObjectManager::Update()
{

}
*/