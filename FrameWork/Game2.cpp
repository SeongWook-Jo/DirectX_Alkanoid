#include "Include.h"

Game2::Game2()
{	
}

Game2::~Game2()
{
}

void Game2::Init()
{
	map.Init();
	target.Init();
	sound.Init();
	ball.Init();
	Gmanager.Init();
	round2.Init();
}

void Game2::Draw()
{
	map.Draw();

	target.Draw();
	ball.Draw();
	Gmanager.Draw();
	round2.Draw();

}

// Chap, 재정의 함수 호출
void Game2::Update(double frame)
{
	
	static DWORD a = 0;

	if (GetTickCount64() - a > frame)
	{
		key.Update();
		target.Update();

		map.Update(130);
		ball.Update();
		Gmanager.Update();
		round2.Update();

		a = GetTickCount64();
	}
}

void Game2::OnMessage(MSG* msg)
{

}