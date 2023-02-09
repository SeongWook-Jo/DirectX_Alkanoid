#pragma once

struct SysTem
{
	int m_Save1;
	int m_Save2;

};

class GameManager
{
	Sprite Menuimg[2];	//스프라이트이미지 띄우기
public:
	GameManager(void);
	~GameManager(void);

	FILE *fp;	//파일을 저장할 파일포인터 준비
	SysTem m_SysTem;	//위에서 선언한 구조체 멤버들 변수

	bool m_Pause;	//게임 멈춤
	int m_GameSpeed;
	
	DWORD GameTime;
	bool m_GameStart;

	bool m_Collision;

	void GameReset(void);
	void Init();
	void Update();	//업데이트 드로우 세이브 필수
	void Draw();
	void Save();
	void Delete();
	
	
};

extern GameManager Gmanager;