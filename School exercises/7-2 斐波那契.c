/* 
쳲�����������ģ���⣺�Ż�������Ԥ����DP��
��������������Fib(n) mod 100007��֧��n��2��10?��1e5���������
���ĸĽ����õ���Ԥ��������ݹ飬���ջ�������
*/

#include <stdio.h>
#include <string.h>

#define MOD 100007
#define MAX_N 2000000

// �Ż��������洢Ԥ�����������飨ȫ�����ݶΣ���ջ���ƣ�
int fib_dp[MAX_N + 1];

/* 
�Աȣ����仯�ݹ�ļ������飨����ע�ͶԱȣ�
int memo[MAX_N + 1];  // ͬ����ȫ�����飬���ݹ�����Ի�ջ���
*/

// �Ż�����������Ԥ���������Ե����ϼ��㣩
void precompute_dp() {
    fib_dp[0] = 0;
    fib_dp[1] = 1;
    // ��forѭ���������㣬�޵ݹ���ã����ױ���ջ���
    for (int i = 2; i <= MAX_N; i++) {
        fib_dp[i] = (fib_dp[i - 1] + fib_dp[i - 2]) % MOD;
    }
}

/* 
�Աȣ����仯�ݹ麯��������ע�ͶԱȣ�
int fib_memo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (memo[n] != -1) return memo[n];
    
    // �����Դ���ݹ�����γ�n��ջ��n=2e6ʱջ���
    memo[n] = (fib_memo(n - 1) + fib_memo(n - 2)) % MOD;
    return memo[n];
}
*/

int main() {
    // �Ż���������ʼ��Ԥ��������һ�Σ�
    precompute_dp();
    
    /* 
    �Աȣ����仯�ݹ�ĳ�ʼ��������ע�ͶԱȣ�
    memset(memo, -1, sizeof(memo));
    memo[0] = 0;
    memo[1] = 1;
    */
    
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int n;
        scanf("%d", &n);
        
        // �Ż�������ֱ�Ӳ�ѯԤ��������O(1)ʱ�䣬��ջ������
        printf("%d\n", fib_dp[n]);
        
        /* 
        �Աȣ����仯�ݹ���ã�����ע�ͶԱȣ�
        printf("%d\n", fib_memo(n));  // n=2e6ʱ��ջ���
        */
    }
    
    return 0;
}


/* 
����ʵ�ַ����ο����Ա��ã�
*/
// ����2�����������������飬�ռ����ţ�
/*
int fib_iterative(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;  // ������ǰ����ռ�O(1)
    for (int i = 2; i <= n; i++) {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return b;
}
// �ŵ㣺�ռ�O(1)��ȱ�㣺�����nʱ��ʱ��O(T*n)��Ч�ʵ�
*/

// ����3����������ݣ�O(log n)ʱ�䣬�ʺϳ���n��
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
// �ŵ㣺�ʺ�n>1e18��ȱ�㣺ʵ�ָ��ӣ�����ʱ���
*/

// ����4�����ٱ�������O(log n)ʱ�䣬�ϼ�ࣩ
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
// �ŵ㣺Ч�ʸߣ�ʵ�ֽϾ��󷨼򵥣�ȱ�㣺������ѧ��ʽ
*/

