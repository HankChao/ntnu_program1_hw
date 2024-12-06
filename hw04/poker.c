#include<stdio.h>
#include<stdint.h>
#include"poker.h"

int32_t big_two_sort( int8_t cards[] ){
    for(int i=0;i<13;i++){
        if(cards[i]<1 || cards[i]>52)
            return -1;
    }
    for(int32_t x=12;x>=0;x--){
        for(int i=0;i<x;i++){
            int32_t a_num=(cards[i]-1)%13+1;
            int32_t a_col=(cards[i]-1)/13+1;

            int32_t b_num=(cards[i+1]-1)%13+1;
            int32_t b_col=(cards[i+1]-1)/13+1;

            if(a_num<=2)
                a_num+=13;
            if(b_num<=2)
                b_num+=13;

            int32_t temp;
            if(a_num>b_num ||(a_num == b_num && a_col>b_col)){
                temp = cards[i+1];
                cards[i+1] = cards[i];
                cards[i] = temp;
            }
        }

    }
    return 0;
}