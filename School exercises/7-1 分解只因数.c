/* 原始代码（含问题标注）
#include <stdio.h>

int main() {
    int t;
    int n;
    scanf("%d", &t);
    int arr[t];  // 问题1：使用VLA（可变长度数组），兼容性差；且无需数组存储
    for(int i = 0; i < t; i++) {
        // 问题2：错误将scanf返回值（输入成功的个数）存入数组，而非实际输入的n值
        arr[i] = scanf("%d", &n);  
    }
    for(int i = 0; i < t; i++) {
        // 问题3：判断逻辑错误，实际判断的是scanf返回值的奇偶性，与n无关
        if (arr[i] % 2 == 0) {  
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}
*/

// 优化后代码
#include <stdio.h>

// 判断一个数是否为"只因数"（所有质因数均为奇数）
// 原理：唯一的偶质数是2，因此只需判断数是否为奇数
int is_only_odd(long long num) {
    return (num % 2 != 0);
}

int main() {
    int t;
    // 输入合法性检查：确保测试组数在有效范围（修复原始代码无检查问题）
    if (scanf("%d", &t) != 1 || t < 1 || t > 9) {
        printf("错误：测试组数必须是1-9的整数\n");
        return 1;
    }

    for (int i = 0; i < t; i++) {
        long long n;  // 使用long long类型，支持1e18范围（修复原始代码int类型不足问题）
        // 输入合法性检查：确保n是≥2的整数（符合题目约束）
        if (scanf("%lld", &n) != 1 || n < 2) {
            printf("错误：第%d组数据必须是≥2的整数\n", i + 1);
            return 1;
        }

        // 核心判断逻辑（修复原始代码判断逻辑错误）
        if (is_only_odd(n)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
