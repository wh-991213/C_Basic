#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//通过程序随机得到一个1—100之内的数，通过输入一个数与它对应，对应则结束循环，否则继续循环
int main1501()
{
	//srand创建随机数种子；rand获取随机数。它们所在头文件<stdlib.h>
	srand((unsigned int)time(NULL));
	int value = rand() % 100 + 1;
	int input = 0;

	for (;;)
	{
		printf("请输入数字\n"); 
		scanf("%d", &input);
		if (input > value)
		{
			printf("您输入的数太大了\n");
		}
		else if (input < value)
		{
			printf("您输入的数太小了\n");
		}
		else
		{
			printf("恭喜您，猜对了\n");
			break;
		}
	}
	return 0;
}