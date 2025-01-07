#pragma once

// ��ʃT�C�Y
#define WIDTH_X 800
#define WIDTH_Y 600

#define TITLE "��񂲂낤�̔䍇�킹�Q�[��"

// #define RINGOROU_IMAGE_PATH "img/ringorou.png"
#define RINGOROU_IMAGE_PATH "img/nashigorou.png"

#define TITLE_BGM "bgm/01.wav"
#define GAME_BGM "bgm/02.wav"

#define TITLE_FONT_SIZE 40
#define BUTTON_FONT_SIZE 20

// �F
#define WHITE 255, 255, 255
#define BLACK 0, 0, 0
#define SKY_COLOR 137, 195, 221
#define PINK 234, 145, 152

#define FPS60 16.666666666666666666666666666666666666666666666666666667

#define INITIAL_SCREEN 0
#define START_SCREEN 1
#define GAME_QUIT 0
#define REPEAT_GAME 2
#define CREDIT_SCREEN 3
#define GAME_END -1

typedef struct COLOR_ {
	unsigned int Red = 0;
	unsigned int Green = 0;
	unsigned int Blue = 0;
} COLOR;


/// <summary>
/// �F��ݒ肷��֐�
/// </summary>
/// <param name="r">��</param>
/// <param name="g">��</param>
/// <param name="b">��</param>
/// <returns></returns>
COLOR ColorSet(const unsigned int r, const unsigned int g, const unsigned int b);
