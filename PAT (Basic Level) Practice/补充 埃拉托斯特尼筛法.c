#include <stdio.h>

int main() {
    int n = 10000;  // 直接使用10000更清晰，避免1e4的类型转换
    int primes[n + 1];
    
    // 关键修正：初始化数组，0表示素数，1表示非素数
    for (int i = 0; i <= n; i++) {
        primes[i] = 0;  // 先假设所有数都是素数
    }
    
    // 0和1不是素数，手动标记
    primes[0] = 1;
    primes[1] = 1;
    
    // 筛法核心逻辑
    for (int i = 2; i <= n / i; i++) {  // i <= sqrt(n)的等价写法，避免溢出
        if (!primes[i]) {  // 如果i是素数，标记其倍数为非素数
            for (int j = i * i; j <= n; j += i) {  // 从i*i开始标记，减少重复操作
                primes[j] = 1;
            }
        }
    }
    
    // 输出所有素数（未被标记的数）
    for (int i = 2; i <= n; i++) {
        if (!primes[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
    
