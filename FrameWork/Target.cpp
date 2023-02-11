#include "Include.h"


Target target;


Target::Target()
{
	BarState = 0;
	m_W = STARTWIDTH;
	m_H = STARTHEIGHT;
	m_Target.dx = m_W + 30;
	m_Target.dy = m_H + 30;
}

Target::~Target()
{
}

void Target::Init()
{
	char FileName[256];

	sprintf_s(FileName, "./resource/Img/taget/%02d.png", BarState);
	BarImg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
}

void Target::Update()
{



}

void Target::Draw()
{
	if (Gmanager.m_GameStart == true)
		BarImg.Render(m_W, m_H, 0, 0.7, 0.7);

	if (Gmanager.m_Collision == true)
	{
		SetRect(&m_rc, m_Target.dx, m_Target.dy, m_Target.dx + 150, m_Target.dy + 150);
		dv_font.Fonts->DrawTextA(NULL, "Ãæ", -1, &m_rc, DT_LEFT, D3DCOLOR_ARGB(255, 255, 0, 0));
	}
}

void Target::Reset()
{
	m_W = 600;
	m_H = 300;
	m_Target.dx = 635;
	m_Target.dy = 330;
}