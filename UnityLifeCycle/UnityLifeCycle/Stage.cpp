#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

#include "Player.h"
#include "Enemy.h"


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
		Vector3 Pos = Vector3(float(rand()%100), float(rand() % 26));
		GameObject* pEnemy = ObjectFactory<Enemy>::CreateObject(Pos);

		ObjectManager::GetInstance()->AddObject(pEnemy);
	}
}

void Stage::Start()
{
	m_pObjects = ObjectManager::GetInstance()->GetObjectList("Enemy");

	m_pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
}

void Stage::FixedUpdate()
{

}

void Stage::Update()
{
	m_pPlayer->Update();

	for (vector<GameObject*>::iterator iter = m_pObjects->begin();
		iter != m_pObjects->end(); ++iter)
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

	for (vector<GameObject*>::iterator iter = m_pObjects->begin();
		iter != m_pObjects->end(); ++iter)
		(*iter)->Render();
}

void Stage::OnDestroy()
{
	SafeRelease(m_pPlayer);

	for (vector<GameObject*>::iterator iter = m_pObjects->begin();
		iter != m_pObjects->end(); ++iter)
		SafeRelease((*iter));
}