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
	//
	if (ball.m_W < 420) ball.Bounce(-1, 1);
	if (ball.m_W+ball.m_WSize > 905) ball.Bounce(-1, 1);
	if (ball.m_H < 120) ball.Bounce(1, -1);



	//
	if (GetTickCount64() - m_MapImg1_1_ani1 > frame)	//����귯���� �ð�
	{
		if (m_Stage == 2)
		{
			m_MapImg2_1_ani1Count++;
			m_MapImg2_2_ani1Count++;
			if (m_MapImg2_1_ani1Count > 29) m_MapImg2_1_ani1Count = 0;
			if (m_MapImg2_2_ani1Count > 44) m_MapImg2_2_ani1Count = 0;

		}
		m_MapImg1_1_ani1 = GetTickCount64();
	}

}

void Map::Draw()	//������������ ���̾� ��������(�̹��� ��ġ)
{
	if (m_Stage == 1)
	{
		m_MapImg[0].Render(415, 105, 0, 1, 1);	//�ǵڿ� ���� 2���� ũ�� 1,1 �� ����ũ��
		m_MapImg[1].Render(400, 100, 0, 1, 1);
		dv_font.DrawString("HIGH SCORE", 590, 25);   //������� 200,210
	}

	else if (m_Stage == 2)
	{
		m_MapImg2_1[0].Render(0, 0, 0, 1, 1);
		m_MapImg2_2[m_MapImg2_1_ani1Count].Render(165, 0, 0, 4, 1);
		m_MapImg2_1[1].Render(0, 0, 0, 1, 1);
		m_MapImg2_2[m_MapImg2_1_ani1Count].Render(300, 710, 0, 2.3, 1);
		m_MapImg2_1[2].Render(0, 0, 0, 1, 1);
		m_MapImg2_3[m_MapImg2_2_ani1Count].Render(0, -40, 0, 4, 2);
		m_MapImg2_1[3].Render(0, 0, 0, 1, 1);
		m_MapImg2_1[4].Render(0, 0, 0, 1, 1);
		m_MapImg2_1[5].Render(0, 0, 0, 1, 1);
		m_MapImg2_1[6].Render(0, 0, 0, 1, 1);

	}

}
