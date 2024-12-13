#pragma once

#include <DxLib.h>

#include "core.h"

class button
{
private:
	int startX;
	int startY;
	int endX;
	int endY;
	int MouseX;
	int MouseY;

public:
	/// <summary>
	/// �{�^���̕`��
	/// </summary>
	/// <param name="START_X">�{�^���̍���[</param>
	/// <param name="START_Y">�{�^���̍���[</param>
	/// <param name="END_X">�{�^���̉E���[</param>
	/// <param name="END_Y">�{�^���̉E���[</param>
	void Draw(int START_X, int START_Y, int END_X, int END_Y);
	
	/// <summary>
	/// �{�^���Ƀe�L�X�g��ǉ�
	/// </summary>
	/// <param name="BUTTON_NAME">�ǉ�����e�L�X�g</param>
	/// <param name="dx">x�����̂���</param>
	/// <param name="dy">y�����̂���</param>
	void Text(const char* BUTTON_NAME, int dx, int dy);
	
	/// <summary>
	/// �{�^�����N���b�N���ꂽ���ǂ����̔���
	/// </summary>
	/// <returns>�{�^�����N���b�N���ꂽ��true�C�����łȂ����false</returns>
	bool IsClick();
};

