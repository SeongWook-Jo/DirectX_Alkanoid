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
	// ����Ÿ ���̽�///////////////////
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
	// ����Ÿ ���̽�///////////////////
	sql.Draw();
}

// Chap, ������ �Լ� ȣ��
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
		// �� ���� �°�
		map.Update(130);
		ball.Update();
		Gmanager.Update();
		// ����Ÿ ���̽�///////////////////
		// �� ���� �°� (���⼱ �Ⱦ���..������ ���� �ʿ� �Ҷ���.. �׳� �����...)
		sql.Update(frame+3000);

		a = GetTickCount64();
	}
	

}


void Game::OnMessage( MSG* msg )
{

}