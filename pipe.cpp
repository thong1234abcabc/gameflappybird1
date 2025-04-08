#include<SDL.h>
#include"pipe.h"
#include<iostream>
#include<cstdlib>
#include"graphics.h"
using namespace std;
Pipe::Pipe(int _x, int _y, SDL_Texture* top, SDL_Texture* bottom)
{
    x=_x;
    distanceY=_y;
    topPipe=top;
    bottomPipe=bottom;
    width=65;
    height=373;
    gap=139;
    passed=false;
}
void Pipe::render(Graphics& g) const
{
    g.renderTexture(topPipe, x, distanceY-height+55, width, height);
    g.renderTexture(bottomPipe, x, distanceY+gap+55, width, height);
}
void Pipe::move(int speed )
{
    x-=speed;
    if (x + width < 0)
    {
    int minGapY = 20;
    int maxGapY = SCREEN_HEIGHT - gap - 150;
    int newY = rand() % (maxGapY - minGapY + 1) + minGapY;
    reset(SCREEN_WIDTH, newY);
    }

}
bool Pipe::checkCollision(Bird bird)
{
    SDL_Rect birdRect={50, bird.position, bird.getCurrentClip()->w, bird.getCurrentClip()->h};

    SDL_Rect topPipeRect={x, distanceY-height+55, width, height};
    SDL_Rect bottomPipeRect={x, distanceY+gap+55, width, height};

    return SDL_HasIntersection(&birdRect, &topPipeRect)||SDL_HasIntersection(&birdRect, &bottomPipeRect);
}
void Pipe::reset(int newX, int newY)
{
    x=newX;
    distanceY=newY;
    passed=false;
}
