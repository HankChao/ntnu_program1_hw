#include<stdio.h>
#include<stdint.h>

int main(){
    int32_t cur=0;

    while(1){
        int32_t n=-1;

        printf("Please enter DNA base: ");
        if(scanf("%d",&n)!=1 || ((n==-1 ||  n<1 || n>4) && n!=0)){
            printf("Invalid input, all the input has been cleared ,please reinput\n");
            scanf("%*[^\n]");
            cur=0;
            continue;
        }

        if(n==0){
            break;
        }

        if(cur == 0){
            if(n==1 || n==3){
                cur = 1;
            }
            if(n==2 || n==4){
                cur = 2;
            }
        }else if(cur == 1){
            if(n==1 || n==3 || n==4){
                cur = 3;
            }
            if(n==2){
                cur = 4;
            }
        }else if(cur == 2){
            if(n==1 || n==2 || n==4){
                cur = 4;
            }
            if(n==3){
                cur = 2;
            }
        }else if(cur == 3){
            if(n==3 || n==4){
                cur = 5;
            }
            if(n==2){
                cur = 3;
            }
            if(n==1){
                cur = 2;
            }
        }else if(cur == 4){
            if(n==3 || n==2){
                cur = 5;
            }
            if(n==1 || n==4){
                cur = 6;
            }
        }else if(cur == 5){
            if(n==1 || n==4){
                cur = 5;
            }
            if(n==2 || n==3){
                cur = 7;
            }
        }else if(cur == 6){
            if(n==1){
                cur = 3;
            }
            if(n==3){
                cur = 5;
            }
            if(n==2 || n==4){
                cur = 6;
            }
        }else if(cur == 7){
            if(n==1 || n==2 || n==3 || n==4){
                cur = 7;
            }
        }
    }

    if(cur==7){
        printf("The state is in S7, the sequence satisfies the pattern.\n");
    }else{
        printf("The state is in S%d, the sequence does not satisfy the pattern.\n",cur);
    }
    return 0;
}