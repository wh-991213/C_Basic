//在VS中使用scanf、strcpy、sprintf函数等，会提示C4996错误
//方法1（需放在开头）
#define _CRT_SECURE_NO_WARNINGS
//方法2
#pragma warning(disable:4996)
//方法3
//在使用scanf函数时，使用scanf_s替代，但不采取。因为scanf_s并不是C语言中的函数，而是VS编译器下的。也就是说在VS中使用scanf_s可行，但是在其它编译器下不一定可行
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
