#include "MainUpdate.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"


MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{

}


void MainUpdate::Awake()
{
	DoubleBuffer::GetInstance()->Start();
	DoubleBuffer::GetInstance()->CreateBuffer(WIDTHSIZE, HEIGHTSIZE);

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
	DoubleBuffer::GetInstance()->FlippingBuffer();
	DoubleBuffer::GetInstance()->ClearBuffer();
}

void MainUpdate::OnDestroy()
{
	SceneManager::GetInstance()->OnDestroy();
}

