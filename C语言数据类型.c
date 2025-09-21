#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main() {
    printf("=== C�����������ͷ�Χ����������2���ݴη��� ===\n\n");
    
    // 1. char���� - 1�ֽ� = 8λ
    printf("1. char���� (1�ֽ� = 8λ):\n");
    printf("   ���۷�Χ: -2^7 �� 2^7-1 (%d �� %d)\n", 
           (int)-pow(2, 7), (int)(pow(2, 7) - 1));
    printf("   ʵ�ʷ�Χ: %d �� %d\n\n", CHAR_MIN, CHAR_MAX);
    
    // 2. short���� - ͨ��2�ֽ� = 16λ
    printf("2. short���� (ͨ��2�ֽ� = 16λ):\n");
    printf("   ���۷�Χ: -2^15 �� 2^15-1 (%d �� %d)\n", 
           (int)-pow(2, 15), (int)(pow(2, 15) - 1));
    printf("   ʵ�ʷ�Χ: %d �� %d\n\n", SHRT_MIN, SHRT_MAX);
    
    // 3. int���� - ͨ��4�ֽ� = 32λ
    printf("3. int���� (ͨ��4�ֽ� = 32λ):\n");
    printf("   ���۷�Χ: -2^31 �� 2^31-1 (%ld �� %ld)\n", 
           (long)-pow(2, 31), (long)(pow(2, 31) - 1));
    printf("   ʵ�ʷ�Χ: %d �� %d\n\n", INT_MIN, INT_MAX);
    
    // 4. long���� - ͨ��4��8�ֽ�
    printf("4. long���� (ͨ��4��8�ֽ�):\n");
    printf("   ���۷�Χ: -2^%d �� 2^%d-1\n", 
           (int)(8 * sizeof(long) - 1), (int)(8 * sizeof(long) - 1));
    printf("   ʵ�ʷ�Χ: %ld �� %ld\n\n", LONG_MIN, LONG_MAX);
    
    // 5. long long���� - ͨ��8�ֽ� = 64λ
    printf("5. long long���� (ͨ��8�ֽ� = 64λ):\n");
    printf("   ���۷�Χ: -2^63 �� 2^63-1 (%lld �� %lld)\n", 
           (long long)-pow(2, 63), (long long)(pow(2, 63) - 1));
    printf("   ʵ�ʷ�Χ: %lld �� %lld\n\n", LLONG_MIN, LLONG_MAX);
    
    // 6. float���� - 4�ֽ� = 32λ
    printf("6. float���� (4�ֽ� = 32λ):\n");
    printf("   ʹ��IEEE 754��׼: 1λ���� + 8λָ�� + 23λβ��\n");
    printf("   ָ����Χ: 2^-126 �� 2^127 (Լ %.3e �� %.3e)\n", 
           pow(2, -126), pow(2, 127));
    printf("   ʵ�ʷ�Χ: %.3e �� %.3e\n\n", FLT_MIN, FLT_MAX);
    
    // 7. double���� - 8�ֽ� = 64λ
    printf("7. double���� (8�ֽ� = 64λ):\n");
    printf("   ʹ��IEEE 754��׼: 1λ���� + 11λָ�� + 52λβ��\n");
    printf("   ָ����Χ: 2^-1022 �� 2^1023 (Լ %.3e �� %.3e)\n", 
           pow(2, -1022), pow(2, 1023));
    printf("   ʵ�ʷ�Χ: %.3e �� %.3e\n\n", DBL_MIN, DBL_MAX);
    
    // 8. long double���� - ͨ��10��16�ֽ�
    printf("8. long double���� (ͨ��10��16�ֽ�):\n");
    printf("   ��С: %zu �ֽ�\n", sizeof(long double));
    printf("   ʵ�ʷ�Χ: %.3Le �� %.3Le\n\n", LDBL_MIN, LDBL_MAX);
    
    // 9. �������ͷ�Χ�Ƚ�
    printf("9. �������ͷ�Χ�Ƚ�:\n");
    printf("   char (8λ):        ��2^7 = ��128\n");
    printf("   short (16λ):      ��2^15 = ��32,768\n");
    printf("   int (32λ):        ��2^31 = ��2,147,483,648\n");
    printf("   long (ͨ��32/64λ): ��2^31 �� ��2^63\n");
    printf("   long long (64λ):   ��2^63 = ��9,223,372,036,854,775,808\n");
    printf("   float (32λ):      ���Լ 2^127 �� 1.7e+38\n");
    printf("   double (64λ):     ���Լ 2^1023 �� 8.9e+307\n");
    printf("   long double:       ���Լ 2^16383 �� 1.2e+4932 (80λʵ��)\n");
    printf("\nע��: float��doubleʹ�ÿ�ѧ�����������Ա�ʾ����Χ����������\n");
    
    // 10. ��ʽ�����ʾ��
    printf("\n10. ��ʽ�����ʾ��:\n");
    long long ll = 9223372036854775807LL; // long long���ֵ
    printf("   long longֵ: %lld\n", ll);
    printf("   long longʮ������: 0x%llx\n", ll);
    
    return 0;
}
