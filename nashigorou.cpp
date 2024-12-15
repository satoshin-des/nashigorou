#include "nashigorou.h"

#include <math.h>

void nashigorou::LoadImage(const char* FILE_NAME) {
	g = LoadGraph(FILE_NAME);
	GetGraphSize(g, &sizeX, &sizeY);
}

void nashigorou::DrawImage(int _X, int _Y, double ratio) {
	GetGraphSize(g, &sizeX, &sizeY);
	DrawExtendGraph(_X, _Y, _X + 200, _Y + ratio * 200.0 * sizeY / sizeX, g, TRUE);
}

void nashigorou::DrawImage(bool IsMovable) {
	if (IsMovable) {
		GetMousePoint(&X, &Y);
		DrawExtendGraph(X, Y, 550, 450, g, TRUE);
	}
	else {
		DrawExtendGraph(X, Y, 550, 450, g, TRUE);
	}
}

void nashigorou::DecideCoordinate() {
	GetMousePoint(&X, &Y);
}

void nashigorou::DrawRatio(double ratio) {
	unsigned int Color = GetColor(0, 0, 0);

	double r1 = (fabs(550.0 - X) / fabs(450.0 - Y)) * ratio * 100, r2 = 10000.0 / r1, r;
	r = r1 < r2 ? r1 : r2;
	
	SetFontSize(28);
	DrawFormatString(0, 0, Color, "Ž—‚Ä‚é—¦F%lf“\n", r);
}
