#include <stdio.h>
#define PI 3.14  //不可以 ; 因为不是C语言的东西 
#define PT printf("%.2f\n", PI); \
		printf("%.2f\n", PI * 2);
 //没有值的宏 条件编译 
#define cube(x) ((x) * (x) * (x)) //参数出现的每个地方都要括号 

int main() {
	int i;
	scanf("%d", &i);
	PT;
	printf("%d\n",	cube(i + 2));
	return 0;
}
 
