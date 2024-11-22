#include<stdio.h>
#include<stdint.h>

int main() {
    uint16_t hex_input,cp_hex;
    int32_t choice;

    printf("Please input a hex:");
    if (scanf("%4hx", &hex_input) != 1) {
        printf("Invalid input!\n");
        return 0;  
    }
    cp_hex = hex_input;

    printf("Please choose the output type (1: integer, 2: unsigned integer, 3: float):");
    if(scanf("%d", &choice) != 1 || (choice < 1 || choice > 3)){
        printf("error\n");
        return 0;
    }

    int32_t b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0;

    if (hex_input >= 0x8000) {
        b15 = 1;
        hex_input -= 0x8000;
    } else {
        b15 = 0;
    }

    if (hex_input >= 0x4000) {
        b14 = 1;
        hex_input -= 0x4000;
    } else {
        b14 = 0;
    }

    if (hex_input >= 0x2000) {
        b13 = 1;
        hex_input -= 0x2000;
    } else {
        b13 = 0;
    }

    if (hex_input >= 0x1000) {
        b12 = 1;
        hex_input -= 0x1000;
    } else {
        b12 = 0;
    }

    if (hex_input >= 0x0800) {
        b11 = 1;
        hex_input -= 0x0800;
    } else {
        b11 = 0;
    }

    if (hex_input >= 0x0400) {
        b10 = 1;
        hex_input -= 0x0400;
    } else {
        b10 = 0;
    }

    if (hex_input >= 0x0200) {
        b9 = 1;
        hex_input -= 0x0200;
    } else {
        b9 = 0;
    }

    if (hex_input >= 0x0100) {
        b8 = 1;
        hex_input -= 0x0100;
    } else {
        b8 = 0;
    }

    if (hex_input >= 0x0080) {
        b7 = 1;
        hex_input -= 0x0080;
    } else {
        b7 = 0;
    }

    if (hex_input >= 0x0040) {
        b6 = 1;
        hex_input -= 0x0040;
    } else {
        b6 = 0;
    }

    if (hex_input >= 0x0020) {
        b5 = 1;
        hex_input -= 0x0020;
    } else {
        b5 = 0;
    }

    if (hex_input >= 0x0010) {
        b4 = 1;
        hex_input -= 0x0010;
    } else {
        b4 = 0;
    }

    if (hex_input >= 0x0008) {
        b3 = 1;
        hex_input -= 0x0008;
    } else {
        b3 = 0;
    }

    if (hex_input >= 0x0004) {
        b2 = 1;
        hex_input -= 0x0004;
    } else {
        b2 = 0;
    }

    if (hex_input >= 0x0002) {
        b1 = 1;
        hex_input -= 0x0002;
    } else {
        b1 = 0;
    }

    if (hex_input >= 0x0001) {
        b0 = 1;
        hex_input -= 0x0001;
    } else {
        b0 = 0;
    }

    printf("Binary of %X is: %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n", 
        cp_hex,b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0);

    
    if (choice == 1) {
        // Signed integer
        int16_t signed_int = 0;
        
        if (b15 == 1) { signed_int -= 32768; }
        if (b14 == 1) { signed_int += 16384; }
        if (b13 == 1) { signed_int += 8192; }
        if (b12 == 1) { signed_int += 4096; }
        if (b11 == 1) { signed_int += 2048; }
        if (b10 == 1) { signed_int += 1024; }
        if (b9 == 1) { signed_int += 512; }
        if (b8 == 1) { signed_int += 256; }
        if (b7 == 1) { signed_int += 128; }
        if (b6 == 1) { signed_int += 64; }
        if (b5 == 1) { signed_int += 32; }
        if (b4 == 1) { signed_int += 16; }
        if (b3 == 1) { signed_int += 8; }
        if (b2 == 1) { signed_int += 4; }
        if (b1 == 1) { signed_int += 2; }
        if (b0 == 1) { signed_int += 1; }

        printf("Converted integer is: %d\n", signed_int);
    } else if (choice == 2) {
        // Unsigned integer
        uint32_t unsigned_int = 0;

        if (b15 == 1) { unsigned_int += 32768; }
        if (b14 == 1) { unsigned_int += 16384; }
        if (b13 == 1) { unsigned_int += 8192; }
        if (b12 == 1) { unsigned_int += 4096; }
        if (b11 == 1) { unsigned_int += 2048; }
        if (b10 == 1) { unsigned_int += 1024; }
        if (b9 == 1) { unsigned_int += 512; }
        if (b8 == 1) { unsigned_int += 256; }
        if (b7 == 1) { unsigned_int += 128; }
        if (b6 == 1) { unsigned_int += 64; }
        if (b5 == 1) { unsigned_int += 32; }
        if (b4 == 1) { unsigned_int += 16; }
        if (b3 == 1) { unsigned_int += 8; }
        if (b2 == 1) { unsigned_int += 4; }
        if (b1 == 1) { unsigned_int += 2; }
        if (b0 == 1) { unsigned_int += 1; }

        printf("Converted unsigned integer is: %u\n", unsigned_int);
    }else if (choice == 3) {
        //float
        uint16_t sign;
        if (b15 == 1) {
            sign = 1;
        } else {
            sign = 0;
        }

        //exponent
        uint16_t exponent = b14 * 16 + b13 * 8 + b12 * 4 + b11 * 2 + b10;

        //fraction
        uint16_t fraction = b9 * 512 + b8 * 256 + b7 * 128 + b6 * 64 + b5 * 32 +
                                  b4 * 16 + b3 * 8 + b2 * 4 + b1 * 2 + b0;

        if (exponent == 0 && fraction == 0) {
            // Zero
            if (sign == 1) {
                printf("Converted float is: -0.0\n");
            } else {
                printf("Converted float is: +0.0\n");
            }
        } else if (exponent == 31) {
            // INF or NaN
            if (fraction == 0) {
                if (sign == 1) {
                    printf("Converted float is: -INF\n");
                } else {
                    printf("Converted float is: +INF\n");
                }
            } else {
                printf("Converted float is: NAN\n");
            }
        } else {
    
            float mantissa = 1.0f;
            if (b9 == 1) { mantissa += 0.5f; }
            if (b8 == 1) { mantissa += 0.25f; }
            if (b7 == 1) { mantissa += 0.125f; }
            if (b6 == 1) { mantissa += 0.0625f; }
            if (b5 == 1) { mantissa += 0.03125f; }
            if (b4 == 1) { mantissa += 0.015625f; }
            if (b3 == 1) { mantissa += 0.0078125f; }
            if (b2 == 1) { mantissa += 0.00390625f; }
            if (b1 == 1) { mantissa += 0.001953125f; }
            if (b0 == 1) { mantissa += 0.0009765625f; }

            // final exponent (-15)
            int final_exponent = exponent - 15;

            // result
            if (sign == 1) {
                printf("Converted float is: -%f*2^%d\n", mantissa, final_exponent);
            } else {
                printf("Converted float is: %f*2^%d\n", mantissa, final_exponent);
            }
        }
    }
    return 0;
}
   
