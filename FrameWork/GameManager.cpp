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

	//if ((fp = fopen("./Save/save.fss", "rb")) == NULL)	//rb����� ���� ����
	//{
	//	return;
	//}
	//fclose(fp);
}

void GameManager::Update()
{
	//���� Ŭ���� ����
	//if (m_BlockCount == 0 && g_Mng.n_Chap == GAME) {	//�������� 0�� �Ǹ� �޴��� �Ѿ��
	//	NextStage();
	//}
	//if (m_BlockCount == 0 && g_Mng.n_Chap == GAME2) {	//�������� 0�� �Ǹ� �޴��� �Ѿ��
	//	GameOver();
	//}

	//�ӽ� Ŭ��������
	if (m_BlockCount < 60 && g_Mng.n_Chap == GAME) {	//�������� 0�� �Ǹ� �޴��� �Ѿ��
		
		NextStage();
	}
	if (m_BlockCount < 85 && g_Mng.n_Chap == GAME2) {	//�������� 0�� �Ǹ� �޴��� �Ѿ��
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

	//�� �� ī��Ʈ ���� ��Ÿ��(�׽�Ʈ)
	char show[20];

	//itoa(round1.m_BlockCount, show, 10);
	//dv_font.DrawString(show, 200, 210);   //�������	

	//itoa(round2.m_BlockCount, show, 10);
	//dv_font.DrawString(show, 200, 230);   //�������

	itoa(m_Score, show, 10);
	dv_font.DrawString(show, 620, 55);   //�������
}
