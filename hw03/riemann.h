#pragma once
#include<stdio.h>
#include<stdint.h>

void set_polynomial( int32_t a, int32_t b, int32_t c );

double calculate_riemann_integral( int32_t begin , int32_t end );

double calculate_riemann_sum( int32_t begin , int32_t end,int32_t n );

double calculate_area( int32_t begin , int32_t end );

double calculate_area_riemann_sum( int32_t begin , int32_t end,int32_t n );