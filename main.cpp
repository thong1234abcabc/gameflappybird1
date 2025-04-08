#include "graphics.h"
#include "mixer.h"
#include "resource.h"
#include "score.h"
#include "pipe.h"
#include "bird.h"
#include "land.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <ctime>
#include<iostream>

int main(int argc, char* argv[]) {
    srand(time(nullptr));
    Graphics graphics;
    graphics.init();
    Mixer mixer;
    mixer.init();
    TTF_Init();

    Resources res;
    if (!loadResources(res, graphics, mixer)) return -1;

    mixer.playMusic(res.nhacNen);
    bool quit=false;
    SDL_Event event;
    bool start=true;
    bool mouseClicked=false;
    int x, y;

while (start)
{
    graphics.renderTexture(res.startScreen, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    graphics.presentScene();

    while (SDL_PollEvent(&event))
    {
       SDL_GetMouseState(&x, &y);
                cout<<x<<" "<<y<<endl;

        if (event.type == SDL_QUIT) {
            SDL_Quit();
            return 0;
        }

        if (event.type==SDL_MOUSEBUTTONDOWN) {
            SDL_GetMouseState(&x, &y);
            if (x>48&&x<303&&y>111&&y<228) {
                mixer.playSound(res.modauSound);
                start=false;
            }
            else if (x>48&&x<303&&y>250&&y<360) {
                SDL_Quit();
                return 0;
            }
            else if(x>183&&x<303&&y>379&&y<450){
                bool inHelp=true;
                while (inHelp) {
                    graphics.renderTexture(res.helpTexture, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                    graphics.presentScene();

                    SDL_Event e;
                    while (SDL_PollEvent(&e)) {
                        if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN) {
                        inHelp=false;
                        }
                    }
                }
            }

        }
    }
}

    mixer.freeMusic(res.nhacNen);

    while (!quit) {

        Pipe pipe1(SCREEN_WIDTH, rand()%370+20, res.topPipe, res.bottomPipe);
        Pipe pipe2(SCREEN_WIDTH + SCREEN_WIDTH/2+65/2, rand()%370+20 , res.topPipe, res.bottomPipe);
        ScrollingLand land;
        land.setTexture(res.land);
        Bird bird;
        bird.init(res.bird, 3, BIRD_CLIPS);
        Score score;
        score.loadFont("arial.ttf", 36);
        score.reset();

        bool running=true;
        while (running) {
            score.loadHighScore("highScore.txt");
            while (SDL_PollEvent(&event)) {
                SDL_GetMouseState(&x, &y);
                cout<<x<<" "<<y<<endl;
                if (event.type==SDL_QUIT) quit=running=true;
                if ((event.type==SDL_KEYDOWN&&event.key.keysym.sym==SDLK_SPACE)||event.type==SDL_MOUSEBUTTONDOWN)
                    mixer.playSound(res.baySound), bird.jump();
            }

            bird.fall();
            bird.tick();
            land.scroll(3);
            pipe1.move(20);
            pipe2.move(20);

            if (!pipe1.passed&&pipe1.x+pipe1.width<55) {
                pipe1.passed=true;
                mixer.playSound(res.diemSound);
                score.increase();
            }
            if (!pipe2.passed&&pipe2.x+pipe2.width<55) {
                pipe2.passed=true;
                mixer.playSound(res.diemSound);
                score.increase();
            }

            if (pipe1.checkCollision(bird) || pipe2.checkCollision(bird)) {
                mixer.playSound(res.dieSound);
                running=true;
            }
            if(bird.position>=522-bird.getCurrentClip()->h)
            {
                mixer.playSound(res.dieSound);
                running=true;
                bird.position=522-bird.getCurrentClip()->h;
            }

            graphics.prepareScene(nullptr);
            graphics.renderTexture(res.background, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            pipe1.render(graphics);
            pipe2.render(graphics);
            graphics.renderland(land);
            graphics.renderBird(50, bird.position, bird);
            score.render(graphics.renderer);
            score.renderHighScore(graphics.renderer);
            graphics.presentScene();
            SDL_Delay(FRAME_DELAY);
            score.saveHighScore("highScore.txt");
        }

        graphics.renderTexture(res.background, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        pipe1.render(graphics);
        pipe2.render(graphics);
        graphics.renderland(land);
        graphics.renderBird(50, bird.position, bird);
        int w, h;
        SDL_QueryTexture(res.gameOver, nullptr, nullptr, &w, &h);
        graphics.renderTexture(res.gameOver, (SCREEN_WIDTH-w)/2,(SCREEN_HEIGHT-h)/2, w, h);
        score.render(graphics.renderer);
        score.renderHighScore(graphics.renderer);
        graphics.presentScene();

        while (SDL_WaitEvent(&event)) {
            if (event.type==SDL_QUIT) return 0;
            if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE||event.type==SDL_MOUSEBUTTONDOWN) break;
        }
    }

    freeResources(res);
    mixer.quit();
    graphics.quit();
    TTF_Quit();
    return 0;
}
