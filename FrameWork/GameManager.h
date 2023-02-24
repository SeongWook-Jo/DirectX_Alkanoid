#pragma once

class GameManager
{
	Sprite Menuimg[2];	//��������Ʈ�̹��� ����
public:
	GameManager(void);
	~GameManager(void);

	FILE *fp;	//������ ������ ���������� �غ�

	bool m_Pause;	//���� ����
	int m_GameSpeed;

	int m_Score;

	int m_BlockCount = 65;
	
	DWORD GameTime;
	bool m_GameStart;

	bool m_Collision;

	bool m_StageStart;

	void NextStage();
	void Init();
	void Update();	//������Ʈ ��ο� ���̺� �ʼ�
	void Draw();
	void Delete();
	void GameOver();
	
	
};

extern GameManager Gmanager;