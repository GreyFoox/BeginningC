/*˼·������
���� + �ո� ������ĩβ�޿ո�
scanfһֱ¼ ֱ��\n Ϊֹ 
����ɱ����� 
�ܳ��Ȳ�����80
���� -> forѭ������������

˼·����������ȷ���������������⣺
1. "scanfһֱ¼ ֱ��\n Ϊֹ" - scanf��ȡ�ַ���ʱ�����ո�ͻ�ֹͣ�������Զ���⻻�з�
2. "����ɱ�����" - C����û�����õĿɱ����飬��Ҫ�ֶ�����
3. ԭ�������ַ�����ֵ������ʹ�÷�ʽ����*/

#include <stdio.h>
#include <string.h>

int main() {
	char word[81];
	// ԭ������룺
	// char r_sentence[] = {"\0"};
	// ����ԭ�������Сδָ���ҳ�ʼ����ʽ�����޷��洢�������
	char r_sentence[40][81]; // ��ȷ���룺��ά�ַ�����洢�������
	int index = 0;
	
	// ԭ������룺
	// while(scanf("%s", &word) != 0) {
	// 	r_sentence[index] = word;
	// 	index++;
	// }
	// ����ԭ��1. scanf����ֵ�жϴ��� 2. ����ֱ�ӽ��ַ�����ֵ������Ԫ�� 3. ȱ���˳�ѭ��������
	
	// ��ȷ���룺
	while(scanf("%s", word) == 1) { // scanf�ɹ���ȡ����1
	// ˵�������ﲻ��Ҫ��&����Ϊ������������ǵ�ַ
    // word �ȼ��� &word[0]������ֱ��ʹ��word����
		strcpy(r_sentence[index], word); // ʹ��strcpy�����ַ���
		index++;
		/*����
		������ strcpy() ������������
		char *strcpy(char *dest, const char *src)
		����
		dest -- ָ�����ڴ洢�������ݵ�Ŀ�����顣
		src -- Ҫ���Ƶ��ַ�����*/
		
		// scanf�����ո�ֹͣ����ʱ���뻺�����л��У�" \n"
		// �����һ���ַ��Ƿ�Ϊ���з�
		int c = getchar();

		if(c == '\n') break;
	}
	
	// ԭ������룺
	// for(int i = index; i >= 0; i--) {
	// 	if(i != 0) {
	// 		printf("%s ", r_sentence[i]);
	// 	} else {
	// 		printf("%s", r_sentence[i]);
	// 	}
	// }
	// ����ԭ��1. ��ʼ����Ӧ����index-1������index 2. ������r_sentence[index]Խ��
	
	// ��ȷ���룺
	for(int i = index - 1; i >= 0; i--) {
		printf("%s", r_sentence[i]);
		if(i > 0) {
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}

/*
�Ż�����1��ʹ��ָ�����鶯̬����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 40
#define MAX_WORD_LEN 80

int main() {
    char word[MAX_WORD_LEN + 1];
    char *words[MAX_WORDS];
    int count = 0;
    
    while(scanf("%s", word) == 1 && count < MAX_WORDS) {
        words[count] = malloc(strlen(word) + 1);
        strcpy(words[count], word);
        count++;
        
        int c = getchar();
        if(c == '\n') break;
    }
    
    for(int i = count - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if(i > 0) printf(" ");
        free(words[i]); // �ͷ��ڴ�
    }
    printf("\n");
    
    return 0;
}

�ŵ㣺�ڴ�ʹ�ø���Ч��ֻ����ʵ����Ҫ�Ŀռ�
ȱ�㣺��Ҫ�ֶ������ڴ棬�����Ը���
���÷�Χ�����ʳ��Ȳ�������ڴ����еĳ���

�Ż�����2�����α������������ջ˼�룩
#include <stdio.h>
#include <string.h>

void printReverse() {
    char word[81];
    if(scanf("%s", word) != 1) return;
    
    int c = getchar();
    if(c != '\n' && c != EOF) {
        printReverse(); // �ݹ�����ȴ������ĵ���
    }
    
    printf("%s", word);
    if(c != '\n' && c != EOF) printf(" ");
}

int main() {
    printReverse();
    printf("\n");
    return 0;
}

�ŵ㣺����Ҫ�洢���е��ʣ���ʡ�ռ�
ȱ�㣺�ݹ������ջ��С���ƣ�����ջ���
���÷�Χ���������������ҿռ����޵ĳ���

�Ż�����3��ʹ��fgets��strtok�ָ��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 81

int main() {
    char line[MAX_LEN];
    char *words[40];
    int count = 0;
    
    // һ���Զ�ȡ����
    if(fgets(line, MAX_LEN, stdin) != NULL) {
        // �Ƴ����з�
        line[strcspn(line, "\n")] = '\0';
        
        // ʹ��strtok�ָ��
        char *token = strtok(line, " ");
        while(token != NULL && count < 40) {
            words[count++] = token;
            token = strtok(NULL, " ");
        }
        
        // �������
        for(int i = count - 1; i >= 0; i--) {
            printf("%s", words[i]);
            if(i > 0) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}

�ŵ㣺�����࣬һ�ζ�ȡ��������
ȱ�㣺�޸���ԭʼ�����ַ�����strtok���̰߳�ȫ
���÷�Χ����Ӧ�ã�����Ҫ����ԭʼ�ַ����ĳ���
*/
