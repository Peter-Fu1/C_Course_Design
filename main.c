#include <stdio.h>
#include "headers/matrixOperation.h"
#include "headers/factorial.h"
#include "headers/sumofArithmeticSequence.h"
#include "headers/solveEquation.h"
#include "headers/setOperation.h"

void printMenu() {
    printf("简易科学计算器\n");
    printf("1. 矩阵运算\n");
    printf("2. 阶乘计算\n");
    printf("3. 等差数列求和\n");
    printf("4. 解方程\n");
    printf("5. 集合的交与并运算\n");
    printf("0. 退出\n");
    printf("请选择功能：");
}

int main() {
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // 调用矩阵运算函数
                printf("矩阵运算选项\n");
                // matrixOperation();
                break;
            case 2:
                // 调用阶乘计算函数
                performFactorialOperation();
                break;
            case 3:
                // 调用等差数列求和函数
                printf("等差数列求和选项\n");
                // sumofArithmeticSequence();
                break;
            case 4:
                // 调用解方程函数
                printf("解方程选项\n");
                // solveEquation();
                break;
            case 5:
                // 调用集合的交与并运算函数
                printf("集合的交与并运算选项\n");
                // setOperations();
                break;
            case 0:
                printf("退出程序。\n");
                break;
            default:
                printf("无效的选项，请重新选择。\n");
        }
    } while(choice != 0);

    return 0;
}
