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
	map.m_Stage = 2;
}

void GameManager::Init()
{
	lifebarimg.Create("./resource/Img/taget/00.png", false, D3DCOLOR_XRGB(0, 0, 0));
}

void GameManager::Update()
{
	//최종 클리어 조건
	if (m_BlockCount == 0 && g_Mng.n_Chap == GAME) {	//블럭갯수가 0이 되면 메뉴로 넘어가게
		NextStage();
	}
	if (m_BlockCount == 0 && g_Mng.n_Chap == GAME2) {	//블럭갯수가 0이 되면 메뉴로 넘어가게
		GameClear();
	}
}

void GameManager::GameOver()
{
	g_Mng.n_Chap = OVER;	
}

//게임 클리어
void GameManager::GameClear()
{	
	g_Mng.n_Chap = CLEAR;	
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
	EffectPlay(sound.m_Death);

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
	map.m_Stage = 1;
	clear.clear1 = true;
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
		
	char show[20];

	itoa(m_Score, show, 10);
	dv_font.DrawString(show, 620, 55);   //글자출력
}
