#include <stdio.h>
#include <string.h>

// 定义日期结构体（结构中的结构）
struct Date {
    int year;
    int month;
    int day;
};

// 定义成绩结构体（结构中的结构）
struct Score {
    float math;
    float english;
    float programming;
};

// 定义学生结构体，包含嵌套结构
struct Student {
    int id;
    char name[50];
    int age;
    struct Date birthday;    // 嵌套结构：生日日期
    struct Score score;      // 嵌套结构：成绩
};

// 函数声明
void printStudent(struct Student stu);
void printAllStudents(struct Student students[], int count);
float calculateAverage(struct Student stu);

int main() {
    // 创建结构数组（包含3个学生）
    struct Student students[3];
    
    // 初始化第一个学生信息
    students[0].id = 1001;
    strcpy(students[0].name, "张三");
    students[0].age = 20;
    students[0].birthday.year = 2003;
    students[0].birthday.month = 5;
    students[0].birthday.day = 15;
    students[0].score.math = 85.5;
    students[0].score.english = 78.0;
    students[0].score.programming = 92.5;
    
    // 初始化第二个学生信息
    students[1].id = 1002;
    strcpy(students[1].name, "李四");
    students[1].age = 19;
    students[1].birthday.year = 2004;
    students[1].birthday.month = 8;
    students[1].birthday.day = 22;
    students[1].score.math = 92.0;
    students[1].score.english = 88.5;
    students[1].score.programming = 95.0;
    
    // 初始化第三个学生信息
    students[2].id = 1003;
    strcpy(students[2].name, "王五");
    students[2].age = 21;
    students[2].birthday.year = 2002;
    students[2].birthday.month = 12;
    students[2].birthday.day = 3;
    students[2].score.math = 76.5;
    students[2].score.english = 82.0;
    students[2].score.programming = 88.5;
    
    printf("=== 学生信息管理系统 ===\n\n");
    
    // 打印所有学生信息
    printAllStudents(students, 3);
    
    // 单独打印第二个学生的详细信息
    printf("\n=== 第二个学生的详细信息 ===\n");
    printStudent(students[1]);
    
    return 0;
}

// 打印单个学生的详细信息
void printStudent(struct Student stu) {
    printf("学号: %d\n", stu.id);
    printf("姓名: %s\n", stu.name);
    printf("年龄: %d\n", stu.age);
    printf("生日: %d年%d月%d日\n", 
           stu.birthday.year, stu.birthday.month, stu.birthday.day);
    printf("数学成绩: %.1f\n", stu.score.math);
    printf("英语成绩: %.1f\n", stu.score.english);
    printf("编程成绩: %.1f\n", stu.score.programming);
    printf("平均成绩: %.1f\n", calculateAverage(stu));
    printf("------------------------\n");
}

// 打印所有学生信息
void printAllStudents(struct Student students[], int count) {
    printf("共有%d个学生:\n", count);
    printf("========================\n");
    
    for(int i = 0; i < count; i++) {
        printf("学生%d:\n", i + 1);
        printf("学号: %d, 姓名: %s, 年龄: %d\n", 
               students[i].id, students[i].name, students[i].age);
        printf("平均成绩: %.1f\n", calculateAverage(students[i]));
        printf("------------------------\n");
    }
}

// 计算学生的平均成绩
float calculateAverage(struct Student stu) {
    return (stu.score.math + stu.score.english + stu.score.programming) / 3.0;
}
