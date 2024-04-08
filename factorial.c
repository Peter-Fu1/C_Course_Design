#include "headers/factorial.h" // 链接头文件
#include <stdio.h>

// 进行阶乘计算的函数
static int computeFactorial(int n);

// 提供给main.c调用的接口函数
void performFactorialOperation() {
    int number;
    printf("请输入一个非负整数计算阶乘：");
    scanf("%d", &number);

    // 检查输入是否有效
    if (number < 0) {
        printf("错误：请输入一个非负整数。\n");
        return;
    }

    int result = computeFactorial(number);
    printf("%d 的阶乘是：%d\n", number, result);
}

// 实际执行阶乘计算的函数
static int computeFactorial(int n) {
    if (n <= 1) return 1; // 基础情况
    return n * computeFactorial(n - 1); // 递归计算
}
