#pragma once
#include <stdio.h>
#include <stdint.h>
#include <math.h>

 int32_t endian_convert( uint8_t *pSrc, uint32_t size, uint8_t **ppDst );

int32_t endian_eqaulity_test( uint8_t *pNum1 , uint32_t size1 ,uint8_t type1 ,
uint8_t *pNum2 , uint32_t size2 ,uint8_t type2 );
