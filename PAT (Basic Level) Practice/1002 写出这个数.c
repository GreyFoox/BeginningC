#include <stdio.h>
#include <string.h>

/*
原始思路（含问题注释）：
n < 10^100 过大 所以肯定不能用整数存 -> 使用字符串 -> %s  // 思路正确
输入数字  
取数字 -> 遍历字符串 -> 字符转数字 -> ASCII码  // 思路正确
和转汉字 -> 再取每一位数字 -> 数组里面找  // 思路正确但不具体
(感觉有点麻烦啊)  // 问题：未明确如何处理输出格式（最后一位无空格）

原始代码（含问题注释）：
#include <stdio.h>

int main() {
    int sum = 0;
    char str[];  // 问题1：未指定数组大小，无法编译
    scanf("%s", &str);  // 问题2：数组名无需&，且未限制输入长度可能溢出
    int size = sizeof(str) / sizeof(str[0]);  // 问题3：sizeof无法获取实际输入长度
    for(int i = 0; i < size; i++ ) {
        sum += str[i]-48;  // 逻辑正确，但用48不如用'0'直观
    }
     
    return 0;  // 问题4：未实现将和转换为拼音的功能
}
*/

/*
其他优化方法（边读边算，无需存储整个字符串）：
优点：
1. 空间复杂度从O(n)降至O(1)，不需要存储整个输入字符串
2. 避免了字符串缓冲区溢出的风险
3. 代码更简洁，步骤更少

缺点：
1. 无法回退重新处理输入（本问题中无需此功能）
2. 需要处理输入结束的判断（如换行符）
*/
/*
// 优化方法的代码实现：
#include <stdio.h>

int main() {
    int sum = 0;
    char c;
    const char* pinyin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    
    // 边读取边计算，无需存储整个字符串
    while((c = getchar()) != '\n' && c != EOF) {
        if(c >= '0' && c <= '9') {
            sum += c - '0';
        }
    }
    
    // 以下部分与主代码相同...
    return 0;
}
*/

int main() {
    // 存储输入的字符串（10^100最多100位数字）
    char str[101];
    // 数字拼音对照表，索引对应数字0-9
    const char* pinyin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    
    // 读取输入
    scanf("%s", str);
    
    // 计算各位数字之和
    int sum = 0;
    int len = strlen(str);  // 使用strlen获取实际长度，解决原代码问题
    for(int i = 0; i < len; i++) {
        sum += str[i] - '0';  // 使用'0'比48更直观，增强可读性
    }
    
    // 处理和为0的特殊情况
    if(sum == 0) {
        printf("ling\n");
        return 0;
    }
    
    // 存储和的每一位数字（从低位到高位）
    int digits[10];  // 最大可能的和是100*9=900，最多3位
    int count = 0;
    while(sum > 0) {
        digits[count++] = sum % 10;
        sum /= 10;
    }
    
    // 输出拼音，从高位到低位
    for(int i = count - 1; i >= 0; i--) {
        // 控制输出格式，最后一位无空格
        if(i == 0) {
            printf("%s\n", pinyin[digits[i]]);
        } else {
            printf("%s ", pinyin[digits[i]]);
        }
    }
    
    return 0;
}

