#include "Include.h"

static DWORD KeyTime = GetTickCount();

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Init()
{
	count = 0;
	alpha = 0;
	//�ε�
	menuimg.Create("./resource/Img/lobby/Main01.png", false, D3DCOLOR_XRGB(0, 0, 0));

}

// Chap, ������ �Լ� ȣ��
void Menu::Update(double frame)
{

}

void Menu::Draw()
{
	menuimg.Render(-50, 0, 0, 0.75, 0.75); //�̹������ 0.75�� �̹���ũ��

}

void Menu::OnMessage(MSG* msg)
{
	
	switch (msg->message)
	{
	case WM_KEYDOWN:
		switch (msg->wParam) {
		case VK_F12:	//f12������ �������� �Ѿ
			if (g_Mng.n_Chap == MENU) {
				Gmanager.m_Score = 0;
				g_Mng.n_Chap = GAME; 
				sound.m_Bk1->Play(0, DSBPLAY_LOOPING);

			}
			break;
		}		
	}	
}

