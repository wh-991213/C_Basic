#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Bubble_Sort(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}
int main0901(void)
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble_Sort(arr, sz);//Bubble_Sort传了个整型数组，并用整型数组接收；只能排序整型
	for (int j = 0; j < sz; j++)
	{
		printf("%d ", arr[j]);
	}
	return 0;
}



//数组排序 - qsort - 库函数 - 所用的算法思想是 - quick sort
//qsort参数原型
//void qsort(void *base, size_t num, size_t width, int(__cdecl *compare)(const void *elem1, const void *elem2));
//分解参数：
//void qsort(void *base, - Start of target array:目标数组的起始位置
//			 size_t num, - Array size in elements:数组中的元素个数
//			 size_t width, - Element size in bytes:元素大小，以字节为单位
//			 int( *cmp)(const void *e1,const void *e2) - Comparison function:  函数指针的两个参数是：待比较的两个元素的地址		
//上面写成void*的作用：可以接收任意类型的地址	
//el1 less than el2 - return - < 0
//el1 equivalent to el2 - return - 0
//el1 greater than el2 - return - > 0
//qsort函数所在头文件<stdlib.h>

//(((
int cmp_int(const void *e1, const void *e2)//用于qsort的第4个参数 - 用于比较两个整型值 - e1和e2用于接收两个值并比较
{
	//*e1 和 *e2 - 因为它是void*类型指针，所以不能解引用
	return  *(int*)e1 - *(int*)e2;//把e1强制类型转换成int* - 就变成一个整型的地址 - 再解引用访问整型
}
void test6()
{
	//使用qsort函数排序arr
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);//这里的是把1的地址和3的地址传给了cmp_int - 然后用cmp_int函数里的两个指针接收
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
//)))

//(((
int cmp_float(const void* e1, const void* e2)
{
	/*if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 > *(float*)e2)
		return 1;
	else
		return -1;*/
		//or
		//return *(float*)e1 - *(float*)e2;//warning:从float转换到int，可能丢失数据
	return(int)*(float*)e1 - *(float*)e2;//避免警告 - 把float强制类型转换成int 
}
void test7()
{
	//使用qsort函数排序f浮点型
	float f[] = { 9.0,8.0,7.0,6.0,5.0,4.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_float);
	for (int i = 0; i < sz; i++)
	{
		printf("%f ", f[i]);
	}
}
//)))

//(((
struct Stu
{
	char name[20];
	int age;
};
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;//强制类型转换 - 结构体类型的指针
}
void test8()
{
	//排序结构体年龄
	struct Stu s[3] = { {"zhangshan",20}, {"lisi",30}, {"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
}
//)))

//(((
int cmp_stu_by_name(const void* e1, const void* e2)
{
	//比较名字 - 比较字符串 - 不能直接用> < = - 应该用strcmp函数
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void test9()
{
	struct Stu s[3] = { {"zhangshan",20}, {"lisi",30}, {"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}
//)))

int main0902(void)
{
	//test6();//排序arr整型数组
	//test7();//排序f浮点型数组
	//test8();//排序结构体中的年龄
	test9();//排序结构体中的名字
	return 0;
}

//void*类型
int main0903(void)
{
	int a = 10;
	int* pa = &a;
	char* pc = &a;//warning:从int*到char*的类型char*的类型不兼容

	//有没有一种指针能够接收任意一种类型的元素地址？？？ - void*
	char ch = 'w';
	void* p = &a;// - 无类型指针 - 万能指针
	p = &ch;
	//void*类型的指针 - 可以接收任意类型的地址
	//*p = 0; //err - 我们曾经说过指针类型决定了解引用的时候访问几个字节 - 现在又是无类型指针 
	//p++;//err - 指针进行加减整数的时候也要确定它的类型
	//对于void*类型的指针 - 不能进行解引用操作 - 不能进行加减整数的操作
	return 0;
}



//(((
//void Bubble_Sort1(int arr[], int sz)
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;
//		for (int j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}


