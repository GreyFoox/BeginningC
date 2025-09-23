#include <stdio.h>
#include <stdlib.h>  // ���malloc��free�����ͷ�ļ�

typedef struct {
    int *array;  // ָ��̬���������ָ��
    int size;    // ���鵱ǰ�Ĵ�С
} Array;

const int BLOCK_SIZE = 20;  // ������С��ÿ�����ݵ�������λ

// ��������ṹ�岢��ʼ��
Array array_create(int init_size) {
    Array a;
    // ��̬�����ڴ棺ָ��arrayָ����ϵ�����ռ�
    a.array = (int*)malloc(sizeof(int) * init_size);
    a.size = init_size;
    return a;  // ���ؽṹ�帱��������ָ��ͬһ���ڴ��ָ�룩
}

// �ͷ������ڴ沢���ýṹ��
void array_free(Array *a) {  // ����ṹ��ָ�����޸�ԭ�ṹ��
    free(a->array);     // �ͷŶ��ڴ�
    a->array = NULL;    // ��ֹҰָ��
    a->size = 0;
}

// ��ȡ�����С
int array_size(const Array *a) {
    return a->size;
}

// ����ָ��λ�õ�Ԫ�أ��Զ����ݣ�
int* array_at(Array *a, int index) {
    if (index >= a->size) {
        // ������Ҫ���ݵĿ���������BLOCK_SIZEΪ��λ����
        int new_size = (index / BLOCK_SIZE + 1) * BLOCK_SIZE;
        array_inflate(a, new_size - a->size);
    }
    return &(a->array[index]);  // ����Ԫ��λ�õ�ָ��
}

// ��ȡԪ��ֵ���ѷ�������array_at�Ѱ������ܣ�
int array_get(const Array *a, int index) {
    return a->array[index];
}

// ����Ԫ��ֵ
void array_set(Array *a, int index, int value) {
    a->array[index] = value;
}

// ��������
void array_inflate(Array *a, int more_size) {
    // �·��������ڴ��
    int *p = (int*)malloc(sizeof(int) * (a->size + more_size));
    // ���ƾ����ݵ����ڴ�
    for (int i = 0; i < a->size; i++) {
        p[i] = a->array[i];
    }
    free(a->array);   // �ͷž��ڴ�
    a->array = p;     // ����ָ��ָ�����ڴ�
    a->size += more_size;
}

int main() {
    Array a = array_create(10);  // ��ʼ�����飨��СΪ10��
    int cnt = 0;
    int num;

    printf("���������֣�����-1������:\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1) break;
        
        // ͨ��array_at�Զ���������
        int *elem_ptr = array_at(&a, cnt);  // ��ȡָ���cnt��Ԫ�ص�ָ��
        *elem_ptr = num;  // ͨ��ָ�븳ֵ
        cnt++;
    }

    // ���ԣ���ӡ����Ԫ��
    printf("�������ݣ�\n");
    for (int i = 0; i < cnt; i++) {
        printf("%d ", a.array[i]);  // ֱ�ӷ��������ڴ�
    }
    printf("\n");

    // ����array_set��array_get
    array_set(&a, 2, 999);  // ���õ�2��Ԫ�أ�������0��ʼ��
    printf("�޸ĺ��2��Ԫ�أ�%d\n", array_get(&a, 2));

    array_free(&a);  // �ͷ��ڴ�
    return 0;
}
