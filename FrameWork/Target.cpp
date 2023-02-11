#include "Include.h"


Target target;


Target::Target()
{
	BarState = 0;
	m_W = STARTWIDTH;
	m_H = STARTHEIGHT;
	
}

Target::~Target()
{
}

void Target::Init()
{
	char FileName[256];

	sprintf_s(FileName, "./resource/Img/taget/%02d.png", BarState);
	BarImg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	m_BarWidth = BarImg.imagesinfo.Width;
	m_BarHeight = BarImg.imagesinfo.Height;

}

void Target::Update()
{
	//Bar客 Ball狼 面倒贸府备泅
	if(ball.m_H+ball.m_radius > m_H &&
		ball.m_H + ball.m_radius < m_H + m_BarHeight &&
		ball.m_W + ball.m_radius > m_W &&
		ball.m_W - ball.m_radius < m_W + m_BarWidth) ball.Bounce();

	m_W = Clamp<float>(m_W, 420, 845);

}

void Target::Draw()
{
	if (Gmanager.m_GameStart == true)
		BarImg.Render(m_W, m_H, 0, 0.7, 0.7);

	if (Gmanager.m_Collision == true)
	{
		
	}
}

void Target::Reset()
{
	m_W = STARTWIDTH;
	m_H = STARTHEIGHT;
}