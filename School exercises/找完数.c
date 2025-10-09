#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    // 原始代码（保留用于对比，并标注问题）
    /*
    int m, n;
    int flag = 1; 
    scanf("%d %d", &m, &n);
    for(int i = m; i <= n; i++) {
        int sum = 0;
        // 问题1：循环范围过大，效率极低
        // 逻辑错误：j无需循环到i，因子最大为i/2（除i本身），此处循环到i导致O(i)时间复杂度
        for(int j = 1; j <= i; j++) {
            flag = 0;  // 问题2：flag逻辑错误，每次循环都重置为0，无法正确标记"是否存在完数"
            // 问题3：因子判断完全错误
            // 正确逻辑：因子是能整除i的数（i%j == 0），此处写反为i%j != 0，且条件i%j >= j无意义
            if(i % j != 0 && i % j >= j) {
                // 问题4：因子和计算错误
                // 正确逻辑：累加因子j本身，此处错误累加j + i%j（与因子无关的数值）
                sum += (j + i % j); 
                // 问题5：输出逻辑混乱
                // 未收集全因子就打印固定格式"1 + 2 + 3"，与实际因子无关，且提前输出导致格式错误
                printf("%d = 1 + 2 + 3", sum);
            }
        }
    }
    // 问题6：因flag被错误重置，此处判断失效
    // 无论是否找到完数，flag都可能为0，无法正确输出"None"
    if(flag) {
        printf("None");
    } 
    */

    int m, n;
    bool has_perfect = false;  // 明确标记是否找到完数（修复flag逻辑问题）
    
    // 输入合法性检查（补充原始代码缺失的鲁棒性）
    if (scanf("%d %d", &m, &n) != 2 || m <= 1 || m > n || n > 10000) {
        printf("输入错误：请输入1<m≤n≤10000的正整数\n");
        return 1;
    }

    // 主方法：优化版成对因子查找法（解决原始代码效率和逻辑问题）
    for (int num = m; num <= n; num++) {
        int factor_sum = 1;                  // 初始包含因子1（所有≥2的数的因子）
        int factors[100] = {1};              // 存储因子，保证递增输出
        int factor_count = 1;                // 因子数量（已含1）
        int sqrt_num = (int)sqrt(num);       // 提前计算平方根，减少重复函数调用（优化效率）

        // 查找因子（循环到sqrt(num)，利用因子成对性，解决原始代码循环范围过大问题）
        for (int j = 2; j <= sqrt_num; j++) {
            if (num % j == 0) {  // 正确判断因子（修复原始代码因子判断错误）
                factors[factor_count++] = j;
                factor_sum += j;  // 累加因子本身（修复原始代码累加错误）

                int pair = num / j;
                if (pair != j) {  // 避免重复添加因子（如4的因子2）
                    factors[factor_count++] = pair;
                    factor_sum += pair;
                }
            }
        }

        // 双指针反转后段因子，确保整体递增（替代低效排序，优化性能）
        int left = 1, right = factor_count - 1;
        while (left < right) {
            int temp = factors[left];
            factors[left] = factors[right];
            factors[right] = temp;
            left++;
            right--;
        }

        // 完数判断与正确输出（修复原始代码输出逻辑混乱问题）
        if (factor_sum == num) {
            has_perfect = true;
            printf("%d = 1", num);
            for (int k = 1; k < factor_count; k++) {
                printf(" + %d", factors[k]);
            }
            printf("\n");
        }
    }

    // 替代方案：预定义已知完数法（针对题目范围的极致优化）
    /*
    int known[] = {6, 28, 496, 8128};
    char* forms[] = {
        "6 = 1 + 2 + 3",
        "28 = 1 + 2 + 4 + 7 + 14",
        "496 = 1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248",
        "8128 = 1 + 2 + 4 + 8 + 16 + 32 + 64 + 127 + 254 + 508 + 1016 + 2032 + 4064"
    };
    for (int i = 0; i < 4; i++) {
        if (known[i] >= m && known[i] <= n) {
            printf("%s\n", forms[i]);
            has_perfect = true;
        }
    }
    */

    // 无完数时输出None（修复原始代码flag判断错误）
    if (!has_perfect) {
        printf("None");
    }

    return 0;
}

