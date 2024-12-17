#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

#define EPSILON 1e-6

// 函式宣告，假設在 myge.c 中實現
int32_t gaussian_elimination(int32_t n, double *pA, double *py, double **px);

// 隨機生成矩陣 A 和向量 y
void generate_random_data(int32_t n, double *pA, double *py) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pA[i * n + j] = rand() % 21 - 10;  // 隨機生成 -10 到 10 之間的數
        }
        py[i] = rand() % 21 - 10;  // 隨機生成 -10 到 10 之間的數
    }
}

// 手動輸入矩陣 A 和向量 y
void input_data(int32_t n, double *pA, double *py) {
    printf("請輸入矩陣 A (%d x %d)：\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &pA[i * n + j]);
        }
    }

    printf("請輸入向量 y (%d x 1)：\n", n);
    for (int i = 0; i < n; i++) {
        printf("y[%d] = ", i);
        scanf("%lf", &py[i]);
    }
}

// 輸出矩陣 A 和向量 y
void print_matrix_and_vector(int32_t n, double *pA, double *py) {
    printf("矩陣 A：\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6.2f ", pA[i * n + j]);
        }
        printf("\n");
    }

    printf("向量 y：\n");
    for (int i = 0; i < n; i++) {
        printf("%6.2f\n", py[i]);
    }
}

// 計算 A * x 並輸出結果，用於驗證解的正確性
void calculate_y(int32_t n, double *pA, double *px, double *result_y) {
    for (int i = 0; i < n; i++) {
        result_y[i] = 0;
        for (int j = 0; j < n; j++) {
            result_y[i] += pA[i * n + j] * px[j];
        }
    }
}

// 比較兩個 y 向量是否相等
int compare_y(int32_t n, double *y1, double *y2) {
    for (int i = 0; i < n; i++) {
        if (fabs(y1[i] - y2[i]) > EPSILON) {
            return 0; // 不相等
        }
    }
    return 1; // 相等
}

int main() {
    srand(time(NULL));  // 初始化隨機數種子

    int32_t n;
    printf("請輸入矩陣的維度 n：");
    scanf("%d", &n);

    double *pA = malloc(n * n * sizeof(double));
    double *py = malloc(n * sizeof(double));

    if (pA == NULL || py == NULL) {
        printf("記憶體分配失敗！\n");
        return -1;
    }

    int continue_program = 1;

    while (continue_program) {
        // 選擇模式：隨機生成或手動輸入
        int choice;
        printf("\n選擇模式：\n");
        printf("1. 隨機生成測試數據\n");
        printf("2. 手動輸入測試數據\n");
        printf("請輸入選項 (1 或 2)：");
        scanf("%d", &choice);

        if (choice == 1) {
            generate_random_data(n, pA, py);
        } else if (choice == 2) {
            input_data(n, pA, py);
        } else {
            printf("無效的選項！\n");
            continue;
        }

        print_matrix_and_vector(n, pA, py);

        double *px = NULL;
        int32_t result = gaussian_elimination(n, pA, py, &px);

        // 輸出結果
        if (result == -1) {
            printf("輸入無效！\n");
        } else if (result == 0) {
            printf("此方程組無解！\n");
        } else if (result == 1) {
            printf("唯一解：\n");
            for (int i = 0; i < n; i++) {
                printf("x[%d] = %.6f\n", i, px[i]);
            }
        } else if (result == 2) {
            printf("方程組有無限多解！\n");
            for (int i = 0; i < n; i++) {
                printf("x[%d] = %.6f\n", i, px[i]);
            }
        }

        // 如果有解，計算 y' 並比較
        if (result == 1 || result == 2) {
            double *calculated_y = malloc(n * sizeof(double));
            if (calculated_y != NULL) {
                calculate_y(n, pA, px, calculated_y);
                printf("計算得到的 y = A * x 結果：\n");
                for (int i = 0; i < n; i++) {
                    printf("y[%d] = %.6f\n", i, calculated_y[i]);
                }

                if (compare_y(n, py, calculated_y)) {
                    printf("結果正確：計算得到的 y 與輸入的 y 相同。\n");
                } else {
                    printf("結果錯誤：計算得到的 y 與輸入的 y 不相同。\n");
                }

                free(calculated_y);
            }
        }

        if (px != NULL) {
            free(px);
        }

        printf("\n是否繼續？(1: 繼續, 0: 結束)：");
        scanf("%d", &continue_program);
    }

    free(pA);
    free(py);

    return 0;
}
