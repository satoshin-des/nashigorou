#pragma once

#include <DxLib.h>

#include "core.h"

class button
{
private:
	int m_button_top_left_x;
	int m_button_top_left_y;
	int m_button_bottom_right_x;
	int m_button_bottom_right_y;
	int m_mouse_pointer_x;
	int m_mouse_pointer_y;

	/// <summary>
	/// �}�E�X�J�[�\�����{�^���̗̈���ɓ����Ă��邩�ǂ���
	/// </summary>
	/// <returns>�}�E�X�J�[�\�����{�^���ɐU���true�C�����łȂ��Ƃ���false</returns>
	bool IsOnButton();

public:
	/// <summary>
	/// �{�^���̕`��
	/// </summary>
	/// <param name="button_top_left_x">�{�^���̍���[</param>
	/// <param name="button_top_left_y">�{�^���̍���[</param>
	/// <param name="button_bottom_right_x">�{�^���̉E���[</param>
	/// <param name="button_bottom_right_y">�{�^���̉E���[</param>
	void Draw(const int button_top_left_x, const int button_top_left_y, const int button_bottom_right_x, const int button_bottom_right_y);
	
	/// <summary>
	/// �{�^���Ƀe�L�X�g��ǉ�
	/// </summary>
	/// <param name="button_label_text">�ǉ�����e�L�X�g</param>
	/// <param name="dx">x�����̂���</param>
	/// <param name="dy">y�����̂���</param>
	void Text(const char* button_label_text, const int dx, const int dy);
	
	/// <summary>
	/// �{�^�����N���b�N���ꂽ���ǂ����̔���
	/// </summary>
	/// <returns>�{�^�����N���b�N���ꂽ��true�C�����łȂ����false</returns>
	bool IsClick();
};
