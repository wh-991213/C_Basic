#include<stdio.h>

int Add2(int x, int y)
{
	return x + y;
}
int Sub2(int x, int y)
{
	return x - y;
}
int Mul2(int x, int y)
{
	return x * y;
}
int Div2(int x, int y)
{
	return x / y;
}
int main0601()
{
	//数组是一个存放相同类型数据的存储空间
	//指针数组	
	//int* arr[5];

	//存放Add3函数的地址
	int(*pa)(int, int) = Add2;
	//如果要把多个函数的地址都存起来 - 需要一个数组，这个数组可以存放四个函数的地址 - 函数指针的数组
	int(*parr[4])(int, int) = { Add2,Sub2,Mul2,Div2 };
	//parr是一个数组，有4个元素，每个元素是函数指针类型。每个函数的返回值都是int；每个函数的参数都是int,int
	//使用
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", parr[i](2, 3));//或者printf("%d ",(*parr[i])(2,3))
	}
	return 0;
}
//char* my_strcpy(char *dest, const char *src)
//{
//	
//}
////1.写一个函数指针pf，能够指向my_strcpy
//char *(*pf)(char*, const char*);//注意这里的const不能丢掉
//
////2.写一个函数指针数组pfarr，能够存放4个my_strcpy函数的地址
////char *(*pfarr)(char*, const char*); - 先写一个函数指针
//char* (*pfarr[4])(char*, const char*);// - pfarr是一个4个元素的数组 - 每个元素的类型是（去掉pfarr[4] - char*(*)(char*,const char*))函数指针类型



