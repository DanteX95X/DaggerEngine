#include "sound_player.h"
#include <assert.h>

SoundPlayer::SoundPlayer(std::string soundPath)
	:sound{Mix_LoadWAV(soundPath.c_str())}
{
	sound = Mix_LoadWAV(soundPath.c_str());
	assert(sound != nullptr);
}
SoundPlayer::SoundPlayer()
	: sound{nullptr}
{
}

SoundPlayer::~SoundPlayer()
{
	Mix_FreeChunk(sound);
}

void SoundPlayer::PlaySound(int loops)
{
	if(sound != nullptr)
		Mix_PlayChannel(-1, sound, loops);
}
