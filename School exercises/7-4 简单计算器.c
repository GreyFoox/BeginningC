#include <stdio.h>
#include <stdlib.h>

int main() {
    // ԭʼ������ڵ����⣺
    // 1. δ��ȡ��ʼ��������sum��ʼ��Ϊ0������
    // 2. δ�����λ����������"123"�޷���ȷʶ��
    // 3. ȱ��������Ϸ��Լ��ͳ�����ĸΪ0���ж�
    // 4. sum += ���޾����߼���switch��֧δʵ������
    /*
    char c;
    int sum = 0;
    
    while((c = getchar()) != '=') {
        sum += 
        switch(c) {
            case '+' :
                //���Ϻ�һ���� 
            case '-' :
                //��ȥ��һ���� 
            case '*' :
                //���Ϻ�һ���� 
            case '/' :
                //����һ���� 
        }
    }
    return 0;
    */

    int sum;          // �洢������
    char op;          // �洢�����
    int next_num;     // �洢��һ��������

    // ����1����ȡ��һ����������������ڣ�����Ϊ����
    // �����Ż�����scanfֱ�Ӷ�ȡ�����������ֶ�������λ���Ŀ���
    if (scanf("%d", &sum) != 1) {
        printf("ERROR");  // ����Ч���������������
        return 0;
    }

    // ����2��ѭ����ȡ���������һ����������ֱ������'='
    while (scanf("%c", &op) == 1) {  // ��ȡ�����
        if (op == '=') {  // �����Ⱥţ��������
            printf("%d", sum);
            return 0;
        }

        // �߽���1���ж�������Ƿ�Ϸ���ֻ����+-*/��
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            printf("ERROR");
            return 0;
        }

        // ����3����ȡ��һ������������������������Ч���֣�
        if (scanf("%d", &next_num) != 1) {
            printf("ERROR");  // ����Ч���������������
            return 0;
        }

        // ����4�����������ִ����Ӧ���㣨�����ң����ȼ���ͬ��
        switch (op) {
            case '+':
                sum += next_num;
                break;
            case '-':
                sum -= next_num;
                break;
            case '*':
                sum *= next_num;
                break;
            case '/':
                // �߽���2��������ĸ����Ϊ0
                if (next_num == 0) {
                    printf("ERROR");
                    return 0;
                }
                sum /= next_num;  // �����������ضϴ���
                break;
        }
    }

    // ��ѭ��������δ����'='�����������ʽ����
    printf("ERROR");
    return 0;
}

