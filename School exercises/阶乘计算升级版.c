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
    
    // ����0!��1!�����
    if (N == 0 || N == 1) {
        printf("1");
        return;
    }
    
    int arr[3000] = {0};
    arr[0] = 1;
    int digits = 1; // ��¼��ǰ�����λ��
    
    for (int i = 2; i <= N; i++) {
        int carry = 0; // ��λ
        
        // ֻ���������ֵ�λ�������Ч��
        for (int j = 0; j < digits; j++) {
            int product = arr[j] * i + carry;
            arr[j] = product % 10;
            carry = product / 10;
        }
        
        // ����ʣ��Ľ�λ
        while (carry > 0) {
            arr[digits] = carry % 10;
            carry = carry / 10;
            digits++;
        }
    }
    
    // �����λ��ʼ���
    for (int i = digits - 1; i >= 0; i--) {
        printf("%d", arr[i]);
    }
}

/*
�Ż�����1��ʹ�ö�̬���飨�����ڲ�ȷ�����λ���������
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
    
    // �������Ĵ���λ����˹���ֹ�ʽ���ƣ�
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
            
            // �������Ԥ��λ�������·����ڴ�
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

�ŵ㣺�Զ���Ӧ��ͬ��С�Ľ׳˽��
ȱ�㣺��Ҫ��̬�ڴ�������븴��

�Ż�����2���ֶμ��㣨�����ڴ���ʣ�
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
        
        // �ֶδ���ÿ�δ����λ����
        for (int j = 0; j < digits; j += 4) {
            long long product = 0;
            
            // һ�δ���4λ����
            for (int k = 0; k < 4 && j + k < digits; k++) {
                product += (long long)arr[j + k] * i;
                if (k > 0) {
                    product *= 10;
                }
            }
            
            product += carry;
            
            // ������ֽ������
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

�ŵ㣺�����ڴ���ʴ�������߻���Ч��
ȱ�㣺�����߼�����

�Ż�����3��ʹ�ø���Ч�����ݽṹ
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

�ŵ㣺����ṹ������������չ
ȱ�㣺��Ҫ��������ݽṹ����
*/
