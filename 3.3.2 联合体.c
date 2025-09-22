#include <stdio.h>

typedef union {
	int a;
	char b;
} A;
	/*节省内存：当需要存储一组不同类型的数据
	但同时只使用其中一个时，联合体可以节省内存空间。*/
int main(int argc, char const *argv[]) {
	A n;
	n.a = 114514;
	return 0;	 
	  
 
}
