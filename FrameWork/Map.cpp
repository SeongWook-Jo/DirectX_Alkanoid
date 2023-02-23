#include "Include.h"

Map map;


Map::Map()
{
	m_Stage = 1;
}

Map::~Map()
{
}

void Map::Init()	//로드할 이미지 넣어놓고
{
	int i, j;
	char FileName[256];

	m_MapImg[0].Create("./resource/Img/map1/BG_Arkanoid/back1.png", false, D3DCOLOR_XRGB(0, 0, 0));
	m_MapImg[1].Create("./resource/Img/map1/BG_Arkanoid/frame1.png", false, D3DCOLOR_XRGB(0, 0, 0));
}

void Map::Update(double frame)
{
	//볼 튀기는 벽의 범위
	if (ball.m_W < 420) ball.Bounce(-1, 1);
	if (ball.m_W+ball.m_WSize > 925) ball.Bounce(-1, 1);	//905
	if (ball.m_H < 120) ball.Bounce(1, -1);
}

void Map::Draw()	//스테이지별로 레이어 나눠놓기(이미지 위치)
{
	if (m_Stage == 1)
	{
		m_MapImg[0].Render(415, 105, 0, 1.05, 1);	//맨뒤에 숫자 2개는 크기 1,1 은 원본크기
		m_MapImg[1].Render(397, 100, 0, 1.05, 1);
		dv_font.DrawString("HIGH SCORE", 590, 25);   //글자출력 200,210
	}

	else if (m_Stage == 2)
	{
		m_MapImg2[0].Render(415, 105, 0, 1.05, 1);	//맨뒤에 숫자 2개는 크기 1,1 은 원본크기
		m_MapImg2[1].Render(397, 100, 0, 1.05, 1);
		dv_font.DrawString("SCORE", 590, 25);   //글자출력 200,210
	}

}
