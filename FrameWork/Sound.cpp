#include "Include.h"

Sound sound;

Sound::Sound(void)
{	
}

Sound::~Sound(void)
{
}

void Sound::Init()
{
	//사운드 불러오기
	// 배경음
	m_Back = AddSoundFile("./resource/Sound/BGM_0001.wav", true);
	// 볼충돌 효과음
	m_Shoot = AddSoundFile("./resource/Sound/sound-bounce.wav", false);
}

