/*˼·������
��ȡa1 b1 scanf("%d / %d", &a1, &b1)����ʽ�ַ�������Ӧ����"%d/%d %d/%d"��
��m�����������double���ͣ�����ȷ����Ҫע������ת���﷨��
a2, b2 ͬ�� ��n����������ȷ��
�Ƚ�m n����ȷ��
���m > n ��ֱ�Ӵ�ӡprintf("%d / %d > %d / %d",ʡ��)����ȷ��
���ģ��᲻����־���ʧЧ���޷��õ�Ԥ�ڽ��������ȷ��ʹ�ø������Ƚ�ȷʵ���ܴ��ھ������⣩*/

#include <stdio.h>

int main() {
    int a1, b1, a2, b2;
    // ԭ������룺
    // scanf("%d / %d %d / %d", &a1, &b1, &a2, &b2);
    // ����ԭ�򣺸�ʽ�ַ����еĿո��б��λ�ò���ȷ��Ӧ��ȥ������Ŀո�
    
    // ��ȷ���룺
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
    
    // ԭ������룺
    // double m = double(a1) / double(b1);
    // double m = double(a2) / double(b2);
    // ����ԭ��1. �ظ�����m 2. C����������ת���﷨��(double)a1������double(a1)
    
    // ��ȷ���룺
    double m = (double)a1 / (double)b1;
    double n = (double)a2 / (double)b2;
    
    if (m > n) {
        printf("%d/%d > %d/%d", a1, b1, a2, b2);
    } else if (m < n) {
        printf("%d/%d < %d/%d", a1, b1, a2, b2);
    } else {
        printf("%d/%d = %d/%d", a1, b1, a2, b2);
    }
    return 0;
}

/*
�Ż�����1��ʹ������������⸡�㾫������
#include <stdio.h>

int main() {
    int a1, b1, a2, b2;
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
    
    // ������˱Ƚϣ����⸡������������
    long long left = (long long)a1 * b2;
    long long right = (long long)a2 * b1;
    
    if (left > right) {
        printf("%d/%d > %d/%d", a1, b1, a2, b2);
    } else if (left < right) {
        printf("%d/%d < %d/%d", a1, b1, a2, b2);
    } else {
        printf("%d/%d = %d/%d", a1, b1, a2, b2);
    }
    return 0;
}

�ŵ㣺���⸡�����������⣬�����׼ȷ
ȱ�㣺�����������ʹ��long long���Ի���

�Ż�����2��ʹ�÷��������Ƚ�
#include <stdio.h>

// �����Լ��
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// �������
void simplify(int *a, int *b) {
    int g = gcd(*a, *b);
    *a /= g;
    *b /= g;
}

int main() {
    int a1, b1, a2, b2;
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
    
    // �������
    simplify(&a1, &b1);
    simplify(&a2, &b2);
    
    // ͨ�ֺ�ȽϷ���
    int left = a1 * b2;
    int right = a2 * b1;
    
    if (left > right) {
        printf("%d/%d > %d/%d", a1, b1, a2, b2);
    } else if (left < right) {
        printf("%d/%d < %d/%d", a1, b1, a2, b2);
    } else {
        printf("%d/%d = %d/%d", a1, b1, a2, b2);
    }
    return 0;
}

�ŵ㣺���������Ƚϸ�ֱ��
ȱ�㣺��Ҫ����Ļ�����

�Ż�����3��ʹ�þ�ȷ�����Ƚ�
#include <stdio.h>

int main() {
    int a1, b1, a2, b2;
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
    
    // ʹ�÷����Ƚϵľ�ȷ������a1/b1 - a2/b2 = (a1*b2 - a2*b1)/(b1*b2)
    // ���ڷ�ĸb1*b2����������ֻ��ȽϷ���
    int numerator = a1 * b2 - a2 * b1;
    
    if (numerator > 0) {
        printf("%d/%d > %d/%d", a1, b1, a2, b2);
    } else if (numerator < 0) {
        printf("%d/%d < %d/%d", a1, b1, a2, b2);
    } else {
        printf("%d/%d = %d/%d", a1, b1, a2, b2);
    }
    return 0;
}

�ŵ㣺��ѧ���ȷ���������о�������
ȱ�㣺��Ҫ�������Ƚϵ���ѧԭ��
*/
