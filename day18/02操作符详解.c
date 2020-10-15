#include<stdio.h>

//sizeof
int main0301(void)
{
	/*int arr[10] = { 0 };
	printf("%d\n", sizeof(int[10]));*/

	//观察下面代码，并指明结果
	short s = 0;
	int a = 10;
	printf("%d\n", sizeof(s = a + 5));
	printf("%d\n", s);
	//short类型占2个字节这是不变的，无论多少赋值给s(短整型)。这个表达式的结果s说了算
	//sizeof后面的表达式是不会真实计算的，所以s的值是不变的
	return 0;
}

int main0302(void)
{
	//~按位取反(二进制位)
	//00000000 00000000 00000000 00000000 - 0的补码
	//11111111 11111111 11111111 11111111 - 按位取反（这里是补码）
	//11111111 11111111 11111111 11111110 - 反码
	//10000000 00000000 00000000 00000001 - 原码
	//-1
	int a = 0;
	printf("%d\n", ~a);
}

//自增
int main0303(void)
{
	int a = 10;
	//printf("%d\n", ++a);//前自增；先++，后使用
	printf("%d\n", a++);//后自增；先使用，后++
	return 0;
}

//(类型)强制类型转换
int main0304(void)
{
	//int a = 3.14;
	//printf("%d\n", a);
	//这样写编译器会报警告：从double转换成 int可能丢失数据，当然这里打印结果是3
	//如果不想看到这个警告，强制类型转换
	int a = (int)3.14;
	//注意别写成这种
	//int a= int (3.14);
	return 0;
}

//逗号表达式:用逗号隔开的多个表达式；从左向右依次执行，整个表达式的结果是最后一个表达式的结果
int main0305(void)
{
	int a = 1;
	int b = 2;
	int c = (a > b, a = b + 10, a, b = a + 1);
	printf("%d\n", c);//13
	return 0;
}
