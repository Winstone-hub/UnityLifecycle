#include "Bullet.h"
#include "DoubleBuffer.h"


Bullet::Bullet() : Target(nullptr)
{
	Awake();
}

Bullet::~Bullet()
{

}

void Bullet::Awake()
{
	m_strKey = "Bullet";
}

void Bullet::Start()
{
	m_tInfo.Position = Vector3(0.0f, 0.0f, 0.0f);
	m_tInfo.Rotation = Vector3(0.0f, 0.0f, 0.0f);
	m_tInfo.Scale = Vector3(2.0f, 1.0f, 0.0f);

	//m_strTexture = "¡Ú";
	Texture = (char*)"¡Ú";
}

void Bullet::FixedUpdate()
{

}

void Bullet::Update()
{

}

void Bullet::LateUpdate()
{

}

void Bullet::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		m_tInfo.Position.x,
		m_tInfo.Position.y,
		Texture);
}

void Bullet::OnDestroy()
{

}