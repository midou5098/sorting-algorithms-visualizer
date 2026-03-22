#include "headers.h"


void bubble(int table[],int size,bubbly *bubblestate){
    if(bubblestate->i==size-1){
        bubblestate->finished=true;
        return ;
    }
    int x;
    if (bubblestate->i<size){
        if (bubblestate->j<size-bubblestate->i-1){
            if(table[bubblestate->j+1]<table[bubblestate->j]){
                x=table[bubblestate->j];
                table[bubblestate->j]=table[bubblestate->j+1];
                table[bubblestate->j+1]=x;
                bubblestate->j++;
            }else{
                bubblestate->j++;}
            
            }
        else{
            bubblestate->j=0;
            bubblestate->i++;}
    }

        }
bool checkmouse(int mx,int my,int lb,int rb,int tb,int bb){
    if (lb<mx && mx<rb && my>tb && my<bb){
        return true;
    } 
    return false;
}

