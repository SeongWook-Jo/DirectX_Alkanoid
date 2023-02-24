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
	m_StageStart = false;

	//m_BlockCount = round1.m_BlockCount;
}

GameManager::~GameManager(void)
{
}

void GameManager::NextStage()
{
	m_StageStart = false;
	blocks.isBlock = true;
	m_BlockCount = round2.m_BlockCount;
	g_Mng.n_Chap = GAME2;
}

void GameManager::Init()
{
	lifebarimg.Create("./resource/Img/taget/00.png", false, D3DCOLOR_XRGB(0, 0, 0));

	//if ((fp = fopen("./Save/save.fss", "rb")) == NULL)	//rb기계어로 파일 오픈
	//{
	//	return;
	//}
	//fclose(fp);
}

void GameManager::Update()
{
	//최종 클리어 조건
	//if (m_BlockCount == 0 && g_Mng.n_Chap == GAME) {	//블럭갯수가 0이 되면 메뉴로 넘어가게
	//	NextStage();
	//}
	//if (m_BlockCount == 0 && g_Mng.n_Chap == GAME2) {	//블럭갯수가 0이 되면 메뉴로 넘어가게
	//	GameOver();
	//}

	//임시 클리어조건
	if (m_BlockCount < 60 && g_Mng.n_Chap == GAME) {	//블럭갯수가 0이 되면 메뉴로 넘어가게
		
		NextStage();
	}
	if (m_BlockCount < 85 && g_Mng.n_Chap == GAME2) {	//블럭갯수가 0이 되면 메뉴로 넘어가게
		GameOver();
	}
}


void GameManager::Delete()
{
	//	sound.g_pSoundManager->drr  

}

void GameManager::GameOver()
{
	g_Mng.n_Chap = OVER;	
}


//바 밑으로 볼이 떨어졌을때 
void GameManager::BallOver()
{
	deathCnt++;	// death카운트 +1
	if (g_Mng.n_Chap == GAME)	//라운드1일때 라운드1에서 공 부활
	{
		m_StageStart = false;
		g_Mng.n_Chap = GAME;
	}
	else if (g_Mng.n_Chap == GAME2)  //라운드2일때 라운드2에서 공 부활
	{
		m_StageStart = false;
		g_Mng.n_Chap = GAME2;
	}
}

//게임 완전 초기화
void GameManager::GameReset()
{
	round1.Init();
	round2.Init();
	m_StageStart = false;
	blocks.isBlock = true;

	m_BlockCount = 65;
	deathCnt = 0;
}

void GameManager::Draw()
{
	//부활
	if (deathCnt == 0)
	{
		lifebarimg.Render(460, 730, 0, 0.5, 0.5);
		lifebarimg.Render(420, 730, 0, 0.5, 0.5);
	}
	if (deathCnt == 1)
	{
		lifebarimg.Render(420, 730, 0, 0.5, 0.5);
	}

	//블럭 총 카운트 숫자 나타냄(테스트)
	char show[20];

	//itoa(round1.m_BlockCount, show, 10);
	//dv_font.DrawString(show, 200, 210);   //글자출력	

	//itoa(round2.m_BlockCount, show, 10);
	//dv_font.DrawString(show, 200, 230);   //글자출력

	itoa(m_Score, show, 10);
	dv_font.DrawString(show, 620, 55);   //글자출력
}
