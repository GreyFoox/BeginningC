#include <stdio.h>

int main() {
    double eps;
    scanf("%le", &eps);
    
    // ԭʼ������ڵ����⣺�߼�������ǰreturn������������������ʼ������
    /*
    return 0;  // ��ǰ���ص��´��벻ִ��
    double sum = 1 + 1 / 3;  // ������������1/3=0
    double count = 1;
    while(count >= eps) { 
        int nu = 1;  // ѭ�����ظ���ʼ�����޷�����
        int de = 3;
        if((double)(nu / de) < eps) {
            break;
        }
        nu++;
        de += 3;
        count = (double)(nu / de);  // �����������¾��ȴ���
        sum += count; 
    }
    printf("%.5f", sum);
    */
    
    // �����Ż�1��ʹ�õ��ƹ�ʽ����ÿһ������ظ�����׳˺ͳ˻�
    // ��ʽ���ɣ���i�� = ��i-1�� �� i/(2i+1)��i��1��ʼ��
    double sum = 1.0;  // ��һ��Ϊ1.0��i=0ʱ��
    double term = 1.0; // ��ǰ���ʼֵ����һ�
    int i = 1;         // �ӵ�2�ʼ���㣨i=1��Ӧ�ڶ��
    
    // �߽�����������ǰ��term >= epsʱ�������ۼ�
    // ">=�е�'='������©��ȷ���պõ���eps���������ͣ����������һ�
    while (term >= eps) {
        // ���Ƽ�����һ���������׳˺ͳ��˻���ֱ����ǰһ���Ƶ�
        term = term * i / (2 * i + 1);  // ���������㣬��������������
        sum += term;
        i++;
    }
    
    double pi = 2 * sum;  // ���ݹ�ʽ2/�� = sum �� �� = 2*sum
    printf("PI = %.5f\n", pi);
    
    return 0;
}

