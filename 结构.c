#include <stdio.h>

struct date {
	int month;
	int day;
	int year;
};//�ֺŲ���©�� 
	
struct point{//ȥ����Ϊ�����ṹ 
	int x;
	int y;
}p1, p2;//p1p2����point������x��y��ֵ 

int main(int argc, char const *argv[]) {
	
	struct date t1;
	t1.month = 9;//�������Ա  
	t1.day = 22;
	t1.year = 2025; 
	printf("������%i-%i-%i.\n", t1.month, t1.day, t1.year);
	struct date t2 = { 9, 22, 2024};
	printf("ȥ��Ľ�����%i-%i-%i.\n", t2.month, t2.day, t2.year);
	struct date t3 = {.month = 9, .year = 2024};//û����ֵ��0 
	printf("ȥ��Ľ�����%i-%i-%i.\n", t3.month, t3.day, t3.year); 
	p1 = (struct point) {5,10}; //p1.x = 5 p1.y = 10
	p1 = p2; // p1.x = p2.x p1.y = p2.y
	//�������鲻���ԣ���Ϊ������const 
	struct date *p = &t1;
	printf("������%i-%i-%i.\n", p->month, p->day, p->year);
	  
	 
}
