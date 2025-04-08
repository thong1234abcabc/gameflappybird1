#include"land.h"
using namespace std;

void ScrollingLand::setTexture(SDL_Texture*_texture)
{
    texture=_texture;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

void ScrollingLand::scroll(int distance)
{
    scrollingOffset-=distance;
    if(scrollingOffset<=-width){
        scrollingOffset=0;
    }
}

