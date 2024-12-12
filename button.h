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
	/// ボタンの描画
	/// </summary>
	/// <param name="START_X">ボタンの左端</param>
	/// <param name="START_Y">ボタンの左端</param>
	/// <param name="END_X">ボタンの右端</param>
	/// <param name="END_Y">ボタンの右端</param>
	void Draw(int START_X, int START_Y, int END_X, int END_Y) {
		startX = START_X; startY = START_Y; endX = END_X; endY = END_Y;

		unsigned int color = GetColor(WHITE);
		DrawBox(START_X, START_Y, END_X, END_Y, color, TRUE);
	}

	/// <summary>
	/// ボタンにテキストを追加
	/// </summary>
	/// <param name="BUTTON_NAME">追加するテキスト</param>
	/// <param name="dx"></param>
	/// <param name="dy"></param>
	void Text(const char* BUTTON_NAME, int dx, int dy) {
		unsigned int Color = GetColor(0, 0, 0);
		DrawFormatString(startX + dx, startY + dy, Color, "%s\n", BUTTON_NAME);
	}

	/// <summary>
	/// ボタンがクリックされたかどうかの判定
	/// </summary>
	/// <returns>ボタンがクリックされたらtrue，そうでなければfalse</returns>
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

