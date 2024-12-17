#include<stdio.h>
#include<stdint.h>
#include "endian.h"
#include <stdlib.h>
#include <string.h>

int32_t endian_convert(uint8_t *pSrc, uint32_t size, uint8_t **ppDst) {
    if (pSrc == NULL || size == 0 || ppDst == NULL) {
        return -1;  // 無效輸入
    }

    *ppDst = (uint8_t *)malloc(size);
    if (*ppDst == NULL) {
        return -1;  // 記憶體分配失敗
    }

    for (uint32_t i = 0; i < size; i++) {
        (*ppDst)[i] = pSrc[size - 1 - i];  // 反轉位元組順序
    }

    return 0;  // 成功
}

uint8_t *convert_and_pad(uint8_t *pNum, uint32_t size, uint32_t target_size, uint8_t type) {
    uint8_t *converted = NULL;

    // 如果是 Little Endian，先反轉成 Big Endian
    if (type == 0) {  
        if (endian_convert(pNum, size, &converted) != 0) {
            return NULL;  // 反轉失敗
        }
    } else {
        converted = (uint8_t *)malloc(size);
        if (converted == NULL) {
            return NULL;  // 記憶體分配失敗
        }
        memcpy(converted, pNum, size);
    }

    // 分配補齊後的記憶體，初始化為 0
    uint8_t *padded = (uint8_t *)calloc(target_size, sizeof(uint8_t));
    if (padded == NULL) {
        free(converted);
        return NULL;  // 記憶體分配失敗
    }

    // 在前面補 0，將轉換後的數值複製到 padded 的尾部
    memcpy(padded + (target_size - size), converted, size);

    free(converted);
    return padded;
}

int32_t endian_eqaulity_test(uint8_t *pNum1, uint32_t size1, uint8_t type1,
                             uint8_t *pNum2, uint32_t size2, uint8_t type2) {
    if (pNum1 == NULL || pNum2 == NULL || size1 == 0 || size2 == 0 || 
        (type1 != 0 && type1 != 1) || (type2 != 0 && type2 != 1)) {
        return -2;  // 無效輸入
    }

    // 找出最大長度
    uint32_t max_size = (size1 > size2) ? size1 : size2;

    // 轉換並補齊兩個數值到相同長度
    uint8_t *padded1 = convert_and_pad(pNum1, size1, max_size, type1);
    uint8_t *padded2 = convert_and_pad(pNum2, size2, max_size, type2);

    if (padded1 == NULL || padded2 == NULL) {
        free(padded1);
        free(padded2);
        return -1;  // 記憶體分配或轉換失敗
    }

    // 比較兩個補齊後的陣列
    int32_t result = memcmp(padded1, padded2, max_size);

    // 釋放記憶體
    free(padded1);
    free(padded2);

    if (result > 0) {
        return 1;  // 第一個數值大於第二個數值
    } else if (result < 0) {
        return -1; // 第一個數值小於第二個數值
    } else {
        return 0;  // 兩個數值相等
    }
}