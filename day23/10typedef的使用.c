#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//typedef   简化结构体关键字
struct Person
{
	char name[63];
	int age;
};
//作用可以将struct Person起一个别名myPerson
typedef struct Person myPerson;
int main1001()
{
	
	struct Person P1 = { "张三",19 };
	myPerson P2 = { "李四",20 };

	return EXIT_SUCCESS;
}


//或者也可以这样写
//格式：typedef  原名  别名
typedef struct Person1
{
	char name[63];
	int age;
}myPerson1;

int main1002(void)
{
	struct Person1 P1 = { "张三",19 };
	myPerson1 P2 = { "李四",20 };
	return 0;
}