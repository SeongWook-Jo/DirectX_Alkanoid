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
	//���� �ҷ�����
	// �����
	m_Back = AddSoundFile("./resource/Sound/BGM_0001.wav", true);
	// ���浹 ȿ����
	m_Shoot = AddSoundFile("./resource/Sound/sound-bounce.wav", false);
	//�� ������
	m_Death = AddSoundFile("./resource/Sound/death.mp3", false);
	//���ӽ�����
	m_Start = AddSoundFile("./resource/Sound/start.mp3", false);
}

