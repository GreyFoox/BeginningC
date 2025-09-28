#include <stdio.h>

/* 原始代码（含问题标注）：
#include <stdio.h>

int main() {
    int n;                  // 问题1：变量命名简单，且被修改后原始值丢失
    int count = 0;          // 问题2："count"命名模糊，未体现"步骤计数"含义
    scanf("%d", &n);        // 问题3：未校验输入合法性（非整数/0/负数会导致异常）
    while(n != 1) {         // 问题4：未显式处理n=1的边界情况，逻辑不直观
        if( n % 2 == 0) {
            n = n / 2;
            count++;        // 问题5：与else分支的count++重复，存在代码冗余
        } else {
            n = (3 * n + 1) / 2;
            count++;        // 问题5：与if分支的count++重复，存在代码冗余
        }
    }
    printf("%d", count);    // 问题6：仅输出数字，缺乏上下文，用户体验差
    return 0;               // 问题7：使用int存储n可能导致大数值溢出
}
*/

int main() {
    // 优化1：变量拆分与命名优化（解决问题1、2、7）
    int originalN;         // 保留原始输入值，不修改
    long long currentNum;  // 使用long long减少大数值溢出风险
    int stepCount = 0;     // 命名明确，体现"步骤计数"含义

    // 优化2：输入校验与提示（解决问题3）
    printf("请输入正整数：");
    if (scanf("%d", &originalN) != 1 || originalN <= 0) {
        printf("输入错误：请输入正整数！\n");
        return 1;  // 非法输入时及时退出
    }

    currentNum = originalN;  // 用currentNum参与计算，保留原始值

    // 优化3：显式处理边界情况（解决问题4）
    if (currentNum == 1) {
        printf("1变换到1需要0步\n");
        return 0;
    }

    // 优化4：消除代码冗余（解决问题5）
    while (currentNum != 1) {
        if (currentNum % 2 == 0) {
            currentNum /= 2;
        } else {
            currentNum = (3 * currentNum + 1) / 2;  // 保留核心计算逻辑
        }
        stepCount++;  // 合并重复的计数操作
    }

    // 优化5：输出信息优化（解决问题6）
    printf("%d变换到1共需要%d步\n", originalN, stepCount);

    return 0;
}

