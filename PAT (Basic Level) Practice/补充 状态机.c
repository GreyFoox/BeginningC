#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief 使用DFA状态转移表计算二进制字符串模5的结果
 * @param binary_str 二进制字符串（只包含0和1）
 * @return 模5的结果（0-4）
 * 
 * 原理说明：
 * 1. 使用5个状态（0-4）表示当前的余数
 * 2. 对于每个输入位，状态转移规则为：新状态 = (当前状态 × 2 + 输入位) % 5
 * 3. 这种方法基于Horner方法，可以流式处理任意长度的二进制数
 */
int binary_mod5_dfa(const char* binary_str) {
    /* DFA状态转移表
     * 行表示当前状态（0-4），列表示输入位（0或1）
     * 转移规则：new_state = (current_state * 2 + input) % 5
     */
    int dfa_table[5][2] = {
        // 状态0: 余数为0
        // 输入0: (0×2+0)%5=0 → 保持状态0
        // 输入1: (0×2+1)%5=1 → 转移到状态1
        {0, 1},
        
        // 状态1: 余数为1  
        // 输入0: (1×2+0)%5=2 → 转移到状态2
        // 输入1: (1×2+1)%5=3 → 转移到状态3
        {2, 3},
        
        // 状态2: 余数为2
        // 输入0: (2×2+0)%5=4 → 转移到状态4
        // 输入1: (2×2+1)%5=0 → 转移到状态0（因为5÷5余0）
        {4, 0},
        
        // 状态3: 余数为3
        // 输入0: (3×2+0)%5=1 → 转移到状态1（因为6÷5余1）
        // 输入1: (3×2+1)%5=2 → 转移到状态2（因为7÷5余2）
        {1, 2},
        
        // 状态4: 余数为4
        // 输入0: (4×2+0)%5=3 → 转移到状态3（因为8÷5余3）
        // 输入1: (4×2+1)%5=4 → 保持状态4（因为9÷5余4）
        {3, 4}
    };
    
    int current_state = 0;  // 初始状态：余数为0（对应空字符串）
    
    // 遍历二进制字符串的每一位
    for (int i = 0; binary_str[i] != '\0'; i++) {
        char current_char = binary_str[i];
        
        // 只处理有效的二进制位（0或1），跳过其他字符
        if (current_char == '0' || current_char == '1') {
            int input_bit = current_char - '0';  // 将字符'0'或'1'转换为数字0或1
            
            // 执行状态转移：根据当前状态和输入位查找下一个状态
            current_state = dfa_table[current_state][input_bit];
            
            // 调试信息：显示每一步的状态转移（可选）
            // printf("读入 '%c': 状态 %d → 状态 %d\n", 
            //        current_char, old_state, current_state);
        }
    }
    
    // 最终状态就是模5的结果
    return current_state;
}

/**
 * @brief 使用Horner方法计算二进制字符串模5的结果
 * @param binary_str 二进制字符串（只包含0和1）
 * @return 模5的结果（0-4）
 * 
 * 原理说明：
 * Horner方法将多项式计算转化为递推形式：
 * 对于二进制数 bₙbₙ₋₁...b₀，其值为：((...(bₙ×2 + bₙ₋₁)×2 + ...)×2 + b₀
 * 在模5运算中：result = (result * 2 + current_bit) % 5
 */
int binary_mod5_horner(const char* binary_str) {
    int result = 0;  // 初始结果为0
    
    // 从左向右遍历二进制字符串（最高位优先）
    for (int i = 0; binary_str[i] != '\0'; i++) {
        char current_char = binary_str[i];
        
        if (current_char == '0' || current_char == '1') {
            int current_bit = current_char - '0';
            
            /* Horner方法的递推公式：
             * 新结果 = (当前结果 × 2 + 当前位) % 5
             * 
             * 数学解释：
             * - 乘以2相当于二进制左移一位
             * - 加上当前位相当于设置最低位
             * - 取模5保证结果始终在0-4范围内
             */
            result = (result * 2 + current_bit) % 5;
        }
    }
    
    return result;
}

/**
 * @brief 清理二进制字符串，移除非0非1字符
 * @param str 待清理的字符串（会被修改）
 */
void clean_binary_string(char* str) {
    int j = 0;  // 新字符串的写入位置
    
    for (int i = 0; str[i] != '\0'; i++) {
        // 只保留0和1字符
        if (str[i] == '0' || str[i] == '1') {
            str[j] = str[i];
            j++;
        }
        // 其他字符（空格、字母等）被自动过滤掉
    }
    
    str[j] = '\0';  // 在新字符串末尾添加结束符
}

/**
 * @brief 验证二进制字符串是否有效（只包含0和1）
 * @param binary_str 要验证的字符串
 * @return 1表示有效，0表示无效
 */
int is_valid_binary(const char* binary_str) {
    // 空字符串无效
    if (binary_str == NULL || strlen(binary_str) == 0) {
        return 0;
    }
    
    // 检查每个字符是否都是0或1
    for (int i = 0; binary_str[i] != '\0'; i++) {
        if (binary_str[i] != '0' && binary_str[i] != '1') {
            return 0;
        }
    }
    
    return 1;
}

/**
 * @brief 将二进制字符串转换为十进制整数（用于验证）
 * @param binary_str 二进制字符串
 * @return 对应的十进制整数
 */
int binary_to_decimal(const char* binary_str) {
    int decimal = 0;
    
    for (int i = 0; binary_str[i] != '\0'; i++) {
        decimal = decimal * 2 + (binary_str[i] - '0');
    }
    
    return decimal;
}

