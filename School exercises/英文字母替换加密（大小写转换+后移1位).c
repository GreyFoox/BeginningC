#include <stdio.h>

int main() {
    // 原始代码问题回顾：
    // 1. 未定义数组arr，缺少输入逻辑
    // 2. 未处理z->A和Z->a的循环移位
    // 3. 转换公式错误，未明确移位与大小写转换的顺序关系
    /*
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < size; i++) {
        if(arr[i] >= 'a' && arr[i] <= 'z') {
            printf("%c", arr[i] - 32 + 1);  // 此处隐含"转大写后移位"
        } else if (arr[i] >= 'A' && arr[i] <= 'Z') {
            printf("%c", arr[i] + 32 + 1);  // 此处隐含"转小写后移位"
        }
    }
    */

    // 优化版本：getchar逐个处理（主方法，适合简单场景）
    char c;
    // 循环读取直到换行符，避免冗余的EOF判断（专注一行处理）
    while ((c = getchar()) != '\n') {
        // 处理小写字母：后移1位 + 转大写（符合题目加密规则）
        if (c >= 'a' && c <= 'z') {  
            // 边界说明：<= 'z'中的'='不可省略，否则会漏掉z→A的转换
            int offset = (c - 'a' + 1) % 26;  // 模26处理循环，比硬编码更可靠
            putchar('A' + offset);  // 性能优化：putchar比printf少格式解析开销
        }
        // 处理大写字母：后移1位 + 转小写
        else if (c >= 'A' && c <= 'Z') {  
            // 边界说明：<= 'Z'中的'='不可省略，否则会漏掉Z→a的转换
            int offset = (c - 'A' + 1) % 26;
            putchar('a' + offset);  // 直接输出字符，减少函数调用开销
        }
        // 非字母字符原样输出（保持功能完整性）
        else {
            putchar(c);
        }
    }
    putchar('\n');  // 补充换行，保持输入输出格式一致


    // 备选版本：getline整行处理（适合长输入，作为注释保留）
    /*
    // 空间优化说明：getline动态分配缓冲区，需手动释放避免泄漏
    char *input = NULL;       // 初始化为NULL，让getline自动分配内存
    size_t buf_size = 0;      // 缓冲区大小由getline自动管理
    ssize_t len = getline(&input, &buf_size, stdin);  // 一次读取整行，减少I/O次数

    if (len != -1) {  // 鲁棒性处理：判断读取成功与否
        for (ssize_t i = 0; i < len; i++) {  // 用ssize_t匹配getline返回值类型
            char c = input[i];
            if (c >= 'a' && c <= 'z') {
                int offset = (c - 'a' + 1) % 26;
                putchar('A' + offset);
            }
            else if (c >= 'A' && c <= 'Z') {
                int offset = (c - 'A' + 1) % 26;
                putchar('a' + offset);
            }
            else {
                putchar(c);
            }
        }
    }
    free(input);  // 必须释放内存，否则造成泄漏（标注为关键操作）
    */


    return 0;
}
