#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);  // ����������ݸ���
    
    while (t--) {  // ����ÿ����������
        int n;
        scanf("%d", &n);  // ����Ƶ�����
        
        int one_light = 0;  // ��¼"��"״̬�Ŀ������������������ֿ�ͷ����������
        // ����Ҫͳ��0����������Ϊ0������=2n - one_light
        
        // ��ȡ2n������״̬
        for (int i = 0; i < 2 * n; i++) {
            int a;
            scanf("%d", &a);
            if (a == 1) {
                one_light++;  // ͳ�ƿ��ŵĿ�������
            }
        }
        
        // ���������������ȡ"��"��"��"�������н�С���Ǹ�
        int max = (one_light < 2 * n - one_light) ? one_light : 2 * n - one_light;
        
        // ������С������������������ż����Ϊ0��������Ϊ1
        int min = (one_light % 2 == 0) ? 0 : 1;
        
        // ������
        printf("%d %d\n", min, max);
    }
    
    return 0;
}

