#pragma once

#define WIDTH_X 800
#define WIDTH_Y 600

#define WHITE 255, 255, 255
#define BLACK 0, 0, 0
#define SKY_COLOR 137, 195, 221

#define FPS60 16.666666666666666666666666666666666666666666666666666667

#define __INIT__ 0
#define __START__ 1
#define __END__ 0
#define __REPEAT__ 2

typedef struct _COLOR_ {
	unsigned int Red = 0;
	unsigned int Green = 0;
	unsigned int Blue = 0;
} COLOR;


/// <summary>
/// F‚ğİ’è‚·‚éŠÖ”
/// </summary>
/// <param name="r">Ô</param>
/// <param name="g">—Î</param>
/// <param name="b">Â</param>
/// <returns></returns>
COLOR ColorSet(unsigned int r, unsigned int g, unsigned int b);
