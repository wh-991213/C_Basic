#include<stdio.h>

//一
//void test(int arr[])//ok - 传过来的是一个整型数组，用整型数组接收
//{}
//void test(int arr[10])//ok
//{}
//void test(int* arr)//ok - 传过来的是首元素地址，用指针接收
//{}
//void test2(int* arr[20])//ok - 完美吻合
//{}
//void test2(int** arr)//ok - 传过来的是首元素地址也就是一级指针地址，用二级指针接收
//{}
//一维数组传参
int main0401(void)
{
	int arr[10] = { 0 };
	int* arr2[20] = { 0 };
	//test(arr);
	//test2(arr2);
	return 0;
}


//二
//void test(int arr[3][5])//ok
//{}
//void test(int arr[][5])//ok - 行是可以省略的
//{}
//void test(int arr[3][])//err - 列是不可以省略的
//{}
//void test(int arr[][])//err - 行和列不能同时省略
//对于二维数组来说，可以不知道有多少行，但是必须知道一行有多少元素 - 也就是说只能省略第一个[]中的数字

//void test1(int* arr)//err - 我们知道二维数组的首地址其实是第一行的地址，第一行的地址	是一维数组的地址，则不能用整型指针存储
//{}
//void test1(int* arr[5])//err - 这里arr是一个数组，它是5个int*类型的元素
//{}
//void test1(int** arr)//err - 这里arr是一个二级指针，应该存放一级指针变量的地址，数组的地址不能放到二级指针里
//{}
void test1(int(*arr)[5])//ok - 传过来是一个一维数组，用数组指针接收
{}
//二维数组传参
int main0402(void)
{
	int arr[3][5] = { 0 };
	//test(arr);
	test1(arr);
	return 0;
}


//三
void print(int* p, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(p + i));
	}
}
//指针传参
int main0403(void)
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(p, sz);
	return 0;
}

//四
//思考当一个函数的参数部分为一级指针的时候，函数能接收什么参数？？？
void test2(int* p)
{
}
void test3(char* p)
{
}
int main0404(void)
{
	int a = 10;
	int* p1 = &a;
	test2(&a);//ok - 变量的地址
	test2(p1);//ok - 一级指针变量

	char ch = 'w';
	char* pc = &ch;
	test3(&ch);//ok - 变量的地址
	test3(pc);//ok - 一级指针变量
	//如果参数部分是一级指针：可以传变量的地址；或者是传一级指针变量
	return 0;
}
//同理当一个函数的参数部分为二级指针的时候，函数能接收什么参数？？？
void test4(int** ptr)
{
	printf("num=%d\n", **ptr);
}
int main0405(void)
{
	int n = 10;
	int* p = &n;
	int** pp = &p;
	test4(pp);//ok - 二级指针变量
	test4(&p);//ok - 一级指针变量的地址
	return 0;
}
void test5(int** p)
{
}
int main0406(void)
{
	int* ptr;
	int** pp = &ptr;
	test5(&ptr);//ok - 一级指针变量的地址
	test5(pp);//ok - 二级指针变量

	int* arr[10];
	test5(arr);//ok - 指针数组的变量
	//如果参数部分是二级指针：可以传二级指针变量；或者是传一级指针变量的地址；或者是传指针数组的变量
	return 0;
}

