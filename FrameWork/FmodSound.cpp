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
	//사우드 추가
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
	//효과 음악 플레이
	void EffectPlay(int _SoundNum)
	{
		auto Find = m_SoundLIst.find(_SoundNum);
		Channel* pChannel = nullptr;

		m_pSystem->playSound(FMOD_CHANNEL_FREE, Find->second, 0, &pChannel);
	}
	//배경음 플레이
	void BGPlay(int _soundNum)
	{
		auto Find = m_SoundLIst.find(_soundNum); //사운드 리스트에서 받은값 찾음
		m_pSystem->playSound(FMOD_CHANNEL_REUSE, Find->second, 0, &m_pBGChannel);
	}
	//볼륨 업
	void VolumUp()
	{
		m_vloum += 0.1f; //볼륨 0.1씩 더하기
		if (m_vloum <= 1.0) m_vloum = 1.0;
		m_pBGChannel->setVolume(m_vloum);
	}
	//볼륨 다운
	void VolumDown()
	{
		m_vloum -= 0.1f; //볼륨 0.1씩 빼기
		if (m_vloum <= 0) m_vloum = 0;
		m_pBGChannel->setVolume(m_vloum);
	}
	//배경음 멈춤
	void BGStop()
	{
		if (m_pBGChannel != nullptr) // 백채널이 널값이 아니면 백채널 멈춤
		{
			m_pBGChannel->stop();
		}
	}
};
static FmodSound g_SoundMgr;

//전역 사운드 추가 함수
int AddSoundFile(std::string _FullPath, bool _IsLoop)
{
	return g_SoundMgr.AddSoundFile(_FullPath, _IsLoop);
}
//전역 효과플레이
void EffectPlay(int _SoundNum)
{
	g_SoundMgr.EffectPlay(_SoundNum);
}
//전역 배경음 출력
void BGPlay(int _SoundNum)
{
	g_SoundMgr.BGPlay(_SoundNum);
}
//전역 볼륨 업
void VolumUp() {
	g_SoundMgr.VolumUp();
}
//전역 볼륨 다운
void VolumDown() {
	g_SoundMgr.VolumDown();
}
//전역 배경음악 멈춤
void BGStop() {
	g_SoundMgr.BGStop();
}