#include <stdio.h>

// ö�ٻ�������
enum COLOR { red, yellow, green, NumColors }; // NumColors���ڻ�ȡö�ٳ�������

// ��ʽָ��ö��ֵ
enum WEEKDAY {
    MONDAY = 1,    // ��ʽָ��ֵΪ1
    TUESDAY,       // �Զ�����Ϊ2
    WEDNESDAY,     // �Զ�����Ϊ3
    THURSDAY = 10, // ��ʽָ��ֵΪ10
    FRIDAY,        // �Զ�����Ϊ11
    SATURDAY,      // �Զ�����Ϊ12
    SUNDAY         // �Զ�����Ϊ13
};

// ö����Ϊ���������ͷ���ֵ
enum TRAFFIC_LIGHT { STOP, CAUTION, GO };

enum TRAFFIC_LIGHT next_light(enum TRAFFIC_LIGHT current) {
    return (enum TRAFFIC_LIGHT)((current + 1) % 3);
}

const char* light_name(enum TRAFFIC_LIGHT light) {
    const char* names[] = { "STOP", "CAUTION", "GO" };
    return names[light];
}

int main() {
    printf("=== C����ö��(enum)֪ʶ����� ===\n\n");
    
    // 1. ö�ٵĻ���ʹ��
    printf("1. ö�ٵĻ���ʹ��:\n");
    enum COLOR my_color = red;
    printf("   my_color = %d\n", my_color);
    printf("   yellow = %d\n", yellow);
    printf("   green = %d\n", green);
    printf("   ö�ٳ�������: %d\n\n", NumColors);
    
    // 2. ö�������͵Ļ���
    printf("2. ö�������͵Ļ���:\n");
    int color_value = green; // ö�ٿ�����ʽת��Ϊ����
    printf("   green������ֵ: %d\n", color_value);
    
    enum COLOR another_color = 1; // ���Ϳ�����ʽת��Ϊö��(���з���)
    printf("   ����1��Ӧ��ö��ֵ: %d\n\n", another_color);
    
    // 3. ��ʽָ��ö��ֵ
    printf("3. ��ʽָ��ö��ֵ:\n");
    printf("   MONDAY = %d\n", MONDAY);
    printf("   TUESDAY = %d\n", TUESDAY);
    printf("   WEDNESDAY = %d\n", WEDNESDAY);
    printf("   THURSDAY = %d\n", THURSDAY);
    printf("   FRIDAY = %d\n", FRIDAY);
    printf("   SATURDAY = %d\n", SATURDAY);
    printf("   SUNDAY = %d\n\n", SUNDAY);
    
    // 4. ö����switch����е�ʹ��
    printf("4. ö����switch����е�ʹ��:\n");
    enum COLOR current = yellow;
    
    switch(current) {
        case red:
            printf("   ��ǰ�Ǻ�ɫ - ֹͣ\n");
            break;
        case yellow:
            printf("   ��ǰ�ǻ�ɫ - ע��\n");
            break;
        case green:
            printf("   ��ǰ����ɫ - ͨ��\n");
            break;
        default:
            printf("   δ֪��ɫ\n");
    }
    printf("\n");
    
    // 5. ö����Ϊ���������ͷ���ֵ
    printf("5. ö����Ϊ���������ͷ���ֵ:\n");
    enum TRAFFIC_LIGHT light = STOP;
    printf("   ��ǰ�źŵ�: %s\n", light_name(light));
    
    light = next_light(light);
    printf("   ��һ���źŵ�: %s\n", light_name(light));
    
    light = next_light(light);
    printf("   ����һ���źŵ�: %s\n\n", light_name(light));
    
    // 6. ö��������Ľ��ʹ��
    printf("6. ö��������Ľ��ʹ��:\n");
    const char* color_names[] = {
        [red] = "��ɫ",
        [yellow] = "��ɫ", 
        [green] = "��ɫ"
    };
    
    for(enum COLOR c = red; c < NumColors; c++) {
        printf("   %d: %s\n", c, color_names[c]);
    }
    printf("\n");
    
    // 7. ö�ٵ�����
    printf("7. ö�ٵ�����:\n");
    printf("   - ��ߴ���ɶ���\n");
    printf("   - ���Ʊ���ȡֵ��Χ\n");
    printf("   - ���ڵ���(�Ⱥ궨����õ���)\n");
    printf("   - �Զ�����ֵ�����ٴ���\n");
    
    return 0;
}
