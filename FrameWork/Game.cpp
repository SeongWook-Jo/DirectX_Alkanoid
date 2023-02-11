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
	monster.Init();
	bird.Init();
	sound.Init();
	ball.Init();
	Gmanager.Init();
	// 데이타 베이스///////////////////
	sql.Init();
}

void Game::Draw()
{
	map.Draw();
	monster.Draw();
	bird.Draw();
	target.Draw();
	ball.Draw();
	Gmanager.Draw();
	// 데이타 베이스///////////////////
	sql.Draw();
}

// Chap, 재정의 함수 호출
void Game::Update(double frame)
{
	//static int a = 0;
	//if(a == 0) 
	//{
	//	GameTime = GetTickCount();
	//	a = 1;
	//}
	static DWORD a = 0;

	if (GetTickCount64() - a > frame)
	{
		key.Update();
		target.Update();
		monster.Update();
		bird.Update();
		// 입 맛에 맞게
		map.Update(130);
		ball.Update();
		Gmanager.Update();
		// 데이타 베이스///////////////////
		// 입 맛에 맞게 (여기선 안쓰임..프레임 값이 필요 할때만.. 그냥 방법만...)
		sql.Update(frame+3000);

		a = GetTickCount64();
	}
	

}


void Game::OnMessage( MSG* msg )
{

}