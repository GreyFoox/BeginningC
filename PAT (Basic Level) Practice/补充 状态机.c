#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief ʹ��DFA״̬ת�Ʊ����������ַ���ģ5�Ľ��
 * @param binary_str �������ַ�����ֻ����0��1��
 * @return ģ5�Ľ����0-4��
 * 
 * ԭ��˵����
 * 1. ʹ��5��״̬��0-4����ʾ��ǰ������
 * 2. ����ÿ������λ��״̬ת�ƹ���Ϊ����״̬ = (��ǰ״̬ �� 2 + ����λ) % 5
 * 3. ���ַ�������Horner������������ʽ�������ⳤ�ȵĶ�������
 */
int binary_mod5_dfa(const char* binary_str) {
    /* DFA״̬ת�Ʊ�
     * �б�ʾ��ǰ״̬��0-4�����б�ʾ����λ��0��1��
     * ת�ƹ���new_state = (current_state * 2 + input) % 5
     */
    int dfa_table[5][2] = {
        // ״̬0: ����Ϊ0
        // ����0: (0��2+0)%5=0 �� ����״̬0
        // ����1: (0��2+1)%5=1 �� ת�Ƶ�״̬1
        {0, 1},
        
        // ״̬1: ����Ϊ1  
        // ����0: (1��2+0)%5=2 �� ת�Ƶ�״̬2
        // ����1: (1��2+1)%5=3 �� ת�Ƶ�״̬3
        {2, 3},
        
        // ״̬2: ����Ϊ2
        // ����0: (2��2+0)%5=4 �� ת�Ƶ�״̬4
        // ����1: (2��2+1)%5=0 �� ת�Ƶ�״̬0����Ϊ5��5��0��
        {4, 0},
        
        // ״̬3: ����Ϊ3
        // ����0: (3��2+0)%5=1 �� ת�Ƶ�״̬1����Ϊ6��5��1��
        // ����1: (3��2+1)%5=2 �� ת�Ƶ�״̬2����Ϊ7��5��2��
        {1, 2},
        
        // ״̬4: ����Ϊ4
        // ����0: (4��2+0)%5=3 �� ת�Ƶ�״̬3����Ϊ8��5��3��
        // ����1: (4��2+1)%5=4 �� ����״̬4����Ϊ9��5��4��
        {3, 4}
    };
    
    int current_state = 0;  // ��ʼ״̬������Ϊ0����Ӧ���ַ�����
    
    // �����������ַ�����ÿһλ
    for (int i = 0; binary_str[i] != '\0'; i++) {
        char current_char = binary_str[i];
        
        // ֻ������Ч�Ķ�����λ��0��1�������������ַ�
        if (current_char == '0' || current_char == '1') {
            int input_bit = current_char - '0';  // ���ַ�'0'��'1'ת��Ϊ����0��1
            
            // ִ��״̬ת�ƣ����ݵ�ǰ״̬������λ������һ��״̬
            current_state = dfa_table[current_state][input_bit];
            
            // ������Ϣ����ʾÿһ����״̬ת�ƣ���ѡ��
            // printf("���� '%c': ״̬ %d �� ״̬ %d\n", 
            //        current_char, old_state, current_state);
        }
    }
    
    // ����״̬����ģ5�Ľ��
    return current_state;
}

/**
 * @brief ʹ��Horner��������������ַ���ģ5�Ľ��
 * @param binary_str �������ַ�����ֻ����0��1��
 * @return ģ5�Ľ����0-4��
 * 
 * ԭ��˵����
 * Horner����������ʽ����ת��Ϊ������ʽ��
 * ���ڶ������� b?b???...b?����ֵΪ��((...(b?��2 + b???)��2 + ...)��2 + b?
 * ��ģ5�����У�result = (result * 2 + current_bit) % 5
 */
int binary_mod5_horner(const char* binary_str) {
    int result = 0;  // ��ʼ���Ϊ0
    
    // �������ұ����������ַ��������λ���ȣ�
    for (int i = 0; binary_str[i] != '\0'; i++) {
        char current_char = binary_str[i];
        
        if (current_char == '0' || current_char == '1') {
            int current_bit = current_char - '0';
            
            /* Horner�����ĵ��ƹ�ʽ��
             * �½�� = (��ǰ��� �� 2 + ��ǰλ) % 5
             * 
             * ��ѧ���ͣ�
             * - ����2�൱�ڶ���������һλ
             * - ���ϵ�ǰλ�൱���������λ
             * - ȡģ5��֤���ʼ����0-4��Χ��
             */
            result = (result * 2 + current_bit) % 5;
        }
    }
    
    return result;
}

/**
 * @brief ����������ַ������Ƴ���0��1�ַ�
 * @param str ��������ַ������ᱻ�޸ģ�
 */
void clean_binary_string(char* str) {
    int j = 0;  // ���ַ�����д��λ��
    
    for (int i = 0; str[i] != '\0'; i++) {
        // ֻ����0��1�ַ�
        if (str[i] == '0' || str[i] == '1') {
            str[j] = str[i];
            j++;
        }
        // �����ַ����ո���ĸ�ȣ����Զ����˵�
    }
    
    str[j] = '\0';  // �����ַ���ĩβ��ӽ�����
}

/**
 * @brief ��֤�������ַ����Ƿ���Ч��ֻ����0��1��
 * @param binary_str Ҫ��֤���ַ���
 * @return 1��ʾ��Ч��0��ʾ��Ч
 */
int is_valid_binary(const char* binary_str) {
    // ���ַ�����Ч
    if (binary_str == NULL || strlen(binary_str) == 0) {
        return 0;
    }
    
    // ���ÿ���ַ��Ƿ���0��1
    for (int i = 0; binary_str[i] != '\0'; i++) {
        if (binary_str[i] != '0' && binary_str[i] != '1') {
            return 0;
        }
    }
    
    return 1;
}

