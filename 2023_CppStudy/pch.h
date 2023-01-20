#pragma once

#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cassert>
#include <string>
#include <array>

using namespace std;

enum class TEXT_COLOR
{
    BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_SKYBLUE,
    DARK_RED,
    DARK_VOILET,
    DAKR_YELLOW,
    GRAY,
    DARK_GRAY,
    BLUE,
    GREEN,
    SKYBLUE,
    RED,
    VIOLET,
    YELLOW,
    WHITE,
};

void SetTextColor(TEXT_COLOR textColor);
