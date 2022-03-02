#include "Enemy.h"


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
	cout << "Enemy::Start" << endl;
}

void Enemy::FixedUpdate()
{
	cout << "Enemy::FixedUpdate" << endl;
}

void Enemy::Update()
{
	cout << "Enemy::Update" << endl;
}

void Enemy::LateUpdate()
{
	cout << "Enemy::LateUpdate" << endl;
}

void Enemy::Render()
{
	cout << "Enemy : " << m_iNumber << endl;
}

void Enemy::OnDestroy()
{
	cout << "Enemy::OnDestroy" << endl;
}

