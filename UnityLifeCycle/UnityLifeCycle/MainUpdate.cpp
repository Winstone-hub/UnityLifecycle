#include "MainUpdate.h"
#include "SceneManager.h"


MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{

}


void MainUpdate::Awake()
{
	SceneManager::GetInstance()->SetScene(SCENEID_LOGO);
}

void MainUpdate::FixedUpdate()
{
	SceneManager::GetInstance()->FixedUpdate();
}

void MainUpdate::Update()
{
	SceneManager::GetInstance()->Update();
}

void MainUpdate::LateUpdate()
{
	SceneManager::GetInstance()->LateUpdate();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::OnDestroy()
{
	SceneManager::GetInstance()->OnDestroy();
}

