#include <stdio.h>
#include <stdint.h>
#include "dhcp.h"

int main() {
    uint8_t data[] = {
        1, 4, 255, 0, 0, 3,     // Subnet Mask
        3, 8, 192, 168, 1, 1, 192, 168, 1, 2,  // Router
        12, 4, 'h', 'o', 's', 't', // Host Name
        19, 1, 1,                  // IP Forward Enable
        255                         // End
    };

    // 第一次調用解析全部數據
    dhcpParse(data, sizeof(data));

    // 後續調用用於繼續解析
    while (dhcpParse(NULL, 0) == 1);

    return 0;
}