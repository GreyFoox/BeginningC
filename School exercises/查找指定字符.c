/*
˼·������
��һ���Ǵ������ַ� -> getchar()
�ڶ������ַ��� -> fgets()
����±� -> �ҵ���һ�������� Ҫ��������  
*/

#include <stdio.h>
#include <string.h>

int main() {
	char c;
	c = getchar();
	
	// �ؼ����⣺��Ҫ��ȡ��һ�������Ļ��з�
	// ����fgets��ֱ�Ӷ�ȡ������з��������ǵڶ��е��ַ���
	getchar(); // ��ȡ��һ�������Ļ��з�
	
	char str[81];
    fgets(str, 81, stdin);
    
    // ԭ������룺
    // int index = 0;
    // int flag = 1;
    // for(int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
    //     char c0 = str[i];
    //     if(c0 == c) {
    // 		index = i;
    // 		flag = 0;
    //     }
    // }
    // if(flag) {
    // 	printf("Not Found");
    // }
    // ����ԭ��
    // 1. ������index��flag������ȷ
    // 2. �����ʽ����ȷ��Ӧ����"index = �±�"
    // 3. ȱ�ٳɹ��ҵ�ʱ��������
    // 4. ��ǰ������ң��ҵ��������һ��ƥ�����Ч�ʲ���Ӻ���ǰ����
    
    // ��ȷ���루�ο���վ���Ż�����
    int index = -1; // ��ʼ��Ϊ-1����ʾδ�ҵ�
    int length = strlen(str);
    
    // �Ӻ���ǰ���ң��ҵ��ĵ�һ��ƥ�����������±�
    for(int i = length - 1; i >= 0; i--) {
        if(str[i] == c) {
            index = i;
            break; // �ҵ��������˳�ѭ��
        }
    }
    
    if(index != -1) {
        printf("index = %d", index);
    } else {
        printf("Not Found");
    }
    
    return 0;
}

/*
�Ż�����1��ʹ��strrchr���������ࣩ
#include <stdio.h>
#include <string.h>

int main() {
    char c;
    c = getchar();
    getchar(); // ��ȡ���з�
    
    char str[81];
    fgets(str, 81, stdin);
    
    // ʹ��strrchr�����ַ����һ�γ��ֵ�λ��
    char *pos = strrchr(str, c);
    
    if(pos != NULL) {
        printf("index = %ld", pos - str); // ָ������õ��±�
    } else {
        printf("Not Found");
    }
    
    return 0;
}

�ŵ㣺�����࣬ʹ�ñ�׼�⺯��
ȱ�㣺��Ҫ���ָ������

�Ż�����2��ʹ��do-whileѭ���Ӻ���ǰ����
#include <stdio.h>
#include <string.h>

int main() {
    char c;
    c = getchar();
    getchar(); // ��ȡ���з�
    
    char str[81];
    fgets(str, 81, stdin);
    
    int index = -1;
    int i = strlen(str) - 1;
    
    do {
        if(str[i] == c) {
            index = i;
            break;
        }
        i--;
    } while(i >= 0);
    
    if(index != -1) {
        printf("index = %d", index);
    } else {
        printf("Not Found");
    }
    
    return 0;
}

�ŵ㣺ѭ���ṹ����
ȱ�㣺��forѭ�����û����������

�Ż�����3����ʹ��string.h�⺯��
#include <stdio.h>

int main() {
    char c;
    c = getchar();
    getchar(); // ��ȡ���з�
    
    char str[81];
    fgets(str, 81, stdin);
    
    int index = -1;
    int i = 0;
    
    // ���ҵ��ַ���ĩβ
    while(str[i] != '\0') {
        i++;
    }
    
    // �Ӻ���ǰ����
    for(int j = i - 1; j >= 0; j--) {
        if(str[j] == c) {
            index = j;
            break;
        }
    }
    
    if(index != -1) {
        printf("index = %d", index);
    } else {
        printf("Not Found");
    }
    
    return 0;
}

�ŵ㣺������string.h��
ȱ�㣺��Ҫ�Լ������ַ�������
*/
