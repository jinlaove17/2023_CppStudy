#pragma once

enum class WORD_TYPE
{
	NUMBER,
	ANIMAL,
	FRUIT,
	
	COUNT
};

class CBoard
{
private:
	array<array<string, 5>, 5> m_array;

	int                        m_bingoCount;

	TEXT_COLOR				   m_markingColor;

public:
	CBoard();

	void SetMarkingColor(TEXT_COLOR markingColor);

	void Init(WORD_TYPE wordType);

	void Update(const string& input);
	void Render();

	bool CheckGameOver();

	// 컴퓨터가 가장 유용한 위치를 알아내기 위해 사용하는 함수
	string GetIdealAnswer();

private:
	bool IsValidPosition(int row, int col);

	void CalculateBingoCount();
	int GetRowStarCount(int row);
	int GetColumnStarCount(int col);
	int GetLeftDownStarCount();
	int GetRightDownStarCount();
};
