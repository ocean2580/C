#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
    int a[10];//���ÿ�����ʵĳ���
    char sen[50];
    int i = 0, j = 0, sum = 0, len1;
    printf("������һ���ַ���");
    gets_s(sen);
    len1 = strlen(sen);

    for (int n = 0; n < len1; n++) {
        if (sen[n] == '\0') exit(0);
        j++;//���ַ�����
        if (sen[n] ==' ') {
            a[i] = j;//���ʳ���
            i++;//���ʸ���
            j = 0;//����
        }
    }
    
    for (int m = 0; m < i; m++) {
        sum += a[m];
    }
    printf("�ܹ���%d�����ʣ�ƽ������Ϊ%d\n", i+1, sum / (i+1));

    return 0;
}