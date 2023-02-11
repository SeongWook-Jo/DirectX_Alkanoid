#include "Include.h"

Ball ball;

Ball::Ball()
{
	m_W = STARTWIDTH;
	m_H = STARTHEIGHT - 30;
	m_DirX = 0;
	m_DirY = 0;
	bTempStart = false;
}

void Ball::Init()
{
	char FileName[256];

	sprintf_s(FileName, "./resource/Img/bullet/Ball.png");
	BallImg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	m_radius = BallImg.imagesinfo.Height / 2;
}

void Ball::Update()
{
	if (!bTempStart) return;
	m_W += (m_DirX * BALLSPEED);
	m_H += (m_DirY * BALLSPEED);
}

void Ball::Draw()
{
	BallImg.Render(m_W, m_H,0,1,1);
}

void Ball::Bounce()
{
	m_DirY *= -1;
}

