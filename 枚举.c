#include <stdio.h>

// 枚举基本定义
enum COLOR { red, yellow, green, NumColors }; // NumColors用于获取枚举常量数量

// 显式指定枚举值
enum WEEKDAY {
    MONDAY = 1,    // 显式指定值为1
    TUESDAY,       // 自动递增为2
    WEDNESDAY,     // 自动递增为3
    THURSDAY = 10, // 显式指定值为10
    FRIDAY,        // 自动递增为11
    SATURDAY,      // 自动递增为12
    SUNDAY         // 自动递增为13
};

// 枚举作为函数参数和返回值
enum TRAFFIC_LIGHT { STOP, CAUTION, GO };

enum TRAFFIC_LIGHT next_light(enum TRAFFIC_LIGHT current) {
    return (enum TRAFFIC_LIGHT)((current + 1) % 3);
}

const char* light_name(enum TRAFFIC_LIGHT light) {
    const char* names[] = { "STOP", "CAUTION", "GO" };
    return names[light];
}

int main() {
    printf("=== C语言枚举(enum)知识点详解 ===\n\n");
    
    // 1. 枚举的基本使用
    printf("1. 枚举的基本使用:\n");
    enum COLOR my_color = red;
    printf("   my_color = %d\n", my_color);
    printf("   yellow = %d\n", yellow);
    printf("   green = %d\n", green);
    printf("   枚举常量数量: %d\n\n", NumColors);
    
    // 2. 枚举与整型的互换
    printf("2. 枚举与整型的互换:\n");
    int color_value = green; // 枚举可以隐式转换为整型
    printf("   green的整型值: %d\n", color_value);
    
    enum COLOR another_color = 1; // 整型可以隐式转换为枚举(但有风险)
    printf("   整型1对应的枚举值: %d\n\n", another_color);
    
    // 3. 显式指定枚举值
    printf("3. 显式指定枚举值:\n");
    printf("   MONDAY = %d\n", MONDAY);
    printf("   TUESDAY = %d\n", TUESDAY);
    printf("   WEDNESDAY = %d\n", WEDNESDAY);
    printf("   THURSDAY = %d\n", THURSDAY);
    printf("   FRIDAY = %d\n", FRIDAY);
    printf("   SATURDAY = %d\n", SATURDAY);
    printf("   SUNDAY = %d\n\n", SUNDAY);
    
    // 4. 枚举在switch语句中的使用
    printf("4. 枚举在switch语句中的使用:\n");
    enum COLOR current = yellow;
    
    switch(current) {
        case red:
            printf("   当前是红色 - 停止\n");
            break;
        case yellow:
            printf("   当前是黄色 - 注意\n");
            break;
        case green:
            printf("   当前是绿色 - 通行\n");
            break;
        default:
            printf("   未知颜色\n");
    }
    printf("\n");
    
    // 5. 枚举作为函数参数和返回值
    printf("5. 枚举作为函数参数和返回值:\n");
    enum TRAFFIC_LIGHT light = STOP;
    printf("   当前信号灯: %s\n", light_name(light));
    
    light = next_light(light);
    printf("   下一个信号灯: %s\n", light_name(light));
    
    light = next_light(light);
    printf("   再下一个信号灯: %s\n\n", light_name(light));
    
    // 6. 枚举与数组的结合使用
    printf("6. 枚举与数组的结合使用:\n");
    const char* color_names[] = {
        [red] = "红色",
        [yellow] = "黄色", 
        [green] = "绿色"
    };
    
    for(enum COLOR c = red; c < NumColors; c++) {
        printf("   %d: %s\n", c, color_names[c]);
    }
    printf("\n");
    
    // 7. 枚举的优势
    printf("7. 枚举的优势:\n");
    printf("   - 提高代码可读性\n");
    printf("   - 限制变量取值范围\n");
    printf("   - 便于调试(比宏定义更好调试)\n");
    printf("   - 自动分配值，减少错误\n");
    
    return 0;
}
