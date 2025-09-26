#include <stdio.h>

// 定义两个结构体
struct date {
    int month;
    int day;
    int year;
} mydate;

struct point {
    int x;
    int y;
};

// 函数声明
struct point* getStruct(struct point*);
void output(struct point);
void print(const struct point *p);

int main(int argc, char const *argv[]) {
    struct date *p = &mydate;
    p->month = 12; //等价于 (*p).month 
    printf("Date: %d/%d/%d\n", p->month, p->day, p->year);

    struct point y = {0, 0};
    getStruct(&y);
    output(y);
    output(*getStruct(&y));
    print(getStruct(&y));
    *getStruct(&y) = (struct point){1,2}; 

    return 0;
}

struct point* getStruct(struct point *p) {
    scanf("%d", &p->x);//获取成员先于取地址 
    scanf("%d", &p->y);
    return p;
}

void output(struct point p) {
    printf("%d, %d\n", p.x, p.y);
}

void print(const struct point *p) {//const 确保不修改内容 大胆打印 
    printf("%d, %d\n", p->x, p->y);
}
