#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>




typedef struct{
    int left;
    int right;
    int pivot;
}stacky;
typedef struct{
    stacky stack[200];
    int stack_top;
    int phase;
    int left;
    int right;
    int pivot;
    int i;
    int j;
}quicky;

typedef struct {
    int i;
    int j;
    int key;
    bool finished;
}inserty;



typedef struct {
    int i;
    int j;
    int min;
    bool finished ;
}selecty;

typedef struct {
    int i;
    int j;
    bool finished ;
    }bubbly;
//         starting merge and quick sort , god help me..
typedef struct{
    int left;
    int right;
    int phase;
}stackbox;

typedef struct{
    stackbox stack[200];
    int stack_top;
    
    
    int left,right;
    int phase;
    int subphase;
    
    
    
    int mid; 
    int i,j,k;
    int *temp;
    int temp_size;
    bool finished;


}mergy;









void insert(int table[],int size,inserty* i);
void resetem(bubbly *bub,selecty* selectful,inserty* insertful,mergy* mergyful,bool *bubbles,bool *select,bool *insert,bool *merged);
void bubble(int table[],int size,bubbly *bubblestate);
bool checkmouse(int mx,int my,int lb,int rb,int tb,int bb);
void selection(int table[],int size,selecty* select);
bool merge_step(int table[],mergy* m);
void merge(int table[],int size, mergy* m);