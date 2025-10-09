#include <stdio.h>
#include <limits.h>

int main() {
    // ԭʼ���루�������ڶԱȣ�
    /*
    double sum = 1.0;
    double term = 1.0;
    int n;
    scanf("%d", n);  // ����1��ȱ��&���޷���ȡ����
    for(int i = 1; i <= n; i++) {
        term *= i;
        sum += 1 / term;  // ����2�������������¾��ȶ�ʧ
    }
    printf(".8f", sum);  // ����3����ʽ��ȱ��%���������
    return 0;
    */

    double sum = 1.0;       // ��ʼֵ��1����Ӧ1/0!��
    double term = 1.0;      // �洢�׳�ֵ��i!������ʼΪ1��0! = 1��
    int n;
    int input_result;       // ���ڼ������Ϸ���

    // 1. �߼��빦����ȷ���޸�
    // �޸�ԭʼ�������1�����&ȡ��ַ����ȷ��������ȷ��ȡ
    input_result = scanf("%d", &n);

    // 5. ³������ǿ��������Ч����
    if (input_result != 1) {  // ����������
        printf("ERROR");
        return 1;
    }
    if (n < 0) {  // �׳��޸������壬�߽紦��
        printf("ERROR");
        return 1;
    }

    // 2. �����Ż�����ǰ��ֹѭ������term����ʱ��1/term�Խ����Ӱ�죩
    // ԭ��double��Ч����Լ15-17λ����term > 1e16ʱ��1/term < 1e-16����Ӱ��8λС�����
    const double MIN_EFFECT = 1e-16;  // ��С��Ч��ֵ
    for (int i = 1; i <= n; i++) {
        term *= i;  // ��������i!�������ظ����㣬ʱ�临�Ӷ�O(n)��

        // ��ǰ�˳���������1/termС����ֵʱ���ۼ�������
        if (term > 1.0 / MIN_EFFECT) {
            break;
        }

        // �޸�ԭʼ�������2����1.0ȷ��������������������ض�
        sum += 1.0 / term;
    }

    // �޸�ԭʼ�������3�����%����ȷָ��8λС����ʽ
    printf("%.8f\n", sum);

    return 0;
}

