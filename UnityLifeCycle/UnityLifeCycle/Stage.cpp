#include "Stage.h"
#include "SceneManager.h"
#include "Player.h"


Stage::Stage()
{
	Awake();
}

Stage::~Stage()
{

}


void Stage::Awake()
{
	m_pPlayer = new Player;
}

void Stage::Start()
{
	m_pPlayer->Start();
}

void Stage::FixedUpdate()
{
	m_pPlayer->FixedUpdate();
}

void Stage::Update()
{
	m_pPlayer->Update();
}

void Stage::LateUpdate()
{
	m_pPlayer->LateUpdate();


	if (GetAsyncKeyState('D'))
		SceneManager::GetInstance()->SetScene(SCENEID_EXIT);
}

void Stage::Render()
{
	m_pPlayer->Render();
}

void Stage::OnDestroy()
{
	m_pPlayer->OnDestroy();
	SafeRelease(m_pPlayer);
}