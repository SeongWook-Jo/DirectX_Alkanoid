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
	//공 폭발음
	m_Death = AddSoundFile("./resource/Sound/death.mp3", false);
	//게임시작음
	m_Start = AddSoundFile("./resource/Sound/start.mp3", false);
}

