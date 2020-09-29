#include<stdio.h>
#include<stdlib.h>//system
#include<string.h>//strcmp
#pragma warning(disable:4996)

int main1301()
{
	//关机命令cmd
	//shutdown -s -t 60   60秒后关机
	//shutdown -a  取消关机
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	again:
	printf("请注意，你的电脑将在1分钟后关机；如果输入：我是猪，就取消关机\n");
	scanf("%s", input);

	if (strcmp(input, "我是猪") == 0)//若str1 = str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数。
		system("shutdown -a");
	else
		goto again;//goto跳转语句，跳转到上面的again:

	return 0;
}