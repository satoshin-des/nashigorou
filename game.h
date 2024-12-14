#pragma once

#include <iostream>
#include <random>

#include <DxLib.h>
#include <corecrt_math_defines.h>

#include "nashigorou.h"
#include "back_ground.h"
#include "button.h"
#include "core.h"

/// <summary>
/// タイトルの制御
/// </summary>
/// <returns>状態</returns>
int Title();

/// <summary>
/// ゲームのメイン画面
/// </summary>
/// <returns>状態</returns>
int MainGame();

/// <summary>
/// クレジットの画面
/// </summary>
/// <returns>状態</returns>
int Credit();
