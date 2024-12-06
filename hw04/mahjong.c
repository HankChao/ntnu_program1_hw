#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include"mahjong.h"

bool used[23]={0};
int32_t kong=0;
int32_t t=1;

bool is_kong(int32_t a, int32_t b, int32_t c,int32_t d){
    if(a==b && b==c && c==d){
        return true;
    }
    return false;
}

bool is_pong(int32_t a, int32_t b, int32_t c){
    int32_t a_col=(a-1)/9+1;
    int32_t b_col=(b-1)/9+1;
    int32_t c_col=(c-1)/9+1;
    
    return (a_col == b_col && b_col == c_col && a==b && b==c);

}

bool is_chew(int32_t a, int32_t b, int32_t c){
    int32_t a_col=(a-1)/9+1;
    int32_t b_col=(b-1)/9+1;
    int32_t c_col=(c-1)/9+1;
    
    return (a_col == b_col && b_col == c_col && 
            a + 1 == b && b + 1 == c);
    return false;
}

bool dfs(int8_t cards[], size_t size, int32_t meld){
    if(meld==5){
        for(int32_t i=0;i<size-1;i++){
            if(cards[i]==cards[i+1] && !used[i] && !used[i+1]){
                used[i]=used[i+1]=true;
                return true;
            }
        }
        return false;
    }

    for(int32_t i=0;i<size-1;i++){
        if(used[i]) continue;

        if(i+3<size && !used[i+1] && !used[i+2] && !used[i+3]){
            if(cards[i] == cards[i+1]
            && cards[i+1] == cards[i+2]
            && cards[i+2] == cards[i+3]){
                
                used[i]=used[i+1]=used[i+2]=used[i+3]=true;
                kong++;
                
                if(dfs(cards,size,meld+1)){
                    return true;
                }
                used[i]=used[i+1]=used[i+2]=used[i+3]=false;
                kong--;
            }
        }

        for(int32_t j=i+1;j<size;j++){
            if(used[j]) continue;

            for(int32_t k=j+1;k<size;k++){
                if(used[k]) continue;

                if(is_chew(cards[i],cards[j],cards[k]) || is_pong(cards[i],cards[j],cards[k])){
                    used[i]=used[j]=used[k]=true;
                    if(dfs(cards,size,meld+1)){
                        return true;
                    }
                    used[i]=used[j]=used[k]=false;
                }
            }
        }
    }
    return false;
}

int32_t check( int8_t cards[], size_t size ){
    if( size<17 || size>22)
        return -1;
    int32_t legal[40]={0};
    for(int32_t i=0;i<size;i++){
        legal[cards[i]]++;
        if(legal[cards[i]]>4){
            return -1;
        }
    }
    
    for(int32_t x=size-1;x>=0;x--){
        for(int i=0;i<x;i++){
            int32_t a_num=(cards[i]-1)%9+1;
            int32_t a_col=(cards[i]-1)/9+1;

            int32_t b_num=(cards[i+1]-1)%9+1;
            int32_t b_col=(cards[i+1]-1)/9+1;

            
            if(a_col>b_col || (a_col==b_col && a_num>b_num)){
                int32_t temp = cards[i+1];
                cards[i+1] = cards[i];
                cards[i] = temp;
            }
        }

    }

    for(int32_t i=0;i<size;i++){
        used[i]=0;
    }

    kong=0;
    bool ok = dfs(cards,size,0);

    int32_t all_kong=0,left=0;
    for(int32_t i=0;i+3<size;i++){
        if(is_kong(cards[i],cards[i+1],cards[i+2],cards[i+3]))
            all_kong++;

    }

    for(int32_t i=0;i<size;i++){
        if(used[i]==0)
            left=1;
    }

    if((kong!=size-17 && all_kong<size-17)){
        return -1;
    }
    if(ok && !left && kong==size-17)
        return 1;
    return  0; 
}