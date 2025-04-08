#ifndef SCORE_H
#define SCORE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
using namespace std;
struct Score {
    int value;
    int highScore;
    TTF_Font* font;

    bool loadFont(const string& path, int fontSize);
    void increase();
    void reset();
    void render(SDL_Renderer* renderer);
    void renderHighScore(SDL_Renderer* renderer);
    void destroy();
    void loadHighScore(const string& filename);
    void saveHighScore(const string& filename);
};

#endif
