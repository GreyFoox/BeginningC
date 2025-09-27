#include <stdio.h>

int main() {
    int n = 10000;  // ֱ��ʹ��10000������������1e4������ת��
    int primes[n + 1];
    
    // �ؼ���������ʼ�����飬0��ʾ������1��ʾ������
    for (int i = 0; i <= n; i++) {
        primes[i] = 0;  // �ȼ�����������������
    }
    
    // 0��1�����������ֶ����
    primes[0] = 1;
    primes[1] = 1;
    
    // ɸ�������߼�
    for (int i = 2; i <= n / i; i++) {  // i <= sqrt(n)�ĵȼ�д�����������
        if (!primes[i]) {  // ���i������������䱶��Ϊ������
            for (int j = i * i; j <= n; j += i) {  // ��i*i��ʼ��ǣ������ظ�����
                primes[j] = 1;
            }
        }
    }
    
    // �������������δ����ǵ�����
    for (int i = 2; i <= n; i++) {
        if (!primes[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
    
