#include <stdio.h>

int reverse( int number );
    
int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", reverse(n));

    return 0;
}

int reverse(int number) {
	int result = 0;
	while(number) {
		int i = number % 10;
		result = result * 10 + i;
		number /= 10; 
	}
	return result;
}  
