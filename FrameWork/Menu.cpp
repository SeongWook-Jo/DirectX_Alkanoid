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
	//로드
	menuimg.Create("./resource/Img/lobby/Main01.png", false, D3DCOLOR_XRGB(0, 0, 0));

}

// Chap, 재정의 함수 호출
void Menu::Update(double frame)
{

}

void Menu::Draw()
{
	menuimg.Render(-50, 0, 0, 0.75, 0.75); //이미지출력 0.75는 이미지크기

}

void Menu::OnMessage(MSG* msg)
{
	
	switch (msg->message)
	{
	case WM_KEYDOWN:
		switch (msg->wParam) {
		case VK_F12:	//f12누르면 게임으로 넘어감
			if (g_Mng.n_Chap == MENU) {
				Gmanager.m_Score = 0;
				g_Mng.n_Chap = GAME; 
				sound.m_Bk1->Play(0, DSBPLAY_LOOPING);

			}
			break;
		}		
	}	
}

