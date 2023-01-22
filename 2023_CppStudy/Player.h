#pragma once

#include "Entity.h"

class CPlayer : public CEntity
{
public:
	virtual void Init(WORD_TYPE wordType);

	virtual string ProcessInput();

	virtual void Render();
};
