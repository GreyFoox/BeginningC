#include <stdio.h>

int MonthDays(int year, int month);

int main()
{
    // 原始代码：定义了三个变量
    // int ndays, month, year;
    int year;  // 优化后：只保留必要的year变量，减少冗余

    scanf("%d", &year);
    // 原始代码：循环变量month在外部定义，使用ndays中转结果
    // for(month = 1; month <= 12; month++){
    //     ndays = MonthDays(year, month);
    //     printf("%d ", ndays);
    // }
    // 优化后：循环变量在循环内定义（缩小作用域），直接打印结果（减少中间变量）
    for(int month = 1; month <= 12; month++){
        printf("%d ", MonthDays(year, month));
    }

    return 0;
}

int MonthDays(int year, int month) {
    // 原始代码：使用flag作为标记变量
    // int flag = 0;
    int is_leap = 0;  // 优化后：变量名改为is_leap，语义更明确

    // 原始代码：闰年判断逻辑（逻辑不变）
    // if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
    //     flag = 1;
    // }
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        is_leap = 1;  // 优化后：变量名对应修改
    }

    // 原始代码：定义两个高度重复的数组（平年和闰年）
    // int arr1[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // if(flag) {
    //     int arr2[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //     return arr2[month];
    // }
    // return arr1[month];
    // 优化后：用一个静态常量数组替代两个数组（减少冗余）
    static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 优化后：用条件表达式简化逻辑（替代if-return结构）
    return (is_leap && month == 2) ? 29 : days[month];
}
    
