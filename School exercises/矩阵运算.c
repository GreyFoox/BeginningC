/*������Ŀ��
ʹ�ö�ά���� 
n*n���� -> 4*4
���������� -> 1-4,4-1 
���һ�� -> x,4
���һ�� -> 4,x
����ע���Ǵ�0��ʼ�� 
����������֮�� ֱ�ӱ���*/

#include <stdio.h>

int main() {
	int n;
	int m;
	scanf("%d", &n);
	int arr[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &m); 
			arr[i][j] = m; 
		}	
	}
	int sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
		 	// ԭ���������жϣ�
		 	// if(i == n-1 || j == n-1 || (i == n-2 -(n -3) && j == n-2) || (i == n-2 && j == n-2 -(n - 3))) {
		 	// ����ԭ�򣺸��Խ��ߵ��жϹ��ڸ���������ֻ������n=4�����������û��ͨ����
		 	
		 	// ��ȷ�������жϣ��ų����һ�С����һ�к͸��Խ���
		 	if(i == n-1 || j == n-1 || i + j == n-1) {
		 		//���Խ����Ǵ����Ͻǵ����½ǣ���Ԫ��λ������ i + j = n - 1��
		 		// ������ЩԪ��
			 } else{
			 	sum += arr[i][j];
			 }
		}	
	}
	printf("%d", sum);
	return 0;
}

/*
�Ż�����1��ֱ�Ӽ��㷨���Ƽ���
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int sum = 0;
    // ֻ������Ҫ���������򣬱��⸴���ж�
    for(int i = 0; i < n-1; i++) {          // �ų����һ��
        for(int j = 0; j < n-1; j++) {      // �ų����һ��
            if(i + j != n-1) {              // �ų����Խ���
                sum += arr[i][j];
            }
        }
    }
    printf("%d", sum);
    return 0;
}

�ŵ㣺�����࣬Ч�ʸߣ�ֻ��Ҫ����(n-1)��(n-1)��
ȱ�㣺��Ҫ���ѭ���߽�����

�Ż�����2�������ų���
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][n];
    int total = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            total += arr[i][j];  // �����ܺ�
        }
    }
    
    int exclude = 0;
    // ������Ҫ�ų��Ĳ���
    for(int i = 0; i < n; i++) {
        exclude += arr[i][n-1];      // ���һ��
        exclude += arr[n-1][i];      // ���һ��
        exclude += arr[i][n-1-i];    // ���Խ���
    }
    
    // ��ȥ�ظ�����Ĳ���
    exclude -= arr[n-1][n-1];        // ���½Ǳ��ظ�����2��
    exclude -= arr[n-1][0];          // ���½Ǳ��ظ�����1��
    exclude -= arr[0][n-1];          // ���ϽǱ��ظ�����1��
    
    int sum = total - exclude;
    printf("%d", sum);
    return 0;
}

�ŵ㣺�߼����������ڵ���
ȱ�㣺��Ҫ�����������Σ�Ч���Ե�
*/
