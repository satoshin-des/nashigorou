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
	/// <param name="START_X">ボタンの左上端</param>
	/// <param name="START_Y">ボタンの左上端</param>
	/// <param name="END_X">ボタンの右下端</param>
	/// <param name="END_Y">ボタンの右下端</param>
	void Draw(int START_X, int START_Y, int END_X, int END_Y);
	
	/// <summary>
	/// ボタンにテキストを追加
	/// </summary>
	/// <param name="BUTTON_NAME">追加するテキスト</param>
	/// <param name="dx">x方向のずれ</param>
	/// <param name="dy">y方向のずれ</param>
	void Text(const char* BUTTON_NAME, int dx, int dy);
	
	/// <summary>
	/// ボタンがクリックされたかどうかの判定
	/// </summary>
	/// <returns>ボタンがクリックされたらtrue，そうでなければfalse</returns>
	bool IsClick();
};

