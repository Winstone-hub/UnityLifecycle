#include "Player.h"
#include "ScreenManager.h"

Player::Player()
{
	Awake();
}

Player::~Player()
{

}


void Player::Awake()
{
	m_strKey = "Player";
}

void Player::Start()
{
	m_tInfo.Position = Vector3(0.0f, 0.0f, 0.0f);
	m_tInfo.Rotation = Vector3(0.0f, 0.0f, 0.0f);
	m_tInfo.Scale = Vector3(0.0f, 0.0f, 0.0f);

	m_strTexture = "¿Ê";
}

void Player::FixedUpdate()
{

}

void Player::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{
		--m_tInfo.Position.y;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		++m_tInfo.Position.y;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		--m_tInfo.Position.x;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		++m_tInfo.Position.x;
	}
}

void Player::LateUpdate()
{

}

void Player::Render()
{
	ScreenManager::GetInstance()->SetCursorPosition(m_tInfo.Position);
	cout << m_strTexture;
}

void Player::OnDestroy()
{

}

