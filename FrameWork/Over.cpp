#define _CRT_NONSTDC_NO_DEPRECATE
#include "Include.h"


Over::Over()
{
}

Over::~Over()
{
}

void Over::Init()
{
	overimg.Create("./resource/Img/map1/BG_Arkanoid/gameover1.png", false, D3DCOLOR_XRGB(0, 0, 0));

}

// Chap, ������ �Լ� ȣ��
void Over::Update(double frame)
{	
	if (KeyDown(VK_SPACE))
	{
		g_Mng.n_Chap = MENU;
	}
}

void Over::Draw()
{
	overimg.Render(330, 0, 0, 1, 1);	//���ӿ��� �̹��� ���		

	//����
	char show[20];
	itoa(Gmanager.m_Score, show, 10);
	dv_font.DrawString(show, 640, 265);   //�������
}

void Over::OnMessage( MSG* msg )
{

}