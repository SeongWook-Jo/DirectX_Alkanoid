#include "Include.h"

Round2 round2;

void Round2::Init()
{
	//블록 이미지
	Blocks tempBlo;
	tempBlo.Init(1);	//blocks의 init에 colornum 1 넣음
	blockSizeX = tempBlo.b_WSize;	//블럭이미지의 가로 사이즈
	blockSizeY = tempBlo.b_HSize;	//블럭이미지의 세로 사이즈

	//처음 블록 위치값
	float x = 420;
	float y = 220;

	//blocks의 위치값 및 색상 전달
	for (int i = 0; i < 13; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			bkarr2[i][j].isBoom = false;
			bkarr2[i][j].Init(chap1_color[i][j]);	//색 숫자넣음
			bkarr2[i][j].SetLocation(x, y);			//위치값 넣음
			x += blockSizeX;						//13번 블럭이미지 가로사이즈만큼 더함
		}
		y += blockSizeY;							//5번 블럭이미지 세로사이즈만큼 더함
		x = 420;									//x를 420으로 초기화
	}
}

void Round2::Update()
{
	if (Gmanager.m_GameStart)
	{
		//블록충돌
		for (int i = 0; i < 13; ++i)
		{
			for (int j = 0; j < 13; ++j)
			{
				bkarr2[i][j].Update();	//블럭 충돌 불러옴
			}
		}
	}
}

void Round2::Draw()
{
	if (Gmanager.m_GameStart)
	{
		//블럭
		for (int i = 0; i < 13; ++i)
		{
			for (int j = 0; j < 13; ++j)
			{
				bkarr2[i][j].Draw();	//블럭 그리기 불러옴
			}
		}
	}
}
