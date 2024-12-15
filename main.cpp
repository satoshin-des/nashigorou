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

	SetOutApplicationLogValidFlag(FALSE);	// ���O�t�@�C�����o�͂��Ȃ�
	SetMainWindowText(TITLE);				// �Q�[���^�C�g��
	SetFontSize(20);						// �t�H���g�T�C�Y��ύX
	SetMouseDispFlag(TRUE);					// �}�E�X��\����Ԃɂ���
	ChangeWindowMode(TRUE);					// �E�B���h�E���[�h
	SetWindowSize(WIDTH_X, WIDTH_Y);		// �E�B���h�E�T�C�Y
	SetDrawScreen(DX_SCREEN_BACK);			// �_�u���o�b�t�@�����O

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
