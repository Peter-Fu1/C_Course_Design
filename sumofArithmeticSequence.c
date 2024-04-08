#include <stdio.h>
#include "headers/sumofArithmeticSequence.h"

void sumofArithmeticSequence() {
    int a1, n;
    float d;
    printf("请输入等差数列的首项：");
    scanf("%d", &a1);
    printf("请输入等差数列的公差：");
    scanf("%f", &d);
    printf("请输入等差数列的项数：");
    scanf("%d", &n);

    // 计算第n项
    float an = a1 + (n - 1) * d;
    // 计算前n项和
    float Sn = n * (a1 + an) / 2;

    printf("等差数列的前%d项和为: %.2f\n", n, Sn);
}