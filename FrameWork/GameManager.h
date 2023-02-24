#pragma once

class GameManager
{
	Sprite Menuimg[2];	//스프라이트이미지 띄우기
public:
	GameManager(void);
	~GameManager(void);

	FILE *fp;	//파일을 저장할 파일포인터 준비

	bool m_Pause;	//게임 멈춤
	int m_GameSpeed;

	int m_Score;

	int m_BlockCount = 65;
	
	DWORD GameTime;
	bool m_GameStart;

	bool m_Collision;

	bool m_StageStart;

	void NextStage();
	void Init();
	void Update();	//업데이트 드로우 세이브 필수
	void Draw();
	void Delete();
	void GameOver();
	
	
};

extern GameManager Gmanager;