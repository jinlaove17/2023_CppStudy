#include "pch.h"

void SetTextColor(TEXT_COLOR textColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)textColor);
}
