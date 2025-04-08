#ifndef LAND_H
#define LAND_H

#include<SDL.h>
using namespace std;
struct ScrollingLand
{
    SDL_Texture* texture;
    int scrollingOffset=0;
    int width, height;

    void setTexture(SDL_Texture* _texture);
    void scroll(int distance);
};


#endif // LAND_H
