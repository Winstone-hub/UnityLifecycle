#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform m_tInfo;
	string m_strKey;
	int m_iNumber;
public:
	virtual void Awake()PURE;
	virtual void Start()PURE;
	virtual void FixedUpdate()PURE;
	virtual void Update()PURE;
	virtual void LateUpdate()PURE;
	virtual void Render()PURE;
	virtual void OnDestroy()PURE;
public:
	string GetKey() { return m_strKey; }

	int GetNumber() { return m_iNumber; }
	void SetNumber(int _inum) { m_iNumber = _inum; }

	Vector3 GetPosition() { return m_tInfo.Position; }
	void SetPosition(Vector3 _Position) { m_tInfo.Position = _Position; }

	Vector3 GetRotation() { return m_tInfo.Rotation; }
	void SetRotation(Vector3 _Rotation) { m_tInfo.Rotation = _Rotation; }
	
	Vector3 GetScale() { return m_tInfo.Scale; }
	void SetScale(Vector3 _Scale) { m_tInfo.Scale = _Scale; }
	
	Transform GetTransform() { return m_tInfo; }
	void SetTransform(Transform _Info)  { m_tInfo = _Info; }
public:
	Object();
	virtual ~Object();
};
