#include "Include.h"

Ball ball;

Ball::Ball()
{
	m_W = STARTWIDTH;
	m_H = STARTHEIGHT - 30;
	m_Speed = BALLSPEED + 3;
	m_DirX = 0;
	m_DirY = 0;
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
	if (!Gmanager.m_StageStart)
	{
		m_W = target.m_W + (target.m_WSize / 2); // 확인해보니 사이즈에 문제 있음
		m_H = target.m_H - m_HSize;
		return;
	}
	if (m_H > target.m_H + target.m_HSize + 100)
	{
		if (Gmanager.deathCnt == 2)	//세번째 충돌시
		{
			Gmanager.GameOver();	//게임오버
		}
		Gmanager.BallOver();	//부활
	}
	m_DirX = m_DirX / sqrt(m_DirX * m_DirX + m_DirY * m_DirY);
	m_DirY = m_DirY / sqrt(m_DirX * m_DirX + m_DirY * m_DirY);

	m_W += (m_DirX * m_Speed);
	m_H += (m_DirY * m_Speed);

}

void Ball::Draw()
{
	BallImg.Render(m_W, m_H, 0, 1, 1);
}

void Ball::BarBounce(float x, float y)
{
	m_DirX = x;
	m_DirY = y;
	EffectPlay(sound.m_barcol);	//fmod사운드 연결
}

void Ball::Bounce(float x, float y)
{
	m_DirX *= x;
	m_DirY *= y;
	EffectPlay(sound.m_Shoot); 	//fmod사운드 연결
}

