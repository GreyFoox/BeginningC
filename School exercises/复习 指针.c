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
    
    // 紧凑的同步写法
    printf("初始化数组: ");
    int index = 0;
    int *ptr = arr;
    
    // 一行完成赋值、打印、指针移动
    while(ptr < arr + 4) {
        printf("%d ", *ptr++ = index);  // 赋值、打印、指针移动同步
        index += 2;
    }
    printf("\n");
    
    // 反转数组
    reverseArray(arr, 4);
    
    // 打印反转后的数组
    printf("反转后数组: ");
    ptr = arr;  // 重置指针
    while(ptr < arr + 4) {
        printf("%d ", *ptr++);  // 打印和指针移动同步
    }
    printf("\n");
    ptr = arr;
    printf("%p\n", find(arr, 4, 2));
  	printf("%d\n", count(arr, 4, 2));
    free(arr);  
    arr = NULL;
    
    return 0;    
}
