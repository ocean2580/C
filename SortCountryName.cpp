#include<stdio.h>
#include<string.h>
#define M 10//�������С
#define N 150//��������
void SortString(char str[][M], int n);
int main() {
	int i, n;
	char name[N][M];
	printf("How many countries?");
	scanf_s("%d", &n);
	getchar();//���س�
	printf("Input their names:\n");
	for (i = 0; i < n; i++) {
		gets_s(name[i]);//����ÿ���ַ�(���ַ���)
	}
		SortString(name, n);
		printf("Sorted results:\n");
		for (i = 0; i < n; i++) {
			puts(name[i]);
		}
	return 0;
}

void SortString(char str[][M], int n) {
	int i, j;
	char temp[M];
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (strcmp(str[j], str[i]) < 0) {
				strcpy_s(temp, str[i]);
				strcpy_s(str[i], str[j]);
				strcpy_s(str[j], temp);
			}
		}
	}
}