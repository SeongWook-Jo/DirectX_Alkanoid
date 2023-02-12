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
	//if(게임 종료시) g_Mng.n_Chap = OVER; 
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


}
