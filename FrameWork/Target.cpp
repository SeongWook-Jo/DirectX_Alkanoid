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
	m_WSize = BarImg.imagesinfo.Width - 20;	//-10
	m_HSize = BarImg.imagesinfo.Height -10;	//-10眠啊

}

void Target::Update()
{
	//Bar客 Ball狼 面倒贸府备泅
	if (ball.m_W + ball.m_WSize > m_W &&
		ball.m_W < m_W + m_WSize &&
		ball.m_H + ball.m_HSize > m_H &&
		ball.m_H < m_H + m_HSize)
	{
		float x, y;

		float ballPivot = ball.m_W + (ball.m_WSize / 2);
		float barPivot = m_W + (m_WSize / 2);

		x = ( ballPivot - barPivot) / (m_WSize / 2);

		x = Clamp<float>(x, -0.5, 0.5);
		y = -(1 - fabs(x));


		ball.BarBounce(x, y);
	}


	m_W = Clamp<float>(m_W, 420, 870);	//420,845

}

void Target::Draw()
{
	if (Gmanager.m_GameStart == true)
		BarImg.Render(m_W, m_H, 0, 0.7, 0.7);
		
}

void Target::Reset()
{
	m_W = STARTWIDTH;
	m_H = STARTHEIGHT;
}