/*思路分析：
0 - 999
那么就有三位数 
两位数
一位数
0 / 个位是0 怎么办? ->题目说了个位不为0 
几百 -> BB(几个B) -> for循环打印 
几十 -> 同理
几个 -> 1-n -> for循环打印
先取出各个位的数*/

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int ge = n % 10;
	int shi = n /10 % 10;
	int bai = n /100 % 10;
	if(bai != 0) {
		for(int i = 0; i < bai; i++) {
			printf("B");
		}
	}
		
	if(shi != 0) {
		for(int i = 0; i < shi; i++) {
			printf("S");
		}
	}
	
	if (ge != 0){
		for(int i = 0; i < ge; i++) {
			printf("%d", i+1);
		}
	}
	printf("\n");
	return 0;
} 
/*void printDigits(int count, char symbol) {
    for(int i = 0; i < count; i++) {
        printf("%c", symbol);
    }
}

// 使用方式
printDigits(bai, 'B');
printDigits(shi, 'S');
*/
