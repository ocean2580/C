#include<stdio.h>
#define N 40
int ReadScore(int score[]);
void PrintScore(int score[], int n);
void SelectionSort(int a[], int n, int(*compare)(int a, int b));
int Ascending(int a, int b);
int Descending(int a, int b);
void Swap(int* a, int* b);
int main() {
    int score[N], n;
    int order;
    n = ReadScore(score);
    printf("学生总数为%d\n",n);
    printf("按1进行升序排列\n");
    printf("按2进行降序排列\n");
    scanf_s("%d", &order);
    printf("原顺序为\n");
    PrintScore(score,n);
    if (order == 1) {
        SelectionSort(score, n, Ascending);
        printf("升序排列\n");
    }
    else {
        SelectionSort(score, n, Descending);
        printf("降序排列\n");
    }
    PrintScore(score, n);
    return 0;
}
//输入值为负，结束输入并返回学生人数。
int ReadScore(int score[]) {
    int i = -1;
    do {
        i++;
        printf("输入成绩:");
        scanf_s("%d", &score[i]);
    } while (score[i]>0);
    return i;
}
//利用返回值n遍历
void PrintScore(int score[],int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%4d",score[i]);
    }
    printf("\n");
}
//调用函数指针compare
void SelectionSort(int a[], int n, int(*compare)(int a, int b)) {
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
        k = i;//k指下标
        for (j = i + 1; j < n; j++) {
           
            if ((*compare)(a[j], a[k])) k = j;//取数组中对应位置的两个值a[j],a[k]
        }
        if (k != i)  Swap(&a[k], &a[i]);//每轮结束,进行对调
    }
}
//
int Ascending(int a, int b) {
    return a < b;
}
int Descending(int a, int b) {
    return a > b;
}

void Swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}