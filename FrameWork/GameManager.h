#pragma once

class GameManager
{	
	Sprite lifebarimg;	//��������Ʈ�̹��� ����
public:
	GameManager(void);
	~GameManager(void);


	bool m_Pause;	//���� ����
	int m_GameSpeed;

	int m_Score;

	int m_BlockCount = 65;
	
	DWORD GameTime;
	bool m_GameStart;
	int deathCnt = 0;	//��Ȱ�� ���� deathī��Ʈ

	bool m_Collision;

	bool m_StageStart;

	void NextStage();
	void Init();
	void Update();
	void Draw();
	void Delete();
	void GameOver();
	void GameReset();
	void BallOver();	
	void GameClear();
	
};

extern GameManager Gmanager;