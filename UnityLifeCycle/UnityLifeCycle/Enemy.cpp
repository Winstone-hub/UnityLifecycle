#include "Enemy.h"
#include "DoubleBuffer.h"

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
	m_tInfo.Scale = Vector3(1.0f, 1.0f, 0.0f);

	//m_strTexture = "E";
	Texture = (char*)"E";
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
	DoubleBuffer::GetInstance()->WriteBuffer(
		m_tInfo.Position.x,
		m_tInfo.Position.y,
		Texture);
}

void Enemy::OnDestroy()
{

}
