#pragma once

class Sound
{
	
public:
	Sound(void);
	~Sound(void);

int m_Select;

//fmod����
int m_Back;	//�����
int m_Shoot; //���浹��		
int m_Death; //�� ������

	void Init();
	
};

extern Sound sound;