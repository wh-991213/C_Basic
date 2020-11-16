#include<stdio.h>

//数组指针指的是指针
int main0301()
{
	int* p = NULL;//p是整型指针 - 指向整型的指针 - 可以存放整型的地址
	char* pc = NULL;//pc是字符指针 - 指向字符的指针 - 可以存放字符的地址

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//数组的地址要存起来
	//int* q = &arr; - q现在是一个整型指针，整型指针不能存放一个数组的地址
	//int* q[10] = &arr; - 当这样写时，q是一个数组，因为[]比*的算术优先级高
	int(*q)[10] = &arr; //数组指针 - 指向数组的指针 - 存放数组的地址  这里的q就是数组指针。
	//int* pa;这里pa的类型是int*
	//char* pb;这里pb的类型是char*
	//int(*q)[10];所以这里的q类型就是int(* )[10]，是一个数组指针类型
	return 0;

	//下面代码哪个是数组指针？？？
	int* p1[10];//对于p1首先和[]结合，那它一定是数组。它是一个存放指针的数组
	int(*p2)[10];//对于p2首先和*结合，那它一定是指针,指向的是一个大小为10个整型的数组。它是一个存放数组的指针
}

int main0302(void)
{
	char* arr[5];
	//需要把上面的arr存起来
	char* (*p)[5] = &arr;//p是一个指针，指向5个元素，每个元素类型是char*

	//方便对比  
	int arr1[10] = { 0 };
	int(*q)[10] = &arr1;
	return 0;
}

//利用数组指针，打印数组内容
int main0303(void)
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//数组指针的方式 
	//int(*pa)[10] = &arr;
	/*for (int i = 0; i < 10; i++)
	{
		printf("%d ", (*pa)[i]);//pa是整个数组的地址 - *pa就拿到数组了 - 相当于数组名
	}*/
	//或者
	/*for (int i = 0; i < 10; i++)
	{
		printf("%d ", *(*pa + i));//*pa == arr - pa存放的是整个数组的地址&arr - *pa把&抵消了
	}*/

	//或者不用数组指针的方式
	int* pa = arr;//pa指向数组首元素地址
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", *(pa + i));
	}
	return 0;
}


//这是老方法；参数是数组的形式
void print1(int arr[3][5], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
//一般情况下，数组指针要用到二维数组才方便
//这里传的是一维数组的地址，就应该放到数组指针里
//参数是数组指针的形式
void print2(int(*p)[5], int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			//printf("%d ", *(*(p + i) + j));//p+i表示跳过行 - *(p+i)表示找到行 - 相当于拿到了这行的数组名
			//或者
			//printf("%d ", (*(p + i))[j]);
			//或者
			//printf("%d ", *(p[i] + j));
			//或者
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}
int main0304(void)
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };//对于二维数组，它的首元素地址就是第一行的地址	
	//打印二维数组内容
	//print1(arr, 3, 5);//第一种方法
	//print2(arr, 3, 5);//第二种方法
	return 0;
}

int main0305(void)
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = arr;
	for (int i = 0; i < 10; i++)
	{
		//写法结果是一样的
		//printf("%d ", *(p + i));
		//printf("%d ", *(arr + i));

		//printf("%d ", arr[i]);
		printf("%d ", p[i]);
		//arr[i]==*(arr+i)==*(p+i)==p[i]
	}

	//总结
	//int arr[5];//arr是一个5个元素的整型数组 
	//int* parr1[10];//parr1是一个数组，数组有10个元素，每个元素的类型是int*，parr1是指针数组
	//int(*parr2)[10];//parr2是一个指针，该指针指向了一个数组，数组有10个元素，每个元素类型是int,parr2是数组指针 
	//int(*parr3[10])[5]//parr3是一个数组，该数组有10个元素，每个元素是一个数组指针，该数组指针指向的数组有5个元素，每个元素是int
	return 0;
}

