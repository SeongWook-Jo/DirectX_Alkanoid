#include "Include.h"

Map map;


Map::Map()
{
	m_Stage = 1;
}

Map::~Map()
{
}

void Map::Init()	//�ε��� �̹��� �־����
{
	int i, j;
	char FileName[256];

	m_MapImg[0].Create("./resource/Img/map1/BG_Arkanoid/back1.png", false, D3DCOLOR_XRGB(0, 0, 0));
	m_MapImg[1].Create("./resource/Img/map1/BG_Arkanoid/frame1.png", false, D3DCOLOR_XRGB(0, 0, 0));
}

void Map::Update(double frame)
{
	//�� Ƣ��� ���� ����
	if (ball.m_W < 420) ball.Bounce(-1, 1);
	if (ball.m_W+ball.m_WSize > 925) ball.Bounce(-1, 1);	//905
	if (ball.m_H < 120) ball.Bounce(1, -1);
}

void Map::Draw()	//������������ ���̾� ��������(�̹��� ��ġ)
{
	if (m_Stage == 1)
	{
		m_MapImg[0].Render(415, 105, 0, 1.05, 1);	//�ǵڿ� ���� 2���� ũ�� 1,1 �� ����ũ��
		m_MapImg[1].Render(397, 100, 0, 1.05, 1);
		dv_font.DrawString("HIGH SCORE", 590, 25);   //������� 200,210
	}

	else if (m_Stage == 2)
	{
		m_MapImg2[0].Render(415, 105, 0, 1.05, 1);	//�ǵڿ� ���� 2���� ũ�� 1,1 �� ����ũ��
		m_MapImg2[1].Render(397, 100, 0, 1.05, 1);
		dv_font.DrawString("SCORE", 590, 25);   //������� 200,210
	}

}
