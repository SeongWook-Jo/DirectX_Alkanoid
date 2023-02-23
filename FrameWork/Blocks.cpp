#include "Include.h"


Blocks::Blocks()
{
}

Blocks::~Blocks()
{
}

void Blocks::Init(int ColorNum)
{
	if (ColorNum == 0)
	{
		isBlock = false;
		return;
	}

	char FileName[256];
	sprintf_s(FileName, "./resource/Img/block/Block_%02d.png", 1);
	orgSize.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	b_WSize = orgSize.imagesinfo.Width;
	b_HSize = orgSize.imagesinfo.Height;

	for (int i = 0; i < 5; i++)
	{
		//블럭이미지 9색
		sprintf_s(FileName, "./resource/Img/block/Block_%02d.png", ColorNum);
		Bkimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

}

void Blocks::Update()
{
	if (!isBoom && isBlock)
	{
		//Bar와 Ball의 충돌처리구현
		if (ball.m_W + ball.m_WSize > m_locationX &&
			ball.m_W < m_locationX + b_WSize &&
			ball.m_H + ball.m_HSize > m_locationY &&
			ball.m_H < m_locationY + b_HSize)
		{

			if (ball.m_W + ball.m_WSize > m_locationX + 1|| ball.m_W < m_locationX + b_WSize - 1)
			{
				ball.Bounce(-1.f, 1.f);
				//Boom();
			}
			if (ball.m_H + ball.m_HSize + 1 > m_locationY || ball.m_H < m_locationY + b_HSize - 1)
			{
				ball.Bounce(1.f, -1.f);
				//Boom();
			}
			Boom();
		}
	}
}


void Blocks::Draw()
{

	if (!isBoom && isBlock)
	{
		Bkimg.Render(m_locationX, m_locationY, 0, 1, 1);
	}
}

///// Block과 Ball충돌 ////////
void Blocks::Boom()
{
	if (map.m_Stage == 1)
	{
		isBoom = true;
		round1.score += 100;
		round1.m_BlockCount--;	//총 블럭갯수 하나씩 줄이기(0되면 클리어)
		round2.m_BlockCount--; // 게임오버화면 테스트(스테이지2카운트 연결하면지우기)
	}
	if (map.m_Stage == 2)
	{
		isBoom = true;
		round1.score += 100;
		round2.m_BlockCount--;	//총 블럭갯수 하나씩 줄이기(0되면 클리어)
	}
}

void Blocks::SetLocation(int x, int y)
{
	m_locationX = x;
	m_locationY = y;

}
