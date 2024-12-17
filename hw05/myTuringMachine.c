#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"myTuringMachine.h"

void TuringMachine(int8_t* ptape1 , int8_t** ptape2, size_t *tape2Size){

    *tape2Size = 1; // 初始大小為 1 開頭的 -1
    *ptape2 = calloc(sizeof(int8_t), *tape2Size);
    if (*ptape2 == NULL) return; // 記憶體分配失敗
    **ptape2 = -1;
    
    ptape1=ptape1+1; //start
    while ((*ptape1) != -1) {
        
        *ptape1 +=10;

        if(*ptape1 == 10 ){//0
            while((*ptape1)!=-1)//to y
                ptape1 = ptape1+1;
            ptape1 = ptape1+1;//cross x y1    

            while((*ptape1)!=-1){
                (*tape2Size)+=1;
                *ptape2 = (int8_t*)realloc(*ptape2, sizeof(int8_t) * (*tape2Size));
                (*ptape2)[(*tape2Size)-1]=0;
                ptape1+=1;
            }
            while((*ptape1)<10){
                ptape1-=1;
            }
            (*ptape1)-=10;
            ptape1+=1;
            
        }else{
            while((*ptape1)!=-1)//to y
                ptape1 = ptape1+1;

            ptape1 = ptape1+1;//cross x y1    
            while((*ptape1)!=-1){
                (*tape2Size)+=1;
                *ptape2 = (int8_t*)realloc(*ptape2, sizeof(int8_t) * (*tape2Size));
                (*ptape2)[(*tape2Size)-1]=(*ptape1);
                ptape1+=1;
            }

            while((*ptape1)<10){
                ptape1-=1;
            }

            (*ptape1)-=10;
            ptape1+=1;
        }    
    }
        
    (*tape2Size)+=1;
    *ptape2 = (int8_t*)realloc(*ptape2, sizeof(int8_t) * (*tape2Size));
    (*ptape2)[*tape2Size-1]= -1;
    //now p1 in middle -1
    
    (*ptape2)=(*ptape2)+1;
    
}