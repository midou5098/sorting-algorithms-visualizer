#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>






typedef struct {
    int i;
    int j;
    int key;
    bool finished;
}inserty;


void insert(int table[],int size,inserty* i);
void resetem(bubbly *bub,selecty* selectful,inserty* insertful,bool *bubbles,bool *select,bool *insert);
void bubble(int table[],int size,bubbly *bubblestate);
bool checkmouse(int mx,int my,int lb,int rb,int tb,int bb);
void selection(int table[],int size,selecty* select);