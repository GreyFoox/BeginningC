#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    // ԭʼ���루�������ڶԱȣ�����ע���⣩
    /*
    int m, n;
    int flag = 1; 
    scanf("%d %d", &m, &n);
    for(int i = m; i <= n; i++) {
        int sum = 0;
        // ����1��ѭ����Χ����Ч�ʼ���
        // �߼�����j����ѭ����i���������Ϊi/2����i�������˴�ѭ����i����O(i)ʱ�临�Ӷ�
        for(int j = 1; j <= i; j++) {
            flag = 0;  // ����2��flag�߼�����ÿ��ѭ��������Ϊ0���޷���ȷ���"�Ƿ��������"
            // ����3�������ж���ȫ����
            // ��ȷ�߼���������������i������i%j == 0�����˴�д��Ϊi%j != 0��������i%j >= j������
            if(i % j != 0 && i % j >= j) {
                // ����4�����Ӻͼ������
                // ��ȷ�߼����ۼ�����j�����˴������ۼ�j + i%j���������޹ص���ֵ��
                sum += (j + i % j); 
                // ����5������߼�����
                // δ�ռ�ȫ���Ӿʹ�ӡ�̶���ʽ"1 + 2 + 3"����ʵ�������޹أ�����ǰ������¸�ʽ����
                printf("%d = 1 + 2 + 3", sum);
            }
        }
    }
    // ����6����flag���������ã��˴��ж�ʧЧ
    // �����Ƿ��ҵ�������flag������Ϊ0���޷���ȷ���"None"
    if(flag) {
        printf("None");
    } 
    */

    int m, n;
    bool has_perfect = false;  // ��ȷ����Ƿ��ҵ��������޸�flag�߼����⣩
    
    // ����Ϸ��Լ�飨����ԭʼ����ȱʧ��³���ԣ�
    if (scanf("%d %d", &m, &n) != 2 || m <= 1 || m > n || n > 10000) {
        printf("�������������1<m��n��10000��������\n");
        return 1;
    }

    // ���������Ż���ɶ����Ӳ��ҷ������ԭʼ����Ч�ʺ��߼����⣩
    for (int num = m; num <= n; num++) {
        int factor_sum = 1;                  // ��ʼ��������1�����С�2���������ӣ�
        int factors[100] = {1};              // �洢���ӣ���֤�������
        int factor_count = 1;                // �����������Ѻ�1��
        int sqrt_num = (int)sqrt(num);       // ��ǰ����ƽ�����������ظ��������ã��Ż�Ч�ʣ�

        // �������ӣ�ѭ����sqrt(num)���������ӳɶ��ԣ����ԭʼ����ѭ����Χ�������⣩
        for (int j = 2; j <= sqrt_num; j++) {
            if (num % j == 0) {  // ��ȷ�ж����ӣ��޸�ԭʼ���������жϴ���
                factors[factor_count++] = j;
                factor_sum += j;  // �ۼ����ӱ����޸�ԭʼ�����ۼӴ���

                int pair = num / j;
                if (pair != j) {  // �����ظ�������ӣ���4������2��
                    factors[factor_count++] = pair;
                    factor_sum += pair;
                }
            }
        }

        // ˫ָ�뷴ת������ӣ�ȷ����������������Ч�����Ż����ܣ�
        int left = 1, right = factor_count - 1;
        while (left < right) {
            int temp = factors[left];
            factors[left] = factors[right];
            factors[right] = temp;
            left++;
            right--;
        }

        // �����ж�����ȷ������޸�ԭʼ��������߼��������⣩
        if (factor_sum == num) {
            has_perfect = true;
            printf("%d = 1", num);
            for (int k = 1; k < factor_count; k++) {
                printf(" + %d", factors[k]);
            }
            printf("\n");
        }
    }

    // ���������Ԥ������֪�������������Ŀ��Χ�ļ����Ż���
    /*
    int known[] = {6, 28, 496, 8128};
    char* forms[] = {
        "6 = 1 + 2 + 3",
        "28 = 1 + 2 + 4 + 7 + 14",
        "496 = 1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248",
        "8128 = 1 + 2 + 4 + 8 + 16 + 32 + 64 + 127 + 254 + 508 + 1016 + 2032 + 4064"
    };
    for (int i = 0; i < 4; i++) {
        if (known[i] >= m && known[i] <= n) {
            printf("%s\n", forms[i]);
            has_perfect = true;
        }
    }
    */

    // ������ʱ���None���޸�ԭʼ����flag�жϴ���
    if (!has_perfect) {
        printf("None");
    }

    return 0;
}

