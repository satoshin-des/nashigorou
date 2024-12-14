#include "button.h"

bool button::IsOnButton() {
	GetMousePoint(&MouseX, &MouseY);
	if (startX <= MouseX && MouseX <= endX && startY <= MouseY && MouseY <= endY) {
		return true;
	}
	else {
		return false;
	}
}

void button::Draw(int START_X, int START_Y, int END_X, int END_Y) {
	startX = START_X; startY = START_Y; endX = END_X; endY = END_Y;

	unsigned int color;
	color = IsOnButton() ? GetColor(PINK) : GetColor(WHITE);
	DrawBox(START_X, START_Y, END_X, END_Y, color, TRUE);
}

void button::Text(const char* BUTTON_NAME, int dx, int dy) {
	unsigned int color = GetColor(0, 0, 0);
	SetFontSize(_BUTTON_FONT_SIZE_);
	DrawFormatString(startX + dx, startY + dy, color, "%s\n", BUTTON_NAME);
}

bool button::IsClick() {
	GetMousePoint(&MouseX, &MouseY);
	if (IsOnButton()) {
		if (GetMouseInput() & MOUSE_INPUT_LEFT) {
			return true;
		}
	}
	return false;
}
