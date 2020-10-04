#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main0101(void)
{
	//数组定义：数据类型 数组名[元素个数]={值1，值2，值3}
	//数组下标：数组名[下标]
	//数组下标是从0开始到数组元素个数-1
	//int arr1[10] = { 9,4,2,1,8,5,3,6,10,7 };
	//数组名是一个常量，不允许被赋值
	//arr1 = 100;//err
		

	//不完全初始化，剩下的元素默认初始化为0
	int arr2[5]={1,2,3,4};
	char arr3[5] = { 'a','b' };//同char arr3[5]={'a',98};
	char arr4[5] =  "ab" ;//这里放到数组里的元素有a,b,'\0'(发现还是有3个0，但注意第1个0是放进去的'\0',而不是默认给的0)

	//如果没有元素个数呢？？？
	char arr5[] = "abcde";//它会根据初始化的内容来确定元素个数


	//下面代码的结果？？？
	char arr6[] = "abc";
	char arr7[] = { 'a','b','c' };
	printf("%d\n", sizeof(arr6));//4
	printf("%d\n", sizeof(arr7));//3
	printf("%d\n", strlen(arr6));//3
	printf("%d\n", strlen(arr7));//15//这里是一个随机值，strlen会继续往下找，直到'\0'

	return 0;
}


int main0102(void)
{
	char arr[] = "abcdef";
	//打印数组元素
	//printf("%c\n", arr[3]);

	//打印数组所有元素(使用循环)
	for (int i = 0; i < (int)strlen(arr); i++)//这里有个警告，strlen返回无符号数;强制类型转换int；不过通常不么写，而是在上面写int len=strlen(arr)	
	{
		printf("%c ", arr[i]);
	}
	printf("\n");


	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}


//一维数组在内存中的存储
int main0103()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//打印数组每个元素的地址
	for (int i = 0; i < sz; i++)
	{
		printf("&arr[%d]=%p\n", i,&arr[i]);
	}
	//打印结果
		//&arr[0] = 000000051B5BFBA8
		//&arr[1] = 000000051B5BFBAC
		//&arr[2] = 000000051B5BFBB0
		//&arr[3] = 000000051B5BFBB4
		//&arr[4] = 000000051B5BFBB8
		//&arr[5] = 000000051B5BFBBC
		//&arr[6] = 000000051B5BFBC0
		//&arr[7] = 000000051B5BFBC4
		//&arr[8] = 000000051B5BFBC8
		//&arr[9] = 000000051B5BFBCC
	//我们发现在一维数组中每个元素都是由低地址到高地址根据数据类型所占字节大小依次进行存储（连续的）
	//数组名是一个指向数组首地址的一个地址常量,可不用&
	//printf("%p\n", arr);

	return 0;
}


//一维数组在内存中所占的大小
int main0104(void)
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("数组大小：%d\n", sizeof(arr));//4*10=40B
	printf("数组元素大小：%d\n", sizeof(arr[0]));//4*1=4
	printf("数组元素个数：%d\n",sizeof(arr) / sizeof(arr[0]));//40/4=10
	return 0;
}