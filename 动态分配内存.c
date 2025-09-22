#include <stdio.h>
#include <stdlib.h>

/**
 * ����1: ��̬�������鲢�������
 * ��ʾmalloc()��free()�Ļ����÷�
 */
void reverse_array() {
    int number;
    int* a;
    int i;
    
    printf("��������: ");
    scanf("%d", &number);
    
    // ��̬�����ڴ� - ������СΪnumber����������
    a = (int*)malloc(number * sizeof(int));
    
    // ����ڴ�����Ƿ�ɹ�
    if (a == NULL) {
        printf("�ڴ����ʧ��!\n");
        return;
    }
    
    // ��ȡ��������
    printf("������%d������: ", number);
    for (i = 0; i < number; i++) {
        scanf("%d", &a[i]);
    }
    
    // �����������
    printf("�������: ");
    for (i = number - 1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    // �ͷŷ�����ڴ�
    free(a);
}

/**
 * ����2: ����ϵͳ�ɷ�����ڴ�����
 * ���Ϸ���100MB�ڴ��ֱ��ʧ��
 */
void test_memory_limit() {
    void *p;
    int cnt = 0;
    
    // ���ϳ��Է���100MB�ڴ��
    while ((p = malloc(100 * 1024 * 1024)) != NULL) {
        cnt++;
    }
    
    printf("������%d00MB�Ŀռ�\n", cnt);
    
    // ע��: ����û���ͷ��ڴ棬��Ϊ���򼴽��˳�
    // ��ʵ��Ӧ���У�Ӧ���ͷ����з�����ڴ�
}

int main(void) {
    printf("=== ��̬�ڴ������ʾ ===\n\n");
    
    // ���е�һ������
    printf("����1: ��̬�����������\n");
    reverse_array();
    
    printf("\n");
    
    // ���еڶ�������
    printf("����2: �ڴ���伫�޲���\n");
    test_memory_limit();
    
    return 0;
}
