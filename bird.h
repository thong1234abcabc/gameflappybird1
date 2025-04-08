#ifndef BIRD_H
#define BIRD_H
#include<SDL.h>
#include<vector>
using namespace std;

struct Bird
{
    SDL_Texture* texture;
    vector<SDL_Rect> clips;
    int currentFrame=0;
    int tocdonhay=0;
    int position=200;
    int trongluc=2;
    int donhay=-10;
    void init(SDL_Texture* _texture, int frames, const int _clips[][4]);
    void tick();
    void jump();
    void fall();
    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }

 };

#endif // BIRD_H
