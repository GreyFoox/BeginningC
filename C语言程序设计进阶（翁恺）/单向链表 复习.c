#include <stdio.h>
#include <stdlib.h>

// ��ȷ�Ľṹ�嶨��
typedef struct _Node {
    int num;
    struct _Node *next;  // ? ��ȷ��ʹ��ָ�����ӽڵ�
} Node;

// ��ȷ������ṹ����
typedef struct {
    Node* head;  // ? ��ȷ��ͷָ��ָ���һ���ڵ�
} List;

// ? ����ʾ��1��ƴд��������ʹ���
/*
typdef struct List {  // ? ����typedefƴд����
    Node head ;       // ? ����Ӧ����Node* headָ�룬����Node����
} list;
*/

int main() {
    int num1, num2;
    List list;        // ? ��ȷ����������ʵ��
    list.head = NULL; // ? ��ȷ����ʼ��ͷָ��Ϊ��
    
    // ������һ���ڵ�
    scanf("%d", &num1);
    
    // ? ��ȷ���ڶ��Ϸ���ڵ��ڴ�
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->num = num1;
    node1->next = NULL;
    list.head = node1;  // ? ��ȷ��ͷָ��ָ���һ���ڵ�
    
    // ? ����ʾ��2��ջ�Ϸ���ʹ���ĸ�ֵ
    /*
    node n;                    // ? ����Ӧ���ڶ��Ϸ���
    list.head.num = num1;      // ? ����list�Ǳ�����������������
    list.head.next = num2;     // ? ����ָ��Ӧ��ָ��ڵ��ַ����������ֵ
    */
    
    // �����ڶ����ڵ�
    scanf("%d", &num2);
    
    // ? ��ȷ����̬����ڶ����ڵ�
    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->num = num2;
    node2->next = NULL;
    
    // ? ��ȷ�����ӽڵ㣨ָ�븳ֵ��
    list.head->next = node2;  // ? ��ȷ����һ���ڵ��nextָ��ڶ����ڵ�
    
    // ? ����ʾ��3����������ӷ�ʽ
    /*
    n.num = num2;
    list.head.next = num2;  // ? �����������ܸ���ָ��
    n.next = NULL;
    */
    
    // ? ��ȷ��������ӡ����
    printf("�������ݣ�");
    Node* current = list.head;
    while (current != NULL) {
        printf("%d ", current->num);
        current = current->next;  // ? ��ȷ��ͨ��ָ���ƶ�����һ���ڵ�
    }
    printf("\n");
    
    // ? ��ȷ���ͷ��ڴ棨��ֹ�ڴ�й©��
    free(node2);
    free(node1);
    list.head = NULL;  // ? ��ȷ��ͷָ����ΪNULL����ֹҰָ��
    
    // ? ����ʾ��4�������ͷ��ڴ�
    /*
    // ���û��free���ᵼ���ڴ�й©
    // ���������Ȼϵͳ����գ������ǲ���ϰ��
    */
    
    return 0;
}

// ? ��ȷ�ĺ�������װ�����ο���
void addNode(List* list, int value) {
    // ? ��ȷ����̬�����½ڵ�
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->num = value;
    newNode->next = NULL;
    
    if (list->head == NULL) {
        // ? ��ȷ��������ʱ�½ڵ��Ϊͷ�ڵ�
        list->head = newNode;
    } else {
        // ? ��ȷ���ҵ����һ���ڵ㲢����
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// ? ����ʾ��5������ĺ����������ڴ����
/*
void addNode(List list, int value) {  // ? ����Ӧ�ô�ָ������޸�ԭ����
    Node newNode;                     // ? ����ջ�Ϸ��䣬��������������
    newNode.num = value;
    // ... �����ʵ��
}
*/
