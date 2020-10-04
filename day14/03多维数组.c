#include<stdio.h>


//多维数组的意思是指三维或者三维以上的数组
//三维数组具有长宽高的概念，或者说层、行、列的概念
int main0301()
{
	//三维数组定义：数据类型 数组名[层][行][列]
	int arr[2][3][4] =
	{
		{
			{1,2,3,4},
			{2,3,4,5},
			{3,4,5,6}
		},
		{
			{4,5,6,7},
			{5,6,7,8},
			{6,7,8,9}
		}

	};
	//打印三维数组的每个元素
	//打印三维数组的每个元素
	int tier = sizeof(arr) / sizeof(arr[0]);//层
	int row = sizeof(arr[0]) / sizeof(arr[0][0]);//行
	int column = sizeof(arr[0][0]) / sizeof(arr[0][0][0]);//列
	for (int i = 0; i < tier; i++)
	{
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < column; k++)
			{
				printf("%d ", arr[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;	
}


int main0302(void)
{
	//三维数组在内存中所占字节大小
	int arr[2][3][4] =
	{
		{
			{1,2,3,4},
			{2,3,4,5},
			{3,4,5,6}
		},
		{
			{4,5,6,7},
			{5,6,7,8},
			{6,7,8,9}
		}

	};
	printf("三维数组的大小：%d\n", sizeof(arr));//层*行*列*数据类型=2*3*4*int=96
	printf("三维数组一层大小：%d\n", sizeof(arr[0]));//48
	printf("三维数组一行大小：%d\n", sizeof(arr[0][0]));//16
	printf("三维数组一个元素大小：%d\n", sizeof(arr[0][0][0]));//4
	printf("层：%d\n", sizeof(arr) / sizeof(arr[0]));//2
	printf("行：%d\n", sizeof(arr) / sizeof(arr[0][0]));//6
	printf("列：%d\n", sizeof(arr[0][0]) / sizeof(arr[0][0][0]));//4
	
	return 0;
}

