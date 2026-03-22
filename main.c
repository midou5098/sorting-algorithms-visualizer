#include "headers.h"
int table[105];
bool bubbles =false;
int main(void){
    bubbly *bub=(bubbly*)malloc(sizeof(bubbly));
    for(int i=0;i<105;i++){
        table[i] = (rand() % 421) + 100;}
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window=NULL;
    SDL_Renderer* renderer=NULL;
    window=SDL_CreateWindow("fuckass sorter",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,0);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    
        SDL_Rect rect={}









    int running=true;
    SDL_Event event;
    int x=50;
    while (running) {
            SDL_PollEvent(&event);
            if (event.type==SDL_QUIT){
                running=false;}
            else if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_s){
                bubbles=true;}
            else if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e){
                bubbles=false;
            }

            SDL_RenderClear(renderer);
            
            SDL_SetRenderDrawColor(renderer,0,0,0,255);
            if (bubbles==true){
                bubble(table,105,bub);
            }
            for(int i=0;i<105;i++){
                x=i*12;
                int y=720-table[i];
                SDL_Rect rect ={x+10,y,10,table[i]};
                SDL_RenderFillRect(renderer,&rect);}
            
            SDL_RenderPresent(renderer);
            SDL_Delay(6);
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
           }


















}
