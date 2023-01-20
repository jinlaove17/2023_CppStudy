#include "pch.h"
#include "Entity.h"

CEntity::CEntity() :
	m_board(new CBoard())
{

}

CEntity::~CEntity()
{
	if (m_board != nullptr)
	{
		delete m_board;
	}
}

void CEntity::Init(WORD_TYPE wordType)
{
	m_board->Init(wordType);
}

void CEntity::Update(const string& input)
{
	m_board->Update(input);
}

void CEntity::Render()
{
	m_board->Render();
}

bool CEntity::CheckGameOver()
{
	return m_board->CheckGameOver();
}
