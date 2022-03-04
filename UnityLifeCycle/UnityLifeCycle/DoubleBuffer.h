#pragma once
#include "Headers.h"

class DoubleBuffer
{
private:
	static DoubleBuffer* Instance;
public:
	static DoubleBuffer* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new DoubleBuffer;
		return Instance;
	}

private:
	DoubleBuffer();
public:
	~DoubleBuffer();
};

