#include <stdio.h>

struct date {
	int month;
	int day;
	int year;
};//分号不能漏掉 
	
struct point{//去掉则为无名结构 
	int x;
	int y;
}p1, p2;//p1p2都是point里面有x和y的值 

int main(int argc, char const *argv[]) {
	
	struct date t1;
	t1.month = 9;//访问其成员  
	t1.day = 22;
	t1.year = 2025; 
	printf("今天是%i-%i-%i.\n", t1.month, t1.day, t1.year);
	struct date t2 = { 9, 22, 2024};
	printf("去年的今天是%i-%i-%i.\n", t2.month, t2.day, t2.year);
	struct date t3 = {.month = 9, .year = 2024};//没给的值填0 
	printf("去年的今天是%i-%i-%i.\n", t3.month, t3.day, t3.year); 
	p1 = (struct point) {5,10}; //p1.x = 5 p1.y = 10
	p1 = p2; // p1.x = p2.x p1.y = p2.y
	//但是数组不可以！因为里面是const 
	struct date *p = &t1;
	printf("今天是%i-%i-%i.\n", p->month, p->day, p->year);
	  
	 
}
