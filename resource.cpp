#include "resource.h"
#include "graphics.h"
#include "mixer.h"
#include <iostream>


bool loadResources(Resources& src, Graphics& graphics, Mixer& mixer) {
    src.background=graphics.loadTexture("image/background_n.png");
    src.land=graphics.loadTexture("image/land.png");
    src.bird=graphics.loadTexture("image/bird.png");
    src.gameOver=graphics.loadTexture("image/gameOVer.png");
    src.startScreen=graphics.loadTexture("image/start_background.png");
    src.topPipe=graphics.loadTexture("image/ongtren.png");
    src.bottomPipe=graphics.loadTexture("image/ongduoi.png");
    src.helpTexture=graphics.loadTexture("image/help.png");

    src.dieSound=mixer.loadSound("sound/sound_chet.wav");
    src.baySound=mixer.loadSound("sound/sound_bay.wav");
    src.modauSound=mixer.loadSound("sound/modau_sound.wav");
    src.diemSound=mixer.loadSound("sound/sound_diem.wav");

    src.nhacNen=mixer.LoadMusic("sound/nhacnen.mp3");

    src.font=TTF_OpenFont("arial.ttf", 36);
    return true;
}

void freeResources(Resources& src) {
    SDL_DestroyTexture(src.background);
    SDL_DestroyTexture(src.land);
    SDL_DestroyTexture(src.bird);
    SDL_DestroyTexture(src.gameOver);
    SDL_DestroyTexture(src.startScreen);
    SDL_DestroyTexture(src.topPipe);
    SDL_DestroyTexture(src.bottomPipe);
    SDL_DestroyTexture(src.helpTexture);

    Mix_FreeChunk(src.dieSound);
    Mix_FreeChunk(src.baySound);
    Mix_FreeChunk(src.modauSound);
    Mix_FreeChunk(src.diemSound);

    Mix_FreeMusic(src.nhacNen);

    if (src.font) TTF_CloseFont(src.font);
}
