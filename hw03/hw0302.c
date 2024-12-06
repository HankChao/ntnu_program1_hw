#include <stdio.h>
#include <stdint.h>
#include "gacha.h"

int main() {
    // 初始化抽卡系統，總共100張卡
    initialize(100);
    
    // 設定卡片分組：
    // 第1組：1-10張
    // 第2組：11-20張
    // 第3組：21-30張
    // 第4組：31-40張
    // 第5組：41-50張
    // 第6組：51-100張
    set_groups(10, 20, 30, 40, 50);
    
    // 設定機率：
    // 第1組：0.01 (1%)
    // 第2組：0.04 (4%)
    // 第3組：0.10 (10%)
    // 第4組：0.20 (20%)
    // 第5組：0.35 (35%)
    // 第6組：0.30 (30%)
    set_props(0.01, 0.04, 0.10, 0.20, 0.30);
    
    // 設定保底：每10次抽必出第1組
    set_guarantee(10);
    
    // 增加50次抽獎機會
    add_pull_number(50);
    
    printf("初始抽獎次數: %d\n", get_pull_number());
    
    // 進行5次單抽
    printf("單抽結果:\n");
    for (int i = 0; i < 5; i++) {
        pull();
    }
    
    // 進行一次10連抽
    printf("\n10連抽結果:\n");
    pull10();\
    pull10();
    // 檢查剩餘抽獎次數
    printf("\n剩餘抽獎次數: %d\n", get_pull_number());
    
    return 0;
}