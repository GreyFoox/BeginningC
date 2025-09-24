#include <stdio.h>
#define PI 3.14  //不可以 ; 因为不是C语言的东西 
#define PT printf("%.2f\n", PI); \
		printf("%.2f\n", PI * 2);
 //没有值的宏 条件编译 
#define cube(x) ((x) * (x) * (x)) //

int main() {
	int i;
	scanf("%d", &i);
	PT;
	printf("%d\n",	cube(i + 2));
	return 0;
}
 
