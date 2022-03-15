#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"
#include "DoubleBuffer.h"

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"


Stage::Stage()
{

}

Stage::~Stage()
{

}

void Stage::Awake()
{
	GameObject* pPlayer = ObjectFactory<Player>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pPlayer);

	for (int i = 0; i < 1; ++i)
	{
		srand(UINT(GetTickCount64() * (i + 1)));
		Vector3 Pos = Vector3(float(rand() % 100), float(rand() % 26));
		GameObject* pEnemy = ObjectFactory<Enemy>::CreateObject(Pos);

		ObjectManager::GetInstance()->AddObject(pEnemy);
	}
	
	for (int i = 0; i < 1; ++i)
	{
		GameObject* pBullet = ObjectFactory<Bullet>::CreateObject(
			pPlayer->GetPosition());

		GameObject* Target = ObjectManager::GetInstance()->GetTarget(pPlayer, "Enemy");
		((Bullet*)pBullet)->SetTarget(Target);

		ObjectManager::GetInstance()->AddObject(pBullet);
	}
}

void Stage::Start()
{
	m_pObjects[FRAMEID_THIRD] = ObjectManager::GetInstance()->GetObjectList("Enemy");
	m_pObjects[FRAMEID_SECOND] = ObjectManager::GetInstance()->GetObjectList("Bullet");

	m_pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
}

void Stage::FixedUpdate()
{
/*
	for (vector<GameObject*>::iterator iter = m_pObjects[FRAMEID_THIRD]->begin();
		iter != m_pObjects[FRAMEID_THIRD]->end(); ++iter)
	{
		if (CollisionManager::Collision(m_pPlayer, (*iter)))
		{
			DoubleBuffer::GetInstance()->WriteBuffer(1.0f, 1.0f, (char*)"충돌입니다.");
		}

		for (vector<GameObject*>::iterator iter2 = m_pObjects[FRAMEID_SECOND]->begin();
			iter2 != m_pObjects[FRAMEID_SECOND]->end(); ++iter2)
		{
			if (CollisionManager::Collision((*iter), (*iter2)))
			{
				DoubleBuffer::GetInstance()->WriteBuffer(1.0f, 1.0f, (char*)"충돌입니다.");
			}
		}
	}
		*/
}

void Stage::Update()
{
	m_pPlayer->Update();

	for (map<FRAMEID, vector<GameObject*>*>::iterator iter = m_pObjects.begin();
		iter != m_pObjects.end(); ++iter)
	{
		if(iter->second != nullptr)
		for (vector<GameObject*>::iterator iter2 = iter->second->begin();
			iter2 != iter->second->end(); ++iter2)
		{
			(*iter2)->Update();
		}
	}
}

void Stage::LateUpdate()
{
	if (GetAsyncKeyState('D'))
		SceneManager::GetInstance()->SetScene(SCENEID_EXIT);
}

void Stage::Render()
{
	m_pPlayer->Render();

	// ** 숙제
	// iter->second == vector<GameObject*>*
	for (map<FRAMEID, vector<GameObject*>*>::iterator iter = m_pObjects.begin();
		iter != m_pObjects.end(); ++iter)
	{
		if(iter->second != nullptr)
			for (vector<GameObject*>::iterator iter2 = iter->second->begin();
				iter2 != iter->second->end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}
}

void Stage::OnDestroy()
{
	SafeRelease(m_pPlayer);

	for (map<FRAMEID, vector<GameObject*>*>::iterator iter = m_pObjects.begin();
		iter != m_pObjects.end(); ++iter)
	{
		for (vector<GameObject*>::iterator iter2 = iter->second->begin();
			iter2 != iter->second->end(); ++iter2)
		{
			SafeRelease((*iter2));
		}
		iter->second->clear();
	}
	m_pObjects.clear();
}