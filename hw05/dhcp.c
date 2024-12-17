#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dhcp.h"

// 支持的Option Code對應表
const char* option_names[] = {
    "Pad",                  // 0
    "Subnet Mask",              // 1
    "Time Offset",              // 2
    "Router",                   // 3
    "Time Server",              // 4
    "Name Server",              // 5
    "Domain Name Server",       // 6
    "Log Server",               // 7
    "Cookie server",            // 8
    "LPR Server",           // 9
    "Impress server", // 10
    "Resource location server", // 11
    "Host name",           // 12
    "Undefined",                // 13-18
    "Undefined",                // 14
    "Undefined",                // 15
    "Undefined",                // 16
    "Undefined",                // 17
    "Undefined",                // 18
    "IP forwarding enable/disable", // 19
    "Non-local source routing enable/disable", // 20
    "Undefined",                // 21-254
    "End"                       // 255
};

// 靜態變量，用於保存上一次解析的狀態
static uint8_t* static_data = NULL;
static uint32_t static_size = 0;
static uint32_t current_offset = 0;

int32_t dhcpParse(uint8_t *pData, uint32_t size) {
    // 第一次調用，保存數據
    if (pData != NULL && size > 0) {
        static_data = pData;
        static_size = size;
        current_offset = 0;
    }
    
    // 檢查是否有數據可解析
    if (static_data == NULL || current_offset >= static_size) {
        return -1;
    }
    
    // 檢查是否還有足夠的數據
    if (current_offset + 2 > static_size) {
        return -1;
    }
    
    uint8_t code = static_data[current_offset];
    uint8_t length = static_data[current_offset + 1];
    
    // 處理特殊的Option Code
    if (code == 0 || code == 255) {
        printf("Code: %d\n", code);
        printf("Name: %s\n", option_names[code]);
        printf("Size: 0\n");
        printf("Data: \n");
        
        // 0和255 option不佔用額外長度
        current_offset += 1;
        return code == 255 ? 0 : 1;
    }
    
    // 檢查數據長度是否合法
    if (current_offset + 2 + length > static_size) {
        return -1;
    }
    
    // 打印Option信息
    printf("Code: %d\n", code);
    printf("Name: %s\n", option_names[code < 21 ? code : 0]);
    printf("Size: %d\n", length);
    printf("Data: ");
    
    // 根據不同的Option Code打印數據
    switch (code) {
        case 1:  // Subnet Mask
        case 3:  // Router
        case 4:  // Time Server
        case 5:  // Name Server
        case 6:  // Domain Name Server
        case 7:  // Log Server
        case 8:  // Cookie server
        case 9:  // LPR Server
        case 10: // Impress server
        case 11: // Resource location server
            for (uint8_t i = 0; i < length; i += 4) {
                // 確保不會超出 length
                if (i + 4 <= length) {
                    printf("%d.%d.%d.%d%s", 
                        static_data[current_offset + 2 + i],
                        static_data[current_offset + 2 + i + 1],
                        static_data[current_offset + 2 + i + 2],
                        static_data[current_offset + 2 + i + 3],
                        (i + 4 < length) ? ", " : "");
                }
                // 如果剩餘長度不足4字節，可以不處理或添加錯誤處理
            }
            break;
            
        case 12: // Boot File Size
            for (uint8_t i = 0; i < length; i++) {
                printf("%c", static_data[current_offset + 2 + i]);
            }
            break;
        
        case 19: // IP Forward Enable
        case 20: // Non-Local Source Routing
            printf("%d", static_data[current_offset + 2]);
            break;
    }
    
    printf("\n");
    
    // 移動到下一個Option
    current_offset += length + 2;
    
    // 如果是最後一個Option（255），則返回0
    return (code == 255) ? 0 : 1;
}