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
	SetWindowSize(WIDTH_X, WIDTH_Y);		// ウィンドウサイズ
	SetDrawScreen(DX_SCREEN_BACK);			// ダブルバッファリング

	int GAME_FLAG = __INIT__;
	
	while(true) {
		switch (GAME_FLAG) {
		case __INIT__:
			GAME_FLAG = Title();
			break;

		case __CREDIT__:
			GAME_FLAG = Credit();
			break;

		case __START__:
			GAME_FLAG = MainGame();
			break;

		case __REPEAT__:
			GAME_FLAG = MainGame();
			break;

		case __GAME_END__:
			return 0;
		}
	}

	DxLib_End();
	return 0;
}
