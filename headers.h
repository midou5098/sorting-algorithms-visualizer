#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1280










typedef struct {
    int i;
    int j;
    bool finished ;
    }bubbly;


void bubble(int table[],int size,bubbly *bubblestate);
bool checkmouse(int mx,int my,int lb,int rb,int tb,int bb);