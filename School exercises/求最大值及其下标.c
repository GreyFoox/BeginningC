/*思路分析：
n （1-10） -> scanf
输入n个数 -> 遍历 数组存储 
最大值 ->  同步遍历 两两比大小
最小下标识 -> 到第一个最大直接停止*/

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
