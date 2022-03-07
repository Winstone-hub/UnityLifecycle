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
	for (vector<GameObject*>::iterator iter = m_pObjects[FRAMEID_THIRD]->begin();
		iter != m_pObjects[FRAMEID_THIRD]->end(); ++iter)
	{
		if (CollisionManager::Collision(m_pPlayer, (*iter)))
		{
			DoubleBuffer::GetInstance()->WriteBuffer(1.0f, 1.0f, (char*)"�浹�Դϴ�.");
		}

		for (vector<GameObject*>::iterator iter2 = m_pObjects[FRAMEID_SECOND]->begin();
			iter2 != m_pObjects[FRAMEID_SECOND]->end(); ++iter2)
		{
			if (CollisionManager::Collision((*iter), (*iter2)))
			{
				DoubleBuffer::GetInstance()->WriteBuffer(1.0f, 1.0f, (char*)"BBBBBBBBBB �浹�Դϴ�.");
			}
		}
	}
}

void Stage::Update()
{
	m_pPlayer->Update();

	for (vector<GameObject*>::iterator iter = m_pObjects[FRAMEID_THIRD]->begin();
		iter != m_pObjects[FRAMEID_THIRD]->end(); ++iter)
		(*iter)->Update();

	for (vector<GameObject*>::iterator iter = m_pObjects[FRAMEID_SECOND]->begin();
		iter != m_pObjects[FRAMEID_SECOND]->end(); ++iter)
		(*iter)->Update();
}

void Stage::LateUpdate()
{
	if (GetAsyncKeyState('D'))
		SceneManager::GetInstance()->SetScene(SCENEID_EXIT);
}

void Stage::Render()
{
	m_pPlayer->Render();
	
	for (vector<GameObject*>::iterator iter = m_pObjects[FRAMEID_THIRD]->begin();
		iter != m_pObjects[FRAMEID_THIRD]->end(); ++iter)
		(*iter)->Render();

	for (vector<GameObject*>::iterator iter = m_pObjects[FRAMEID_SECOND]->begin();
		iter != m_pObjects[FRAMEID_SECOND]->end(); ++iter)
		(*iter)->Render();
}

void Stage::OnDestroy()
{
	SafeRelease(m_pPlayer);

	//for (vector<GameObject*>::iterator iter = m_pObjects->begin();
		//iter != m_pObjects->end(); ++iter)
		//SafeRelease((*iter));
}