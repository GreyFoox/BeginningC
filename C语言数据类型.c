#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main() {
    printf("=== C语言数据类型范围分析（基于2的幂次方） ===\n\n");
    
    // 1. char类型 - 1字节 = 8位
    printf("1. char类型 (1字节 = 8位):\n");
    printf("   理论范围: -2^7 到 2^7-1 (%d 到 %d)\n", 
           (int)-pow(2, 7), (int)(pow(2, 7) - 1));
    printf("   实际范围: %d 到 %d\n\n", CHAR_MIN, CHAR_MAX);
    
    // 2. short类型 - 通常2字节 = 16位
    printf("2. short类型 (通常2字节 = 16位):\n");
    printf("   理论范围: -2^15 到 2^15-1 (%d 到 %d)\n", 
           (int)-pow(2, 15), (int)(pow(2, 15) - 1));
    printf("   实际范围: %d 到 %d\n\n", SHRT_MIN, SHRT_MAX);
    
    // 3. int类型 - 通常4字节 = 32位
    printf("3. int类型 (通常4字节 = 32位):\n");
    printf("   理论范围: -2^31 到 2^31-1 (%ld 到 %ld)\n", 
           (long)-pow(2, 31), (long)(pow(2, 31) - 1));
    printf("   实际范围: %d 到 %d\n\n", INT_MIN, INT_MAX);
    
    // 4. long类型 - 通常4或8字节
    printf("4. long类型 (通常4或8字节):\n");
    printf("   理论范围: -2^%d 到 2^%d-1\n", 
           (int)(8 * sizeof(long) - 1), (int)(8 * sizeof(long) - 1));
    printf("   实际范围: %ld 到 %ld\n\n", LONG_MIN, LONG_MAX);
    
    // 5. long long类型 - 通常8字节 = 64位
    printf("5. long long类型 (通常8字节 = 64位):\n");
    printf("   理论范围: -2^63 到 2^63-1 (%lld 到 %lld)\n", 
           (long long)-pow(2, 63), (long long)(pow(2, 63) - 1));
    printf("   实际范围: %lld 到 %lld\n\n", LLONG_MIN, LLONG_MAX);
    
    // 6. float类型 - 4字节 = 32位
    printf("6. float类型 (4字节 = 32位):\n");
    printf("   使用IEEE 754标准: 1位符号 + 8位指数 + 23位尾数\n");
    printf("   指数范围: 2^-126 到 2^127 (约 %.3e 到 %.3e)\n", 
           pow(2, -126), pow(2, 127));
    printf("   实际范围: %.3e 到 %.3e\n\n", FLT_MIN, FLT_MAX);
    
    // 7. double类型 - 8字节 = 64位
    printf("7. double类型 (8字节 = 64位):\n");
    printf("   使用IEEE 754标准: 1位符号 + 11位指数 + 52位尾数\n");
    printf("   指数范围: 2^-1022 到 2^1023 (约 %.3e 到 %.3e)\n", 
           pow(2, -1022), pow(2, 1023));
    printf("   实际范围: %.3e 到 %.3e\n\n", DBL_MIN, DBL_MAX);
    
    // 8. long double类型 - 通常10或16字节
    printf("8. long double类型 (通常10或16字节):\n");
    printf("   大小: %zu 字节\n", sizeof(long double));
    printf("   实际范围: %.3Le 到 %.3Le\n\n", LDBL_MIN, LDBL_MAX);
    
    // 9. 数据类型范围比较
    printf("9. 数据类型范围比较:\n");
    printf("   char (8位):        ±2^7 = ±128\n");
    printf("   short (16位):      ±2^15 = ±32,768\n");
    printf("   int (32位):        ±2^31 = ±2,147,483,648\n");
    printf("   long (通常32/64位): ±2^31 或 ±2^63\n");
    printf("   long long (64位):   ±2^63 = ±9,223,372,036,854,775,808\n");
    printf("   float (32位):      最大约 2^127 ≈ 1.7e+38\n");
    printf("   double (64位):     最大约 2^1023 ≈ 8.9e+307\n");
    printf("   long double:       最大约 2^16383 ≈ 1.2e+4932 (80位实现)\n");
    printf("\n注意: float和double使用科学计数法，可以表示更大范围但精度有限\n");
    
    // 10. 格式化输出示例
    printf("\n10. 格式化输出示例:\n");
    long long ll = 9223372036854775807LL; // long long最大值
    printf("   long long值: %lld\n", ll);
    printf("   long long十六进制: 0x%llx\n", ll);
    
    return 0;
}
