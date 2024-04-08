#include <stdio.h>
#include <math.h>

void solveQuadraticEquation();
void solveLinearEquations();

void solveEquation() {
    int choice;
    do {
        printf("请选择方程类型：\n1. 解一元二次方程\n2. 解二元一次方程组\n0. 返回上一级\n请输入选择（0-2）：");
        scanf("%d", &choice);
        if (choice == 0) return; // 返回到main.c的switch(choice)中
        
        switch (choice) {
            case 1:
                solveQuadraticEquation();
                break;
            case 2:
                solveLinearEquations();
                break;
            default:
                printf("无效的选择，请重新输入。\n");
                break;
        }
    } while (choice < 0 || choice > 2);
}

void solveQuadraticEquation() {
    double coefficients[4]; // 存放a, b, c和等式右边的值
    printf("请输入一元二次方程的二次项系数、一次项系数、常数项以及等号右边的结果（空格分隔）：");
    scanf("%lf %lf %lf %lf", &coefficients[0], &coefficients[1], &coefficients[2], &coefficients[3]);

    // 将方程化为标准形式
    coefficients[2] -= coefficients[3];
    coefficients[3] = 0;

    double a = coefficients[0], b = coefficients[1], c = coefficients[2];
    double discriminant = b*b - 4*a*c;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2*a);
        double root2 = (-b - sqrt(discriminant)) / (2*a);
        printf("方程有两个不同的实数解：%.2lf 和 %.2lf\n", root1, root2);
    } else if (discriminant == 0) {
        double root = -b / (2*a);
        printf("方程有两个相同的实数解（一个实数解）：%.2lf\n", root);
    } else {
        double realPart = -b / (2*a);
        double imaginaryPart = sqrt(-discriminant) / (2*a);
        printf("方程有两个复数解：%.2lf+%.2lfi 和 %.2lf-%.2lfi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }
}

void solveLinearEquations() {
    double a, b, c, d, e, f; // 系数矩阵和常数项
    printf("请输入二元一次方程组的系数和常数项（a, b, c, d, e, f）：\n");
    printf("方程1的形式为 ax + by = e\n");
    printf("方程2的形式为 cx + dy = f\n");
    scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);

    double denominator = a*d - b*c; // 计算分母
    if (denominator == 0) {
        printf("该方程组没有解或有无限多解。\n");
    } else {
        double x = (e*d - b*f) / denominator;
        double y = (a*f - e*c) / denominator;
        printf("方程组的解为：x = %.2lf, y = %.2lf\n", x, y);
    }
}

int main() {
    solveEquation();
    return 0;
}
