/*思路分析：
排除AEIOU
不超过90个字符 
输入字符 -> 字符数组 
*/

#include <stdio.h> 

int main() {
	char c;
	int sum = 0;
	
	// 原错误代码：
	// while((c = getchar())!= "\n") {
	// 错误原因：比较字符应该用单引号'\n'，双引号表示字符串
	// 原错误条件判断：
	// if(c != 'A' || c != 'E'|| c != 'I' || c != 'O'|| c != 'U') {
	// 错误原因：逻辑运算符使用错误，应该用&&而不是||
	// 因为一个字符不可能同时不等于所有元音字母，所以这个条件总是为真
	
	// 正确代码：
	while((c = getchar())!= '\n') {
		// 判断条件：必须是大写字母，且不是元音字母
		if(c >= 'A' && c <= 'Z' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
			sum++;
		}
	}
	printf("%d", sum);
	return 0;
}

/*
优化方案1：使用字符串处理函数
#include <stdio.h>
#include <string.h>

int main() {
    char str[81];
    int sum = 0;
    
    fgets(str, 81, stdin);  // 读取一行字符串
    
    for(int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        char c = str[i];
        // 使用strchr检查是否在元音字符串中
        if(c >= 'A' && c <= 'Z' && strchr("AEIOU", c) == NULL) {
            sum++;
        }
    }
    printf("%d", sum);
    return 0;
}

优点：代码更清晰，易于理解和维护
缺点：需要包含string.h头文件

优化方案2：使用switch语句
#include <stdio.h>

int main() {
    char c;
    int sum = 0;
    
    while((c = getchar()) != '\n') {
        if(c >= 'A' && c <= 'Z') {
            switch(c) {
                case 'A': case 'E': case 'I': case 'O': case 'U':
                    break;  // 如果是元音，跳过
                default:
                    sum++;  // 否则是辅音，计数
            }
        }
    }
    printf("%d", sum);
    return 0;
}

优点：逻辑清晰，易于扩展
缺点：代码稍长

优化方案3：使用位运算（高级技巧）
#include <stdio.h>

int main() {
    char c;
    int sum = 0;
    // 创建一个位掩码，元音字母对应的位设为1
    unsigned long long vowel_mask = 0;
    vowel_mask |= 1ULL << ('A' - 'A');
    vowel_mask |= 1ULL << ('E' - 'A');
    vowel_mask |= 1ULL << ('I' - 'A');
    vowel_mask |= 1ULL << ('O' - 'A');
    vowel_mask |= 1ULL << ('U' - 'A');
    
    while((c = getchar()) != '\n') {
        if(c >= 'A' && c <= 'Z') {
            // 检查该字母对应的位是否为0（不是元音）
            if(!(vowel_mask & (1ULL << (c - 'A')))) {
                sum++;
            }
        }
    }
    printf("%d", sum);
    return 0;
}

优点：查询速度快，适合大量数据
缺点：代码复杂，可读性差
*/
