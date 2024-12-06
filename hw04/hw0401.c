#include<stdio.h>
#include<stdint.h>
#include"poker.h"

int main(){
    int8_t a[]={1, 14, 27, 40, 2, 15, 28, 41, 3, 16, 29, 42, 13};
    big_two_sort(a);
    for(int i=0;i<13;i++){
        printf("%d,",a[i]);
    }
}