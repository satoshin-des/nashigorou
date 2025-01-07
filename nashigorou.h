#pragma once

#include <DxLib.h>
#include "core.h"

class nashigorou
{
private:
	int m_nashigorou_img;
	int m_x; // ��񂲂낤��x���W
	int m_y; // ��񂲂낤��y���W
	int m_width, m_height;

public:
	/// <summary>
	/// �摜�̓ǂݍ���
	/// </summary>
	/// <param name="file_name">�t�@�C���̖��O�i�g���q�܂ށj</param>
	void LoadImage(const char* file_name);

	/// <summary>
	/// �摜�̕`��i�Œ�j
	/// </summary>
	/// <param name="x">�摜��x���W</param>
	/// <param name="y">�摜��y���W</param>
	/// <param name="aspect_ratio">�c����</param>
	void DrawImage(const int x, const int y, const double aspect_ratio);

	/// <summary>
	/// �摜�̕`��i�����j
	/// </summary>
	void DrawImage(const bool is_movable);

	/// <summary>
	/// �ŏI�I�Ȃ�񂲂낤�̍��W�����肷��
	/// </summary>
	void DecideCoordinate();

	/// <summary>
	/// ���{�Ƃǂ̂��炢�䗦�������Ă��邩�̊�����`�悷��
	/// </summary>
	/// <param name="aspect_ratio">���{�̏c����</param>
	void DrawRatio(double aspect_ratio);
};
