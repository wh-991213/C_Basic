#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//模拟用户登录，并且只能登录三次（只允许输入三次密码，如果密码正确则提示登录成功，如果三次均错误，则退出程序）
int main1201()
{
	int i = 0;
	char password[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码\n");
		scanf("%s", password);
		if (strcmp(password, "123456") == 0)//注意==不能用来比较两个字符串是否相等，应该使用一个库函数strcmp
		{
			printf("登录成功\n");
			break;
		}
		else
			printf("密码错误\n");
	}
	if (i == 3)
		printf("三次密码均错误，退出程序\n");
	return 0;
}

