#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//compare
int compare(char a[],char b[]) {
    return strcmp(a, b);
}
int main()
{
    char  name[10], NAME[] = {"ocean"};
    char  password[20], PASSWORD[] = {"BCPTDTPTP."};
    int i = 5;
    printf("Welcome to our system!\n");
    do {
        int I = 0;
        int J = 0;
        printf("Please input your account name:\n");
        gets_s(name);
        printf("Please input your password:\n");
        gets_s(password);
      //judge
        if ( strcmp(name,NAME)==0&&strcmp(password,PASSWORD)==0) {
            printf("You're right!\n");
            exit(0);
        }
        else {
            i--;
            if (i > 0) printf("You're wrong,and you still have %d times of chance.\n", i);
            else printf("You've run out of the chances.\n");
        }
        printf("----------------------------------------------------------------------------------\n");
    } while (i!=0);
  
    return 0;
}
