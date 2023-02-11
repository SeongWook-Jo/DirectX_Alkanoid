#include "Include.h"

Ball ball;

Ball::Ball()
{
	m_W = STARTWIDTH;
	m_H = STARTHEIGHT - 30;
	m_Speed = BALLSPEED + 5;
	m_DirX = 0;
	m_DirY = 0;
	bTempStart = false;
}

void Ball::Init()
{
	char FileName[256];

	sprintf_s(FileName, "./resource/Img/bullet/Ball.png");
	BallImg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	m_WSize = BallImg.imagesinfo.Width;
	m_HSize = BallImg.imagesinfo.Height;
}

void Ball::Update()
{
	//테스트용변수 F2 누르면 TRUE
	if (!bTempStart) return;

	//정규화
	m_DirX = m_DirX / sqrt(m_DirX * m_DirX + m_DirY * m_DirY);
	m_DirY = m_DirY / sqrt(m_DirX * m_DirX + m_DirY * m_DirY);
	m_W += (m_DirX * m_Speed);
	m_H += (m_DirY * m_Speed);
}

void Ball::Draw()
{
	BallImg.Render(m_W, m_H,0,1,1);
}

void Ball::BarBounce(float x, float y)
{
	m_DirX = x;
	m_DirY = y;
}

void Ball::Bounce(float x, float y)
{
	m_DirX *= x;
	m_DirY *= y;
}

