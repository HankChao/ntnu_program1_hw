#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include"mirror.h"

int main() {
    double x1, y1, x2, y2;
    double a, b, c, d;
    int32_t result;

    // 輸入直線的兩個點
    printf("請輸入直線的兩個點 (x1, y1) 和 (x2, y2): ");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

    set_line(x1, y1, x2, y2);

    // 輸入要鏡射的點
    printf("請輸入要鏡射的點 (a, b): ");
    scanf("%lf %lf", &a, &b);

    result = get_mirror(a, b, &c, &d);

    if (result == -1) {
        printf("錯誤：無法計算鏡射點。\n");
    } else {
        printf("點 (%.2f, %.2f) 的鏡射點是 (%.2f, %.2f)\n", a, b, c, d);
    }

    return 0;
}
