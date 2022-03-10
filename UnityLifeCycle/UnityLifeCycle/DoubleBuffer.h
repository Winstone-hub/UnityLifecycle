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
	HANDLE hBuffer[2];
	int BufferIndex;
public:
	void Start();
	void CreateBuffer(const int& _Width, const int& _Height);
	void WriteBuffer(const float& _x, const float& _y, char* _str, DWORD _Color = Èò»ö);
	void FlippingBuffer();
	void ClearBuffer();
	void DestoryBuffer();
private:
	DoubleBuffer();
public:
	~DoubleBuffer();
};

