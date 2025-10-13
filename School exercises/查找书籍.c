/*思路分析：
n本书（正确）
书名（长度不超过30的字符串） -> 应该使用fgets而不是fputs，fgets用于输入，fputs用于输出（fgets(str,31,stdin)正确）
价格 double -> scanf("%lf")（正确）
同时存入二维数组存储(两种数据类型怎么办呢？) 应该使用结构体数组而不是二维数组，因为数据类型不同
冒泡排序（正确，但需要明确是按价格排序）
联想：怎么样能达到和Python字典一样的效果？C语言中可以使用结构体数组来模拟字典的功能*/

#include <stdio.h>
#include <string.h>

// 定义书的结构体
struct Book {
    char name[31];
    double price;
};

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // 读取换行符，避免影响后面的fgets
    
    struct Book books[10]; // 最多10本书
    
    // 输入书籍信息
    for(int i = 0; i < n; i++) {
        fgets(books[i].name, 31, stdin);
        // 去除fgets读取的换行符
        books[i].name[strcspn(books[i].name, "\n")] = '\0';
        scanf("%lf", &books[i].price);
        getchar(); // 读取换行符
    }
    
    // 使用冒泡排序按价格排序
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(books[j].price > books[j+1].price) {
                // 交换两本书的信息
                struct Book temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
    
    // 输出价格最高和最低的书
    printf("%.2f, %s\n", books[n-1].price, books[n-1].name); // 最高价
    printf("%.2f, %s\n", books[0].price, books[0].name);     // 最低价
    
    return 0;
}

/*
优化方案1：不排序，直接查找最高价和最低价
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
    
    // 输入第一本书，同时初始化最高价和最低价
    fgets(books[0].name, 31, stdin);
    books[0].name[strcspn(books[0].name, "\n")] = '\0';
    scanf("%lf", &books[0].price);
    getchar();
    
    int maxIndex = 0, minIndex = 0;
    
    // 输入剩余书籍并同时比较
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

优点：只需一次遍历，效率更高
缺点：代码逻辑稍复杂

优化方案2：使用指针数组
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
    
    struct Book *books[10]; // 指针数组
    
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
    
    // 释放内存
    for(int i = 0; i < n; i++) {
        free(books[i]);
    }
    
    return 0;
}

优点：使用指针数组，灵活性高
缺点：需要手动管理内存

优化方案3：使用qsort排序
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book {
    char name[31];
    double price;
};

// 比较函数，用于qsort
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
    
    // 使用qsort按价格排序
    qsort(books, n, sizeof(struct Book), compare);
    
    printf("%.2f, %s\n", books[n-1].price, books[n-1].name);
    printf("%.2f, %s\n", books[0].price, books[0].name);
    
    return 0;
}

优点：使用标准库函数，代码简洁
缺点：需要理解函数指针
*/
