#pragma once

// 画面サイズ
#define WIDTH_X 800
#define WIDTH_Y 600

#define TITLE "りんごろうの比合わせゲーム"

#define RINGOROU_IMAGE_PATH "img/ringorou.png"
#define TITLE_BGM "bgm/01.wav"
#define GAME_BGM "bgm/02.wav"

#define _TITLE_FONT_SIZE_ 40
#define _BUTTON_FONT_SIZE_ 20

// 色
#define WHITE 255, 255, 255
#define BLACK 0, 0, 0
#define SKY_COLOR 137, 195, 221
#define PINK 234, 145, 152

#define FPS60 16.666666666666666666666666666666666666666666666666666667

#define __INIT__ 0
#define __START__ 1
#define __END__ 0
#define __REPEAT__ 2
#define __CREDIT__ 3
#define __GAME_END__ -1


#define LOOP while(ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)

typedef struct _COLOR_ {
	unsigned int Red = 0;
	unsigned int Green = 0;
	unsigned int Blue = 0;
} COLOR;


/// <summary>
/// 色を設定する関数
/// </summary>
/// <param name="r">赤</param>
/// <param name="g">緑</param>
/// <param name="b">青</param>
/// <returns></returns>
COLOR ColorSet(unsigned int r, unsigned int g, unsigned int b);
