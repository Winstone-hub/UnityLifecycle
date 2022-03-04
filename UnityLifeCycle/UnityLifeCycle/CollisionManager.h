#pragma once
#include "GameObject.h"

class CollisionManager
{
public:
	static bool Collision(GameObject* _Origin, GameObject* _Target)
	{
		Vector3 OriginPos = _Origin->GetPosition();
		Vector3 TargetPos = _Target->GetPosition();

		Vector3 OriginScale = _Origin->GetScale();
		Vector3 TargetScale = _Target->GetScale();

		if ((OriginPos.x + OriginScale.x) > TargetPos.x &&
			(TargetPos.x + TargetScale.x) > OriginPos.x &&
			OriginPos.y == TargetPos.y)
			return true;
		return false;
	}
};

