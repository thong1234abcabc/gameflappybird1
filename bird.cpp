#include"bird.h"
using namespace std;
void Bird::init(SDL_Texture* _texture, int frames, const int _clips[][4])
{
    texture=_texture;
    SDL_Rect clip;
    for(int i=0; i<frames; i++)
    {
        clip.x=_clips[i][0];
        clip.y=_clips[i][1];
        clip.w=_clips[i][2];
        clip.h=_clips[i][3];
        clips.push_back(clip);
    }
}
void Bird::tick()
{
    currentFrame=(currentFrame+1)%clips.size();
}
void Bird::jump()
{
    tocdonhay=donhay;
}
void Bird::fall()
{
    tocdonhay+=trongluc;
    position+=tocdonhay;
}
