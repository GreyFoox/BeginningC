#include <stdio.h>

int MonthDays(int year, int month);

int main()
{
    // ԭʼ���룺��������������
    // int ndays, month, year;
    int year;  // �Ż���ֻ������Ҫ��year��������������

    scanf("%d", &year);
    // ԭʼ���룺ѭ������month���ⲿ���壬ʹ��ndays��ת���
    // for(month = 1; month <= 12; month++){
    //     ndays = MonthDays(year, month);
    //     printf("%d ", ndays);
    // }
    // �Ż���ѭ��������ѭ���ڶ��壨��С�����򣩣�ֱ�Ӵ�ӡ����������м������
    for(int month = 1; month <= 12; month++){
        printf("%d ", MonthDays(year, month));
    }

    return 0;
}

int MonthDays(int year, int month) {
    // ԭʼ���룺ʹ��flag��Ϊ��Ǳ���
    // int flag = 0;
    int is_leap = 0;  // �Ż��󣺱�������Ϊis_leap���������ȷ

    // ԭʼ���룺�����ж��߼����߼����䣩
    // if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
    //     flag = 1;
    // }
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        is_leap = 1;  // �Ż��󣺱�������Ӧ�޸�
    }

    // ԭʼ���룺���������߶��ظ������飨ƽ������꣩
    // int arr1[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // if(flag) {
    //     int arr2[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //     return arr2[month];
    // }
    // return arr1[month];
    // �Ż�����һ����̬������������������飨�������ࣩ
    static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // �Ż������������ʽ���߼������if-return�ṹ��
    return (is_leap && month == 2) ? 29 : days[month];
}
    
