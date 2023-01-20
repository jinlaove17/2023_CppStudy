#pragma once

class CEntity;

enum class TURN
{
	PLAYER,
	COMPUTER,

	COUNT
};

class CBingoGame
{
private:
	bool     m_isGameOver;

	TURN	 m_turn;

	CEntity* m_player;
	CEntity* m_computer;

public:
	CBingoGame();
	~CBingoGame();

	void Run();

public:
	void Update();
	void Render();
};
