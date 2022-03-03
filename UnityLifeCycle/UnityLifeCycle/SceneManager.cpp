#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr)
{
}

SceneManager::~SceneManager()
{
	OnDestroy();
}

void SceneManager::SetScene(SCENEID _SceneState)
{
	SafeRelease(SceneState);

	switch (_SceneState)
	{
	case SCENEID_LOGO:
		SceneState = new Logo;
		break;

	case SCENEID_MENU:
		SceneState = new Menu;
		break;

	case SCENEID_STAGE:
		SceneState = new Stage;
		break;

	case SCENEID_EXIT:
		exit(NULL);
		break;

	default:
		break;
	}

	/*
	 * ������ ������ �ִٴ� ���� ������.
	 * 
	 * Awake �Լ��� ���� 1ȸ�� ���� �Ǿ�������� ���� �� ���渶�� �����.
	 */ 
	SceneState->Awake();

	SceneState->Start();
}

void SceneManager::Start()
{
	SceneState->Start();
}

void SceneManager::FixedUpdate()
{
	SceneState->FixedUpdate();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::LateUpdate()
{
	SceneState->LateUpdate();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::OnDestroy()
{
	SafeRelease(SceneState);
}
