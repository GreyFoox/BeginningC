/*思路分析：
单词 + 空格 （句子末尾无空格）
scanf一直录 直到\n 为止 
塞入可变数组 
总长度不超过80
倒序 -> for循环倒过来遍历

思路分析基本正确，但存在以下问题：
1. "scanf一直录 直到\n 为止" - scanf读取字符串时遇到空格就会停止，不会自动检测换行符
2. "塞入可变数组" - C语言没有内置的可变数组，需要手动管理
3. 原代码中字符串赋值和数组使用方式错误*/

#include <stdio.h>
#include <string.h>

int main() {
	char word[81];
	// 原错误代码：
	// char r_sentence[] = {"\0"};
	// 错误原因：数组大小未指定且初始化方式错误，无法存储多个单词
	char r_sentence[40][81]; // 正确代码：二维字符数组存储多个单词
	int index = 0;
	
	// 原错误代码：
	// while(scanf("%s", &word) != 0) {
	// 	r_sentence[index] = word;
	// 	index++;
	// }
	// 错误原因：1. scanf返回值判断错误 2. 不能直接将字符串赋值给数组元素 3. 缺少退出循环的条件
	
	// 正确代码：
	while(scanf("%s", word) == 1) { // scanf成功读取返回1
	// 说明：这里不需要加&，因为数组名本身就是地址
    // word 等价于 &word[0]，所以直接使用word即可
		strcpy(r_sentence[index], word); // 使用strcpy复制字符串
		index++;
		/*声明
		下面是 strcpy() 函数的声明。
		char *strcpy(char *dest, const char *src)
		参数
		dest -- 指向用于存储复制内容的目标数组。
		src -- 要复制的字符串。*/
		
		// scanf遇到空格停止，此时输入缓冲区中还有：" \n"
		// 检查下一个字符是否为换行符
		int c = getchar();

		if(c == '\n') break;
	}
	
	// 原错误代码：
	// for(int i = index; i >= 0; i--) {
	// 	if(i != 0) {
	// 		printf("%s ", r_sentence[i]);
	// 	} else {
	// 		printf("%s", r_sentence[i]);
	// 	}
	// }
	// 错误原因：1. 起始索引应该是index-1而不是index 2. 访问了r_sentence[index]越界
	
	// 正确代码：
	for(int i = index - 1; i >= 0; i--) {
		printf("%s", r_sentence[i]);
		if(i > 0) {
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}

/*
优化方案1：使用指针数组动态分配
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 40
#define MAX_WORD_LEN 80

int main() {
    char word[MAX_WORD_LEN + 1];
    char *words[MAX_WORDS];
    int count = 0;
    
    while(scanf("%s", word) == 1 && count < MAX_WORDS) {
        words[count] = malloc(strlen(word) + 1);
        strcpy(words[count], word);
        count++;
        
        int c = getchar();
        if(c == '\n') break;
    }
    
    for(int i = count - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if(i > 0) printf(" ");
        free(words[i]); // 释放内存
    }
    printf("\n");
    
    return 0;
}

优点：内存使用更高效，只分配实际需要的空间
缺点：需要手动管理内存，代码稍复杂
适用范围：单词长度差异大且内存敏感的场景

优化方案2：单次遍历反向输出（栈思想）
#include <stdio.h>
#include <string.h>

void printReverse() {
    char word[81];
    if(scanf("%s", word) != 1) return;
    
    int c = getchar();
    if(c != '\n' && c != EOF) {
        printReverse(); // 递归调用先处理后面的单词
    }
    
    printf("%s", word);
    if(c != '\n' && c != EOF) printf(" ");
}

int main() {
    printReverse();
    printf("\n");
    return 0;
}

优点：不需要存储所有单词，节省空间
缺点：递归深度受栈大小限制，可能栈溢出
适用范围：单词数量不多且空间受限的场景

优化方案3：使用fgets和strtok分割单词
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 81

int main() {
    char line[MAX_LEN];
    char *words[40];
    int count = 0;
    
    // 一次性读取整行
    if(fgets(line, MAX_LEN, stdin) != NULL) {
        // 移除换行符
        line[strcspn(line, "\n")] = '\0';
        
        // 使用strtok分割单词
        char *token = strtok(line, " ");
        while(token != NULL && count < 40) {
            words[count++] = token;
            token = strtok(NULL, " ");
        }
        
        // 反向输出
        for(int i = count - 1; i >= 0; i--) {
            printf("%s", words[i]);
            if(i > 0) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}

优点：代码简洁，一次读取整个句子
缺点：修改了原始输入字符串，strtok非线程安全
适用范围：简单应用，不需要保留原始字符串的场景
*/
