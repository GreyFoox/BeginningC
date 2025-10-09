/*
思路分析：
第一行是待查找字符 -> getchar()
第二行是字符串 -> fgets()
最大下标 -> 找到第一个还不够 要继续遍历  
*/

#include <stdio.h>
#include <string.h>

int main() {
	char c;
	c = getchar();
	
	// 关键问题：需要读取第一行输入后的换行符
	// 否则fgets会直接读取这个换行符，而不是第二行的字符串
	getchar(); // 读取第一行输入后的换行符
	
	char str[81];
    fgets(str, 81, stdin);
    
    // 原错误代码：
    // int index = 0;
    // int flag = 1;
    // for(int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
    //     char c0 = str[i];
    //     if(c0 == c) {
    // 		index = i;
    // 		flag = 0;
    //     }
    // }
    // if(flag) {
    // 	printf("Not Found");
    // }
    // 错误原因：
    // 1. 变量名index和flag不够明确
    // 2. 输出格式不正确，应该是"index = 下标"
    // 3. 缺少成功找到时的输出语句
    // 4. 从前往后查找，找到的是最后一个匹配项，但效率不如从后往前查找
    
    // 正确代码（参考网站答案优化）：
    int index = -1; // 初始化为-1，表示未找到
    int length = strlen(str);
    
    // 从后往前查找，找到的第一个匹配项就是最大下标
    for(int i = length - 1; i >= 0; i--) {
        if(str[i] == c) {
            index = i;
            break; // 找到后立即退出循环
        }
    }
    
    if(index != -1) {
        printf("index = %d", index);
    } else {
        printf("Not Found");
    }
    
    return 0;
}

/*
优化方案1：使用strrchr函数（最简洁）
#include <stdio.h>
#include <string.h>

int main() {
    char c;
    c = getchar();
    getchar(); // 读取换行符
    
    char str[81];
    fgets(str, 81, stdin);
    
    // 使用strrchr查找字符最后一次出现的位置
    char *pos = strrchr(str, c);
    
    if(pos != NULL) {
        printf("index = %ld", pos - str); // 指针相减得到下标
    } else {
        printf("Not Found");
    }
    
    return 0;
}

优点：代码简洁，使用标准库函数
缺点：需要理解指针运算

优化方案2：使用do-while循环从后往前查找
#include <stdio.h>
#include <string.h>

int main() {
    char c;
    c = getchar();
    getchar(); // 读取换行符
    
    char str[81];
    fgets(str, 81, stdin);
    
    int index = -1;
    int i = strlen(str) - 1;
    
    do {
        if(str[i] == c) {
            index = i;
            break;
        }
        i--;
    } while(i >= 0);
    
    if(index != -1) {
        printf("index = %d", index);
    } else {
        printf("Not Found");
    }
    
    return 0;
}

优点：循环结构清晰
缺点：与for循环相比没有明显优势

优化方案3：不使用string.h库函数
#include <stdio.h>

int main() {
    char c;
    c = getchar();
    getchar(); // 读取换行符
    
    char str[81];
    fgets(str, 81, stdin);
    
    int index = -1;
    int i = 0;
    
    // 先找到字符串末尾
    while(str[i] != '\0') {
        i++;
    }
    
    // 从后往前查找
    for(int j = i - 1; j >= 0; j--) {
        if(str[j] == c) {
            index = j;
            break;
        }
    }
    
    if(index != -1) {
        printf("index = %d", index);
    } else {
        printf("Not Found");
    }
    
    return 0;
}

优点：不依赖string.h库
缺点：需要自己计算字符串长度
*/
