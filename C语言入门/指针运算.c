#include <stdio.h>

/**
 * 演示指针算术运算、数组遍历和类型转换
 */

int main(void) {
    printf("=== 1. 指针算术运算 ===\n");
    
    // 字符数组 - 每个元素占1字节
    char ac[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char *p = ac; // p指向数组ac的首元素
    
    printf("字符数组ac的地址:\n");
    printf("p   = %p\n", p);    // 输出p的当前值（地址）
    printf("p+1 = %p\n", p+1);  // 输出p+1的地址（增加1字节）
    printf("*(p+1) = %d\n", *(p+1)); // 解引用p+1，获取ac[1]的值
    
    // 整数数组 - 每个元素通常占4字节（取决于系统）
    int ai[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *q = ai; // q指向数组ai的首元素
    
    printf("\n整数数组ai的地址:\n");
    printf("q   = %p\n", q);    // 输出q的当前值（地址）
    printf("q+1 = %p\n", q+1);  // 输出q+1的地址（增加4字节）
    printf("*(q+1) = %d\n", *(q+1)); // 解引用q+1，获取ai[1]的值
    
    printf("\n=== 2. 指针遍历数组 ===\n");
    
    // 使用哨兵值(-1)标记数组结束的字符数组
    char ac2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
    char *p2 = &ac2[0]; // p2指向数组ac2的首元素
    
    printf("使用索引遍历数组:\n");
    for (int i = 0; i < sizeof(ac2)/sizeof(ac2[0]); i++) {
        printf("%d ", ac2[i]);
    }
    printf("\n");
    
    printf("使用指针遍历数组(直到遇到-1):\n");
    // while (*p2 != -1) {
    //     printf("%d ", *p2++); // 先取p2指向的值，然后p2自增
    // }
    // 上面的循环会漏掉最后一个元素(因为遇到-1就停止了)
    // 修改为更安全的版本：
    p2 = ac2; // 重置指针
    while (*p2 != -1) {
        printf("%d ", *p2);
        p2++;
    }
    printf("\n");
    
    printf("\n=== 3. 指针类型转换 ===\n");
    
    int i = 0x12345678; // 一个整数值
    int *pi = &i;       // 指向整数的指针
    void *pv = (void *)pi; // 将int*转换为void*
    char *pc = (char *)pi; // 将int*转换为char*
    
    printf("整数值 i = 0x%x\n", i);
    printf("int指针 pi = %p, 指向的值 = 0x%x\n", pi, *pi);
    printf("void指针 pv = %p\n", pv);
    printf("char指针 pc = %p, 指向的值 = 0x%x\n", pc, *pc);
    
    // 通过char指针查看整数的各个字节
    printf("\n通过char指针查看整数的各个字节(字节序):\n");
    for (int j = 0; j < sizeof(int); j++) {
        printf("字节 %d: 0x%02x\n", j, *(pc + j));
    }
    
    return 0;
}
