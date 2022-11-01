#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define M 40
// stack
typedef struct{
 double data[M];
 int top;
}Stack;
// init
InitStack(Stack *s)
{
 s->top=0;
}
// isEmpty
int StEmpty(Stack *s)
{
 if(s->top==0)
 {
   return 1;
 }
 else
 {
   return 0;
 }
}
// push
StPush(Stack *s,double x)
{
  if(s->top==M)
  {
   printf("The stack is overflow!");
  }
  else
  {
   s->top=s->top+1;
   s->data[s->top]=x;
  }
}
// pop
double StPop(Stack *s)
{
  double t;
  if(!StEmpty(s))
  {
   t=s->data[s->top];
   s->top=s->top-1;
  }
   else
  {
   printf("StPop:The stack is empty!");
   t=NULL;
  }
  return t;
}
// getTop
double StGetTop(Stack *s)
{
  double t;
  if(!StEmpty(s))
  {
   t=s->data[s->top];
  }
  else
  {
   printf("StGeTop:The stack is empty!");
   t=NULL;
  }
  return t;
}
// transfer type
int ChrTransferint(char c)
{
  int n;
  switch(c)
  {
    case '0': n=0;break;
    case '1': n=1;break;
    case '2': n=2;break;
    case '3': n=3;break;
    case '4': n=4;break;
    case '5': n=5;break;
    case '6': n=6;break;
    case '7': n=7;break;
    case '8': n=8;break;
    case '9': n=9;break;
  }
   return n;
}
/*获取两个操作符之间数字字符的个数,返回的是最后一个数字字符的位置*/
int GetNumsize(char str[],int n1)
{
  int n2=n1;
  while(isdigit(str[n2])||(str[n2])==46) // num
  {
   n2=n2+1;
  }
  return n2;
}
/*判断上个函数中获得的数字字符串中是否包含小数点，并返回它的位置，不包含，返回-1*/
int IsIncludepoint(char str[],int n1,int n2)
{
  int n3=-1;
  int i;
  for(i=n1;i<=n2;i++)
  {
    if(str[i]=='.')
     {
       n3=i;
       break;
     }
  }
  return n3;
}
// value
double Transfer(char str[],int n1,int n2,int n3)
{
 double data=0;
 int i,ct;
 if(n3<0)
 {
   for(i=n2;i>=n1;i--)
    {
      ct=ChrTransferint(str[i]);
      data=data+ct*pow(10,n2-i);/*pow(x,y)计算x的y次方的值*/
    }
 }
 else
 {
    for(i=n3-1;i>=n1;i--)
    {
      ct=ChrTransferint(str[i]);
      data=data+ct*pow(10,n3-1-i);/*pow(x,y)计算x的y次方的值*/
    }
    for(i=n3+1;i<=n2;i++)
    {
      ct=ChrTransferint(str[i]);
      data=data+ct*pow(0.1,i-n3);/*pow(x,y)计算x的y次方的值*/
    }
 }
 return data;
}
// main
main()
{
  char str[M],c;
  char a;
  int n,p1,p2,p3;    /*n为字符串长度，p1,p2,p3分别为数字字符起始位置，结束位置，和小数点位置*/
  double data;      /*存放转换后的数值*/
  int i=0;
  Stack *opter=(Stack *)malloc(sizeof(Stack));   /*存储操作符 '(':1,'+':2,'-':3, '*':4,'/':5  字符'),＝'不压栈*/
  Stack *opnd=(Stack *)malloc(sizeof(Stack));   /*存储操作数*/
  InitStack(opter);
  InitStack(opnd);
  printf("Please input formula(format:2*(3+4)#:)\n");
  n=0;
  while((a=getchar())!='\n')
  {
    str[n]=a;
    n++;
  }
  while(i<n)
   {
     char c;
     c=str[i];
     if(c=='(')
      {                                         /*c若是'('直接入栈so，i++*/
        StPush(opter,1);
        i++;
      }
     else if(isdigit(c))
      {
        p1=i;                            /*c若是数字字符，一并将后面的连续数字字符转换为数值并压栈到sd,并把i设为后面的*/
 p2=GetNumsize(str,p1);
 p3=IsIncludepoint(str,p1,p2-1);  /*第一个非数字字符的位置*/
 data=Transfer(str,p1,p2-1,p3);
        StPush(opnd,data);
        i=p2;
      }
     else if(c=='+')
       {
 StPush(opter,2);          /*c若是'+'直接入栈so,i++*/
        i++;
       }
     else if(c=='-')
       {
        StPush(opter,3);          /*c若是'-'直接入栈so,i++*/
        i++;
       }
     else if(c=='*')
       {
        if(str[i+1]=='(')      /*c若是‘*’它后面的字符是否为'('，若是直接将'*'压栈so，*/
          {                  
           StPush(opter,4);
           i++;
          }
        else
          {
           double t1,t2,t3;       /*若不是，为数字字符,将后面的连续数字字符一并转换成数值t2,sd出栈给t1,将t3=t2*t1压栈到sd*/
           t1=StPop(opnd);           /*操作符'*'不压栈so*/
           p1=i+1;
    p2=GetNumsize(str,p1);
    p3=IsIncludepoint(str,p1,p2-1);
    t2=Transfer(str,p1,p2-1,p3);
           t3=t1*t2;
           StPush(opnd,t3);
           i=p2;
           }
       }
     else if(c=='/')
       {
        if(str[i+1]=='(')
          {
           StPush(opter,5);
           i++;
          }
        else
          {
           double t1,t2,t3;
           t1=StPop(opnd);                    /*c是'/'同'*'*/
           p1=i+1;
    p2=GetNumsize(str,p1);
    p3=IsIncludepoint(str,p1,p2-1);
    t2=Transfer(str,p1,p2-1,p3);
           t3=t1/t2;
           StPush(opnd,t3);
           i=p2;
          }
       }
     else if(c==')')
       {
        double t1,t2,t3;
        int p;
        while((p=StPop(opter))!=1&&!StEmpty(opter))  /*c若是')',出栈so,判断是'+'或'-',出栈sd两个操作数，进行加减运算*/
         {                                     /*直到StPop=='('*/
           t1=StPop(opnd);
           t2=StPop(opnd);
           if(p==2)
           {
             t3=t2+t1;
             StPush(opnd,t3);
           }
           else if(p==3)
           {
             t3=t2-t1;
             StPush(opnd,t3);
           }
         }
        if(StGetTop(opter)==4)                /*然后判断so栈顶是否为'*'或者'/'*/
         {
           StPop(opter);
           t1=StPop(opnd);                    /*为'*'出栈so,出栈 sd 获得2个操作数，进行乘法操作*/
           t2=StPop(opnd);                  
           t3=t2*t1;
           StPush(opnd,t3);
         }
        else if(StGetTop(opter)==5)
         {
           StPop(opter);
           t1=StPop(opnd);         /*为'/'出栈so,出栈 sd 获得2个操作数，进行除法操作*/
           t2=StPop(opnd);
           t3=t2/t1;
           StPush(opnd,t3);
         }
         i++;
       }
     else if(c=='#')
       {
  double t1,t2,t3;            /*c若是'='，这是so内只有加减号，出栈so到p ，sd到t1,t2*/
  int p;
         while(!StEmpty(opter))
          {
           t1=StPop(opnd);
           t2=StPop(opnd);
    p=StPop(opter);
           if(p==2)
           {
             t3=t2+t1;             /*p=='+',加法运算，并将结果t3压栈sd*/
             StPush(opnd,t3);
           }
           else if(p==3)
           {
             t3=t2-t1;
      StPush(opnd,t3);         /*p=='-',减法运算，并将结果t3压栈sd*/
           }
   }
   i++;
       }
   }
if(!StEmpty(opter)||StEmpty(opnd))
{
  printf("Input error,Back!\n");  /*若so不为空，或者sd为空，且sd中只有一个元素,则输入的式子不对*/
}
else
{
  double end;
  int i;                                  /*否则，sd中的那个数据就是最后计算结果，打印输出*/
  end=StGetTop(opnd);
  printf("The value of this formula:\n");
  for(i=0;i<n;i++)
   {
   	if(str[i] == '#') {
   		printf("=");
   		continue;
	   }
     printf("%c",str[i]);
   }
  printf("%f\n",end);
}

}
