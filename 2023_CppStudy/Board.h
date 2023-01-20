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

	// ��ǻ�Ͱ� ���� ������ ��ġ�� �˾Ƴ��� ���� ����ϴ� �Լ�
	string GetIdealAnswer();

private:
	bool IsValidPosition(int row, int col);

	void CalculateBingoCount();
	int GetRowStarCount(int row);
	int GetColumnStarCount(int col);
	int GetLeftDownStarCount();
	int GetRightDownStarCount();
};
