#pragma once

struct SysTem
{
	int m_Save1;
	int m_Save2;

};

class GameManager
{
	Sprite Menuimg[2];	//��������Ʈ�̹��� ����
public:
	GameManager(void);
	~GameManager(void);

	FILE *fp;	//������ ������ ���������� �غ�
	SysTem m_SysTem;	//������ ������ ����ü ����� ����

	bool m_Pause;	//���� ����
	int m_GameSpeed;
	
	DWORD GameTime;
	bool m_GameStart;

	bool m_Collision;

	void GameReset(void);
	void Init();
	void Update();	//������Ʈ ��ο� ���̺� �ʼ�
	void Draw();
	void Save();
	void Delete();
	
	
};

extern GameManager Gmanager;