#pragma once
#include "Scene.h"

class GameObject;
class Stage : public Scene
{
private:
	map<FRAMEID, vector<GameObject*>*> m_pObjects;
	GameObject* m_pPlayer;
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

