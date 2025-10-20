/*˼·������
n -> scanf
�������ڼ���ָ������� char* arr = (char*) malloc(n * 9 * sizeof(char)) -> �����������
�ƺ���һ�������1
����n ->��� -1
С��n -> дfind������˼·������ȷ����ʵ�ַ�ʽ����Ӧ��ʹ��ָ������洢�������ƣ�*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    // ԭ������룺
    // char* arr = (char*) malloc(n * 9 * sizeof(char));
    // char* ptr = arr;
    // char date[9];
    // while(ptr < arr + n) {
    //     scanf("%s", &date);
    //     *ptr++ = date;
    // }
    // ����ԭ��
    // 1. ������ڴ�ʹ�÷�ʽ����Ӧ���Ǵ洢�ַ���ָ��������ַ�
    // 2. *ptr++ = date ��ͼ�������ַ�����ַ������Ͳ�ƥ��
    // 3. û����ȷ�洢������ַ���
    
    // ��ȷ���룺
    // �����������Ƶ�ָ������
    char *weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    // ����repeat�β�ѯ
    for(int i = 0; i < n; i++) {
        char input[10];
        scanf("%s", input);
        
        int found = -1;
        // �����������в��������ַ���
        for(int j = 0; j < 7; j++) {
            if(strcmp(input, weekdays[j]) == 0) {
                found = j + 1;  // ��Ŵ�1��ʼ
                break;
            }
        }
        printf("%d\n", found);
    }
    
    return 0;
}

/*
�Ż�����1��ʹ�ú�����װ�����߼�
#include <stdio.h>
#include <string.h>

// ���Һ���
int findWeekday(char *day) {
    char *weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    for(int i = 0; i < 7; i++) {
        if(strcmp(day, weekdays[i]) == 0) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        char input[10];
        scanf("%s", input);
        printf("%d\n", findWeekday(input));
    }
    
    return 0;
}

�ŵ㣺����ṹ�����������߼�����������ά��
ȱ�㣺����������һ������
���÷�Χ����Ҫ����ɶ��ԺͿ�ά���Ե���Ŀ

�Ż�����2��ʹ�ù�ϣ����ٲ���
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// �򵥵��ַ�����ϣ����
unsigned int hash(char *str) {
    unsigned int hash = 0;
    while(*str) {
        hash = (hash * 31) + *str;
        str++;
    }
    return hash;
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Ԥ�����������ƵĹ�ϣֵ
    char *weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    unsigned int hashes[7];
    for(int i = 0; i < 7; i++) {
        hashes[i] = hash(weekdays[i]);
    }
    
    for(int i = 0; i < n; i++) {
        char input[10];
        scanf("%s", input);
        unsigned int inputHash = hash(input);
        
        int found = -1;
        for(int j = 0; j < 7; j++) {
            if(inputHash == hashes[j] && strcmp(input, weekdays[j]) == 0) {
                found = j + 1;
                break;
            }
        }
        printf("%d\n", found);
    }
    
    return 0;
}

�ŵ㣺���ڴ�����ѯ����ϣ�Ƚϱ��ַ����Ƚϸ���
ȱ�㣺���븴�Ӷ����ӣ���Ҫ�����ϣ��ͻ
���÷�Χ�����������Ҳ�ѯƵ���ĳ���

�Ż�����3��ʹ��switch-case�Ż������������֧���ַ���switch��
#include <stdio.h>
#include <string.h>

int findWeekday(char *day) {
    // ע�⣺�ⲻ�Ǳ�׼C�﷨����ĳЩ������֧��
    // ����ֻ��չʾ˼·��ʵ��ʵ����Ҫ���ݱ��������Ե���
    if(strcmp(day, "Sunday") == 0) return 1;
    else if(strcmp(day, "Monday") == 0) return 2;
    else if(strcmp(day, "Tuesday") == 0) return 3;
    else if(strcmp(day, "Wednesday") == 0) return 4;
    else if(strcmp(day, "Thursday") == 0) return 5;
    else if(strcmp(day, "Friday") == 0) return 6;
    else if(strcmp(day, "Saturday") == 0) return 7;
    else return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        char input[10];
        scanf("%s", input);
        printf("%d\n", findWeekday(input));
    }
    
    return 0;
}

�ŵ㣺��ĳЩ�������п����и��õ�����
ȱ�㣺����ֲ�Բ���Ǳ�׼C�﷨
���÷�Χ���ض����뻷���µ������Ż�
*/
