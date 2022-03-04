#pragma once
#include "MainUpdate.h"

/*
* Ÿ�̸� �Ŵ��� ���� �ؾ���.
* ���� �ϸ鼭 deltatime, FixedUpdate ����
* while ���� ����.
* (���� FixedUpdate ���� �ð��� Update �Լ��� ���� �ð��� ���� Unity ������ ���� ����.)
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