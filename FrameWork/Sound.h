#pragma once

class Sound
{
	
public:
	Sound(void);
	~Sound(void);

int m_Select;

//fmod사운드
int m_Back;	//배경음
int m_Shoot; //공충돌음		
int m_Death; //공 폭발음

	void Init();
	
};

extern Sound sound;