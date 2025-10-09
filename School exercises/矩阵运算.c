/*分析题目：
使用二维数组 
n*n方阵 -> 4*4
右上至左下 -> 1-4,4-1 
最后一列 -> x,4
最后一行 -> 4,x
但是注意是从0开始的 
除上述给出之和 直接遍历*/

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
		 	// 原错误条件判断：
		 	// if(i == n-1 || j == n-1 || (i == n-2 -(n -3) && j == n-2) || (i == n-2 && j == n-2 -(n - 3))) {
		 	// 错误原因：副对角线的判断过于复杂且有误，只考虑了n=4的特殊情况，没有通用性
		 	
		 	// 正确的条件判断：排除最后一行、最后一列和副对角线
		 	if(i == n-1 || j == n-1 || i + j == n-1) {
		 		//副对角线是从右上角到左下角，即元素位置满足 i + j = n - 1。
		 		// 跳过这些元素
			 } else{
			 	sum += arr[i][j];
			 }
		}	
	}
	printf("%d", sum);
	return 0;
}

/*
优化方案1：直接计算法（推荐）
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
    // 只遍历需要保留的区域，避免复杂判断
    for(int i = 0; i < n-1; i++) {          // 排除最后一行
        for(int j = 0; j < n-1; j++) {      // 排除最后一列
            if(i + j != n-1) {              // 排除副对角线
                sum += arr[i][j];
            }
        }
    }
    printf("%d", sum);
    return 0;
}

优点：代码简洁，效率高，只需要遍历(n-1)×(n-1)次
缺点：需要理解循环边界条件

优化方案2：反向排除法
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][n];
    int total = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            total += arr[i][j];  // 计算总和
        }
    }
    
    int exclude = 0;
    // 计算需要排除的部分
    for(int i = 0; i < n; i++) {
        exclude += arr[i][n-1];      // 最后一列
        exclude += arr[n-1][i];      // 最后一行
        exclude += arr[i][n-1-i];    // 副对角线
    }
    
    // 减去重复计算的部分
    exclude -= arr[n-1][n-1];        // 右下角被重复计算2次
    exclude -= arr[n-1][0];          // 左下角被重复计算1次
    exclude -= arr[0][n-1];          // 右上角被重复计算1次
    
    int sum = total - exclude;
    printf("%d", sum);
    return 0;
}

优点：逻辑清晰，易于调试
缺点：需要遍历矩阵两次，效率稍低
*/
