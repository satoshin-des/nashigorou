#pragma once

#include <DxLib.h>
#include "core.h"

class nashigorou
{
private:
	int g;
	int X; // りんごろうのX座標
	int Y; // りんごろうのY座標
	int sizeX, sizeY;

public:
	/// <summary>
	/// 画像の読み込み
	/// </summary>
	/// <param name="FILE_NAME">ファイルの名前（拡張子含む）</param>
	void LoadImage(const char* FILE_NAME) {
		g = LoadGraph(FILE_NAME);
		GetGraphSize(g, &sizeX, &sizeY);
	}

	/// <summary>
	/// 画像の描画（固定）
	/// </summary>
	/// <param name="_X">画像のX座標</param>
	/// <param name="_Y">画像のY座標</param>
	/// <param name="ratio">縦横比</param>
	void DrawImage(int _X, int _Y, double ratio) {
		GetGraphSize(g, &sizeX, &sizeY);
		DrawExtendGraph(_X, _Y, _X + 200, _Y + ratio * 200.0 * sizeY / sizeX, g, TRUE);
	}

	/// <summary>
	/// 画像の描画（動く）
	/// </summary>
	void DrawImage() {
		GetMousePoint(&X, &Y);
		DrawExtendGraph(X, Y, 550, 450, g, TRUE);
	}

	/// <summary>
	/// 見本とどのくらい比率があっているかの割合を描画する
	/// </summary>
	/// <param name="ratio">見本の縦横比</param>
	void DrawRatio(double ratio) {
		unsigned int Color = GetColor(0, 0, 0);

		double r1 = (fabs(550.0 - X) / fabs(450.0 - Y)) * ratio * 100, r2 = 10000.0 / r1, r;
		r = r1 < r2 ? r1 : r2;

		DrawFormatString(0, 0, Color, "%lf％\n", r);
	}
};
