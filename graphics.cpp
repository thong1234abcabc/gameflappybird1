
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include"bird.h"
#include "graphics.h"

//Graphics
void Graphics::logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

void Graphics::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logErrorAndExit("SDL_Init", SDL_GetError());

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        //full screen
        //window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
            logErrorAndExit( "SDL_image error:", IMG_GetError());

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
        //Khi chạy trong máy ảo (ví dụ phòng máy ở trường)
        //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

    if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void Graphics::prepareScene(SDL_Texture * background)
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy( renderer, background, NULL, NULL);
}

void Graphics::presentScene()
{
    SDL_RenderPresent(renderer);
}

SDL_Texture* Graphics::loadTexture(const char* filename) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, filename);
    if (!texture) {
        std::cout << "IMG_LoadTexture lỗi: " << IMG_GetError() << std::endl;
    }
    return texture;
}


void Graphics::renderTexture(SDL_Texture *texture, int x, int y, int w, int h)
{
    SDL_Rect dest;

    dest.x=x;
    dest.y=y;
    dest.w=w;
    dest.h=h;

    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void Graphics::blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    dest.w = src->w;
    dest.h = src->h;

    SDL_RenderCopy(renderer, texture, src, &dest);
}

void Graphics::quit()
{
    IMG_Quit();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Graphics::renderland(const ScrollingLand& bgr)
{
    SDL_Rect dst1 = { bgr.scrollingOffset, SCREEN_HEIGHT - bgr.height+110, bgr.width, bgr.height };
    SDL_Rect dst2 = { bgr.scrollingOffset + bgr.width, SCREEN_HEIGHT - bgr.height+110, bgr.width, bgr.height };

    SDL_RenderCopy(renderer, bgr.texture, nullptr, &dst1);
    SDL_RenderCopy(renderer, bgr.texture, nullptr, &dst2);

}
void Graphics::renderBird(int x, int y, const Bird& bird)
{
    const SDL_Rect* clip=bird.getCurrentClip();
    SDL_Rect renderQuad={x,y,clip->w, clip->h};
    SDL_RenderCopy(renderer, bird.texture, clip, &renderQuad);
}






