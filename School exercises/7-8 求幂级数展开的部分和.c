#include <stdio.h>
#include <math.h>

int main() {
    double x;
    // 输入检查（鲁棒性优化）
    if (scanf("%lf", &x) != 1) {
        printf("输入错误：请输入有效的数字\n");
        return 1;
    }

    // 方法1：泰勒级数递推法（当前使用，平衡精度与实现复杂度）
    double term = 1.0;       // 当前项：x^n / n!（初始为n=0的项）
    double result = term;    // 累加结果
    int n = 1;               // 阶乘数

    while (fabs(term) >= 1e-5) {
        term *= x / n;       // 递推计算下一项（优化点：避免重复计算x^n和n!）
        result += term;
        n++;
    }

    printf("%.4lf\n", result);
    return 0;
}

/*
替代方法说明：

1. 方法2：直接调用标准库函数exp()
   实现代码：
   #include <math.h>
   int main() {
       double x;
       scanf("%lf", &x);
       printf("%.4lf\n", exp(x));
       return 0;
   }
   优点：由编译器高度优化，精度更高（通常达15位有效数字），计算速度极快（底层用近似算法而非逐项累加）
   缺点：无法体现手动计算逻辑，不适用于学习场景；依赖math库

2. 方法3：区间分段近似法（针对大|x|优化）
   原理：利用e^(a+b) = e^a * e^b，将大x拆分为整数a和小数b（|b|≤0.5），对b用泰勒级数，a用查表法
   优点：解决泰勒级数在|x|较大时收敛慢的问题（如x=10时，泰勒需约40项，分段法只需10项以内）
   缺点：实现复杂，需预先计算常用区间的e^a值

3. 原始代码的问题对比：
   - 冗余计算：单独维护pre_exp和pre_fac，实际可通过term *= x/n递推
   - 逻辑错误：循环结束后多累加一次term（此时已小于阈值），导致结果偏大
   - 未处理负数：循环条件用term >= 1e-5，对x<0时的负项会提前终止，导致精度不足
*/

