#include <stdio.h>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;	
}

int* reverse(int nums[], int size) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		swap(&nums[left++], &nums[right--]);
	}
	return nums;
}

int main() {
	int n;
	scanf("%d", &n);
	int nums[n];
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		nums[i] = tmp;
	}
	reverse(nums, n);
	for (int i = 0; i < n - 1; i++) {
		printf("%d ", nums[i]);
	}
	printf("%d\n", nums[n - 1]);
	return 0;
}
