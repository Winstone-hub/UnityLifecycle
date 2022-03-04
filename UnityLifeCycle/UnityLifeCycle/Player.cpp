#include "Player.h"
#include "DoubleBuffer.h"

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
	m_tInfo.Scale = Vector3(3.0f, 1.0f, 0.0f);

	m_strTexture = "��";
	Texture = (char*)"��/";
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

	if (GetAsyncKeyState(VK_SPACE))
	{
		Texture = (char*)"�ʤ�";
		m_tInfo.Scale.x = 4.0f;
	}
	else
	{
		Texture = (char*)"��/";
		m_tInfo.Scale.x = 3.0f;
	}

}

void Player::LateUpdate()
{

}

void Player::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		m_tInfo.Position.x,
		m_tInfo.Position.y,
		Texture);
}

void Player::OnDestroy()
{

}

