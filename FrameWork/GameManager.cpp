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

	if ((fp = fopen("./Save/save.fss","rb"))== NULL)	//rb����� ���� ����
	{
		return ;
	}
	

	fclose(fp);
	
}

void GameManager::Update()
{
	//if(���� �����) g_Mng.n_Chap = OVER; 
}


void GameManager::Delete()
{
//	sound.g_pSoundManager->drr  

}
 



void GameManager::GameReset(void)  // ����� ���ӻ� ÷�� �ѹ���  �ʱ�ȭ�Ǵ� �κи� �־���.
{

}


void GameManager::Draw()
{
	//�� �� ī��Ʈ ���� ��Ÿ��(�׽�Ʈ)
	char show[20];
	//itoa(blocks.m_BlockCount, show, 10);
	dv_font.DrawString(show, 200, 210);   //�������	
	//����
	//itoa(blocks.score, show, 10);
	dv_font.DrawString(show, 200, 310);   //�������
}
