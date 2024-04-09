#include <stdio.h>
#include <stdlib.h>
#include "headers/setOperation.h"

void inputSet(int *set, int size);
int isInSet(int element, int *set, int size);
void printSet(int *set, int size);

void setOperation() {
    int size1, size2;
    printf("输入第一个集合的元素数量：");
    scanf("%d", &size1);
    int *set1 = (int *)malloc(size1 * sizeof(int));

    printf("输入第二个集合的元素数量：");
    scanf("%d", &size2);
    int *set2 = (int *)malloc(size2 * sizeof(int));

    printf("依次输入第一个集合中的元素：\n");
    inputSet(set1, size1);
    
    printf("依次输入第二个集合中的元素：\n");
    inputSet(set2, size2);

    int *unionSet = (int *)malloc((size1 + size2) * sizeof(int));
    int *intersectionSet = (int *)malloc((size1 < size2 ? size1 : size2) * sizeof(int));
    int unionSize = 0, intersectionSize = 0;

    // 计算并集和交集
    for (int i = 0; i < size1; i++) {
        unionSet[unionSize++] = set1[i]; // 先添加第一个集合的所有元素到并集
        if (isInSet(set1[i], set2, size2) && !isInSet(set1[i], intersectionSet, intersectionSize)) {
            intersectionSet[intersectionSize++] = set1[i]; // 如果元素同时存在于两个集合中，添加到交集
        }
    }

    for (int i = 0; i < size2; i++) {
        if (!isInSet(set2[i], unionSet, unionSize)) {
            unionSet[unionSize++] = set2[i]; // 添加第二个集合中独有的元素到并集
        }
    }

    printf("两个集合的交集是：\n");
    printSet(intersectionSet, intersectionSize);
    
    printf("两个集合的并集是：\n");
    printSet(unionSet, unionSize);

    // 释放内存
    free(set1);
    free(set2);
    free(unionSet);
    free(intersectionSet);
}


void inputSet(int *set, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &set[i]);
    }
}

int isInSet(int element, int *set, int size) {
    for (int i = 0; i < size; i++) {
        if (set[i] == element) {
            return 1; // 元素在集合中
        }
    }
    return 0; // 元素不在集合中
}

void printSet(int *set, int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
}
