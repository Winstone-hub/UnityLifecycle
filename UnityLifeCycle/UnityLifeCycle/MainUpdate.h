#pragma once
#include "Headers.h"

class Object;
class MainUpdate
{
private:
	Object* m_pPlayer;
public:
	void Awake();
	void Start();


	void FixedUpdate();

	void Update();
	void LateUpdate();

	void Render();
	void OnDestroy();
public:
	MainUpdate();
	~MainUpdate();
};
