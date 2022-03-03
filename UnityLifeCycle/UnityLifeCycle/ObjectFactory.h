#pragma once
#include "Player.h"
#include "Enemy.h"


template <typename T>
class ObjectFactory
{
public:
	static GameObject* CreateObject()
	{
		GameObject* Obj = new T;
		Obj->Start();

		return Obj;
	}

	static GameObject* CreateObject(Vector3 _Position)
	{
		GameObject* Obj = new T;

		Obj->Start();
		Obj->SetPosition(_Position);

		return Obj;
	}

	static GameObject* CreateObject(Vector3 _Position, Vector3 _Rotation)
	{
		GameObject* Obj = new T;

		Obj->Start();
		Obj->SetPosition(_Position);
		Obj->SetRotation(_Rotation);

		return Obj;
	}

	static GameObject* CreateObject(Transform _Info)
	{
		GameObject* Obj = new T;

		Obj->Start();
		Obj->SetTransform(_Info);

		return Obj;
	}
};