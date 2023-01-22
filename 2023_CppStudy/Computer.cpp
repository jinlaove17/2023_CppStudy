#include "pch.h"
#include "Computer.h"

void CComputer::Init(WORD_TYPE wordType)
{
	CEntity::Init(wordType);

	m_board->SetMarkingColor(TEXT_COLOR::RED);
}

string CComputer::ProcessInput()
{
	return m_board->GetIdealAnswer();
}

void CComputer::Render()
{
	SetTextColor(TEXT_COLOR::RED);
	cout << "¢º Computer" << endl;

	CEntity::Render();
}
