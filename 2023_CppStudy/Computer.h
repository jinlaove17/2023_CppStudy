#pragma once

#include "Entity.h"

class CComputer : public CEntity
{
public:
	virtual void Init(WORD_TYPE wordType);

	virtual string ProcessInput();

	virtual void Render();

};
