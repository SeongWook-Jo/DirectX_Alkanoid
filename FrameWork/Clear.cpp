#define _CRT_NONSTDC_NO_DEPRECATE
#include "Include.h"

Clear clear;

Clear::Clear()
{
}

Clear::~Clear()
{
}

void Clear::Init()
{
	speed = 400;
	alpha = 0;	//안보임

	int i;
	char FileName[256];

	for (i = 0; i < 2; i++)
	{
		sprintf_s(FileName, "./resource/Img/map1/BG_Arkanoid/clear_%02d.png", i + 1);
		clearimg[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}
}

// Chap, 재정의 함수 호출
void Clear::Update(double frame)
{	
	if (clear1 == true)
	{		
		alpha += speed * frame / 300;	//처음에 안보였다가 점점 로고 보임
		if (alpha >= 255)
		{
			alpha = 255;
			speed = -speed;
		}
		if (alpha <= 0) {	//알파값이 다시 0이 되면(로고안보이면)메뉴로 넘어가게
			clear1 = false;
		}
	}	

	if (KeyDown(VK_SPACE))
	{
		g_Mng.n_Chap = MENU;
		Gmanager.GameReset();
	}
}

void Clear::Draw()
{
	if (clear1 == true)
	{
		clearimg[0].SetColor(255, 255, 255, alpha);
		clearimg[0].Render(0, -50, 0, 0.7, 0.7);	//게임오버 이미지 출력		
	}
	if (clear1 == false)
	{
		clearimg[1].Render(0, 0, 0, 0.7, 0.7);	//게임오버 이미지 출력		
	}

	//점수
	dv_font.DrawString("SCORE", 610, 25);   //글자출력 200,210
	char show[20];
	itoa(Gmanager.m_Score, show, 10);
	dv_font.DrawString(show, 620, 55);   //글자출력
}

void Clear::OnMessage(MSG* msg)
{

}