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
	void LoadImage(const char* FILE_NAME);

	/// <summary>
	/// 画像の描画（固定）
	/// </summary>
	/// <param name="_X">画像のX座標</param>
	/// <param name="_Y">画像のY座標</param>
	/// <param name="ratio">縦横比</param>
	void DrawImage(int _X, int _Y, double ratio);

	/// <summary>
	/// 画像の描画（動く）
	/// </summary>
	void DrawImage(bool IsMovable);

	/// <summary>
	/// 最終的なりんごろうの座標を決定する
	/// </summary>
	void DecideCoordinate();

	/// <summary>
	/// 見本とどのくらい比率があっているかの割合を描画する
	/// </summary>
	/// <param name="ratio">見本の縦横比</param>
	void DrawRatio(double ratio);
};
