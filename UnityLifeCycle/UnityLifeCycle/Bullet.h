#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
private:
	DIRENTIONID Direction;
	GameObject* Target;
public:
	virtual void Awake()override;
	virtual void Start()override;
	virtual void FixedUpdate()override;
	virtual void Update()override;
	virtual void LateUpdate()override;
	virtual void Render()override;
	virtual void OnDestroy()override;
public:
	void SetTarget(GameObject* _Target) { Target = _Target; }
public:
	Bullet();
	virtual ~Bullet();
};
