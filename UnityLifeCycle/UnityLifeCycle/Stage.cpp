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
	Object* pPlayer = ObjectFactory<Player>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pPlayer);

	for (int i = 0; i < 10; ++i)
	{
		Object* pEnemy = ObjectFactory<Enemy>::CreateObject();
		pEnemy->SetNumber(i);

		ObjectManager::GetInstance()->AddObject(pEnemy);
	}
}

void Stage::Start()
{
	m_pObjects = ObjectManager::GetInstance()->GetObjectList("Enemy");
}

void Stage::FixedUpdate()
{

}

void Stage::Update()
{

}

void Stage::LateUpdate()
{
	if (GetAsyncKeyState('D'))
		SceneManager::GetInstance()->SetScene(SCENEID_EXIT);
}

void Stage::Render()
{
	for (vector<Object*>::iterator iter = m_pObjects->begin();
		iter != m_pObjects->end(); ++iter)
		(*iter)->Render();
}

void Stage::OnDestroy()
{

}