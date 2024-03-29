#include "Include.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
	map.Init();
	target.Init();
	sound.Init();
	ball.Init();
	Gmanager.Init();
	round1.Init();
}

void Game::Draw()
{
	map.Draw();

	target.Draw();
	ball.Draw();
	Gmanager.Draw();
	round1.Draw();

}

// Chap, 재정의 함수 호출
void Game::Update(double frame)
{
	static DWORD a = 0;

	if (GetTickCount64() - a > frame)
	{
		key.Update();
		target.Update();

		map.Update(130);
		ball.Update();
		Gmanager.Update();
		round1.Update();

		a = GetTickCount64();
	}	

}


void Game::OnMessage( MSG* msg )
{

}