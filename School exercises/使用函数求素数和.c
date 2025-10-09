#include <stdio.h>
#include <stdlib.h>

int prime(int p);
int PrimeSum(int m, int n);
    
int main()
{
    int m, n, p;
    int sum = 0;
    int firstPrint = 1;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    
    // 原始代码（两次遍历+重复判断）：
    // for( p=m; p<=n; p++ ) {
    //     if( prime(p) != 0 )
    //         printf("%d ", p);
    // }
    // printf(") = %d\n", PrimeSum(m, n));
    
    // 优化：一次遍历完成打印和求和，减少函数调用（空间复杂度O(1)）
    int start = (m < 2) ? 2 : m;  // 跳过小于2的非素数，减少无效判断
    for (p = start; p <= n; p++) {  // "<="中的"="不可遗漏
        // 原因：若n是素数，需包含在结果中（端点值必须处理）
        int isPrime = prime(p);
        if (isPrime) {
            // 优化输出格式，消除尾部空格
            printf(firstPrint ? "%d" : " %d", p);
            firstPrint = 0;
            sum += p;  // 合并求和，避免二次循环
        }
    }
    
    // 备选方案：埃氏筛法（时间优化，空间复杂度O(n)）
    /*
    if (m < 2) m = 2;
    int *isPrime = (int*)calloc(n + 1, sizeof(int));
    for (int i = 2; i * i <= n; i++) {  // "<="中的"="不可遗漏
        if (!isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 1;
            }
        }
    }
    for (p = m; p <= n; p++) {
        if (!isPrime[p]) {
            printf(firstPrint ? "%d" : " %d", p);
            firstPrint = 0;
            sum += p;
        }
    }
    free(isPrime);
    */
    
    printf(") = %d\n", sum);
    return 0;
}

int prime(int p) {
    // 原始代码：
    // if(p <= 1) return 0;
    // if(p == 2 || p ==3 ) { return 1; }
    // if(p % 6 != 1 && p % 6 != 5){ return 0; }
    // for(int i = 5; i * i <= p; i+=6) {
    //     if (p % i == 0 || p % (i + 2) == 0) { return 0; } 
    // }
    // return 1;
    
    // 优化：精简判断逻辑，保持O(1)空间
    if (p <= 1) return 0;  // "<="中的"="不可遗漏
    // 原因：1是素数定义的边界（素数需>1），必须包含p=1的情况
    if (p <= 3) return 1;  // 合并2、3的判断，减少分支
    if (p % 2 == 0 || p % 3 == 0) return 0;  // 提前过滤2、3的倍数
    // 核心优化：使用 i <= p/i 替代 i <= sqrt (p)
	// 优点 1：避免调用数学库函数 sqrt，减少函数调用开销（库函数调用涉及上下文切换）
	// 优点 2：规避浮点运算误差（sqrt 返回 double 类型，可能因精度问题导致边界判断错误）
	// 优点 3：整数运算效率更高（p/i 是整数除法，比浮点计算更快）
	// 等价性证明：i <= sqrt (p) 两边平方（i 和 p 均为正整数）→ ii <= p → i <= p/i（因 ii <= p → i <= p/i）
    // 优化：用p/i替代i*i，避免整数溢出且减少乘法运算
    for (int i = 5; i <= p / i; i += 6) {  // "<="中的"="不可遗漏
        // 原因：当i == p/i时，i*i == p，说明p有因子i，需判定为非素数
        if (p % i == 0 || p % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

int PrimeSum(int m, int n) {
    // 原始代码求和逻辑，优化后已合并到main函数，此处仅保留兼容
    int sum = 0;
    for (int i = m; i <= n; i++) {  // "<="中的"="不可遗漏
        if (prime(i)) sum += i;
    }
    return sum;
}

/*
===== 原代码未使用的算法原理介绍 =====
1. 埃氏筛法（Sieve of Eratosthenes）：
   - 原理：通过标记素数的倍数筛选素数。先假设所有数为素数，再从2开始，将其倍数标记为非素数，最终未被标记的即为素数。
   - 优势：时间效率高（O(n log log n)），适合大区间批量判断。
   - 劣势：需要O(n)空间存储标记数组，n过大时内存占用高。

2. 试除法优化（本代码使用）：
   - 原理：基于"素数必为6k±1"规则（除2、3外），仅判断可能为素数的数，减少循环次数。
   - 优势：空间复杂度O(1)，适合内存受限场景。
   - 劣势：对每个数单独判断，大区间效率低于埃氏筛。
*/

