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
	
	DWORD GameTime;
	bool m_GameStart;

	bool m_Collision;

	void GameReset(void);
	void Init();
	void Update();	//������Ʈ ��ο� ���̺� �ʼ�
	void Draw();
	void Delete();
	
	
};

extern GameManager Gmanager;