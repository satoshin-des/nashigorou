#include "game.h"

int Title() {
	double theta = 0.0;
	back_ground BACK_GROUND;
	nashigorou TitleApple;
	button StartButton;						// �J�n�{�^��
	button EndButton;						// �I���{�^��
	button CreditButton;

	TitleApple.LoadImage(RINGOROU_IMAGE_PATH);

	StopSoundFile();
	PlaySoundFile(TITLE_BGM, DX_PLAYTYPE_LOOP);

	LOOP {
		BACK_GROUND.DrawBackGround();

		TitleApple.DrawImage(100 * cos(theta), 100 * sin(theta), 1);
		
		SetFontSize(_TITLE_FONT_SIZE_);
		DrawFormatString(10, 10, GetColor(0, 0, 0), TITLE);

		StartButton.Draw(100, 350, 250, 400);
		StartButton.Text("�͂��߂�", 30, 13);
		if (StartButton.IsClick()) {
			return __START__;
		}

		EndButton.Draw(400, 350, 550, 400);
		EndButton.Text("�����", 45, 13);
		if (EndButton.IsClick()) {
			return __GAME_END__;
		}

		CreditButton.Draw(500, 420, 600, 470);
		CreditButton.Text("�ڼޯ�", 20, 13);
		if (CreditButton.IsClick()) {
			return __CREDIT__;
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
	APPLE_MIHON.LoadImage(RINGOROU_IMAGE_PATH);
	APPLE.LoadImage(RINGOROU_IMAGE_PATH);

	StopSoundFile();
	PlaySoundFile(GAME_BGM, DX_PLAYTYPE_LOOP);

	LOOP {
		if (TimeCount >= 600) {
			break;
		}

		BACK_GROUND.DrawBackGround();
		APPLE_MIHON.DrawImage(400, 0, r);
		APPLE.DrawImage(true);

		DrawFormatString(0, 0, CounterColor, "�c�莞�ԁF%lf\n", 10.0 - TimeCount / 60.0);

		++TimeCount;
		WaitTimer(FPS60);
	}

	// �ŏI�I�ȍ��W�����߂�
	APPLE.DecideCoordinate();

	LOOP {
		BACK_GROUND.DrawBackGround();
		APPLE_MIHON.DrawImage(400, 0, r);
		APPLE.DrawImage(false);
		APPLE.DrawRatio(r);

		RepeatButton.Draw(100, 250, 250, 300);
		RepeatButton.Text("������x", 30, 13);
		if (RepeatButton.IsClick()) {
			WaitTimer(500);
			return __REPEAT__;
		}

		EndButton.Draw(100, 350, 250, 400);
		EndButton.Text("�����", 45, 13);
		if (EndButton.IsClick()) {
			WaitTimer(500);
			return __END__;
		}

		WaitTimer(FPS60);
	}
}

int Credit() {
	button EndButton;
	back_ground BACK_GROUND;

	LOOP{
		BACK_GROUND.DrawBackGround();
		
		SetFontSize(40);
		DrawFormatString(10, 3, GetColor(0, 0, 0), "�N���W�b�g");

		SetFontSize(20);
		DrawFormatString(10, 50, GetColor(0, 0, 0), "���g�p�y��");
		DrawFormatString(10, 50, GetColor(0, 0, 0), "\n�@�o�`�l�u���ׂ�񂲂̂����v");
		DrawFormatString(10, 50, GetColor(0, 0, 0), "\n\n�@URL: https://www.nicovideo.jp/watch/sm36210300");
		DrawFormatString(10, 50, GetColor(0, 0, 0), "\n\n\n���g�p����");
		DrawFormatString(10, 50, GetColor(0, 0, 0), "\n\n\n\n�@�Ђ�߂��l�uGB�����uHiyameshi-DMG�v�v");
		DrawFormatString(10, 50, GetColor(0, 0, 0), "\n\n\n\n\n�@URL: https://hiyameshi8bit.booth.pm/items/4710188");
		
		EndButton.Draw(325, 350, 475, 400);
		EndButton.Text("�^�C�g��", 45, 13);
		if (EndButton.IsClick()) {
			WaitTimer(500);
			return __END__;
		}
	}
}
