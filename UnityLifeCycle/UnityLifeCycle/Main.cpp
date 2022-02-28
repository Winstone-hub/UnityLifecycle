#include "MainUpdate.h"



int main(void)
{
	ULONGLONG OldTime = GetTickCount64();
	ULONGLONG DeltaTime = 0;

	// ** Create
	MainUpdate Main; 

	// ** Initialize
	Main.Awake();
	Main.Start();

	while (true)
	{
		OldTime = GetTickCount64();

		// ** Physcis
		Main.FixedUpdate();

		// ** Progress
		Main.Update();
		Main.LateUpdate();

		// ** Render
		Main.Render();

		DeltaTime = GetTickCount64() - OldTime;

		cout << (float)DeltaTime / 1000.f << endl;

		system("pause");

		if (GetAsyncKeyState(VK_RETURN))
			break;
	}

	// ** Release
	Main.OnDestroy();
	
	

	return 0;
}