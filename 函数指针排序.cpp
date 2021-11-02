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
    printf("ѧ������Ϊ%d\n",n);
    printf("��1������������\n");
    printf("��2���н�������\n");
    scanf_s("%d", &order);
    printf("ԭ˳��Ϊ\n");
    PrintScore(score,n);
    if (order == 1) {
        SelectionSort(score, n, Ascending);
        printf("��������\n");
    }
    else {
        SelectionSort(score, n, Descending);
        printf("��������\n");
    }
    PrintScore(score, n);
    return 0;
}
//����ֵΪ�����������벢����ѧ��������
int ReadScore(int score[]) {
    int i = -1;
    do {
        i++;
        printf("����ɼ�:");
        scanf_s("%d", &score[i]);
    } while (score[i]>0);
    return i;
}
//���÷���ֵn����
void PrintScore(int score[],int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%4d",score[i]);
    }
    printf("\n");
}
//���ú���ָ��compare
void SelectionSort(int a[], int n, int(*compare)(int a, int b)) {
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
        k = i;//kָ�±�
        for (j = i + 1; j < n; j++) {
           
            if ((*compare)(a[j], a[k])) k = j;//ȡ�����ж�Ӧλ�õ�����ֵa[j],a[k]
        }
        if (k != i)  Swap(&a[k], &a[i]);//ÿ�ֽ���,���жԵ�
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