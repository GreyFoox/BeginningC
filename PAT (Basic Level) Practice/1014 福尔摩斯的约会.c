/*思路分析：
第一、二行 
第一对相同大写字母 -> day -> 第几个字母 -> 第几天 
第二对相同大写字母 -> time -> (0,23) -> (0,9) + (A,N)
第三四行
第几个字符相同 -> 第几分 
长度非空、不包含空格 、长度不超过六十 -> fgets()
选择短的那一行进行遍历 -> strlen() 
找到两个相同大写直接结束 -> 直接用ascii码减去64 
后面两个同理  -> 打表->直接输出index；

根据评测结果和正确答案分析，主要问题在于：
1. 星期数组大小定义错误
2. 小时处理方式错误，应该直接转换为数字而不是使用字符数组
3. 分钟查找没有检查字符类型
4. 输出格式和索引有误

思路分析基本正确，但输入方式应使用scanf更简洁，分钟查找应使用明确的字符范围检查*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char line1[61];
    char line2[61];
    char line3[61];
    char line4[61];
    
    // 原错误代码：
    // fgets(line1, 61, stdin);
    // fgets(line2, 61, stdin);
    // fgets(line3, 61, stdin);
    // fgets(line4, 61, stdin);
    // 错误原因：fgets会读取换行符，需要额外处理，而scanf更简洁
    // 正确代码：
    scanf("%s%s%s%s", line1, line2, line3, line4);
    
    // 移除换行符的代码已不再需要
    
    int l_line = strlen(line1)>=strlen(line2) ? 1 : 0;
    int size;
    if(l_line) {
        size = strlen(line1);
    } else {
        size = strlen(line2);
    }
    int count = 0;
    char d;
    char h;
    
    // 保持原有的计数逻辑，但添加字符范围检查
    for(int i = 0; i < size; i++) {
        if(line1[i] == line2[i]) {
            if(count == 0) {
                // 第一个匹配必须是A-G
                if(line1[i] >= 'A' && line1[i] <= 'G') {
                    d = line1[i];
                    count++;
                }
            } else if(count == 1) {
                // 第二个匹配必须是0-9或A-N
                if((line1[i] >= '0' && line1[i] <= '9') || 
                   (line1[i] >= 'A' && line1[i] <= 'N')) {
                    h = line1[i];
                    count++;
                    break;
                }
            }
        }
    }
    
    // 原错误代码：
    // int day = (int)d - 64;
    // char week[7][3] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    // 错误原因：1.数组大小不足，字符串需要为结束符'\0'预留空间 2.索引计算应该从0开始对应星期
    // 正确代码：
    int day = d - 'A';  // A=0, B=1, ..., G=6
    char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    
    // 原错误代码：
    // char hour[24] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N'};
    // 错误原因：应该直接转换为数字而不是使用字符数组，这样更简洁高效
    // 正确代码：
    int hour;
    if(h >= '0' && h <= '9') {
        hour = h - '0';
    } else {
        hour = h - 'A' + 10;
    }
    
    int l_line2 = strlen(line3)>=strlen(line4) ? 1 : 0;
    int s;
    if(l_line2) {
        size = strlen(line3);
    } else {
        size = strlen(line4);
    }
    
    // 原错误代码：
    // for(int i = 0; i < size; i++) {
    //     if(line3[i] == line4[i]) {
    //         s = i;
    //         break; 
    //     }
    // }
    // 错误原因：没有检查字符是否为字母，且应该使用明确的字符范围检查
    // 正确代码：
    s = 0;
    for(int i = 0; i < size; i++) {
        if(line3[i] == line4[i] && 
           ((line3[i] >= 'A' && line3[i] <= 'Z') || 
            (line3[i] >= 'a' && line3[i] <= 'z'))) {
            s = i;
            break;
        }
    }
    
    // 原错误代码：
    // printf("%s %02d:%02d", week[day], hour[h], s);
    // 错误原因：1.数组索引错误 2.小时输出格式错误
    // 正确代码：
    printf("%s %02d:%02d\n", week[day], hour, s);
    return 0;
}

/*
优化方案1：逻辑简化版本
#include <stdio.h>
#include <string.h>

int main() {
    char s1[61], s2[61], s3[61], s4[61];
    scanf("%s%s%s%s", s1, s2, s3, s4);
    
    char *week[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int found = 0;
    
    for(int i = 0; s1[i] && s2[i]; i++) {
        if(s1[i] == s2[i]) {
            if(!found) {
                if(s1[i] >= 'A' && s1[i] <= 'G') {
                    printf("%s ", week[s1[i]-'A']);
                    found = 1;
                }
            } else {
                if((s1[i] >= '0' && s1[i] <= '9') || (s1[i] >= 'A' && s1[i] <= 'N')) {
                    int hour = (s1[i] >= '0' && s1[i] <= '9') ? s1[i]-'0' : s1[i]-'A'+10;
                    printf("%02d:", hour);
                    break;
                }
            }
        }
    }
    
    for(int i = 0; s3[i] && s4[i]; i++) {
        if(s3[i] == s4[i] && ((s3[i] >= 'A' && s3[i] <= 'Z') || (s3[i] >= 'a' && s3[i] <= 'z'))) {
            printf("%02d\n", i);
            break;
        }
    }
    
    return 0;
}

优点：代码简洁，逻辑清晰，减少变量使用
缺点：可读性稍差，嵌套层次较深
适用范围：熟悉算法逻辑的开发者

优化方案2：模块化版本
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int findDayAndHour(char *s1, char *s2, int *day, int *hour) {
    int found_day = 0;
    int len = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);
    
    for(int i = 0; i < len; i++) {
        if(s1[i] == s2[i]) {
            if(!found_day) {
                if(s1[i] >= 'A' && s1[i] <= 'G') {
                    *day = s1[i] - 'A';
                    found_day = 1;
                }
            } else {
                if((s1[i] >= '0' && s1[i] <= '9') || (s1[i] >= 'A' && s1[i] <= 'N')) {
                    *hour = (s1[i] >= '0' && s1[i] <= '9') ? s1[i] - '0' : s1[i] - 'A' + 10;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int findMinute(char *s3, char *s4) {
    int len = strlen(s3) < strlen(s4) ? strlen(s3) : strlen(s4);
    for(int i = 0; i < len; i++) {
        if(s3[i] == s4[i] && isalpha(s3[i])) {
            return i;
        }
    }
    return 0;
}

int main() {
    char str1[61], str2[61], str3[61], str4[61];
    scanf("%s%s%s%s", str1, str2, str3, str4);
    
    char *week[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int day, hour;
    
    if(findDayAndHour(str1, str2, &day, &hour)) {
        int minute = findMinute(str3, str4);
        printf("%s %02d:%02d\n", week[day], hour, minute);
    }
    
    return 0;
}

优点：模块化设计，代码可读性强，易于维护和测试
缺点：代码量增加，函数调用有额外开销
适用范围：大型项目或需要代码重用的场景

优化方案3：高效紧凑版本
#include <stdio.h>
#include <string.h>

int main() {
    char s1[61], s2[61], s3[61], s4[61];
    scanf("%s%s%s%s", s1, s2, s3, s4);
    
    char *w[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int i, d = 0, h = 0, m = 0, f = 0;
    
    for(i = 0; s1[i] && s2[i] && !h; i++) {
        if(s1[i] == s2[i]) {
            if(!f && s1[i] >= 'A' && s1[i] <= 'G') {
                d = s1[i] - 'A';
                f = 1;
            } else if(f && ((s1[i] >= '0' && s1[i] <= '9') || (s1[i] >= 'A' && s1[i] <= 'N'))) {
                h = (s1[i] >= '0' && s1[i] <= '9') ? s1[i] - '0' : s1[i] - 'A' + 10;
            }
        }
    }
    
    for(i = 0; s3[i] && s4[i]; i++) {
        if(s3[i] == s4[i] && ((s3[i] >= 'A' && s3[i] <= 'Z') || (s3[i] >= 'a' && s3[i] <= 'z'))) {
            m = i;
            break;
        }
    }
    
    printf("%s %02d:%02d\n", w[d], h, m);
    return 0;
}

优点：代码极其紧凑，变量使用最少，执行效率高
缺点：可读性差，变量命名不清晰，不利于维护
适用范围：代码竞赛或对代码长度有严格限制的场景
*/
