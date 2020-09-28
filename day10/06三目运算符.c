#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//define：宏定义常量、宏定义表达式、宏定义函数
#define MAX(a,b) (a)>(b)?(a):(b)

int main0601()
{
	//三目运算符：表达式1? 表达式2:表达式3   (如果表达式1的值为真，选择表达式2作为结果，否则选择表达式3为结果)
	int c=3 > 2 ? 5 : 7;
	printf("%d\n", c);


	//宏定义
	int a = 10;
	int b = 20;
	printf("%d\n", MAX(a,b));
	return 0;
}