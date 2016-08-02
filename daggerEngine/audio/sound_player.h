#ifndef SOUND_PLAYER_H
#define SOUND_PLAYER_H

#include <SDL2/SDL_mixer.h>
#include <string>
#include "actor/actor.h"

class SoundPlayer
{
public:
	SoundPlayer(std::string soundPath);
	~SoundPlayer();

	void PlaySound(int loops = 0);
private:
	Mix_Chunk* sound;
};

#endif // SOUND_PLAYER_H
