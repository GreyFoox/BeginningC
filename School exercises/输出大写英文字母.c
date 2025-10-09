/*˼·������
�����۴�д��ĸ
ÿ����д�ַ�����һ�� -> ��д��ĸȥ�� -> ���б�ֻ�����б���û�е����ݣ�ԭע����ȷ��
û��Ҫ�����ԭע����ȷ����û��ʵ������߼���*/

#include <stdio.h>
#include <string.h>
int main() {
	char s1[81];
	fgets(s1, 81, stdin);
	char s2[81];
	int index = 0;
	
	// ��ʼ��s2���飬����δ������Ϊ
	for(int i = 0; i < 81; i++) {
		s2[i] = '\0';
	}
	
	// ԭ������룺
	// for(int i = 0; i < strlen(s1); i++) {
	// 	if(s1[i] >= 'A' && s2[i] <= 'Z') { // ����Ӧ����s1[i] <= 'Z'
	// 		for(int j = 0; j < strlen(s2); j++) {
	// 			if(s1[i] == s2[j]) {
	// 				break;
	// 			}
	// 		} 
	// 		else { // ����C������forѭ������ֱ����else����
	// 			s2[index] = s1[i];
	// 			index++;
	// 		}
	// 	}
	// }
	
	// ��ȷ���룺
	for(int i = 0; i < strlen(s1); i++) {
		if(s1[i] >= 'A' && s1[i] <= 'Z') { // ���������ж�
			int found = 0; // ����Ƿ��Ѵ���
			for(int j = 0; j < index; j++) { // ֻ�������indexλ��
				if(s1[i] == s2[j]) {
					found = 1;
					break;
				}
			}
			if(!found) { // ���û�ҵ�������ӵ�s2
				s2[index] = s1[i];
				index++;
			}
		}
	}
	
	// ԭ����������룺
	// for(int i = 0; i < strlen(s2); i++) {
	// 		if(s2[i] != '\0') {
	// 			break;
	// 		} 
	// 		printf("%c", s2[i]);
	// }
	
	// ��ȷ������룺
	if(index == 0) {
		printf("Not Found");
	} else {
		for(int i = 0; i < index; i++) {
			printf("%c", s2[i]);
		}
	}
	
	return 0;
}

/*
�Ż�����1��ʹ�ñ�����飨����Ч��
#include <stdio.h>
#include <string.h>

int main() {
    char s1[81];
    fgets(s1, 81, stdin);
    
    // ʹ�ñ�������¼��Щ��д��ĸ�Ѿ����ֹ�
    int appeared[26] = {0}; // ��ӦA-Z
    int hasUpper = 0; // ����Ƿ��д�д��ĸ
    
    for(int i = 0; i < strlen(s1); i++) {
        if(s1[i] >= 'A' && s1[i] <= 'Z') {
            int idx = s1[i] - 'A'; // ������ĸ�������е�����
            if(!appeared[idx]) {
                appeared[idx] = 1; // ���Ϊ�ѳ���
                printf("%c", s1[i]); // ֱ���������Ϊ������˳��
                hasUpper = 1;
            }
        }
    }
    
    if(!hasUpper) {
        printf("Not Found");
    }
    
    return 0;
}

�ŵ㣺ʱ�临�Ӷȴ�O(n^2)����O(n)���ռ任ʱ��
ȱ�㣺��Ҫ����ı������

�Ż�����2��ʹ��λ�����ǣ���ʡ�ռ䣩
#include <stdio.h>
#include <string.h>

int main() {
    char s1[81];
    fgets(s1, 81, stdin);
    
    // ʹ��һ��32λ������Ϊλ��ǣ�26����ĸֻ��26λ��
    unsigned int appeared = 0;
    int hasUpper = 0;
    
    for(int i = 0; i < strlen(s1); i++) {
        if(s1[i] >= 'A' && s1[i] <= 'Z') {
            int bit = 1 << (s1[i] - 'A'); // �����Ӧ��λ
            if(!(appeared & bit)) {
                appeared |= bit; // ���ö�Ӧ��λ
                printf("%c", s1[i]);
                hasUpper = 1;
            }
        }
    }
    
    if(!hasUpper) {
        printf("Not Found");
    }
    
    return 0;
}

�ŵ㣺�ռ�Ч�ʸߣ�ֻ��Ҫһ������
ȱ�㣺����ɶ����Բ�

�Ż�����3��ʹ��ָ�����
#include <stdio.h>
#include <string.h>

int main() {
    char s1[81];
    fgets(s1, 81, stdin);
    char result[81] = {0};
    int index = 0;
    
    char *p = s1;
    while(*p != '\0' && *p != '\n') {
        if(*p >= 'A' && *p <= 'Z') {
            // ����Ƿ��Ѿ��ڽ����
            int found = 0;
            for(int i = 0; i < index; i++) {
                if(result[i] == *p) {
                    found = 1;
                    break;
                }
            }
            if(!found) {
                result[index++] = *p;
            }
        }
        p++;
    }
    
    if(index == 0) {
        printf("Not Found");
    } else {
        printf("%s", result);
    }
    
    return 0;
}

�ŵ㣺ʹ��ָ���������Ч
ȱ�㣺ȥ���߼���Ȼ��O(n^2)
*/
