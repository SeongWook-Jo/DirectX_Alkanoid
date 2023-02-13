#include "Include.h"

Blocks blocks;

Blocks::Blocks()
{
}

Blocks::~Blocks()
{
}

void Blocks::Init()
{
	char FileName[256];
	for (int i = 0; i < 5; i++)
	{
		//블럭이미지 5색
		sprintf_s(FileName, "./resource/Img/block/Block_%02d.png", i + 1);
		Bkimg[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
}

void Blocks::Update()
{

}

void Blocks::Draw()
{
	// 이미지 가로로 띄우기 위한 변수
	int x = 0, y = 0, z = 0, a = 0, b = 0;

	if (Gmanager.m_GameStart == true)
	{
		for (int i = 0; i < 5; i++)	//2차원배열 [5],[13]이라 2번 for문 돌리기
		{
			for (int j = 0; j < 13; j++)
			{
				if (bkarr1[i][j] == 1)	//bkarr1 안에 1이면 회색블럭 그리기
				{
					Bkimg[0].Render(420 + x, 200, 0, 1, 1);
					x += 40;
				}
				else if (bkarr1[i][j] == 2)
				{
					Bkimg[1].Render(420 + y, 220, 0, 1, 1);
					y += 40;
				}
				else if (bkarr1[i][j] == 3)
				{
					Bkimg[2].Render(420 + z, 240, 0, 1, 1);
					z += 40;
				}
				else if (bkarr1[i][j] == 4)
				{
					Bkimg[3].Render(420 + a, 260, 0, 1, 1);
					a += 40;
				}
				else if (bkarr1[i][j] == 5)
				{
					Bkimg[4].Render(420 + b, 280, 0, 1, 1);
					b += 40;
				}
			}
		}

	}
}
