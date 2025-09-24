#include <stdio.h>

// 全局变量 - 具有全局生存期和作用域
// 问题1：自动初始化为0，但这种隐式初始化可能带来困惑
// 问题2：任何函数都可以修改，导致程序状态难以追踪
int global_var = 0;

// 函数声明
void demonstrate_static_variable(void);
int* dangerous_local_pointer(void);
int* safe_global_pointer(void);
int* safe_static_pointer(void);
void problematic_global_usage(void);
void better_parameter_passing(int value);

int main() {
    // 知识点1：全局变量的自动初始化
    // 全局变量未显式初始化时会自动初始化为0
    // 这可能导致开发者忽略初始化的重要性
    printf("全局变量初始值: %d\n", global_var);
    
    // 知识点2：静态局部变量的持久性
    // 静态局部变量在函数调用间保持值不变
    // 但过度使用会带来与全局变量类似的问题
    demonstrate_static_variable();
    demonstrate_static_variable();
    
    // 知识点3：返回局部变量地址的危险性
    // 局部变量在函数返回后被销毁，返回其地址会导致未定义行为
    int* dangerous_ptr = dangerous_local_pointer();
    // 危险：访问已释放的内存区域
    // printf("危险值: %d\n", *dangerous_ptr); // 注释掉以避免崩溃
    
    // 知识点4：安全的指针返回方式
    // 返回全局变量或静态变量的地址是安全的
    int* safe_ptr1 = safe_global_pointer();
    int* safe_ptr2 = safe_static_pointer();
    printf("安全指针值: %d, %d\n", *safe_ptr1, *safe_ptr2);
    
    // 知识点5：全局变量导致的隐蔽依赖
    problematic_global_usage();
    
    // 知识点6：更好的参数传递方式
    // 通过函数参数传递数据，避免使用全局变量
    better_parameter_passing(100);
    
    return 0;
}

void demonstrate_static_variable(void) {
    // 静态局部变量特性：
    // 1. 只初始化一次（第一次调用时）
    // 2. 函数调用间保持值不变
    // 3. 实际上是具有函数作用域的全局变量
    static int static_local = 10;
    
    // 问题：静态变量和全局变量都会带来状态持久化
    // 这使得函数的行为依赖于历史调用，降低了可预测性
    static_local += 5;
    global_var += 1; // 隐蔽的副作用：修改了全局状态
    
    printf("静态变量: %d, 全局变量: %d\n", static_local, global_var);
}

int* dangerous_local_pointer(void) {
    // 危险做法：返回局部变量的地址
    // 局部变量存储在栈上，函数返回时自动销毁
    int local_var = 42;
    
    // 返回后，该内存区域可能被其他函数覆盖
    // 访问这样的指针会导致未定义行为
    return &local_var;
}

int* safe_global_pointer(void) {
    // 安全做法：返回全局变量的地址
    // 全局变量在程序整个生命周期内有效
    return &global_var;
}

int* safe_static_pointer(void) {
    // 安全做法：返回静态局部变量的地址
    // 静态变量在数据区，程序生命周期内有效
    static int static_var = 999;
    return &static_var;
}

void problematic_global_usage(void) {
    // 演示全局变量带来的问题：
    
    // 问题1：隐蔽的依赖关系
    // 这个函数依赖于外部状态，但接口没有体现这种依赖
    global_var += 10;
    
    // 问题2：难以测试和调试
    // 函数行为受外部状态影响，测试时需要设置全局环境
    
    // 问题3：并发安全问题
    // 多线程环境下，全局变量需要额外的同步机制
    printf("全局变量当前值: %d\n", global_var);
}

void better_parameter_passing(int value) {
    // 更好的做法：通过参数传递数据
    
    // 优点1：明确的接口依赖
    // 函数的所有输入都通过参数明确声明
    
    // 优点2：无副作用
    // 函数不修改外部状态（除非通过指针参数明确声明）
    
    // 优点3：易于测试和重用
    // 函数行为完全由参数决定，不依赖外部环境
    
    int result = value * 2;
    printf("通过参数计算的结果: %d\n", result);
    
    // 如果需要修改外部变量，应该通过指针参数明确传递
    // 例如：void process_data(int input, int* output);
}

// 额外的知识点说明：

/**
 * 全局变量的替代方案：
 * 
 * 1. 使用函数参数传递数据
 *    - 优点：接口清晰，无隐藏依赖
 *    - 缺点：调用链较长时参数传递繁琐
 * 
 * 2. 使用静态变量（谨慎使用）
 *    - 优点：限制在函数作用域内
 *    - 缺点：仍然有状态持久化的问题
 * 
 * 3. 使用堆内存和明确的所有权管理
 *    - 优点：生命周期明确可控
 *    - 缺点：需要手动管理内存
 * 
 * 4. 使用面向对象的设计模式
 *    - 将相关数据和操作封装在一起
 *    - 通过实例变量代替全局变量
 */

/**
 * 何时可以考虑使用全局变量：
 * 
 * 1. 程序的配置信息（只读）
 * 2. 单例模式的实现
 * 3. 性能关键的场景（经过充分测试）
 * 4. 小型工具程序或脚本
 * 
 * 但即使在这些情况下，也应该优先考虑其他设计方案。
 */

/**
 * 返回指针的最佳实践：
 * 
 * 1. 返回传入的指针参数（最安全）
 * 2. 返回动态分配的内存指针（调用者负责释放）
 * 3. 返回全局或静态变量的指针
 * 4. 避免返回局部变量的指针
 */
