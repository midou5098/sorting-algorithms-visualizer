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
            bubblestate->i++;}}}
void selection(int table[],int size,selecty* select){
    if(select->finished==true){
        return;
    }
    int x;
    if (select->j<size){
        if (table[select->j]<table[select->min])
            select->min=select->j;
        select->j++;
        return;
    
    }
    
    x=table[select->i];
    table[select->i]=table[select->min];
    table[select->min]=x;
    select->i++;
    if(select->i<size){
        select->min=select->i;
        select->j=select->i+1;

    }else{
        select->finished=true;
    }
    
    

        
 

}
void insert(int table[],int size,inserty* i)
{
    if (i->finished){
        return;
    }
    
    if (table[i->j]>i->key && i->j>=0)
    {
        table[i->j+1]=table[i->j];
        i->j--;
        
        return;
    }else{
        table[i->j+1]=i->key;
        if (i->i<size-1){
            i->i++;
            i->j=i->i-1;
            i->key=table[i->i];
        

        }else{
            i->finished=true;
        }
        
    } 
       
}























void resetem(bubbly *bub,selecty* selectful,inserty* insertful,bool *bubbles,bool *select,bool *insert){
    *bubbles=false;
    bub->i = 0;
    bub->j = 0;
    bub->finished = false;
    *select=false;
    selectful->i=0;
    selectful->j=0;
    selectful->min=0;
    selectful->finished=false;
    *insert=false;
    insertful->finished=false;
    insertful->i=1;
    insertful->j=0;
}



























bool checkmouse(int mx,int my,int lb,int rb,int tb,int bb){
    if (lb<mx && mx<rb && my>tb && my<bb){
        return true;
    } 
    return false;
}


