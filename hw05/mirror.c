#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include"mirror.h"

double slide,A,B,C;
int32_t valid_line=0;
void set_line( double x1, double y1, double x2, double y2 ){
    if(x1==x2 && y1==y2){
        return;
    }
    if(x1==x2){
        A=1;
        B=0;
        C=-x1;
    }else{
        slide=(y2-y1)/(x2-x1);
        A=slide;
        B=-1;
        C=(-slide*x1)+y1;
    }
    
    valid_line=1;
}

int32_t get_mirror( double a, double b, double *c, double *d ){
    if (!valid_line) return -1; 

    
    double low=A*A+B*B;
    if(low==0)  return -1;

    *c=a-2*A*(A*a+B*b+C)/low;
    *d=b-2*B*(A*a+B*b+C)/low;

    return 0;
}