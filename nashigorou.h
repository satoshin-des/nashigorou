#pragma once

#include <DxLib.h>
#include "core.h"

class nashigorou
{
private:
	int m_nashigorou_img;
	int m_x; // りんごろうのx座標
	int m_y; // りんごろうのy座標
	int m_width, m_height;

public:
	/// <summary>
	/// 画像の読み込み
	/// </summary>
	/// <param name="file_name">ファイルの名前（拡張子含む）</param>
	void LoadImage(const char* file_name);

	/// <summary>
	/// 画像の描画（固定）
	/// </summary>
	/// <param name="x">画像のx座標</param>
	/// <param name="y">画像のy座標</param>
	/// <param name="aspect_ratio">縦横比</param>
	void DrawImage(const int x, const int y, const double aspect_ratio);

	/// <summary>
	/// 画像の描画（動く）
	/// </summary>
	void DrawImage(const bool is_movable);

	/// <summary>
	/// 最終的なりんごろうの座標を決定する
	/// </summary>
	void DecideCoordinate();

	/// <summary>
	/// 見本とどのくらい比率があっているかの割合を描画する
	/// </summary>
	/// <param name="aspect_ratio">見本の縦横比</param>
	void DrawRatio(double aspect_ratio);
};
