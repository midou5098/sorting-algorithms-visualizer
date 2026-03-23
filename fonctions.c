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

void merge(int table[],int size, mergy* m){
    if (m->finished){
        return;
    }
    if(m->stack_top=-1){
        m->finished=true;
        return;
    }
    m->left=m->stack[m->stack_top].left;
    m->right=m->stack[m->stack_top].right;
    m->phase=m->stack[m->stack_top].left;
    if (m->left==m->right){
        m->stack_top--;
        return;
    }
    m->mid=(m->left+m->right)/2;
    if (m->phase==0){
        m->stack[m->stack_top].phase=1;
        m->stack_top++;
        m->stack[m->stack_top].left=m->left;
        m->stack[m->stack_top].right=m->mid;
        m->stack[m->stack_top].phase=0;
    }else if(m->phase==1){
        m->stack[m->stack_top].phase=2;
        m->stack_top++;
        m->stack[m->stack_top].left=m->mid+1;
        m->stack[m->stack_top].right=m->right;
        m->stack[m->stack_top].phase=0;
    }else if(m->phase==2){
        m->i = m->left;
        m->j =m->mid + 1;
        m->k =0;
        m->subphase =2.0;
        if(merge_step(table,m)){
            m->stack_top--;
        }
    }}


void merge_step(int table[],mergy* m){
    
    if (m->subphase==2.0){
        if(m->i>m->mid || m->j>m->right){
            if(m->i>m->mid){
                m->subphase=2.1;
                return;

            }else if(m->j>m->right){
                m->subphase=2.2;
                return;
            }
        }
        if (table[m->i]<table[m->j]){
            m->temp[m->k]=table[m->i];
            m->i++;
            m->k++;
        }else{
            m->temp[m->k]=table[m->j];
            m->j++;
            m->k++;
        }
        return;
    }else if (m->subphase==2.1){
        m->temp[m->k]=table[m->i];
        m->i++;
        m->k++;
        m->temp_size++;
        if(m->i>m->mid){
            m->k=0;
            m->subphase=2.3;}
        
        return;
    }else if (m->subphase==2.2){
        m->temp[m->k]=table[m->j];
        m->j++;
        m->k++;
        m->temp_size++;
        if(m->j>m->right){
            m->k=0;
            m->subphase=2.3;}
    return;}
    else if (m->subphase==2.3){
        table[m->left+m->k]=m->temp[m->k];
        m->k++;

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


