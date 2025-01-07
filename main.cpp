#include <iostream>

#include <DxLib.h>

#include "game.h"
#include "nashigorou.h"
#include "back_ground.h"
#include "button.h"
#include "core.h"

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	if (DxLib_Init() == -1) {
		return -1;
	}

	SetOutApplicationLogValidFlag(FALSE);	// ログファイルを出力しない
	SetMainWindowText(TITLE);				// ゲームタイトル
	SetFontSize(20);						// フォントサイズを変更
	SetMouseDispFlag(TRUE);					// マウスを表示状態にする
	ChangeWindowMode(TRUE);					// ウィンドウモード
	SetGraphMode(WIDTH_X, WIDTH_Y, 32);
	SetWindowSize(WIDTH_X, WIDTH_Y);		// ウィンドウサイズ
	SetDrawScreen(DX_SCREEN_BACK);			// ダブルバッファリング

	int current_game_state = INITIAL_SCREEN;
	
	while(true) {
		switch (current_game_state) {
		case INITIAL_SCREEN:
			current_game_state = Title();
			break;

		case CREDIT_SCREEN:
			current_game_state = Credit();
			break;

		case START_SCREEN:
			current_game_state = MainGame();
			break;

		case REPEAT_GAME:
			current_game_state = MainGame();
			break;

		case GAME_END:
			return 0;
		}
	}

	DxLib_End();
	return 0;
}
