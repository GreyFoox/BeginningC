#include <stdio.h>

int main() {
    int n;
    // 原始代码（保留用于对比）
    /*
    scanf("%d", &n);
    char c = 'A' - 1;
    int count = -1;
    while( n!= 0) {
        for(int i = 1; i <= n; i++) {
            count ++;
            c = 'A' + count;  // 问题：count超过25时（Z），会输出非A-Z字符
            printf("%c ", c);
        }
        if( n!= 1) {
            printf("\n");
        }
        n--;
    }
    */

    // 读取输入并检查合法性（鲁棒性优化）
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("ERROR: 请输入非负整数\n");
        return 1;
    }

    int count = 0;  // 优化：从0开始计数，更直观
    while (n > 0) {  // 用n>0替代n!=0，逻辑更清晰
        for (int i = 1; i <= n; i++) {
            // 核心优化：通过%26实现循环（0-25对应A-Z，26→0→A，27→1→B...）
            // 原理：A-Z的ASCII码差为25（'A'=65, 'Z'=90），模26确保始终在0-25范围内
            char c = 'A' + (count % 26);
            printf("%c ", c);
            count++;  // 计数后移，放在输出后更符合逻辑流
        }
        // 仅在n>1时换行（避免最后一行多余换行）
        if (n > 1) {
            printf("\n");
        }
        n--;
    }

    return 0;
}

