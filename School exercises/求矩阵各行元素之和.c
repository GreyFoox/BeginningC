/*思路分析：
m行 n列 -> scanf 
双循环存到mums[m][n]
每行之和 -> sum[m]
最后遍历打印 */

#include <stdio.h>

int main() {
	int m, n;
	scanf("%d", &m, &n );
	int nums[m][n];
	int sumarr[m];
	for(int i = 0; i < m; i++) {
		int sum = 0;
		for(int j = 0; j < n; j++) {
    		scanf("%d", &nums[i][j]);
    		sum += nums[i][j];	
		}
		sumarr[i] = sum;
    }
    for (int i = 0; i < m; i++) {
    	printf("%d\n", sumarr[i]);	
	}
}


