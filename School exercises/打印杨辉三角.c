/*˼·������
n�У���ȷ��
�������� -> n�� ÿ�и�����1��ʼ������n����ȷ��
ÿ�����̶ֹ�ռ��λ -> Ӧ��ʹ��%4d��ʽ�������������\t��\t�Ŀ�Ȳ��̶�����������ĿҪ��
������� -> ��ͷ����1 ���м� = ���м�֮�ͣ���ȷ������������ǵĺ������ʣ�
����1�������� = ��һ�б�Ե������֮�ͣ���������׼ȷ��Ӧ����ÿ�����������Ϸ�������֮�ͣ�
��������ǲ���Ϥ ����ʽ����Ҳ���԰ɣ� -> �׳ˣ�����ʹ�ö���ʽϵ�����㣬��Ч�ʽϵͣ����ƹ�ϵ����Ч��*/

#include <stdio.h>

int main() {
    int n, i, j, k;
    int a[15][15] = {0};
    
    scanf("%d", &n);
    
    // ��ʼ��ǰ����
    a[0][0] = 1;
    a[1][0] = 1;
    a[1][1] = 1;
    
    // ���������һ��
    for(k = n-1; k > 0; k--)
        printf(" ");
    printf("   1\n");
    
    // ���������
    for(i = 1; i < n; i++) {
        // ��ӡ��ǰ�ո�
        for(k = n-1; k > i; k--)
            printf(" ");
        
        // ���㲢��ӡ��ǰ��
        for(j = 0; j <= i; j++) {
            if(j == 0 || j == i)
                a[i][j] = 1;
            else
                a[i][j] = a[i-1][j-1] + a[i-1][j];
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

/*
�Ż�����1��ʹ��һά���飨��ʡ�ռ䣩
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int row[15] = {1}; // ��ʼ��Ϊ��һ��
    
    // ���������һ��
    for(int k = n-1; k > 0; k--)
        printf(" ");
    printf("   1\n");
    
    for(int i = 1; i < n; i++) {
        // ��ӡ�ո�
        for(int k = n-1; k > i; k--)
            printf(" ");
        
        // ������һ�У��Ӻ���ǰ���£����⸲�ǣ�
        for(int j = i; j > 0; j--) {
            row[j] = row[j] + row[j-1];
        }
        row[i] = 1; // ��β���1
        
        // ��ӡ��ǰ��
        for(int j = 0; j <= i; j++) {
            printf("%4d", row[j]);
        }
        printf("\n");
    }
    
    return 0;
}

�ŵ㣺ֻʹ��һά���飬��ʡ�ռ�
ȱ�㣺�����߼��Ը���

�Ż�����2��ʹ���������ʽ����ѧ������
#include <stdio.h>

// ���������C(n, k)
int combination(int n, int k) {
    if(k == 0 || k == n) return 1;
    
    long result = 1;
    // ʹ��C(n, k) = C(n, n-k)�����ʼ��ټ�����
    if(k > n - k) k = n - k;
    
    for(int i = 0; i < k; i++) {
        result = result * (n - i) / (i + 1);
    }
    
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    
    // ���������һ��
    for(int k = n-1; k > 0; k--)
        printf(" ");
    printf("   1\n");
    
    for(int i = 1; i < n; i++) {
        // ��ӡ�ո�
        for(int k = n-1; k > i; k--)
            printf(" ");
        
        // ʹ���������ʽ����������ǵ�ÿ��Ԫ��
        for(int j = 0; j <= i; j++) {
            printf("%4d", combination(i, j));
        }
        printf("\n");
    }
    
    return 0;
}

�ŵ㣺ֱ�Ӽ���ÿ��Ԫ�أ�����Ҫ�洢����������
ȱ�㣺�����������������Ч�ʽϵ�

�Ż�����3��ʹ�õݹ飨��ѧ��;��
#include <stdio.h>

// �ݹ�����������Ԫ��
int pascal(int row, int col) {
    if(col == 0 || col == row) {
        return 1;
    }
    return pascal(row - 1, col - 1) + pascal(row - 1, col);
}

int main() {
    int n;
    scanf("%d", &n);
    
    // ���������һ��
    for(int k = n-1; k > 0; k--)
        printf(" ");
    printf("   1\n");
    
    for(int i = 1; i < n; i++) {
        // ��ӡ�ո�
        for(int k = n-1; k > i; k--)
            printf(" ");
        
        // ʹ�õݹ����ÿ��Ԫ��
        for(int j = 0; j <= i; j++) {
            printf("%4d", pascal(i, j));
        }
        printf("\n");
    }
    
    return 0;
}

�ŵ㣺����ֱ�ۣ��������ݹ�˼��
ȱ�㣺Ч�ʼ��ͣ��д����ظ�����
*/
