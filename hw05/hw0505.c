#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>  
#include"myTuringMachine.h"

int main(){
    size_t size=0;
    int8_t table_1[]={-1, 0, 1, 0, -1, 1, 2, 3, 4, -1};
    int8_t *table_2=NULL;
    TuringMachine(table_1,&table_2,&size);

    for(int i=0;i<size-1;i++)
        printf("%d ",table_2[i]);

    return 0;
}