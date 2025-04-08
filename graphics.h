#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include"land.h"
#include <SDL_image.h>
#include "defs.h"
#include"bird.h"
#include<vector>
#include<SDL_mixer.h>

using namespace std;



struct Graphics {
    SDL_Renderer *renderer;
	SDL_Window *window;

	void logErrorAndExit(const char* msg, const char* error);
	void init();
	void prepareScene(SDL_Texture * background);
    void presentScene();
    SDL_Texture *loadTexture(const char *filename);
    void renderTexture(SDL_Texture *texture, int x, int y, int w, int h);
    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);
    void quit();
    void renderland(const ScrollingLand& bgr);
    void renderBird(int x, int y, const Bird& bird);
};



#endif // _GRAPHICS__H
