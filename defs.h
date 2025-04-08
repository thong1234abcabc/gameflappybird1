
#ifndef _DEFS__H
#define _DEFS__H

const int s_fps=15;
const int FRAME_DELAY=1000/s_fps;
const int SCREEN_WIDTH = 350;
const int SCREEN_HEIGHT = 550;
const int BIRD_CLIPS[3][4]=
{
    {0,0,60,42},
    {60,0,60,42},
    {120,0,60,42},

};
const int BIRD_FRAMES = sizeof(BIRD_CLIPS)/sizeof(int)/3;
#define WINDOW_TITLE "flappy bird"

#endif
