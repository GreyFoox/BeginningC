/*˼·������
ʹ������ѭ�������к��еĴ�ӡ
���ѭ�������������ڲ�ѭ������ÿ�д�ӡ���Ǻ�����
ͨ�������жϿ����Ǻź�Ŀո����һ���ǻ��з�

˼·����������ȷ����ȱ�ٶ�ǰ���ո�Ĵ������������ʽ������Ҫ��*/

#include <stdio.h>

int main () {
	int index = 4;
	for(int i = 0; i < 4; i++) {
		// ԭ������룺ȱ��ǰ���ո��ӡ
		// ��ȷ���룺���ǰ���ո��ӡ
		for(int k = 0; k < i; k++) {
			printf(" ");
		}
		
		for(int j = index; j >= 1; j--) {
			if(j != 1) {
				printf("* "); 
			}else {
				printf("*\n");
			}
		}
		index--;
	}
	return 0;
}

/*
�Ż�����1�������ո���汾
#include <stdio.h>

int main() {
    int rows = 4;
    
    for(int i = 0; i < rows; i++) {
        // ��ӡǰ���ո�
        for(int j = 0; j < i; j++) {
            printf(" ");
        }
        // ��ӡ�ǺźͿո�
        for(int j = 0; j < rows - i; j++) {
            if(j < rows - i - 1) {
                printf("* ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    
    return 0;
}

�ŵ㣺��ʽ��ȫ��ȷ�����������׶�
ȱ�㣺ʹ��������ѭ�������Ը���
���÷�Χ����Ҫ�ϸ���������ʽҪ��ĳ���

�Ż�����2���򻯰汾
#include <stdio.h>

int main() {
    printf("* * * *\n");
    printf(" * * *\n");
    printf("  * *\n");
    printf("   *\n");
    return 0;
}

�ŵ㣺���뼫���࣬����Ч�ʸ�
ȱ�㣺Ӳ���������ȱ�������
���÷�Χ�������ʽ�̶��Ҳ���Ҫ�޸ĵĳ���

�Ż�����3��ͨ�ð汾
#include <stdio.h>

int main() {
    int n = 4;
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for(int j = 0; j < i; j++) {
            printf("*");
            if(j < i - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}

�ŵ㣺�ɵ��������С�����븴����ǿ
ȱ�㣺���ֱ������Ը���
���÷�Χ����Ҫ�����������С�ĳ���
*/
