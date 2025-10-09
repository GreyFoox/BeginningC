/*思路分析：
去重操作 -> 新建数组 不在才添加 新想法：可不可以使用set()？ （C语言没有内置set，需要自己实现）
根据ASCII码排序 -> 使用冒泡排序（正确，但需要实现排序逻辑）*/

#include <stdio.h>
#include <string.h>

int main() {
	char s1[81];
	fgets(s1, 81, stdin);
	
	// 原错误代码：
	// 缺少移除fgets读取的换行符的步骤
	// 这会导致格式错误，因为换行符也会被处理
	
	// 正确代码：移除fgets读取的换行符
	int len = strlen(s1);
	if(len > 0 && s1[len-1] == '\n') {
		s1[len-1] = '\0';
		len--; // 更新长度
	}
	
	char s2[81];
	int index = 0;
	
	// 初始化s2数组
	for(int i = 0; i < 81; i++) {
		s2[i] = '\0';
	}
	
	// 去重操作
	for(int i = 0; i < len; i++) {
		int found = 0; // 每次检查新字符前重置found
		for(int j = 0; j < index; j++) { 
			if(s1[i] == s2[j]) {
				found = 1;
				break;
			}
		}
		if(!found) { 
			s2[index] = s1[i];
			index++;
		}
	}
	
	// 添加冒泡排序
	for(int i = 0; i < index - 1; i++) {
		for(int j = 0; j < index - 1 - i; j++) {
			if(s2[j] > s2[j+1]) {
				// 交换字符
				char temp = s2[j];
				s2[j] = s2[j+1];
				s2[j+1] = temp;
			}
		}
	}
	
	// 输出结果
	printf("%s", s2);
	
	return 0;
}

/*
优化方案1：计数排序法（推荐）
#include <stdio.h>
#include <string.h>

int main() {
    char s1[81];
    fgets(s1, 81, stdin);
    
    // 移除换行符
    int len = strlen(s1);
    if(len > 0 && s1[len-1] == '\n') {
        s1[len-1] = '\0';
        len--;
    }
    
    // 使用计数数组记录每个字符是否出现
    int count[128] = {0}; // ASCII码范围0-127
    
    // 标记出现的字符
    for(int i = 0; i < len; i++) {
        count[s1[i]] = 1;
    }
    
    // 按ASCII码顺序输出
    for(int i = 0; i < 128; i++) {
        if(count[i] == 1) {
            printf("%c", i);
        }
    }
    
    return 0;
}

优点：时间复杂度O(n)，效率最高
缺点：需要额外的计数数组

优化方案2：先排序再去重
#include <stdio.h>
#include <string.h>

int main() {
    char s1[81];
    fgets(s1, 81, stdin);
    
    // 移除换行符
    int len = strlen(s1);
    if(len > 0 && s1[len-1] == '\n') {
        s1[len-1] = '\0';
        len--;
    }
    
    // 先对原字符串进行排序
    for(int i = 0; i < len - 1; i++) {
        for(int j = 0; j < len - 1 - i; j++) {
            if(s1[j] > s1[j+1]) {
                char temp = s1[j];
                s1[j] = s1[j+1];
                s1[j+1] = temp;
            }
        }
    }
    
    // 再去重（由于已排序，重复字符会相邻）
    char result[81] = {0};
    int index = 0;
    
    for(int i = 0; i < len; i++) {
        // 如果是第一个字符，或者当前字符与前一个不同，则添加
        if(i == 0 || s1[i] != s1[i-1]) {
            result[index++] = s1[i];
        }
    }
    
    printf("%s", result);
    return 0;
}

优点：去重逻辑更简单
缺点：改变了原字符串的顺序

优化方案3：使用位集标记（节省空间）
#include <stdio.h>
#include <string.h>

int main() {
    char s1[81];
    fgets(s1, 81, stdin);
    
    // 移除换行符
    int len = strlen(s1);
    if(len > 0 && s1[len-1] == '\n') {
        s1[len-1] = '\0';
        len--;
    }
    
    // 使用4个32位整数作为位标记（128位对应128个ASCII字符）
    unsigned int bitset[4] = {0};
    
    // 标记出现的字符
    for(int i = 0; i < len; i++) {
        int ascii = s1[i];
        int index = ascii / 32;
        int bit = 1 << (ascii % 32);
        bitset[index] |= bit;
    }
    
    // 按ASCII码顺序输出
    for(int i = 0; i < 128; i++) {
        int index = i / 32;
        int bit = 1 << (i % 32);
        if(bitset[index] & bit) {
            printf("%c", i);
        }
    }
    
    return 0;
}

优点：空间效率高，只需要4个整数
缺点：代码可读性差，需要理解位运算
*/
