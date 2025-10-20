/*˼·������
ʹ�ýṹ��洢ѧ����Ϣ�������Ա������
ʹ��˫ָ�뷨���������������м�������
����ǰһ���ÿ��ѧ�����Ӻ���ǰѰ���������

*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int gender;
    char name[9];
} Student;

int main() {
    int n;
    scanf("%d", &n);
    Student students[n];
    
    for(int i = 0; i < n; i++) {
        scanf("%d %s", &students[i].gender, students[i].name);
    }
    
    int j = n - 1, k = n - 1;
    for(int i = 0; i < n/2; i++) {
        if(students[i].gender == 1) {
            while(students[j].gender == students[i].gender) j--;
            printf("%s %s\n", students[i].name, students[j].name);
            j--;
        } else {
            while(students[k].gender == students[i].gender) k--;
            printf("%s %s\n", students[i].name, students[k].name);
            k--;
        }
    }
    return 0;
}

/*
�Ż�����1����ָ�뷨
#include <stdio.h>
#include <string.h>

typedef struct {
    int gender;
    char name[9];
} Student;

int main() {
    int n;
    scanf("%d", &n);
    Student students[n];
    
    for(int i = 0; i < n; i++) {
        scanf("%d %s", &students[i].gender, students[i].name);
    }
    
    int used[n];
    memset(used, 0, sizeof(used));
    
    for(int i = 0; i < n/2; i++) {
        for(int j = n-1; j >= n/2; j--) {
            if(!used[j] && students[i].gender != students[j].gender) {
                printf("%s %s\n", students[i].name, students[j].name);
                used[j] = 1;
                break;
            }
        }
    }
    return 0;
}

�ŵ㣺�߼���ֱ�ۣ��������
ȱ�㣺��Ҫ����ı�����飬ʱ�临�Ӷ�O(n2)
���÷�Χ����ѧ��ʾ��С��ģ����

�Ż�����2��˫���з�
#include <stdio.h>
#include <string.h>

typedef struct {
    int gender;
    char name[9];
} Student;

int main() {
    int n;
    scanf("%d", &n);
    Student students[n];
    int boys[n], girls[n];
    int boy_count = 0, girl_count = 0;
    
    for(int i = 0; i < n; i++) {
        scanf("%d %s", &students[i].gender, students[i].name);
        if(students[i].gender == 1) {
            boys[boy_count++] = i;
        } else {
            girls[girl_count++] = i;
        }
    }
    
    int boy_index = 0, girl_index = 0;
    for(int i = 0; i < n/2; i++) {
        if(students[i].gender == 1) {
            printf("%s %s\n", students[i].name, students[girls[--girl_count]]);
        } else {
            printf("%s %s\n", students[i].name, students[boys[--boy_count]]);
        }
    }
    return 0;
}

�ŵ㣺ʱ�临�Ӷ�O(n)��Ч�ʸ�
ȱ�㣺��Ҫ����Ķ��пռ�
���÷�Χ������Ҫ��ߵĳ���

�Ż�����3���Ľ�˫ָ�뷨
#include <stdio.h>
#include <string.h>

typedef struct {
    int gender;
    char name[9];
} Student;

int main() {
    int n;
    scanf("%d", &n);
    Student students[n];
    
    for(int i = 0; i < n; i++) {
        scanf("%d %s", &students[i].gender, students[i].name);
    }
    
    int left = 0, right = n-1;
    while(left < n/2) {
        if(students[left].gender != students[right].gender) {
            printf("%s %s\n", students[left].name, students[right].name);
            left++;
            right--;
        } else {
            // ����Ա���ͬ����ǰ�ƶ���ָ��Ѱ������
            right--;
        }
    }
    return 0;
}

�ŵ㣺�ռ临�Ӷ�O(1)��������
ȱ�㣺������ʱ�临�ӶȽϸ�
���÷�Χ���ڴ����޵Ļ���
*/
