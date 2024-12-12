#pragma once

#include <DxLib.h>
#include "core.h"

class nashigorou
{
private:
	int g;
	int X; // ��񂲂낤��X���W
	int Y; // ��񂲂낤��Y���W
	int sizeX, sizeY;

public:
	/// <summary>
	/// �摜�̓ǂݍ���
	/// </summary>
	/// <param name="FILE_NAME">�t�@�C���̖��O�i�g���q�܂ށj</param>
	void LoadImage(const char* FILE_NAME) {
		g = LoadGraph(FILE_NAME);
		GetGraphSize(g, &sizeX, &sizeY);
	}

	/// <summary>
	/// �摜�̕`��i�Œ�j
	/// </summary>
	/// <param name="_X">�摜��X���W</param>
	/// <param name="_Y">�摜��Y���W</param>
	/// <param name="ratio">�c����</param>
	void DrawImage(int _X, int _Y, double ratio) {
		GetGraphSize(g, &sizeX, &sizeY);
		DrawExtendGraph(_X, _Y, _X + 200, _Y + ratio * 200.0 * sizeY / sizeX, g, TRUE);
	}

	/// <summary>
	/// �摜�̕`��i�����j
	/// </summary>
	void DrawImage() {
		GetMousePoint(&X, &Y);
		DrawExtendGraph(X, Y, 550, 450, g, TRUE);
	}

	/// <summary>
	/// ���{�Ƃǂ̂��炢�䗦�������Ă��邩�̊�����`�悷��
	/// </summary>
	/// <param name="ratio">���{�̏c����</param>
	void DrawRatio(double ratio) {
		unsigned int Color = GetColor(0, 0, 0);

		double r1 = (fabs(550.0 - X) / fabs(450.0 - Y)) * ratio * 100, r2 = 10000.0 / r1, r;
		r = r1 < r2 ? r1 : r2;

		DrawFormatString(0, 0, Color, "%lf��\n", r);
	}
};
