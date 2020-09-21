#include<stdio.h>

//char			字符类型
//short			短整型
//int			整型
//long			长整型
//long long		长长整型
//float			单精度浮点数
//double		双精度浮点数

int main0101()
{
	//那么问题来了，这些数据类型在内存中所占的字节大小是多少？？？

	//1Byte=8bit
	//不同的编译器所占内存空间大小不一
	printf("字符型：%d\n", sizeof(char));//1B
	printf("短整型：%d\n", sizeof(short));//2B
	printf("整型：%d\n", sizeof(int));//4B
	printf("长整型：%d\n", sizeof(long));//4B
	printf("长长整型：%d\n", sizeof(long long));//8B
	printf("单精度浮点型：%d\n", sizeof(float));//4B
	printf("双精度浮点型：%d\n", sizeof(double));//8B
	return 0;
}