#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>

int main0201()
{
	//strcpy这个库函数需要注意
	//1.原字符串必须以'\0'结束
	//2.目标空间必须足够大
	//3.目标空间必须可变，不能是常量字符串
	char arr1[] = "abcdefghi";
	char arr2[] = "bit";
	strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}


char* my_strcpy(char* dest, const char* src)
{
	//保证指针的有效性
	assert(dest != NULL);
	assert(src != NULL);
	//备份一份目的空间的起始地址 - 因为strcpy这个函数的返回值是char*
	char* ret = dest;
	//while (*src)
	//{
	//	*dest = *src;
	//	dest++;
	//	src++;
	//}
	//*dest = *src;//拷贝'\0'
	//  |   |
	//  |   |
	while (*dest++ = *src++)
	{
		;
	}
	//返回目标空间的起始位置
	return ret;
}
//模拟实现strcpy
int main0202()
{
	char arr1[] = "abcdefghi";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

//strncpy
int main0203()
{
	char arr1[5] = "abc";
	char arr2[] = "hello world!";
	//长度不受限制，只以'\0'为标志；程序挂了，但依然能够输出 - 这个函数是不安全的
	//strcpy(arr1, arr2);
	//长度受限制 - 相对安全
	strncpy(arr1, arr2, 4);
	printf("%s\n", arr1);
	return 0;
}

int main0204()
{
	char arr1[10] = "abcdef";
	char arr2[] = "hell o";
	//只会拷贝指定的长度
	strncpy(arr1, arr2, 5);
	printf("%s\n", arr1);
	return 0;
}

int main0205()
{
	char arr1[10] = "abcdefgh";
	char arr2[] = "bit";
	//原字符串长度小于要指定拷贝的数量，则后面补'\0'
	strncpy(arr1, arr2, 6);
	printf("%s\n", arr1);
	return 0;
}

int main0206()
{
	char arr1[10] = "abcdefg";
	//在拷贝的过程中，如果遇到'\0'，则目标字符串后'\0'后面的内容不会被打印；
	//char arr2[] = "bit";
	//char arr2[] = "bi\0t";

	//注意区分空格
	char arr2[] = "bit ";
	strncpy(arr1, arr2, 4);
	printf("%s\n", arr1);       
	return 0;
}


char* my_strncpy(char* str1, const char* str2, int n)
{
	assert(*str1&&*str2);
	while (n)
	{
		*str1 = *str2;
		str1++;
		str2++;
		n--;
	}
}
//模拟strncpy
int main0207()
{
	char arr1[10] = "abcdefg";
	char arr2[] = "bit";
	my_strncpy(arr1, arr2, 4);
	printf("%s\n", arr1);
	return 0;
}