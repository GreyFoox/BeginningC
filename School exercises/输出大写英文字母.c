/*思路分析：
仅讨论大写字母
每个大写字符出现一遍 -> 大写字母去重 -> 新列表只加入列表里没有的内容（原注释正确）
没有要输出（原注释正确，但没有实现相关逻辑）*/

#include <stdio.h>
#include <string.h>
int main() {
	char s1[81];
	fgets(s1, 81, stdin);
	char s2[81];
	int index = 0;
	
	// 初始化s2数组，避免未定义行为
	for(int i = 0; i < 81; i++) {
		s2[i] = '\0';
	}
	
	// 原错误代码：
	// for(int i = 0; i < strlen(s1); i++) {
	// 	if(s1[i] >= 'A' && s2[i] <= 'Z') { // 错误：应该是s1[i] <= 'Z'
	// 		for(int j = 0; j < strlen(s2); j++) {
	// 			if(s1[i] == s2[j]) {
	// 				break;
	// 			}
	// 		} 
	// 		else { // 错误：C语言中for循环不能直接与else搭配
	// 			s2[index] = s1[i];
	// 			index++;
	// 		}
	// 	}
	// }
	
	// 正确代码：
	for(int i = 0; i < strlen(s1); i++) {
		if(s1[i] >= 'A' && s1[i] <= 'Z') { // 修正条件判断
			int found = 0; // 标记是否已存在
			for(int j = 0; j < index; j++) { // 只需遍历到index位置
				if(s1[i] == s2[j]) {
					found = 1;
					break;
				}
			}
			if(!found) { // 如果没找到，则添加到s2
				s2[index] = s1[i];
				index++;
			}
		}
	}
	
	// 原错误输出代码：
	// for(int i = 0; i < strlen(s2); i++) {
	// 		if(s2[i] != '\0') {
	// 			break;
	// 		} 
	// 		printf("%c", s2[i]);
	// }
	
	// 正确输出代码：
	if(index == 0) {
		printf("Not Found");
	} else {
		for(int i = 0; i < index; i++) {
			printf("%c", s2[i]);
		}
	}
	
	return 0;
}

/*
优化方案1：使用标记数组（更高效）
#include <stdio.h>
#include <string.h>

int main() {
    char s1[81];
    fgets(s1, 81, stdin);
    
    // 使用标记数组记录哪些大写字母已经出现过
    int appeared[26] = {0}; // 对应A-Z
    int hasUpper = 0; // 标记是否有大写字母
    
    for(int i = 0; i < strlen(s1); i++) {
        if(s1[i] >= 'A' && s1[i] <= 'Z') {
            int idx = s1[i] - 'A'; // 计算字母在数组中的索引
            if(!appeared[idx]) {
                appeared[idx] = 1; // 标记为已出现
                printf("%c", s1[i]); // 直接输出，因为按输入顺序
                hasUpper = 1;
            }
        }
    }
    
    if(!hasUpper) {
        printf("Not Found");
    }
    
    return 0;
}

优点：时间复杂度从O(n^2)降到O(n)，空间换时间
缺点：需要额外的标记数组

优化方案2：使用位运算标记（节省空间）
#include <stdio.h>
#include <string.h>

int main() {
    char s1[81];
    fgets(s1, 81, stdin);
    
    // 使用一个32位整数作为位标记（26个字母只需26位）
    unsigned int appeared = 0;
    int hasUpper = 0;
    
    for(int i = 0; i < strlen(s1); i++) {
        if(s1[i] >= 'A' && s1[i] <= 'Z') {
            int bit = 1 << (s1[i] - 'A'); // 计算对应的位
            if(!(appeared & bit)) {
                appeared |= bit; // 设置对应的位
                printf("%c", s1[i]);
                hasUpper = 1;
            }
        }
    }
    
    if(!hasUpper) {
        printf("Not Found");
    }
    
    return 0;
}

优点：空间效率高，只需要一个整数
缺点：代码可读性稍差

优化方案3：使用指针遍历
#include <stdio.h>
#include <string.h>

int main() {
    char s1[81];
    fgets(s1, 81, stdin);
    char result[81] = {0};
    int index = 0;
    
    char *p = s1;
    while(*p != '\0' && *p != '\n') {
        if(*p >= 'A' && *p <= 'Z') {
            // 检查是否已经在结果中
            int found = 0;
            for(int i = 0; i < index; i++) {
                if(result[i] == *p) {
                    found = 1;
                    break;
                }
            }
            if(!found) {
                result[index++] = *p;
            }
        }
        p++;
    }
    
    if(index == 0) {
        printf("Not Found");
    } else {
        printf("%s", result);
    }
    
    return 0;
}

优点：使用指针遍历更高效
缺点：去重逻辑仍然是O(n^2)
*/
