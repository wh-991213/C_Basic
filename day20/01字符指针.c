#include<stdio.h>


int main0101()
{
	//字符指针
	char ch = 'w';
	char* pc = &ch;
	return 0;
}

int main0102(void)
{
	char arr[] = "abcdef";
	char* pc = arr;
	printf("%s\n", arr);
	printf("%s\n", pc);
	return 0;
}

int main0103(void)
{
	char* p = "abcdef";//"abcdef"是一个常量字符串。这里不是把字符串的内容赋给p，而是把这个字符串的首地址赋给p
	printf("%c\n", *p);//说明p存的就是a的地址
	printf("%s\n", p);//根据首元素地址往后访问

	//为什么"abcdef"是常量字符串呢？？？
	//试着改变其值 
	*p = 'w';
	printf("%c\n", *p);
	//如果调试会发现，它写入访问权限冲突，也证实了"abcdef"是一个常量
	//这个代码最准确的写法是加上const。因为p指向的这个常量字符串本身是不可修改的，这样加上让代码更具有保护性
	//const char* p = "abcdef";
	return 0;
}

int main0104(void)
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";
	char* p1 = "abcdef";
	char* p2 = "abcdef";

	//1.
	/*if (arr1 == arr2)
	{
		printf("hehe\n");
	}
	else
	{
		printf("haha\n");
	}*/
	//结果是打印haha，因为在abcdef创建了一个空间，abcdef创建了另一个空间，比较地址当然是不同的

	//2.
	if (p1 == p2)
	{
		printf("hehe\n");
	}
	else
	{
		printf("haha\n");
	}
	//结果是打印hehe，p1和p2都是常量字符串，在内存中实际上只存一份，这里不管是p1还是p2指的是同一块空间
	return 0;
}