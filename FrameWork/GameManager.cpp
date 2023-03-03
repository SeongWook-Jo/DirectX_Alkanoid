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
	//���� Ŭ���� ����
	if (m_BlockCount == 0 && g_Mng.n_Chap == GAME) {	//�������� 0�� �Ǹ� �޴��� �Ѿ��
		NextStage();
	}
	if (m_BlockCount == 0 && g_Mng.n_Chap == GAME2) {	//�������� 0�� �Ǹ� �޴��� �Ѿ��
		GameClear();
	}
}

void GameManager::GameOver()
{
	g_Mng.n_Chap = OVER;	
}

//���� Ŭ����
void GameManager::GameClear()
{	
	g_Mng.n_Chap = CLEAR;	
}

//�� ������ ���� ���������� 
void GameManager::BallOver()
{
	deathCnt++;	// deathī��Ʈ +1
	if (g_Mng.n_Chap == GAME)	//����1�϶� ����1���� �� ��Ȱ
	{
		m_StageStart = false;
		g_Mng.n_Chap = GAME;
	}
	else if (g_Mng.n_Chap == GAME2)  //����2�϶� ����2���� �� ��Ȱ
	{
		m_StageStart = false;
		g_Mng.n_Chap = GAME2;
	}
	EffectPlay(sound.m_Death);

}

//���� ���� �ʱ�ȭ
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
	//��Ȱ
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
	dv_font.DrawString(show, 620, 55);   //�������
}
