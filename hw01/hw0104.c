#include<stdio.h>
#include<stdint.h>

int main(){
    int32_t x1=-1,x2=-1,x3=-1,x4=-1,x5=-1;
    printf("Please enter 5 cards: ");
    if(scanf("%d %d %d %d %d", &x1, &x2, &x3,&x4,&x5)!= 5 || 0>x1 
    || x1>52 || 0>x2 || x2>52 || 0>x3 || x3>52 || 0>x4 || x4>52 || 0>x5 || x5>52){
        printf("error\n");
        return 0;

    }

    //color,number
    int32_t c1=0,c2=0,c3=0,c4=0,c5=0;
    int32_t n1=-1,n2=-1,n3=-1,n4=-1,n5=-1;
    int32_t temp = 0;
    
    x1--;x2--;x3--;x4--;x5--;
    //number_4
    if(x1>x2){temp = x2;x2 = x1;x1 = temp;}
    if(x2>x3){temp = x3;x3 = x2;x2 = temp;}
    if(x3>x4){temp = x4;x4 = x3;x3 = temp;}
    if(x4>x5){temp = x5;x5 = x4;x4 = temp;}
    //3
    if(x1>x2){temp = x2;x2 = x1;x1 = temp;}
    if(x2>x3){temp = x3;x3 = x2;x2 = temp;}
    if(x3>x4){temp = x4;x4 = x3;x3 = temp;}
    //2
    if(x1>x2){temp = x2;x2 = x1;x1 = temp;}
    if(x2>x3){temp = x3;x3 = x2;x2 = temp;}
    //1
    if(x1>x2){temp = x2;x2 = x1;x1 = temp;}

    if((x1==x2)||(x2==x3)||(x3==x4)||(x4==x5)){
        printf("error\n");
        return 0;
    }

    c1 = x1%13;c2 = x2%13;c3 = x3%13;c4 = x4%13;c5 = x5%13;
    n1 = x1/13;n2 = x2/13;n3 = x3/13;n4 = x4/13;n5 = x5/13;

    //card_number
    if(c1>c2){temp = c2;c2 = c1;c1 = temp;}
    if(c2>c3){temp = c3;c3 = c2;c2 = temp;}
    if(c3>c4){temp = c4;c4 = c3;c3 = temp;}
    if(c4>c5){temp = c5;c5 = c4;c4 = temp;}
    //3
    if(c1>c2){temp = c2;c2 = c1;c1 = temp;}
    if(c2>c3){temp = c3;c3 = c2;c2 = temp;}
    if(c3>c4){temp = c4;c4 = c3;c3 = temp;}
    //2
    if(c1>c2){temp = c2;c2 = c1;c1 = temp;}
    if(c2>c3){temp = c3;c3 = c2;c2 = temp;}
    //1
    if(c1>c2){temp = c2;c2 = c1;c1 = temp;}

    int32_t flush=0,pairs=0,straight=0,three=0,four=0;

    if((n1 == n2) && (n2 == n3) && (n3 == n4) && (n4 == n5)){
        flush = 1;
    }
    if(((c5-c1) == 4) && ((c4-c1) == 3) && ((c3-c1) == 2) && ((c2-c1) == 1)){
        straight = 1;
    }else if((c1 == 0) && (c2 == 9) && (c3 == 10) && (c4 == 11) && (c5 == 12)){
        straight = 1;
    }

    //pair
    if(c1 == c2)    pairs++;
    if(c2 == c3)    pairs++;
    if(c3 == c4)    pairs++;
    if(c4 == c5)    pairs++;

    if(((c1 == c2) && (c2==c3)) || ((c2 == c3) && (c3 == c4)) || ((c3 == c4) && (c4 == c5))){
        three = 1;
    }

    if(((c1 == c2) && (c2 == c3) && (c3 == c4)) || ((c2 == c3) && (c3 == c4) && (c4 == c5))){
        four = 1;
    }

    if(flush && straight){
        printf("Straight Flush\n");
        return 0;
    }
    if(four){
        printf("Four of a kind\n");
        return 0;
    }
    if(three && (pairs == 3)){
        printf("Full house\n");
        return 0;
    }
    if(flush){
        printf("Flush\n");
        return 0;
    }
    if(straight){
        printf("Straight\n");
        return 0;
    }
    if(three){
        printf("Three of a kind\n");
        return 0;
    }
    if(pairs == 2){
        printf("Two pair\n");
        return 0;
    }
    if(pairs == 1){
        printf("One pair\n");
        return 0;
    }

    printf("High card\n");
    return 0;
}