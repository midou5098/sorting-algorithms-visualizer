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
    if(m->stack_top==-1){
        m->finished=true;
        return;
    }
    if (m->subphase != 0){
        if (merge_step(table,m)){
            m->subphase=0;
            m->stack_top--;
        }
        return;
    }
    m->left=m->stack[m->stack_top].left;
    m->right=m->stack[m->stack_top].right;
    m->phase=m->stack[m->stack_top].phase;
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
        int temp_size = m->right - m->left + 1;
        if (m->subphase == 0) {
            m->i = m->left;
            m->j = m->mid + 1;
            m->k = 0;
            m->subphase = 20;}

    }}


bool merge_step(int table[],mergy* m){
    
    if (m->subphase==20){
        if(m->i>m->mid || m->j>m->right){
            if(m->i>m->mid){
                m->subphase=22;
                return false;

            }else if(m->j>m->right){
                m->subphase=21;
                return false;
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
        return false;
    }else if (m->subphase==21){
        m->temp[m->k]=table[m->i];
        m->i++;
        m->k++;
        if(m->i>m->mid){
            m->subphase=22;}
        
        return false;
    }else if (m->subphase==22){
        m->temp[m->k]=table[m->j];
        m->j++;
        m->k++;
        if(m->j>m->right){
            m->temp_size=m->right-m->left +1;
            m->k=0;
            m->subphase=23;
        }
        return false;
        
    }
    else if (m->subphase==23){
        if(m->k==m->temp_size){
            return true;
        }
        table[m->left+m->k]=m->temp[m->k];
        m->k++;
        return false;

    }


}

    

void quick(int table[],int size,quicky* q){
    if (q->finished==true){
        return;
    }
    q->left=q->std[q->stack_top].left;
    q->right=q->std[q->stack_top].right;
    q->pivot_index=q->right;
    q->pivot=table[q->pivot_index];
    int x;
    if (q->phase==0){
        if(q->init==true){
            q->pivot = table[q->right];
            
        }
        if(q->j>=q->right){
            q->i++;
            x=table[q->pivot_index];
            table[q->pivot_index]=table[q->i];
            table[q->i]=x;
            q->j=q->i+1;
            q->phase=1;
            return;
        }
        if(table[q->j]<=q->pivot){
            q->i++;
            x=table[q->i];
            table[q->i]=table[q->j];
            table[q->j]=x;
            q->j++;
        }else{
            q->j++;
        }
        
        



    }else if (q->phase==1){
        q->stack_top--;
        if (q->left<=q->pivot_index-1){
            q->stack_top++;
            q->std[q->stack_top].left=q->left;
            q->std[q->stack_top].right=q->pivot_index-1;
        }
        if(q->pivot_index+1<=q->right){
            q->stack_top++;
            q->std[q->stack_top].left=q->pivot_index+1;
            q->std[q->stack_top].right=q->right;
        }
        
        if (q->stack_top==-1){
            q->finished=true;
            return;
        }
        q->phase=0;
        q->i=0;
        q->init=true;
        return;
    }
}






































































void resetem(bubbly *bub,selecty* selectful,inserty* insertful,mergy* mergyful,quicky *quickyful,bool *bubbles,bool *select,bool *insert,bool *merged ,bool *quicked){
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
    *merged=false;
    mergyful->stack_top = -1;  
    mergyful->stack_top++;
    mergyful->stack[0].left = 0;
    mergyful->stack[0].right = 104;
    mergyful->stack[0].phase = 0;
    mergyful->finished = false;
    mergyful->temp = (int*)malloc(105 * sizeof(int));
    mergyful->temp_size = 0;
    mergyful->subphase = 0;
    *quicked=false;
    quickyful->init=true;
    quickyful->stack_top = -1;  
    quickyful->stack_top++;
    quickyful->std[0].left = 0;
    quickyful->std[0].right = 104;
    quickyful->finished = false;
    quickyful->phase=0;
    quickyful->i=0;
    quickyful->j=0;
    quickyful->pivot_index=0;
    quickyful->pivot=0;
}



























bool checkmouse(int mx,int my,int lb,int rb,int tb,int bb){
    if (lb<mx && mx<rb && my>tb && my<bb){
        return true;
    } 
    return false;
}


