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
	m_BlockCount = round2.m_BlockCount;
	g_Mng.n_Chap = GAME2;
}

void GameManager::Init()
{

	if ((fp = fopen("./Save/save.fss", "rb")) == NULL)	//rb����� ���� ����
	{
		return;
	}


	fclose(fp);

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
	if (m_BlockCount < 20 && g_Mng.n_Chap == GAME2) {	//�������� 0�� �Ǹ� �޴��� �Ѿ��
		GameOver();
	}
}


void GameManager::Delete()
{
	//	sound.g_pSoundManager->drr  

}

void GameManager::GameOver()
{
	m_StageStart = false;
	m_BlockCount = 65;
	g_Mng.n_Chap = OVER;
	round1.Init();
	round2.Init();
}


void GameManager::Draw()
{
	//�� �� ī��Ʈ ���� ��Ÿ��(�׽�Ʈ)
	char show[20];

	//itoa(round1.m_BlockCount, show, 10);
	//dv_font.DrawString(show, 200, 210);   //�������	

	//itoa(round2.m_BlockCount, show, 10);
	//dv_font.DrawString(show, 200, 230);   //�������

	itoa(m_Score, show, 10);
	dv_font.DrawString(show, 620, 55);   //�������
}
