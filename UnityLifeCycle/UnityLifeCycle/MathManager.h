#pragma once
#include "Headers.h"
#include "GameObject.h"

class MathManager
{
public:
	// ** 방향을 구하는 함수.
	static Vector3 GetDirection(const Transform& _Origin, const Transform& _Target)
	{
		// ** 타겟과의 X, Y값을 구함.
		float x = _Target.Position.x - _Origin.Position.x;
		float y = _Target.Position.y - _Origin.Position.y;

		// ** sqrt() = 루트 함수.
		float Distance = sqrt((x * x) + (y * y));

		// ** 방향만 남김.
		Vector3 Direction = Vector3(
			x / Distance,
			y / Distance);

		return Direction;
	}

	// ** 거리를 구하는 함수
	static float GetDistance(const Transform& _Origin, const Transform& _Target)
	{
		// ** 타겟과의 X, Y값을 구함.
		float x = _Target.Position.x - _Origin.Position.x;
		float y = _Target.Position.y - _Origin.Position.y;

		// ** sqrt() = 루트 함수.
		return sqrt((x * x) + (y * y));
	}
};

