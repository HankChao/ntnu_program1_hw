#include "encrypt.h"

int s1, s2, s3, s4; 
int c1, c2, c3, c4; 
int tmpS, tmpC, tmpZ;    

int encrypt(int shapez) {
    // TODO: Implement encryption for shape
    return shapez;
}

int decrypt(int shapez) {
    // TODO: Implement decryption for shape
    return shapez;
}

void load_shapez(int shapez){
    shapez = decrypt(shapez);
    c4 = ( ( shapez )  ) % 10 ;
    s4 = ( ( shapez - c4 ) / 10 ) % 10;
    c3 = ( ( shapez - c4 - s4*10 ) / 100 ) % 10;
    s3 = ( ( shapez - c4 - s4*10 - c3*100 ) / 1000 ) % 10;
    c2 = ( ( shapez - c4 - s4*10 - c3*100 - s3*1000 ) / 10000 ) % 10;
    s2 = ( ( shapez - c4 - s4*10 - c3*100 - s3*1000 - c2*10000 ) / 100000 ) % 10;
    c1 = ( ( shapez - c4 - s4*10 - c3*100 - s3*1000 - c2*10000 - s2*100000 ) / 1000000 ) % 10;
    s1 = ( ( shapez - c4 - s4*10 - c3*100 - s3*1000 - c2*10000 - s2*100000 - c1*1000000 ) / 10000000 ) % 10;
    return;
}

int store_shapez(){
    return encrypt(s1*10000000 + c1*1000000 + s2*100000 + c2*10000 + s3*1000 + c3*100 + s4*10 + c4);
}

void print_shapez(int shapez){
    char color_table[] = {'-', 'r', 'g', 'b', 'y', 'p', 'c', 'u', 'w'};
    char shape_table[] = {'-', 'C', 'R', 'W', 'S'};
    load_shapez(decrypt(shapez));
    printf("%c%c", shape_table[s1], color_table[c1]);
    printf("%c%c", shape_table[s2], color_table[c2]);
    printf("%c%c", shape_table[s3], color_table[c3]);
    printf("%c%c", shape_table[s4], color_table[c4]);
    printf("\n");
}

