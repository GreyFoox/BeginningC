#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int nums[n];
	int num;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		nums[i] = num;
	} 
	int max = -1;
	int max_num = 0;
	int tmp_num = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] == max) continue;
		for (int j = 0; j < n; j++) {
			if (nums[j] == nums[i]) {
				tmp_num++;
			}
		}
		if (tmp_num > max_num) {
			max = nums[i];
			max_num = tmp_num;
		}
		tmp_num = 0;
	}
	printf("%d %d\n", max, max_num);
	return 0;
} 
