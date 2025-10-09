#include <stdio.h>
#include <string.h>

int main() {
    // 原始代码（未使用sprintf、strlen等字符串函数）
    /*
    long n;
    scanf("%l", &n);  // 原始错误：long类型格式符应为%ld
    while( n != 0) {  // 原始逻辑：从低位到高位输出，未处理n=0
        int m = n % 10;
        printf("%d ", m);
        n /= 10;
    }
    */

    // 方法1：权重法（修复原始代码，仍不依赖字符串函数）
    /*
    思路：纯算术运算实现，无需字符串函数
    步骤：
    1. 修复输入格式符为%ld，正确读取long类型
    2. 处理n=0的特殊情况（输出"0 "）
    3. 计算最高位权重（如12345→10000），定位最高位
    4. 从高位到低位逐位提取并输出
    
    优点：仅用基础算术（+、-、*、/、%），不依赖额外函数
    缺点：需两次循环（计算权重+输出），逻辑较繁琐
    */
    /*
    long n;
    scanf("%ld", &n);
    if (n == 0) {
        printf("0 ");
        return 0;
    }
    long divisor = 1;
    while (n / divisor >= 10) divisor *= 10;  // 计算最高位权重
    while (divisor > 0) {
        printf("%d ", (n / divisor) % 10);    // 提取高位数字
        divisor /= 10;
    }
    */

    // 方法2：字符串法（使用sprintf、strlen，优化后实现）
    /*
    思路：借助字符串函数简化实现
    步骤：
    1. 用%ld正确读取输入
    2. 处理n=0的特殊情况
    3. 将数字转为字符串（用sprintf）
    4. 遍历字符串输出（用strlen控制循环范围）
    
    优点：逻辑简单，一次循环完成输出，代码简洁
    缺点：依赖字符串函数，需要额外数组存储
    */
    long n;
    scanf("%ld", &n);
    if (n == 0) {
        printf("0 ");
        return 0;
    }
    char str[20];
    // sprintf函数：将格式化的数据写入字符串
    // 此处作用：把long类型的n按"%ld"格式转为字符串存到str中
    // 格式：sprintf(目标字符串, 格式符, 待转换数据)
    sprintf(str, "%ld", n);
    
    // strlen函数：计算字符串长度（不含终止符'\0'）
    // 此处作用：获取数字的位数，控制循环次数
    // 格式：strlen(字符串) → 返回字符个数
    for (int i = 0; i < strlen(str); i++) {
        printf("%c ", str[i]);
    }

    return 0;
}

/*
【原始代码未使用的函数科普】
1. sprintf函数：
   - 功能：将格式化的数据（如整数、浮点数）转换为字符串
   - 原型：int sprintf(char *str, const char *format, ...)
   - 举例：sprintf(str, "%ld", 12345) → str变为"12345"
   - 本代码应用：替代手动计算每位数字的复杂逻辑，直接将数字转为字符串，保留高位到低位的自然顺序

2. strlen函数：
   - 功能：计算字符串的长度（即字符个数，不包括末尾的终止符'\0'）
   - 原型：size_t strlen(const char *str)
   - 举例：strlen("12345") → 返回5
   - 本代码应用：获取数字字符串的长度，确定循环输出的次数，避免手动计算位数
*/
    
