#pragma once
#include "Scene.h"


class Object;
class Stage : public Scene
{
private:
	Object* m_pPlayer;
public:
	virtual void Awake()override;
	virtual void Start()override;
	virtual void FixedUpdate()override;
	virtual void Update()override;
	virtual void LateUpdate()override;
	virtual void Render()override;
	virtual void OnDestroy()override;
public:
	Stage();
	virtual ~Stage();
};

