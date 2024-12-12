#pragma once

#include <DxLib.h>

class nashigorou
{
private:
	int g;
	int X; // ÇËÇÒÇ≤ÇÎÇ§ÇÃXç¿ïW
	int Y; // ÇËÇÒÇ≤ÇÎÇ§ÇÃYç¿ïW
	int sizeX, sizeY;

public:
	void LoadImage(const char* FILE_NAME) {
		g = LoadGraph(FILE_NAME);
		GetGraphSize(g, &sizeX, &sizeY);
	}

	int DrawImage(int _X, int _Y, double ratio) {
		int FLAG;

		GetGraphSize(g, &sizeX, &sizeY);
		FLAG = DrawExtendGraph(_X, _Y, _X + 200, _Y + ratio * 200.0 * sizeY / sizeX, g, TRUE);
		return FLAG;
	}

	int DrawImage(double SIZE) {
		int FLAG;

		if (GetMousePoint(&X, &Y) == -1) {
			return -1;
		}

		FLAG = DrawExtendGraph(X, Y, 550, 450, g, TRUE);

		return FLAG;
	}

	void DrawRatio(double ratio) {
		unsigned int Color = GetColor(255, 255, 255);
		DrawFormatString(0, 0, Color, "%lfÅì\n", (fabs(550.0 - X) / fabs(450.0 - Y)) * ratio * 100);
	}
};
