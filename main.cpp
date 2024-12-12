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

	if (SetMainWindowText("りんごろうの比合わせゲーム") == -1) {
		return -1;
	}


	SetFontSize(20);						// フォントサイズを変更
	SetMouseDispFlag(TRUE);					// マウスを表示状態にする
	ChangeWindowMode(TRUE);					// ウィンドウモード
	SetWindowSize(WIDTH_X, WIDTH_Y);		// ウィンドウサイズ

	back_ground BACK_GROUND;				// 背景
	nashigorou APPLE_MIHON;					// 見本のりんごろう
	nashigorou APPLE;						// 自機のりんごろう
	nashigorou TitleApple;
	button StartButton;						// 開始ボタン
	button EndButton;						// 終了ボタン
	button RepeatButton;					// もう一度ボタン
	double r;
	double theta = 0.0;
	double TimeCount = 0.0;
	unsigned int CounterColor = GetColor(BLACK);
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());
	std::uniform_real_distribution<double> dist(0.2, 0.7);

	TitleApple.LoadImage("ringorou.png");

	// ==============================
	// タイトル
	// ==============================
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		BACK_GROUND.DrawBackGround();

		TitleApple.DrawImage(100 * cos(theta), 100 * sin(theta), 1);

		StartButton.Draw(100, 350, 250, 400);
		StartButton.Text("はじめる", 30, 13);
		if (StartButton.IsClick()) {
			break;
		}

		EndButton.Draw(400, 350, 550, 400);
		EndButton.Text("おわる", 45, 13);
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
		// メインゲーム
		// =========================
		while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && TimeCount < 600) {
			BACK_GROUND.DrawBackGround();
			APPLE_MIHON.DrawImage(400, 0, r);
			APPLE.DrawImage(true);

			DrawFormatString(0, 0, CounterColor, "残り時間：%lf\n", 10.0 - TimeCount / 60.0);

			++TimeCount;
			WaitTimer(16.6666666667);
		}

		// 最終的な座標を決める
		APPLE.DecideCoordinate();

		while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
			BACK_GROUND.DrawBackGround();
			APPLE_MIHON.DrawImage(400, 0, r);
			APPLE.DrawImage(false);
			APPLE.DrawRatio(r);

			RepeatButton.Draw(100, 350, 250, 400);
			RepeatButton.Text("もう一度", 30, 13);
			if (RepeatButton.IsClick()) {
				break;
			}

			EndButton.Draw(400, 350, 550, 400);
			EndButton.Text("おわる", 45, 13);
			if (EndButton.IsClick()) {
				DxLib_End();
				return 0;
			}
		}
	}

	DxLib_End();
	return 0;
}
