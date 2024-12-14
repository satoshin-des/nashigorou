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
	void LoadImage(const char* FILE_NAME);

	/// <summary>
	/// �摜�̕`��i�Œ�j
	/// </summary>
	/// <param name="_X">�摜��X���W</param>
	/// <param name="_Y">�摜��Y���W</param>
	/// <param name="ratio">�c����</param>
	void DrawImage(int _X, int _Y, double ratio);

	/// <summary>
	/// �摜�̕`��i�����j
	/// </summary>
	void DrawImage(bool IsMovable);

	/// <summary>
	/// �ŏI�I�Ȃ�񂲂낤�̍��W�����肷��
	/// </summary>
	void DecideCoordinate();

	/// <summary>
	/// ���{�Ƃǂ̂��炢�䗦�������Ă��邩�̊�����`�悷��
	/// </summary>
	/// <param name="ratio">���{�̏c����</param>
	void DrawRatio(double ratio);
};
