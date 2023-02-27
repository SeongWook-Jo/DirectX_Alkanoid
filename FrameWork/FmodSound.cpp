#include "FMODENGIN//inc/fmod.hpp"
#pragma comment(lib, "FMODENGIN/lib/fmodex64_vc.lib")

using namespace FMOD;

#include "FmodSound.h"
#include <map>

class FmodSound
{
	System* m_pSystem;
	int m_Index;
	Channel* m_pBGChannel;
	float m_vloum;

public:
	std::map<std::string, int>m_CheckList;
	std::map<int, Sound* >m_SoundLIst;

	FmodSound()
	{
		System_Create(&m_pSystem);
		m_pSystem->init(10, FMOD_INIT_NORMAL, 0);
		m_Index = 0;
		m_vloum = 1.0f;
		m_pBGChannel = nullptr;
	}
	~FmodSound()
	{
		m_CheckList.clear();
		for (auto& lter : m_SoundLIst)
		{
			lter.second->release();
		}
		m_SoundLIst.clear();
		m_pSystem->release();
		m_pSystem->close();
	}
	//���� �߰�
	int AddSoundFile(std::string _FullPath, bool _IsLoop)
	{
		auto Find = m_CheckList.find(_FullPath);
		if (Find != m_CheckList.end())
		{
			return Find->second;
		}
		Sound* pSound = nullptr;

		int Mode = FMOD_HARDWARE | (_IsLoop ? FMOD_LOOP_NORMAL | FMOD_DEFAULT : FMOD_LOOP_OFF);

		m_pSystem->createSound(_FullPath.c_str(), Mode, 0, &pSound);

		if (pSound == nullptr)
		{
			return -1;
		}
		m_CheckList.insert(std::make_pair(_FullPath, m_Index));
		m_SoundLIst.insert(std::make_pair(m_Index, pSound));

		return m_Index++;
	}
	//ȿ�� ���� �÷���
	void EffectPlay(int _SoundNum)
	{
		auto Find = m_SoundLIst.find(_SoundNum);
		Channel* pChannel = nullptr;

		m_pSystem->playSound(FMOD_CHANNEL_FREE, Find->second, 0, &pChannel);
	}
	//����� �÷���
	void BGPlay(int _soundNum)
	{
		auto Find = m_SoundLIst.find(_soundNum); //���� ����Ʈ���� ������ ã��
		m_pSystem->playSound(FMOD_CHANNEL_REUSE, Find->second, 0, &m_pBGChannel);
	}
	//���� ��
	void VolumUp()
	{
		m_vloum += 0.1f; //���� 0.1�� ���ϱ�
		if (m_vloum <= 1.0) m_vloum = 1.0;
		m_pBGChannel->setVolume(m_vloum);
	}
	//���� �ٿ�
	void VolumDown()
	{
		m_vloum -= 0.1f; //���� 0.1�� ����
		if (m_vloum <= 0) m_vloum = 0;
		m_pBGChannel->setVolume(m_vloum);
	}
	//����� ����
	void BGStop()
	{
		if (m_pBGChannel != nullptr) // ��ä���� �ΰ��� �ƴϸ� ��ä�� ����
		{
			m_pBGChannel->stop();
		}
	}
};
static FmodSound g_SoundMgr;

//���� ���� �߰� �Լ�
int AddSoundFile(std::string _FullPath, bool _IsLoop)
{
	return g_SoundMgr.AddSoundFile(_FullPath, _IsLoop);
}
//���� ȿ���÷���
void EffectPlay(int _SoundNum)
{
	g_SoundMgr.EffectPlay(_SoundNum);
}
//���� ����� ���
void BGPlay(int _SoundNum)
{
	g_SoundMgr.BGPlay(_SoundNum);
}
//���� ���� ��
void VolumUp() {
	g_SoundMgr.VolumUp();
}
//���� ���� �ٿ�
void VolumDown() {
	g_SoundMgr.VolumDown();
}
//���� ������� ����
void BGStop() {
	g_SoundMgr.BGStop();
}