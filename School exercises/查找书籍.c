/*˼·������
n���飨��ȷ��
���������Ȳ�����30���ַ����� -> Ӧ��ʹ��fgets������fputs��fgets�������룬fputs���������fgets(str,31,stdin)��ȷ��
�۸� double -> scanf("%lf")����ȷ��
ͬʱ�����ά����洢(��������������ô���أ�) Ӧ��ʹ�ýṹ����������Ƕ�ά���飬��Ϊ�������Ͳ�ͬ
ð��������ȷ������Ҫ��ȷ�ǰ��۸�����
���룺��ô���ܴﵽ��Python�ֵ�һ����Ч����C�����п���ʹ�ýṹ��������ģ���ֵ�Ĺ���*/

#include <stdio.h>
#include <string.h>

// ������Ľṹ��
struct Book {
    char name[31];
    double price;
};

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // ��ȡ���з�������Ӱ������fgets
    
    struct Book books[10]; // ���10����
    
    // �����鼮��Ϣ
    for(int i = 0; i < n; i++) {
        fgets(books[i].name, 31, stdin);
        // ȥ��fgets��ȡ�Ļ��з�
        books[i].name[strcspn(books[i].name, "\n")] = '\0';
        scanf("%lf", &books[i].price);
        getchar(); // ��ȡ���з�
    }
    
    // ʹ��ð�����򰴼۸�����
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(books[j].price > books[j+1].price) {
                // �������������Ϣ
                struct Book temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
    
    // ����۸���ߺ���͵���
    printf("%.2f, %s\n", books[n-1].price, books[n-1].name); // ��߼�
    printf("%.2f, %s\n", books[0].price, books[0].name);     // ��ͼ�
    
    return 0;
}

/*
�Ż�����1��������ֱ�Ӳ�����߼ۺ���ͼ�
#include <stdio.h>
#include <string.h>

struct Book {
    char name[31];
    double price;
};

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    
    struct Book books[10];
    
    // �����һ���飬ͬʱ��ʼ����߼ۺ���ͼ�
    fgets(books[0].name, 31, stdin);
    books[0].name[strcspn(books[0].name, "\n")] = '\0';
    scanf("%lf", &books[0].price);
    getchar();
    
    int maxIndex = 0, minIndex = 0;
    
    // ����ʣ���鼮��ͬʱ�Ƚ�
    for(int i = 1; i < n; i++) {
        fgets(books[i].name, 31, stdin);
        books[i].name[strcspn(books[i].name, "\n")] = '\0';
        scanf("%lf", &books[i].price);
        getchar();
        
        if(books[i].price > books[maxIndex].price) {
            maxIndex = i;
        }
        if(books[i].price < books[minIndex].price) {
            minIndex = i;
        }
    }
    
    printf("%.2f, %s\n", books[maxIndex].price, books[maxIndex].name);
    printf("%.2f, %s\n", books[minIndex].price, books[minIndex].name);
    
    return 0;
}

�ŵ㣺ֻ��һ�α�����Ч�ʸ���
ȱ�㣺�����߼��Ը���

�Ż�����2��ʹ��ָ������
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book {
    char name[31];
    double price;
};

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    
    struct Book *books[10]; // ָ������
    
    for(int i = 0; i < n; i++) {
        books[i] = (struct Book*)malloc(sizeof(struct Book));
        fgets(books[i]->name, 31, stdin);
        books[i]->name[strcspn(books[i]->name, "\n")] = '\0';
        scanf("%lf", &books[i]->price);
        getchar();
    }
    
    int maxIndex = 0, minIndex = 0;
    for(int i = 1; i < n; i++) {
        if(books[i]->price > books[maxIndex]->price) {
            maxIndex = i;
        }
        if(books[i]->price < books[minIndex]->price) {
            minIndex = i;
        }
    }
    
    printf("%.2f, %s\n", books[maxIndex]->price, books[maxIndex]->name);
    printf("%.2f, %s\n", books[minIndex]->price, books[minIndex]->name);
    
    // �ͷ��ڴ�
    for(int i = 0; i < n; i++) {
        free(books[i]);
    }
    
    return 0;
}

�ŵ㣺ʹ��ָ�����飬����Ը�
ȱ�㣺��Ҫ�ֶ������ڴ�

�Ż�����3��ʹ��qsort����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book {
    char name[31];
    double price;
};

// �ȽϺ���������qsort
int compare(const void *a, const void *b) {
    struct Book *bookA = (struct Book*)a;
    struct Book *bookB = (struct Book*)b;
    if(bookA->price > bookB->price) return 1;
    if(bookA->price < bookB->price) return -1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    
    struct Book books[10];
    
    for(int i = 0; i < n; i++) {
        fgets(books[i].name, 31, stdin);
        books[i].name[strcspn(books[i].name, "\n")] = '\0';
        scanf("%lf", &books[i].price);
        getchar();
    }
    
    // ʹ��qsort���۸�����
    qsort(books, n, sizeof(struct Book), compare);
    
    printf("%.2f, %s\n", books[n-1].price, books[n-1].name);
    printf("%.2f, %s\n", books[0].price, books[0].name);
    
    return 0;
}

�ŵ㣺ʹ�ñ�׼�⺯����������
ȱ�㣺��Ҫ��⺯��ָ��
*/
