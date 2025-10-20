/*˼·������
N sancf
���� �������� �������� ֧�� -> ʹ�ýṹ������ -> scanf����ȡ���� 
�������� < 10 
������� ������
����õ����չ��� .2f ��˼·��ȷ�������������ʽ��Ҫ������*/

#include <stdio.h>

typedef struct {
    char name[10];
    float bs;
    float fs;
    float output;
} Employee;

int main() {
    int n;
    scanf("%d", &n);
    Employee employee[n];
    
    // ԭ������룺
    // for(int i = 0; i < n; i++) {
    //     scanf("%c %lf % lf %lf", employee[i].name, employee[i].bs, employee[i].fs, employee[i].output);
    // }
    // ����ԭ��
    // 1. %cӦ�ø�Ϊ%s����ȡ�ַ���
    // 2. %lf����double���ͣ����ṹ������float��Ӧ����%f
    // 3. ��ʽ�ַ����еĿո�λ�ô���
    // 4. scanf������Ҫ���ݱ����ĵ�ַ
    
    // ��ȷ���룺
    for(int i = 0; i < n; i++) {
        scanf("%s %f %f %f", 
              employee[i].name, 
              &employee[i].bs, 
              &employee[i].fs, 
              &employee[i].output);
    }
    
    // ԭ������룺
    // for(int i = 0; i < n; i++) {
    //     printf("%c %lf\n",employee[i].name, employee[i].bs + employee[i].fs - employee[i].output);
    // }
    // ����ԭ��
    // 1. %cӦ�ø�Ϊ%s����ַ���
    // 2. %lfӦ�ø�Ϊ%.2f��������λС��
    
    // ��ȷ���룺
    for(int i = 0; i < n; i++) {
        float salary = employee[i].bs + employee[i].fs - employee[i].output;
        printf("%s %.2f\n", employee[i].name, salary);
    }
    
    return 0;
}

/*
�Ż�����1��ʹ�ö�̬�ڴ����
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    float bs;
    float fs;
    float output;
} Employee;

int main() {
    int n;
    scanf("%d", &n);
    
    // ��̬�����ڴ�
    Employee *employee = (Employee*)malloc(n * sizeof(Employee));
    if(employee == NULL) {
        printf("�ڴ����ʧ��\n");
        return 1;
    }
    
    for(int i = 0; i < n; i++) {
        scanf("%s %f %f %f", 
              employee[i].name, 
              &employee[i].bs, 
              &employee[i].fs, 
              &employee[i].output);
    }
    
    for(int i = 0; i < n; i++) {
        float salary = employee[i].bs + employee[i].fs - employee[i].output;
        printf("%s %.2f\n", employee[i].name, salary);
    }
    
    free(employee);
    return 0;
}

�ŵ㣺���Դ�������������������ջ�ռ�����
ȱ�㣺��Ҫ�ֶ������ڴ�

�Ż�����2��ʹ��ָ�����
#include <stdio.h>

typedef struct {
    char name[10];
    float bs;
    float fs;
    float output;
} Employee;

int main() {
    int n;
    scanf("%d", &n);
    Employee employee[n];
    
    // ʹ��ָ������
    Employee *ptr = employee;
    for(int i = 0; i < n; i++) {
        scanf("%s %f %f %f", 
              ptr->name, 
              &ptr->bs, 
              &ptr->fs, 
              &ptr->output);
        ptr++;
    }
    
    // ʹ��ָ�����
    ptr = employee;  // ����ָ��
    for(int i = 0; i < n; i++) {
        float salary = ptr->bs + ptr->fs - ptr->output;
        printf("%s %.2f\n", ptr->name, salary);
        ptr++;
    }
    
    return 0;
}

�ŵ㣺ʹ��ָ��������������Ч
ȱ�㣺��Ҫ���ָ������

�Ż�����3�����������֤
#include <stdio.h>

typedef struct {
    char name[10];
    float bs;
    float fs;
    float output;
} Employee;

int main() {
    int n;
    if(scanf("%d", &n) != 1 || n <= 0) {
        printf("�������\n");
        return 1;
    }
    
    Employee employee[n];
    
    for(int i = 0; i < n; i++) {
        if(scanf("%9s %f %f %f", 
                 employee[i].name, 
                 &employee[i].bs, 
                 &employee[i].fs, 
                 &employee[i].output) != 4) {
            printf("�����ʽ����\n");
            return 1;
        }
    }
    
    for(int i = 0; i < n; i++) {
        float salary = employee[i].bs + employee[i].fs - employee[i].output;
        printf("%s %.2f\n", employee[i].name, salary);
    }
    
    return 0;
}

�ŵ㣺��׳��ǿ���ܴ����쳣����
ȱ�㣺�����Գ�
*/
