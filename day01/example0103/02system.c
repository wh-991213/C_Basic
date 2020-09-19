#include<stdio.h>
#include<stdlib.h>

int main0201()
{
	//cmd命令：calc计算器；notepad记事本；mspaint画图板...
	//system所在头文件<stdlib.h>；可以打开一个外部的应用程序，如果带路径需要使用\\或者/
	//定义一个整型类型value，将system执行的结果赋值给value
	int value=system ("calc");
	//%d：是一个占位符,打印整型十进制数据 
	printf("%d\n", value);
	return 0;
}
