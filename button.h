#pragma once

#include <DxLib.h>

#include "core.h"

class button
{
private:
	int m_button_top_left_x;
	int m_button_top_left_y;
	int m_button_bottom_right_x;
	int m_button_bottom_right_y;
	int m_mouse_pointer_x;
	int m_mouse_pointer_y;

	/// <summary>
	/// マウスカーソルがボタンの領域内に入っているかどうか
	/// </summary>
	/// <returns>マウスカーソルがボタンに振ればtrue，そうでないときはfalse</returns>
	bool IsOnButton();

public:
	/// <summary>
	/// ボタンの描画
	/// </summary>
	/// <param name="button_top_left_x">ボタンの左上端</param>
	/// <param name="button_top_left_y">ボタンの左上端</param>
	/// <param name="button_bottom_right_x">ボタンの右下端</param>
	/// <param name="button_bottom_right_y">ボタンの右下端</param>
	void Draw(const int button_top_left_x, const int button_top_left_y, const int button_bottom_right_x, const int button_bottom_right_y);
	
	/// <summary>
	/// ボタンにテキストを追加
	/// </summary>
	/// <param name="button_label_text">追加するテキスト</param>
	/// <param name="dx">x方向のずれ</param>
	/// <param name="dy">y方向のずれ</param>
	void Text(const char* button_label_text, const int dx, const int dy);
	
	/// <summary>
	/// ボタンがクリックされたかどうかの判定
	/// </summary>
	/// <returns>ボタンがクリックされたらtrue，そうでなければfalse</returns>
	bool IsClick();
};
