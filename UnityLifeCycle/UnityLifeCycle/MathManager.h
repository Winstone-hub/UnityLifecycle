#pragma once
#include "Headers.h"
#include "GameObject.h"

class MathManager
{
public:
	// ** ������ ���ϴ� �Լ�.
	static Vector3 GetDirection(const Transform& _Origin, const Transform& _Target)
	{
		// ** Ÿ�ٰ��� X, Y���� ����.
		float x = _Target.Position.x - _Origin.Position.x;
		float y = _Target.Position.y - _Origin.Position.y;

		// ** sqrt() = ��Ʈ �Լ�.
		float Distance = sqrt((x * x) + (y * y));

		// ** ���⸸ ����.
		Vector3 Direction = Vector3(
			x / Distance,
			y / Distance);

		return Direction;
	}

	// ** �Ÿ��� ���ϴ� �Լ�
	static float GetDistance(const Transform& _Origin, const Transform& _Target)
	{
		// ** Ÿ�ٰ��� X, Y���� ����.
		float x = _Target.Position.x - _Origin.Position.x;
		float y = _Target.Position.y - _Origin.Position.y;

		// ** sqrt() = ��Ʈ �Լ�.
		return sqrt((x * x) + (y * y));
	}
};

