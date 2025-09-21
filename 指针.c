# include <stdio.h>
//指针： 保存地址的变量
 
int i;
int* p; //强调int* 是“整型指针” 
int *q; //强调m是指针 
// *p是一个 int，而不是 p 是一个int*
 
void f(int *p);
void g(int k);

int main() {
	int i = 6;
	printf("&i = %p\n", &i);//打印地址值 
	f(&i);//发现地址值相同，传入成功 
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
