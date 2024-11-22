#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include "hw0304-2.h"

int hanoi_iterative(int32_t n){
    
    if (n<2 || n>20) {
        return -1; 
    }
    
    int32_t disk[21];

    for(int32_t i=0;i<21;i++)
        disk[i]=1;

    int32_t all_even=0;
    if(n%2==0)  all_even++;

    for(int32_t i=1;i<=pow(2,n)-1;i++){
        int cur=0; //which disk
        if(i%2==1)    cur=1;
        else{
            int32_t temp=i;
            while(temp%2==0){
                temp/=2;
                cur++;
            }
            cur++;
        }

        if(all_even){
            if(cur%2==1){
                if(disk[cur]==1)
                    disk[cur]=3;
                else if(disk[cur]==3)
                    disk[cur]=2;
                else if(disk[cur]==2)
                    disk[cur]=1;
            }else{
                if(disk[cur]==1)
                    disk[cur]=2;
                else if(disk[cur]==2)
                    disk[cur]=3;
                else if(disk[cur]==3)
                    disk[cur]=1;
            }

        }else{
            if(cur%2==0){
                if(disk[cur]==1)
                    disk[cur]=3;
                else if(disk[cur]==3)
                    disk[cur]=2;
                else if(disk[cur]==2)
                    disk[cur]=1;
            }else{
                if(disk[cur]==1)
                    disk[cur]=2;
                else if(disk[cur]==2)
                    disk[cur]=3;
                else if(disk[cur]==3)
                    disk[cur]=1;
            }
        }

        printf("move disk %d to rod %d\n",cur ,disk[cur]);
    }
    
    return pow(2,n)-1;
}
