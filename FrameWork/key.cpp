#include "Include.h"

Key key;

Key::Key(void)
{


}

Key::~Key(void)
{
}


void Key::Update()
{
	//Ball 스피드 임시 테스트
	if (KeyDown(VK_SPACE))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			if (!Gmanager.m_StageStart)
			{
				Gmanager.m_StageStart = true;
				ball.m_DirX = 1;
				ball.m_DirY = 1;

				KeyTime = GetTickCount64();
			}
		}

	}

	if (KeyDown(VK_F3))
	{
		Gmanager.m_StageStart = false;
	}

	if (KeyDown(VK_F12))
	{
		if (GetTickCount64() - KeyTime > 200)
		{
			KeyTime = GetTickCount64();
		}

	}

	if (KeyDown(VK_LEFT))
	{
		if (GetTickCount64() - KeyTime1 > 10)
		{
			if (target.m_W <= 0)
			{
				target.m_W = target.m_W;
			}
			else if (Gmanager.m_GameStart == true)
			{
				target.m_W -= 5;
			}
			KeyTime1 = GetTickCount64();
		}
	}

	if (KeyDown(VK_RIGHT))
	{

		if (GetTickCount64() - KeyTime1 > 10)
		{
			if (target.m_W >= 1190)
			{
				target.m_W = target.m_W;
			}
			else if (Gmanager.m_GameStart == true)
			{
				target.m_W += 5;
			}
			KeyTime1 = GetTickCount64();
		}

	}

	//퍼즈구현
	if (KeyDown('P'))
	{
		if (GetTickCount64() - KeyTime > 200)
		{

			KeyTime = GetTickCount64();
		}
	}

}