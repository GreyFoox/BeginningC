#include <stdio.h>

/* ԭʼ���루�������ע����
#include <stdio.h>

int main() {
    int n;                  // ����1�����������򵥣��ұ��޸ĺ�ԭʼֵ��ʧ
    int count = 0;          // ����2��"count"����ģ����δ����"�������"����
    scanf("%d", &n);        // ����3��δУ������Ϸ��ԣ�������/0/�����ᵼ���쳣��
    while(n != 1) {         // ����4��δ��ʽ����n=1�ı߽�������߼���ֱ��
        if( n % 2 == 0) {
            n = n / 2;
            count++;        // ����5����else��֧��count++�ظ������ڴ�������
        } else {
            n = (3 * n + 1) / 2;
            count++;        // ����5����if��֧��count++�ظ������ڴ�������
        }
    }
    printf("%d", count);    // ����6����������֣�ȱ�������ģ��û������
    return 0;               // ����7��ʹ��int�洢n���ܵ��´���ֵ���
}
*/

int main() {
    // �Ż�1����������������Ż����������1��2��7��
    int originalN;         // ����ԭʼ����ֵ�����޸�
    long long currentNum;  // ʹ��long long���ٴ���ֵ�������
    int stepCount = 0;     // ������ȷ������"�������"����

    // �Ż�2������У������ʾ���������3��
    printf("��������������");
    if (scanf("%d", &originalN) != 1 || originalN <= 0) {
        printf("���������������������\n");
        return 1;  // �Ƿ�����ʱ��ʱ�˳�
    }

    currentNum = originalN;  // ��currentNum������㣬����ԭʼֵ

    // �Ż�3����ʽ����߽�������������4��
    if (currentNum == 1) {
        printf("1�任��1��Ҫ0��\n");
        return 0;
    }

    // �Ż�4�������������ࣨ�������5��
    while (currentNum != 1) {
        if (currentNum % 2 == 0) {
            currentNum /= 2;
        } else {
            currentNum = (3 * currentNum + 1) / 2;  // �������ļ����߼�
        }
        stepCount++;  // �ϲ��ظ��ļ�������
    }

    // �Ż�5�������Ϣ�Ż����������6��
    printf("%d�任��1����Ҫ%d��\n", originalN, stepCount);

    return 0;
}

