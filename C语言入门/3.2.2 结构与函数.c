#include <stdio.h>

// ���������ṹ��
struct date {
    int month;
    int day;
    int year;
} mydate;

struct point {
    int x;
    int y;
};

// ��������
struct point* getStruct(struct point*);
void output(struct point);
void print(const struct point *p);

int main(int argc, char const *argv[]) {
    struct date *p = &mydate;
    p->month = 12; //�ȼ��� (*p).month 
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
    scanf("%d", &p->x);//��ȡ��Ա����ȡ��ַ 
    scanf("%d", &p->y);
    return p;
}

void output(struct point p) {
    printf("%d, %d\n", p.x, p.y);
}

void print(const struct point *p) {//const ȷ�����޸����� �󵨴�ӡ 
    printf("%d, %d\n", p->x, p->y);
}
