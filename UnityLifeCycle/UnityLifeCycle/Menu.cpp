#include "Menu.h"
#include "SceneManager.h"

Menu::Menu()
{
	Awake();
}

Menu::~Menu()
{

}


void Menu::Awake()
{

}

void Menu::Start()
{

}

void Menu::FixedUpdate()
{

}

void Menu::Update()
{
	cout << "Menu::Update" << endl;
}

void Menu::LateUpdate()
{
	if (GetAsyncKeyState('S'))
		SceneManager::GetInstance()->SetScene(SCENEID_STAGE);
}

void Menu::Render()
{
	cout << "Menu::Render" << endl;
}

void Menu::OnDestroy()
{

}