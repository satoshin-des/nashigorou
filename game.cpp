#include "game.h"

int Title() {
	double theta = 0.0;
	back_ground background;
	nashigorou nashigorou_on_title;
	button start_button;				// 開始ボタン
	button quit_button;					// 終了ボタン
	button credit_button;				// クレジット表示ボタン

	nashigorou_on_title.LoadImage(RINGOROU_IMAGE_PATH);

	StopSoundFile();
	PlaySoundFile(TITLE_BGM, DX_PLAYTYPE_LOOP);

	while(ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		background.DrawBackGround();

		nashigorou_on_title.DrawImage(100 * cos(theta), 100 * sin(theta), 1);
		
		SetFontSize(TITLE_FONT_SIZE);
		DrawFormatString(10, 10, GetColor(0, 0, 0), TITLE);

		start_button.Draw(150, WIDTH_Y - 150, 300, WIDTH_Y - 100);
		start_button.Text("はじめる", 30, 13);
		if (start_button.IsClick()) {
			return START_SCREEN;
		}

		quit_button.Draw(WIDTH_X - 300, WIDTH_Y - 150, WIDTH_X - 150, WIDTH_Y - 100);
		quit_button.Text("おわる", 45, 13);
		if (quit_button.IsClick()) {
			return GAME_END;
		}

		credit_button.Draw(WIDTH_X - 120, WIDTH_Y - 70, WIDTH_X - 20, WIDTH_Y - 20);
		credit_button.Text("ｸﾚｼﾞｯﾄ", 20, 13);
		if (credit_button.IsClick()) {
			return CREDIT_SCREEN;
		}

		theta += M_PI * 0.03490658503;
		if (theta > M_PI + M_PI) {
			theta = 0.0;
		}

		WaitTimer(FPS60);
	}
}


int MainGame() {
	nashigorou sample_nashigorou;					// 見本のりんごろう
	nashigorou player_nashigorou;						// 自機のりんごろう
	button quit_button;						// 終了ボタン
	button repeat_button;					// もう一度ボタン
	back_ground background;
	double r;
	double time_counter;
	unsigned int time_counter_color = GetColor(BLACK);
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());
	std::uniform_real_distribution<double> dist(0.2, 0.7);

	time_counter = 0.0;
	r = dist(engine);
	sample_nashigorou.LoadImage(RINGOROU_IMAGE_PATH);
	player_nashigorou.LoadImage(RINGOROU_IMAGE_PATH);

	StopSoundFile();
	PlaySoundFile(GAME_BGM, DX_PLAYTYPE_LOOP);

	while(ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		if (time_counter >= 600) {
			break;
		}

		background.DrawBackGround();
		sample_nashigorou.DrawImage(WIDTH_X - 300, 0, r);
		player_nashigorou.DrawImage(true);

		DrawFormatString(0, 0, time_counter_color, "残り時間：%lf\n", 10.0 - time_counter / 60.0);

		++time_counter;
		WaitTimer(FPS60);
	}

	// 最終的な座標を決める
	player_nashigorou.DecideCoordinate();

	while(ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		background.DrawBackGround();
		sample_nashigorou.DrawImage(400, 0, r);
		player_nashigorou.DrawImage(false);
		player_nashigorou.DrawRatio(r);

		repeat_button.Draw(150, WIDTH_Y - 150, 300, WIDTH_Y - 100);
		repeat_button.Text("もう一度", 30, 13);
		if (repeat_button.IsClick()) {
			WaitTimer(500);
			return REPEAT_GAME;
		}

		quit_button.Draw(WIDTH_X - 300, WIDTH_Y - 150, WIDTH_X - 150, WIDTH_Y - 100);
		quit_button.Text("おわる", 45, 13);
		if (quit_button.IsClick()) {
			WaitTimer(500);
			return GAME_QUIT;
		}

		WaitTimer(FPS60);
	}
}

int Credit() {
	button quit_button;
	back_ground background;

	while(ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0){
		background.DrawBackGround();
		
		SetFontSize(40);
		DrawFormatString(10, 3, GetColor(0, 0, 0), "クレジット");

		SetFontSize(20);
		DrawFormatString(10, 50, GetColor(0, 0, 0), "■使用楽曲");
		DrawFormatString(10, 50, GetColor(0, 0, 0), "\n　バチ様「たべるんごのうた」");
		DrawFormatString(10, 50, GetColor(0, 0, 0), "\n\n　URL: https://www.nicovideo.jp/watch/sm36210300");
		DrawFormatString(10, 50, GetColor(0, 0, 0), "\n\n\n■使用音源");
		DrawFormatString(10, 50, GetColor(0, 0, 0), "\n\n\n\n　ひやめし様「GB音源「Hiyameshi-DMG」」");
		DrawFormatString(10, 50, GetColor(0, 0, 0), "\n\n\n\n\n　URL: https://hiyameshi8bit.booth.pm/items/4710188");
		
		quit_button.Draw(WIDTH_X - 300, WIDTH_Y - 150, WIDTH_X - 150, WIDTH_Y - 100);
		quit_button.Text("タイトル", 45, 13);
		if (quit_button.IsClick()) {
			WaitTimer(500);
			return GAME_QUIT;
		}
	}
}
