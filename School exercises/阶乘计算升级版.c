#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
    
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

void Print_Factorial(const int N) {
    if (N < 0) {
        printf("Invalid input");
        return; 
    }
    
    // 处理0!和1!的情况
    if (N == 0 || N == 1) {
        printf("1");
        return;
    }
    
    int arr[3000] = {0};
    arr[0] = 1;
    int digits = 1; // 记录当前结果的位数
    
    for (int i = 2; i <= N; i++) {
        int carry = 0; // 进位
        
        // 只遍历有数字的位数，提高效率
        for (int j = 0; j < digits; j++) {
            int product = arr[j] * i + carry;
            arr[j] = product % 10;
            carry = product / 10;
        }
        
        // 处理剩余的进位
        while (carry > 0) {
            arr[digits] = carry % 10;
            carry = carry / 10;
            digits++;
        }
    }
    
    // 从最高位开始输出
    for (int i = digits - 1; i >= 0; i--) {
        printf("%d", arr[i]);
    }
}

/*
优化方案1：使用动态数组（适用于不确定结果位数的情况）
#include <stdio.h>
#include <stdlib.h>

void Print_Factorial(const int N) {
    if (N < 0) {
        printf("Invalid input");
        return;
    }
    
    if (N == 0 || N == 1) {
        printf("1");
        return;
    }
    
    // 估算结果的大致位数（斯特林公式近似）
    int estimated_digits = (int)(N * log10(N / exp(1)) + log10(2 * M_PI * N) / 2) + 2;
    
    int *arr = (int*)calloc(estimated_digits, sizeof(int));
    arr[0] = 1;
    int digits = 1;
    
    for (int i = 2; i <= N; i++) {
        int carry = 0;
        
        for (int j = 0; j < digits; j++) {
            int product = arr[j] * i + carry;
            arr[j] = product % 10;
            carry = product / 10;
        }
        
        while (carry > 0) {
            arr[digits] = carry % 10;
            carry = carry / 10;
            digits++;
            
            // 如果超出预估位数，重新分配内存
            if (digits >= estimated_digits) {
                estimated_digits *= 2;
                arr = (int*)realloc(arr, estimated_digits * sizeof(int));
                for (int k = digits; k < estimated_digits; k++) {
                    arr[k] = 0;
                }
            }
        }
    }
    
    for (int i = digits - 1; i >= 0; i--) {
        printf("%d", arr[i]);
    }
    
    free(arr);
}

优点：自动适应不同大小的阶乘结果
缺点：需要动态内存管理，代码复杂

优化方案2：分段计算（减少内存访问）
#include <stdio.h>

void Print_Factorial(const int N) {
    if (N < 0) {
        printf("Invalid input");
        return;
    }
    
    if (N == 0 || N == 1) {
        printf("1");
        return;
    }
    
    int arr[3000] = {0};
    arr[0] = 1;
    int digits = 1;
    
    for (int i = 2; i <= N; i++) {
        int carry = 0;
        
        // 分段处理，每次处理多位数字
        for (int j = 0; j < digits; j += 4) {
            long long product = 0;
            
            // 一次处理4位数字
            for (int k = 0; k < 4 && j + k < digits; k++) {
                product += (long long)arr[j + k] * i;
                if (k > 0) {
                    product *= 10;
                }
            }
            
            product += carry;
            
            // 将结果分解回数组
            for (int k = 0; k < 4 && j + k < digits; k++) {
                arr[j + k] = product % 10;
                product /= 10;
            }
            
            carry = product;
        }
        
        while (carry > 0) {
            arr[digits] = carry % 10;
            carry = carry / 10;
            digits++;
        }
    }
    
    for (int i = digits - 1; i >= 0; i--) {
        printf("%d", arr[i]);
    }
}

优点：减少内存访问次数，提高缓存效率
缺点：代码逻辑复杂

优化方案3：使用更高效的数据结构
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *digits;
    int size;
    int capacity;
} BigNumber;

void initBigNumber(BigNumber *num, int value) {
    num->capacity = 100;
    num->digits = (int*)calloc(num->capacity, sizeof(int));
    num->size = 1;
    num->digits[0] = value;
}

void multiply(BigNumber *num, int factor) {
    int carry = 0;
    
    for (int i = 0; i < num->size; i++) {
        long long product = (long long)num->digits[i] * factor + carry;
        num->digits[i] = product % 10;
        carry = product / 10;
    }
    
    while (carry > 0) {
        if (num->size >= num->capacity) {
            num->capacity *= 2;
            num->digits = (int*)realloc(num->digits, num->capacity * sizeof(int));
            for (int i = num->size; i < num->capacity; i++) {
                num->digits[i] = 0;
            }
        }
        num->digits[num->size] = carry % 10;
        carry /= 10;
        num->size++;
    }
}

void Print_Factorial(const int N) {
    if (N < 0) {
        printf("Invalid input");
        return;
    }
    
    if (N == 0 || N == 1) {
        printf("1");
        return;
    }
    
    BigNumber result;
    initBigNumber(&result, 1);
    
    for (int i = 2; i <= N; i++) {
        multiply(&result, i);
    }
    
    for (int i = result.size - 1; i >= 0; i--) {
        printf("%d", result.digits[i]);
    }
    
    free(result.digits);
}

优点：代码结构清晰，易于扩展
缺点：需要额外的数据结构定义
*/
