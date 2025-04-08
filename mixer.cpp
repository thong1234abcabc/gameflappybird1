#include<bits/stdc++.h>
#include<SDL_mixer.h>
#include"mixer.h"
using namespace std;

bool Mixer::init()
{
    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096)<0)
    {
        cout<<"khong the khoi tao SDL Mixer"<<Mix_GetError();
        return false;
    }
    return true;
}
void Mixer::quit()
{
    Mix_CloseAudio();
}
Mix_Music* Mixer::LoadMusic(const string &file)
{
    Mix_Music* music=Mix_LoadMUS(file.c_str());
    return music;
}
Mix_Chunk* Mixer::loadSound(const string &file)
{
    Mix_Chunk* sound=Mix_LoadWAV(file.c_str());
    return sound;
}
void Mixer::playMusic(Mix_Music* music)
{
    if(music!=nullptr)
    {
        if(Mix_PlayMusic(music, -1)==-1)
        {
            cout<<"khong the phat am thanh"<<Mix_GetError()<<endl;
        }
    }
}
void Mixer::playSound(Mix_Chunk* sound)
{
    if(sound!=nullptr)
    {
        if(Mix_PlayChannel(-1,sound, 0)==-1)
        {
            cout<<"Khong the phat am thanh"<<Mix_GetError()<<endl;
        }
    }
}
void Mixer::freeMusic(Mix_Music* music)
{
    if(music!=nullptr)
    {
        Mix_FreeMusic(music);
        music=nullptr;
    }
}
void Mixer::freeSound (Mix_Chunk* sound)
{
    if(sound!=nullptr)
    {
        Mix_FreeChunk(sound);
        sound=nullptr;
    }
}
