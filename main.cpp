#include <iostream>
#include <random>
#include <corecrt_math_defines.h>

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
	button RepeatButton;
	double r;
	double theta = 0.0;
	double TimeCount = 0.0;
	unsigned int CounterColor = GetColor(BLACK);
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

		theta += M_PI * 0.03490658503;
		if (theta > M_PI + M_PI) {
			theta = 0.0;
		}

		WaitTimer(16.6666666667);
	}

	r = dist(engine);
	APPLE_MIHON.LoadImage("ringorou.png");
	APPLE.LoadImage("ringorou.png");


	while (1) {
		// =========================
		// ���C���Q�[��
		// =========================
		while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && TimeCount < 600) {
			BACK_GROUND.DrawBackGround();
			APPLE_MIHON.DrawImage(400, 0, r);
			APPLE.DrawImage(true);

			DrawFormatString(0, 0, CounterColor, "�c�莞�ԁF%lf\n", 10.0 - TimeCount / 60.0);

			++TimeCount;
			WaitTimer(16.6666666667);
		}

		// �ŏI�I�ȍ��W�����߂�
		APPLE.DecideCoordinate();

		while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
			BACK_GROUND.DrawBackGround();
			APPLE_MIHON.DrawImage(400, 0, r);
			APPLE.DrawImage(false);
			APPLE.DrawRatio(r);

			RepeatButton.Draw(100, 350, 250, 400);
			RepeatButton.Text("������x", 30, 13);
			if (RepeatButton.IsClick()) {
				break;
			}

			EndButton.Draw(400, 350, 550, 400);
			EndButton.Text("�����", 45, 13);
			if (EndButton.IsClick()) {
				DxLib_End();
				return 0;
			}
		}
	}

	DxLib_End();
	return 0;
}
