#include "Include.h"

Blocks blocks;

Blocks::Blocks()
{
	m_BlockCount = 65;	//스테이지1 65개 블럭
	m_blockW = 425;
	m_blockH = 200;
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
	//블럭 이미지 가로,세로 사이즈
	b_WSize = Bkimg->imagesinfo.Width;
	b_HSize = Bkimg->imagesinfo.Height;
}

void Blocks::Update()
{
	if (Gmanager.m_GameStart == true)
	{
		Boom(); //공과 블럭 충돌시 호출					
	}
}

///// Block과 Ball충돌 ////////
void Blocks::Boom()
{
	//블럭 왼쪽위 x좌표 < 볼 오른쪽 아래 x좌표, 볼 왼쪽위 x좌표 < 블럭 오른쪽 아래 x좌표
	//블럭 왼쪽위 y좌표 < 볼 오른쪽 아래 y좌표, 볼 왼쪽위 y좌표 < 블럭 오른쪽아래 y좌표 

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (m_blockW < ball.m_W + ball.m_HSize &&
				ball.m_W < m_blockW + b_WSize &&
				m_blockH < ball.m_H + ball.m_HSize &&
				ball.m_H < m_blockH + b_HSize)
			{
				//공 튕기기
				float x, y;

				float ballPivot = ball.m_W + (ball.m_WSize / 2);
				float blockPivot = m_blockW + (b_WSize / 2);

				x = (ballPivot - blockPivot) / (b_WSize / 2);

				x = Clamp<float>(x, -0.5, 0.5);
				y = -(1 - fabs(x));

				ball.BarBounce(x, y);

				//블럭 사라지기
				bkarr1[i][j] = 0;	//값0으로 바꿈

				//점수올리기
				m_BlockCount--;	//총 블럭갯수 하나씩 줄이기(0되면 클리어처리)
				score += 100;
				//	score += m_block[i][j].point; //점수올리기
			}
		}
	}
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

					//충돌할 범위 만들기
					SetRect(&m_bkrc, m_blockW + x, m_blockH, m_blockW + x + 40, m_blockH + 20);
					dv_font.Fonts->DrawTextA(NULL, "충", -1, &m_bkrc, DT_LEFT, D3DCOLOR_ARGB(255, 255, 0, 0));
					x += 40;
				}
				else if (bkarr1[i][j] == 2)
				{
					Bkimg[1].Render(420 + y, 220, 0, 1, 1);

					SetRect(&m_bkrc, m_blockW + y, m_blockH + 20, m_blockW + y + 40, m_blockH + 40);
					dv_font.Fonts->DrawTextA(NULL, "충", -1, &m_bkrc, DT_LEFT, D3DCOLOR_ARGB(255, 255, 0, 0));

					y += 40;
				}
				else if (bkarr1[i][j] == 3)
				{
					Bkimg[2].Render(420 + z, 240, 0, 1, 1);

					SetRect(&m_bkrc, m_blockW + z, m_blockH + 40, m_blockW + z + 40, m_blockH + 60);
					dv_font.Fonts->DrawTextA(NULL, "충", -1, &m_bkrc, DT_LEFT, D3DCOLOR_ARGB(255, 255, 0, 0));

					z += 40;
				}
				else if (bkarr1[i][j] == 4)
				{
					Bkimg[3].Render(420 + a, 260, 0, 1, 1);

					SetRect(&m_bkrc, m_blockW + a, m_blockH + 60, m_blockW + a + 40, m_blockH + 80);
					dv_font.Fonts->DrawTextA(NULL, "충", -1, &m_bkrc, DT_LEFT, D3DCOLOR_ARGB(255, 255, 0, 0));

					a += 40;
				}
				else if (bkarr1[i][j] == 5)
				{
					Bkimg[4].Render(420 + b, 280, 0, 1, 1);

					SetRect(&m_bkrc, m_blockW + b, m_blockH + 80, m_blockW + b + 40, m_blockH + 100);
					dv_font.Fonts->DrawTextA(NULL, "충", -1, &m_bkrc, DT_LEFT, D3DCOLOR_ARGB(255, 255, 0, 0));

					b += 40;
				}
			}
		}

	}
}
