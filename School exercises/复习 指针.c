#include <stdio.h>
#include <stdlib.h>

void reverseArray(int *arr, int n) {
    int *start = arr;
    int *end = arr + n - 1;
    
    while(start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
} 

int* find(int *arr, int n, int target) {
	for(int *p = arr; p < arr + n; p++) {
		if( *p == target ) {
			return p;
		}
	}
	return NULL; 
}

int count(int *arr, int n, int target) {
	int count = 0;
	for (int *p = arr; p < arr + n; p++) {
		if(*p == target) {
			count++;
		}
	}
	return count;
}

int main() {
    int* arr = (int*)malloc(4 * sizeof(int));
    if(arr == NULL) return 1;
    
    // ���յ�ͬ��д��
    printf("��ʼ������: ");
    int index = 0;
    int *ptr = arr;
    
    // һ����ɸ�ֵ����ӡ��ָ���ƶ�
    while(ptr < arr + 4) {
        printf("%d ", *ptr++ = index);  // ��ֵ����ӡ��ָ���ƶ�ͬ��
        index += 2;
    }
    printf("\n");
    
    // ��ת����
    reverseArray(arr, 4);
    
    // ��ӡ��ת�������
    printf("��ת������: ");
    ptr = arr;  // ����ָ��
    while(ptr < arr + 4) {
        printf("%d ", *ptr++);  // ��ӡ��ָ���ƶ�ͬ��
    }
    printf("\n");
    ptr = arr;
    printf("%p\n", find(arr, 4, 2));
  	printf("%d\n", count(arr, 4, 2));
    free(arr);  
    arr = NULL;
    
    return 0;    
}
