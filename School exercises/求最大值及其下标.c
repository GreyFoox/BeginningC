/*˼·������
n ��1-10�� -> scanf
����n���� -> ���� ����洢 
���ֵ ->  ͬ������ �����ȴ�С
��С�±�ʶ -> ����һ�����ֱ��ֹͣ*/

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int nums[10];
	int m;
	int index = 0;
	for(int i = 0; i < n; i++) {
		nums[index] = m;
		index++;
	}
	int max = nums[0]; 
	for(int j = 0; j < n; j++) {
		if(nums[j] >= max) {
			max = nums[j];
		}
	}
	printf("%d ", max);
	for(int k = 0; k < n; k++) {
		if(nums[k] = max) {
			printf("%d", k);
			return; 
		}
	}
}
