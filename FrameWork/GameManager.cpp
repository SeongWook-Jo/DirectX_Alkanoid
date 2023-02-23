#define _CRT_NONSTDC_NO_DEPRECATE
#include "Include.h"

GameManager Gmanager;
static DWORD ALPHATime = GetTickCount64();

GameManager::GameManager(void)
{
	GameTime = GetTickCount64();
	m_GameSpeed = 1;
	m_Pause = false;

	m_GameStart = true;
}

GameManager::~GameManager(void)
{
}

void GameManager::Init()
{

	if ((fp = fopen("./Save/save.fss","rb"))== NULL)	//rb기계어로 파일 오픈
	{
		return ;
	}
	

	fclose(fp);
	
}

void GameManager::Update()
{
	//게임오버
	if (round1.m_BlockCount <= 60) {	//블럭갯수가 0이 되면 메뉴로 넘어가게
		g_Mng.n_Chap = GAME2;
	}
	if (round2.m_BlockCount <= 80) {	//블럭갯수가 0이 되면 메뉴로 넘어가게
		g_Mng.n_Chap = OVER;
	}
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
	//블럭 총 카운트 숫자 나타냄(테스트)
	char show[20];

	itoa(round1.m_BlockCount, show, 10);
	dv_font.DrawString(show, 200, 210);   //글자출력	

	itoa(round2.m_BlockCount, show, 10);
	dv_font.DrawString(show, 200, 230);   //글자출력

	itoa(round1.score, show, 10);
	dv_font.DrawString(show, 620, 55);   //글자출력
}
