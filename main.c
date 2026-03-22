#include "headers.h"
int table[105];
bool bubbles =false,selected=false;
int current_state=1;
int main(void){
    bubbly *bub=(bubbly*)malloc(sizeof(bubbly));
    selecty *selectful=(selecty*)malloc(sizeof(selecty));
    selectful->i=0;
    selectful->j=0;
    selectful->min=0;
    selectful->finished=false;
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
    SDL_Rect rect3={350,50,100,50};
    SDL_Rect rect4={500,50,100,50};
    SDL_Rect rect5={650,50,100,50};

    TTF_Font *font=TTF_OpenFont("/usr/share/fonts/liberation/LiberationSerif-Regular.ttf",20);
    SDL_Color text_color={0,0,0,255};
    SDL_Surface* surface=TTF_RenderText_Solid(font,"start",text_color);
    SDL_Texture* texture=SDL_CreateTextureFromSurface(renderer,surface);
    SDL_Surface* surface2=TTF_RenderText_Solid(font,"stop",text_color);
    SDL_Texture* texture2=SDL_CreateTextureFromSurface(renderer,surface2);
    SDL_Surface* surface3=TTF_RenderText_Solid(font,"bubble sort",text_color);
    SDL_Texture* texture3=SDL_CreateTextureFromSurface(renderer,surface3);
    SDL_Surface* surface4=TTF_RenderText_Solid(font,"selection sort",text_color);
    SDL_Texture* texture4=SDL_CreateTextureFromSurface(renderer,surface4);
    SDL_Surface* surface5=TTF_RenderText_Solid(font,"reset ts",text_color);
    SDL_Texture* texture5=SDL_CreateTextureFromSurface(renderer,surface5);











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
                        switch(current_state){
                            case 1:
                                bubbles=true;
                                selected=false;
                                break;
                            case 2:
                                selected=true;
                                bubbles=false;
                                break;

                        }
                    }
                    else if (checkmouse(event.button.x,event.button.y,200,300,50,100)==true){
                        bubbles=false;
                        bub->i = 0;
                        bub->j = 0;
                        bub->finished = false;
                        selectful->i=0;
                        selectful->j=0;
                        selectful->min=0;
                        selectful->finished=false;
                    }else if(checkmouse(event.button.x,event.button.y,350,450,50,100)==true){
                        current_state=1;
                    }else if(checkmouse(event.button.x,event.button.y,500,600,50,100)==true){
                        current_state=2;
                    }else if(checkmouse(event.button.x,event.button.y,650,750,50,100)==true){
                        
                        for(int i=0;i<105;i++){
                            bubbles=false;
                            bub->i = 0;
                            bub->j = 0;
                            bub->finished = false;
                            selectful->i=0;
                            selectful->j=0;
                            selectful->min=0;
                            selectful->finished=false;
                            table[i] = (rand() % 421) + 100;
                            SDL_SetRenderDrawColor(renderer,0,0,0,255);
                            x=i*12;
                            int y=720-table[i];
                            SDL_Rect rect ={x+10,y,10,table[i]};
                            SDL_RenderFillRect(renderer,&rect);}
                    }
                
                
                
                
                
                
                
                }}}
            SDL_RenderClear(renderer);
            
            
            if (bubbles==true){
                bubble(table,105,bub);
            }else if (selected==true){
                selection(table,105,selectful);
            }
            for(int i=0;i<105;i++){
                if(bubbles){
                    x=i*12;
                    int y=720-table[i];
                    SDL_Rect rect ={x+10,y,10,table[i]};
                    if(i>=105-bub->i){
                        SDL_SetRenderDrawColor(renderer,0,255,0,255);
                    }else if(i==bub->j ||i==bub->j+1){
                        SDL_SetRenderDrawColor(renderer,0,0,255,255);
                    }else{
                        SDL_SetRenderDrawColor(renderer,255,0,0,255);
                    }
                    SDL_RenderFillRect(renderer,&rect);}
                else if(selected){
                    x=i*12;
                    int y=720-table[i];
                    SDL_Rect rect ={x+10,y,10,table[i]};
                    if(i<selectful->i){
                        SDL_SetRenderDrawColor(renderer,0,255,0,255);
                    }else if(i==selectful->j ){
                        SDL_SetRenderDrawColor(renderer,0,0,255,255);
                    }else if(i==selectful->min){
                        SDL_SetRenderDrawColor(renderer,0,0,0,255);
                    }else{
                        SDL_SetRenderDrawColor(renderer,255,0,0,255);
                    }
                    SDL_RenderFillRect(renderer,&rect);}
                else{
                    SDL_SetRenderDrawColor(renderer,0,0,0,255);
                    x=i*12;
                    int y=720-table[i];
                    SDL_Rect rect ={x+10,y,10,table[i]};
                    SDL_RenderFillRect(renderer,&rect);
            
                }
            
            
            
            
            
            
            
            }
            SDL_SetRenderDrawColor(renderer,60,60,60,255);
            SDL_RenderFillRect(renderer, &rect1);
            SDL_RenderFillRect(renderer, &rect2);
            SDL_RenderCopy(renderer,texture,NULL,&rect1);
            SDL_RenderCopy(renderer,texture2,NULL,&rect2);
            SDL_RenderCopy(renderer,texture3,NULL,&rect3);
            SDL_RenderCopy(renderer,texture4,NULL,&rect4);
            SDL_RenderCopy(renderer,texture5,NULL,&rect5);

            SDL_RenderPresent(renderer);
            SDL_SetRenderDrawColor(renderer,255,255,255,255);}
        SDL_DestroyTexture(texture);
        SDL_DestroyTexture(texture2);
        SDL_FreeSurface(surface);
        SDL_FreeSurface(surface2);
        SDL_FreeSurface(surface3);
        SDL_DestroyTexture(texture3);
        SDL_FreeSurface(surface4);
        SDL_DestroyTexture(texture4);
        SDL_FreeSurface(surface5);
        SDL_DestroyTexture(texture5);
        TTF_CloseFont(font);
        free(bub);
        TTF_Quit();
        SDL_Quit();}
            



















