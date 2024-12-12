#include <iostream>
#include <time.h>

#include <DxLib.h>
#include "nashigorou.h"


int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	if (DxLib_Init() == -1) {
		return -1;
	}

	if (SetMainWindowText("ÇËÇÒÇ≤ÇÎÇ§ÇÃî‰çáÇÌÇπÉQÅ[ÉÄ") == -1) {
		return -1;
	}

	ChangeWindowMode(TRUE);
	SetWindowSize(800, 600);

	nashigorou APPLE_MIHON;
	nashigorou APPLE;
	double r;

	srand((long long int)time(nullptr));
	r = ((double)rand() + 1.0) / RAND_MAX; // ëÂÇ´Ç≥ÇÃî‰ó¶

	APPLE_MIHON.LoadImage("ringorou.png");
	APPLE.LoadImage("ringorou.png");
	
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		ClearDrawScreen();

		if (APPLE_MIHON.DrawImage(400, 0, r)) {
			return -1;
		}
		if (APPLE.DrawImage(1.0) == -1) {
			return -1;
		}

		APPLE.DrawRatio(r);
	}

	DxLib_End();

	return 0;
}
