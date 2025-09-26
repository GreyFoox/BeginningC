#include <stdio.h>
#include <stdlib.h>

int main() {
    // 原始代码存在的问题：
    // 1. 未读取初始操作数，sum初始化为0不合理
    // 2. 未处理多位数解析（如"123"无法正确识别）
    // 3. 缺少运算符合法性检查和除法分母为0的判断
    // 4. sum += 后无具体逻辑，switch分支未实现运算
    /*
    char c;
    int sum = 0;
    
    while((c = getchar()) != '=') {
        sum += 
        switch(c) {
            case '+' :
                //加上后一个数 
            case '-' :
                //减去后一个数 
            case '*' :
                //乘上后一个数 
            case '/' :
                //除后一个数 
        }
    }
    return 0;
    */

    int sum;          // 存储运算结果
    char op;          // 存储运算符
    int next_num;     // 存储下一个操作数

    // 步骤1：读取第一个操作数（必须存在，否则为错误）
    // 性能优化：用scanf直接读取整数，避免手动解析多位数的开销
    if (scanf("%d", &sum) != 1) {
        printf("ERROR");  // 无有效操作数，输出错误
        return 0;
    }

    // 步骤2：循环读取运算符和下一个操作数，直到遇到'='
    while (scanf("%c", &op) == 1) {  // 读取运算符
        if (op == '=') {  // 遇到等号，计算结束
            printf("%d", sum);
            return 0;
        }

        // 边界检查1：判断运算符是否合法（只能是+-*/）
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            printf("ERROR");
            return 0;
        }

        // 步骤3：读取下一个操作数（运算符后必须有有效数字）
        if (scanf("%d", &next_num) != 1) {
            printf("ERROR");  // 无有效操作数，输出错误
            return 0;
        }

        // 步骤4：根据运算符执行相应运算（从左到右，优先级相同）
        switch (op) {
            case '+':
                sum += next_num;
                break;
            case '-':
                sum -= next_num;
                break;
            case '*':
                sum *= next_num;
                break;
            case '/':
                // 边界检查2：除法分母不能为0
                if (next_num == 0) {
                    printf("ERROR");
                    return 0;
                }
                sum /= next_num;  // 整数除法（截断处理）
                break;
        }
    }

    // 若循环结束仍未遇到'='，属于输入格式错误
    printf("ERROR");
    return 0;
}

