/*˼·������
��һ������ 
��һ����ͬ��д��ĸ -> day -> �ڼ�����ĸ -> �ڼ��� 
�ڶ�����ͬ��д��ĸ -> time -> (0,23) -> (0,9) + (A,N)
��������
�ڼ����ַ���ͬ -> �ڼ��� 
���ȷǿա��������ո� �����Ȳ�������ʮ -> fgets()
ѡ��̵���һ�н��б��� -> strlen() 
�ҵ�������ͬ��дֱ�ӽ��� -> ֱ����ascii���ȥ64 
��������ͬ��  -> ���->ֱ�����index��

��������������ȷ�𰸷�������Ҫ�������ڣ�
1. ���������С�������
2. Сʱ����ʽ����Ӧ��ֱ��ת��Ϊ���ֶ�����ʹ���ַ�����
3. ���Ӳ���û�м���ַ�����
4. �����ʽ����������

˼·����������ȷ�������뷽ʽӦʹ��scanf����࣬���Ӳ���Ӧʹ����ȷ���ַ���Χ���*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char line1[61];
    char line2[61];
    char line3[61];
    char line4[61];
    
    // ԭ������룺
    // fgets(line1, 61, stdin);
    // fgets(line2, 61, stdin);
    // fgets(line3, 61, stdin);
    // fgets(line4, 61, stdin);
    // ����ԭ��fgets���ȡ���з�����Ҫ���⴦����scanf�����
    // ��ȷ���룺
    scanf("%s%s%s%s", line1, line2, line3, line4);
    
    // �Ƴ����з��Ĵ����Ѳ�����Ҫ
    
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
    
    // ����ԭ�еļ����߼���������ַ���Χ���
    for(int i = 0; i < size; i++) {
        if(line1[i] == line2[i]) {
            if(count == 0) {
                // ��һ��ƥ�������A-G
                if(line1[i] >= 'A' && line1[i] <= 'G') {
                    d = line1[i];
                    count++;
                }
            } else if(count == 1) {
                // �ڶ���ƥ�������0-9��A-N
                if((line1[i] >= '0' && line1[i] <= '9') || 
                   (line1[i] >= 'A' && line1[i] <= 'N')) {
                    h = line1[i];
                    count++;
                    break;
                }
            }
        }
    }
    
    // ԭ������룺
    // int day = (int)d - 64;
    // char week[7][3] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    // ����ԭ��1.�����С���㣬�ַ�����ҪΪ������'\0'Ԥ���ռ� 2.��������Ӧ�ô�0��ʼ��Ӧ����
    // ��ȷ���룺
    int day = d - 'A';  // A=0, B=1, ..., G=6
    char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    
    // ԭ������룺
    // char hour[24] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N'};
    // ����ԭ��Ӧ��ֱ��ת��Ϊ���ֶ�����ʹ���ַ����飬����������Ч
    // ��ȷ���룺
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
    
    // ԭ������룺
    // for(int i = 0; i < size; i++) {
    //     if(line3[i] == line4[i]) {
    //         s = i;
    //         break; 
    //     }
    // }
    // ����ԭ��û�м���ַ��Ƿ�Ϊ��ĸ����Ӧ��ʹ����ȷ���ַ���Χ���
    // ��ȷ���룺
    s = 0;
    for(int i = 0; i < size; i++) {
        if(line3[i] == line4[i] && 
           ((line3[i] >= 'A' && line3[i] <= 'Z') || 
            (line3[i] >= 'a' && line3[i] <= 'z'))) {
            s = i;
            break;
        }
    }
    
    // ԭ������룺
    // printf("%s %02d:%02d", week[day], hour[h], s);
    // ����ԭ��1.������������ 2.Сʱ�����ʽ����
    // ��ȷ���룺
    printf("%s %02d:%02d\n", week[day], hour, s);
    return 0;
}

/*
�Ż�����1���߼��򻯰汾
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

�ŵ㣺�����࣬�߼����������ٱ���ʹ��
ȱ�㣺�ɶ����ԲǶ�ײ�ν���
���÷�Χ����Ϥ�㷨�߼��Ŀ�����

�Ż�����2��ģ�黯�汾
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

�ŵ㣺ģ�黯��ƣ�����ɶ���ǿ������ά���Ͳ���
ȱ�㣺���������ӣ����������ж��⿪��
���÷�Χ��������Ŀ����Ҫ�������õĳ���

�Ż�����3����Ч���հ汾
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

�ŵ㣺���뼫����գ�����ʹ�����٣�ִ��Ч�ʸ�
ȱ�㣺�ɶ��Բ����������������������ά��
���÷�Χ�����뾺����Դ��볤�����ϸ����Ƶĳ���
*/
