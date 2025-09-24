#include <stdio.h>
#include <stdlib.h>

// 定义节点结构体
typedef struct __node {
    int value;              // 节点存储的数据
    struct __node *next;    // 指向下一个节点的指针 - 链表连接的关键
} Node;

// 定义链表结构体（包含头指针）
typedef struct __list {
    Node* head;             // 指向链表第一个节点的指针 - 链表入口点
} List;

// 函数声明
void add(List* plist, int number);
int delete(List* plist, int number);
void print_list(List* plist);
void free_list(List* plist);

int main(int argc, char const *argv[]) {
    List list;              // 创建链表结构体实例
    int number;
    list.head = NULL;       // 初始化头指针为空（空链表）
    
    printf("请输入数字（输入-1结束）:\n");
    do {
        scanf("%d", &number);
        if (number != -1) {
            add(&list, number);  // 向链表添加新节点
        }
    } while (number != -1);
    
    // 打印链表内容
    printf("添加后的链表：");
    print_list(&list);
    
    // 测试删除功能
    printf("\n请输入要删除的数字（输入-1结束）：");
    scanf("%d", &number);
    if (number != -1) {
        if (delete(&list, number)) {
            printf("删除成功，当前链表：");
            print_list(&list);
        } else {
            printf("删除失败，未找到该数字。当前链表：");
            print_list(&list);
        }
    }
    
    // 释放链表内存 - 防止内存泄漏
    free_list(&list);
    
    return 0;
}

// 向链表添加新节点
void add(List* plist, int number) {
    // 创建新节点 - 在堆上分配内存
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = number;      // 设置节点值
    p->next = NULL;         // 新节点放在末尾，所以next为NULL
    
    // 如果链表为空，新节点成为头节点
    if (plist->head == NULL) {
        plist->head = p;    // 头指针指向新节点 - 修改外部指针需要传地址
    } 
    // 否则找到最后一个节点并连接新节点
    else {
        Node* last = plist->head;
        // 遍历找到最后一个节点（next为NULL的节点）
        while (last->next != NULL) {
            last = last->next;  // 关键：通过next指针移动到下一个节点
        }
        last->next = p;     // 将新节点连接到链表末尾
    }
}

// 删除链表中指定值的节点
int delete(List* plist, int number) {
    // 如果链表为空，直接返回失败
    if (plist->head == NULL) {
        return 0;
    }
    
    // 创建两个指针：当前指针和前一个指针
    Node* current = plist->head;  // 当前指针，用于遍历和检查节点
    Node* previous = NULL;        // 前一个指针 - 关键：初始为NULL，因为头节点前面没有节点
    
    // 遍历链表查找要删除的节点
    while (current != NULL) {
        // 先判断当前节点是否为目标节点
        if (current->value == number) {
            // 找到要删除的节点
            
            if (previous == NULL) {
                // 情况1：删除头节点 - previous为NULL表示current是头节点
                plist->head = current->next;  // 头指针指向第二个节点
            } else {
                // 情况2：删除中间或尾部节点
                previous->next = current->next;  // 前一个节点跳过当前节点，直接连接下一个
            }
            
            free(current);  // 释放当前节点内存 - 必须释放防止内存泄漏
            return 1;       // 删除成功
        }
        
        // 重要：只有当前节点不是目标时，才移动指针继续查找
        // 移动顺序：先保存当前位置，再前进到下一个节点
        previous = current;           // previous跟进到current的位置
        current = current->next;      // current前进到下一个节点
    }
    
    return 0;  // 未找到要删除的节点
}

// 打印链表所有元素
void print_list(List* plist) {
    if (plist->head == NULL) {
        printf("链表为空\n");
        return;
    }
    
    Node* current = plist->head;  // 从头节点开始遍历
    
    // 遍历链表直到末尾（current为NULL）
    while (current != NULL) {
        printf("%d ", current->value);  // 打印当前节点值
        current = current->next;        // 关键：通过next指针移动到下一个节点
    }
    printf("\n");
}

// 释放链表内存 - 每个malloc都必须有对应的free
void free_list(List* plist) {
    Node* current = plist->head;
    
    // 逐个释放所有节点
    while (current != NULL) {
        Node* temp = current;   // 保存当前节点指针
        current = current->next; // 先移动到下一个节点，再释放当前节点
        free(temp);             // 释放当前节点内存
    }
    
    plist->head = NULL;  // 头指针设为NULL，防止野指针
}
