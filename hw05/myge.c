#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#define EPSILON 1e-10

int32_t gaussian_elimination(int32_t n, double *pA, double *py, double **px) {
    // 输入验证
    if (n <= 0 || pA == NULL || py == NULL || px == NULL) {
        return -1;
    }

    // 分配增广矩阵内存
    double **matrix = malloc(n * sizeof(double*));
    for (int32_t i = 0; i < n; i++) {
        matrix[i] = malloc((n + 1) * sizeof(double));
        for (int32_t j = 0; j < n; j++) {
            matrix[i][j] = pA[i * n + j];
        }
        matrix[i][n] = py[i];
    }

    // 前向消元（高斯消元）
    for (int32_t i = 0; i < n; i++) {
        // 寻找主元
        int32_t max_row = i;
        for (int32_t k = i + 1; k < n; k++) {
            if (fabs(matrix[k][i]) > fabs(matrix[max_row][i])) {
                max_row = k;
            }
        }

        // 交换行
        if (max_row != i) {
            for (int32_t k = i; k <= n; k++) {
                double temp = matrix[i][k];
                matrix[i][k] = matrix[max_row][k];
                matrix[max_row][k] = temp;
            }
        }

        // 检查主元是否接近零
        if (fabs(matrix[i][i]) < 1e-10) {
            continue;
        }

        // 消元
        for (int32_t k = i + 1; k < n; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int32_t j = i; j <= n; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // 检查是否无解
    for (int32_t i = 0; i < n; i++) {
        int all_zero = 1;
        for (int32_t j = 0; j < n; j++) {
            if (fabs(matrix[i][j]) > 1e-10) {
                all_zero = 0;
                break;
            }
        }
        if (all_zero && fabs(matrix[i][n]) > 1e-10) {
            // 释放内存并返回无解
            for (int32_t k = 0; k < n; k++) {
                free(matrix[k]);
            }
            free(matrix);
            *px = NULL;
            return 0;
        }
    }

    // 分配解的内存
    *px = malloc(n * sizeof(double));
    if (*px == NULL) {
        for (int32_t k = 0; k < n; k++) {
            free(matrix[k]);
        }
        free(matrix);
        return -1;
    }

    // 回代求解（反向替代）
    for (int32_t i = n - 1; i >= 0; i--) {
        double sum = matrix[i][n];
        for (int32_t j = i + 1; j < n; j++) {
            sum -= matrix[i][j] * (*px)[j];
        }
        
        // 检查主元是否接近零
        if (fabs(matrix[i][i]) < 1e-10) {
            (*px)[i] = 0;  // 视为自由变量
        } else {
            (*px)[i] = sum / matrix[i][i];
        }
    }

    // 判断解的类型
    int32_t rank = 0;
    for (int32_t i = 0; i < n; i++) {
        if (fabs(matrix[i][i]) >= 1e-10) {
            rank++;
        }
    }

    // 释放内存
    for (int32_t k = 0; k < n; k++) {
        free(matrix[k]);
    }
    free(matrix);

    // 返回解的类型
    if (rank < n) {
        return 2;  // 无限解
    }
    return 1;  // 唯一解
}