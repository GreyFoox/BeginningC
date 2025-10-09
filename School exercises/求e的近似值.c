#include <stdio.h>
#include <limits.h>

int main() {
    // 原始代码（保留用于对比）
    /*
    double sum = 1.0;
    double term = 1.0;
    int n;
    scanf("%d", n);  // 错误1：缺少&，无法读取输入
    for(int i = 1; i <= n; i++) {
        term *= i;
        sum += 1 / term;  // 错误2：整数除法导致精度丢失
    }
    printf(".8f", sum);  // 错误3：格式符缺少%，输出错误
    return 0;
    */

    double sum = 1.0;       // 初始值：1（对应1/0!）
    double term = 1.0;      // 存储阶乘值（i!），初始为1（0! = 1）
    int n;
    int input_result;       // 用于检查输入合法性

    // 1. 逻辑与功能正确性修复
    // 修复原始代码错误1：添加&取地址符，确保输入正确读取
    input_result = scanf("%d", &n);

    // 5. 鲁棒性增强：处理无效输入
    if (input_result != 1) {  // 非整数输入
        printf("ERROR");
        return 1;
    }
    if (n < 0) {  // 阶乘无负数定义，边界处理
        printf("ERROR");
        return 1;
    }

    // 2. 性能优化：提前终止循环（当term过大时，1/term对结果无影响）
    // 原理：double有效精度约15-17位，当term > 1e16时，1/term < 1e-16，不影响8位小数结果
    const double MIN_EFFECT = 1e-16;  // 最小有效阈值
    for (int i = 1; i <= n; i++) {
        term *= i;  // 迭代计算i!（避免重复计算，时间复杂度O(n)）

        // 提前退出条件：当1/term小于阈值时，累加无意义
        if (term > 1.0 / MIN_EFFECT) {
            break;
        }

        // 修复原始代码错误2：用1.0确保浮点除法，避免整数截断
        sum += 1.0 / term;
    }

    // 修复原始代码错误3：添加%，正确指定8位小数格式
    printf("%.8f\n", sum);

    return 0;
}

