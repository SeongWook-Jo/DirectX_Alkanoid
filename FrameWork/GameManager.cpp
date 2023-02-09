#define _CRT_NONSTDC_NO_DEPRECATE
#include "Include.h"

GameManager Gmanager;
static DWORD ALPHATime = GetTickCount64();

GameManager::GameManager(void)
{
	GameTime = GetTickCount64();
	m_GameSpeed = 1;
	m_Pause = false;

	m_SysTem.m_Save1 = 100;
	m_SysTem.m_Save2 = 200;
	//Save();	//주석풀고 시작하면 한번 세이브가 되고 다시 주석하고 시작

	m_GameStart = true;
}

GameManager::~GameManager(void)
{
}

void GameManager::Init()
{
	//Menuimg[0].Create("./resource/Effect/menu/1.png",false,D3DCOLOR_XRGB(0,0,0));
	//Menuimg[1].Create("./resource/Effect/menu/2.png",false,D3DCOLOR_XRGB(0,0,0));


	//char seps[] = ",\n";
	//char *token;

	// 텍스트 버전
	//if ((fp = fopen("C:\\SYSTEM.txt","r"))== NULL)
	//{
	//	return ;
	//}
	
	// 기계어 버전
	if ((fp = fopen("./Save/save.fss","rb"))== NULL)	//rb기계어로 파일 오픈
	{
		return ;
	}
	
	fread(&m_SysTem,sizeof(SysTem),1,fp);	//구조체 읽어들임

	fclose(fp);
	
}

void GameManager::Update()
{
	//if(게임 종료시) g_Mng.n_Chap = OVER; 
}
void GameManager::Save()
{
	// 텍스트 버전은 "w" 로
	if ((fp = fopen("./Save/save.fss", "wb")) == NULL)	//기계어로 저장
	{
		return;
	}
	fwrite(&m_SysTem, sizeof(SysTem), 1, fp);
	fclose(fp);

}

void GameManager::Delete()
{
//	sound.g_pSoundManager->drr  

}
 



void GameManager::GameReset(void)  // 여기는 게임상 첨에 한번만  초기화되는 부분만 넣어줌.
{

}


void GameManager::Draw()
{

	//if(m_Alpha == 0) { Menuimg[0].SetColor(255,255, 255, 255);  Menuimg[1].SetColor(255,255, 255, 255);}
	//if(m_Alpha == 1) { Menuimg[0].SetColor(255,255,255,0); Menuimg[1].SetColor(255,255,255,0); }
	

	//map.numimg[5].Draw(50, 53);
	//map.numimg[0].Draw(65, 53);
	//map.numimg[0].Draw(80, 53);
	//map.numimg[0].Draw(95, 53);
	char show[20];
	itoa(m_SysTem.m_Save1, show, 10);
	dv_font.DrawString(show, 200, 210);   //글자출력
	itoa(m_SysTem.m_Save2, show, 10);
	dv_font.DrawString(show, 200, 310);   //글자출력
	
}
