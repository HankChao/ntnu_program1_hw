#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include "riemann.h"

int main(){
    int32_t a = 0, b = 0, c = 1;
    int32_t begin = -1, end = 2, n = 10;
    printf("x^2 -3:\n");
    set_polynomial(a,b,c);
    printf("calculate_riemann_integral(%d, %d): %lf\n",begin, end, calculate_riemann_integral(begin, end));
    printf("calculate_riemann_sum(%d, %d, %d): %lf\n", begin, end, n, calculate_riemann_sum(begin, end, n));
    printf("calculate_area(%d, %d): %lf\n", begin, end, calculate_area(begin, end));
    printf("calculate_area_riemann_sum(%d, %d, %d): %lf\n", begin, end, n, calculate_area_riemann_sum(begin, end, n));
    printf("------\n");

    a = -1, b = 2, c = 1;
    begin = 0, end = 5, n = 15;
    printf("-x^2 +2x +1:\n");
    set_polynomial(a,b,c);
    printf("calculate_riemann_integral(%d, %d): %lf\n",begin, end, calculate_riemann_integral(begin, end));
    printf("calculate_riemann_sum(%d, %d, %d): %lf\n", begin, end, n, calculate_riemann_sum(begin, end, n));
    printf("calculate_area(%d, %d): %lf\n", begin, end, calculate_area(begin, end));
    printf("calculate_area_riemann_sum(%d, %d, %d): %lf\n", begin, end, n, calculate_area_riemann_sum(begin, end, n));
    printf("------\n");

    a = 2, b = -3, c = 4;
    begin =-2, end = 3, n = 20;
    printf("2x^2 -3x +4:\n");
    set_polynomial(a,b,c);
    printf("calculate_riemann_integral(%d, %d): %lf\n",begin, end, calculate_riemann_integral(begin, end));
    printf("calculate_riemann_sum(%d, %d, %d): %lf\n", begin, end, n, calculate_riemann_sum(begin, end, n));
    printf("calculate_area(%d, %d): %lf\n", begin, end, calculate_area(begin, end));
    printf("calculate_area_riemann_sum(%d, %d, %d): %lf\n", begin, end, n, calculate_area_riemann_sum(begin, end, n));
    printf("------\n");
    return 0;
}