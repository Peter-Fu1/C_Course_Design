#include <stdio.h>
#include "headers/matrixOperation.h"
void matrixAddition();
void matrixSubtraction();
void matrixMultiplication();

void matrixOperation() {
    int choice;
    do {
        printf("选择矩阵操作：\n1. 矩阵加法\n2. 矩阵减法\n3. 矩阵乘法\n0. 返回上一级\n请输入选择（0-3）：");
        scanf("%d", &choice);
        if (choice == 0) return; // 返回到main.c的switch(choice)中
        
        switch (choice) {
            case 1:
                matrixAddition();
                break;
            case 2:
                matrixSubtraction();
                break;
            case 3:
                matrixMultiplication();
                break;
            default:
                printf("无效的选择，请重新输入。\n");
                break;
        }
    } while (choice < 0 || choice > 3);
}

void matrixAddition() {
    int row, col;
    printf("输入矩阵的行数和列数：");
    scanf("%d %d", &row, &col);
    
    int matrix1[row][col], matrix2[row][col], sum[row][col];

    printf("输入第一个矩阵的元素：\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("输入第二个矩阵的元素：\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("两矩阵之和为：\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

void matrixSubtraction() {
    int row, col;
    printf("输入矩阵的行数和列数：");
    scanf("%d %d", &row, &col);
    
    int matrix1[row][col], matrix2[row][col], diff[row][col];

    printf("输入第一个矩阵的元素：\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("输入第二个矩阵的元素：\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            diff[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    printf("两矩阵之差为：\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }
}

void matrixMultiplication() {
    int row1, col1, row2, col2;
    printf("输入第一个矩阵的行数和列数：");
    scanf("%d %d", &row1, &col1);
    printf("输入第二个矩阵的行数和列数：");
    scanf("%d %d", &row2, &col2);
    
    // 检查是否可以进行矩阵乘法
    while (col1 != row2) {
        printf("第一个矩阵的列数必须等于第二个矩阵的行数，请重新输入：\n");
        printf("输入第一个矩阵的行数和列数：");
        scanf("%d %d", &row1, &col1);
        printf("输入第二个矩阵的行数和列数：");
        scanf("%d %d", &row2, &col2);
    }

    int matrix1[row1][col1], matrix2[row2][col2], product[row1][col2];

    printf("输入第一个矩阵的元素：\n");
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("输入第二个矩阵的元素：\n");
    for(int i = 0; i < row2; i++) {
        for(int j = 0; j < col2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // 初始化乘积矩阵
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col2; j++) {
            product[i][j] = 0;
        }
    }

    // 计算矩阵乘积
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col2; j++) {
            for(int k = 0; k < col1; k++) {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("矩阵乘积为：\n");
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col2; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
}
