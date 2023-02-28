#pragma once

class GameManager
{	
	Sprite lifebarimg;	//스프라이트이미지 띄우기
public:
	GameManager(void);
	~GameManager(void);


	bool m_Pause;	//게임 멈춤
	int m_GameSpeed;

	int m_Score;

	int m_BlockCount = 65;
	
	DWORD GameTime;
	bool m_GameStart;
	int deathCnt = 0;	//부활을 위한 death카운트

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