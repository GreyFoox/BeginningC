#include <stdio.h>

int main() {
    int n;
    // ԭʼ���루�������ڶԱȣ�
    /*
    scanf("%d", &n);
    char c = 'A' - 1;
    int count = -1;
    while( n!= 0) {
        for(int i = 1; i <= n; i++) {
            count ++;
            c = 'A' + count;  // ���⣺count����25ʱ��Z�����������A-Z�ַ�
            printf("%c ", c);
        }
        if( n!= 1) {
            printf("\n");
        }
        n--;
    }
    */

    // ��ȡ���벢���Ϸ��ԣ�³�����Ż���
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("ERROR: ������Ǹ�����\n");
        return 1;
    }

    int count = 0;  // �Ż�����0��ʼ��������ֱ��
    while (n > 0) {  // ��n>0���n!=0���߼�������
        for (int i = 1; i <= n; i++) {
            // �����Ż���ͨ��%26ʵ��ѭ����0-25��ӦA-Z��26��0��A��27��1��B...��
            // ԭ��A-Z��ASCII���Ϊ25��'A'=65, 'Z'=90����ģ26ȷ��ʼ����0-25��Χ��
            char c = 'A' + (count % 26);
            printf("%c ", c);
            count++;  // �������ƣ����������������߼���
        }
        // ����n>1ʱ���У��������һ�ж��໻�У�
        if (n > 1) {
            printf("\n");
        }
        n--;
    }

    return 0;
}

