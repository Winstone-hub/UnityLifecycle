#pragma once
#include "Headers.h"

class GameObject;
class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;
		return Instance;
	}
private:
	map<string, vector<GameObject*>> m_pObjectList;
public:
	void AddObject(GameObject* _pObj);
public:
	vector<GameObject*>* GetObjectList(string _Key)
	{
		map<string, vector<GameObject*>>::iterator iter = m_pObjectList.find(_Key);

		if (iter == m_pObjectList.end())
			return nullptr;
		else
			return &iter->second;
	}

	void Update();

	/*
	void Start();
	void FixedUpdate();
	void LateUpdate();
	void Render();
	void OnDestroy();
	*/
private:
	ObjectManager();
public:
	~ObjectManager();
};

