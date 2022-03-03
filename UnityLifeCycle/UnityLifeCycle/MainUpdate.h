#pragma once
#include "Headers.h"

class MainUpdate
{
public:
	void Awake();
	void FixedUpdate();

	void Update();
	void LateUpdate();

	void Render();
	void OnDestroy();
public:
	MainUpdate();
	~MainUpdate();
};
