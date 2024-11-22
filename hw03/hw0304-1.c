#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include "hw0304-1.h"

void move(int32_t n, char source , char temp, char target){
    if(n>0){
        
        move(n-1, source, target, temp);
        printf("move disk %d to rod %c\n", n, target);
        move(n-1, temp, source, target);
    }
}

int hanoi_recursive(int32_t t) {
    if(t<2 || t>20) return -1;
    move(t,'1','3','2');
    return pow(2,t)-1;
}
