/*思路分析：
获取a1 b1 scanf("%d / %d", &a1, &b1)（格式字符串有误，应该是"%d/%d %d/%d"）
用m来存计算结果（double类型）（正确，但要注意类型转换语法）
a2, b2 同理 用n来存结果（正确）
比较m n（正确）
如果m > n 就直接打印printf("%d / %d > %d / %d",省略)（正确）
担心：会不会出现精度失效？无法得到预期结果？（正确，使用浮点数比较确实可能存在精度问题）*/

#include <stdio.h>

int main() {
    int a1, b1, a2, b2;
    // 原错误代码：
    // scanf("%d / %d %d / %d", &a1, &b1, &a2, &b2);
    // 错误原因：格式字符串中的空格和斜杠位置不正确，应该去掉多余的空格
    
    // 正确代码：
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
    
    // 原错误代码：
    // double m = double(a1) / double(b1);
    // double m = double(a2) / double(b2);
    // 错误原因：1. 重复定义m 2. C语言中类型转换语法是(double)a1，不是double(a1)
    
    // 正确代码：
    double m = (double)a1 / (double)b1;
    double n = (double)a2 / (double)b2;
    
    if (m > n) {
        printf("%d/%d > %d/%d", a1, b1, a2, b2);
    } else if (m < n) {
        printf("%d/%d < %d/%d", a1, b1, a2, b2);
    } else {
        printf("%d/%d = %d/%d", a1, b1, a2, b2);
    }
    return 0;
}

/*
优化方案1：使用整数运算避免浮点精度问题
#include <stdio.h>

int main() {
    int a1, b1, a2, b2;
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
    
    // 交叉相乘比较，避免浮点数精度问题
    long long left = (long long)a1 * b2;
    long long right = (long long)a2 * b1;
    
    if (left > right) {
        printf("%d/%d > %d/%d", a1, b1, a2, b2);
    } else if (left < right) {
        printf("%d/%d < %d/%d", a1, b1, a2, b2);
    } else {
        printf("%d/%d = %d/%d", a1, b1, a2, b2);
    }
    return 0;
}

优点：避免浮点数精度问题，结果更准确
缺点：可能溢出，但使用long long可以缓解

优化方案2：使用分数化简后比较
#include <stdio.h>

// 求最大公约数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 化简分数
void simplify(int *a, int *b) {
    int g = gcd(*a, *b);
    *a /= g;
    *b /= g;
}

int main() {
    int a1, b1, a2, b2;
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
    
    // 化简分数
    simplify(&a1, &b1);
    simplify(&a2, &b2);
    
    // 通分后比较分子
    int left = a1 * b2;
    int right = a2 * b1;
    
    if (left > right) {
        printf("%d/%d > %d/%d", a1, b1, a2, b2);
    } else if (left < right) {
        printf("%d/%d < %d/%d", a1, b1, a2, b2);
    } else {
        printf("%d/%d = %d/%d", a1, b1, a2, b2);
    }
    return 0;
}

优点：化简分数后比较更直观
缺点：需要额外的化简步骤

优化方案3：使用精确分数比较
#include <stdio.h>

int main() {
    int a1, b1, a2, b2;
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
    
    // 使用分数比较的精确方法：a1/b1 - a2/b2 = (a1*b2 - a2*b1)/(b1*b2)
    // 由于分母b1*b2总是正数，只需比较分子
    int numerator = a1 * b2 - a2 * b1;
    
    if (numerator > 0) {
        printf("%d/%d > %d/%d", a1, b1, a2, b2);
    } else if (numerator < 0) {
        printf("%d/%d < %d/%d", a1, b1, a2, b2);
    } else {
        printf("%d/%d = %d/%d", a1, b1, a2, b2);
    }
    return 0;
}

优点：数学上最精确，避免所有精度问题
缺点：需要理解分数比较的数学原理
*/
