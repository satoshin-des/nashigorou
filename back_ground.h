#pragma once

#include <DxLib.h>

#define WIDTH_X 800
#define WIDTH_Y 600

class back_ground
{
public:
	/// <summary>
	/// ”wŒi‚Ì•`‰æ
	/// </summary>
	void DrawBackGround() {
		unsigned int color = GetColor(137, 195, 221);
		DrawBox(0, 0, WIDTH_X, WIDTH_Y, color, TRUE);
	}
};