/**
 * @brief ���������ַ���ת��Ϊʮ����������������֤��
 * @param binary_str �������ַ���
 * @return ��Ӧ��ʮ��������
 */
int binary_to_decimal(const char* binary_str) {
    int decimal = 0;
    
    for (int i = 0; binary_str[i] != '\0'; i++) {
        decimal = decimal * 2 + (binary_str[i] - '0');
    }
    
    return decimal;
}

/**
 * @brief ��ʾ״̬ת�Ƶ���ϸ���̣������ڶ��ַ�����
 * @param binary_str �������ַ���
 */
void show_state_transition(const char* binary_str) {
    // ֻ�Խ϶̵��ַ�����ʾ��ϸ����
    if (strlen(binary_str) > 20) {
        printf("�ַ���̫��������ʾ��ϸ״̬ת�ƹ���\n");
        return;
    }
    
    printf("״̬ת�ƹ���: ��ʼ(״̬0)");
    
    int state = 0;
    int dfa_table[5][2] = {{0,1}, {2,3}, {4,0}, {1,2}, {3,4}};
    
    for (int i = 0; binary_str[i] != '\0'; i++) {
        if (binary_str[i] == '0' || binary_str[i] == '1') {
            int input = binary_str[i] - '0';
            int old_state = state;
            state = dfa_table[state][input];
            
            printf(" --[����%c]--> ״̬%d", binary_str[i], state);
        }
    }
    
    printf("\n");
}

/**
 * @brief ����Ԥ����Ĳ�������
 */
void run_test_cases() {
    printf("=== �����ư�5ȡģ�������� ===\n");
    printf("��������\tʮ����\tԤ�ڽ��\tDFA����\tHorner����\t״̬\n");
    printf("----------------------------------------------------------------\n");
    
    // �����������飺{�������ַ���, ʮ����ֵ, Ԥ��ģ5���}
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
        {"1111111", 127, 2},  // 127 �� 5 = 25��2
        {NULL, 0, 0}  // �������
    };
    
    int passed = 0, total = 0;
    
    for (int i = 0; test_cases[i].binary != NULL; i++) {
        const char* binary = test_cases[i].binary;
        int expected = test_cases[i].expected;
        
        int result_dfa = binary_mod5_dfa(binary);
        int result_horner = binary_mod5_horner(binary);
        
        // ������ַ����Ƿ�һ���ҷ���Ԥ��
        int dfa_correct = (result_dfa == expected);
        int horner_correct = (result_horner == expected);
        int methods_consistent = (result_dfa == result_horner);
        
        const char* status = (dfa_correct && horner_correct && methods_consistent) ? "?" : "?";
        
        if (dfa_correct && horner_correct && methods_consistent) {
            passed++;
        }
        
        printf("%-10s\t%d\t%d\t\t%d\t%d\t\t%s\n", 
               binary, test_cases[i].decimal, expected, 
               result_dfa, result_horner, status);
        
        total++;
    }
    
    printf("----------------------------------------------------------------\n");
    printf("���Խ��: %d/%d ͨ��\n\n", passed, total);
}

/**
 * @brief ����ʽģʽ���û���������������������ģ5���
 */
void interactive_mode() {
    printf("=== ����ʽ������ģ5������ ===\n");
    printf("�������������ֻ����0��1�������򽫼���ģ5�Ľ��\n");
    printf("���� 'quit' �� 'exit' �˳�����\n\n");
    
    char input[1000];
    
    while (1) {
        printf("�������������: ");
        
        // ��ȡ�û�����
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;  // ��ȡʧ�ܻ�EOF
        }
        
        // �Ƴ����з�
        input[strcspn(input, "\n")] = 0;
        
        // ����˳�����
        if (strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0) {
            break;
        }
        
        // ����������
        if (strlen(input) == 0) {
            continue;
        }
        
        // �������루�Ƴ��ո�ȷǷ��ַ���
        char cleaned_input[1000];
        strcpy(cleaned_input, input);
        clean_binary_string(cleaned_input);
        
        // ��֤�����Ƿ���Ч
        if (!is_valid_binary(cleaned_input) || strlen(cleaned_input) == 0) {
            printf("����: ��������Ч�Ķ���������ֻ����0��1������ǰ����: '%s'\n\n", input);
            continue;
        }
        
        // �������ַ����Ľ��
        int result_dfa = binary_mod5_dfa(cleaned_input);
        int result_horner = binary_mod5_horner(cleaned_input);
        int decimal_value = binary_to_decimal(cleaned_input);
        
        // ��ʾ���
        printf("����: %s\n", cleaned_input);
        printf("ʮ����ֵ: %d\n", decimal_value);
        printf("DFA�������: %d\n", result_dfa);
        printf("Horner�������: %d\n", result_horner);
        printf("��֤: %s\n", 
               (result_dfa == result_horner) ? "? ���ַ������һ��" : "? �����һ��");
        printf("��ȷ��: %s\n\n", 
               (decimal_value % 5 == result_dfa) ? "? �����ȷ" : "? �������");
        
        // ��ʾ��ϸ��״̬ת�ƹ��̣����ڶ��ַ�����
        if (strlen(cleaned_input) <= 15) {
            show_state_transition(cleaned_input);
            printf("\n");
        }
    }
    
    printf("��лʹ�ã����������\n");
}

/**
 * @brief ��������������ڵ�
 */
int main() {
    printf("�����ư�5ȡģ������ - ����ʵ��\n");
    printf("==============================\n\n");
    
    // ���в�������
    run_test_cases();
    
    // ���뽻��ʽģʽ
    interactive_mode();
    
    return 0;
}