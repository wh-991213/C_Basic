#include<stdio.h>
 
/*二维数组数据类型 数组名[行][列]=
	{
		{值1,值2},
		{值3,值4}
	}
	*/
int main0201()
{
	//二维数组不完全初始化
	//int arr[3][4] = { {1,2,3},{4,5} };
	//结果
	//1 2 3 0
	//4 5 0 0
	//0 0 0 0

	//在学一维数组的时候int arr[]={1,2,3};它会根据初始化内容来确定元素个数；那在二维数组这里是怎么做的？？？
	//int arr1[][] = { { 1,2,3,4},{5,6,7,8 } }; //这里可知，二维数组里是不可以同时省略行和列的
	//int arr1[3][] = { {1,2,3,4},{5,6,7,8} };//这里可知，二维数组里是不以省略列的
	//int arr1[][4] = { {1,2,3,4},{5,6,7,8} };//这里可知，二维数组里是可以省略行的
	//只有挨着数组名的才可以省略
	
	return 0;
}


int main0202(void)
{
	//对于二维数组的使用
	/*
	int arr[3][4];
	   0   1   2   3
	0 int int int int 
	1 int int int int
	2 int int int int 
	*/
	
	int arr[3][4] = { {1,2,3},{4,5} };
	//打印二维数组里的所有元素
	int row = sizeof(arr) / sizeof(arr[0]);//行
	int column = sizeof(arr[0]) / sizeof(arr[0][0]);//列
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	//结果
	//1 2 3 0
	//4 5 0 0
	//0 0 0 0
}


int main0203(void)
{
	//二维数组在内存中的存储
	//先打印每个元素的地址
	int arr[3][4]=
	{
		{1,2,3,4},
		{2,3,4,5},
		{3,4,5,6}
	};
	int row = sizeof(arr) / sizeof(arr[0]);
	int column = sizeof(arr[0]) / sizeof(arr[0][0]);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("&arr[%d][%d]=%p\n", i, j, &arr[i][j]);
		}
	}
	//结果
		//&arr[0][0] = 000000F032AFF668
		//&arr[0][1] = 000000F032AFF66C
		//&arr[0][2] = 000000F032AFF670
		//&arr[0][3] = 000000F032AFF674
		//&arr[1][0] = 000000F032AFF678
		//&arr[1][1] = 000000F032AFF67C
		//&arr[1][2] = 000000F032AFF680
		//&arr[1][3] = 000000F032AFF684
		//&arr[2][0] = 000000F032AFF688
		//&arr[2][1] = 000000F032AFF68C
		//&arr[2][2] = 000000F032AFF690
		//&arr[2][3] = 000000F032AFF694
	//我们发现在二维数组中每一行每个元素且包括相邻的行都是由低地址到高地址依次根据数据类型所占字节大小进行存储（连续的）
	
	//int int int int
	//int int int int      ----->>int int int int int int int int... ...
	//int int int int
	//所谓二维数组的行与列是抽象的
	
	return 0;
}


int main0204(void)
{
	//二维数组在内存中所占字节大小
	int arr[3][4] = { {1,2,3,4},{2,3,4,5},{3,4,5,6} };
	printf("二维数组大小%d\n",sizeof(arr) );//行*列*数据类型=3*4*4=48B
	printf("二维数组一行的大小%d\n", sizeof(arr[0]));//4*4=16B
	printf("二维数组元素的大小%d\n", sizeof(arr[0][0]));//4B
	printf("二维数组行数%d\n", sizeof(arr) / sizeof(arr[0]));//arr/行=48/16=3
	printf("二维数组列数%d\n", sizeof(arr[0]) / sizeof(arr[0][0]));//行/元素大小=4
	return 0;
}