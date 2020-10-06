#include<stdio.h>

int main0401()
{
	//无序数组变成有序数组(升序或降序)
	int arr[]= { 9,1,5,7,2,10,8,4,6,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//升序:每结束1次外循环,都会有一个最大值被推到了最右边
	//降序:每结束1次外循环,都会有一个最小值被推到了最右边
	for (int i = 0; i < sz-1; i++)
	{
		for (int j = 0; j < sz-1-i; j++)
		{
			if (arr[j] > arr[j+1])//这里>为升序;<为降序
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for (int j = 0; j < sz; j++)
	{
		printf("%d ", arr[j]);
	}

	return 0;
}



void Bubble_Sort(int arr[],int sz)
{
	for (int i = 0; i < sz-1; i++)
	{
		for (int j = 0; j < sz-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
//自定义函数实现冒泡排序
int main0402()
{
	int arr[] = { 9,1,5,7,2,10,8,4,6,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble_Sort(arr,sz);
	for (int i = 0; i < sz; i++)
	{	
		printf("%d ", arr[i]);
	}
	return 0;
}



//其实上面的这两种方法过于老实
int main0403(void)
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz - 1; i++)
	{
		int flag = 1;//假设这一趟要排序的数据已经有序
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;//本趟排序的数据其实不完全有序
			}
		}
		if (flag==1)
		{
			break;//这样写的好处是如果是这个数组{1,2,3,5,4,6,7,8,9,10}只需要两次外循环(第1次用于交换两个数的值;第2次循环结束后跳到这里结束),大大提高了效率
			//if语句里是不能break的,但如果if在循环中,break表示满足这个条件,则跳出循环
		}
	}
	for (int j = 0; j < sz; j++)
	{
		printf("%d ", arr[j]);
	}
}