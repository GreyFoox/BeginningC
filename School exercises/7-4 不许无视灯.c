#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);  // 输入测试数据个数
    
    while (t--) {  // 处理每个测试数据
        int n;
        scanf("%d", &n);  // 输入灯的数量
        
        int one_light = 0;  // 记录"开"状态的开关数量（不能用数字开头当变量名）
        // 不需要统计0的数量，因为0的数量=2n - one_light
        
        // 读取2n个开关状态
        for (int i = 0; i < 2 * n; i++) {
            int a;
            scanf("%d", &a);
            if (a == 1) {
                one_light++;  // 统计开着的开关数量
            }
        }
        
        // 计算最大亮灯数：取"开"和"关"的数量中较小的那个
        int max = (one_light < 2 * n - one_light) ? one_light : 2 * n - one_light;
        
        // 计算最小亮灯数：开的数量是偶数则为0，奇数则为1
        int min = (one_light % 2 == 0) ? 0 : 1;
        
        // 输出结果
        printf("%d %d\n", min, max);
    }
    
    return 0;
}

