#include <stdio.h>
#define PI 3.14  //������ ; ��Ϊ����C���ԵĶ��� 
#define PT printf("%.2f\n", PI); \
		printf("%.2f\n", PI * 2);
 //û��ֵ�ĺ� �������� 
#define cube(x) ((x) * (x) * (x)) //�������ֵ�ÿ���ط���Ҫ���� 

int main() {
	int i;
	scanf("%d", &i);
	PT;
	printf("%d\n",	cube(i + 2));
	return 0;
}
 
