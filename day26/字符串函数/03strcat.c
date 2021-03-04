#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
int main0301()
{
	char arr1[30] = "hello";
	char arr2[] = "world"; 
	strcat(arr1, arr2);
	printf("%s\n", arr1);
	//strcat
	//1.原字符串必须以'\0'结束  
	//2.目标空间必须足够大
	//3.目标空间必须可修改
	//4.字符串不能给自己追加
	//5.在追加的过程是以目标字符串的'\0'开始，以原字符串的'\0'结束
	return 0;
}

char* my_strcat(char* dest, const char* src)
{
	//它的返回值是目标数组的起始位置
	char* ret = dest;
	assert(dest&&src);
	//1.找到目的字符串的'\0'
	while (*dest != '\0')
	{
		dest++;
	}
	//2.追加
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
//模拟实现strcat
int main0302()
{
	char arr1[30] = "hello"; 
	char arr2[] = "world";
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}



//strncat
int main0303()
{
	char arr1[30] = "hello\0xxxxx";
	char arr2[] = "world";
	//调试发现在追加完成后会补上一个'\0'
	strncat(arr1, arr2, 3);
	printf("%s\n", arr1);
	return 0;
}

int main0304()
{
	char arr1[30] = "hello\0xxxxxxxxxx";
	char arr2[] = "wor";
	//在追加时如果指定数大于原字符串长度，它会在原字符串的最后一个字符后补'\0'
	strncat(arr1, arr2, 8);
	printf("%s\n", arr1);
	return 0;
}



char* my_strncat(char* str1, const char* str2, int n)
{
	char* ret = str1;
	assert(*str1&&*str2);
	while (*str1)
	{
		str1++;
	}
	//while (n)
	//{
	//	*str1 = *str2;
	//	str1++;
	//	str2++;
	//	n--;
	//}
	//| | |
	while ((*str1++ = *str2++)&&n)
	{
		n--;
	}
	return ret;
}
//模拟strncat
int main0305()
{
	char arr1[30] = "hello";
	char arr2[] = "world";
	my_strncat(arr1, arr2, 3);
	printf("%s\n", arr1);
	return 0;
}

