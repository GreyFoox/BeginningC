/*思路分析：
输入n个数 -> scanf（正确）
有空格怎么办 -> C语言获取（表述不清晰，应该是用循环读取整数）
存入数组 -> fgets（错误，应该用循环读取整数到整型数组）
遍历到目标截止（正确）
notfind -> flag（正确，但代码中使用了直接返回的方式）*/

#include <stdio.h>
#include <string.h>

int main() {
	int n,x;
	// 原错误代码：
	// scanf("%d &d", &n, &x);
	// 错误原因：格式字符串错误，应该是"%d %d"而不是"%d &d"
	scanf("%d %d", &n, &x);
	
	// 原错误代码：
	// char c[21];
	// 错误原因：应该使用整型数组而不是字符数组，因为输入的是整数
	int arr[21]; // 修正为整型数组，最多20个元素
	
	for(int i = 0; i < n; i++) {
		int m;
		scanf("%d", &m);
		arr[i] = m; // 修正为存储到整型数组
	}
	
	int found = 0; // 添加标志变量
	for(int i = 0; i < n; i++) {
		if(x == arr[i]) { // 修正为使用整型数组
			printf("%d", i);
			found = 1;
			break; // 找到后退出循环
		} 
	} 
	
	if(!found) {
		printf("Not Found");
	}
	return 0;
}

/*
优化方案1：使用函数封装查找逻辑
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

优点：代码结构清晰，可复用性强
缺点：增加函数调用开销

优化方案2：使用指针遍历
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

优点：使用指针遍历，效率稍高
缺点：代码可读性稍差

优化方案3：使用while循环
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

优点：循环结构更灵活
缺点：与for循环相比没有明显优势
*/
