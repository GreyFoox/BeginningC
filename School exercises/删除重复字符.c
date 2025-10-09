/*˼·������
ȥ�ز��� -> �½����� ���ڲ���� ���뷨���ɲ�����ʹ��set()�� ��C����û������set����Ҫ�Լ�ʵ�֣�
����ASCII������ -> ʹ��ð��������ȷ������Ҫʵ�������߼���*/

#include <stdio.h>
#include <string.h>

int main() {
	char s1[81];
	fgets(s1, 81, stdin);
	
	// ԭ������룺
	// ȱ���Ƴ�fgets��ȡ�Ļ��з��Ĳ���
	// ��ᵼ�¸�ʽ������Ϊ���з�Ҳ�ᱻ����
	
	// ��ȷ���룺�Ƴ�fgets��ȡ�Ļ��з�
	int len = strlen(s1);
	if(len > 0 && s1[len-1] == '\n') {
		s1[len-1] = '\0';
		len--; // ���³���
	}
	
	char s2[81];
	int index = 0;
	
	// ��ʼ��s2����
	for(int i = 0; i < 81; i++) {
		s2[i] = '\0';
	}
	
	// ȥ�ز���
	for(int i = 0; i < len; i++) {
		int found = 0; // ÿ�μ�����ַ�ǰ����found
		for(int j = 0; j < index; j++) { 
			if(s1[i] == s2[j]) {
				found = 1;
				break;
			}
		}
		if(!found) { 
			s2[index] = s1[i];
			index++;
		}
	}
	
	// ���ð������
	for(int i = 0; i < index - 1; i++) {
		for(int j = 0; j < index - 1 - i; j++) {
			if(s2[j] > s2[j+1]) {
				// �����ַ�
				char temp = s2[j];
				s2[j] = s2[j+1];
				s2[j+1] = temp;
			}
		}
	}
	
	// ������
	printf("%s", s2);
	
	return 0;
}

/*
�Ż�����1���������򷨣��Ƽ���
#include <stdio.h>
#include <string.h>

int main() {
    char s1[81];
    fgets(s1, 81, stdin);
    
    // �Ƴ����з�
    int len = strlen(s1);
    if(len > 0 && s1[len-1] == '\n') {
        s1[len-1] = '\0';
        len--;
    }
    
    // ʹ�ü��������¼ÿ���ַ��Ƿ����
    int count[128] = {0}; // ASCII�뷶Χ0-127
    
    // ��ǳ��ֵ��ַ�
    for(int i = 0; i < len; i++) {
        count[s1[i]] = 1;
    }
    
    // ��ASCII��˳�����
    for(int i = 0; i < 128; i++) {
        if(count[i] == 1) {
            printf("%c", i);
        }
    }
    
    return 0;
}

�ŵ㣺ʱ�临�Ӷ�O(n)��Ч�����
ȱ�㣺��Ҫ����ļ�������

�Ż�����2����������ȥ��
#include <stdio.h>
#include <string.h>

int main() {
    char s1[81];
    fgets(s1, 81, stdin);
    
    // �Ƴ����з�
    int len = strlen(s1);
    if(len > 0 && s1[len-1] == '\n') {
        s1[len-1] = '\0';
        len--;
    }
    
    // �ȶ�ԭ�ַ�����������
    for(int i = 0; i < len - 1; i++) {
        for(int j = 0; j < len - 1 - i; j++) {
            if(s1[j] > s1[j+1]) {
                char temp = s1[j];
                s1[j] = s1[j+1];
                s1[j+1] = temp;
            }
        }
    }
    
    // ��ȥ�أ������������ظ��ַ������ڣ�
    char result[81] = {0};
    int index = 0;
    
    for(int i = 0; i < len; i++) {
        // ����ǵ�һ���ַ������ߵ�ǰ�ַ���ǰһ����ͬ�������
        if(i == 0 || s1[i] != s1[i-1]) {
            result[index++] = s1[i];
        }
    }
    
    printf("%s", result);
    return 0;
}

�ŵ㣺ȥ���߼�����
ȱ�㣺�ı���ԭ�ַ�����˳��

�Ż�����3��ʹ��λ����ǣ���ʡ�ռ䣩
#include <stdio.h>
#include <string.h>

int main() {
    char s1[81];
    fgets(s1, 81, stdin);
    
    // �Ƴ����з�
    int len = strlen(s1);
    if(len > 0 && s1[len-1] == '\n') {
        s1[len-1] = '\0';
        len--;
    }
    
    // ʹ��4��32λ������Ϊλ��ǣ�128λ��Ӧ128��ASCII�ַ���
    unsigned int bitset[4] = {0};
    
    // ��ǳ��ֵ��ַ�
    for(int i = 0; i < len; i++) {
        int ascii = s1[i];
        int index = ascii / 32;
        int bit = 1 << (ascii % 32);
        bitset[index] |= bit;
    }
    
    // ��ASCII��˳�����
    for(int i = 0; i < 128; i++) {
        int index = i / 32;
        int bit = 1 << (i % 32);
        if(bitset[index] & bit) {
            printf("%c", i);
        }
    }
    
    return 0;
}

�ŵ㣺�ռ�Ч�ʸߣ�ֻ��Ҫ4������
ȱ�㣺����ɶ��Բ��Ҫ���λ����
*/
