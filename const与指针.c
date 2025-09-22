#include <stdio.h>

int main(void) {
    int i = 0;
    int j = 10;
    
    /* 
     * 指向常量的指针 (Pointer to const)
     * 承诺：不通过指针p修改其所指向的数据
     * 注意：const int *p 与 int const *p 完全等价
     */
    const int *p = &i; // p指向一个const int（这里指向i）
    // *p = 26;  // 错误：违反承诺，不能通过p修改i的值
    p = &j;     // 正确：可以改变p的指向，现在指向j
    i = 26;     // 正确：i本身不是const，可以直接修改
    
    /*
     * 常量数组 (Const array)
     * 承诺：数组内容不可修改
     * 优化：编译器可能将此类数组放入只读数据段(.rodata)
     *       并进行激进优化（如直接替换使用处的值为字面量）
     */
    const int a[] = {1, 2, 3, 4, 5, 6}; // 只能通过初始化赋值
    // a[0] = 10;  // 错误：不能修改const数组元素
    // int *ptr = a; // 警告：丢弃const限定符（C++中错误）
    
    /*
     * 常量指针 (Constant pointer) - 指针本身不可修改
     * 承诺：指针的值（指向的地址）不可改变
     */
    int *const const_ptr = &i; // const_ptr将始终指向i
    *const_ptr = 30;           // 正确：可以通过const_ptr修改i的值
    // const_ptr = &j;         // 错误：不能改变const_ptr的指向
    
    /*
     * 指向常量的常量指针 (Constant pointer to const)
     * 双重承诺：既不能修改指针的指向，也不能通过指针修改数据
     */
    const int *const const_ptr_to_const = &i;
    // *const_ptr_to_const = 40;  // 错误：不能通过指针修改数据
    // const_ptr_to_const = &j;   // 错误：不能改变指针的指向
    
    printf("i = %d, j = %d\n", i, j);
    printf("a[0] = %d\n", a[0]);
    
    return 0;
}

/*
 * 关键总结：
 * 1. const是一种"承诺"，告诉编译器和其他程序员"我不会修改这个数据"
 * 2. const位置决定约束对象：
 *    - const在*左侧：约束指向的数据（数据不可变）
 *    - const在*右侧：约束指针本身（指针不可变）
 * 3. const带来的好处：
 *    - 提高代码可读性和可维护性（明确设计意图）
 *    - 增强安全性（编译器防止意外修改）
 *    - 启用编译器优化（将const数据放入只读段，替换为字面量等）
 * 4. 最佳实践：在函数参数和变量声明中，尽可能使用const限定符
 */
