#pragma once

#include <DxLib.h>

#include "core.h"

class button
{
private:
	int startX;
	int startY;
	int endX;
	int endY;
	int MouseX;
	int MouseY;

public:
	/// <summary>
	/// �{�^���̕`��
	/// </summary>
	/// <param name="START_X">�{�^���̍��[</param>
	/// <param name="START_Y">�{�^���̍��[</param>
	/// <param name="END_X">�{�^���̉E�[</param>
	/// <param name="END_Y">�{�^���̉E�[</param>
	void Draw(int START_X, int START_Y, int END_X, int END_Y) {
		startX = START_X; startY = START_Y; endX = END_X; endY = END_Y;

		unsigned int color = GetColor(WHITE);
		DrawBox(START_X, START_Y, END_X, END_Y, color, TRUE);
	}

	/// <summary>
	/// �{�^���Ƀe�L�X�g��ǉ�
	/// </summary>
	/// <param name="BUTTON_NAME">�ǉ�����e�L�X�g</param>
	/// <param name="dx"></param>
	/// <param name="dy"></param>
	void Text(const char* BUTTON_NAME, int dx, int dy) {
		unsigned int Color = GetColor(0, 0, 0);
		DrawFormatString(startX + dx, startY + dy, Color, "%s\n", BUTTON_NAME);
	}

	/// <summary>
	/// �{�^�����N���b�N���ꂽ���ǂ����̔���
	/// </summary>
	/// <returns>�{�^�����N���b�N���ꂽ��true�C�����łȂ����false</returns>
	bool IsClick() {
		GetMousePoint(&MouseX, &MouseY);
		if (startX <= MouseX && MouseX <= endX && startY <= MouseY && MouseY <= endY) {
			if (GetMouseInput() & MOUSE_INPUT_LEFT) {
				return true;
			}
		}
		return false;
	}
};

