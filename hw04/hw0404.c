#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define YELLOW   "\033[33m"
#define RESET    "\033[0m"
int32_t n=11;
int32_t bingo[6][11]={},used[26]={},setx_check[26]={},sety_check[26]={};

int check_bingo(int player) {
    int start = player == 1 ? 1 : 6;
    int end = player == 1 ? 6 : 11;
    int lines = 0;

    // 检查行
    for (int i = 1; i < 6; i++) {
        int row_complete = 1;
        for (int j = start; j < end; j++) {
            if (!used[bingo[i][j]]) {
                row_complete = 0;
                break;
            }
        }
        if (row_complete) lines++;
    }

    // 检查列
    for (int j = start; j < end; j++) {
        int col_complete = 1;
        for (int i = 1; i < 6; i++) {
            if (!used[bingo[i][j]]) {
                col_complete = 0;
                break;
            }
        }
        if (col_complete) lines++;
    }

    // 检查对角线
    int diag1_complete = 1, diag2_complete = 1;
    for (int i = 1; i < 6; i++) {
        if (!used[bingo[i][start+i-1]]) diag1_complete = 0;
        if (!used[bingo[i][end-i]]) diag2_complete = 0;
    }
    if (diag1_complete) lines++;
    if (diag2_complete) lines++;

    return lines;
}

int main(){
    

    //input
    int32_t cur_input=1,set_x,set_y,repeat=0;
    for(int32_t i=1;i<6;i++){
        for(int32_t j=1;j<6;j++){
            repeat=0;
            printf("Setup %02d: ", cur_input);
            if(scanf("%d,%d",&set_x,&set_y)!=2 || set_x<1 || set_x>5 || set_y<1 || set_y>5){
                printf(" invalid input,input again\n");
                j--;
                continue;
            }
            for(int32_t k=0;k<cur_input;k++){
                if(setx_check[k]==set_x && sety_check[k]==set_y){
                    printf("repeat input, input again\n");
                    j--;
                    repeat=1;
                    break;
                }
            }
            if(repeat)  continue;
            setx_check[cur_input-1]=set_x;
            sety_check[cur_input-1]=set_y;
            cur_input++;
            bingo[set_x][set_y]=5*(i-1)+j;
        }
    }
    //bot
    int32_t bot_bingo[25]={};
    int32_t bot_set=1;
    srand(time(NULL));
    for(int32_t i=0;i<25;i++){
        bot_bingo[i]=bot_set++;
    }

    for (int i = 25-1; i > 0; i--){ 
        int j = rand() % (i + 1);    
        int32_t temp = bot_bingo[i];
        bot_bingo[i] = bot_bingo[j];
        bot_bingo[j] = temp;
    }

    int32_t bot_trans=0;
    for(int32_t i=1;i<6;i++){
        for(int32_t j=6;j<11;j++){
            bingo[i][j]=bot_bingo[bot_trans++];
        }
    }

    //calculate
    printf("===\n");
    int32_t flag=0,select;
    while(true){
        if(flag==1){
            printf("Player's choice: ");
            if(scanf("%02d",&select)!=1 || select<1 || select>25){
                printf("invalid choose,input again\n");
                continue;
            }
            if(used[select]){
                printf("alrealy exist,input again\n");
                continue;
            }
            used[select]=1;
            printf("===\n");
        }else if(flag==2){
            printf("Computer's choice: ");
            int32_t comp_rand[26]={};
            int32_t cur=0;
            for(int32_t i=1;i<26;i++){
                if(used[i]==0)  comp_rand[cur++]=i;
            }

            int32_t rand_i=rand() % cur;
            select = comp_rand[rand_i];
            printf("%02d\n",select);

            used[select]=1;
            printf("===\n");
        }
        for(int32_t i=1;i<6;i++){
            for(int32_t j=1;j<6;j++){
                if(used[bingo[i][j]]){
                    printf(YELLOW);
                }
                printf("%02d ",bingo[i][j]);

                printf(RESET);
            }

            printf("|");

            for(int32_t j=6;j<11;j++){
                if(used[bingo[i][j]]){
                    printf(YELLOW);
                    printf(" %02d",bingo[i][j]);
                    printf(RESET);
                }else{
                    printf(" xx");
                }
            }
            printf("\n");
        }

        printf("===\n");

        int32_t play_win = check_bingo(1);
        int32_t bot_win = check_bingo(2);

        if(play_win>=3 && bot_win>=3){
            printf("Draw\n");
            return 0;
        }else if(play_win>=3){
            printf("The winner is Player.\n");
            return 0;
        }else if(bot_win>=3){
            printf("The winner is Computer.\n");
            return 0;
        }

        if(flag==0) flag=1;
        else if(flag==1) flag=2;
        else if(flag==2) flag=1;
        
    }

}