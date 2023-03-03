#include "Include.h"

Blocks blocks;

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
	if (ColorNum == 1)
	{
		isGray = true;
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
		//Block과 Ball의 충돌처리구현
		if (ball.m_W + ball.m_WSize > m_locationX &&
			ball.m_W < m_locationX + b_WSize &&
			ball.m_H + ball.m_HSize > m_locationY &&
			ball.m_H < m_locationY + b_HSize)
		{

			if (ball.m_W + ball.m_WSize > m_locationX + 1 || ball.m_W < m_locationX + b_WSize - 1)
			{
				ball.Bounce(-1.f, 1.f);				
			}
			if (ball.m_H + ball.m_HSize + 1 > m_locationY || ball.m_H < m_locationY + b_HSize - 1)
			{
				ball.Bounce(1.f, -1.f);				
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
	//회색블럭이면(isGray=true) 두번째에 사라지게(처음 충돌시 isBoom끄고, isGray끄고)
	if (isGray)
	{
		isBoom = false;
		isGray = false;	//회색블럭 아님으로 바꿈	
		EffectPlay(sound.m_graycol); 	//fmod사운드 연결
	}
	else   //회색블럭 첫 충돌 외 충돌시
	{
		isBoom = true;
		Gmanager.m_Score += 100;
		--Gmanager.m_BlockCount;		
	}
}

void Blocks::SetLocation(int x, int y)
{
	m_locationX = x;
	m_locationY = y;
}
