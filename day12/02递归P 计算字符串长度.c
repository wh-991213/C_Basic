#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//int my_strlen(char*str)
//{
//	//计算字符串长度；使用了临时变量count
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
int my_strlen(char*str)
{
	//递归 (大事化小）
	//my_strlen("bit");
	//1+my_strlen("it");
	//1+1+my_strlen("t");
	//1+1+1+my_strlen("");
	//1+1+1+0
	if (*str != '\0')
		return 1 + my_strlen(str + 1);
	else
		return 0;

}
//P编写函数不允许创建临时变量，求字符串长度
int main0203()
{
	char arr[] = "bit";
	//int len = strlen(arr);
	//printf("%d\n", len);

	//自定义函数实现strlen的功能
	int len = my_strlen(arr);//数组传参，传过去的不是整个数组，而是首元素地址
	printf("%d\n", len);
	return 0;
}

