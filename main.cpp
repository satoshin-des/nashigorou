#include <iostream>
#include <random>

#include <DxLib.h>
#include "nashigorou.h"
#include "back_ground.h"
#include "button.h"


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
	button StartButton;						// �J�n�{�^��
	button EndButton;						// �I���{�^��
	double r;
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());
	std::uniform_real_distribution<double> dist(0.2, 0.7);

	
	// �^�C�g�����
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		StartButton.Draw(100, 350, 250, 400);
		StartButton.Text("�͂��߂�", 30, 13);
		if (StartButton.IsClick()) {
			break;
		}

		EndButton.Draw(400, 350, 550, 400);
		EndButton.Text("�����", 30, 13);
		if (EndButton.IsClick()) {
			return 0;
		}
	}

	r = dist(engine);
	APPLE_MIHON.LoadImage("ringorou.png");
	APPLE.LoadImage("ringorou.png");

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
