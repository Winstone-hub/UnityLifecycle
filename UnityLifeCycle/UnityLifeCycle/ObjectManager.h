#pragma once
#include "Headers.h"

class Object;
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
	map<string, vector<Object*>> m_pObjectList;
public:
	void AddObject(Object* _pObj);

public:
	vector<Object*>* GetObjectList(string _Key)
	{
		map<string, vector<Object*>>::iterator iter = m_pObjectList.find(_Key);

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

