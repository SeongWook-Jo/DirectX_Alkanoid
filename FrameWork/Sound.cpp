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
//	m_Back = AddSoundFile("./resource/Sound/BGM_0001.wav", true);
	// 볼충돌 효과음
	m_Shoot = AddSoundFile("./resource/Sound/sound-bounce.wav", false);
	m_barcol = AddSoundFile("./resource/Sound/sound_bar.mp3", false);
	m_graycol = AddSoundFile("./resource/Sound/sound_gray.mp3", false);
	//공 폭발음
	m_Death = AddSoundFile("./resource/Sound/death.mp3", false);
	//게임시작음
	m_Start = AddSoundFile("./resource/Sound/sound_round.mp3", false);
}

