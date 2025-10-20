/*思路分析：
使用两层循环控制行和列的打印
外层循环控制行数，内层循环控制每行打印的星号数量
通过条件判断控制星号后的空格，最后一个是换行符

思路分析基本正确，但缺少对前导空格的处理，导致输出格式不符合要求*/

#include <stdio.h>

int main () {
	int index = 4;
	for(int i = 0; i < 4; i++) {
		// 原错误代码：缺少前导空格打印
		// 正确代码：添加前导空格打印
		for(int k = 0; k < i; k++) {
			printf(" ");
		}
		
		for(int j = index; j >= 1; j--) {
			if(j != 1) {
				printf("* "); 
			}else {
				printf("*\n");
			}
		}
		index--;
	}
	return 0;
}

/*
优化方案1：完整空格处理版本
#include <stdio.h>

int main() {
    int rows = 4;
    
    for(int i = 0; i < rows; i++) {
        // 打印前导空格
        for(int j = 0; j < i; j++) {
            printf(" ");
        }
        // 打印星号和空格
        for(int j = 0; j < rows - i; j++) {
            if(j < rows - i - 1) {
                printf("* ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    
    return 0;
}

优点：格式完全正确，代码清晰易读
缺点：使用了三层循环，稍显复杂
适用范围：需要严格符合输出格式要求的场景

优化方案2：简化版本
#include <stdio.h>

int main() {
    printf("* * * *\n");
    printf(" * * *\n");
    printf("  * *\n");
    printf("   *\n");
    return 0;
}

优点：代码极其简洁，运行效率高
缺点：硬编码输出，缺乏灵活性
适用范围：输出格式固定且不需要修改的场景

优化方案3：通用版本
#include <stdio.h>

int main() {
    int n = 4;
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for(int j = 0; j < i; j++) {
            printf("*");
            if(j < i - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}

优点：可调整输出大小，代码复用性强
缺点：相对直接输出稍复杂
适用范围：需要灵活调整输出大小的场景
*/
