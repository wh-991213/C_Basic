#include<stdio.h>

int main0201()
{
	int arr[10] = { 0 };//整型数组
	char ch[5] = { 0 };//字符数组
	int* p[4];//存放整型指针的数组
	char* q[5];//存放字符指针的数组 
	char** arr1[5];//存放二级字符指针的数组
	return 0;
}

int main0202(void)
{
	//指针数组的用途 - 最直观的
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	//利用指针数组把a,b,c,d的地址存起来
	int* arr[4] = { &a,&b,&c,&d };
	//打印a,b,c,d的值
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", *(arr[i]));
	}
	return 0;
}

int main0203(void)
{
	//但是指针数组的用途压根就不是这样用的，也不会有这样的场景的
	//指针数组正常的用途
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };
	//现在要把arr1、arr2、arr3存起来。这三个是数组名，就是首元素地址
	int* parr[] = { arr1,arr2,arr3 };
	//打印arr1、arr2、arr3、的值
	//1.数组
	/*for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", parr[i][j]);
		}
		printf("\n");
	}*/

	//2.指针
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", *(parr[i] + j));
		}
		printf("\n");
	}
	return 0;
}