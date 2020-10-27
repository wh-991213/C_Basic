#include<stdio.h> 
#define N_VALUES 5//用于0204

int main0201()
{
	//不使用下标访问，使用指针访问
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	/*for (int i = 0; i < 10; i++)
	{
		printf("%d\n", *(arr + i));//1 2 3 4 5 6 7 8 9 10
	}*/
	
	int* p = arr;
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", *p);//1 3 5 7 9
		p += 2;//注意不要越界
	}
	printf("\n");
	

	int* q = &arr[8];
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", *q);//9 7 5 3 1
		q -= 2;
	}
	return 0;
}

int main0202(void)
{
	//指针-指针
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d\n", &arr[9] - &arr[0]);//9
	//指针-指针得到的不是字节数40-4=36；而是指针和指针之间元素个数-1

	//使用整型指针-字符指针？？？
	char ch[5] = { 0 };
	printf("%d\n", &arr[9] - &ch[0]);//err
	//这样写是不对的；当指针-指针，那这两个指针一定是指向同一块空间的 
	return 0; 
}

int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;//这就是之间的元素长度
}
int main0203(void)
{
	//求字符串长度
	//1.strlen 
	//2.之前使用了递归模拟实现strlen
	//3.
	char arr[] = "bit";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}

//指针关系运算
int main0204(void)
{
	float values[N_VALUES];//5
	float* vp;
	//1
	/*for (vp = &values[N_VALUES]; vp > &values[0];)
	{
		*--vp = 0; 
	}*/
	//代码修改如下
	//2.
	for (vp = &values[N_VALUES - 1]; vp >= &values[0]; vp--)
	{
		*vp = 0;
	}
	//尽量使用第1种写法,虽然第1种比第2种不好理解
	//因为实际在绝大部分的编译器上是可以顺利完成任务的，然而我们还是应该避免第2种写法，因为标准并不保证它可行
	//标准规定：
	/*允许指向数组元素的指针与指针数组最后一个元素后面的那个内存位置的指针比较，但是不允许与指针第一个元素
	之前的那个内存位置的指针进行比较*/
	return 0;
}