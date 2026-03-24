#include "headers.h"
int table[105];
bool bubbles =false,selected=false,inserted=false,merged=false,quicked=true;
int current_state=1;
int main(void){
    bubbly *bub=(bubbly*)malloc(sizeof(bubbly));
    selecty *selectful=(selecty*)malloc(sizeof(selecty));
    inserty *insertful=(inserty*)malloc(sizeof(inserty));
    mergy *mergyful=(mergy*)malloc(sizeof(mergy));
    quicky *quickful=(quicky*)malloc(sizeof(quicky));
    resetem(bub, selectful, insertful, mergyful,quickful, &bubbles, &selected, &inserted, &merged,&quicked);
    insertful->key = table[1];
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
    SDL_Rect rect6={800,50,100,50};
    SDL_Rect rect7={950,50,100,50};
    SDL_Rect rect8={1180,50,100,50};

    TTF_Font *font=TTF_OpenFont("/usr/share/fonts/liberation/LiberationSerif-Regular.ttf",20);
    SDL_Color text_color={0,0,0,255};
    SDL_Surface* surface=TTF_RenderText_Solid(font,"start",text_color);
    SDL_Texture* texture=SDL_CreateTextureFromSurface(renderer,surface);
    SDL_Surface* surface2=TTF_RenderText_Solid(font,"stop",text_color);
    SDL_Texture* texture2=SDL_CreateTextureFromSurface(renderer,surface2);
    SDL_Surface* surface3=TTF_RenderText_Solid(font,"bubble",text_color);
    SDL_Texture* texture3=SDL_CreateTextureFromSurface(renderer,surface3);
    SDL_Surface* surface4=TTF_RenderText_Solid(font,"selection",text_color);
    SDL_Texture* texture4=SDL_CreateTextureFromSurface(renderer,surface4);
    SDL_Surface* surface5=TTF_RenderText_Solid(font,"insert",text_color);
    SDL_Texture* texture5=SDL_CreateTextureFromSurface(renderer,surface5);
    SDL_Surface* surface6=TTF_RenderText_Solid(font,"merge",text_color);
    SDL_Texture* texture6=SDL_CreateTextureFromSurface(renderer,surface6);
    SDL_Surface* surface7=TTF_RenderText_Solid(font,"quick",text_color);
    SDL_Texture* texture7=SDL_CreateTextureFromSurface(renderer,surface7);
    SDL_Surface* surface8=TTF_RenderText_Solid(font,"reset ts",text_color);
    SDL_Texture* texture8=SDL_CreateTextureFromSurface(renderer,surface8);









    int running=true;
    SDL_Event event;
    int x=50;
    while (running) {
            while(SDL_PollEvent(&event)){
                if (event.type==SDL_QUIT){
                running=false;}
            else if (event.type==SDL_MOUSEBUTTONDOWN ){
                if (event.button.button ==SDL_BUTTON_LEFT){
                    if (checkmouse(event.button.x,event.button.y,50,150,50,100)==true){
                        switch(current_state){
                            case 1:
                                bubbles=true;
                                selected=false;
                                inserted=false;
                                merged=false;
                                quicked=false;
                                break;
                            case 2:
                                selected=true;
                                bubbles=false;
                                inserted=false;
                                merged=false;
                                quicked=false;
                                break;
                            case 3:
                                selected=false;
                                bubbles=false;
                                inserted=true;
                                merged=false;
                                quicked=false;
                                break;
                            case 4:
                                selected=false;
                                bubbles=false;
                                inserted=false;
                                merged=true;
                                quicked=false;
                                break;
                            case 5:
                                selected=false;
                                bubbles=false;
                                inserted=false;
                                merged=false;
                                quicked=true;
                                break;


                        }
                    }
                    else if (checkmouse(event.button.x,event.button.y,200,300,50,100)==true){
                        
                        resetem(bub, selectful, insertful, mergyful,quickful, &bubbles, &selected, &inserted, &merged,&quicked);                        insertful->key = table[1];
                    }else if(checkmouse(event.button.x,event.button.y,350,450,50,100)==true){
                        current_state=1;
                    }else if(checkmouse(event.button.x,event.button.y,500,600,50,100)==true){
                        current_state=2;
                    }else if(checkmouse(event.button.x,event.button.y,650,750,50,100)==true){
                        current_state=3;
                    }else if(checkmouse(event.button.x,event.button.y,800,900,50,100)==true){
                        current_state=4;
                    }else if(checkmouse(event.button.x,event.button.y,950,1050,50,100)==true){
                        current_state=5;
                    }
                    else if(checkmouse(event.button.x,event.button.y,1180,1280,50,100)==true){
                        
                        for(int i=0;i<105;i++){
                            
                            table[i] = (rand() % 421) + 100;
                            SDL_SetRenderDrawColor(renderer,0,0,0,255);
                            x=i*12;
                            int y=720-table[i];
                            SDL_Rect rect ={x+10,y,10,table[i]};
                            SDL_RenderFillRect(renderer,&rect);}
                            resetem(bub, selectful, insertful, mergyful,quickful, &bubbles, &selected, &inserted, &merged,&quicked);
                            insertful->key = table[1];
                    }
                
                
                
                
                
                
                
                }}}
            SDL_RenderClear(renderer);
            
            
            if (bubbles){
                bubble(table,105,bub);
            }else if (selected){
                selection(table,105,selectful);
            }else if(inserted){
                insert(table,105,insertful);
            }else if(merged){
                merge(table,105,mergyful);
            }else if(quicked){
                quick(table,105,quickful);
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
                else if(inserted){
                    x=i*12;
                    int y=720-table[i];
                    SDL_Rect rect ={x+10,y,10,table[i]};
                    if(i<insertful->i-1){
                        SDL_SetRenderDrawColor(renderer,0,255,0,255);
                    }else if(table[i]==insertful->key ){
                        SDL_SetRenderDrawColor(renderer,0,0,255,255);
                    }else if(i>insertful->i+1){
                        SDL_SetRenderDrawColor(renderer,255,0,0,255);
                    }else{
                        SDL_SetRenderDrawColor(renderer,0,0,0,255);
                    }
                    SDL_RenderFillRect(renderer,&rect);
                }else if (merged){
                    if (mergyful->finished){
                        for(int i=0;i<105;i++){
                            
                            SDL_SetRenderDrawColor(renderer,0,255,0,255);
                            x=i*12;
                            int y=720-table[i];
                            SDL_Rect rect ={x+10,y,10,table[i]};
                            SDL_RenderFillRect(renderer,&rect);}
                    }
                    x=i*12;
                    int y=720-table[i];
                    SDL_Rect rect ={x+10,y,10,table[i]};
                    if(mergyful->subphase==20){
                        if(i==mergyful->j || i==mergyful->i){
                            SDL_SetRenderDrawColor(renderer,0,0,255,255);
                        }else{
                            SDL_SetRenderDrawColor(renderer,0,0,0,255);
                        }
                    }else if(mergyful->subphase==21 || mergyful->subphase==22){
                        if(i==mergyful->i){
                            SDL_SetRenderDrawColor(renderer,0,0,255,255);
                        }else{
                            SDL_SetRenderDrawColor(renderer,0,0,0,255);
                        }
                    }else if(mergyful->subphase==23){
                        if(i == mergyful->left + mergyful->k){
                            SDL_SetRenderDrawColor(renderer,0,0,255,255);
                        }else{
                            SDL_SetRenderDrawColor(renderer,0,0,0,255);
                        }
                    }else{
                        SDL_SetRenderDrawColor(renderer,0,0,0,255);  // ← this is what's missing
                    }SDL_RenderFillRect(renderer,&rect);
                }else if (quicked){
                    for(int i=0;i<104;i++){
                        x=i*12;
                        int y=720-table[i];
                        SDL_Rect rect ={x+10,y,10,table[i]};
                        if(i==quickful->j){
                            SDL_SetRenderDrawColor(renderer,0,0,255,255);
                        }else if(i==quickful->right){
                            SDL_SetRenderDrawColor(renderer,255,0,0,255);
                        }else if (i < quickful->i){
                                SDL_SetRenderDrawColor(renderer,0,255,0,255);}
                        else if (i == quickful->j){
                                SDL_SetRenderDrawColor(renderer,0,0,255,255);}
                        else if (i == quickful->pivot_index){
                                SDL_SetRenderDrawColor(renderer,255,0,0,255);}
                        else{
                                SDL_SetRenderDrawColor(renderer,255,0,0,255);}
                        SDL_RenderFillRect(renderer,&rect);
                    }}
                else{
                    SDL_SetRenderDrawColor(renderer,0,0,0,255);
                    x=i*12;
                    int y=720-table[i];
                    SDL_Rect rect ={x+10,y,10,table[i]};
                    SDL_RenderFillRect(renderer,&rect);
            
                }
            
            
            
            
            
            
            
            }
            SDL_SetRenderDrawColor(renderer,90,90,90,40);
            SDL_RenderFillRect(renderer,&rect1);
            SDL_RenderFillRect(renderer,&rect2);
            SDL_RenderFillRect(renderer,&rect2);
            SDL_RenderFillRect(renderer,&rect3);
            SDL_RenderFillRect(renderer,&rect4);
            SDL_RenderFillRect(renderer,&rect5);
            SDL_RenderFillRect(renderer,&rect6);
            SDL_RenderFillRect(renderer,&rect7);
            SDL_RenderFillRect(renderer,&rect8);
            SDL_SetRenderDrawColor(renderer,60,60,60,255);
            SDL_RenderCopy(renderer,texture,NULL,&rect1);
            SDL_RenderCopy(renderer,texture2,NULL,&rect2);
            SDL_RenderCopy(renderer,texture3,NULL,&rect3);
            SDL_RenderCopy(renderer,texture4,NULL,&rect4);
            SDL_RenderCopy(renderer,texture5,NULL,&rect5);
            SDL_RenderCopy(renderer,texture6,NULL,&rect6);
            SDL_RenderCopy(renderer,texture7,NULL,&rect7);
            SDL_RenderCopy(renderer,texture8,NULL,&rect8);
            SDL_RenderPresent(renderer);
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            SDL_Delay(10);}
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
        SDL_FreeSurface(surface6);
        SDL_DestroyTexture(texture6);
        TTF_CloseFont(font);
        free(mergyful->temp);
        free(bub);
        free(selectful);
        free(insertful);
        free(mergyful);
        free(quickful);
        free(bub);
        TTF_Quit();
        SDL_Quit();}
            



















