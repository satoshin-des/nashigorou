#pragma once

#include <DxLib.h>
#include "core.h"

class back_ground
{
public:
	/// <summary>
	/// �w�i�̕`��
	/// </summary>
	void DrawBackGround() {
		unsigned int color = GetColor(SKY_COLOR);
		DrawBox(0, 0, WIDTH_X, WIDTH_Y, color, TRUE);
	}
};
