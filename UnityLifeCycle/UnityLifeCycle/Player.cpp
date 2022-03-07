#include "Player.h"
#include "DoubleBuffer.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "Bullet.h"

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

	Direction = DIRID_NONE;

	//m_strTexture = "¿Ê";
	Texture = (char*)"¿Ê/";
	Check = false;
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
		Direction = DIRID_LEFT;
		OldX = m_tInfo.Position.x;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		++m_tInfo.Position.x;
		Direction = DIRID_RIGHT;
		OldX = m_tInfo.Position.x;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		// ** ÃÑ¾Ë »ý¼º
		GameObject* pBullet = ObjectFactory<Bullet>::CreateObject(m_tInfo.Position);

		// ** Å¸°Ù ¼³Á¤ : Å¸°ÙÀÌ ¾øÀ¸¸é nullptr
		GameObject* Target = ObjectManager::GetInstance()->GetTarget(this, "Enemy");
		((Bullet*)pBullet)->SetTarget(Target);
		
		// ** ¿ÀºêÁ§Æ® ¸®½ºÆ®¿¡ Ãß°¡
		ObjectManager::GetInstance()->AddObject(pBullet);
	}

	if (GetAsyncKeyState('T'))
	{
		//DoubleBuffer::GetInstance()->WriteBuffer(48, 1, (char*)"<Enemy>");
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

