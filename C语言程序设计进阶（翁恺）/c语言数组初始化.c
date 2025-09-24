#include <stdio.h>

int main() {
    printf("=== C���������ʼ��ʾ�� ===\n\n");
    
    // 1. ��ͨ�����ʼ��
    printf("1. ��ͨ�����ʼ��:\n");
    int arr1[5] = {1, 2, 3, 4, 5};
    printf("   int arr1[5] = {1, 2, 3, 4, 5};\n");
    printf("   ���: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n\n");
    
    // 2. ���ֳ�ʼ����ʣ��Ԫ���Զ����㣩
    printf("2. ���ֳ�ʼ����ʣ��Ԫ���Զ����㣩:\n");
    int arr2[5] = {1, 2}; // ֻ��ʼ��ǰ����Ԫ��
    printf("   int arr2[5] = {1, 2};\n");
    printf("   ���: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n\n");
    
    // 3. ʹ�ö�λ����ʼ����C99���ԣ�
    printf("3. ʹ�ö�λ����ʼ����C99���ԣ�:\n");
    int arr3[10] = {
        [0] = 2, 
        [2] = 3, 
        6, // û�ж�λ��������ǰһ��λ�ú��棬��[3] = 6
        [7] = 9
    };
    printf("   int arr3[10] = {[0] = 2, [2] = 3, 6, [7] = 9};\n");
    printf("   ���: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n\n");
    
    // 4. ��ָ�������С���ñ���������
    printf("4. ��ָ�������С���ñ���������:\n");
    int arr4[] = {
        [0] = 1,
        [5] = 2,
        [10] = 3
    }; // ���������Զ����������СΪ11
    printf("   int arr4[] = {[0] = 1, [5] = 2, [10] = 3};\n");
    printf("   �����С: %zu\n", sizeof(arr4)/sizeof(arr4[0]));
    printf("   ���: ");
    for(int i = 0; i < sizeof(arr4)/sizeof(arr4[0]); i++) {
        printf("%d ", arr4[i]);
    }
    printf("\n\n");
    
    // 5. ϡ�������ʼ�����ǳ��ʺ�ʹ�ö�λ����
    printf("5. ϡ�������ʼ�����ǳ��ʺ�ʹ�ö�λ����:\n");
    int sparse[100] = {
        [0] = 1,
        [50] = 2,
        [99] = 3
    }; // ֻ��3��λ����ֵ�����඼��0
    printf("   int sparse[100] = {[0] = 1, [50] = 2, [99] = 3};\n");
    printf("   ��鼸���ؼ�λ��:\n");
    printf("   sparse[0] = %d\n", sparse[0]);
    printf("   sparse[1] = %d\n", sparse[1]);
    printf("   sparse[50] = %d\n", sparse[50]);
    printf("   sparse[99] = %d\n", sparse[99]);
    printf("\n");
    
    // 6. �ַ�����Ķ�λ��ʼ��
    printf("6. �ַ�����Ķ�λ��ʼ��:\n");
    char str[10] = {
        [0] = 'H',
        [1] = 'e',
        [2] = 'l',
        [3] = 'l',
        [4] = 'o',
        [5] = '\0' // �ַ�����ֹ��
    };
    printf("   char str[10] = {[0]='H',[1]='e',[2]='l',[3]='l',[4]='o',[5]='\\0'};\n");
    printf("   ���: %s\n", str);
    printf("\n");
    
    // 7. ��ά�����C99���Գ�ʼ��
    printf("7. ��ά�����C99���Գ�ʼ��:\n");
    
    // 7.1 ʹ��Ƕ�״����ų�ʼ��
    printf("7.1 ʹ��Ƕ�״����ų�ʼ��:\n");
    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printf("   int matrix1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};\n");
    printf("   ���:\n");
    for(int i = 0; i < 3; i++) {
        printf("   ");
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // 7.2 ʹ�ö�λ����ʼ����ά����
    printf("7.2 ʹ�ö�λ����ʼ����ά����:\n");
    int matrix2[3][3] = {
        [0][0] = 1, [0][2] = 2,
        [1][1] = 3,
        [2][0] = 4, [2][2] = 5
    };
    printf("   int matrix2[3][3] = {[0][0]=1, [0][2]=2, [1][1]=3, [2][0]=4, [2][2]=5};\n");
    printf("   ���:\n");
    for(int i = 0; i < 3; i++) {
        printf("   ");
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // 7.3 ��ά����Ĳ��ֳ�ʼ��
    printf("7.3 ��ά����Ĳ��ֳ�ʼ��:\n");
    int matrix3[3][3] = {
        {1},        // ��һ��: 1, 0, 0
        {0, 2},     // �ڶ���: 0, 2, 0
        {0, 0, 3}   // ������: 0, 0, 3
    };
    printf("   int matrix3[3][3] = {{1},{0,2},{0,0,3}};\n");
    printf("   ���:\n");
    for(int i = 0; i < 3; i++) {
        printf("   ");
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // 7.4 ��ά����Ļ�ϳ�ʼ��
    printf("7.4 ��ά����Ļ�ϳ�ʼ��:\n");
    int matrix4[3][4] = {
        [0] = {1, 2},           // ��һ��: 1, 2, 0, 0
        [1][1] = 5, [1][3] = 6, // �ڶ���: 0, 5, 0, 6
        [2] = {[0] = 7, [2] = 8} // ������: 7, 0, 8, 0
    };
    printf("   int matrix4[3][4] = {[0]={1,2}, [1][1]=5, [1][3]=6, [2]={[0]=7, [2]=8}};\n");
    printf("   ���:\n");
    for(int i = 0; i < 3; i++) {
        printf("   ");
        for(int j = 0; j < 4; j++) {
            printf("%d ", matrix4[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // 7.5 ��ָ����һά��С�Ķ�ά�����ʼ��
    printf("7.5 ��ָ����һά��С�Ķ�ά�����ʼ��:\n");
    int matrix5[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printf("   int matrix5[][3] = {{1,2,3},{4,5,6},{7,8,9}};\n");
    printf("   ��������: %zu\n", sizeof(matrix5)/sizeof(matrix5[0]));
    printf("   ���:\n");
    for(int i = 0; i < sizeof(matrix5)/sizeof(matrix5[0]); i++) {
        printf("   ");
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix5[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
