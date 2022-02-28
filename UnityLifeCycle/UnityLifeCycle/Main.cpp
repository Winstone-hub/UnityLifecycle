#pragma once
#include "MainUpdate.h"




int main(void)
{
	ULONGLONG DeltaTime = 0;
	ULONGLONG OriginTime = GetTickCount64();
	ULONGLONG OldTime = GetTickCount64();

	// ** Create
	MainUpdate Main; 

	// ** Initialize
	Main.Awake();
	Main.Start();

	while (true)
	{
		system("cls");
		OldTime = GetTickCount64();

		if (OriginTime + DeltaTime < GetTickCount64())
		{
			OriginTime = GetTickCount64();

			// ** Physcis
			Main.FixedUpdate();
			//system("pause");
		}
		else
		{
			// ** Progress
			Main.Update();
			Main.LateUpdate();

			// ** Render
			Main.Render();
		}

		DeltaTime = 1000;// GetTickCount64() - OldTime;
	}

	// ** Release
	Main.OnDestroy();
	
	return 0;
}