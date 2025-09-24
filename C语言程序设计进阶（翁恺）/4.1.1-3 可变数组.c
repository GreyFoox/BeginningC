#include <stdio.h>
#include <stdlib.h>  // 添加malloc和free所需的头文件

typedef struct {
    int *array;  // 指向动态分配数组的指针
    int size;    // 数组当前的大小
} Array;

const int BLOCK_SIZE = 20;  // 定义块大小，每次扩容的增量单位

// 创建数组结构体并初始化
Array array_create(int init_size) {
    Array a;
    // 动态分配内存：指针array指向堆上的数组空间
    a.array = (int*)malloc(sizeof(int) * init_size);
    a.size = init_size;
    return a;  // 返回结构体副本（包含指向同一堆内存的指针）
}

// 释放数组内存并重置结构体
void array_free(Array *a) {  // 传入结构体指针以修改原结构体
    free(a->array);     // 释放堆内存
    a->array = NULL;    // 防止野指针
    a->size = 0;
}

// 获取数组大小
int array_size(const Array *a) {
    return a->size;
}

// 访问指定位置的元素（自动扩容）
int* array_at(Array *a, int index) {
    if (index >= a->size) {
        // 计算需要扩容的块数量，按BLOCK_SIZE为单位扩容
        int new_size = (index / BLOCK_SIZE + 1) * BLOCK_SIZE;
        array_inflate(a, new_size - a->size);
    }
    return &(a->array[index]);  // 返回元素位置的指针
}

// 获取元素值（已废弃，因array_at已包含功能）
int array_get(const Array *a, int index) {
    return a->array[index];
}

// 设置元素值
void array_set(Array *a, int index, int value) {
    a->array[index] = value;
}

// 扩容数组
void array_inflate(Array *a, int more_size) {
    // 新分配更大的内存块
    int *p = (int*)malloc(sizeof(int) * (a->size + more_size));
    // 复制旧数据到新内存
    for (int i = 0; i < a->size; i++) {
        p[i] = a->array[i];
    }
    free(a->array);   // 释放旧内存
    a->array = p;     // 更新指针指向新内存
    a->size += more_size;
}

int main() {
    Array a = array_create(10);  // 初始化数组（大小为10）
    int cnt = 0;
    int num;

    printf("请输入数字（输入-1结束）:\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1) break;
        
        // 通过array_at自动处理扩容
        int *elem_ptr = array_at(&a, cnt);  // 获取指向第cnt个元素的指针
        *elem_ptr = num;  // 通过指针赋值
        cnt++;
    }

    // 测试：打印所有元素
    printf("数组内容：\n");
    for (int i = 0; i < cnt; i++) {
        printf("%d ", a.array[i]);  // 直接访问数组内存
    }
    printf("\n");

    // 测试array_set和array_get
    array_set(&a, 2, 999);  // 设置第2个元素（索引从0开始）
    printf("修改后第2个元素：%d\n", array_get(&a, 2));

    array_free(&a);  // 释放内存
    return 0;
}
