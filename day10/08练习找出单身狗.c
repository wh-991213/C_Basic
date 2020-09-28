#include<stdio.h>
#pragma warning(disable:4996)

//第一种
int main0801()
{
	int arr[] = { 1,2,3,4,5,1,2,3,7,5,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++)
	{
		int count = 0;
		for (int j = 0; j < sz; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		if (count == 1)
		{
			printf("单身狗:%d\n", arr[i]);
			break;
		}
	}
	return 0;
}


//第二种
	//观察
	/*
	3^3   011^011  =0
	5^5   101^101  =0
	a^a   =0
	... ...
	*/

	/*
	0^5    000^101 =101=5
	0^3    000^011 =011=3
	0^a    =a
	... ...
	*/

	/*
	3^5^3  011^101^011 = 110^011 = 101=5
	3^3^5  011^011^101 = 000^101 = 101=5
	从这里可以看出异或是满足交换律的
	*/
int main0802(void)
{
	int arr[] = { 1,2,3,4,5,1,2,3,7,5,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = 0;
	for (int i = 0; i < sz; i++)
	{
		ret=ret^arr[i];
	}
	printf("单身狗:%d\n",ret);
	return 0;
	//同上面算法比较，上面的执行次数是n的平方，这个是n
}


//有序数组中查找数字  方法1：从前往后遍历；这种算法最坏的情况需要循环n次
int main0803(void)
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int k = 7;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		if (k == arr[i])
		{
			printf("找到了，数组下标为%d\n", i);
			break;
		}
	}
	if (i == sz)
		printf("没有找到\n");
	return 0;
}


//有序数组中查找数字  方法2：折半查找算法也叫二分查找算法  需要执行大约log2^n次    如2^32只需要查32次
int main0804()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10 };
	int k = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;//左下标
	int right =sz-1;//右下标
	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			printf("找到了，下标是%d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("找不到\n");
	}
	return 0;
}