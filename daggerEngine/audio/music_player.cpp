#include "music_player.h"
#include <assert.h>

MusicPlayer::MusicPlayer(std::string musicPath)
	: music{Mix_LoadMUS(musicPath.c_str())}
{
	assert(music != nullptr);
}

MusicPlayer::~MusicPlayer()
{
	Mix_FreeMusic(music);
}

void MusicPlayer::PlayMusic(int loops)
{
	if(Mix_PlayingMusic())
		Mix_ResumeMusic();
	else
		Mix_PlayMusic(music, loops);
}

void MusicPlayer::PauseMusic()
{
	Mix_PauseMusic();
}

void MusicPlayer::StopMusic()
{
	Mix_HaltMusic();
}

bool MusicPlayer::IsPlaying()
{
	return Mix_PausedMusic() == 0;
}
