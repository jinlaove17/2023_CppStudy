#pragma once

#include "Board.h"

class CEntity
{
protected:
	CBoard* m_board;

public:
	CEntity();
	~CEntity();

	virtual void Init(WORD_TYPE wordType);

	virtual string ProcessInput() = 0;
	
	virtual void Update(const string& input);
	virtual void Render();

	bool CheckGameOver();
};
