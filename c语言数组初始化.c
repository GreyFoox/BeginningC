#include <stdio.h>

int main() {
    printf("=== C语言数组初始化示例 ===\n\n");
    
    // 1. 普通数组初始化
    printf("1. 普通数组初始化:\n");
    int arr1[5] = {1, 2, 3, 4, 5};
    printf("   int arr1[5] = {1, 2, 3, 4, 5};\n");
    printf("   结果: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n\n");
    
    // 2. 部分初始化（剩余元素自动补零）
    printf("2. 部分初始化（剩余元素自动补零）:\n");
    int arr2[5] = {1, 2}; // 只初始化前两个元素
    printf("   int arr2[5] = {1, 2};\n");
    printf("   结果: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n\n");
    
    // 3. 使用定位符初始化（C99特性）
    printf("3. 使用定位符初始化（C99特性）:\n");
    int arr3[10] = {
        [0] = 2, 
        [2] = 3, 
        6, // 没有定位符，接在前一个位置后面，即[3] = 6
        [7] = 9
    };
    printf("   int arr3[10] = {[0] = 2, [2] = 3, 6, [7] = 9};\n");
    printf("   结果: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n\n");
    
    // 4. 不指定数组大小，让编译器计算
    printf("4. 不指定数组大小，让编译器计算:\n");
    int arr4[] = {
        [0] = 1,
        [5] = 2,
        [10] = 3
    }; // 编译器会自动计算数组大小为11
    printf("   int arr4[] = {[0] = 1, [5] = 2, [10] = 3};\n");
    printf("   数组大小: %zu\n", sizeof(arr4)/sizeof(arr4[0]));
    printf("   结果: ");
    for(int i = 0; i < sizeof(arr4)/sizeof(arr4[0]); i++) {
        printf("%d ", arr4[i]);
    }
    printf("\n\n");
    
    // 5. 稀疏数组初始化（非常适合使用定位符）
    printf("5. 稀疏数组初始化（非常适合使用定位符）:\n");
    int sparse[100] = {
        [0] = 1,
        [50] = 2,
        [99] = 3
    }; // 只有3个位置有值，其余都是0
    printf("   int sparse[100] = {[0] = 1, [50] = 2, [99] = 3};\n");
    printf("   检查几个关键位置:\n");
    printf("   sparse[0] = %d\n", sparse[0]);
    printf("   sparse[1] = %d\n", sparse[1]);
    printf("   sparse[50] = %d\n", sparse[50]);
    printf("   sparse[99] = %d\n", sparse[99]);
    printf("\n");
    
    // 6. 字符数组的定位初始化
    printf("6. 字符数组的定位初始化:\n");
    char str[10] = {
        [0] = 'H',
        [1] = 'e',
        [2] = 'l',
        [3] = 'l',
        [4] = 'o',
        [5] = '\0' // 字符串终止符
    };
    printf("   char str[10] = {[0]='H',[1]='e',[2]='l',[3]='l',[4]='o',[5]='\\0'};\n");
    printf("   结果: %s\n", str);
    printf("\n");
    
    // 7. 二维数组的C99特性初始化
    printf("7. 二维数组的C99特性初始化:\n");
    
    // 7.1 使用嵌套大括号初始化
    printf("7.1 使用嵌套大括号初始化:\n");
    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printf("   int matrix1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};\n");
    printf("   结果:\n");
    for(int i = 0; i < 3; i++) {
        printf("   ");
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // 7.2 使用定位符初始化二维数组
    printf("7.2 使用定位符初始化二维数组:\n");
    int matrix2[3][3] = {
        [0][0] = 1, [0][2] = 2,
        [1][1] = 3,
        [2][0] = 4, [2][2] = 5
    };
    printf("   int matrix2[3][3] = {[0][0]=1, [0][2]=2, [1][1]=3, [2][0]=4, [2][2]=5};\n");
    printf("   结果:\n");
    for(int i = 0; i < 3; i++) {
        printf("   ");
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // 7.3 二维数组的部分初始化
    printf("7.3 二维数组的部分初始化:\n");
    int matrix3[3][3] = {
        {1},        // 第一行: 1, 0, 0
        {0, 2},     // 第二行: 0, 2, 0
        {0, 0, 3}   // 第三行: 0, 0, 3
    };
    printf("   int matrix3[3][3] = {{1},{0,2},{0,0,3}};\n");
    printf("   结果:\n");
    for(int i = 0; i < 3; i++) {
        printf("   ");
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // 7.4 二维数组的混合初始化
    printf("7.4 二维数组的混合初始化:\n");
    int matrix4[3][4] = {
        [0] = {1, 2},           // 第一行: 1, 2, 0, 0
        [1][1] = 5, [1][3] = 6, // 第二行: 0, 5, 0, 6
        [2] = {[0] = 7, [2] = 8} // 第三行: 7, 0, 8, 0
    };
    printf("   int matrix4[3][4] = {[0]={1,2}, [1][1]=5, [1][3]=6, [2]={[0]=7, [2]=8}};\n");
    printf("   结果:\n");
    for(int i = 0; i < 3; i++) {
        printf("   ");
        for(int j = 0; j < 4; j++) {
            printf("%d ", matrix4[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // 7.5 不指定第一维大小的二维数组初始化
    printf("7.5 不指定第一维大小的二维数组初始化:\n");
    int matrix5[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printf("   int matrix5[][3] = {{1,2,3},{4,5,6},{7,8,9}};\n");
    printf("   数组行数: %zu\n", sizeof(matrix5)/sizeof(matrix5[0]));
    printf("   结果:\n");
    for(int i = 0; i < sizeof(matrix5)/sizeof(matrix5[0]); i++) {
        printf("   ");
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix5[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
