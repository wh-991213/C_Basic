//在VS中使用scanf、strcpy、sprintf函数等，会提示C4996错误
//方法1（需放在开头）
#define _CRT_SECURE_NO_WARNINGS
//方法2
#pragma warning(disable:4996)
#include<stdio.h>

int main0201(viod)

{
	//黄瓜3元/斤 
	//常量：在程序运行过程中，其值不能发生改变的量
	//const：约束使其为常量
	const int price = 3;
	//price = 5;//err

	//变量：在程序运行过程中，其值可以发生改变的量
	int weight;
	printf("请输入购买斤数：\n");
	//scanf：通过键盘输入赋值；&：取地址运算符
	scanf("%d", &weight);

	int sum = price * weight;

	printf("%d\n", sum);
	return 0;
}
