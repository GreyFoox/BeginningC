/*˼·������
����n���� -> scanf����ȷ��
�пո���ô�� -> C���Ի�ȡ��������������Ӧ������ѭ����ȡ������
�������� -> fgets������Ӧ����ѭ����ȡ�������������飩
������Ŀ���ֹ����ȷ��
notfind -> flag����ȷ����������ʹ����ֱ�ӷ��صķ�ʽ��*/

#include <stdio.h>
#include <string.h>

int main() {
	int n,x;
	// ԭ������룺
	// scanf("%d &d", &n, &x);
	// ����ԭ�򣺸�ʽ�ַ�������Ӧ����"%d %d"������"%d &d"
	scanf("%d %d", &n, &x);
	
	// ԭ������룺
	// char c[21];
	// ����ԭ��Ӧ��ʹ����������������ַ����飬��Ϊ�����������
	int arr[21]; // ����Ϊ�������飬���20��Ԫ��
	
	for(int i = 0; i < n; i++) {
		int m;
		scanf("%d", &m);
		arr[i] = m; // ����Ϊ�洢����������
	}
	
	int found = 0; // ��ӱ�־����
	for(int i = 0; i < n; i++) {
		if(x == arr[i]) { // ����Ϊʹ����������
			printf("%d", i);
			found = 1;
			break; // �ҵ����˳�ѭ��
		} 
	} 
	
	if(!found) {
		printf("Not Found");
	}
	return 0;
}

/*
�Ż�����1��ʹ�ú�����װ�����߼�
#include <stdio.h>

int findIndex(int arr[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int arr[21];
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int result = findIndex(arr, n, x);
    if(result != -1) {
        printf("%d", result);
    } else {
        printf("Not Found");
    }
    
    return 0;
}

�ŵ㣺����ṹ�������ɸ�����ǿ
ȱ�㣺���Ӻ������ÿ���

�Ż�����2��ʹ��ָ�����
#include <stdio.h>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int arr[21];
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int *p = arr;
    for(int i = 0; i < n; i++) {
        if(*p == x) {
            printf("%d", i);
            return 0;
        }
        p++;
    }
    
    printf("Not Found");
    return 0;
}

�ŵ㣺ʹ��ָ�������Ч���Ը�
ȱ�㣺����ɶ����Բ�

�Ż�����3��ʹ��whileѭ��
#include <stdio.h>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int arr[21];
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int i = 0;
    while(i < n) {
        if(arr[i] == x) {
            printf("%d", i);
            return 0;
        }
        i++;
    }
    
    printf("Not Found");
    return 0;
}

�ŵ㣺ѭ���ṹ�����
ȱ�㣺��forѭ�����û����������
*/
