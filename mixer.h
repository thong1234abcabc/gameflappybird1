#ifndef MIXER_H
#define MIXER_H

#include<SDL_mixer.h>
#include<bits/stdc++.h>

using namespace std;

struct Mixer
{
    bool init();
    void quit();


    Mix_Music* LoadMusic(const string &file);
    Mix_Chunk* loadSound(const string &file);

    void playSound(Mix_Chunk* sound);
    void playMusic(Mix_Music* music);
    void freeMusic(Mix_Music* music);
    void freeSound(Mix_Chunk* sound);
};
#endif // MIXER_H
