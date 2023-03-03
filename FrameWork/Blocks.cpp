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
		//���̹��� 9��
		sprintf_s(FileName, "./resource/Img/block/Block_%02d.png", ColorNum);
		Bkimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

}

void Blocks::Update()
{
	if (!isBoom && isBlock)
	{
		//Block�� Ball�� �浹ó������
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

///// Block�� Ball�浹 ////////
void Blocks::Boom()
{
	//ȸ�����̸�(isGray=true) �ι�°�� �������(ó�� �浹�� isBoom����, isGray����)
	if (isGray)
	{
		isBoom = false;
		isGray = false;	//ȸ���� �ƴ����� �ٲ�	
		EffectPlay(sound.m_graycol); 	//fmod���� ����
	}
	else   //ȸ���� ù �浹 �� �浹��
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
