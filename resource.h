//tai tat ca texture, am thanh, font
#ifndef RESOURCE_H
#define RESOURCE_H

#include<SDL.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include"graphics.h"
#include"mixer.h"

struct Resources {
    SDL_Texture* background = nullptr;
    SDL_Texture* land=nullptr;
    SDL_Texture* bird=nullptr;
    SDL_Texture* gameOver=nullptr;
    SDL_Texture* startScreen=nullptr;
    SDL_Texture* topPipe=nullptr;
    SDL_Texture* bottomPipe=nullptr;
    SDL_Texture* helpTexture=nullptr;

    Mix_Chunk* dieSound=nullptr;
    Mix_Chunk* baySound=nullptr;
    Mix_Chunk* modauSound=nullptr;
    Mix_Chunk* diemSound=nullptr;

    Mix_Music* nhacNen=nullptr;

    TTF_Font* font=nullptr;

};
bool loadResources(Resources& src, Graphics& graphics, Mixer& mixer);
void freeResources(Resources& src);
#endif
