#include "Player.h"


Player::Player()
{
	Awake();
}

Player::~Player()
{

}


void Player::Awake()
{
	cout << "Player::Awake" << endl;
}

void Player::Start()
{
	cout << "Player::Start" << endl;
}

void Player::FixedUpdate()
{
	cout << "Player::FixedUpdate" << endl;
}

void Player::Update()
{
	cout << "Player::Update" << endl;

}

void Player::LateUpdate()
{
	cout << "Player::LateUpdate" << endl;
}

void Player::Render()
{
	cout << "Player::Render" << endl;
}

void Player::OnDestroy()
{
	cout << "Player::OnDestroy" << endl;
}

