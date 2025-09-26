#include <stdio.h>
#include <stdlib.h>

/**
 * 程序1: 动态分配数组并逆序输出
 * 演示malloc()和free()的基本用法
 */
void reverse_array() {
    int number;
    int* a;
    int i;
    
    printf("输入数量: ");
    scanf("%d", &number);
    
    // 动态分配内存 - 创建大小为number的整数数组
    a = (int*)malloc(number * sizeof(int));
    
    // 检查内存分配是否成功
    if (a == NULL) {
        printf("内存分配失败!\n");
        return;
    }
    
    // 读取输入数据
    printf("请输入%d个整数: ", number);
    for (i = 0; i < number; i++) {
        scanf("%d", &a[i]);
    }
    
    // 逆序输出数组
    printf("逆序输出: ");
    for (i = number - 1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    // 释放分配的内存
    free(a);
}

/**
 * 程序2: 测试系统可分配的内存上限
 * 不断分配100MB内存块直到失败
 */
void test_memory_limit() {
    void *p;
    int cnt = 0;
    
    // 不断尝试分配100MB内存块
    while ((p = malloc(100 * 1024 * 1024)) != NULL) {
        cnt++;
    }
    
    printf("分配了%d00MB的空间\n", cnt);
    
    // 注意: 这里没有释放内存，因为程序即将退出
    // 在实际应用中，应该释放所有分配的内存
}

int main(void) {
    printf("=== 动态内存分配演示 ===\n\n");
    
    // 运行第一个程序
    printf("程序1: 动态数组逆序输出\n");
    reverse_array();
    
    printf("\n");
    
    // 运行第二个程序
    printf("程序2: 内存分配极限测试\n");
    test_memory_limit();
    
    return 0;
}
