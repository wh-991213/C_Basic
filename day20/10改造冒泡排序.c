#include<stdio.h>

//交换
void Swap(char*buf1, char*buf2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char temp = *buf1;
		*buf1 = *buf2;
		*buf2 = temp;
		buf1++;
		buf2++;
	}
}
//在这里实现Bubble_Sort1函数的程序员，他不知道未来排序的数据类型 - 它必须有能力能够接收任意类型的地址
//void*base - 接收任意类型地址；sz - 接收的元素个数；width - 接收单个元素大小；int(*cmp)(void*e1,void*e2) - 接收任意类型的两个参数
void Bubble_Sort1(void*base, int sz, int width, int(*cmp)(void*e1, void*e2))
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			//如果是整型数组则if(*>*)，但如果是结构体数组就需要重新设计。所以这里我们要设计一个通用的关系 
			//要比较的这两个元素如何找到这是一个问题 
			//if(cmp(base,(int*)base+1) - 这样是可以的 - 但是有一定的局限性(用户传的是别的类型)
			//if(cmp(base,(char*)base+width)把base强制类型转换成char*，(一个字节)，再加上目标元素所占字节大小(int类型跳过int个字节；double类型跳过double个字节)
			//要找到后面的元素位置：
			if (cmp((char*)base + j * width, (char*)base + (j + 1)*width) > 0)
			{
				//找到元素后交换
				//传过去char*、char*的值，对应上面char*、char*接收。width - 把宽度传过去
				Swap((char*)base + j * width, (char*)base + (j + 1)*width, width);
			} 
		}
	}
}

int cmp_int1(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void test10()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//在这里使用Bubble_Sort1的程序员一定知道自己排序的数据类型 - 就应该知道如何比较待排序数组中的元素
	Bubble_Sort1(arr, sz, sizeof(arr[0]), cmp_int1);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

struct Stu
{
	char name[20];
	int age1;
};
int cmp_stu_by_age1(const void*e1, const void*e2)
{
	return ((struct Stu*)e1)->age1 - ((struct Stu*)e2)->age1;
}
void test11()
{
	struct Stu s[3] = { {"zhangshan",20},{"lisi",30},{"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	Bubble_Sort1(s, sz, sizeof(s[0]), cmp_stu_by_age1);
}

//改造冒泡排序函数 - 排序不同类型的数据
int main(void)
{
	//test10();
	test11();
	return 0;
}
