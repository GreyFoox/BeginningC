#include <stdio.h>
typedef long int64_t;//�����ָ������ҿ���ֲ 
typedef struct mydate {//�򻯸������� 
	int month;
	int day;
	int year;
}D; 
	

int main(int argc, char const *argv[]) {
	int64_t i = 4294967295; 
	D d = {9, 22, 2025};
	printf("%i-%i-%i", d.month, d.day, d.year); 
	return 0;	 
	  
 
}
