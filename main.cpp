#include <iostream>
#include <random>
#include <corecrt_math_defines.h>

#include <DxLib.h>

#include "game.h"
#include "nashigorou.h"
#include "back_ground.h"
#include "button.h"
#include "core.h"

//#define _USE_MATH_DEFINES

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	if (DxLib_Init() == -1) {
		return -1;
	}

	SetMainWindowText("りんごろうの比合わせゲーム");			// ゲームタイトル
	SetFontSize(20);											// フォントサイズを変更
	SetMouseDispFlag(TRUE);										// マウスを表示状態にする
	ChangeWindowMode(TRUE);										// ウィンドウモード
	SetWindowSize(WIDTH_X, WIDTH_Y);							// ウィンドウサイズ

	int GAME_FLAG = __INIT__;
	
	while (true) {
		if (GAME_FLAG == __INIT__) {
			GAME_FLAG = Title();
			if (GAME_FLAG == __END__) {
				return 0;
			}
		}

		GAME_FLAG = MainGame();
	}

	DxLib_End();
	return 0;
}
