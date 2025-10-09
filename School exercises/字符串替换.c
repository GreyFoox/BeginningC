/*˼·������
A -> Z ʹ��ASCII�루ԭע��"A��"��������׼ȷ��
�����Ǵ�д��ĸ �����Ĳ��� 
������80���ַ� �Իس����� -> Ӧ��ʹ��fgets()������fputs() 
ͨ���������ֺ�ʼ��Ϊ155 -> ʹ���������㣨ԭע��"��Ԫ�����"������׼ȷ��*/

#include <stdio.h>
#include <string.h>

int main() {
	char str[81];
    fgets(str, 81, stdin);
    int length = strlen(str);
    
    // ԭ������룺
    // for(int i = 1; i < length; i++) {
    // ����ԭ��ѭ����i=1��ʼ�������˵�һ���ַ���Ӧ�ô�i=0��ʼ
    
    // ��ȷ���룺
    for(int i = 0; i < length; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            // ʹ�öԳ�ӳ�䣺A->Z, B->Y, ..., Z->A
            // ��ʽ��'A' + 'Z' - str[i] �� 155 - str[i]
            printf("%c", 155 - str[i]);
        } else {
            printf("%c", str[i]);
        }
    }
    return 0;
}

/*
�Ż�����1��ʹ�ø�ֱ�۵�ӳ�乫ʽ
#include <stdio.h>
#include <string.h>

int main() {
    char str[81];
    fgets(str, 81, stdin);
    int length = strlen(str);
    
    for(int i = 0; i < length; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            // ʹ�ù�ʽ��'A' + 'Z' - str[i]
            printf("%c", 'A' + 'Z' - str[i]);
        } else {
            printf("%c", str[i]);
        }
    }
    return 0;
}

�ŵ㣺��ʽ��ֱ�ۣ��������
ȱ�㣺��155-str[i]Ч����ͬ

�Ż�����2��ʹ�ò��ұ������ڸ���ӳ�䣩
#include <stdio.h>
#include <string.h>

int main() {
    char str[81];
    fgets(str, 81, stdin);
    
    // ����ӳ���
    char map[256] = {0};
    for(int i = 0; i < 256; i++) {
        map[i] = i; // Ĭ��ӳ��Ϊ�Լ�
    }
    
    // ���ô�д��ĸ��ӳ��
    for(char c = 'A'; c <= 'Z'; c++) {
        map[c] = 'A' + 'Z' - c;
    }
    
    // ʹ��ӳ������ת��
    for(int i = 0; str[i] != '\0'; i++) {
        printf("%c", map[str[i]]);
    }
    return 0;
}

�ŵ㣺���ڸ���ӳ�����Ч�ʸߣ���������
ȱ�㣺��Ҫ����Ĵ洢�ռ�

�Ż�����3��ʹ��ָ�����
#include <stdio.h>
#include <string.h>

int main() {
    char str[81];
    fgets(str, 81, stdin);
    
    char *p = str;
    while(*p != '\0') {
        if(*p >= 'A' && *p <= 'Z') {
            printf("%c", 'A' + 'Z' - *p);
        } else {
            printf("%c", *p);
        }
        p++;
    }
    return 0;
}

�ŵ㣺�����࣬ʹ��ָ��Ч�ʸ�
ȱ�㣺��ָ�����Ҫ��ϸ�
*/
