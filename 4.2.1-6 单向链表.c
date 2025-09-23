#include <stdio.h>
#include <stdlib.h>

// ����ڵ�ṹ��
typedef struct __node {
    int value;              // �ڵ�洢������
    struct __node *next;    // ָ����һ���ڵ��ָ�� - �������ӵĹؼ�
} Node;

// ��������ṹ�壨����ͷָ�룩
typedef struct __list {
    Node* head;             // ָ�������һ���ڵ��ָ�� - ������ڵ�
} List;

// ��������
void add(List* plist, int number);
int delete(List* plist, int number);
void print_list(List* plist);
void free_list(List* plist);

int main(int argc, char const *argv[]) {
    List list;              // ��������ṹ��ʵ��
    int number;
    list.head = NULL;       // ��ʼ��ͷָ��Ϊ�գ�������
    
    printf("���������֣�����-1������:\n");
    do {
        scanf("%d", &number);
        if (number != -1) {
            add(&list, number);  // ����������½ڵ�
        }
    } while (number != -1);
    
    // ��ӡ��������
    printf("��Ӻ������");
    print_list(&list);
    
    // ����ɾ������
    printf("\n������Ҫɾ�������֣�����-1��������");
    scanf("%d", &number);
    if (number != -1) {
        if (delete(&list, number)) {
            printf("ɾ���ɹ�����ǰ����");
            print_list(&list);
        } else {
            printf("ɾ��ʧ�ܣ�δ�ҵ������֡���ǰ����");
            print_list(&list);
        }
    }
    
    // �ͷ������ڴ� - ��ֹ�ڴ�й©
    free_list(&list);
    
    return 0;
}

// ����������½ڵ�
void add(List* plist, int number) {
    // �����½ڵ� - �ڶ��Ϸ����ڴ�
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = number;      // ���ýڵ�ֵ
    p->next = NULL;         // �½ڵ����ĩβ������nextΪNULL
    
    // �������Ϊ�գ��½ڵ��Ϊͷ�ڵ�
    if (plist->head == NULL) {
        plist->head = p;    // ͷָ��ָ���½ڵ� - �޸��ⲿָ����Ҫ����ַ
    } 
    // �����ҵ����һ���ڵ㲢�����½ڵ�
    else {
        Node* last = plist->head;
        // �����ҵ����һ���ڵ㣨nextΪNULL�Ľڵ㣩
        while (last->next != NULL) {
            last = last->next;  // �ؼ���ͨ��nextָ���ƶ�����һ���ڵ�
        }
        last->next = p;     // ���½ڵ����ӵ�����ĩβ
    }
}

// ɾ��������ָ��ֵ�Ľڵ�
int delete(List* plist, int number) {
    // �������Ϊ�գ�ֱ�ӷ���ʧ��
    if (plist->head == NULL) {
        return 0;
    }
    
    // ��������ָ�룺��ǰָ���ǰһ��ָ��
    Node* current = plist->head;  // ��ǰָ�룬���ڱ����ͼ��ڵ�
    Node* previous = NULL;        // ǰһ��ָ�� - �ؼ�����ʼΪNULL����Ϊͷ�ڵ�ǰ��û�нڵ�
    
    // �����������Ҫɾ���Ľڵ�
    while (current != NULL) {
        // ���жϵ�ǰ�ڵ��Ƿ�ΪĿ��ڵ�
        if (current->value == number) {
            // �ҵ�Ҫɾ���Ľڵ�
            
            if (previous == NULL) {
                // ���1��ɾ��ͷ�ڵ� - previousΪNULL��ʾcurrent��ͷ�ڵ�
                plist->head = current->next;  // ͷָ��ָ��ڶ����ڵ�
            } else {
                // ���2��ɾ���м��β���ڵ�
                previous->next = current->next;  // ǰһ���ڵ�������ǰ�ڵ㣬ֱ��������һ��
            }
            
            free(current);  // �ͷŵ�ǰ�ڵ��ڴ� - �����ͷŷ�ֹ�ڴ�й©
            return 1;       // ɾ���ɹ�
        }
        
        // ��Ҫ��ֻ�е�ǰ�ڵ㲻��Ŀ��ʱ�����ƶ�ָ���������
        // �ƶ�˳���ȱ��浱ǰλ�ã���ǰ������һ���ڵ�
        previous = current;           // previous������current��λ��
        current = current->next;      // currentǰ������һ���ڵ�
    }
    
    return 0;  // δ�ҵ�Ҫɾ���Ľڵ�
}

// ��ӡ��������Ԫ��
void print_list(List* plist) {
    if (plist->head == NULL) {
        printf("����Ϊ��\n");
        return;
    }
    
    Node* current = plist->head;  // ��ͷ�ڵ㿪ʼ����
    
    // ��������ֱ��ĩβ��currentΪNULL��
    while (current != NULL) {
        printf("%d ", current->value);  // ��ӡ��ǰ�ڵ�ֵ
        current = current->next;        // �ؼ���ͨ��nextָ���ƶ�����һ���ڵ�
    }
    printf("\n");
}

// �ͷ������ڴ� - ÿ��malloc�������ж�Ӧ��free
void free_list(List* plist) {
    Node* current = plist->head;
    
    // ����ͷ����нڵ�
    while (current != NULL) {
        Node* temp = current;   // ���浱ǰ�ڵ�ָ��
        current = current->next; // ���ƶ�����һ���ڵ㣬���ͷŵ�ǰ�ڵ�
        free(temp);             // �ͷŵ�ǰ�ڵ��ڴ�
    }
    
    plist->head = NULL;  // ͷָ����ΪNULL����ֹҰָ��
}
