#include <stdio.h>

typedef union {
	int a;
	char b;
} A;
	/*��ʡ�ڴ棺����Ҫ�洢һ�鲻ͬ���͵�����
	��ͬʱֻʹ������һ��ʱ����������Խ�ʡ�ڴ�ռ䡣*/
int main(int argc, char const *argv[]) {
	A n;
	n.a = 114514;
	return 0;	 
	  
 
}
