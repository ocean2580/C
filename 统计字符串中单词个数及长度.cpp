#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
    int a[10];//存放每个单词的长度
    char sen[50];
    int i = 0, j = 0, sum = 0, len1;
    printf("请输入一行字符：");
    gets_s(sen);
    len1 = strlen(sen);

    for (int n = 0; n < len1; n++) {
        if (sen[n] == '\0') exit(0);
        j++;//计字符个数
        if (sen[n] ==' ') {
            a[i] = j;//单词长度
            i++;//单词个数
            j = 0;//清零
        }
    }
    
    for (int m = 0; m < i; m++) {
        sum += a[m];
    }
    printf("总共有%d个单词，平均长度为%d\n", i+1, sum / (i+1));

    return 0;
}