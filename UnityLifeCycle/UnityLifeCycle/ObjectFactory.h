#pragma once
#include "Player.h"
#include "Enemy.h"



template <typename T>
class ObjectFactory
{
public:
	static Object* CreateObject()
	{
		Object* Obj = new T;
		//Obj->Awake();

		return Obj;
	}

	static Object* CreateObject(Vector3 _Position)
	{
		Object* Obj = new T;

		//Obj->Awake();

		Obj->SetPosition(_Position);

		return Obj;
	}

	static Object* CreateObject(Vector3 _Position, Vector3 _Rotation)
	{
		Object* Obj = new T;

		//Obj->Awake();

		Obj->SetPosition(_Position);
		Obj->SetRotation(_Rotation);

		return Obj;
	}

	static Object* CreateObject(Transform _Info)
	{
		Object* Obj = new T;

		//Obj->Awake();

		Obj->SetTransform(_Info);

		return Obj;
	}
};