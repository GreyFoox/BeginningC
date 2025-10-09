#include <stdio.h>

int main() {
    double eps;
    scanf("%le", &eps);
    
    // 原始代码存在的问题：逻辑错误（提前return、整数除法、变量初始化错误）
    /*
    return 0;  // 提前返回导致代码不执行
    double sum = 1 + 1 / 3;  // 整数除法导致1/3=0
    double count = 1;
    while(count >= eps) { 
        int nu = 1;  // 循环内重复初始化，无法递增
        int de = 3;
        if((double)(nu / de) < eps) {
            break;
        }
        nu++;
        de += 3;
        count = (double)(nu / de);  // 整数除法导致精度错误
        sum += count; 
    }
    printf("%.5f", sum);
    */
    
    // 性能优化1：使用递推公式计算每一项，避免重复计算阶乘和乘积
    // 公式规律：第i项 = 第i-1项 × i/(2i+1)（i从1开始）
    double sum = 1.0;  // 第一项为1.0（i=0时）
    double term = 1.0; // 当前项初始值（第一项）
    int i = 1;         // 从第2项开始计算（i=1对应第二项）
    
    // 边界条件：当当前项term >= eps时，继续累加
    // ">=中的'='不可遗漏，确保刚好等于eps的项被纳入求和（否则会少算一项）
    while (term >= eps) {
        // 递推计算下一项：避免计算大阶乘和长乘积，直接用前一项推导
        term = term * i / (2 * i + 1);  // 浮点数计算，无整数除法问题
        sum += term;
        i++;
    }
    
    double pi = 2 * sum;  // 根据公式2/π = sum → π = 2*sum
    printf("PI = %.5f\n", pi);
    
    return 0;
}

