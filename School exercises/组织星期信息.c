/*思路分析：
n -> scanf
输入星期几用指针数组存 char* arr = (char*) malloc(n * 9 * sizeof(char)) -> 用最长的星期三
似乎第一个序号是1
大于n ->输出 -1
小于n -> 写find函数（思路基本正确，但实现方式有误，应该使用指针数组存储星期名称）*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    // 原错误代码：
    // char* arr = (char*) malloc(n * 9 * sizeof(char));
    // char* ptr = arr;
    // char date[9];
    // while(ptr < arr + n) {
    //     scanf("%s", &date);
    //     *ptr++ = date;
    // }
    // 错误原因：
    // 1. 分配的内存使用方式错误，应该是存储字符串指针而不是字符
    // 2. *ptr++ = date 试图将数组地址赋给字符，类型不匹配
    // 3. 没有正确存储输入的字符串
    
    // 正确代码：
    // 定义星期名称的指针数组
    char *weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    // 处理repeat次查询
    for(int i = 0; i < n; i++) {
        char input[10];
        scanf("%s", input);
        
        int found = -1;
        // 在星期数组中查找输入字符串
        for(int j = 0; j < 7; j++) {
            if(strcmp(input, weekdays[j]) == 0) {
                found = j + 1;  // 序号从1开始
                break;
            }
        }
        printf("%d\n", found);
    }
    
    return 0;
}

/*
优化方案1：使用函数封装查找逻辑
#include <stdio.h>
#include <string.h>

// 查找函数
int findWeekday(char *day) {
    char *weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    for(int i = 0; i < 7; i++) {
        if(strcmp(day, weekdays[i]) == 0) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        char input[10];
        scanf("%s", input);
        printf("%d\n", findWeekday(input));
    }
    
    return 0;
}

优点：代码结构清晰，查找逻辑独立，易于维护
缺点：函数调用有一定开销
适用范围：需要代码可读性和可维护性的项目

优化方案2：使用哈希表快速查找
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 简单的字符串哈希函数
unsigned int hash(char *str) {
    unsigned int hash = 0;
    while(*str) {
        hash = (hash * 31) + *str;
        str++;
    }
    return hash;
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 预计算星期名称的哈希值
    char *weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    unsigned int hashes[7];
    for(int i = 0; i < 7; i++) {
        hashes[i] = hash(weekdays[i]);
    }
    
    for(int i = 0; i < n; i++) {
        char input[10];
        scanf("%s", input);
        unsigned int inputHash = hash(input);
        
        int found = -1;
        for(int j = 0; j < 7; j++) {
            if(inputHash == hashes[j] && strcmp(input, weekdays[j]) == 0) {
                found = j + 1;
                break;
            }
        }
        printf("%d\n", found);
    }
    
    return 0;
}

优点：对于大量查询，哈希比较比字符串比较更快
缺点：代码复杂度增加，需要处理哈希冲突
适用范围：数据量大且查询频繁的场景

优化方案3：使用switch-case优化（如果编译器支持字符串switch）
#include <stdio.h>
#include <string.h>

int findWeekday(char *day) {
    // 注意：这不是标准C语法，但某些编译器支持
    // 这里只是展示思路，实际实现需要根据编译器特性调整
    if(strcmp(day, "Sunday") == 0) return 1;
    else if(strcmp(day, "Monday") == 0) return 2;
    else if(strcmp(day, "Tuesday") == 0) return 3;
    else if(strcmp(day, "Wednesday") == 0) return 4;
    else if(strcmp(day, "Thursday") == 0) return 5;
    else if(strcmp(day, "Friday") == 0) return 6;
    else if(strcmp(day, "Saturday") == 0) return 7;
    else return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        char input[10];
        scanf("%s", input);
        printf("%d\n", findWeekday(input));
    }
    
    return 0;
}

优点：在某些编译器中可能有更好的性能
缺点：可移植性差，不是标准C语法
适用范围：特定编译环境下的性能优化
*/
