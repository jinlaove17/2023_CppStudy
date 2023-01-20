#include "pch.h"
#include "Board.h"

CBoard::CBoard() :
	m_array(),
	m_bingoCount(0),
	m_markingColor(TEXT_COLOR::WHITE)
{

}

void CBoard::SetMarkingColor(TEXT_COLOR markingColor)
{
	m_markingColor = markingColor;
}

void CBoard::Init(WORD_TYPE wordType)
{
	assert(WORD_TYPE::NUMBER <= wordType && wordType < WORD_TYPE::COUNT);

	ifstream in;

	switch (wordType)
	{
	case WORD_TYPE::NUMBER:
		in.open("Number.txt");
		break;
	case WORD_TYPE::ANIMAL:
		in.open("Animal.txt");
		break;
	case WORD_TYPE::FRUIT:
		in.open("Fruit.txt");
		break;
	}

	for (int i = 0; i < m_array.size(); ++i)
	{
		for (int j = 0; j < m_array.size(); ++j)
		{
			in >> m_array[i][j];
		}
	}

	for (int i = 0; i < 30; ++i)
	{
		swap(m_array[rand() % m_array.size()][rand() % m_array.size()], m_array[rand() % m_array.size()][rand() % m_array.size()]);
	}

	m_bingoCount = 0;
}

void CBoard::Update(const string& input)
{
	int row = -1, col = -1;

	for (int i = 0; i < m_array.size(); ++i)
	{
		for (int j = 0; j < m_array.size(); ++j)
		{
			if (m_array[i][j] == input)
			{
				row = i;
				col = j;

				break;
			}
		}
	}

	if (row == -1 && col == -1)
	{
		return;
	}

	if (IsValidPosition(row, col))
	{
		m_array[row][col] = "*";
	}

	CalculateBingoCount();
}

void CBoard::Render()
{
	for (int i = 0; i < m_array.size(); ++i)
	{
		for (int j = 0; j < m_array.size(); ++j)
		{
			if (m_array[i][j] == "*")
			{
				SetTextColor(m_markingColor);
			}
			else
			{
				SetTextColor(TEXT_COLOR::WHITE);
			}

			cout << setw(10) << m_array[i][j] << " ";
		}

		cout << endl;
	}

	SetTextColor(TEXT_COLOR::SKYBLUE);
	cout << " Bingo Count: " << m_bingoCount << endl << endl;
}

bool CBoard::CheckGameOver()
{
	// 승리 조건: 빙고 5줄 이상
	return m_bingoCount >= 5;
}

string CBoard::GetIdealAnswer()
{
	string idealAnswer;

	// maxNumber: 가로(0 ~ m_array.size() - 1), 세로(m_array.size() ~ 2 * m_array.size() - 1), 좌하향 대각선(2 * m_array.size()), 우하향 대각선(2 * m_array.size() + 1)
	int starCount = 0, maxStarCount = 0, maxNumber = 0;

	// 가로 별 개수 계산
	for (int i = 0; i < m_array.size(); ++i)
	{
		starCount = GetRowStarCount(i);

		if ((starCount < 5) && (starCount > maxStarCount))
		{
			maxStarCount = starCount;
			maxNumber = i;
		}
	}

	// 세로 별 개수 계산
	for (int i = 0; i < m_array.size(); ++i)
	{
		starCount = GetColumnStarCount(i);

		if ((starCount < 5) && (starCount > maxStarCount))
		{
			maxStarCount = starCount;
			maxNumber = m_array.size() + i;
		}
	}

	// 좌하향 대각선 별 개수 계산
	starCount = GetLeftDownStarCount();

	if ((starCount < 5) && (starCount > maxStarCount))
	{
		maxStarCount = starCount;
		maxNumber = 2 * m_array.size();
	}

	// 우하향 대각선 별 개수 계산
	starCount = GetRightDownStarCount();

	if ((starCount < 5) && (starCount > maxStarCount))
	{
		maxStarCount = starCount;
		maxNumber = 2 * m_array.size() + 1;
	}

	// 해당 라인에 있는 값을 찾는다.
	if (0 <= maxNumber && maxNumber <= m_array.size() - 1)
	{
		for (int i = 0; i < m_array.size(); ++i)
		{
			if (m_array[maxNumber][i] != "*")
			{
				idealAnswer = m_array[maxNumber][i];

				break;
			}
		}
	}
	else if (m_array.size() <= maxNumber && maxNumber <= 2 * m_array.size() - 1)
	{
		for (int i = 0; i < m_array.size(); ++i)
		{
			if (m_array[i][maxNumber - m_array.size()] != "*")
			{
				idealAnswer = m_array[i][maxNumber - m_array.size()];

				break;
			}
		}
	}
	else if (maxNumber == 2 * m_array.size())
	{
		for (int i = 0; i < m_array.size(); ++i)
		{
			if (m_array[i][(m_array.size() - 1) - i] != "*")
			{
				idealAnswer = m_array[i][(m_array.size() - 1) - i];

				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < m_array.size(); ++i)
		{
			if (m_array[i][i] != "*")
			{
				idealAnswer = m_array[i][i];

				break;
			}
		}
	}

	return idealAnswer;
}

bool CBoard::IsValidPosition(int row, int col)
{
	if (m_array[row][col] == "*")
	{
		return false;
	}

	return true;
}

void CBoard::CalculateBingoCount()
{
	m_bingoCount = 0;

	for (int i = 0; i < m_array.size(); ++i)
	{
		if (GetRowStarCount(i) == 5)
		{
			++m_bingoCount;
		}
	}

	for (int i = 0; i < m_array.size(); ++i)
	{
		if (GetColumnStarCount(i) == 5)
		{
			++m_bingoCount;
		}
	}

	if (GetLeftDownStarCount() == 5)
	{
		++m_bingoCount;
	}

	if (GetRightDownStarCount() == 5)
	{
		++m_bingoCount;
	}
}

int CBoard::GetRowStarCount(int row)
{
	int startCount = 0;

	for (int col = 0; col < m_array.size(); ++col)
	{
		if (m_array[row][col] == "*")
		{
			++startCount;
		}
	}

	return startCount;
}

int CBoard::GetColumnStarCount(int col)
{
	int startCount = 0;

	for (int row = 0; row < m_array.size(); ++row)
	{
		if (m_array[row][col] == "*")
		{
			++startCount;
		}
	}

	return startCount;
}

int CBoard::GetLeftDownStarCount()
{
	int startCount = 0;

	for (int i = 0; i < m_array.size(); ++i)
	{
		if (m_array[i][(m_array.size() - 1) - i] == "*")
		{
			++startCount;
		}
	}

	return startCount;
}

int CBoard::GetRightDownStarCount()
{
	int startCount = 0;

	for (int i = 0; i < m_array.size(); ++i)
	{
		if (m_array[i][i] == "*")
		{
			++startCount;
		}
	}

	return startCount;
}
