#include "Enemy.h"
#include "ScreenManager.h"

Enemy::Enemy()
{
	Awake();
}

Enemy::~Enemy()
{

}

void Enemy::Awake()
{
	m_strKey = "Enemy";
}

void Enemy::Start()
{
	m_tInfo.Position = Vector3(0.0f, 0.0f, 0.0f);
	m_tInfo.Rotation = Vector3(0.0f, 0.0f, 0.0f);
	m_tInfo.Scale = Vector3(0.0f, 0.0f, 0.0f);

	m_strTexture = "Ȫ";
}

void Enemy::FixedUpdate()
{

}

void Enemy::Update()
{

}

void Enemy::LateUpdate()
{

}

void Enemy::Render()
{
	ScreenManager::GetInstance()->SetCursorPosition(m_tInfo.Position);
	cout << m_strTexture;
}

void Enemy::OnDestroy()
{

}
