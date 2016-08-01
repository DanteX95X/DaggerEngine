#ifndef SOUND_PLAYER_H
#define SOUND_PLAYER_H

#include <SDL2/SDL_mixer.h>
#include <string>

class SoundPlayer
{
public:
	SoundPlayer(std::string soundPath);
	SoundPlayer();
	~SoundPlayer();

	void PlaySound(int loops);
private:
	Mix_Chunk* sound;
};

#endif // SOUND_PLAYER_H
