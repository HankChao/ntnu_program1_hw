#include<stdio.h>
#include<stdint.h>

int main(){
    double a,b,sxx=0,sxy=0,sum_y=0,sum_x=0;
    double i=0;
    
    while(1){
        double year=-2;
        double t=0;

        printf("Please enter the year: ");
        if(scanf("%lf", &year) != 1){
            printf("Invalid Input\n");
            return 0;
        }

        if(year==-1){
            break;
        }

        printf("Temperature: ");
        if(scanf("%lf", &t) != 1 ){
            printf("Invalid Input\n");
            return 0;
        }

        sxx += year*year;
        sxy += year*t;

        sum_x += year;
        sum_y += t;

        i++;
    }

    if(i<=1){
        printf("error, too little data\n");
        return 0;
    }
    
    sxx = sxx - (sum_x*sum_x)/i;

    sxy = sxy - (sum_x*sum_y)/i;

    b = sxy/sxx;
    a = (sum_y/i) - b*(sum_x/i);


    printf("Please enter the prediction year: ");

    double pre_year=-1;
    if(scanf("%lf", &pre_year)!=1 || pre_year==-1 || pre_year<0){
        printf("Invalid error\n");
        return 0;
    }

    printf("Temperature: %.1lf\n",b*pre_year+a);

    return 0;

}