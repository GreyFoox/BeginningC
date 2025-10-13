/*思路分析：
n行（正确）
正三角形 -> n行 每行个数从1开始递增到n（正确）
每个数字固定占四位 -> 应该使用%4d格式化输出，而不是\t（\t的宽度不固定，不符合题目要求）
杨辉三角 -> 两头都是1 新中间 = 旧中间之和（正确，这是杨辉三角的核心性质）
除了1的新两边 = 上一行边缘两个数之和（表述不够准确，应该是每个数等于它上方两个数之和）
对杨辉三角不熟悉 二项式定理也可以吧？ -> 阶乘（可以使用二项式系数计算，但效率较低，递推关系更高效）*/

#include <stdio.h>

int main() {
    int n, i, j, k;
    int a[15][15] = {0};
    
    scanf("%d", &n);
    
    // 初始化前两行
    a[0][0] = 1;
    a[1][0] = 1;
    a[1][1] = 1;
    
    // 单独处理第一行
    for(k = n-1; k > 0; k--)
        printf(" ");
    printf("   1\n");
    
    // 处理后续行
    for(i = 1; i < n; i++) {
        // 打印行前空格
        for(k = n-1; k > i; k--)
            printf(" ");
        
        // 计算并打印当前行
        for(j = 0; j <= i; j++) {
            if(j == 0 || j == i)
                a[i][j] = 1;
            else
                a[i][j] = a[i-1][j-1] + a[i-1][j];
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

/*
优化方案1：使用一维数组（节省空间）
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int row[15] = {1}; // 初始化为第一行
    
    // 单独处理第一行
    for(int k = n-1; k > 0; k--)
        printf(" ");
    printf("   1\n");
    
    for(int i = 1; i < n; i++) {
        // 打印空格
        for(int k = n-1; k > i; k--)
            printf(" ");
        
        // 计算下一行（从后往前更新，避免覆盖）
        for(int j = i; j > 0; j--) {
            row[j] = row[j] + row[j-1];
        }
        row[i] = 1; // 行尾添加1
        
        // 打印当前行
        for(int j = 0; j <= i; j++) {
            printf("%4d", row[j]);
        }
        printf("\n");
    }
    
    return 0;
}

优点：只使用一维数组，节省空间
缺点：更新逻辑稍复杂

优化方案2：使用组合数公式（数学方法）
#include <stdio.h>

// 计算组合数C(n, k)
int combination(int n, int k) {
    if(k == 0 || k == n) return 1;
    
    long result = 1;
    // 使用C(n, k) = C(n, n-k)的性质减少计算量
    if(k > n - k) k = n - k;
    
    for(int i = 0; i < k; i++) {
        result = result * (n - i) / (i + 1);
    }
    
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 单独处理第一行
    for(int k = n-1; k > 0; k--)
        printf(" ");
    printf("   1\n");
    
    for(int i = 1; i < n; i++) {
        // 打印空格
        for(int k = n-1; k > i; k--)
            printf(" ");
        
        // 使用组合数公式计算杨辉三角的每个元素
        for(int j = 0; j <= i; j++) {
            printf("%4d", combination(i, j));
        }
        printf("\n");
    }
    
    return 0;
}

优点：直接计算每个元素，不需要存储整个三角形
缺点：组合数计算可能溢出，效率较低

优化方案3：使用递归（教学用途）
#include <stdio.h>

// 递归计算杨辉三角元素
int pascal(int row, int col) {
    if(col == 0 || col == row) {
        return 1;
    }
    return pascal(row - 1, col - 1) + pascal(row - 1, col);
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 单独处理第一行
    for(int k = n-1; k > 0; k--)
        printf(" ");
    printf("   1\n");
    
    for(int i = 1; i < n; i++) {
        // 打印空格
        for(int k = n-1; k > i; k--)
            printf(" ");
        
        // 使用递归计算每个元素
        for(int j = 0; j <= i; j++) {
            printf("%4d", pascal(i, j));
        }
        printf("\n");
    }
    
    return 0;
}

优点：代码直观，易于理解递归思想
缺点：效率极低，有大量重复计算
*/
