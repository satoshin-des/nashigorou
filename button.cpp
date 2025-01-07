#include "button.h"

bool button::IsOnButton() {
	GetMousePoint(&m_mouse_pointer_x, &m_mouse_pointer_y);
	if (m_button_top_left_x <= m_mouse_pointer_x && m_mouse_pointer_x <= m_button_bottom_right_x && m_button_top_left_y <= m_mouse_pointer_y && m_mouse_pointer_y <= m_button_bottom_right_y) {
		return true;
	}
	else {
		return false;
	}
}

void button::Draw(const int button_top_left_x, const int button_top_left_y, const int button_bottom_right_x, const int button_bottom_right_y) {
	m_button_top_left_x = button_top_left_x; m_button_top_left_y = button_top_left_y; m_button_bottom_right_x = button_bottom_right_x; m_button_bottom_right_y = button_bottom_right_y;

	unsigned int color = IsOnButton() ? GetColor(PINK) : GetColor(WHITE);
	DrawBox(button_top_left_x, button_top_left_y, button_bottom_right_x, button_bottom_right_y, color, TRUE);
}

void button::Text(const char* button_label_text, const int dx, const int dy) {
	unsigned int color = GetColor(0, 0, 0);
	SetFontSize(BUTTON_FONT_SIZE);
	DrawFormatString(m_button_top_left_x + dx, m_button_top_left_y + dy, color, "%s\n", button_label_text);
}

bool button::IsClick() {
	GetMousePoint(&m_mouse_pointer_x, &m_mouse_pointer_y);
	if (IsOnButton()) {
		if (GetMouseInput() & MOUSE_INPUT_LEFT) {
			return true;
		}
	}
	return false;
}
