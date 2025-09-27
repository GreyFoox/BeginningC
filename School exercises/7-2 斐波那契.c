/* 
斐波那契数列求模问题：优化方案（预处理DP）
问题描述：计算Fib(n) mod 100007，支持n≤2×10?和1e5组测试用例
核心改进：用迭代预处理替代递归，解决栈溢出问题
*/

#include <stdio.h>
#include <string.h>

#define MOD 100007
#define MAX_N 2000000

// 优化方案：存储预处理结果的数组（全局数据段，无栈限制）
int fib_dp[MAX_N + 1];

/* 
对比：记忆化递归的记忆数组（仅作注释对比）
int memo[MAX_N + 1];  // 同样是全局数组，但递归调用仍会栈溢出
*/

// 优化方案：迭代预处理函数（自底向上计算）
void precompute_dp() {
    fib_dp[0] = 0;
    fib_dp[1] = 1;
    // 用for循环迭代计算，无递归调用，彻底避免栈溢出
    for (int i = 2; i <= MAX_N; i++) {
        fib_dp[i] = (fib_dp[i - 1] + fib_dp[i - 2]) % MOD;
    }
}

/* 
对比：记忆化递归函数（仅作注释对比）
int fib_memo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (memo[n] != -1) return memo[n];
    
    // 问题根源：递归调用形成n层栈，n=2e6时栈溢出
    memo[n] = (fib_memo(n - 1) + fib_memo(n - 2)) % MOD;
    return memo[n];
}
*/

int main() {
    // 优化方案：初始化预处理（仅需一次）
    precompute_dp();
    
    /* 
    对比：记忆化递归的初始化（仅作注释对比）
    memset(memo, -1, sizeof(memo));
    memo[0] = 0;
    memo[1] = 1;
    */
    
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int n;
        scanf("%d", &n);
        
        // 优化方案：直接查询预处理结果（O(1)时间，无栈操作）
        printf("%d\n", fib_dp[n]);
        
        /* 
        对比：记忆化递归调用（仅作注释对比）
        printf("%d\n", fib_memo(n));  // n=2e6时会栈溢出
        */
    }
    
    return 0;
}


/* 
其他实现方法参考（对比用）
*/
// 方法2：迭代法（滚动数组，空间最优）
/*
int fib_iterative(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;  // 仅保存前两项，空间O(1)
    for (int i = 2; i <= n; i++) {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return b;
}
// 优点：空间O(1)；缺点：多组大n时总时间O(T*n)，效率低
*/

// 方法3：矩阵快速幂（O(log n)时间，适合超大n）
/*
typedef struct { long long m[2][2]; } Matrix;
void matrix_mult(Matrix *res, Matrix a, Matrix b) {
    Matrix temp;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            temp.m[i][j] = 0;
            for (int k = 0; k < 2; k++)
                temp.m[i][j] = (temp.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD;
        }
    *res = temp;
}
void matrix_pow(Matrix *res, Matrix mat, int power) {
    Matrix temp = {{1,0}, {0,1}};
    *res = temp;
    while (power > 0) {
        if (power % 2 == 1) matrix_mult(&temp, *res, mat), *res = temp;
        matrix_mult(&temp, mat, mat), mat = temp;
        power /= 2;
    }
}
int fib_matrix(int n) {
    if (n <= 1) return n;
    Matrix mat = {{1,1}, {1,0}}, res;
    matrix_pow(&res, mat, n-1);
    return res.m[0][0] % MOD;
}
// 优点：适合n>1e18；缺点：实现复杂，常数时间高
*/

// 方法4：快速倍增法（O(log n)时间，较简洁）
/*
void fast_doubling(int n, long long *a, long long *b) {
    if (n == 0) { *a = 0; *b = 1; return; }
    long long c, d;
    fast_doubling(n >> 1, &c, &d);
    long long cc = (c*c) % MOD, dd = (d*d) % MOD, cd2 = (2*c*d) % MOD;
    if (n & 1) { *a = (cc + dd) % MOD; *b = (cd2 + dd) % MOD; }
    else { *a = (cd2 + cc) % MOD; *b = (cc + dd) % MOD; }
}
int fib_fast(int n) { long long a, b; fast_doubling(n, &a, &b); return a % MOD; }
// 优点：效率高，实现较矩阵法简单；缺点：依赖数学公式
*/

