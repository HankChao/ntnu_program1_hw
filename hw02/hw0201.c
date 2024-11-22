#include<stdio.h>
#include<stdint.h>

int main(){
    uint16_t n;
    printf("Please enter n (16-bits unsigned):");
    if(scanf("%hu", &n) != 1 || n==0){
        printf("error\n");
        return 0;
    }

    double gold = 1.61803398874989484820;

    double m = 1,all=1,cur=1;


    printf("n = 1: %.20lf (%.20lf)\n", cur, gold-cur);
    
    for(int32_t i=2;i<=n;i++){ 
        m = 1/all;
        all = 1+m ;
        printf("n = %d: %.20lf (%.20lf)\n", i, all, gold-all);
    }
    

    return 0;
}