#pragma once
#include<stdio.h>
#include<stdint.h>
#include<math.h>

int32_t inputDataset( uint32_t size, int32_t label[], int32_t x[], int32_t y[] );

int32_t classify( int32_t k, int32_t x, int32_t y );