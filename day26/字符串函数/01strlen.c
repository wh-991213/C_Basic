#include<stdio.h>
#include<string.h>
#include<assert.h>

int  main0101()
{
	int len1 = strlen("abcdef");
	printf("%d\n", len1);
	char arr[] = { 'a','b','c','d','e','f' };
	int len2 = strlen(arr);
	printf("%d\n", len2);
	//len1和len2的值分别是6和17(随机值) - 说明strlen在计算字符串长度时它是以'\0'为结束标志的
	return 0;
}


size_t my_strlen1(const char* str)
{
	int count = 0;
	assert(str != NULL);
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}
//模拟实现1strlen - 计数器 
int main0102()
{
	char arr[] = "abcdef";
	int ret = my_strlen1(arr);
	printf("%d\n", ret);
	return 0;
}


size_t my_strlen2(char*str)
{
	if (*str != '\0')
		return 1 + my_strlen2(str + 1);
	else
		return 0;
}
//模拟实现2strlen - 递归
int main0103()
{
	char arr[] = "abcdef";
	my_strlen2(arr);
	return 0;
}

int main0104()
{
	//结果？
	if (strlen("abc") - strlen("abcdef") > 0)
	{
		printf("hehe\n");
	}
	else
	{
		printf("haha\n");
	}
	//hehe - 这里虽然3-6=-3，但是strlen这个函数的返回值是size_t(unsigned int)，故>0
	return 0;
}