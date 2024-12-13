#pragma once

#include <iostream>

#include <DxLib.h>
#include <corecrt_math_defines.h>

#include "nashigorou.h"
#include "back_ground.h"
#include "button.h"
#include "core.h"

int Title() {
	double theta = 0.0;
	back_ground BACK_GROUND;
	nashigorou TitleApple;
	button StartButton;						// �J�n�{�^��
	button EndButton;						// �I���{�^��

	TitleApple.LoadImage("ringorou.png");

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		BACK_GROUND.DrawBackGround();

		TitleApple.DrawImage(100 * cos(theta), 100 * sin(theta), 1);

		StartButton.Draw(100, 350, 250, 400);
		StartButton.Text("�͂��߂�", 30, 13);
		if (StartButton.IsClick()) {
			return __START__;
		}

		EndButton.Draw(400, 350, 550, 400);
		EndButton.Text("�����", 45, 13);
		if (EndButton.IsClick()) {
			DxLib_End();
			return __END__;
		}

		theta += M_PI * 0.03490658503;
		if (theta > M_PI + M_PI) {
			theta = 0.0;
		}

		WaitTimer(FPS60);
	}
}


int MainGame() {
	nashigorou APPLE_MIHON;					// ���{�̂�񂲂낤
	nashigorou APPLE;						// ���@�̂�񂲂낤
	button EndButton;						// �I���{�^��
	button RepeatButton;					// ������x�{�^��
	back_ground BACK_GROUND;
	double r;
	double TimeCount;
	unsigned int CounterColor = GetColor(BLACK);
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());
	std::uniform_real_distribution<double> dist(0.2, 0.7);

	TimeCount = 0.0;
	r = dist(engine);
	APPLE_MIHON.LoadImage("ringorou.png");
	APPLE.LoadImage("ringorou.png");

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && TimeCount < 600) {
		BACK_GROUND.DrawBackGround();
		APPLE_MIHON.DrawImage(400, 0, r);
		APPLE.DrawImage(true);

		DrawFormatString(0, 0, CounterColor, "�c�莞�ԁF%lf\n", 10.0 - TimeCount / 60.0);

		++TimeCount;
		WaitTimer(FPS60);
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
			return __REPEAT__;
		}

		EndButton.Draw(400, 350, 550, 400);
		EndButton.Text("�����", 45, 13);
		if (EndButton.IsClick()) {
			DxLib_End();
			return __END__;
		}
	}
}
