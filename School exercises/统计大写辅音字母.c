/*˼·������
�ų�AEIOU
������90���ַ� 
�����ַ� -> �ַ����� 
*/

#include <stdio.h> 

int main() {
	char c;
	int sum = 0;
	
	// ԭ������룺
	// while((c = getchar())!= "\n") {
	// ����ԭ�򣺱Ƚ��ַ�Ӧ���õ�����'\n'��˫���ű�ʾ�ַ���
	// ԭ���������жϣ�
	// if(c != 'A' || c != 'E'|| c != 'I' || c != 'O'|| c != 'U') {
	// ����ԭ���߼������ʹ�ô���Ӧ����&&������||
	// ��Ϊһ���ַ�������ͬʱ����������Ԫ����ĸ�����������������Ϊ��
	
	// ��ȷ���룺
	while((c = getchar())!= '\n') {
		// �ж������������Ǵ�д��ĸ���Ҳ���Ԫ����ĸ
		if(c >= 'A' && c <= 'Z' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
			sum++;
		}
	}
	printf("%d", sum);
	return 0;
}

/*
�Ż�����1��ʹ���ַ���������
#include <stdio.h>
#include <string.h>

int main() {
    char str[81];
    int sum = 0;
    
    fgets(str, 81, stdin);  // ��ȡһ���ַ���
    
    for(int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        char c = str[i];
        // ʹ��strchr����Ƿ���Ԫ���ַ�����
        if(c >= 'A' && c <= 'Z' && strchr("AEIOU", c) == NULL) {
            sum++;
        }
    }
    printf("%d", sum);
    return 0;
}

�ŵ㣺�������������������ά��
ȱ�㣺��Ҫ����string.hͷ�ļ�

�Ż�����2��ʹ��switch���
#include <stdio.h>

int main() {
    char c;
    int sum = 0;
    
    while((c = getchar()) != '\n') {
        if(c >= 'A' && c <= 'Z') {
            switch(c) {
                case 'A': case 'E': case 'I': case 'O': case 'U':
                    break;  // �����Ԫ��������
                default:
                    sum++;  // �����Ǹ���������
            }
        }
    }
    printf("%d", sum);
    return 0;
}

�ŵ㣺�߼�������������չ
ȱ�㣺�����Գ�

�Ż�����3��ʹ��λ���㣨�߼����ɣ�
#include <stdio.h>

int main() {
    char c;
    int sum = 0;
    // ����һ��λ���룬Ԫ����ĸ��Ӧ��λ��Ϊ1
    unsigned long long vowel_mask = 0;
    vowel_mask |= 1ULL << ('A' - 'A');
    vowel_mask |= 1ULL << ('E' - 'A');
    vowel_mask |= 1ULL << ('I' - 'A');
    vowel_mask |= 1ULL << ('O' - 'A');
    vowel_mask |= 1ULL << ('U' - 'A');
    
    while((c = getchar()) != '\n') {
        if(c >= 'A' && c <= 'Z') {
            // ������ĸ��Ӧ��λ�Ƿ�Ϊ0������Ԫ����
            if(!(vowel_mask & (1ULL << (c - 'A')))) {
                sum++;
            }
        }
    }
    printf("%d", sum);
    return 0;
}

�ŵ㣺��ѯ�ٶȿ죬�ʺϴ�������
ȱ�㣺���븴�ӣ��ɶ��Բ�
*/
