#include "MainUpdate.h"
#include "Player.h"


MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{

}


void MainUpdate::Awake()
{
	m_pPlayer = new Player;
}

void MainUpdate::Start()
{
	m_pPlayer->Start();
}

void MainUpdate::FixedUpdate()
{
	m_pPlayer->FixedUpdate();
}

void MainUpdate::Update()
{
	m_pPlayer->Update();
}

void MainUpdate::LateUpdate()
{
	m_pPlayer->LateUpdate();
}

void MainUpdate::Render()
{
	m_pPlayer->Render();
}

void MainUpdate::OnDestroy()
{
	m_pPlayer->OnDestroy();
}

