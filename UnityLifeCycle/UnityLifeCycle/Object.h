#pragma once
#include "Headers.h"

class Object
{
public:
	virtual void Awake()PURE;
	virtual void Start()PURE;
	virtual void FixedUpdate()PURE;
	virtual void Update()PURE;
	virtual void LateUpdate()PURE;
	virtual void Render()PURE;
	virtual void OnDestroy()PURE;
public:
	Object();
	virtual ~Object();
};
