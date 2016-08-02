#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <SDL2/SDL_mixer.h>
#include <string>

class MusicPlayer
{
public:
	MusicPlayer(std::string musicPath);
	~MusicPlayer();

	void PlayMusic(int loops = -1);
	void PauseMusic();
	void StopMusic();

	bool IsPlaying();
private:
	Mix_Music* music;
};

#endif // MUSIC_PLAYER_H
