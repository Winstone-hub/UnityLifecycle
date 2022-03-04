#include "Logo.h"
#include "SceneManager.h"

Logo::Logo()
{
	Awake();
}

Logo::~Logo()
{

}


void Logo::Awake()
{

}

void Logo::Start()
{

}

void Logo::FixedUpdate()
{

}

void Logo::Update()
{

}

void Logo::LateUpdate()
{
	if (GetAsyncKeyState('A'))
		SceneManager::GetInstance()->SetScene(SCENEID_MENU);
}

void Logo::Render()
{

}

void Logo::OnDestroy()
{

}