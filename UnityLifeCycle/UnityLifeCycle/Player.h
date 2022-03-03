#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	virtual void Awake()override;
	virtual void Start()override;
	virtual void FixedUpdate()override;
	virtual void Update()override;
	virtual void LateUpdate()override;
	virtual void Render()override;
	virtual void OnDestroy()override;
public:
	Player();
	virtual ~Player();
};

