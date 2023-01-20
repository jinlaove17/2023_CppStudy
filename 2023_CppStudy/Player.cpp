#include "pch.h"
#include "Player.h"

void CPlayer::Init(WORD_TYPE wordType)
{
	CEntity::Init(wordType);

	m_board->SetMarkingColor(TEXT_COLOR::GREEN);
}

string CPlayer::ProcessInput()
{
	SetTextColor(TEXT_COLOR::WHITE);
	cout << "마킹할 값을 입력하세요(종료: q): ";

	string input;

	cin >> input;

	if (input == "q" || input == "Q")
	{
		exit(1);
	}

	return input;
}

void CPlayer::Render()
{
	SetTextColor(TEXT_COLOR::GREEN);
	cout << "▶ Player" << endl;

	CEntity::Render();
}
