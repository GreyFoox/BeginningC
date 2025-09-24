#include <stdio.h>
#include <stdlib.h>

// 正确的结构体定义
typedef struct _Node {
    int num;
    struct _Node *next;  // ? 正确：使用指针连接节点
} Node;

// 正确的链表结构定义
typedef struct {
    Node* head;  // ? 正确：头指针指向第一个节点
} List;

// ? 错误示例1：拼写错误和类型错误
/*
typdef struct List {  // ? 错误：typedef拼写错误
    Node head ;       // ? 错误：应该是Node* head指针，不是Node对象
} list;
*/

int main() {
    int num1, num2;
    List list;        // ? 正确：创建链表实例
    list.head = NULL; // ? 正确：初始化头指针为空
    
    // 创建第一个节点
    scanf("%d", &num1);
    
    // ? 正确：在堆上分配节点内存
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->num = num1;
    node1->next = NULL;
    list.head = node1;  // ? 正确：头指针指向第一个节点
    
    // ? 错误示例2：栈上分配和错误的赋值
    /*
    node n;                    // ? 错误：应该在堆上分配
    list.head.num = num1;      // ? 错误：list是变量名，不是类型名
    list.head.next = num2;     // ? 错误：指针应该指向节点地址，不是整数值
    */
    
    // 创建第二个节点
    scanf("%d", &num2);
    
    // ? 正确：动态分配第二个节点
    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->num = num2;
    node2->next = NULL;
    
    // ? 正确：连接节点（指针赋值）
    list.head->next = node2;  // ? 正确：第一个节点的next指向第二个节点
    
    // ? 错误示例3：错误的连接方式
    /*
    n.num = num2;
    list.head.next = num2;  // ? 错误：整数不能赋给指针
    n.next = NULL;
    */
    
    // ? 正确：遍历打印链表
    printf("链表内容：");
    Node* current = list.head;
    while (current != NULL) {
        printf("%d ", current->num);
        current = current->next;  // ? 正确：通过指针移动到下一个节点
    }
    printf("\n");
    
    // ? 正确：释放内存（防止内存泄漏）
    free(node2);
    free(node1);
    list.head = NULL;  // ? 正确：头指针设为NULL，防止野指针
    
    // ? 错误示例4：忘记释放内存
    /*
    // 如果没有free，会导致内存泄漏
    // 程序结束虽然系统会回收，但这是不良习惯
    */
    
    return 0;
}

// ? 正确的函数化封装（供参考）
void addNode(List* list, int value) {
    // ? 正确：动态创建新节点
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->num = value;
    newNode->next = NULL;
    
    if (list->head == NULL) {
        // ? 正确：空链表时新节点成为头节点
        list->head = newNode;
    } else {
        // ? 正确：找到最后一个节点并连接
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// ? 错误示例5：错误的函数参数和内存分配
/*
void addNode(List list, int value) {  // ? 错误：应该传指针才能修改原链表
    Node newNode;                     // ? 错误：栈上分配，函数结束即销毁
    newNode.num = value;
    // ... 错误的实现
}
*/
