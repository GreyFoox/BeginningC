# include <stdio.h>
//ָ�룺 �����ַ�ı���
 
int i;
int* p; //ǿ��int* �ǡ�����ָ�롱 
int *q; //ǿ��m��ָ�� 
// *p��һ�� int�������� p ��һ��int*
 
void f(int *p);
void g(int k);

int main() {
	int i = 6;
	printf("&i = %p\n", &i);//��ӡ��ֵַ 
	f(&i);//���ֵ�ֵַ��ͬ������ɹ� 
	g(i);
	return 0; 
} 

void f(int *p) {
	printf("p = %p\n", p);
	*p = 26; 
	printf("*p = %d \n", *p);
	
}

void g(int k) {
	printf("k = %d\n", k);
}
