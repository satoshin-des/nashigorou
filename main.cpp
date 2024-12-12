#include <iostream>
#include <time.h>

#include <DxLib.h>
#include "nashigorou.h"
#include "back_ground.h"


int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	if (DxLib_Init() == -1) {
		return -1;
	}

	if (SetMainWindowText("��񂲂낤�̔䍇�킹�Q�[��") == -1) {
		return -1;
	}

	ChangeWindowMode(TRUE);
	SetWindowSize(WIDTH_X, WIDTH_Y);

	back_ground BACK_GROUND;
	nashigorou APPLE_MIHON;
	nashigorou APPLE;
	double r;

	srand((long long int)time(nullptr));
	r = ((double)rand() + 1.0) / RAND_MAX; // �傫���̔䗦

	APPLE_MIHON.LoadImage("ringorou.png");
	APPLE.LoadImage("ringorou.png");

	
	// �^�C�g�����

	// ���C���Q�[��
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		BACK_GROUND.DrawBackGround();
		APPLE_MIHON.DrawImage(400, 0, r);
		APPLE.DrawImage();

		APPLE.DrawRatio(r);
	}

	DxLib_End();

	return 0;
}
