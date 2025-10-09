#include <stdio.h>
#include <string.h>

// 纯C语言宏定义，用于取两个数的最大值
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int N, V;
    // 读取物品种数和背包容量
    scanf("%d%d", &N, &V);
    
    // 存储物品的体积和价值数组
    int v[1001], w[1001];
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &v[i], &w[i]);
    }
    
    // 主方法：最优解法 - 一维动态规划
    // 时间复杂度O(N*V)，空间复杂度O(V)
    int dp[1001] = {0};  // dp[j]表示容量为j的背包能获得的最大价值
    
    // 遍历每种物品
    for (int i = 0; i < N; i++) {
        // 正向遍历体积（完全背包的关键，允许物品重复使用）
        for (int j = v[i]; j <= V; j++) {
            // 状态转移：不选当前物品 vs 选当前物品（可多次选择）
            dp[j] = MAX(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    
    // 输出最大价值
    printf("%d\n", dp[V]);
    return 0;
}

/*
其他解法参考（均为纯C语言实现）：

// 方法2：二维动态规划解法
// 时间复杂度O(N*V)，空间复杂度O(N*V)
int solve_2d(int N, int V, int v[], int w[]) {
    // dp[i][j]表示前i种物品在容量j下的最大价值
    int dp[1001][1001] = {0};
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= V; j++) {
            // 不选第i种物品
            dp[i][j] = dp[i-1][j];
            
            // 选第i种物品（可多次选择）
            if (j >= v[i-1]) {
                // 与0-1背包的区别：使用dp[i][j-v[i-1]]而非dp[i-1][j-v[i-1]]
                dp[i][j] = MAX(dp[i][j], dp[i][j - v[i-1]] + w[i-1]);
            }
        }
    }
    return dp[N][V];
}

// 方法3：朴素解法（暴力枚举）
// 时间复杂度O(N*V2)，空间复杂度O(N*V)
// 仅适合小规模数据，大规模数据会超时
int solve_naive(int N, int V, int v[], int w[]) {
    int dp[1001][1001] = {0};
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= V; j++) {
            // 枚举第i种物品的使用数量k
            for (int k = 0; k * v[i-1] <= j; k++) {
                dp[i][j] = MAX(dp[i][j], dp[i-1][j - k*v[i-1]] + k*w[i-1]);
            }
        }
    }
    return dp[N][V];
}

三种方法对比：
1. 一维DP（主方法）：最优解法，时间和空间效率最高，适合实际应用
2. 二维DP：状态定义直观，易于理解，但空间占用较大
3. 朴素解法：实现逻辑简单，直接枚举所有可能，但时间复杂度高，仅用于理解原理
*/

