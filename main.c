#include "headers.h"
int table[105];
bool bubbles =false;
int main(void){
    bubbly *bub=(bubbly*)malloc(sizeof(bubbly));
    bub->i = 0;
    bub->j = 0;
    bub->finished = false;
    for(int i=0;i<105;i++){
        table[i] = (rand() % 421) + 100;}
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window=NULL;
    SDL_Renderer* renderer=NULL;
    window=SDL_CreateWindow("fuckass sorter",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,0);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    
    SDL_Rect rect1={50,50,100,50};
    SDL_Rect rect2={200,50,100,50};
    TTF_Font *font=TTF_OpenFont("/usr/share/fonts/liberation/LiberationSerif-Regular.ttf",20);
    SDL_Color text_color={0,0,0,255};
    SDL_Surface* surface=TTF_RenderText_Solid(font,"start",text_color);
    SDL_Texture* texture=SDL_CreateTextureFromSurface(renderer,surface);
    SDL_Surface* surface2=TTF_RenderText_Solid(font,"stop",text_color);
    SDL_Texture* texture2=SDL_CreateTextureFromSurface(renderer,surface2);











    int running=true;
    SDL_Event event;
    int x=50;
    while (running) {
            if(SDL_PollEvent(&event)){
                if (event.type==SDL_QUIT){
                running=false;}
            else if (event.type==SDL_MOUSEBUTTONDOWN ){
                if (event.button.button ==SDL_BUTTON_LEFT){
                    if (checkmouse(event.button.x,event.button.y,50,150,50,100)==true){
                        bubbles=true;
                    }
                    else if (checkmouse(event.button.x,event.button.y,200,300,50,100)==true){
                        bubbles=false;
                        bub->i = 0;
                        bub->j = 0;
                        bub->finished = false;}}}}
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
            SDL_SetRenderDrawColor(renderer,60,60,60,255);
            SDL_RenderFillRect(renderer, &rect1);
            SDL_RenderFillRect(renderer, &rect2);
            SDL_RenderCopy(renderer,texture,NULL,&rect1);
            SDL_RenderCopy(renderer,texture2,NULL,&rect2);
            SDL_RenderPresent(renderer);
            SDL_Delay(6);
            SDL_SetRenderDrawColor(renderer,255,255,255,255);}
        SDL_DestroyTexture(texture);
        SDL_DestroyTexture(texture2);
        SDL_FreeSurface(surface);
        SDL_FreeSurface(surface2);
        TTF_CloseFont(font);
        free(bub);
        TTF_Quit();
        SDL_Quit();}
            



















