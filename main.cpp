#include <iostream>
#include <time.h>

#include <DxLib.h>
#include "nashigorou.h"
#include "back_ground.h"


int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	if (DxLib_Init() == -1) {
		return -1;
	}

	if (SetMainWindowText("りんごろうの比合わせゲーム") == -1) {
		return -1;
	}

	ChangeWindowMode(TRUE);
	SetWindowSize(WIDTH_X, WIDTH_Y);

	back_ground BACK_GROUND;
	nashigorou APPLE_MIHON;
	nashigorou APPLE;
	double r;

	srand((long long int)time(nullptr));
	r = ((double)rand() + 1.0) / RAND_MAX; // 大きさの比率

	APPLE_MIHON.LoadImage("ringorou.png");
	APPLE.LoadImage("ringorou.png");

	
	// タイトル画面

	// メインゲーム
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		BACK_GROUND.DrawBackGround();
		APPLE_MIHON.DrawImage(400, 0, r);
		APPLE.DrawImage();

		APPLE.DrawRatio(r);
	}

	DxLib_End();

	return 0;
}
