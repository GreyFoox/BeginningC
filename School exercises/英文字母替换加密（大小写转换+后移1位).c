#include <stdio.h>

int main() {
    // ԭʼ��������عˣ�
    // 1. δ��������arr��ȱ�������߼�
    // 2. δ����z->A��Z->a��ѭ����λ
    // 3. ת����ʽ����δ��ȷ��λ���Сдת����˳���ϵ
    /*
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < size; i++) {
        if(arr[i] >= 'a' && arr[i] <= 'z') {
            printf("%c", arr[i] - 32 + 1);  // �˴�����"ת��д����λ"
        } else if (arr[i] >= 'A' && arr[i] <= 'Z') {
            printf("%c", arr[i] + 32 + 1);  // �˴�����"תСд����λ"
        }
    }
    */

    // �Ż��汾��getchar����������������ʺϼ򵥳�����
    char c;
    // ѭ����ȡֱ�����з������������EOF�жϣ�רעһ�д���
    while ((c = getchar()) != '\n') {
        // ����Сд��ĸ������1λ + ת��д��������Ŀ���ܹ���
        if (c >= 'a' && c <= 'z') {  
            // �߽�˵����<= 'z'�е�'='����ʡ�ԣ������©��z��A��ת��
            int offset = (c - 'a' + 1) % 26;  // ģ26����ѭ������Ӳ������ɿ�
            putchar('A' + offset);  // �����Ż���putchar��printf�ٸ�ʽ��������
        }
        // �����д��ĸ������1λ + תСд
        else if (c >= 'A' && c <= 'Z') {  
            // �߽�˵����<= 'Z'�е�'='����ʡ�ԣ������©��Z��a��ת��
            int offset = (c - 'A' + 1) % 26;
            putchar('a' + offset);  // ֱ������ַ������ٺ������ÿ���
        }
        // ����ĸ�ַ�ԭ����������ֹ��������ԣ�
        else {
            putchar(c);
        }
    }
    putchar('\n');  // ���任�У��������������ʽһ��


    // ��ѡ�汾��getline���д����ʺϳ����룬��Ϊע�ͱ�����
    /*
    // �ռ��Ż�˵����getline��̬���仺���������ֶ��ͷű���й©
    char *input = NULL;       // ��ʼ��ΪNULL����getline�Զ������ڴ�
    size_t buf_size = 0;      // ��������С��getline�Զ�����
    ssize_t len = getline(&input, &buf_size, stdin);  // һ�ζ�ȡ���У�����I/O����

    if (len != -1) {  // ³���Դ����ж϶�ȡ�ɹ����
        for (ssize_t i = 0; i < len; i++) {  // ��ssize_tƥ��getline����ֵ����
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
    free(input);  // �����ͷ��ڴ棬�������й©����עΪ�ؼ�������
    */


    return 0;
}
