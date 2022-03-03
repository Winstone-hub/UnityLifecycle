#pragma once
#include "Headers.h"

class ScreenManager
{
private:
	static ScreenManager* Instance;
public:
	static ScreenManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ScreenManager;
		return Instance;
	}

public:
	void SetCursorPosition(float _x, float _y, float _z = 0.0f)
	{
		COORD Pos = { (SHORT)_x, (SHORT)_y };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

	void SetCursorPosition(Vector3 _CursorPos)
	{
		COORD Pos = { (SHORT)_CursorPos.x, (SHORT)_CursorPos.y };
		
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

private:
	ScreenManager();
public:
	~ScreenManager();
};

