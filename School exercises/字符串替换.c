/*思路分析：
A -> Z 使用ASCII码（原注释"A码"表述不够准确）
必须是大写字母 其他的不管 
不超过80个字符 以回车结束 -> 应该使用fgets()而不是fputs() 
通过举例发现和始终为155 -> 使用算术运算（原注释"二元运算符"表述不准确）*/

#include <stdio.h>
#include <string.h>

int main() {
	char str[81];
    fgets(str, 81, stdin);
    int length = strlen(str);
    
    // 原错误代码：
    // for(int i = 1; i < length; i++) {
    // 错误原因：循环从i=1开始，跳过了第一个字符，应该从i=0开始
    
    // 正确代码：
    for(int i = 0; i < length; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            // 使用对称映射：A->Z, B->Y, ..., Z->A
            // 公式：'A' + 'Z' - str[i] 或 155 - str[i]
            printf("%c", 155 - str[i]);
        } else {
            printf("%c", str[i]);
        }
    }
    return 0;
}

/*
优化方案1：使用更直观的映射公式
#include <stdio.h>
#include <string.h>

int main() {
    char str[81];
    fgets(str, 81, stdin);
    int length = strlen(str);
    
    for(int i = 0; i < length; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            // 使用公式：'A' + 'Z' - str[i]
            printf("%c", 'A' + 'Z' - str[i]);
        } else {
            printf("%c", str[i]);
        }
    }
    return 0;
}

优点：公式更直观，易于理解
缺点：与155-str[i]效果相同

优化方案2：使用查找表（适用于复杂映射）
#include <stdio.h>
#include <string.h>

int main() {
    char str[81];
    fgets(str, 81, stdin);
    
    // 创建映射表
    char map[256] = {0};
    for(int i = 0; i < 256; i++) {
        map[i] = i; // 默认映射为自己
    }
    
    // 设置大写字母的映射
    for(char c = 'A'; c <= 'Z'; c++) {
        map[c] = 'A' + 'Z' - c;
    }
    
    // 使用映射表进行转换
    for(int i = 0; str[i] != '\0'; i++) {
        printf("%c", map[str[i]]);
    }
    return 0;
}

优点：对于复杂映射规则效率高，代码清晰
缺点：需要额外的存储空间

优化方案3：使用指针遍历
#include <stdio.h>
#include <string.h>

int main() {
    char str[81];
    fgets(str, 81, stdin);
    
    char *p = str;
    while(*p != '\0') {
        if(*p >= 'A' && *p <= 'Z') {
            printf("%c", 'A' + 'Z' - *p);
        } else {
            printf("%c", *p);
        }
        p++;
    }
    return 0;
}

优点：代码简洁，使用指针效率高
缺点：对指针理解要求较高
*/
