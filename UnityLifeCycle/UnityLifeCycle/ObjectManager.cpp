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

// ** _Origin ���� ���� ����� ������Ʈ�� ����.
GameObject* ObjectManager::GetTarget(GameObject* _Origin, string _Key)
{
	// ** multimap = Ű���� �ߺ� ������ (list�� ����� �����̳�)
	multimap<float, GameObject*> SortObject;

	// ** ������Ʈ ����Ʈ�� Ž���ϰ� �޾ƿ��� ��������
	// ** ����Ʈ����� �ִٸ� ����� ��ȯ �ϰ�
	vector<GameObject*>* pTargetList = GetObjectList(_Key);

	// ** ���ٸ� nullptr�� ��ȯ.
	if (pTargetList == nullptr)
		return nullptr;
	else
	{
		// ** ��� ����� Ȯ����
		for (vector<GameObject*>::iterator iter = pTargetList->begin();
			iter != pTargetList->end(); ++iter)
		{
			// ** �Ÿ��� ����
			float Distance = MathManager::GetDistance(_Origin->GetTransform(), (*iter)->GetTransform());

			// ** ���� �Ÿ��� Key������ �߰�. (�������� ����)
			SortObject.insert(make_pair(Distance, (*iter)));
		}

		// ** ���� ó���� �ִ� ���Ұ� ���� ����� �����̱⶧���� ó�� ������Ʈ�� ��ȯ.
		return SortObject.begin()->second;
	}
}

/*
void ObjectManager::Update()
{

}
*/