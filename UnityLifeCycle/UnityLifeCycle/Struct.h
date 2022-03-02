#pragma once


typedef struct tagVector3
{
	float x, y, z;

}Vector3;

typedef struct tagTransform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;

}Transform;