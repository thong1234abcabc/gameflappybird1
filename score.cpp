#include "score.h"
#include <iostream>
#include<fstream>
#include<sstream>
using namespace std;


bool Score::loadFont(const string& path, int fontSize) {
    font = TTF_OpenFont(path.c_str(), fontSize);
    if (!font) {
        cout << "Không thể mở font: " << TTF_GetError() << endl;
        return false;
    }
    return true;
}

void Score::increase() {
    value++;
}

void Score::reset() {
    value = 0;
}

void Score::render(SDL_Renderer* renderer) {
    SDL_Color color = {255, 255, 255, 255};
    string text = "Score: " + to_string(value);

    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) return;

    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    SDL_Rect dstRect = {20, 20, w, h};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    SDL_DestroyTexture(texture);
}
void Score::renderHighScore(SDL_Renderer* renderer)
{
    if (!font) return;

    string text = "High Score: " + to_string(highScore);
    SDL_Color color = {255, 255, 0};

    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_Rect dest = {10, 50, w, h};

    SDL_RenderCopy(renderer, texture, NULL, &dest);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
void Score::destroy() {
    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }
}
void Score::loadHighScore(const string& filename)
{
    ifstream file(filename);
    if(file.is_open())
    {
        file>>highScore;
        file.close();
    }else {highScore=0;}
}
void Score::saveHighScore(const string& filename)
{
    if(value>highScore)
    {
        highScore=value;
        ofstream file(filename);
        if(file.is_open())
        {
            file<<highScore;
            file.close();
        }
    }
}
