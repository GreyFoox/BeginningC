/* ԭʼ���루�������ע��
#include <stdio.h>

int main() {
    int t;
    int n;
    scanf("%d", &t);
    int arr[t];  // ����1��ʹ��VLA���ɱ䳤�����飩�������Բ����������洢
    for(int i = 0; i < t; i++) {
        // ����2������scanf����ֵ������ɹ��ĸ������������飬����ʵ�������nֵ
        arr[i] = scanf("%d", &n);  
    }
    for(int i = 0; i < t; i++) {
        // ����3���ж��߼�����ʵ���жϵ���scanf����ֵ����ż�ԣ���n�޹�
        if (arr[i] % 2 == 0) {  
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}
*/

// �Ż������
#include <stdio.h>

// �ж�һ�����Ƿ�Ϊ"ֻ����"��������������Ϊ������
// ԭ��Ψһ��ż������2�����ֻ���ж����Ƿ�Ϊ����
int is_only_odd(long long num) {
    return (num % 2 != 0);
}

int main() {
    int t;
    // ����Ϸ��Լ�飺ȷ��������������Ч��Χ���޸�ԭʼ�����޼�����⣩
    if (scanf("%d", &t) != 1 || t < 1 || t > 9) {
        printf("���󣺲�������������1-9������\n");
        return 1;
    }

    for (int i = 0; i < t; i++) {
        long long n;  // ʹ��long long���ͣ�֧��1e18��Χ���޸�ԭʼ����int���Ͳ������⣩
        // ����Ϸ��Լ�飺ȷ��n�ǡ�2��������������ĿԼ����
        if (scanf("%lld", &n) != 1 || n < 2) {
            printf("���󣺵�%d�����ݱ����ǡ�2������\n", i + 1);
            return 1;
        }

        // �����ж��߼����޸�ԭʼ�����ж��߼�����
        if (is_only_odd(n)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
