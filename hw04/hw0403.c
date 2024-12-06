#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include"knn.h"

int main(){
int32_t labels[] = {1, 2, 3, 1, 1, 1, 2, 2, 2, 3};
int32_t x_coords[] = {22, 43, 0, 36, 44, 43, 4, 32, 31, 4};
int32_t y_coords[] = {31, 46, 15, 46, 15, 6, 28, 45, 26, 6};
uint32_t size = 10;

    if (inputDataset(size, labels, x_coords, y_coords) == 0) {
        printf("Dataset input successfully!\n");
    } else {
        printf("Dataset input failed.\n");
        return -1;
    }

    int32_t test_x = 25, test_y = 17;
    int32_t k = 3;

    printf("Testing classify() with k = %d...\n", k);
    int32_t result = classify(k, test_x, test_y);
    if (result == -1) {
        printf("Classification failed due to invalid k or input.\n");
    } else {
        printf("Classified test point (%d, %d) to class: %d\n", test_x, test_y, result);
    }

    return 0;

}