#pragma once
#include "Headers.h"
#include "GameObject.h"

class MathManager
{
public:
	static Vector3 GetDirection(GameObject* _Origin, GameObject* _Target)
	{
		Vector3 OriginPos = _Origin->GetPosition();
		Vector3 TargetPos = _Target->GetPosition();

		float x = TargetPos.x - OriginPos.x;
		float y = TargetPos.y - OriginPos.y;

		// ** sqrt() = 루트 함수.
		float Distance = GetDistance(_Origin->GetTransform(), _Target->GetTransform());

		Vector3 Direction = Vector3(
			x / Distance,
			y / Distance);

		return Direction;
	}

	static float GetDistance(const Transform& _Origin, const Transform& _Target)
	{
		float x = _Target.Position.x - _Origin.Position.x;
		float y = _Target.Position.y - _Origin.Position.y;

		// ** sqrt() = 루트 함수.
		return sqrt((x * x) + (y * y));
	}
};

