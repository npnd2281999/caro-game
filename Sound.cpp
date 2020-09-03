#include "Sound.h"

void Sound::playSound(string SoundName)
{
	SoundName += ".wav";
	PlaySound(SoundName.c_str(),NULL,SND_LOOP | SND_ASYNC);
}

void Sound::setVolume(int volume)
{
	waveOutSetVolume(NULL, volume*655);
}

void Sound::moveSound()
{
	PlaySound("cora.wav", NULL,SND_ASYNC);
}

