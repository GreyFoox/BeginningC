/*思路分析：
N sancf
姓名 基本工资 浮动工资 支出 -> 使用结构体数组 -> scanf来获取数据 
姓名长度 < 10 
输入输出 单精度
相减得到最终工资 .2f （思路正确，但输入输出格式需要修正）*/

#include <stdio.h>

typedef struct {
    char name[10];
    float bs;
    float fs;
    float output;
} Employee;

int main() {
    int n;
    scanf("%d", &n);
    Employee employee[n];
    
    // 原错误代码：
    // for(int i = 0; i < n; i++) {
    //     scanf("%c %lf % lf %lf", employee[i].name, employee[i].bs, employee[i].fs, employee[i].output);
    // }
    // 错误原因：
    // 1. %c应该改为%s来读取字符串
    // 2. %lf用于double类型，但结构体中是float，应该用%f
    // 3. 格式字符串中的空格位置错误
    // 4. scanf参数需要传递变量的地址
    
    // 正确代码：
    for(int i = 0; i < n; i++) {
        scanf("%s %f %f %f", 
              employee[i].name, 
              &employee[i].bs, 
              &employee[i].fs, 
              &employee[i].output);
    }
    
    // 原错误代码：
    // for(int i = 0; i < n; i++) {
    //     printf("%c %lf\n",employee[i].name, employee[i].bs + employee[i].fs - employee[i].output);
    // }
    // 错误原因：
    // 1. %c应该改为%s输出字符串
    // 2. %lf应该改为%.2f来保留两位小数
    
    // 正确代码：
    for(int i = 0; i < n; i++) {
        float salary = employee[i].bs + employee[i].fs - employee[i].output;
        printf("%s %.2f\n", employee[i].name, salary);
    }
    
    return 0;
}

/*
优化方案1：使用动态内存分配
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    float bs;
    float fs;
    float output;
} Employee;

int main() {
    int n;
    scanf("%d", &n);
    
    // 动态分配内存
    Employee *employee = (Employee*)malloc(n * sizeof(Employee));
    if(employee == NULL) {
        printf("内存分配失败\n");
        return 1;
    }
    
    for(int i = 0; i < n; i++) {
        scanf("%s %f %f %f", 
              employee[i].name, 
              &employee[i].bs, 
              &employee[i].fs, 
              &employee[i].output);
    }
    
    for(int i = 0; i < n; i++) {
        float salary = employee[i].bs + employee[i].fs - employee[i].output;
        printf("%s %.2f\n", employee[i].name, salary);
    }
    
    free(employee);
    return 0;
}

优点：可以处理更大的数据量，不受栈空间限制
缺点：需要手动管理内存

优化方案2：使用指针遍历
#include <stdio.h>

typedef struct {
    char name[10];
    float bs;
    float fs;
    float output;
} Employee;

int main() {
    int n;
    scanf("%d", &n);
    Employee employee[n];
    
    // 使用指针输入
    Employee *ptr = employee;
    for(int i = 0; i < n; i++) {
        scanf("%s %f %f %f", 
              ptr->name, 
              &ptr->bs, 
              &ptr->fs, 
              &ptr->output);
        ptr++;
    }
    
    // 使用指针输出
    ptr = employee;  // 重置指针
    for(int i = 0; i < n; i++) {
        float salary = ptr->bs + ptr->fs - ptr->output;
        printf("%s %.2f\n", ptr->name, salary);
        ptr++;
    }
    
    return 0;
}

优点：使用指针操作，代码更高效
缺点：需要理解指针运算

优化方案3：添加输入验证
#include <stdio.h>

typedef struct {
    char name[10];
    float bs;
    float fs;
    float output;
} Employee;

int main() {
    int n;
    if(scanf("%d", &n) != 1 || n <= 0) {
        printf("输入错误\n");
        return 1;
    }
    
    Employee employee[n];
    
    for(int i = 0; i < n; i++) {
        if(scanf("%9s %f %f %f", 
                 employee[i].name, 
                 &employee[i].bs, 
                 &employee[i].fs, 
                 &employee[i].output) != 4) {
            printf("输入格式错误\n");
            return 1;
        }
    }
    
    for(int i = 0; i < n; i++) {
        float salary = employee[i].bs + employee[i].fs - employee[i].output;
        printf("%s %.2f\n", employee[i].name, salary);
    }
    
    return 0;
}

优点：健壮性强，能处理异常输入
缺点：代码稍长
*/
