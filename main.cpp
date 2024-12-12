#include <iostream>
#include <random>
#include<corecrt_math_defines.h>

#include <DxLib.h>

#include "nashigorou.h"
#include "back_ground.h"
#include "button.h"
#include "core.h"

//#define _USE_MATH_DEFINES

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	if (DxLib_Init() == -1) {
		return -1;
	}

	if (SetMainWindowText("��񂲂낤�̔䍇�킹�Q�[��") == -1) {
		return -1;
	}


	SetFontSize(20);						// �t�H���g�T�C�Y��ύX
	SetMouseDispFlag(TRUE);					// �}�E�X��\����Ԃɂ���
	ChangeWindowMode(TRUE);					// �E�B���h�E���[�h
	SetWindowSize(WIDTH_X, WIDTH_Y);		// �E�B���h�E�T�C�Y

	back_ground BACK_GROUND;				// �w�i
	nashigorou APPLE_MIHON;					// ���{�̂�񂲂낤
	nashigorou APPLE;						// ���@�̂�񂲂낤
	nashigorou TitleApple;
	button StartButton;						// �J�n�{�^��
	button EndButton;						// �I���{�^��
	double r;
	double theta = 0.0;
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());
	std::uniform_real_distribution<double> dist(0.2, 0.7);

	TitleApple.LoadImage("ringorou.png");

	// ==============================
	// �^�C�g��
	// ==============================
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		BACK_GROUND.DrawBackGround();

		TitleApple.DrawImage(100 * cos(theta), 100 * sin(theta), 1);

		StartButton.Draw(100, 350, 250, 400);
		StartButton.Text("�͂��߂�", 30, 13);
		if (StartButton.IsClick()) {
			break;
		}

		EndButton.Draw(400, 350, 550, 400);
		EndButton.Text("�����", 45, 13);
		if (EndButton.IsClick()) {
			DxLib_End();
			return 0;
		}

		theta += M_PI * 0.0111111111111111111;
		if (theta > M_PI + M_PI) {
			theta = 0.0;
		}
	}

	r = dist(engine);
	APPLE_MIHON.LoadImage("ringorou.png");
	APPLE.LoadImage("ringorou.png");

	// =========================
	// ���C���Q�[��
	// =========================
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		BACK_GROUND.DrawBackGround();
		APPLE_MIHON.DrawImage(400, 0, r);
		APPLE.DrawImage();
		APPLE.DrawRatio(r);
	}

	DxLib_End();
	return 0;
}
