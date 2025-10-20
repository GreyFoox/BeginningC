/*思路分析：
使用结构体存储学生信息，包含性别和姓名
使用双指针法，从数组两端向中间遍历配对
对于前一半的每个学生，从后往前寻找异性配对

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
优化方案1：单指针法
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

优点：逻辑简单直观，易于理解
缺点：需要额外的标记数组，时间复杂度O(n2)
适用范围：教学演示或小规模数据

优化方案2：双队列法
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

优点：时间复杂度O(n)，效率高
缺点：需要额外的队列空间
适用范围：性能要求高的场景

优化方案3：改进双指针法
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
            // 如果性别相同，向前移动右指针寻找异性
            right--;
        }
    }
    return 0;
}

优点：空间复杂度O(1)，代码简洁
缺点：最坏情况下时间复杂度较高
适用范围：内存受限的环境
*/
