/*˼·������
0 - 999
��ô������λ�� 
��λ��
һλ��
0 / ��λ��0 ��ô��? ->��Ŀ˵�˸�λ��Ϊ0 
���� -> BB(����B) -> forѭ����ӡ 
��ʮ -> ͬ��
���� -> 1-n -> forѭ����ӡ
��ȡ������λ����*/

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

// ʹ�÷�ʽ
printDigits(bai, 'B');
printDigits(shi, 'S');
*/
