#include "Include.h"

Ball ball;

Ball::Ball()
{
	m_W = STARTWIDTH;
	m_H = STARTHEIGHT + 10;
	m_MoveX = 0;
	m_MoveY = 0;
	SetRect(&m_rcCol, m_W, m_H, m_W + 10, m_H + 10);
	bTempStart = false;
}

void Ball::Init()
{
	char FileName[256];

	sprintf_s(FileName, "./resource/Img/bullet/Ball.png");
	BallImg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

}

void Ball::Update()
{
	if (!bTempStart) return;
	m_W += (m_MoveX * BALLSPEED);
	m_H += (m_MoveY * BALLSPEED);
}

void Ball::Draw()
{
	BallImg.Render(m_W, m_H,0,1,1);
	SetRect(&m_rcCol, m_W, m_H, m_W + 10, m_H + 10);
}

void Ball::Bounce()
{
}

