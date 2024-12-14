#include "core.h"
#include "back_ground.h"

void back_ground::DrawBackGround() {
	unsigned int color = GetColor(SKY_COLOR);
	DrawBox(0, 0, WIDTH_X, WIDTH_Y, color, TRUE);
}
