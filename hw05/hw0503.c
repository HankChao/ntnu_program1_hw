#include <stdio.h>
#include <stdint.h>
#include "endian.h"

int main() {
    // 測試 1: 相等的數值
    uint8_t num1[] = {0x01, 0x00};              // Little Endian: 0x0001
    uint8_t num2[] = {0x00, 0x01};              // Big Endian: 0x0001
    printf("Test 1 result: %d\n", endian_eqaulity_test(num1, sizeof(num1), 0, num2, sizeof(num2), 1)); // 0 (相等)

    // 測試 2: 第一個數值大於第二個數值
    uint8_t num3[] = {0x05, 0x00};              // Little Endian: 0x0005
    uint8_t num4[] = {0x00, 0x03};              // Big Endian: 0x0003
    printf("Test 2 result: %d\n", endian_eqaulity_test(num3, sizeof(num3), 0, num4, sizeof(num4), 1)); // 1 (num3 大於 num4)

    // 測試 3: 第一個數值小於第二個數值
    uint8_t num5[] = {0x02, 0x00};              // Little Endian: 0x0002
    uint8_t num6[] = {0x00, 0x04};              // Big Endian: 0x0004
    printf("Test 3 result: %d\n", endian_eqaulity_test(num5, sizeof(num5), 0, num6, sizeof(num6), 1)); // -1 (num5 小於 num6)

    // 測試 4: 長度不同但數值相等
    uint8_t num7[] = {0xFF, 0xFF};              // Little Endian: 0xFFFF
    uint8_t num8[] = {0x00, 0x00, 0xFF, 0xFF};  // Big Endian: 0xFFFF
    printf("Test 4 result: %d\n", endian_eqaulity_test(num7, sizeof(num7), 0, num8, sizeof(num8), 1)); // 0 (相等)

    // 測試 5: 長度不同，第一個數值小於第二個數值
    uint8_t num9[] = {0xAA};                    // Little Endian: 0xAA
    uint8_t num10[] = {0x00, 0x00, 0x00, 0xAA}; // Big Endian: 0x000000AA
    printf("Test 5 result: %d\n", endian_eqaulity_test(num9, sizeof(num9), 0, num10, sizeof(num10), 1)); // -1 (num9 小於 num10)

    // 測試 6: 長度不同，第一個數值大於第二個數值
uint8_t num11[] = {0x00, 0x10};             // Little Endian: 0x1000
uint8_t num12[] = {0x10, 0x00};             // Big Endian: 0x1000
 printf("Test 6 result: %d\n", endian_eqaulity_test(num11, sizeof(num11)/sizeof(uint8_t), 0, num12, sizeof(num12)/sizeof(uint8_t), 1)); // 1 (num11 大於 num12)

    return 0;
}
