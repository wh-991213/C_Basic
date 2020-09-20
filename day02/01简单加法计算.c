#include<stdio.h>

int main(void)
{
	//定义整型变量a，将值10赋值给变量a
	//int a = 10;
	//int b = 20;
	//int c = a + b;

	//汇编语言的简单计算
	//在内存中开辟a,b,c三个变量的空间
	int a;
	int b;
	int c;

	//asm:汇编英文缩写
	__asm
	{
		//将10移动到a对应的内存中;将20移动到b对应内存中
		//将a对应的值移动到寄储器中；将b对应的值移动到寄储器中，并与a相加
		//再将寄储器中的数据移动到c，完成加法计算
		mov a, 10
		mov b, 20
		mov eax, a
		add eax, b
		mov c, eax
	}

	printf("%d\n", c);
	return 0;
}