/**
 * @brief 显示状态转移的详细过程（仅用于短字符串）
 * @param binary_str 二进制字符串
 */
void show_state_transition(const char* binary_str) {
    // 只对较短的字符串显示详细过程
    if (strlen(binary_str) > 20) {
        printf("字符串太长，不显示详细状态转移过程\n");
        return;
    }
    
    printf("状态转移过程: 开始(状态0)");
    
    int state = 0;
    int dfa_table[5][2] = {{0,1}, {2,3}, {4,0}, {1,2}, {3,4}};
    
    for (int i = 0; binary_str[i] != '\0'; i++) {
        if (binary_str[i] == '0' || binary_str[i] == '1') {
            int input = binary_str[i] - '0';
            int old_state = state;
            state = dfa_table[state][input];
            
            printf(" --[输入%c]--> 状态%d", binary_str[i], state);
        }
    }
    
    printf("\n");
}

/**
 * @brief 运行预定义的测试用例
 */
void run_test_cases() {
    printf("=== 二进制按5取模测试用例 ===\n");
    printf("二进制数\t十进制\t预期结果\tDFA方法\tHorner方法\t状态\n");
    printf("----------------------------------------------------------------\n");
    
    // 测试用例数组：{二进制字符串, 十进制值, 预期模5结果}
    struct TestCase {
        const char* binary;
        int decimal;
        int expected;
    } test_cases[] = {
        {"0", 0, 0},
        {"1", 1, 1},
        {"10", 2, 2},
        {"11", 3, 3},
        {"100", 4, 4},
        {"101", 5, 0},
        {"110", 6, 1},
        {"111", 7, 2},
        {"1000", 8, 3},
        {"1001", 9, 4},
        {"1010", 10, 0},
        {"1011", 11, 1},
        {"1100", 12, 2},
        {"1101", 13, 3},
        {"1110", 14, 4},
        {"1111", 15, 0},
        {"10000", 16, 1},
        {"100000", 32, 2},
        {"1000000", 64, 4},
        {"1111111", 127, 2},  // 127 ÷ 5 = 25余2
        {NULL, 0, 0}  // 结束标记
    };
    
    int passed = 0, total = 0;
    
    for (int i = 0; test_cases[i].binary != NULL; i++) {
        const char* binary = test_cases[i].binary;
        int expected = test_cases[i].expected;
        
        int result_dfa = binary_mod5_dfa(binary);
        int result_horner = binary_mod5_horner(binary);
        
        // 检查两种方法是否一致且符合预期
        int dfa_correct = (result_dfa == expected);
        int horner_correct = (result_horner == expected);
        int methods_consistent = (result_dfa == result_horner);
        
        const char* status = (dfa_correct && horner_correct && methods_consistent) ? "✓" : "✗";
        
        if (dfa_correct && horner_correct && methods_consistent) {
            passed++;
        }
        
        printf("%-10s\t%d\t%d\t\t%d\t%d\t\t%s\n", 
               binary, test_cases[i].decimal, expected, 
               result_dfa, result_horner, status);
        
        total++;
    }
    
    printf("----------------------------------------------------------------\n");
    printf("测试结果: %d/%d 通过\n\n", passed, total);
}

/**
 * @brief 交互式模式：用户输入二进制数，程序计算模5结果
 */
void interactive_mode() {
    printf("=== 交互式二进制模5计算器 ===\n");
    printf("输入二进制数（只包含0和1），程序将计算模5的结果\n");
    printf("输入 'quit' 或 'exit' 退出程序\n\n");
    
    char input[1000];
    
    while (1) {
        printf("请输入二进制数: ");
        
        // 读取用户输入
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;  // 读取失败或EOF
        }
        
        // 移除换行符
        input[strcspn(input, "\n")] = 0;
        
        // 检查退出条件
        if (strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0) {
            break;
        }
        
        // 跳过空输入
        if (strlen(input) == 0) {
            continue;
        }
        
        // 清理输入（移除空格等非法字符）
        char cleaned_input[1000];
        strcpy(cleaned_input, input);
        clean_binary_string(cleaned_input);
        
        // 验证输入是否有效
        if (!is_valid_binary(cleaned_input) || strlen(cleaned_input) == 0) {
            printf("错误: 请输入有效的二进制数（只包含0和1），当前输入: '%s'\n\n", input);
            continue;
        }
        
        // 计算两种方法的结果
        int result_dfa = binary_mod5_dfa(cleaned_input);
        int result_horner = binary_mod5_horner(cleaned_input);
        int decimal_value = binary_to_decimal(cleaned_input);
        
        // 显示结果
        printf("输入: %s\n", cleaned_input);
        printf("十进制值: %d\n", decimal_value);
        printf("DFA方法结果: %d\n", result_dfa);
        printf("Horner方法结果: %d\n", result_horner);
        printf("验证: %s\n", 
               (result_dfa == result_horner) ? "✓ 两种方法结果一致" : "✗ 结果不一致");
        printf("正确性: %s\n\n", 
               (decimal_value % 5 == result_dfa) ? "✓ 结果正确" : "✗ 结果错误");
        
        // 显示详细的状态转移过程（对于短字符串）
        if (strlen(cleaned_input) <= 15) {
            show_state_transition(cleaned_input);
            printf("\n");
        }
    }
    
    printf("感谢使用！程序结束。\n");
}

/**
 * @brief 主函数：程序入口点
 */
int main() {
    printf("二进制按5取模计算器 - 完整实现\n");
    printf("==============================\n\n");
    
    // 运行测试用例
    run_test_cases();
    
    // 进入交互式模式
    interactive_mode();
    
    return 0;
}