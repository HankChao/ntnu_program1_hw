#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include "mygcd.h"

static int count_digits(uint32_t n) {
    if (n == 0) return 1;
    return (int)log10(n) + 1;
}

uint32_t gcd( int32_t print_format , uint32_t a, uint32_t b ){
    if(a<b || print_format < 0 || print_format > 2 || b==0 || a==0){
        return 0;
    }

    int32_t x=a,y=b;
    int32_t la = count_digits(a);
    int32_t lb = count_digits(b);
    int32_t left_mx = count_digits(x/y);

    while(1){//left
        int32_t l_temp1,l_temp2,lt1,lt2,e,r;
        
        l_temp1 = x/y;
        lt1 = l_temp1*y;
        e = x%y;

        if((int)log10(l_temp1) + 1>left_mx)
            left_mx=(int)log10(l_temp1) + 1;
        
        if(e!=0){
            l_temp2 = y/e;
            lt2 = l_temp2*e;
            r = y%e;
        }

        x = e;
        y = r;

        if(e==0 || r==0)    break;
    }

    x=a;y=b;
    while(1){//print
        int32_t temp1,temp2,t1,t2,z,o;
        
        temp1 = x/y;
        t1 = temp1*y;
        z = x%y;
        
        if(z!=0){
            temp2 = y/z;
            t2 = temp2*z;
            o = y%z;
        }

        if(print_format==0){
            if(z==0)    return y;
            else if(o==0)   return z;
        }

        if(print_format==1){
            if(z==0){
                printf("%d / %d = %d ... %d\n",x,y,temp1,z);
                return y;
            }else if(o==0){
                printf("%d / %d = %d ... %d\n",x,y,temp1,z);
                printf("%d / %d = %d ... %d\n",y,z,temp2,o);
                return z;
            }else{
                printf("%d / %d = %d ... %d\n",x,y,temp1,z);
                printf("%d / %d = %d ... %d\n",y,z,temp2,o);
            }
            
        }

        if(print_format==2){
            if(z==0){
                printf("%-*d |%*d|%*d|\n",left_mx,temp1,la,x,lb,y);
                printf("%*s |%*d|%*s|\n",left_mx,"",la,t1,lb,"");
                printf("%*s ---------\n",left_mx,"");
                printf("%*s |%*d|\n",left_mx,"",lb,z);
                return y;
            }else if(o==0){
                printf("%-*d |%*d|%*d| %d\n",left_mx,temp1,la,x,lb,y,temp2);
                printf("%*s |%*d|%*d|\n",left_mx,"",la,t1,lb,t2);
                printf("%*s ---------\n",left_mx,"");
                printf("%*s |%*d|%*d|\n",left_mx,"",la,z,lb,o);
                return z;
            }else{
                printf("%-*d |%*d|%*d| %d\n",left_mx,temp1,la,x,lb,y,temp2);
                printf("%*s |%*d|%*d|\n",left_mx,"",la,t1,lb,t2);
                printf("%*s ---------\n",left_mx,"");

            }
        }

        x = z;
        y = o;
    }

}
