#pragma once

//FMOD �����Ͻ� ����
#include <string>

int AddSoundFile(std::string FullPath, bool IsLoop = false);
void EffectPlay(int _SoundNum);
void BGPlay(int _soundNum);
void VolumUp();
void VolumDown();
void BGStop();
