#pragma once
#include "MainUpdate.h"

/*
* 타이머 매니저 생성 해야함.
* 생성 하면서 deltatime, FixedUpdate 수정
* while 로직 수정.
* (현재 FixedUpdate 실행 시간과 Update 함수의 실행 시간이 실제 Unity 로직과 맞지 않음.)
*/
int main(void)
{
	ULONGLONG DeltaTime = 25;
	ULONGLONG OriginTime = GetTickCount64();
	ULONGLONG OldTime = GetTickCount64();

	// ** Create
	MainUpdate Main; 

	// ** Initialize
	Main.Awake();

	while (true)
	{
		if (OriginTime + DeltaTime < GetTickCount64())
		{
			OriginTime = GetTickCount64();
			system("cls");

			// ** Physcis
			Main.FixedUpdate();

			// ** Progress
			Main.Update();
			Main.LateUpdate();

			// ** Render
			Main.Render();
		}
	}


	// ** Release
	Main.OnDestroy();
	
	return 0;
}