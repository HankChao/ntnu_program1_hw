#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include"riemann.h"
int32_t A,B,C;
void set_polynomial( int32_t a, int32_t b, int32_t c ){
    A=a;
    B=b;
    C=c;
}

double calculate_riemann_integral_double( double begin , double end ){

    double integral_begin = A * begin * begin * begin /3.0
                          + B * begin * begin / 2.0
                          + C * begin;
    double integral_end = (A / 3.0) * end * end * end 
                        + (B / 2.0) * end * end 
                        + C * end;

    return integral_end - integral_begin;
}

double calculate_riemann_integral( int32_t begin , int32_t end ){

    double integral_begin = A * begin * begin * begin /3.0
                          + B * begin * begin / 2.0
                          + C * begin;
    double integral_end = (A / 3.0) * end * end * end 
                        + (B / 2.0) * end * end 
                        + C * end;

    return integral_end - integral_begin;
}

double calculate_riemann_sum( int32_t begin , int32_t end,int32_t n ){
    if(n<=0){
        printf("error\n");
        return -1.0;
    }
    double integral=0;
    double t=(double)(end-begin)/n;
    for(int32_t i=0;i<n;i++){
        
        double x=begin+t*i;
        integral += (A*x*x+B*x+C)*t;                             
    }

    return integral;
}

double calculate_area( int32_t begin , int32_t end ){
    //x
    //pow2
    double area=0;
    if(A!=0){
        double d=B*B-4.0*A*C;
        if(d<=0){
            area += fabs(calculate_riemann_integral_double(begin,end));
            return area;
        }else{
            double x1=(-B-sqrt(d))/(2.0*A);
            double x2=(-B+sqrt(d))/(2.0*A);
            
            if(begin<=x1 && x1<=end && begin<=x2 && x2<=end){
                area += fabs(calculate_riemann_integral_double(begin,x1));
                area += fabs(calculate_riemann_integral_double(x1,x2));
                area += fabs(calculate_riemann_integral_double(x2,end));
            }else if(begin<=x1 && x1<=end){
                area += fabs(calculate_riemann_integral_double(begin,x1));
                area += fabs(calculate_riemann_integral_double(x1,end));
            }else if(begin<=x2 && x2<=end){
                area += fabs(calculate_riemann_integral_double(begin,x2));
                area += fabs(calculate_riemann_integral_double(x2,end));
            }else{
                area += fabs(calculate_riemann_integral_double(begin,end));
            }

            return area;
        }
    }else if(A==0 && B!=0){
    //pow1
        double x=-C/B;
        if(begin<=x && x<=end){
            area += fabs(calculate_riemann_integral_double(begin,x));
            area += fabs(calculate_riemann_integral_double(x,end));
        }else{
            fabs(calculate_riemann_integral_double(begin,end));
        }
        return area;

    }else{//0
        return fabs(calculate_riemann_integral(begin,end));
    }

}

double calculate_area_riemann_sum( int32_t begin , int32_t end,int32_t n ){
    if(n<=0){
        printf("error\n");
        return -1.0;
    }
    double area=0;
    
    for(int32_t i=0;i<n;i++){
        double t=(double)(end-begin)/n;
        double x=begin+t*i;
        area += fabs((A*x*x+B*x+C)*t);                             
    }

    return area;
}