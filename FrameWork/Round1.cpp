#include "Include.h"

Round1 round1;

void Round1::Init()
{
	
	Blocks tempBlo;
	tempBlo.Init(1);
	blockSizeX = tempBlo.b_WSize;
	blockSizeY = tempBlo.b_HSize;

	//처음 블록 위치값
	float x = 420;
	float y = 220;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			bkarr1[i][j].Init(chap1_color[i][j]);
			bkarr1[i][j].SetLocation(x, y);
			x += blockSizeX;
		}
		y += blockSizeY;
		x = 420;
	}
}

void Round1::Update()
{
	if (Gmanager.m_GameStart)
	{
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 13; ++j)
			{
				bkarr1[i][j].Update();
			}
		}
	}
}

void Round1::Draw()
{
	if (Gmanager.m_GameStart)
	{
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 13; ++j)
			{
				bkarr1[i][j].Draw();
			}
		}
	}
}
