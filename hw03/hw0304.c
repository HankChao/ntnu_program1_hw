#include<stdio.h>
#include<stdint.h>
#include"hw0304-1.h"
#include"hw0304-2.h"

int main(){
    printf("%d",hanoi_recursive(3));

    printf("----------\n");

    printf("%d",hanoi_iterative(3));

    return 0;
}