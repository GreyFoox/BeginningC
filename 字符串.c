#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    printf("=== C语言字符串操作教程 ===\n\n");
    
    // ========== 1. 字符串的基本表示方式 ==========
    printf("1. 字符串的基本表示方式:\n");
    
    // 方式1: 字符数组形式，手动添加结束符'\0'
    char words0[] = {'m','i','k','u','\0'};
    printf("  字符数组: %s (长度: %zu)\n", words0, strlen(words0));
    
    // 方式2: 字符串字面量初始化数组，自动添加结束符
    char words1[] = "Miku";
    printf("  字符串字面量: %s (长度: %zu)\n", words1, strlen(words1));
    
    // 方式3: 指向字符串常量的指针(只读)
    const char *words2 = "Miku";
    printf("  字符串指针: %s (长度: %zu)\n\n", words2, strlen(words2));
    
    
    // ========== 2. 字符串输入输出 ==========
    printf("2. 字符串输入输出:\n");
    
    // 安全输入字符串 - 限制输入长度为7个字符(保留1位给结束符)
    char str[8];
    printf("  请输入一个字符串(最多7个字符): ");
    scanf("%7s", str);
    printf("  你输入的字符串: %s\n", str);
    
    // 清除输入缓冲区
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    // 字符输入输出
    printf("  请输入一个字符: ");
    int ch = getchar();
    printf("  你输入的字符: ");
    putchar(ch);
    printf("\n\n");
    
    
    // ========== 3. 字符串比较与复制 ==========
    printf("3. 字符串比较与复制:\n");
    
    // 字符串比较
    char s1[] = "abc";
    char s2[] = "abc";
    printf("  字符串比较结果: %d (0表示相等)\n", strcmp(s1, s2));
    
    // 字符串复制
    const char *src = "Hello World";
    char *dst = (char*)malloc(strlen(src) + 1); // 分配足够内存(包含结束符)
    if (dst != NULL) {
        strcpy(dst, src); // 目标在前，源在后
        printf("  复制的字符串: %s\n", dst);
        free(dst); // 释放内存
    }
    printf("\n");
    
    
    // ========== 4. 字符串搜索函数 ==========
    printf("4. 字符串搜索函数:\n");
    
    // strstr - 在字符串中查找子串(区分大小写)
    const char *text = "Hello World, hello C language";
    const char *substr = "hello";
    
    char *result = strstr(text, substr);
    if (result != NULL) {
        printf("  找到子串: %s\n", result);
    } else {
        printf("  未找到子串: %s\n", substr);
    }
    
    // strchr - 查找字符
    char *char_result = strchr(text, 'W');
    if (char_result != NULL) {
        printf("  找到字符: %s\n", char_result);
    }
    printf("\n");
    
    
    // ========== 5. 修复后的代码示例 ==========
    printf("5. 修复后的代码示例:\n");
    
    char s[] = "hello";
    
    // 查找字符'l'而不是不存在的'1'
    char *p = strchr(s, 'l');
    
    if (p != NULL) {
        char c = *p;        // 保存找到的字符
        *p = '\0';          // 分割字符串
        
        // 正确分配内存并复制字符串
        char *t = (char*)malloc(strlen(s) + 1); // +1用于结束符
        if (t != NULL) {
            strcpy(t, s);    // 复制字符串
            printf("  分割后的字符串: %s\n", t);
            free(t);         // 释放内存
        }
        
        // 恢复原字符
        *p = c;
        printf("  恢复后的原字符串: %s\n", s);
    } else {
        printf("  未找到指定字符\n");
    }
    
    printf("\n=== 教程结束 ===\n");
    
    return 0;
}
