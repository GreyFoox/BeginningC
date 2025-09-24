#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    printf("=== C�����ַ��������̳� ===\n\n");
    
    // ========== 1. �ַ����Ļ�����ʾ��ʽ ==========
    printf("1. �ַ����Ļ�����ʾ��ʽ:\n");
    
    // ��ʽ1: �ַ�������ʽ���ֶ���ӽ�����'\0'
    char words0[] = {'m','i','k','u','\0'};
    printf("  �ַ�����: %s (����: %zu)\n", words0, strlen(words0));
    
    // ��ʽ2: �ַ�����������ʼ�����飬�Զ���ӽ�����
    char words1[] = "Miku";
    printf("  �ַ���������: %s (����: %zu)\n", words1, strlen(words1));
    
    // ��ʽ3: ָ���ַ���������ָ��(ֻ��)
    const char *words2 = "Miku";
    printf("  �ַ���ָ��: %s (����: %zu)\n\n", words2, strlen(words2));
    
    
    // ========== 2. �ַ���������� ==========
    printf("2. �ַ����������:\n");
    
    // ��ȫ�����ַ��� - �������볤��Ϊ7���ַ�(����1λ��������)
    char str[8];
    printf("  ������һ���ַ���(���7���ַ�): ");
    scanf("%7s", str);
    printf("  ��������ַ���: %s\n", str);
    
    // ������뻺����
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    // �ַ��������
    printf("  ������һ���ַ�: ");
    int ch = getchar();
    printf("  ��������ַ�: ");
    putchar(ch);
    printf("\n\n");
    
    
    // ========== 3. �ַ����Ƚ��븴�� ==========
    printf("3. �ַ����Ƚ��븴��:\n");
    
    // �ַ����Ƚ�
    char s1[] = "abc";
    char s2[] = "abc";
    printf("  �ַ����ȽϽ��: %d (0��ʾ���)\n", strcmp(s1, s2));
    
    // �ַ�������
    const char *src = "Hello World";
    char *dst = (char*)malloc(strlen(src) + 1); // �����㹻�ڴ�(����������)
    if (dst != NULL) {
        strcpy(dst, src); // Ŀ����ǰ��Դ�ں�
        printf("  ���Ƶ��ַ���: %s\n", dst);
        free(dst); // �ͷ��ڴ�
    }
    printf("\n");
    
    
    // ========== 4. �ַ����������� ==========
    printf("4. �ַ�����������:\n");
    
    // strstr - ���ַ����в����Ӵ�(���ִ�Сд)
    const char *text = "Hello World, hello C language";
    const char *substr = "hello";
    
    char *result = strstr(text, substr);
    if (result != NULL) {
        printf("  �ҵ��Ӵ�: %s\n", result);
    } else {
        printf("  δ�ҵ��Ӵ�: %s\n", substr);
    }
    
    // strchr - �����ַ�
    char *char_result = strchr(text, 'W');
    if (char_result != NULL) {
        printf("  �ҵ��ַ�: %s\n", char_result);
    }
    printf("\n");
    
    
    // ========== 5. �޸���Ĵ���ʾ�� ==========
    printf("5. �޸���Ĵ���ʾ��:\n");
    
    char s[] = "hello";
    
    // �����ַ�'l'�����ǲ����ڵ�'1'
    char *p = strchr(s, 'l');
    
    if (p != NULL) {
        char c = *p;        // �����ҵ����ַ�
        *p = '\0';          // �ָ��ַ���
        
        // ��ȷ�����ڴ沢�����ַ���
        char *t = (char*)malloc(strlen(s) + 1); // +1���ڽ�����
        if (t != NULL) {
            strcpy(t, s);    // �����ַ���
            printf("  �ָ����ַ���: %s\n", t);
            free(t);         // �ͷ��ڴ�
        }
        
        // �ָ�ԭ�ַ�
        *p = c;
        printf("  �ָ����ԭ�ַ���: %s\n", s);
    } else {
        printf("  δ�ҵ�ָ���ַ�\n");
    }
    
    printf("\n=== �̳̽��� ===\n");
    
    return 0;
}
