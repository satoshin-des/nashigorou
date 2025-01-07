#include "nashigorou.h"

void nashigorou::LoadImage(const char* file_name) {
	m_nashigorou_img = LoadGraph(file_name);
	GetGraphSize(m_nashigorou_img, &m_width, &m_height);
}

void nashigorou::DrawImage(const int x, const int y, const double aspect_ratio) {
	GetGraphSize(m_nashigorou_img, &m_width, &m_height);
	DrawExtendGraph(x, y, x + 200, y + aspect_ratio * 200.0 * m_height / m_width, m_nashigorou_img, TRUE);
}

void nashigorou::DrawImage(const bool is_movable) {
	if (is_movable) {
		GetMousePoint(&m_x, &m_y);
		DrawExtendGraph(m_x, m_y, WIDTH_X - 20, WIDTH_Y - 20, m_nashigorou_img, TRUE);
	}
	else {
		DrawExtendGraph(m_x, m_y, WIDTH_X - 20, WIDTH_Y - 20, m_nashigorou_img, TRUE);
	}
}

void nashigorou::DecideCoordinate() {
	GetMousePoint(&m_x, &m_y);
}

void nashigorou::DrawRatio(const double aspect_ratio) {
	unsigned int text_color = GetColor(0, 0, 0);

	double temp_similarity_rate1 = (std::abs(WIDTH_X - 20.0 - m_x) / std::abs(WIDTH_Y - 20.0 - m_y)) * aspect_ratio * 100, temp_similarity_rate2 = 10000.0 / temp_similarity_rate1;
	double similarity_rate;
	similarity_rate = temp_similarity_rate1 < temp_similarity_rate2 ? temp_similarity_rate1 : temp_similarity_rate2;
	
	SetFontSize(28);
	DrawFormatString(0, 0, text_color, "Ž—‚Ä‚é—¦F%lf“\n", similarity_rate);
}
