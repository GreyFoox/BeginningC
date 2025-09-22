#include <stdio.h>
#include <string.h>

// �������ڽṹ�壨�ṹ�еĽṹ��
struct Date {
    int year;
    int month;
    int day;
};

// ����ɼ��ṹ�壨�ṹ�еĽṹ��
struct Score {
    float math;
    float english;
    float programming;
};

// ����ѧ���ṹ�壬����Ƕ�׽ṹ
struct Student {
    int id;
    char name[50];
    int age;
    struct Date birthday;    // Ƕ�׽ṹ����������
    struct Score score;      // Ƕ�׽ṹ���ɼ�
};

// ��������
void printStudent(struct Student stu);
void printAllStudents(struct Student students[], int count);
float calculateAverage(struct Student stu);

int main() {
    // �����ṹ���飨����3��ѧ����
    struct Student students[3];
    
    // ��ʼ����һ��ѧ����Ϣ
    students[0].id = 1001;
    strcpy(students[0].name, "����");
    students[0].age = 20;
    students[0].birthday.year = 2003;
    students[0].birthday.month = 5;
    students[0].birthday.day = 15;
    students[0].score.math = 85.5;
    students[0].score.english = 78.0;
    students[0].score.programming = 92.5;
    
    // ��ʼ���ڶ���ѧ����Ϣ
    students[1].id = 1002;
    strcpy(students[1].name, "����");
    students[1].age = 19;
    students[1].birthday.year = 2004;
    students[1].birthday.month = 8;
    students[1].birthday.day = 22;
    students[1].score.math = 92.0;
    students[1].score.english = 88.5;
    students[1].score.programming = 95.0;
    
    // ��ʼ��������ѧ����Ϣ
    students[2].id = 1003;
    strcpy(students[2].name, "����");
    students[2].age = 21;
    students[2].birthday.year = 2002;
    students[2].birthday.month = 12;
    students[2].birthday.day = 3;
    students[2].score.math = 76.5;
    students[2].score.english = 82.0;
    students[2].score.programming = 88.5;
    
    printf("=== ѧ����Ϣ����ϵͳ ===\n\n");
    
    // ��ӡ����ѧ����Ϣ
    printAllStudents(students, 3);
    
    // ������ӡ�ڶ���ѧ������ϸ��Ϣ
    printf("\n=== �ڶ���ѧ������ϸ��Ϣ ===\n");
    printStudent(students[1]);
    
    return 0;
}

// ��ӡ����ѧ������ϸ��Ϣ
void printStudent(struct Student stu) {
    printf("ѧ��: %d\n", stu.id);
    printf("����: %s\n", stu.name);
    printf("����: %d\n", stu.age);
    printf("����: %d��%d��%d��\n", 
           stu.birthday.year, stu.birthday.month, stu.birthday.day);
    printf("��ѧ�ɼ�: %.1f\n", stu.score.math);
    printf("Ӣ��ɼ�: %.1f\n", stu.score.english);
    printf("��̳ɼ�: %.1f\n", stu.score.programming);
    printf("ƽ���ɼ�: %.1f\n", calculateAverage(stu));
    printf("------------------------\n");
}

// ��ӡ����ѧ����Ϣ
void printAllStudents(struct Student students[], int count) {
    printf("����%d��ѧ��:\n", count);
    printf("========================\n");
    
    for(int i = 0; i < count; i++) {
        printf("ѧ��%d:\n", i + 1);
        printf("ѧ��: %d, ����: %s, ����: %d\n", 
               students[i].id, students[i].name, students[i].age);
        printf("ƽ���ɼ�: %.1f\n", calculateAverage(students[i]));
        printf("------------------------\n");
    }
}

// ����ѧ����ƽ���ɼ�
float calculateAverage(struct Student stu) {
    return (stu.score.math + stu.score.english + stu.score.programming) / 3.0;
}
