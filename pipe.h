#ifndef PIPE_H
#define PIPE_H
#include"graphics.h"
struct Pipe
{
    int x;
    int distanceY; //vi tri khoang trong
    int width;
    int height;
    int gap; //khong cach giua hai ong
    SDL_Texture* topPipe;
    SDL_Texture* bottomPipe;
    bool passed;

    Pipe(int _x, int _y, SDL_Texture* top, SDL_Texture* bottom);
    void render(Graphics& g) const;
    void move(int speed);
    bool checkCollision(Bird bird);
    void reset(int newX, int newY);
};
#endif // PIPE_H
