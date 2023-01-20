#include "pch.h"
#include "BingoGame.h"
#include "Player.h"
#include "Computer.h"

CBingoGame::CBingoGame() :
	m_isGameOver(false),
	m_turn(TURN::PLAYER),
	m_player(new CPlayer()),
	m_computer(new CComputer())
{
	srand((unsigned int)time(nullptr));

	m_player->Init(WORD_TYPE::NUMBER);
	m_computer->Init(WORD_TYPE::NUMBER);
}

CBingoGame::~CBingoGame()
{
	// ���� ���� �� ���������� �������� �ѹ� �� ����Ѵ�.
	Render();

	switch (m_turn)
	{
	case TURN::PLAYER:
		SetTextColor(TEXT_COLOR::GREEN);
		cout << "================== Player Win ! ===================" << endl;
		break;
	case TURN::COMPUTER:
		SetTextColor(TEXT_COLOR::RED);
		cout << "================== Computer Win ! ==================" << endl;
		break;
	case TURN::COUNT:
		SetTextColor(TEXT_COLOR::BLUE);
		cout << "====================== Draw ! ======================" << endl;
		break;
	}

	if (m_player != nullptr)
	{
		delete m_player;
	}

	if (m_computer != nullptr)
	{
		delete m_computer;
	}

	SetTextColor(TEXT_COLOR::WHITE);
}

void CBingoGame::Run()
{
	while (!m_isGameOver)
	{
		Render();
		Update();
	}
}

void CBingoGame::Update()
{
	string input;

	switch (m_turn)
	{
	case TURN::PLAYER:
		input = m_player->ProcessInput();
		m_turn = TURN::COMPUTER;
		break;
	case TURN::COMPUTER:
		input = m_computer->ProcessInput();
		m_turn = TURN::PLAYER;

		// ��ǻ�Ͱ� ���� ���� ����ϴ� ��ó�� �����ϱ� ���� 0.5�ʰ� ��ٸ����� �����.
		Sleep(500);
		break;
	}

	m_player->Update(input);
	m_computer->Update(input);

	bool playerWin = m_player->CheckGameOver();
	bool computerWin = m_computer->CheckGameOver();

	// ���ڰ� �����Ǹ�, turn���� ���� �������� �����Ѵ�.
	// ��� ��쿡��, COUNT ������ �����Ѵ�.
	if (playerWin && computerWin)
	{
		m_turn = TURN::COUNT;
		m_isGameOver = true;
	}
	else if (playerWin)
	{
		m_turn = TURN::PLAYER;
		m_isGameOver = true;
	}
	else if (computerWin)
	{
		m_turn = TURN::COMPUTER;
		m_isGameOver = true;
	}
}

void CBingoGame::Render()
{
	system("cls");

	m_player->Render();
	m_computer->Render();
}
